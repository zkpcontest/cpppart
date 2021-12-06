
include(CMakeFindDependencyMacro)
# Library: Boost::container
find_dependency(boost_container 1.76.0)

include("${CMAKE_CURRENT_LIST_DIR}/crypto3-stream-targets.cmake")
include("${CMAKE_CURRENT_LIST_DIR}/properties-crypto3-stream-targets.cmake")
