CXXFLAGS := -std=c++14 -Wall -Werror -pthread
DANGEROUSFLAGS := -O3

ALL_SOURCES := $(wildcard *.cpp)
MAIN_SOURCES := $(filter-out TESTSs.cpp, $(ALL_SOURCES))
TESTS_SOURCES := $(filter-out main.cpp, $(ALL_SOURCES))

MAIN_OBJS := $(MAIN_SOURCES:%.cpp=%.o)
TESTS_OBJ := $(TESTS_SOURCES:%.cpp=%.o)

# Linking
LDFLAGS := -L/usr/local/lib
LDLIBS := -lgtest -lgtest_main

MAIN := finalProject.out
TESTS := runTests.out

.PHONY : all
all : $(MAIN) $(TESTS)

$(MAIN) : $(MAIN_OBJS)
	 $(CXX) $(CXXFLAGS) $(DANGEROUSFLAGS) $^ -o $@

$(TESTS): $(TESTS_OBJS)
	$(LINK.cc) $^ $(LOADLIBES) $(LDLIBS) -o $@


.PHONY : clean
clean : 
	rm -rf $(MAIN) $(TESTS) $(MAIN_OBJS) $(TESTS_OBJS)

.PHONY : run
run :
	./$(MAIN)

.PHONY : TESTS
TESTS : 
	./$(TESTS)