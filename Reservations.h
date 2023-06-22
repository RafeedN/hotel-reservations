#ifndef RESERVATIONS_H
#define RESERVATIONS_H

#include <iostream>
#include <string>
#include <iomanip>
#include "Date.h"

using namespace std;

class Reservation {
		
	public:
		//constructors
		Reservation(string customerName, Date& checkIn, int duration);

		//setters
		void setDur(int);
		
		//getters
		int getDur();

		bool overlaps(Reservation& r);
		bool lessThan(Reservation& r);
		bool lessThan(Date& r);

		
		void print();
	
	private:
		string customerName;
        Date checkIn;
        int duration;
	
};
#endif