# CMakeLists.txt
# Date: 2014-08-25
# Author: Karsten Ahnert (karsten.ahnert@gmx.de)
#
# Distributed under the Boost Software License, Version 1.0.
# (See accompanying file LICENSE_1_0.txt or
# copy at http://www.boost.org/LICENSE_1_0.txt)
#


project ( hackerrank )
cmake_minimum_required ( VERSION 2.8 )

# Add path for custom modules
set( CMAKE_MODULE_PATH
  ${CMAKE_MODULE_PATH}
  ${CMAKE_CURRENT_SOURCE_DIR}/cmake
  ${CMAKE_CURRENT_SOURCE_DIR}/cmake/modules
  )

set ( CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14" )


add_executable ( gem_stones gem_stones.cpp )
add_executable ( insertion_sort_analysis insertion_sort_analysis.cpp )
add_executable ( two-arrays two-arrays.cpp )
add_executable ( priyanka-and-toys priyanka-and-toys.cpp )
add_executable ( find-median find-median.cpp )
add_executable ( balanced-parentheses balanced-parentheses.cpp )
add_executable ( largest-rectangle largest-rectangle.cpp )
add_executable ( castle-on-the-grid castle-on-the-grid.cpp )
