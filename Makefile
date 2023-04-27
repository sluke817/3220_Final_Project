CXXFLAGS := -std=c++14 -Wall -Werror -ggdb -O0
DANGEROUSFLAGS := -O3

ALL_SOURCES := $(wildcard *.cpp)
MAIN_SOURCES := $(filter-out tests.cpp, $(ALL_SOURCES))
TESTS_SOURCES := $(filter-out main.cpp, $(ALL_SOURCES))

MAIN_OBJS := $(MAIN_SOURCES:%.cpp=%.o)
TESTS_OBJ := $(TESTS_SOURCES:%.cpp=%.o)

# Linking
LDFLAGS := -L/usr/local/lib
LDLIBS := -lgtest -lgtest_main

MAIN := finalProject.out
TESTS := runTests.out

.PHONY : all clean run test
all : $(MAIN) $(TESTS)

$(MAIN) : $(MAIN_OBJS)
	 $(CXX) $(CXXFLAGS) $(DANGEROUSFLAGS) $^ -o $@

$(TESTS): $(TESTS_OBJS)
	$(LINK.cc) $^ $(LOADLIBES) $(LDLIBS) -o $@

clean : 
	rm -rf $(MAIN) $(TESTS) $(MAIN_OBJS) $(TESTS_OBJS)

run :
	./$(MAIN)

test : 
	./$(TESTS)
