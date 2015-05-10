# Install script for directory: F:/Ola/Moje/dcmtk-3.6.0/dcmimgle/include/dcmtk/dcmimgle

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
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/dcmtk/dcmimgle" TYPE FILE FILES
    "F:/Ola/Moje/dcmtk-3.6.0/dcmimgle/include/dcmtk/dcmimgle/dcmimage.h"
    "F:/Ola/Moje/dcmtk-3.6.0/dcmimgle/include/dcmtk/dcmimgle/dibaslut.h"
    "F:/Ola/Moje/dcmtk-3.6.0/dcmimgle/include/dcmtk/dcmimgle/diciefn.h"
    "F:/Ola/Moje/dcmtk-3.6.0/dcmimgle/include/dcmtk/dcmimgle/dicielut.h"
    "F:/Ola/Moje/dcmtk-3.6.0/dcmimgle/include/dcmtk/dcmimgle/dicrvfit.h"
    "F:/Ola/Moje/dcmtk-3.6.0/dcmimgle/include/dcmtk/dcmimgle/didislut.h"
    "F:/Ola/Moje/dcmtk-3.6.0/dcmimgle/include/dcmtk/dcmimgle/didispfn.h"
    "F:/Ola/Moje/dcmtk-3.6.0/dcmimgle/include/dcmtk/dcmimgle/didocu.h"
    "F:/Ola/Moje/dcmtk-3.6.0/dcmimgle/include/dcmtk/dcmimgle/diflipt.h"
    "F:/Ola/Moje/dcmtk-3.6.0/dcmimgle/include/dcmtk/dcmimgle/digsdfn.h"
    "F:/Ola/Moje/dcmtk-3.6.0/dcmimgle/include/dcmtk/dcmimgle/digsdlut.h"
    "F:/Ola/Moje/dcmtk-3.6.0/dcmimgle/include/dcmtk/dcmimgle/diimage.h"
    "F:/Ola/Moje/dcmtk-3.6.0/dcmimgle/include/dcmtk/dcmimgle/diinpx.h"
    "F:/Ola/Moje/dcmtk-3.6.0/dcmimgle/include/dcmtk/dcmimgle/diinpxt.h"
    "F:/Ola/Moje/dcmtk-3.6.0/dcmimgle/include/dcmtk/dcmimgle/diluptab.h"
    "F:/Ola/Moje/dcmtk-3.6.0/dcmimgle/include/dcmtk/dcmimgle/dimo1img.h"
    "F:/Ola/Moje/dcmtk-3.6.0/dcmimgle/include/dcmtk/dcmimgle/dimo2img.h"
    "F:/Ola/Moje/dcmtk-3.6.0/dcmimgle/include/dcmtk/dcmimgle/dimocpt.h"
    "F:/Ola/Moje/dcmtk-3.6.0/dcmimgle/include/dcmtk/dcmimgle/dimoflt.h"
    "F:/Ola/Moje/dcmtk-3.6.0/dcmimgle/include/dcmtk/dcmimgle/dimoimg.h"
    "F:/Ola/Moje/dcmtk-3.6.0/dcmimgle/include/dcmtk/dcmimgle/dimoipxt.h"
    "F:/Ola/Moje/dcmtk-3.6.0/dcmimgle/include/dcmtk/dcmimgle/dimomod.h"
    "F:/Ola/Moje/dcmtk-3.6.0/dcmimgle/include/dcmtk/dcmimgle/dimoopx.h"
    "F:/Ola/Moje/dcmtk-3.6.0/dcmimgle/include/dcmtk/dcmimgle/dimoopxt.h"
    "F:/Ola/Moje/dcmtk-3.6.0/dcmimgle/include/dcmtk/dcmimgle/dimopx.h"
    "F:/Ola/Moje/dcmtk-3.6.0/dcmimgle/include/dcmtk/dcmimgle/dimopxt.h"
    "F:/Ola/Moje/dcmtk-3.6.0/dcmimgle/include/dcmtk/dcmimgle/dimorot.h"
    "F:/Ola/Moje/dcmtk-3.6.0/dcmimgle/include/dcmtk/dcmimgle/dimosct.h"
    "F:/Ola/Moje/dcmtk-3.6.0/dcmimgle/include/dcmtk/dcmimgle/diobjcou.h"
    "F:/Ola/Moje/dcmtk-3.6.0/dcmimgle/include/dcmtk/dcmimgle/diovdat.h"
    "F:/Ola/Moje/dcmtk-3.6.0/dcmimgle/include/dcmtk/dcmimgle/diovlay.h"
    "F:/Ola/Moje/dcmtk-3.6.0/dcmimgle/include/dcmtk/dcmimgle/diovlimg.h"
    "F:/Ola/Moje/dcmtk-3.6.0/dcmimgle/include/dcmtk/dcmimgle/diovpln.h"
    "F:/Ola/Moje/dcmtk-3.6.0/dcmimgle/include/dcmtk/dcmimgle/dipixel.h"
    "F:/Ola/Moje/dcmtk-3.6.0/dcmimgle/include/dcmtk/dcmimgle/diplugin.h"
    "F:/Ola/Moje/dcmtk-3.6.0/dcmimgle/include/dcmtk/dcmimgle/dipxrept.h"
    "F:/Ola/Moje/dcmtk-3.6.0/dcmimgle/include/dcmtk/dcmimgle/diregbas.h"
    "F:/Ola/Moje/dcmtk-3.6.0/dcmimgle/include/dcmtk/dcmimgle/dirotat.h"
    "F:/Ola/Moje/dcmtk-3.6.0/dcmimgle/include/dcmtk/dcmimgle/discalet.h"
    "F:/Ola/Moje/dcmtk-3.6.0/dcmimgle/include/dcmtk/dcmimgle/displint.h"
    "F:/Ola/Moje/dcmtk-3.6.0/dcmimgle/include/dcmtk/dcmimgle/ditranst.h"
    "F:/Ola/Moje/dcmtk-3.6.0/dcmimgle/include/dcmtk/dcmimgle/diutils.h"
    )
endif()

