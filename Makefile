build-tests:
	g++ tests/demo.cpp -o bin/demo -Wall
run-tests:
	./bin/demo
clear-all:
	cd bin; rm *