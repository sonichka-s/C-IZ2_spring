file(GLOB SRC *.c ../mirroring.h)
add_library(mirroring_parallel SHARED ${SRC})
target_include_directories(mirroring_parallel PUBLIC ${CMAKE_CURRENT_SOURCE_DIR} ../.)

target_link_libraries(mirroring_parallel PUBLIC matrix_storage)