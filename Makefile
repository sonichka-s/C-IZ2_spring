build:
	 mkdir build && cd build && cmake .. && cmake --build .

build-tests:
	mkdir build && cd build && cmake .. && cmake --build . &&

run:
	./build/src/main

run-tests:
	./build/tests/matrix_storage/test_matrix_storage && ./build/tests/mirroring/test_mirroring && ./build/tests/mirroring_async/test_mirroring_async

generate-lcov:
	lcov --coverage --directory=coverage --output-file=coverage.info

generate-coverage-html:
	genhtml coverage.info --output-directory=coverage-output

get-coverage:
	mkdir coverage && mkdir coverage_output && make generate-lcov && make generate-coverage-html

get-all-coverage:
	make get-coverage