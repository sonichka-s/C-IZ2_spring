add_executable(test_matrix_storage main.cpp matrix_storage.cpp)

find_package(GTest REQUIRED)
find_package(Threads REQUIRED)

target_include_directories(test_matrix_storage PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(test_matrix_storage ${GTEST_LIBRARIES} Threads::Threads matrix_storage)