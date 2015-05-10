# Install script for directory: F:/Ola/Moje/dcmtk-3.6.0/dcmsign/include/dcmtk/dcmsign

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "F:/Ola/Moje/SIM/SIMproject")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "Release")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/dcmtk/dcmsign" TYPE FILE FILES
    "F:/Ola/Moje/dcmtk-3.6.0/dcmsign/include/dcmtk/dcmsign/dcsignat.h"
    "F:/Ola/Moje/dcmtk-3.6.0/dcmsign/include/dcmtk/dcmsign/sialgo.h"
    "F:/Ola/Moje/dcmtk-3.6.0/dcmsign/include/dcmtk/dcmsign/siautopr.h"
    "F:/Ola/Moje/dcmtk-3.6.0/dcmsign/include/dcmtk/dcmsign/sibrsapr.h"
    "F:/Ola/Moje/dcmtk-3.6.0/dcmsign/include/dcmtk/dcmsign/sicert.h"
    "F:/Ola/Moje/dcmtk-3.6.0/dcmsign/include/dcmtk/dcmsign/sicertvf.h"
    "F:/Ola/Moje/dcmtk-3.6.0/dcmsign/include/dcmtk/dcmsign/sicreapr.h"
    "F:/Ola/Moje/dcmtk-3.6.0/dcmsign/include/dcmtk/dcmsign/sidsa.h"
    "F:/Ola/Moje/dcmtk-3.6.0/dcmsign/include/dcmtk/dcmsign/simac.h"
    "F:/Ola/Moje/dcmtk-3.6.0/dcmsign/include/dcmtk/dcmsign/simaccon.h"
    "F:/Ola/Moje/dcmtk-3.6.0/dcmsign/include/dcmtk/dcmsign/simd5.h"
    "F:/Ola/Moje/dcmtk-3.6.0/dcmsign/include/dcmtk/dcmsign/sinullpr.h"
    "F:/Ola/Moje/dcmtk-3.6.0/dcmsign/include/dcmtk/dcmsign/siprivat.h"
    "F:/Ola/Moje/dcmtk-3.6.0/dcmsign/include/dcmtk/dcmsign/siripemd.h"
    "F:/Ola/Moje/dcmtk-3.6.0/dcmsign/include/dcmtk/dcmsign/sirsa.h"
    "F:/Ola/Moje/dcmtk-3.6.0/dcmsign/include/dcmtk/dcmsign/sisha1.h"
    "F:/Ola/Moje/dcmtk-3.6.0/dcmsign/include/dcmtk/dcmsign/sisprof.h"
    "F:/Ola/Moje/dcmtk-3.6.0/dcmsign/include/dcmtk/dcmsign/sitstamp.h"
    "F:/Ola/Moje/dcmtk-3.6.0/dcmsign/include/dcmtk/dcmsign/sitypes.h"
    )
endif()

