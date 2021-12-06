
include(CMakeFindDependencyMacro)
# Library: crypto3::block
find_dependency(crypto3::block)
# Library: crypto3::codec
find_dependency(crypto3::codec)
# Library: crypto3::hash
find_dependency(crypto3::hash)
# Library: Boost::program_options
find_dependency(boost_program_options 1.76.0)
# Library: Boost::system
find_dependency(boost_system 1.76.0)

include("${CMAKE_CURRENT_LIST_DIR}/crypto3-modes-targets.cmake")
include("${CMAKE_CURRENT_LIST_DIR}/properties-crypto3-modes-targets.cmake")
