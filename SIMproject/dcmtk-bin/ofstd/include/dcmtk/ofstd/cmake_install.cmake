# Install script for directory: F:/Ola/Moje/dcmtk-3.6.0/ofstd/include/dcmtk/ofstd

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
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/dcmtk/ofstd" TYPE FILE FILES
    "F:/Ola/Moje/dcmtk-3.6.0/ofstd/include/dcmtk/ofstd/ofalgo.h"
    "F:/Ola/Moje/dcmtk-3.6.0/ofstd/include/dcmtk/ofstd/ofaptr.h"
    "F:/Ola/Moje/dcmtk-3.6.0/ofstd/include/dcmtk/ofstd/ofbmanip.h"
    "F:/Ola/Moje/dcmtk-3.6.0/ofstd/include/dcmtk/ofstd/ofcast.h"
    "F:/Ola/Moje/dcmtk-3.6.0/ofstd/include/dcmtk/ofstd/ofcmdln.h"
    "F:/Ola/Moje/dcmtk-3.6.0/ofstd/include/dcmtk/ofstd/ofconapp.h"
    "F:/Ola/Moje/dcmtk-3.6.0/ofstd/include/dcmtk/ofstd/ofcond.h"
    "F:/Ola/Moje/dcmtk-3.6.0/ofstd/include/dcmtk/ofstd/ofconfig.h"
    "F:/Ola/Moje/dcmtk-3.6.0/ofstd/include/dcmtk/ofstd/ofconsol.h"
    "F:/Ola/Moje/dcmtk-3.6.0/ofstd/include/dcmtk/ofstd/ofcrc32.h"
    "F:/Ola/Moje/dcmtk-3.6.0/ofstd/include/dcmtk/ofstd/ofdate.h"
    "F:/Ola/Moje/dcmtk-3.6.0/ofstd/include/dcmtk/ofstd/ofdatime.h"
    "F:/Ola/Moje/dcmtk-3.6.0/ofstd/include/dcmtk/ofstd/ofdefine.h"
    "F:/Ola/Moje/dcmtk-3.6.0/ofstd/include/dcmtk/ofstd/offile.h"
    "F:/Ola/Moje/dcmtk-3.6.0/ofstd/include/dcmtk/ofstd/offname.h"
    "F:/Ola/Moje/dcmtk-3.6.0/ofstd/include/dcmtk/ofstd/ofglobal.h"
    "F:/Ola/Moje/dcmtk-3.6.0/ofstd/include/dcmtk/ofstd/oflist.h"
    "F:/Ola/Moje/dcmtk-3.6.0/ofstd/include/dcmtk/ofstd/ofmap.h"
    "F:/Ola/Moje/dcmtk-3.6.0/ofstd/include/dcmtk/ofstd/ofoset.h"
    "F:/Ola/Moje/dcmtk-3.6.0/ofstd/include/dcmtk/ofstd/ofset.h"
    "F:/Ola/Moje/dcmtk-3.6.0/ofstd/include/dcmtk/ofstd/ofsetit.h"
    "F:/Ola/Moje/dcmtk-3.6.0/ofstd/include/dcmtk/ofstd/ofstack.h"
    "F:/Ola/Moje/dcmtk-3.6.0/ofstd/include/dcmtk/ofstd/ofstd.h"
    "F:/Ola/Moje/dcmtk-3.6.0/ofstd/include/dcmtk/ofstd/ofstdinc.h"
    "F:/Ola/Moje/dcmtk-3.6.0/ofstd/include/dcmtk/ofstd/ofstream.h"
    "F:/Ola/Moje/dcmtk-3.6.0/ofstd/include/dcmtk/ofstd/ofstring.h"
    "F:/Ola/Moje/dcmtk-3.6.0/ofstd/include/dcmtk/ofstd/ofthread.h"
    "F:/Ola/Moje/dcmtk-3.6.0/ofstd/include/dcmtk/ofstd/oftime.h"
    "F:/Ola/Moje/dcmtk-3.6.0/ofstd/include/dcmtk/ofstd/oftimer.h"
    "F:/Ola/Moje/dcmtk-3.6.0/ofstd/include/dcmtk/ofstd/oftypes.h"
    "F:/Ola/Moje/dcmtk-3.6.0/ofstd/include/dcmtk/ofstd/ofuoset.h"
    "F:/Ola/Moje/dcmtk-3.6.0/ofstd/include/dcmtk/ofstd/ofvector.h"
    )
endif()

