#!/bin/bash

MORPHEUS_CONFIG_FILE_LOCATION='/etc/morpheus/morpheus.yaml'
if [ -z "$1" ]; then
    DEFAULT_LOG_LEVEL=${MORPHEUS_LOG_LEVEL}
else
    DEFAULT_LOG_LEVEL=$1
fi

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
  optimizer_timeout: 2
  optimizer_timeout_init: 10
  optimizer_timeout_steps: 1
  log_level: ${DEFAULT_LOG_LEVEL}
EOF