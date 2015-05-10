# Install script for directory: F:/Ola/Moje/dcmtk-3.6.0/dcmpstat/include/dcmtk/dcmpstat

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
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/dcmtk/dcmpstat" TYPE FILE FILES
    "F:/Ola/Moje/dcmtk-3.6.0/dcmpstat/include/dcmtk/dcmpstat/dcmpstat.h"
    "F:/Ola/Moje/dcmtk-3.6.0/dcmpstat/include/dcmtk/dcmpstat/dvcache.h"
    "F:/Ola/Moje/dcmtk-3.6.0/dcmpstat/include/dcmtk/dcmpstat/dviface.h"
    "F:/Ola/Moje/dcmtk-3.6.0/dcmpstat/include/dcmtk/dcmpstat/dvpsab.h"
    "F:/Ola/Moje/dcmtk-3.6.0/dcmpstat/include/dcmtk/dcmpstat/dvpsabl.h"
    "F:/Ola/Moje/dcmtk-3.6.0/dcmpstat/include/dcmtk/dcmpstat/dvpsal.h"
    "F:/Ola/Moje/dcmtk-3.6.0/dcmpstat/include/dcmtk/dcmpstat/dvpsall.h"
    "F:/Ola/Moje/dcmtk-3.6.0/dcmpstat/include/dcmtk/dcmpstat/dvpscf.h"
    "F:/Ola/Moje/dcmtk-3.6.0/dcmpstat/include/dcmtk/dcmpstat/dvpscu.h"
    "F:/Ola/Moje/dcmtk-3.6.0/dcmpstat/include/dcmtk/dcmpstat/dvpscul.h"
    "F:/Ola/Moje/dcmtk-3.6.0/dcmpstat/include/dcmtk/dcmpstat/dvpsda.h"
    "F:/Ola/Moje/dcmtk-3.6.0/dcmpstat/include/dcmtk/dcmpstat/dvpsdal.h"
    "F:/Ola/Moje/dcmtk-3.6.0/dcmpstat/include/dcmtk/dcmpstat/dvpsdef.h"
    "F:/Ola/Moje/dcmtk-3.6.0/dcmpstat/include/dcmtk/dcmpstat/dvpsfs.h"
    "F:/Ola/Moje/dcmtk-3.6.0/dcmpstat/include/dcmtk/dcmpstat/dvpsga.h"
    "F:/Ola/Moje/dcmtk-3.6.0/dcmpstat/include/dcmtk/dcmpstat/dvpsgal.h"
    "F:/Ola/Moje/dcmtk-3.6.0/dcmpstat/include/dcmtk/dcmpstat/dvpsgl.h"
    "F:/Ola/Moje/dcmtk-3.6.0/dcmpstat/include/dcmtk/dcmpstat/dvpsgll.h"
    "F:/Ola/Moje/dcmtk-3.6.0/dcmpstat/include/dcmtk/dcmpstat/dvpsgr.h"
    "F:/Ola/Moje/dcmtk-3.6.0/dcmpstat/include/dcmtk/dcmpstat/dvpsgrl.h"
    "F:/Ola/Moje/dcmtk-3.6.0/dcmpstat/include/dcmtk/dcmpstat/dvpshlp.h"
    "F:/Ola/Moje/dcmtk-3.6.0/dcmpstat/include/dcmtk/dcmpstat/dvpsib.h"
    "F:/Ola/Moje/dcmtk-3.6.0/dcmpstat/include/dcmtk/dcmpstat/dvpsibl.h"
    "F:/Ola/Moje/dcmtk-3.6.0/dcmpstat/include/dcmtk/dcmpstat/dvpsmsg.h"
    "F:/Ola/Moje/dcmtk-3.6.0/dcmpstat/include/dcmtk/dcmpstat/dvpsov.h"
    "F:/Ola/Moje/dcmtk-3.6.0/dcmpstat/include/dcmtk/dcmpstat/dvpsovl.h"
    "F:/Ola/Moje/dcmtk-3.6.0/dcmpstat/include/dcmtk/dcmpstat/dvpspl.h"
    "F:/Ola/Moje/dcmtk-3.6.0/dcmpstat/include/dcmtk/dcmpstat/dvpspll.h"
    "F:/Ola/Moje/dcmtk-3.6.0/dcmpstat/include/dcmtk/dcmpstat/dvpspr.h"
    "F:/Ola/Moje/dcmtk-3.6.0/dcmpstat/include/dcmtk/dcmpstat/dvpsprt.h"
    "F:/Ola/Moje/dcmtk-3.6.0/dcmpstat/include/dcmtk/dcmpstat/dvpsri.h"
    "F:/Ola/Moje/dcmtk-3.6.0/dcmpstat/include/dcmtk/dcmpstat/dvpsril.h"
    "F:/Ola/Moje/dcmtk-3.6.0/dcmpstat/include/dcmtk/dcmpstat/dvpsrs.h"
    "F:/Ola/Moje/dcmtk-3.6.0/dcmpstat/include/dcmtk/dcmpstat/dvpsrsl.h"
    "F:/Ola/Moje/dcmtk-3.6.0/dcmpstat/include/dcmtk/dcmpstat/dvpssp.h"
    "F:/Ola/Moje/dcmtk-3.6.0/dcmpstat/include/dcmtk/dcmpstat/dvpsspl.h"
    "F:/Ola/Moje/dcmtk-3.6.0/dcmpstat/include/dcmtk/dcmpstat/dvpssv.h"
    "F:/Ola/Moje/dcmtk-3.6.0/dcmpstat/include/dcmtk/dcmpstat/dvpssvl.h"
    "F:/Ola/Moje/dcmtk-3.6.0/dcmpstat/include/dcmtk/dcmpstat/dvpstat.h"
    "F:/Ola/Moje/dcmtk-3.6.0/dcmpstat/include/dcmtk/dcmpstat/dvpstx.h"
    "F:/Ola/Moje/dcmtk-3.6.0/dcmpstat/include/dcmtk/dcmpstat/dvpstxl.h"
    "F:/Ola/Moje/dcmtk-3.6.0/dcmpstat/include/dcmtk/dcmpstat/dvpstyp.h"
    "F:/Ola/Moje/dcmtk-3.6.0/dcmpstat/include/dcmtk/dcmpstat/dvpsvl.h"
    "F:/Ola/Moje/dcmtk-3.6.0/dcmpstat/include/dcmtk/dcmpstat/dvpsvll.h"
    "F:/Ola/Moje/dcmtk-3.6.0/dcmpstat/include/dcmtk/dcmpstat/dvpsvw.h"
    "F:/Ola/Moje/dcmtk-3.6.0/dcmpstat/include/dcmtk/dcmpstat/dvpsvwl.h"
    "F:/Ola/Moje/dcmtk-3.6.0/dcmpstat/include/dcmtk/dcmpstat/dvsighdl.h"
    )
endif()

