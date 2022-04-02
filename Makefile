build:
	 mkdir build && cd build && cmake .. && cmake --build .

run:
	./build/src/main

run-tests:
	./build/tests/matrix_storage/matrix_storage && ./build/tests/mirroring/main && ./build/tests/mirroring_async/main

build-tests:
	cd build && make && run-tests

generate-lcov:
	lcov --coverage --directory=coverage --output-file=coverage.info

generate-coverage-html:
	genhtml coverage.info --output-directory=coverage-output

get-coverage:
	mkdir coverage && mkdir coverage_output && make generate-lcov && make generate-coverage-html

get-all-coverage:
	make get-coverage