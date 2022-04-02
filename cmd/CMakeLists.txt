add_executable(main main.c)

target_link_libraries(main PUBLIC matrix_storage)

if(parallel)
    target_link_libraries(main PUBLIC mirroring_parallel)
else()
    target_link_libraries(main PUBLIC mirroring)
endif(parallel)