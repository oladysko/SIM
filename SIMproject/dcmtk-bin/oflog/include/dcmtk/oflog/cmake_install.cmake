# Install script for directory: F:/Ola/Moje/dcmtk-3.6.0/oflog/include/dcmtk/oflog

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
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/dcmtk/oflog" TYPE FILE FILES
    "F:/Ola/Moje/dcmtk-3.6.0/oflog/include/dcmtk/oflog/appender.h"
    "F:/Ola/Moje/dcmtk-3.6.0/oflog/include/dcmtk/oflog/config.h"
    "F:/Ola/Moje/dcmtk-3.6.0/oflog/include/dcmtk/oflog/configrt.h"
    "F:/Ola/Moje/dcmtk-3.6.0/oflog/include/dcmtk/oflog/consap.h"
    "F:/Ola/Moje/dcmtk-3.6.0/oflog/include/dcmtk/oflog/fileap.h"
    "F:/Ola/Moje/dcmtk-3.6.0/oflog/include/dcmtk/oflog/fstreams.h"
    "F:/Ola/Moje/dcmtk-3.6.0/oflog/include/dcmtk/oflog/hierarchy.h"
    "F:/Ola/Moje/dcmtk-3.6.0/oflog/include/dcmtk/oflog/hierlock.h"
    "F:/Ola/Moje/dcmtk-3.6.0/oflog/include/dcmtk/oflog/layout.h"
    "F:/Ola/Moje/dcmtk-3.6.0/oflog/include/dcmtk/oflog/logger.h"
    "F:/Ola/Moje/dcmtk-3.6.0/oflog/include/dcmtk/oflog/loglevel.h"
    "F:/Ola/Moje/dcmtk-3.6.0/oflog/include/dcmtk/oflog/logmacro.h"
    "F:/Ola/Moje/dcmtk-3.6.0/oflog/include/dcmtk/oflog/ndc.h"
    "F:/Ola/Moje/dcmtk-3.6.0/oflog/include/dcmtk/oflog/ntelogap.h"
    "F:/Ola/Moje/dcmtk-3.6.0/oflog/include/dcmtk/oflog/nullap.h"
    "F:/Ola/Moje/dcmtk-3.6.0/oflog/include/dcmtk/oflog/oflog.h"
    "F:/Ola/Moje/dcmtk-3.6.0/oflog/include/dcmtk/oflog/socketap.h"
    "F:/Ola/Moje/dcmtk-3.6.0/oflog/include/dcmtk/oflog/streams.h"
    "F:/Ola/Moje/dcmtk-3.6.0/oflog/include/dcmtk/oflog/syslogap.h"
    "F:/Ola/Moje/dcmtk-3.6.0/oflog/include/dcmtk/oflog/tstring.h"
    "F:/Ola/Moje/dcmtk-3.6.0/oflog/include/dcmtk/oflog/winconap.h"
    "F:/Ola/Moje/dcmtk-3.6.0/oflog/include/dcmtk/oflog/windebap.h"
    )
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for each subdirectory.
  include("F:/Ola/Moje/SIM/SIMproject/dcmtk-bin/oflog/include/dcmtk/oflog/config/cmake_install.cmake")
  include("F:/Ola/Moje/SIM/SIMproject/dcmtk-bin/oflog/include/dcmtk/oflog/helpers/cmake_install.cmake")
  include("F:/Ola/Moje/SIM/SIMproject/dcmtk-bin/oflog/include/dcmtk/oflog/spi/cmake_install.cmake")

endif()

