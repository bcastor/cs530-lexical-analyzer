################################################
#
#Makefile for cs530 assignment 3
#
#Brandon Castor/cssc1960/817046315
#
#
################################################
CXX = g++
CFLAGS = -std=c++11

exp: exp.o bnf.o
	${CXX} ${CFLAGS} exp.o bnf.o -o exp

exp.o: exp.cpp
	${CXX} ${CFLAGS} -c exp.cpp

Bnf.o: bnf.cpp
	${CXX} ${CFLAGS} -c bnf.cpp

clean:
	rm -f *.o exp

	