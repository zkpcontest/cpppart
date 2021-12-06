
include(CMakeFindDependencyMacro)
# Library: crypto3::hash
find_dependency(crypto3::hash)
# Library: crypto3::multiprecision
find_dependency(crypto3::multiprecision)
# Library: Boost::program_options
find_dependency(boost_program_options 1.76.0)
# Library: Boost::system
find_dependency(boost_system 1.76.0)

include("${CMAKE_CURRENT_LIST_DIR}/crypto3-algebra-targets.cmake")
include("${CMAKE_CURRENT_LIST_DIR}/properties-crypto3-algebra-targets.cmake")
