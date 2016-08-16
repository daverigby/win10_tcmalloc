cmake_minimum_required(VERSION 3.0)

find_path(TCMALLOC_INCLUDE_DIR gperftools/tcmalloc.h)
find_library(TCMALLOC_LIBRARIES NAMES libtcmalloc_minimal)

if(TCMALLOC_LIBRARIES AND TCMALLOC_INCLUDE_DIR)
  message(STATUS "Found TCMalloc in ${TCMALLOC_INCLUDE_DIR} : ${TCMALLOC_LIBRARIES}")
else()
  message(FATAL_ERROR "Unable to find TCMalloc ${TCMALLOC_INCLUDE_DIR} : ${TCMALLOC_LIBRARIES}")
endif()

include_directories(${TCMALLOC_INCLUDE_DIR})

add_executable(win10_tcmalloc win10_tcmalloc.cc)
target_link_libraries(win10_tcmalloc ${TCMALLOC_LIBRARIES})

enable_testing()
add_test(win10_tcmalloc win10_tcmalloc)