CC=g++
headers_location = headers/*.h headers/*.cpp
gtest = -I{GTEST_DIR}/include
parsers_location = -Iparsers/
output = main
version = c++98

compile:
	$(CC) main.cpp -o $(output) $(headers_location) $(gtest) $(parsers_location) -std=$(version)
