# Install script for directory: F:/Ola/Moje/dcmtk-3.6.0

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
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/dcmtk/config" TYPE FILE FILES "F:/Ola/Moje/SIM/SIMproject/dcmtk-bin/include/dcmtk/config/osconfig.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/doc/dcmtk" TYPE FILE FILES
    "F:/Ola/Moje/dcmtk-3.6.0/ANNOUNCE.360"
    "F:/Ola/Moje/dcmtk-3.6.0/CHANGES.360"
    "F:/Ola/Moje/dcmtk-3.6.0/COPYRIGHT"
    "F:/Ola/Moje/dcmtk-3.6.0/FAQ"
    "F:/Ola/Moje/dcmtk-3.6.0/HISTORY"
    "F:/Ola/Moje/dcmtk-3.6.0/VERSION"
    )
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for each subdirectory.
  include("F:/Ola/Moje/SIM/SIMproject/dcmtk-bin/config/cmake_install.cmake")
  include("F:/Ola/Moje/SIM/SIMproject/dcmtk-bin/ofstd/cmake_install.cmake")
  include("F:/Ola/Moje/SIM/SIMproject/dcmtk-bin/oflog/cmake_install.cmake")
  include("F:/Ola/Moje/SIM/SIMproject/dcmtk-bin/dcmdata/cmake_install.cmake")
  include("F:/Ola/Moje/SIM/SIMproject/dcmtk-bin/dcmimgle/cmake_install.cmake")
  include("F:/Ola/Moje/SIM/SIMproject/dcmtk-bin/dcmjpeg/cmake_install.cmake")
  include("F:/Ola/Moje/SIM/SIMproject/dcmtk-bin/dcmimage/cmake_install.cmake")
  include("F:/Ola/Moje/SIM/SIMproject/dcmtk-bin/dcmtls/cmake_install.cmake")
  include("F:/Ola/Moje/SIM/SIMproject/dcmtk-bin/dcmnet/cmake_install.cmake")
  include("F:/Ola/Moje/SIM/SIMproject/dcmtk-bin/dcmwlm/cmake_install.cmake")
  include("F:/Ola/Moje/SIM/SIMproject/dcmtk-bin/dcmqrdb/cmake_install.cmake")
  include("F:/Ola/Moje/SIM/SIMproject/dcmtk-bin/dcmsr/cmake_install.cmake")
  include("F:/Ola/Moje/SIM/SIMproject/dcmtk-bin/dcmpstat/cmake_install.cmake")
  include("F:/Ola/Moje/SIM/SIMproject/dcmtk-bin/dcmsign/cmake_install.cmake")
  include("F:/Ola/Moje/SIM/SIMproject/dcmtk-bin/dcmjpls/cmake_install.cmake")
  include("F:/Ola/Moje/SIM/SIMproject/dcmtk-bin/doxygen/cmake_install.cmake")

endif()

if(CMAKE_INSTALL_COMPONENT)
  set(CMAKE_INSTALL_MANIFEST "install_manifest_${CMAKE_INSTALL_COMPONENT}.txt")
else()
  set(CMAKE_INSTALL_MANIFEST "install_manifest.txt")
endif()

string(REPLACE ";" "\n" CMAKE_INSTALL_MANIFEST_CONTENT
       "${CMAKE_INSTALL_MANIFEST_FILES}")
file(WRITE "F:/Ola/Moje/SIM/SIMproject/dcmtk-bin/${CMAKE_INSTALL_MANIFEST}"
     "${CMAKE_INSTALL_MANIFEST_CONTENT}")
