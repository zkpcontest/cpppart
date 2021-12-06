
include(CMakeFindDependencyMacro)
# Library: Boost::program_options
find_dependency(boost_program_options 1.76.0)
# Library: Boost::system
find_dependency(boost_system 1.76.0)
# Library: crypto3::multiprecision
find_dependency(crypto3::multiprecision)
# Library: marshalling::core
find_dependency(marshalling::core)

include("${CMAKE_CURRENT_LIST_DIR}/marshalling-crypto3_multiprecision-targets.cmake")
include("${CMAKE_CURRENT_LIST_DIR}/properties-marshalling-crypto3_multiprecision-targets.cmake")
