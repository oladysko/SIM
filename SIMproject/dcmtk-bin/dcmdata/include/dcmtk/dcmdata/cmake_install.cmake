# Install script for directory: F:/Ola/Moje/dcmtk-3.6.0/dcmdata/include/dcmtk/dcmdata

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
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/dcmtk/dcmdata" TYPE FILE FILES
    "F:/Ola/Moje/dcmtk-3.6.0/dcmdata/include/dcmtk/dcmdata/cmdlnarg.h"
    "F:/Ola/Moje/dcmtk-3.6.0/dcmdata/include/dcmtk/dcmdata/dcbytstr.h"
    "F:/Ola/Moje/dcmtk-3.6.0/dcmdata/include/dcmtk/dcmdata/dcchrstr.h"
    "F:/Ola/Moje/dcmtk-3.6.0/dcmdata/include/dcmtk/dcmdata/dccodec.h"
    "F:/Ola/Moje/dcmtk-3.6.0/dcmdata/include/dcmtk/dcmdata/dcdatset.h"
    "F:/Ola/Moje/dcmtk-3.6.0/dcmdata/include/dcmtk/dcmdata/dcddirif.h"
    "F:/Ola/Moje/dcmtk-3.6.0/dcmdata/include/dcmtk/dcmdata/dcdeftag.h"
    "F:/Ola/Moje/dcmtk-3.6.0/dcmdata/include/dcmtk/dcmdata/dcdicdir.h"
    "F:/Ola/Moje/dcmtk-3.6.0/dcmdata/include/dcmtk/dcmdata/dcdicent.h"
    "F:/Ola/Moje/dcmtk-3.6.0/dcmdata/include/dcmtk/dcmdata/dcdict.h"
    "F:/Ola/Moje/dcmtk-3.6.0/dcmdata/include/dcmtk/dcmdata/dcdirrec.h"
    "F:/Ola/Moje/dcmtk-3.6.0/dcmdata/include/dcmtk/dcmdata/dcelem.h"
    "F:/Ola/Moje/dcmtk-3.6.0/dcmdata/include/dcmtk/dcmdata/dcerror.h"
    "F:/Ola/Moje/dcmtk-3.6.0/dcmdata/include/dcmtk/dcmdata/dcfcache.h"
    "F:/Ola/Moje/dcmtk-3.6.0/dcmdata/include/dcmtk/dcmdata/dcfilefo.h"
    "F:/Ola/Moje/dcmtk-3.6.0/dcmdata/include/dcmtk/dcmdata/dchashdi.h"
    "F:/Ola/Moje/dcmtk-3.6.0/dcmdata/include/dcmtk/dcmdata/dcistrma.h"
    "F:/Ola/Moje/dcmtk-3.6.0/dcmdata/include/dcmtk/dcmdata/dcistrmb.h"
    "F:/Ola/Moje/dcmtk-3.6.0/dcmdata/include/dcmtk/dcmdata/dcistrmf.h"
    "F:/Ola/Moje/dcmtk-3.6.0/dcmdata/include/dcmtk/dcmdata/dcistrmz.h"
    "F:/Ola/Moje/dcmtk-3.6.0/dcmdata/include/dcmtk/dcmdata/dcitem.h"
    "F:/Ola/Moje/dcmtk-3.6.0/dcmdata/include/dcmtk/dcmdata/dclist.h"
    "F:/Ola/Moje/dcmtk-3.6.0/dcmdata/include/dcmtk/dcmdata/dcmetinf.h"
    "F:/Ola/Moje/dcmtk-3.6.0/dcmdata/include/dcmtk/dcmdata/dcobject.h"
    "F:/Ola/Moje/dcmtk-3.6.0/dcmdata/include/dcmtk/dcmdata/dcofsetl.h"
    "F:/Ola/Moje/dcmtk-3.6.0/dcmdata/include/dcmtk/dcmdata/dcostrma.h"
    "F:/Ola/Moje/dcmtk-3.6.0/dcmdata/include/dcmtk/dcmdata/dcostrmb.h"
    "F:/Ola/Moje/dcmtk-3.6.0/dcmdata/include/dcmtk/dcmdata/dcostrmf.h"
    "F:/Ola/Moje/dcmtk-3.6.0/dcmdata/include/dcmtk/dcmdata/dcostrmz.h"
    "F:/Ola/Moje/dcmtk-3.6.0/dcmdata/include/dcmtk/dcmdata/dcovlay.h"
    "F:/Ola/Moje/dcmtk-3.6.0/dcmdata/include/dcmtk/dcmdata/dcpath.h"
    "F:/Ola/Moje/dcmtk-3.6.0/dcmdata/include/dcmtk/dcmdata/dcpcache.h"
    "F:/Ola/Moje/dcmtk-3.6.0/dcmdata/include/dcmtk/dcmdata/dcpixel.h"
    "F:/Ola/Moje/dcmtk-3.6.0/dcmdata/include/dcmtk/dcmdata/dcpixseq.h"
    "F:/Ola/Moje/dcmtk-3.6.0/dcmdata/include/dcmtk/dcmdata/dcpxitem.h"
    "F:/Ola/Moje/dcmtk-3.6.0/dcmdata/include/dcmtk/dcmdata/dcrleccd.h"
    "F:/Ola/Moje/dcmtk-3.6.0/dcmdata/include/dcmtk/dcmdata/dcrlecce.h"
    "F:/Ola/Moje/dcmtk-3.6.0/dcmdata/include/dcmtk/dcmdata/dcrlecp.h"
    "F:/Ola/Moje/dcmtk-3.6.0/dcmdata/include/dcmtk/dcmdata/dcrledec.h"
    "F:/Ola/Moje/dcmtk-3.6.0/dcmdata/include/dcmtk/dcmdata/dcrledrg.h"
    "F:/Ola/Moje/dcmtk-3.6.0/dcmdata/include/dcmtk/dcmdata/dcrleenc.h"
    "F:/Ola/Moje/dcmtk-3.6.0/dcmdata/include/dcmtk/dcmdata/dcrleerg.h"
    "F:/Ola/Moje/dcmtk-3.6.0/dcmdata/include/dcmtk/dcmdata/dcrlerp.h"
    "F:/Ola/Moje/dcmtk-3.6.0/dcmdata/include/dcmtk/dcmdata/dcsequen.h"
    "F:/Ola/Moje/dcmtk-3.6.0/dcmdata/include/dcmtk/dcmdata/dcstack.h"
    "F:/Ola/Moje/dcmtk-3.6.0/dcmdata/include/dcmtk/dcmdata/dcswap.h"
    "F:/Ola/Moje/dcmtk-3.6.0/dcmdata/include/dcmtk/dcmdata/dctag.h"
    "F:/Ola/Moje/dcmtk-3.6.0/dcmdata/include/dcmtk/dcmdata/dctagkey.h"
    "F:/Ola/Moje/dcmtk-3.6.0/dcmdata/include/dcmtk/dcmdata/dctk.h"
    "F:/Ola/Moje/dcmtk-3.6.0/dcmdata/include/dcmtk/dcmdata/dctypes.h"
    "F:/Ola/Moje/dcmtk-3.6.0/dcmdata/include/dcmtk/dcmdata/dcuid.h"
    "F:/Ola/Moje/dcmtk-3.6.0/dcmdata/include/dcmtk/dcmdata/dcvm.h"
    "F:/Ola/Moje/dcmtk-3.6.0/dcmdata/include/dcmtk/dcmdata/dcvr.h"
    "F:/Ola/Moje/dcmtk-3.6.0/dcmdata/include/dcmtk/dcmdata/dcvrae.h"
    "F:/Ola/Moje/dcmtk-3.6.0/dcmdata/include/dcmtk/dcmdata/dcvras.h"
    "F:/Ola/Moje/dcmtk-3.6.0/dcmdata/include/dcmtk/dcmdata/dcvrat.h"
    "F:/Ola/Moje/dcmtk-3.6.0/dcmdata/include/dcmtk/dcmdata/dcvrcs.h"
    "F:/Ola/Moje/dcmtk-3.6.0/dcmdata/include/dcmtk/dcmdata/dcvrda.h"
    "F:/Ola/Moje/dcmtk-3.6.0/dcmdata/include/dcmtk/dcmdata/dcvrds.h"
    "F:/Ola/Moje/dcmtk-3.6.0/dcmdata/include/dcmtk/dcmdata/dcvrdt.h"
    "F:/Ola/Moje/dcmtk-3.6.0/dcmdata/include/dcmtk/dcmdata/dcvrfd.h"
    "F:/Ola/Moje/dcmtk-3.6.0/dcmdata/include/dcmtk/dcmdata/dcvrfl.h"
    "F:/Ola/Moje/dcmtk-3.6.0/dcmdata/include/dcmtk/dcmdata/dcvris.h"
    "F:/Ola/Moje/dcmtk-3.6.0/dcmdata/include/dcmtk/dcmdata/dcvrlo.h"
    "F:/Ola/Moje/dcmtk-3.6.0/dcmdata/include/dcmtk/dcmdata/dcvrlt.h"
    "F:/Ola/Moje/dcmtk-3.6.0/dcmdata/include/dcmtk/dcmdata/dcvrobow.h"
    "F:/Ola/Moje/dcmtk-3.6.0/dcmdata/include/dcmtk/dcmdata/dcvrof.h"
    "F:/Ola/Moje/dcmtk-3.6.0/dcmdata/include/dcmtk/dcmdata/dcvrpn.h"
    "F:/Ola/Moje/dcmtk-3.6.0/dcmdata/include/dcmtk/dcmdata/dcvrpobw.h"
    "F:/Ola/Moje/dcmtk-3.6.0/dcmdata/include/dcmtk/dcmdata/dcvrsh.h"
    "F:/Ola/Moje/dcmtk-3.6.0/dcmdata/include/dcmtk/dcmdata/dcvrsl.h"
    "F:/Ola/Moje/dcmtk-3.6.0/dcmdata/include/dcmtk/dcmdata/dcvrss.h"
    "F:/Ola/Moje/dcmtk-3.6.0/dcmdata/include/dcmtk/dcmdata/dcvrst.h"
    "F:/Ola/Moje/dcmtk-3.6.0/dcmdata/include/dcmtk/dcmdata/dcvrtm.h"
    "F:/Ola/Moje/dcmtk-3.6.0/dcmdata/include/dcmtk/dcmdata/dcvrui.h"
    "F:/Ola/Moje/dcmtk-3.6.0/dcmdata/include/dcmtk/dcmdata/dcvrul.h"
    "F:/Ola/Moje/dcmtk-3.6.0/dcmdata/include/dcmtk/dcmdata/dcvrulup.h"
    "F:/Ola/Moje/dcmtk-3.6.0/dcmdata/include/dcmtk/dcmdata/dcvrus.h"
    "F:/Ola/Moje/dcmtk-3.6.0/dcmdata/include/dcmtk/dcmdata/dcvrut.h"
    "F:/Ola/Moje/dcmtk-3.6.0/dcmdata/include/dcmtk/dcmdata/dcwcache.h"
    "F:/Ola/Moje/dcmtk-3.6.0/dcmdata/include/dcmtk/dcmdata/dcxfer.h"
    "F:/Ola/Moje/dcmtk-3.6.0/dcmdata/include/dcmtk/dcmdata/vrscan.h"
    )
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for each subdirectory.
  include("F:/Ola/Moje/SIM/SIMproject/dcmtk-bin/dcmdata/include/dcmtk/dcmdata/libi2d/cmake_install.cmake")

endif()

