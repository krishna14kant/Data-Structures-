#!/bin/bash
echo ""
echo "1.- ELIMINANDO CONTENEDOR E IMAGEN"
docker stop file-parser || echo "El contenedor file-parser no está ejecutándose"
docker container rm file-parser || echo "El contenedor file-parser no existe"
docker image rm ferbosonit/file-parser:latest || echo "La imagen ferbosonit/file-parser:latest no existe"