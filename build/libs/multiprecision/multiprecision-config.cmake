
include(CMakeFindDependencyMacro)
# Library: Boost::random
find_dependency(boost_random 1.76.0)

include("${CMAKE_CURRENT_LIST_DIR}/crypto3-multiprecision-targets.cmake")
include("${CMAKE_CURRENT_LIST_DIR}/properties-crypto3-multiprecision-targets.cmake")
