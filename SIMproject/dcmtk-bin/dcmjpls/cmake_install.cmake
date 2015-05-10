# Install script for directory: F:/Ola/Moje/dcmtk-3.6.0/dcmjpls

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

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for each subdirectory.
  include("F:/Ola/Moje/SIM/SIMproject/dcmtk-bin/dcmjpls/libsrc/cmake_install.cmake")
  include("F:/Ola/Moje/SIM/SIMproject/dcmtk-bin/dcmjpls/libcharls/cmake_install.cmake")
  include("F:/Ola/Moje/SIM/SIMproject/dcmtk-bin/dcmjpls/apps/cmake_install.cmake")
  include("F:/Ola/Moje/SIM/SIMproject/dcmtk-bin/dcmjpls/include/dcmtk/dcmjpls/cmake_install.cmake")

endif()

