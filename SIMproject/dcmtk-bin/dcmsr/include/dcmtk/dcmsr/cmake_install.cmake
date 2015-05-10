# Install script for directory: F:/Ola/Moje/dcmtk-3.6.0/dcmsr/include/dcmtk/dcmsr

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
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/dcmtk/dcmsr" TYPE FILE FILES
    "F:/Ola/Moje/dcmtk-3.6.0/dcmsr/include/dcmtk/dcmsr/dsrbascc.h"
    "F:/Ola/Moje/dcmtk-3.6.0/dcmsr/include/dcmtk/dcmsr/dsrchecc.h"
    "F:/Ola/Moje/dcmtk-3.6.0/dcmsr/include/dcmtk/dcmsr/dsrcitem.h"
    "F:/Ola/Moje/dcmtk-3.6.0/dcmsr/include/dcmtk/dcmsr/dsrcodtn.h"
    "F:/Ola/Moje/dcmtk-3.6.0/dcmsr/include/dcmtk/dcmsr/dsrcodvl.h"
    "F:/Ola/Moje/dcmtk-3.6.0/dcmsr/include/dcmtk/dcmsr/dsrcolcc.h"
    "F:/Ola/Moje/dcmtk-3.6.0/dcmsr/include/dcmtk/dcmsr/dsrcomcc.h"
    "F:/Ola/Moje/dcmtk-3.6.0/dcmsr/include/dcmtk/dcmsr/dsrcomtn.h"
    "F:/Ola/Moje/dcmtk-3.6.0/dcmsr/include/dcmtk/dcmsr/dsrcomvl.h"
    "F:/Ola/Moje/dcmtk-3.6.0/dcmsr/include/dcmtk/dcmsr/dsrcontn.h"
    "F:/Ola/Moje/dcmtk-3.6.0/dcmsr/include/dcmtk/dcmsr/dsrcsidl.h"
    "F:/Ola/Moje/dcmtk-3.6.0/dcmsr/include/dcmtk/dcmsr/dsrdattn.h"
    "F:/Ola/Moje/dcmtk-3.6.0/dcmsr/include/dcmtk/dcmsr/dsrdoc.h"
    "F:/Ola/Moje/dcmtk-3.6.0/dcmsr/include/dcmtk/dcmsr/dsrdoctn.h"
    "F:/Ola/Moje/dcmtk-3.6.0/dcmsr/include/dcmtk/dcmsr/dsrdoctr.h"
    "F:/Ola/Moje/dcmtk-3.6.0/dcmsr/include/dcmtk/dcmsr/dsrdtitn.h"
    "F:/Ola/Moje/dcmtk-3.6.0/dcmsr/include/dcmtk/dcmsr/dsrenhcc.h"
    "F:/Ola/Moje/dcmtk-3.6.0/dcmsr/include/dcmtk/dcmsr/dsrimgfr.h"
    "F:/Ola/Moje/dcmtk-3.6.0/dcmsr/include/dcmtk/dcmsr/dsrimgtn.h"
    "F:/Ola/Moje/dcmtk-3.6.0/dcmsr/include/dcmtk/dcmsr/dsrimgvl.h"
    "F:/Ola/Moje/dcmtk-3.6.0/dcmsr/include/dcmtk/dcmsr/dsrimpcc.h"
    "F:/Ola/Moje/dcmtk-3.6.0/dcmsr/include/dcmtk/dcmsr/dsriodcc.h"
    "F:/Ola/Moje/dcmtk-3.6.0/dcmsr/include/dcmtk/dcmsr/dsrkeycc.h"
    "F:/Ola/Moje/dcmtk-3.6.0/dcmsr/include/dcmtk/dcmsr/dsrmaccc.h"
    "F:/Ola/Moje/dcmtk-3.6.0/dcmsr/include/dcmtk/dcmsr/dsrmamcc.h"
    "F:/Ola/Moje/dcmtk-3.6.0/dcmsr/include/dcmtk/dcmsr/dsrnumtn.h"
    "F:/Ola/Moje/dcmtk-3.6.0/dcmsr/include/dcmtk/dcmsr/dsrnumvl.h"
    "F:/Ola/Moje/dcmtk-3.6.0/dcmsr/include/dcmtk/dcmsr/dsrpnmtn.h"
    "F:/Ola/Moje/dcmtk-3.6.0/dcmsr/include/dcmtk/dcmsr/dsrprocc.h"
    "F:/Ola/Moje/dcmtk-3.6.0/dcmsr/include/dcmtk/dcmsr/dsrreftn.h"
    "F:/Ola/Moje/dcmtk-3.6.0/dcmsr/include/dcmtk/dcmsr/dsrsc3gr.h"
    "F:/Ola/Moje/dcmtk-3.6.0/dcmsr/include/dcmtk/dcmsr/dsrsc3tn.h"
    "F:/Ola/Moje/dcmtk-3.6.0/dcmsr/include/dcmtk/dcmsr/dsrsc3vl.h"
    "F:/Ola/Moje/dcmtk-3.6.0/dcmsr/include/dcmtk/dcmsr/dsrscogr.h"
    "F:/Ola/Moje/dcmtk-3.6.0/dcmsr/include/dcmtk/dcmsr/dsrscotn.h"
    "F:/Ola/Moje/dcmtk-3.6.0/dcmsr/include/dcmtk/dcmsr/dsrscovl.h"
    "F:/Ola/Moje/dcmtk-3.6.0/dcmsr/include/dcmtk/dcmsr/dsrsoprf.h"
    "F:/Ola/Moje/dcmtk-3.6.0/dcmsr/include/dcmtk/dcmsr/dsrspecc.h"
    "F:/Ola/Moje/dcmtk-3.6.0/dcmsr/include/dcmtk/dcmsr/dsrstrvl.h"
    "F:/Ola/Moje/dcmtk-3.6.0/dcmsr/include/dcmtk/dcmsr/dsrtcodt.h"
    "F:/Ola/Moje/dcmtk-3.6.0/dcmsr/include/dcmtk/dcmsr/dsrtcosp.h"
    "F:/Ola/Moje/dcmtk-3.6.0/dcmsr/include/dcmtk/dcmsr/dsrtcotn.h"
    "F:/Ola/Moje/dcmtk-3.6.0/dcmsr/include/dcmtk/dcmsr/dsrtcoto.h"
    "F:/Ola/Moje/dcmtk-3.6.0/dcmsr/include/dcmtk/dcmsr/dsrtcovl.h"
    "F:/Ola/Moje/dcmtk-3.6.0/dcmsr/include/dcmtk/dcmsr/dsrtextn.h"
    "F:/Ola/Moje/dcmtk-3.6.0/dcmsr/include/dcmtk/dcmsr/dsrtimtn.h"
    "F:/Ola/Moje/dcmtk-3.6.0/dcmsr/include/dcmtk/dcmsr/dsrtlist.h"
    "F:/Ola/Moje/dcmtk-3.6.0/dcmsr/include/dcmtk/dcmsr/dsrtncsr.h"
    "F:/Ola/Moje/dcmtk-3.6.0/dcmsr/include/dcmtk/dcmsr/dsrtree.h"
    "F:/Ola/Moje/dcmtk-3.6.0/dcmsr/include/dcmtk/dcmsr/dsrtypes.h"
    "F:/Ola/Moje/dcmtk-3.6.0/dcmsr/include/dcmtk/dcmsr/dsruidtn.h"
    "F:/Ola/Moje/dcmtk-3.6.0/dcmsr/include/dcmtk/dcmsr/dsrwavch.h"
    "F:/Ola/Moje/dcmtk-3.6.0/dcmsr/include/dcmtk/dcmsr/dsrwavtn.h"
    "F:/Ola/Moje/dcmtk-3.6.0/dcmsr/include/dcmtk/dcmsr/dsrwavvl.h"
    "F:/Ola/Moje/dcmtk-3.6.0/dcmsr/include/dcmtk/dcmsr/dsrxmlc.h"
    "F:/Ola/Moje/dcmtk-3.6.0/dcmsr/include/dcmtk/dcmsr/dsrxmld.h"
    "F:/Ola/Moje/dcmtk-3.6.0/dcmsr/include/dcmtk/dcmsr/dsrxrdcc.h"
    )
endif()

