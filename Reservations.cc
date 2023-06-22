#include "Reservations.h"

Reservation::Reservation(string name, Date& inDate, int d){
	this->customerName = name;
    this->checkIn = inDate;
    this->duration = d;
}

void Reservation::setDur(int dur){
    if (dur <= 1){   
        duration = 1;
    } else {
        duration = dur;
    }
}

bool Reservation::overlaps(Reservation &r){

        Date leaveDate(this->checkIn.getYear(), this->checkIn.getMonth(), this->checkIn.getDay());
        leaveDate.addDays(this->duration);
        Date tempLeave(r.checkIn.getYear(), r.checkIn.getMonth(), r.checkIn.getDay());
        tempLeave.addDays(r.duration);
        Date tempR = r.checkIn;

        if (this->checkIn.lessThan(tempR)){
            if (leaveDate.lessThan(tempR) || leaveDate.equals(tempR)){
                return false;
            } else{
                return true;
            }
        }else{
            if (tempLeave.lessThan(this->checkIn) || tempLeave.equals(this->checkIn)){
                return false;
            } else{
                return true;
            }
        }
}

bool Reservation::lessThan(Reservation &r){
        if (this->overlaps(r)){
            return false;
        }
        else{
            return true;
        }
}

bool Reservation::lessThan(Date &r){
        Date leaveDate(this->checkIn.getYear(), this->checkIn.getMonth(), this->checkIn.getDay() + this->duration);
        return leaveDate.lessThan(r) || leaveDate.equals(r);
}

void Reservation::print(){
        cout << "Reservation for " << this->customerName << " on ";
        checkIn.print();
        cout << " for " << this->duration << " days." << endl;
}