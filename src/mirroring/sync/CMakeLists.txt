file(GLOB SRC *.c ../mirroring.h)
add_library(mirroring STATIC ${SRC})
target_include_directories(mirroring PUBLIC ${CMAKE_CURRENT_SOURCE_DIR} ../.)

target_link_libraries(mirroring PUBLIC matrix_storage)