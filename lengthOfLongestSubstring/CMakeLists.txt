STRING(REGEX REPLACE ".*/(.*)" "\\1" CURRENT_FOLDER ${CMAKE_CURRENT_SOURCE_DIR})
project(${CURRENT_FOLDER})
set(OUTPUT_NAME ${PROJECT_NAME}${PLATFORM_NAME})


#set source file
aux_source_directory(. SRC)

#set output type/name
add_executable(${OUTPUT_NAME}${D_SUFFIX} ${SRC})

#link library
# if (OPENCV_FOUND)
#     include_directories(${OpenCV_INCLUDE_DIRS})
#     target_link_libraries(${OUTPUT_NAME}${D_SUFFIX}
#                         ${OpenCV_LIBS}
#                         )
# endif (OPENCV_FOUND)


#install info
set_target_properties(${OUTPUT_NAME}${D_SUFFIX} PROPERTIES OUTPUT_NAME ${OUTPUT_NAME}${D_SUFFIX})
# set_target_properties(${OUTPUT_NAME}${D_SUFFIX} PROPERTIES LINK_FLAGS -Wl, --no-undefined)