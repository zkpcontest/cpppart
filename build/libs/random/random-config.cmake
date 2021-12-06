
include(CMakeFindDependencyMacro)
# Library: crypto3::algebra
find_dependency(crypto3::algebra)
# Library: crypto3::hash
find_dependency(crypto3::hash)
# Library: crypto3::mac
find_dependency(crypto3::mac)
# Library: crypto3::stream
find_dependency(crypto3::stream)
# Library: Boost::program_options
find_dependency(boost_program_options 1.76.0)
# Library: Boost::system
find_dependency(boost_system 1.76.0)

include("${CMAKE_CURRENT_LIST_DIR}/crypto3-random-targets.cmake")
include("${CMAKE_CURRENT_LIST_DIR}/properties-crypto3-random-targets.cmake")
