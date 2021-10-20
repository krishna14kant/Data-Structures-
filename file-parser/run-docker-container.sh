#!/bin/bash
echo ""
echo "1.- ELIMINANDO CONTENEDOR E IMAGEN"
docker stop file-parser || echo "El contenedor file-parser no está ejecutándose"
docker container rm file-parser || echo "El contenedor file-parser no existe"
docker image rm ferbosonit/file-parser:latest || echo "La imagen ferbosonit/file-parser:latest no existe"
echo ""
echo "2.- CONSTRUYENDO CONTENEDOR"
docker build -t ferbosonit/file-parser:latest .
echo ""
echo "3.- CORRIENDO CONTENEDOR"
docker run --name file-parser ferbosonit/file-parser:latest
docker logs file-parser -f