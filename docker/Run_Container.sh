#!/bin/bash

set -e 

uploads_dir="${HOME}/DCMA_WS_client_uploads/"
artifacts_dir="${HOME}/DCMA_WS_artifacts/"

mkdir -p "${uploads_dir}"
mkdir -p "${artifacts_dir}"

printf "Client uploads go to: ${uploads_dir}\n"
printf "WebServer artifacts go to: ${artifacts_dir}\n"

sudo docker run -it --rm -p 8080:80 \
    -v "${uploads_dir}":/client_uploads/:rw \
    -v "${artifacts_dir}":/home/hal/DICOMautomaton_Webserver_Artifacts/:rw \
    dicomautomaton_webserver:latest

#    --entrypoint /bin/bash \
