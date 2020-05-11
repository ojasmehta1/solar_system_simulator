all:
	make NBody

NBody: main.o Body.o
	g++ -o NBody main.o Body.o -lsfml-graphics -lsfml-system -lsfml-window

main.o: Body.hpp main.cpp
	g++ -c main.cpp

Body.o: Body.hpp Body.cpp
	g++ -c Body.cpp

clean:
	rm -f *.o *~ NBody
