# if you want to dive into makefiles have a look at:
#	https://makefiletutorial.com/
#	http://www.gnu.org/software/make/manual/make.html

CXX=g++
CPPFLAGS=--std=c++17

DEPS=bintree.hpp lib/catch.hpp
OBJ=main.o bintree.o tests.o

all: clean test

%.o: %.cpp $(DEPS)
	$(CXX) -c -o $@ $< $(CPPFLAGS)

exercise6: $(OBJ)
	$(CXX) -o $@ $^ $(CPPFLAGS)

test: exercise6
	# executes all tests
	./exercise6

clean:
	rm -f exercise6
