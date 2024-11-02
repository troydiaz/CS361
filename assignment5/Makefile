CXX = g++
CXXFLAGS = -Wall -std=c++11

# Target executable
TARGET = nursetrack

# Source and header files
SRCS = main.cpp
HEADERS = nursetrack.h

# Build the program
$(TARGET): $(SRCS) $(HEADERS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(SRCS)

# Clean up build files
clean:
	rm -f $(TARGET)
