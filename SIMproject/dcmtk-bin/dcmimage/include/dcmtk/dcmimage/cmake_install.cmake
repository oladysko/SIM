# Install script for directory: F:/Ola/Moje/dcmtk-3.6.0/dcmimage/include/dcmtk/dcmimage

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
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/dcmtk/dcmimage" TYPE FILE FILES
    "F:/Ola/Moje/dcmtk-3.6.0/dcmimage/include/dcmtk/dcmimage/diargimg.h"
    "F:/Ola/Moje/dcmtk-3.6.0/dcmimage/include/dcmtk/dcmimage/diargpxt.h"
    "F:/Ola/Moje/dcmtk-3.6.0/dcmimage/include/dcmtk/dcmimage/dicmyimg.h"
    "F:/Ola/Moje/dcmtk-3.6.0/dcmimage/include/dcmtk/dcmimage/dicmypxt.h"
    "F:/Ola/Moje/dcmtk-3.6.0/dcmimage/include/dcmtk/dcmimage/dicocpt.h"
    "F:/Ola/Moje/dcmtk-3.6.0/dcmimage/include/dcmtk/dcmimage/dicoflt.h"
    "F:/Ola/Moje/dcmtk-3.6.0/dcmimage/include/dcmtk/dcmimage/dicoimg.h"
    "F:/Ola/Moje/dcmtk-3.6.0/dcmimage/include/dcmtk/dcmimage/dicomot.h"
    "F:/Ola/Moje/dcmtk-3.6.0/dcmimage/include/dcmtk/dcmimage/dicoopx.h"
    "F:/Ola/Moje/dcmtk-3.6.0/dcmimage/include/dcmtk/dcmimage/dicoopxt.h"
    "F:/Ola/Moje/dcmtk-3.6.0/dcmimage/include/dcmtk/dcmimage/dicopx.h"
    "F:/Ola/Moje/dcmtk-3.6.0/dcmimage/include/dcmtk/dcmimage/dicopxt.h"
    "F:/Ola/Moje/dcmtk-3.6.0/dcmimage/include/dcmtk/dcmimage/dicorot.h"
    "F:/Ola/Moje/dcmtk-3.6.0/dcmimage/include/dcmtk/dcmimage/dicosct.h"
    "F:/Ola/Moje/dcmtk-3.6.0/dcmimage/include/dcmtk/dcmimage/dihsvimg.h"
    "F:/Ola/Moje/dcmtk-3.6.0/dcmimage/include/dcmtk/dcmimage/dihsvpxt.h"
    "F:/Ola/Moje/dcmtk-3.6.0/dcmimage/include/dcmtk/dcmimage/dilogger.h"
    "F:/Ola/Moje/dcmtk-3.6.0/dcmimage/include/dcmtk/dcmimage/dipalimg.h"
    "F:/Ola/Moje/dcmtk-3.6.0/dcmimage/include/dcmtk/dcmimage/dipalpxt.h"
    "F:/Ola/Moje/dcmtk-3.6.0/dcmimage/include/dcmtk/dcmimage/dipipng.h"
    "F:/Ola/Moje/dcmtk-3.6.0/dcmimage/include/dcmtk/dcmimage/dipitiff.h"
    "F:/Ola/Moje/dcmtk-3.6.0/dcmimage/include/dcmtk/dcmimage/diqtcmap.h"
    "F:/Ola/Moje/dcmtk-3.6.0/dcmimage/include/dcmtk/dcmimage/diqtctab.h"
    "F:/Ola/Moje/dcmtk-3.6.0/dcmimage/include/dcmtk/dcmimage/diqtfs.h"
    "F:/Ola/Moje/dcmtk-3.6.0/dcmimage/include/dcmtk/dcmimage/diqthash.h"
    "F:/Ola/Moje/dcmtk-3.6.0/dcmimage/include/dcmtk/dcmimage/diqthitl.h"
    "F:/Ola/Moje/dcmtk-3.6.0/dcmimage/include/dcmtk/dcmimage/diqthitm.h"
    "F:/Ola/Moje/dcmtk-3.6.0/dcmimage/include/dcmtk/dcmimage/diqtid.h"
    "F:/Ola/Moje/dcmtk-3.6.0/dcmimage/include/dcmtk/dcmimage/diqtpbox.h"
    "F:/Ola/Moje/dcmtk-3.6.0/dcmimage/include/dcmtk/dcmimage/diqtpix.h"
    "F:/Ola/Moje/dcmtk-3.6.0/dcmimage/include/dcmtk/dcmimage/diqtstab.h"
    "F:/Ola/Moje/dcmtk-3.6.0/dcmimage/include/dcmtk/dcmimage/diqttype.h"
    "F:/Ola/Moje/dcmtk-3.6.0/dcmimage/include/dcmtk/dcmimage/diquant.h"
    "F:/Ola/Moje/dcmtk-3.6.0/dcmimage/include/dcmtk/dcmimage/diregist.h"
    "F:/Ola/Moje/dcmtk-3.6.0/dcmimage/include/dcmtk/dcmimage/dirgbimg.h"
    "F:/Ola/Moje/dcmtk-3.6.0/dcmimage/include/dcmtk/dcmimage/dirgbpxt.h"
    "F:/Ola/Moje/dcmtk-3.6.0/dcmimage/include/dcmtk/dcmimage/diybrimg.h"
    "F:/Ola/Moje/dcmtk-3.6.0/dcmimage/include/dcmtk/dcmimage/diybrpxt.h"
    "F:/Ola/Moje/dcmtk-3.6.0/dcmimage/include/dcmtk/dcmimage/diyf2img.h"
    "F:/Ola/Moje/dcmtk-3.6.0/dcmimage/include/dcmtk/dcmimage/diyf2pxt.h"
    "F:/Ola/Moje/dcmtk-3.6.0/dcmimage/include/dcmtk/dcmimage/diyp2img.h"
    "F:/Ola/Moje/dcmtk-3.6.0/dcmimage/include/dcmtk/dcmimage/diyp2pxt.h"
    )
endif()

