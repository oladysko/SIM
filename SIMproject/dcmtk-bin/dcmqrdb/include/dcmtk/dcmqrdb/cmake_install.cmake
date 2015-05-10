# Install script for directory: F:/Ola/Moje/dcmtk-3.6.0/dcmqrdb/include/dcmtk/dcmqrdb

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
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/dcmtk/dcmqrdb" TYPE FILE FILES
    "F:/Ola/Moje/dcmtk-3.6.0/dcmqrdb/include/dcmtk/dcmqrdb/dcmqrcbf.h"
    "F:/Ola/Moje/dcmtk-3.6.0/dcmqrdb/include/dcmtk/dcmqrdb/dcmqrcbg.h"
    "F:/Ola/Moje/dcmtk-3.6.0/dcmqrdb/include/dcmtk/dcmqrdb/dcmqrcbm.h"
    "F:/Ola/Moje/dcmtk-3.6.0/dcmqrdb/include/dcmtk/dcmqrdb/dcmqrcbs.h"
    "F:/Ola/Moje/dcmtk-3.6.0/dcmqrdb/include/dcmtk/dcmqrdb/dcmqrcnf.h"
    "F:/Ola/Moje/dcmtk-3.6.0/dcmqrdb/include/dcmtk/dcmqrdb/dcmqrdba.h"
    "F:/Ola/Moje/dcmtk-3.6.0/dcmqrdb/include/dcmtk/dcmqrdb/dcmqrdbi.h"
    "F:/Ola/Moje/dcmtk-3.6.0/dcmqrdb/include/dcmtk/dcmqrdb/dcmqrdbs.h"
    "F:/Ola/Moje/dcmtk-3.6.0/dcmqrdb/include/dcmtk/dcmqrdb/dcmqridx.h"
    "F:/Ola/Moje/dcmtk-3.6.0/dcmqrdb/include/dcmtk/dcmqrdb/dcmqropt.h"
    "F:/Ola/Moje/dcmtk-3.6.0/dcmqrdb/include/dcmtk/dcmqrdb/dcmqrptb.h"
    "F:/Ola/Moje/dcmtk-3.6.0/dcmqrdb/include/dcmtk/dcmqrdb/dcmqrsrv.h"
    "F:/Ola/Moje/dcmtk-3.6.0/dcmqrdb/include/dcmtk/dcmqrdb/dcmqrtis.h"
    )
endif()

