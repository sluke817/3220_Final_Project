CXXFLAGS := -std=c++14 -Wall -Werror -ggdb -O0
DANGEROUSFLAGS := -O3

ALL_SOURCES := $(wildcard *.cpp)
TARGET_SOURCES := $(filter-out tests.cpp, $(ALL_SOURCES))
TESTS_SOURCES := $(filter-out main.cpp, $(ALL_SOURCES))

TARGET_OBJS := $(TARGET_SOURCES:%.cpp=%.o)
TESTS_OBJ := $(TESTS_SOURCES:%.cpp=%.o)

# Linking
LDFLAGS := -L/usr/local/lib
LDLIBS := -lgtest -lgtest_main

TARGET := finalProject.out
TESTS := runTests.out

.PHONY : all clean run test
all : $(TARGET) $(TESTS)

$(TARGET) : $(TARGET_OBJS)
	 $(CXX) $(CXXFLAGS) $(DANGEROUSFLAGS) $^ -o $@

$(TESTS): $(TESTS_OBJS)
	$(LINK.cc) $^ $(LOADLIBES) $(LDLIBS) -o $@

clean : 
	rm -rf $(TARGET) $(TESTS) $(TARGET_OBJS) $(TESTS_OBJS)

run :
	./$(TARGET)

test : 
	./$(TESTS)
