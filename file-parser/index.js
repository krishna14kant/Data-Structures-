'use strict';

// Load environmental variables
require('dotenv').config()

const fs = require('fs');
const path = require('path');
const chokidar = require('chokidar');
const axios = require('axios');

require('console-stamp')(console, {pattern: 'dd/mm/yy HH:MM:ss'});

if (!process.env.UPLOADS_PATH) {
  console.error('Variable de entorno UPLOADS_PATH no especificada');
  process.exit(0);
};

if (!process.env.ORION_IP) {
  console.error('Variable de entorno ORION_IP no especificada');
  process.exit(0);
};

if (!process.env.ORION_PORT) {
  console.error('Variable de entorno ORION_PORT no especificada');
  process.exit(0);
};

const {
  UPLOADS_PATH,
  ORION_IP,
  ORION_PORT
} = process.env;

// One-liner for current directory
const watcher = chokidar.watch(UPLOADS_PATH);

console.log('Escuchando cambios en', path.resolve(UPLOADS_PATH));
// watcher.on('all', (event, path) => {
//   console.log('Event:', event, 'Path:', path);
// });

watcher.on('change', path => {
  console.log ('Cambio detectado en archivo, Ruta:', path);

  const file = fs.readFileSync(path, 'utf-8');
  const lines = file.trim().split('\n').reverse();

  let headerLine, lastLine;

  for (let line of lines) {
    line = line.trim();
    // console.log('line', line);
    if (line === '' || !line.includes(';')) continue;
    if (!lastLine) {
      lastLine = line;
      console.log('lastLine', lastLine);
      continue;
    }
    if (!headerLine && ['"Tiempo inicio"', "[ ]"].includes(line.split(';')[0]) && line.split(';')[1] !== '"Iny"') {
      headerLine = line;
      console.log('headerLine', headerLine);
      continue;
    }
  };

  if (!headerLine || !lastLine || !headerLine.includes(';') || !lastLine.includes(';')) {
    console.error('Formato de datos no reconocido. Lectura de datos abortada')
    return;
  };

  const csvType = headerLine.split(';')[0];
  let header = headerLine.split(';').slice(1,-1);
  let data = lastLine.split(';').slice(1,-1);

  if (header.length !== data.length) {
    console.error(`Formato de datos inconsistente -> Claves: ${header.length}, Valores: ${data.length}`);
    return;
  }
  
  let re;

  if (csvType === '"Tiempo inicio"') re = /("Trigger"|\[\w+\]"$)/ig
  if (csvType === "[ ]") re = /^\w+\s/ig

  header = header.map(item => {
    // console.log(item)
    // console.log(re)
    return item.match(re)[0].replace(/(\[|\]|")/ig, '').trim();
  });
  // console.log("TCL: header", header)
  // console.log("TCL: data", data)

  let attributes = {};

  header.forEach((key, i) => {
    if (key === 'Trigger') {
      // attributes[key] = { type: 'String', value: data[i] };
      // Skip Trigger attribute
      return;
    } else {
      attributes[key] = { type: 'Float', value: parseFloat(data[i].replace(/,/, '.')) }
    }
    return attributes[key];
  });

  const entityID = path.split(/\\|\//).slice(-2)[0];

  console.log(`Enviando a Orion datos de ${entityID}, ${Object.keys(attributes).length} atributos`);
  console.log(`Atributos de ${entityID}:`, attributes);

  // const symbols =["C3u", "CPx", "PHu", "H1x", "H2x", "H3x", "H4x", "H5x", "H6x", "OelTx", "PNs", "ZSch1", "PVs", "SFs", "SSx", "SKs", "ZDx", "ZFx", "ZSx", "ZUs"];

  // for (let key in attributes) {
  //   if (!symbols.includes(key)) delete attributes[key];
  // }

  // console.log('Después:', attributes, Object.keys(attributes).length);

  axios.post(`http://${ORION_IP}:${ORION_PORT}/v2/entities/${entityID}/attrs`, {
        ...attributes
      }, {
        headers: {
          'fiware-service': 'openiot',
          'fiware-servicepath': '/',
          'Content-Type': 'application/json'
        }
      })
        .then((res) => {
          console.log(`[ORION] Petición recibida para ${entityID}, status: ${res.status}`);
        })
        .catch((error) => {
          console.error(`[ORION] Error de conexión: ${error}`);
        })

})
