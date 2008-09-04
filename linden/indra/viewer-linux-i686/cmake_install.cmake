# Install script for directory: /home/gareth/slbrowser/linden/indra

# Set the install prefix
IF(NOT DEFINED CMAKE_INSTALL_PREFIX)
  SET(CMAKE_INSTALL_PREFIX "/usr/local")
ENDIF(NOT DEFINED CMAKE_INSTALL_PREFIX)
STRING(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
IF(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  IF(BUILD_TYPE)
    STRING(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  ELSE(BUILD_TYPE)
    SET(CMAKE_INSTALL_CONFIG_NAME "Release")
  ENDIF(BUILD_TYPE)
  MESSAGE(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
ENDIF(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)

# Set the component getting installed.
IF(NOT CMAKE_INSTALL_COMPONENT)
  IF(COMPONENT)
    MESSAGE(STATUS "Install component: \"${COMPONENT}\"")
    SET(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  ELSE(COMPONENT)
    SET(CMAKE_INSTALL_COMPONENT)
  ENDIF(COMPONENT)
ENDIF(NOT CMAKE_INSTALL_COMPONENT)

# Install shared libraries without execute permission?
IF(NOT DEFINED CMAKE_INSTALL_SO_NO_EXE)
  SET(CMAKE_INSTALL_SO_NO_EXE "0")
ENDIF(NOT DEFINED CMAKE_INSTALL_SO_NO_EXE)

IF(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for each subdirectory.
  INCLUDE("/home/gareth/slbrowser/linden/indra/viewer-linux-i686/cmake/cmake_install.cmake")
  INCLUDE("/home/gareth/slbrowser/linden/indra/viewer-linux-i686/llaudio/cmake_install.cmake")
  INCLUDE("/home/gareth/slbrowser/linden/indra/viewer-linux-i686/llcharacter/cmake_install.cmake")
  INCLUDE("/home/gareth/slbrowser/linden/indra/viewer-linux-i686/llcommon/cmake_install.cmake")
  INCLUDE("/home/gareth/slbrowser/linden/indra/viewer-linux-i686/llimage/cmake_install.cmake")
  INCLUDE("/home/gareth/slbrowser/linden/indra/viewer-linux-i686/llimagej2coj/cmake_install.cmake")
  INCLUDE("/home/gareth/slbrowser/linden/indra/viewer-linux-i686/llinventory/cmake_install.cmake")
  INCLUDE("/home/gareth/slbrowser/linden/indra/viewer-linux-i686/llmath/cmake_install.cmake")
  INCLUDE("/home/gareth/slbrowser/linden/indra/viewer-linux-i686/llmedia/cmake_install.cmake")
  INCLUDE("/home/gareth/slbrowser/linden/indra/viewer-linux-i686/llmessage/cmake_install.cmake")
  INCLUDE("/home/gareth/slbrowser/linden/indra/viewer-linux-i686/llprimitive/cmake_install.cmake")
  INCLUDE("/home/gareth/slbrowser/linden/indra/viewer-linux-i686/llrender/cmake_install.cmake")
  INCLUDE("/home/gareth/slbrowser/linden/indra/viewer-linux-i686/llvfs/cmake_install.cmake")
  INCLUDE("/home/gareth/slbrowser/linden/indra/viewer-linux-i686/llwindow/cmake_install.cmake")
  INCLUDE("/home/gareth/slbrowser/linden/indra/viewer-linux-i686/llxml/cmake_install.cmake")
  INCLUDE("/home/gareth/slbrowser/linden/indra/viewer-linux-i686/lscript/cmake_install.cmake")
  INCLUDE("/home/gareth/slbrowser/linden/indra/viewer-linux-i686/llcrashlogger/cmake_install.cmake")
  INCLUDE("/home/gareth/slbrowser/linden/indra/viewer-linux-i686/llui/cmake_install.cmake")
  INCLUDE("/home/gareth/slbrowser/linden/indra/viewer-linux-i686/linux_crash_logger/cmake_install.cmake")
  INCLUDE("/home/gareth/slbrowser/linden/indra/viewer-linux-i686/newview/cmake_install.cmake")

ENDIF(NOT CMAKE_INSTALL_LOCAL_ONLY)

IF(CMAKE_INSTALL_COMPONENT)
  SET(CMAKE_INSTALL_MANIFEST "install_manifest_${CMAKE_INSTALL_COMPONENT}.txt")
ELSE(CMAKE_INSTALL_COMPONENT)
  SET(CMAKE_INSTALL_MANIFEST "install_manifest.txt")
ENDIF(CMAKE_INSTALL_COMPONENT)

FILE(WRITE "/home/gareth/slbrowser/linden/indra/viewer-linux-i686/${CMAKE_INSTALL_MANIFEST}" "")
FOREACH(file ${CMAKE_INSTALL_MANIFEST_FILES})
  FILE(APPEND "/home/gareth/slbrowser/linden/indra/viewer-linux-i686/${CMAKE_INSTALL_MANIFEST}" "${file}\n")
ENDFOREACH(file)
