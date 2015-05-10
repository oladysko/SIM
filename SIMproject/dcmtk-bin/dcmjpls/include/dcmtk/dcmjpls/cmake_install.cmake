# Install script for directory: F:/Ola/Moje/dcmtk-3.6.0/dcmjpls/include/dcmtk/dcmjpls

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
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/dcmtk/dcmjpls" TYPE FILE FILES
    "F:/Ola/Moje/dcmtk-3.6.0/dcmjpls/include/dcmtk/dcmjpls/djcodecd.h"
    "F:/Ola/Moje/dcmtk-3.6.0/dcmjpls/include/dcmtk/dcmjpls/djcodece.h"
    "F:/Ola/Moje/dcmtk-3.6.0/dcmjpls/include/dcmtk/dcmjpls/djcparam.h"
    "F:/Ola/Moje/dcmtk-3.6.0/dcmjpls/include/dcmtk/dcmjpls/djdecode.h"
    "F:/Ola/Moje/dcmtk-3.6.0/dcmjpls/include/dcmtk/dcmjpls/djencode.h"
    "F:/Ola/Moje/dcmtk-3.6.0/dcmjpls/include/dcmtk/dcmjpls/djlsutil.h"
    "F:/Ola/Moje/dcmtk-3.6.0/dcmjpls/include/dcmtk/dcmjpls/djrparam.h"
    )
endif()

