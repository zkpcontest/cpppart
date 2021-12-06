
include(CMakeFindDependencyMacro)
# Library: Boost::program_options
find_dependency(boost_program_options 1.76.0)
# Library: Boost::system
find_dependency(boost_system 1.76.0)

include("${CMAKE_CURRENT_LIST_DIR}/marshalling-core-targets.cmake")
include("${CMAKE_CURRENT_LIST_DIR}/properties-marshalling-core-targets.cmake")
