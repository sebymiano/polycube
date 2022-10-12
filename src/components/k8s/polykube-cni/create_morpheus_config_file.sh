#!/bin/bash

MORPHEUS_CONFIG_FILE_LOCATION='/etc/morpheus/morpheus.yaml'
DEFAULT_MORPHEUS_TABLES_TO_SKIP="[]"
DEFAULT_MORPHEUS_OPTIMIZER_TIMEOUT="2"
DEFAULT_MORPHEUS_OPTIMIZER_TIMEOUT_INIT="10"

if [ -z "$1" ]; then
    DEFAULT_LOG_LEVEL=${MORPHEUS_LOG_LEVEL}
else
    DEFAULT_LOG_LEVEL=$1
fi

if [[ -z "${MORPHEUS_TABLES_TO_SKIP}" ]]; then
  USE_MORPHEUS_TABLES_TO_SKIP=${DEFAULT_MORPHEUS_TABLES_TO_SKIP}
else
  USE_MORPHEUS_TABLES_TO_SKIP=${MORPHEUS_TABLES_TO_SKIP}
fi
USE_MORPHEUS_TABLES_TO_SKIP=$(echo "$USE_MORPHEUS_TABLES_TO_SKIP" | tr -d '"')

if [[ -z "${MORPHEUS_OPTIMIZER_TIMEOUT}" ]]; then
  USE_MORPHEUS_OPTIMIZER_TIMEOUT=${DEFAULT_MORPHEUS_OPTIMIZER_TIMEOUT}
else
  USE_MORPHEUS_OPTIMIZER_TIMEOUT=${MORPHEUS_OPTIMIZER_TIMEOUT}
fi
USE_MORPHEUS_OPTIMIZER_TIMEOUT=$(echo "$USE_MORPHEUS_OPTIMIZER_TIMEOUT" | tr -d '"')

if [[ -z "${MORPHEUS_OPTIMIZER_TIMEOUT_INIT}" ]]; then
  USE_MORPHEUS_OPTIMIZER_TIMEOUT_INIT=${DEFAULT_MORPHEUS_OPTIMIZER_TIMEOUT_INIT}
else
  USE_MORPHEUS_OPTIMIZER_TIMEOUT_INIT=${MORPHEUS_OPTIMIZER_TIMEOUT_INIT}
fi
USE_MORPHEUS_OPTIMIZER_TIMEOUT_INIT=$(echo "$USE_MORPHEUS_OPTIMIZER_TIMEOUT_INIT" | tr -d '"')

mkdir -p -- "$(dirname -- "${MORPHEUS_CONFIG_FILE_LOCATION}")"
cat > ${MORPHEUS_CONFIG_FILE_LOCATION} <<EOF
Morpheus:
  enable_runtime_opts: true
  enable_instrumentation: true
  instrumentation_rate: 5
  enable_guard: false
  enable_guards_update: false
  enable_debug_printk: false
  always_instrument: true
  stop_instrumentation_after_cycles: 5
  max_offloaded_entries: 50
  always_swap_program: false
  naive_instrumentation: false
  optimizer_timeout: ${USE_MORPHEUS_OPTIMIZER_TIMEOUT}
  optimizer_timeout_init: ${USE_MORPHEUS_OPTIMIZER_TIMEOUT_INIT}
  optimizer_timeout_steps: 1
  log_level: ${DEFAULT_LOG_LEVEL}
  tables_to_skip: ${USE_MORPHEUS_TABLES_TO_SKIP}
EOF