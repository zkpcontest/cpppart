# - Find CommsChampion
# Find the CommsChampion includes and libraries
# 
# Output is provided using the following variables
#  CC_MARSHALLING_FOUND - Found Marshalling library, use CC_INCLUDE_DIRS for includes
#  CC_MARSHALLING_FOUND - Found CommsChampion, use CC_INCLUDE_DIRS, CC_PLUGIN_LIBRARIES, CC_PLUGIN_DIR)
#  CC_INCLUDE_DIRS - Where to find all the headers
#  CC_ROOT_DIR - Root directory of CommsChampion installation
#  CC_PLUGIN_LIBRARIES - Libraries to link against when building a plugin
#  CC_PLUGIN_LIBRARY_DIRS - Where to find the libraries required to build plugin.
#  CC_PLUGIN_DIR - Directory where to install newly built plugin
#  CC_CMAKE_DIR - Directory containing installed cmake scripts

get_filename_component(CC_INSTALL_LIB_PROJ_DIR ${CMAKE_CURRENT_LIST_DIR} DIRECTORY)
get_filename_component(CC_INSTALL_LIB_DIR ${CC_INSTALL_LIB_PROJ_DIR} DIRECTORY)
get_filename_component(CC_ROOT_DIR ${CC_INSTALL_LIB_DIR} DIRECTORY)

find_path(CC_INCLUDE_DIR NAMES marshalling/marshalling.h PATHS "${CC_ROOT_DIR}" PATH_SUFFIXES include)
find_library(CC_PLUGIN_LIBRARY NAMES "crypto3_lib" PATHS "${CC_ROOT_DIR}" PATH_SUFFIXES lib)

if(MSVC)
    find_file(CC_NULL_SOCK_LIBRARY NAMES "null_socket.dll" PATHS "${CC_ROOT_DIR}/lib/CommsChampion" PATH_SUFFIXES plugin)
else()
    find_library(CC_NULL_SOCK_LIBRARY NAMES "null_socket" PATHS "${CC_ROOT_DIR}/lib/CommsChampion" PATH_SUFFIXES plugin)
endif()

if(CC_PLUGIN_LIBRARY)
    get_filename_component(CC_PLUGIN_LIBRARY_DIR ${CC_PLUGIN_LIBRARY} DIRECTORY)
endif()

if(CC_NULL_SOCK_LIBRARY)
    get_filename_component(CC_PLUGIN_DIR ${CC_NULL_SOCK_LIBRARY} DIRECTORY)
endif()

set(CC_CMAKE_DIR ${CMAKE_CURRENT_LIST_DIR})

find_package(PackageHandleStandardArgs REQUIRED)
find_package_handle_standard_args(CC_Marshalling REQUIRED_VARS CC_INCLUDE_DIR)
find_package_handle_standard_args(CC_BROTO REQUIRED_VARS
                                  CC_ROOT_DIR CC_INCLUDE_DIR CC_PLUGIN_LIBRARY_DIR CC_PLUGIN_LIBRARY CC_PLUGIN_DIR CC_CMAKE_DIR)

if(CC_MARSHALLING_FOUND)
    set(CC_INCLUDE_DIRS ${CC_INCLUDE_DIR})
endif()

if(CC_MARSHALLING_FOUND)
    set(CC_PLUGIN_LIBRARIES ${CC_PLUGIN_LIBRARY})
    set(CC_PLUGIN_LIBRARY_DIRS ${CC_PLUGIN_LIBRARY_DIR})
endif()

