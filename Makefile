.DEFAULT_GOAL := run

CXX := g++
CXXFLAGS := -DLOCAL -std=c++20 -O2 -Wall

sol: sol.cpp
	$(CXX) $(CXXFLAGS) sol.cpp -o sol

run: sol
	./sol

clean:
	rm -f sol
