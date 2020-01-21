cmake_minimum_required(VERSION 3.8)


if (NOT CMAKE_TOOLCHAIN_FILE)
    set(PLATFORM_ID )
    set(PLATFORM_NAME )
endif()

message("Platform: ${PLATFORM_ID} Compiler:${GNU_MACHINE}")


# set output path
set(LIBRARY_OUTPUT_PATH ${PROJECT_BINARY_DIR}/${PLATFORM_ID}/lib)
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/${PLATFORM_ID}/bin)

#################################
# set include path
set (INC_PATH
    include
    src
)

# set library path
set (LIB_PATH
    ${CMAKE_CURRENT_SOURCE_DIR}/lib
)

########## set build rule ##########

#include header file
include_directories(${INC_PATH})

#link library
link_directories(
    ${LIBRARY_OUTPUT_PATH}
    ${LIB_PATH}
)

########## add make flag ###########
set(CMAKE_C_FLAGS ${CMAKE_C_FLAGS} "-g -o -fPIC -pthread")
set(CMAKE_CXX_FLAGS ${CMAKE_C_FLAGS})#"-std=c++11")
add_definitions("-Wall")
add_definitions(-DDEBUG_FLAG)

########## install output ##########
#install(FILES src/*.h DESTINATION include)
#install(DIRECTORY src/ DESTINATION include FILES_MATCHING PATTERN "*.h")
#install(TARGETS ${PROJECT_NAME}
#        EXPORT ${PROJECT_NAME}-targets
#        RUNTIME DESTINATION bin
#        LIBRARY DESTINATION lib
#        ARCHIVE DESTINATION lib
#)
#install(EXPORT ${PROJECT_NAME}-targets
#        NAMESPACE ${PROJECT_NAME}::
#        FILE ${PROJECT_NAME}-config.cmake
#        DESTINATION lib/cmake/${PROJECT_NAME}
#)

#set library path
# set(CMAKE_PREFIX_PATH ${CMAKE_PREFIX_PATH} "${CMAKE_CURRENT_SOURCE_DIR}/${PLATFORM_ID}/lib/cmake/opencv4")
# find_package(OpenCV REQUIRED)
# if (OPENCV_FOUND)
#     message("opencv ok!")
# endif (OPENCV_FOUND)

add_subdirectory(MidOf2SortedArray)
add_subdirectory(873lenfibsubseq)
add_subdirectory(886reachableNodes)
add_subdirectory(887projectionAera)
add_subdirectory(lengthOfLongestSubstring)