build:
	 mkdir build && cd build && cmake .. && cmake --build .

run:
	./build/src/main

run-tests:
	./build/tests/matrix_storage/test_matrix_storage && ./build/tests/mirroring/test_mirroring

run-valgrind:
	valgrind && run-tests
