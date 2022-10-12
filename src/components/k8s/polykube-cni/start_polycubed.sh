#!/bin/bash

POLYCUBED_LOGLEVEL="INFO"
POLYCUBED_ADDR="0.0.0.0"
POLYCUBED_LOGFILE="/host/var/log/polycubed.morpheus.log"

POLYCUBED_CMD="polycubed --loglevel=${POLYCUBED_LOGLEVEL} --addr=${POLYCUBED_ADDR} --logfile=${POLYCUBED_LOGFILE}"

POLYCUBED_CLEANUP_SCRIPT="/cleanup_polycube.sh"

until ${POLYCUBED_CMD}; do
    status=$?
    echo "Process 'polycubed' crashed with exit code $status.  Cleanup" >&2
    if [ $status -eq 0 ]; then 
        exit 0
    else
        /bin/bash ${POLYCUBED_CLEANUP_SCRIPT}
        exit 1
    fi
done