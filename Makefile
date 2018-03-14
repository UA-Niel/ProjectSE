CC = g++
headers_location = classes/*.h classes/*.cpp
gtest = -I{GTEST_DIR}/include
parsers_location = parsers/*.h parsers/*.cpp
tinyxml = parsers/library/*
output = main
version = c++98

compile:
	$(CC) main.cpp -o $(output) $(headers_location) $(gtest) $(parsers_location) $(tinyxml) -std=$(version)
