CMAKE_MINIMUM_REQUIRED(VERSION 2.6)

PROJECT("mystd" CXX C)

OPTION(MYSTD_COMPILE_EXAMPLES "Should compile examples ?" OFF)

IF(MYSTD_COMPILE_EXAMPLES)
  INCLUDE_DIRECTORIES("${CMAKE_CURRENT_LIST_DIR}/include")

  # Enables C++11 when necessary.
  INCLUDE(CheckCXXCompilerFlag)
  CHECK_CXX_COMPILER_FLAG(-std=c++11 HAS_CXX11_FLAG)
  IF(HAS_CXX11_FLAG)
    LIST(APPEND CMAKE_CXX_FLAGS "-std=c++11")
  ENDIF()

  ADD_EXECUTABLE("cartesian_product_example" "${CMAKE_CURRENT_LIST_DIR}/examples/cartesian_product_example.cpp")
  ADD_EXECUTABLE("iterator_example" "${CMAKE_CURRENT_LIST_DIR}/examples/iterator_example.cpp")
  ADD_EXECUTABLE("stopwatch_example" "${CMAKE_CURRENT_LIST_DIR}/examples/stopwatch_example.cpp")
ENDIF()

INSTALL(DIRECTORY include/ DESTINATION include)