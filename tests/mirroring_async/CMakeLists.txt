add_executable(test_mirroring_async main.cpp mirroring_async.cpp)

find_package(GTest REQUIRED)
find_package(Threads REQUIRED)

target_include_directories(test_mirroring_async PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(test_mirroring_async ${GTEST_LIBRARIES} Threads::Threads mirroring_parallel)