﻿file (GLOB_RECURSE MY_SOURCE_FILES CONFIGURE_DEPENDS LIST_DIRECTORIES false RELATIVE ${CMAKE_CURRENT_LIST_DIR} *.cpp)
target_sources (${CMAKE_PROJECT_NAME} PRIVATE ${MY_SOURCE_FILES} "../include/Consts.h" "Bar.cpp" "../include/Grid.h" "Grid.cpp" "../include/Row.h" "../include/Tile.h" "Tile.cpp" "Row.cpp" "../include/File.h" "File.cpp" "../include/Images.h" "Images.cpp")
