CXX := g++
CXXFLAGS := -std=c++14 -Wall -Werror -ggdb -O0
DANGEROUSFLAGS := -O3

ALL_SOURCES := $(wildcard *.cpp)
TARGET_SOURCES := $(filter-out tests.cpp, $(ALL_SOURCES))
TEST_SOURCES := $(filter-out main.cpp, $(ALL_SOURCES))

TARGET_OBJS := $(TARGET_SOURCES:%.cpp=%.o)
TEST_OBJS := $(TEST_SOURCES:%.cpp=%.o)

# Linking
LDFLAGS := -L/usr/local/lib
LDLIBS := -lgtest -lgtest_main

TARGET := finalProject
TEST := runTests

.PHONY : all clean run test
all : $(TEST) $(TARGET)

$(TEST): $(TEST_OBJS)
	$(LINK.cc) $^ $(LOADLIBES) $(LDLIBS) -o $@

$(TARGET) : $(TARGET_OBJS)
	 $(CXX) $(CXXFLAGS) $(DANGEROUSFLAGS) $^ -o $@

clean : 
	rm -rf $(TARGET) $(TEST) $(TARGET_OBJS) $(TEST_OBJS)

run :
	./$(TARGET)

test : 
	./$(TEST)
