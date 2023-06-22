#include "Room.h"

Room::Room(int roomNumber, string bedType, int capacity, bool hasFridge){
	this->roomNumber = roomNumber;
    this->bedType = bedType;
    this->capacity = capacity;
    this->hasFridge = hasFridge;
    this->resNums = 0;
}
Room::~Room(){
	for (int i = 0; i < resNums; i++)
    {
        delete resArray[i];
    }
}

int Room::getRoomNumber(){
    return this->roomNumber;
}

bool Room::isMatch(string bt, int cap, bool f){
    bool fridge;

    if (f == true && this->hasFridge == true)
    {
        fridge = true;
    } else if(f == false){
        fridge = true;
    } else {
        fridge = false;
    }
    
    return (bt == this->bedType && cap <= this->capacity && fridge) ? true: false;
}
bool Room::lessThan(Room &r){
    return(this->roomNumber < r.getRoomNumber()) ? true : false;
}

bool Room::addReservation(string customerName, Date &d, int duration){
    if (this->resNums == MAX_RES){return false;}

    //Checking if it overlaps with any of the other reservations
    Reservation* res = new Reservation(customerName, d, duration);
    
    if(this->resNums == 0){
        resArray[0] = res;
        this->resNums += 1;
        return true;
    }
    for (int i = 0; i < this->resNums; i++)
    {
        if(res->overlaps(*resArray[i])){
            return false;
        }
    }

    //Finding the position to put new reservation
    int index = 0;
    for (int i = this->resNums - 1; i >= 0; i--)
    {
        if(this->resArray[i]->lessThan(*res)){
            index = i + 1;
        }
    }

    // Moving all the indicies back one to place new res
    // to place new res in order
    for (int i = this->resNums - 1; i >= index; i--)
    {
            this->resArray[i + 1] = this->resArray[i];
    }

    resArray[index] = res;
    this->resNums += 1;
    
    return true;
    
}

void Room::print(){
    string fridge = (this->hasFridge) ? "True" : "False";
    cout <<" Room Number: " << this->roomNumber << " (Bed Type: " << this->bedType << ", Capacity: "<< this->capacity << ", Fridge: " << fridge << ")" <<endl;
    
}

void Room::printReservations(){
    this->print();
    for (int i = 0; i < this->resNums; i++)
    {
        cout<<"\t";
        this->resArray[i]->print();
    }
    
}