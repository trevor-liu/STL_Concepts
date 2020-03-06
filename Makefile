all: student calc

student: student_hash.o
	g++ student_hash.o -o student

calc: complex_postfix.o
	g++ complex_postfix.o -o calc

student_hash.o: student_hash.cpp
	g++ -c -std=c++11 student_hash.cpp

complex_postfix.o: complex_postfix.cpp
	g++ -c -std=c++11 complex_postfix.cpp

clean:
	rm *.o student calc