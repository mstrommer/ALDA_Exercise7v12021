# if you want to dive into makefiles have a look at:
#	https://makefiletutorial.com/
#	http://www.gnu.org/software/make/manual/make.html

CXX=g++
CPPFLAGS=--std=c++17

DEPS=graph.hpp node.hpp list.hpp lib/catch.hpp
OBJ=main.o graph.o list.o tests.o

all: clean test

%.o: %.cpp $(DEPS)
	$(CXX) -c -o $@ $< $(CPPFLAGS)

exercise7: $(OBJ)
	$(CXX) -o $@ $^ $(CPPFLAGS)

test: exercise7
	# executes all tests
	./exercise7

clean:
	rm -f exercise7
