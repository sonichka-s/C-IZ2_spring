add_executable(test_mirroring main.cpp mirroring.cpp)

find_package(GTest REQUIRED)
find_package(Threads REQUIRED)

target_include_directories(test_mirroring PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(test_mirroring ${GTEST_LIBRARIES} Threads::Threads mirroring)