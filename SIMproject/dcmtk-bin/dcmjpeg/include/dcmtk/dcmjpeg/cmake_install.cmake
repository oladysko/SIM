# Install script for directory: F:/Ola/Moje/dcmtk-3.6.0/dcmjpeg/include/dcmtk/dcmjpeg

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
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/dcmtk/dcmjpeg" TYPE FILE FILES
    "F:/Ola/Moje/dcmtk-3.6.0/dcmjpeg/include/dcmtk/dcmjpeg/ddpiimpl.h"
    "F:/Ola/Moje/dcmtk-3.6.0/dcmjpeg/include/dcmtk/dcmjpeg/dipijpeg.h"
    "F:/Ola/Moje/dcmtk-3.6.0/dcmjpeg/include/dcmtk/dcmjpeg/djcodecd.h"
    "F:/Ola/Moje/dcmtk-3.6.0/dcmjpeg/include/dcmtk/dcmjpeg/djcodece.h"
    "F:/Ola/Moje/dcmtk-3.6.0/dcmjpeg/include/dcmtk/dcmjpeg/djcparam.h"
    "F:/Ola/Moje/dcmtk-3.6.0/dcmjpeg/include/dcmtk/dcmjpeg/djdecabs.h"
    "F:/Ola/Moje/dcmtk-3.6.0/dcmjpeg/include/dcmtk/dcmjpeg/djdecbas.h"
    "F:/Ola/Moje/dcmtk-3.6.0/dcmjpeg/include/dcmtk/dcmjpeg/djdecext.h"
    "F:/Ola/Moje/dcmtk-3.6.0/dcmjpeg/include/dcmtk/dcmjpeg/djdeclol.h"
    "F:/Ola/Moje/dcmtk-3.6.0/dcmjpeg/include/dcmtk/dcmjpeg/djdecode.h"
    "F:/Ola/Moje/dcmtk-3.6.0/dcmjpeg/include/dcmtk/dcmjpeg/djdecpro.h"
    "F:/Ola/Moje/dcmtk-3.6.0/dcmjpeg/include/dcmtk/dcmjpeg/djdecsps.h"
    "F:/Ola/Moje/dcmtk-3.6.0/dcmjpeg/include/dcmtk/dcmjpeg/djdecsv1.h"
    "F:/Ola/Moje/dcmtk-3.6.0/dcmjpeg/include/dcmtk/dcmjpeg/djdijg12.h"
    "F:/Ola/Moje/dcmtk-3.6.0/dcmjpeg/include/dcmtk/dcmjpeg/djdijg16.h"
    "F:/Ola/Moje/dcmtk-3.6.0/dcmjpeg/include/dcmtk/dcmjpeg/djdijg8.h"
    "F:/Ola/Moje/dcmtk-3.6.0/dcmjpeg/include/dcmtk/dcmjpeg/djeijg12.h"
    "F:/Ola/Moje/dcmtk-3.6.0/dcmjpeg/include/dcmtk/dcmjpeg/djeijg16.h"
    "F:/Ola/Moje/dcmtk-3.6.0/dcmjpeg/include/dcmtk/dcmjpeg/djeijg8.h"
    "F:/Ola/Moje/dcmtk-3.6.0/dcmjpeg/include/dcmtk/dcmjpeg/djencabs.h"
    "F:/Ola/Moje/dcmtk-3.6.0/dcmjpeg/include/dcmtk/dcmjpeg/djencbas.h"
    "F:/Ola/Moje/dcmtk-3.6.0/dcmjpeg/include/dcmtk/dcmjpeg/djencext.h"
    "F:/Ola/Moje/dcmtk-3.6.0/dcmjpeg/include/dcmtk/dcmjpeg/djenclol.h"
    "F:/Ola/Moje/dcmtk-3.6.0/dcmjpeg/include/dcmtk/dcmjpeg/djencode.h"
    "F:/Ola/Moje/dcmtk-3.6.0/dcmjpeg/include/dcmtk/dcmjpeg/djencpro.h"
    "F:/Ola/Moje/dcmtk-3.6.0/dcmjpeg/include/dcmtk/dcmjpeg/djencsps.h"
    "F:/Ola/Moje/dcmtk-3.6.0/dcmjpeg/include/dcmtk/dcmjpeg/djencsv1.h"
    "F:/Ola/Moje/dcmtk-3.6.0/dcmjpeg/include/dcmtk/dcmjpeg/djrplol.h"
    "F:/Ola/Moje/dcmtk-3.6.0/dcmjpeg/include/dcmtk/dcmjpeg/djrploss.h"
    "F:/Ola/Moje/dcmtk-3.6.0/dcmjpeg/include/dcmtk/dcmjpeg/djutils.h"
    )
endif()

