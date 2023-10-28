// https://thisdavej.com/how-to-watch-for-files-changes-in-node-js/

'use strict';

const fs = require('fs');
const md5 = require('md5');
require('log-timestamp');

const buttonPressesLogFile = './button-presses.log';

console.log(`Watching for file changes on ${buttonPressesLogFile}`);

let md5Previous = null;
let fsWait = false;
fs.watch(buttonPressesLogFile, (event, filename) => {
  if (filename) {
    if (fsWait) return;
    fsWait = setTimeout(() => {
      fsWait = false;
    }, 100);
    const md5Current = md5(fs.readFileSync(buttonPressesLogFile));
    if (md5Current === md5Previous) {
      return;
    }
    md5Previous = md5Current;
    console.log(`${filename} file Changed`);
  }
});