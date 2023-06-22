all: hotelRes

hotelRes: Date.o Reservations.o Room.o Hotel.o main.o
	g++ -o hotelRes Date.o Reservations.o Room.o main.o Hotel.o

Date.o: Date.h Date.cc defs.h
	g++ -c Date.cc

main.o: main.cc
	g++ -c main.cc

Reservations.o: Reservations.h Reservations.cc defs.h
	g++ -c Reservations.cc

Room.o: Room.h Room.cc defs.h
	g++ -c Room.cc

Hotel.o: Hotel.h Hotel.cc defs.h
	g++ -c Hotel.cc

clean:
	rm -f hotelRes *.o

