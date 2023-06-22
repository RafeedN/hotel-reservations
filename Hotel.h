#ifndef HOTEL_H
#define HOTEL_H

#include <iostream>
#include <string>
#include <iomanip>
#include "Room.h"
#include "defs.h"

using namespace std;

class Hotel {
		
	public:
		//constructors
		Hotel();
        ~Hotel();
		
		bool addRoom(int roomNumber, string bedType, int capacity, bool fr);
        bool deleteRoom(int roomNumber);

        bool getRoom(int roomNumber, Room** room);

		bool addReservation(string customer, string bedType, int capacity, bool fr, Date& date, int duration);
		
        void print();
		void printReservations();
	
	private:
		Room* rmArray[MAX_ROOMS];
		int numRms;


};
#endif