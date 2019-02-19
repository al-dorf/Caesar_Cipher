kaiser: Caesar_Cipher.h Caesar_Cipher.cpp main.cpp
	g++ -Wall -std=c++17 -c Caesar_Cipher.h
	g++ -Wall -std=c++17 -c Caesar_Cipher.cpp
	g++ -Wall -std=c++17 -c main.cpp
	g++ -Wall -std=c++17 -o kaiser Caesar_Cipher.o main.o
