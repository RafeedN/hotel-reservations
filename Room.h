#ifndef ROOM_H
#define ROOM_H

#include <iostream>
#include <string>
#include <iomanip>
#include "Room.h"
#include "Reservations.h"
#include "defs.h"

using namespace std;

class Room {
		
	public:
		//constructors
		Room(int roomNumber, string bedType, int capacity, bool hasFridge);
		~Room();

		//getters
		int getRoomNumber();
		
		bool isMatch(string bt, int cap, bool f);
		bool lessThan(Room& r);

		bool addReservation(string customerName, Date& d, int duration);
		
		void print();
		void printReservations();
	
	private:
		int roomNumber;
        string bedType;
        int capacity;
        bool hasFridge;
		Reservation* resArray[MAX_RES];
		int resNums;


};
#endif