# Install script for directory: F:/Ola/Moje/dcmtk-3.6.0/dcmnet/include/dcmtk/dcmnet

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
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/dcmtk/dcmnet" TYPE FILE FILES
    "F:/Ola/Moje/dcmtk-3.6.0/dcmnet/include/dcmtk/dcmnet/assoc.h"
    "F:/Ola/Moje/dcmtk-3.6.0/dcmnet/include/dcmtk/dcmnet/cond.h"
    "F:/Ola/Moje/dcmtk-3.6.0/dcmnet/include/dcmtk/dcmnet/dcasccff.h"
    "F:/Ola/Moje/dcmtk-3.6.0/dcmnet/include/dcmtk/dcmnet/dcasccfg.h"
    "F:/Ola/Moje/dcmtk-3.6.0/dcmnet/include/dcmtk/dcmnet/dccfenmp.h"
    "F:/Ola/Moje/dcmtk-3.6.0/dcmnet/include/dcmtk/dcmnet/dccfpcmp.h"
    "F:/Ola/Moje/dcmtk-3.6.0/dcmnet/include/dcmtk/dcmnet/dccfprmp.h"
    "F:/Ola/Moje/dcmtk-3.6.0/dcmnet/include/dcmtk/dcmnet/dccfrsmp.h"
    "F:/Ola/Moje/dcmtk-3.6.0/dcmnet/include/dcmtk/dcmnet/dccftsmp.h"
    "F:/Ola/Moje/dcmtk-3.6.0/dcmnet/include/dcmtk/dcmnet/dccfuidh.h"
    "F:/Ola/Moje/dcmtk-3.6.0/dcmnet/include/dcmtk/dcmnet/dcmlayer.h"
    "F:/Ola/Moje/dcmtk-3.6.0/dcmnet/include/dcmtk/dcmnet/dcmsmap.h"
    "F:/Ola/Moje/dcmtk-3.6.0/dcmnet/include/dcmtk/dcmnet/dcmtrans.h"
    "F:/Ola/Moje/dcmtk-3.6.0/dcmnet/include/dcmtk/dcmnet/dcompat.h"
    "F:/Ola/Moje/dcmtk-3.6.0/dcmnet/include/dcmtk/dcmnet/dcuserid.h"
    "F:/Ola/Moje/dcmtk-3.6.0/dcmnet/include/dcmtk/dcmnet/dfindscu.h"
    "F:/Ola/Moje/dcmtk-3.6.0/dcmnet/include/dcmtk/dcmnet/dicom.h"
    "F:/Ola/Moje/dcmtk-3.6.0/dcmnet/include/dcmtk/dcmnet/dimse.h"
    "F:/Ola/Moje/dcmtk-3.6.0/dcmnet/include/dcmtk/dcmnet/diutil.h"
    "F:/Ola/Moje/dcmtk-3.6.0/dcmnet/include/dcmtk/dcmnet/dul.h"
    "F:/Ola/Moje/dcmtk-3.6.0/dcmnet/include/dcmtk/dcmnet/extneg.h"
    "F:/Ola/Moje/dcmtk-3.6.0/dcmnet/include/dcmtk/dcmnet/lst.h"
    "F:/Ola/Moje/dcmtk-3.6.0/dcmnet/include/dcmtk/dcmnet/scp.h"
    "F:/Ola/Moje/dcmtk-3.6.0/dcmnet/include/dcmtk/dcmnet/scu.h"
    )
endif()

