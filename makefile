kaiser: Caesar_Cipher.h Caesar_Cipher.cpp main.cpp
	g++ -Wall -c Caesar_Cipher.h
	g++ -Wall -c Caesar_Cipher.cpp
	g++ -Wall -c main.cpp
	g++ -Wall -o kaiser Caesar_Cipher.o main.o
