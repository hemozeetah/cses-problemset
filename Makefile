.DEFAULT_GOAL := run

CXX := g++
CXXFLAGS := -std=c++20 -Wall -DLOCAL -O2

sol: sol.cpp
	$(CXX) $(CXXFLAGS) sol.cpp -o sol

run: sol
	./sol

clean:
	rm -f sol
