
include(CMakeFindDependencyMacro)
# Library: Boost::program_options
find_dependency(boost_program_options 1.76.0)
# Library: Boost::system
find_dependency(boost_system 1.76.0)
# Library: crypto3::algebra
find_dependency(crypto3::algebra)
# Library: crypto3::math
find_dependency(crypto3::math)
# Library: crypto3::hash
find_dependency(crypto3::hash)
# Library: crypto3::multiprecision
find_dependency(crypto3::multiprecision)
# Library: crypto3::random
find_dependency(crypto3::random)
# Library: crypto3::zk
find_dependency(crypto3::zk)

include("${CMAKE_CURRENT_LIST_DIR}/crypto3-blueprint-targets.cmake")
include("${CMAKE_CURRENT_LIST_DIR}/properties-crypto3-blueprint-targets.cmake")
