include(${PROJECT_SOURCE_DIR}/cmake/LoadFileAsVariable.cmake)

aux_source_directory(serializer SERIALIZER_SOURCES)
aux_source_directory(api API_SOURCES)
aux_source_directory(base BASE_SOURCES)

include_directories(serializer)

if (NOT DEFINED POLYCUBE_STANDALONE_SERVICE OR POLYCUBE_STANDALONE_SERVICE)
  find_package(PkgConfig REQUIRED)
  pkg_check_modules(POLYCUBE libpolycube)
  include_directories(${POLYCUBE_INCLUDE_DIRS})
endif(NOT DEFINED POLYCUBE_STANDALONE_SERVICE OR POLYCUBE_STANDALONE_SERVICE)

# Needed to load files as variables
include_directories(${CMAKE_CURRENT_BINARY_DIR})

add_library(pcn-lbrp SHARED
  ${SERIALIZER_SOURCES}
  ${API_SOURCES}
  ${BASE_SOURCES}
  Lbrp.cpp
  Ports.cpp
  Service.cpp
  ServiceBackend.cpp
  SrcIpRewrite.cpp
  Lbrp-lib.cpp)

# load ebpf datapath code in std::string variables
load_file_as_variable(pcn-lbrp Lbrp_dp.c lbrp_code)

# load datamodel in a variable
load_file_as_variable(pcn-lbrp ../datamodel/lbrp.yang lbrp_datamodel)

target_link_libraries(pcn-lbrp ${POLYCUBE_LIBRARIES})

# Specify shared library install directory

set(CMAKE_INSTALL_LIBDIR /usr/lib)

install(
    TARGETS
    pcn-lbrp
    DESTINATION
    "${CMAKE_INSTALL_LIBDIR}"
)
