#include "Hotel.h"

Hotel::~Hotel(){
	for (int i = 0; i < numRms; i++)
    {
        delete rmArray[i];
    }
}
Hotel::Hotel(){
    numRms = 0;
}

bool Hotel::addRoom(int roomNumber, string bedType, int capacity, bool fr){
    
    if (numRms == MAX_ROOMS){return false;}

    Room* room = new Room(roomNumber, bedType, capacity, fr);
    
    if(numRms == 0){
        rmArray[0] = room;
        numRms += 1;
        return true;
    }
    //Checking for any duplicates
    for (int i = 0; i < numRms; i++)
    {
        if(rmArray[0]->getRoomNumber() == room->getRoomNumber()){
            return false;
        }
    }

    //Finding the position to put new reservation
    int index = 0;
    for (int i = numRms - 1; i >= 0; i--)
    {
        if(rmArray[i]->lessThan(*room)){
            index = i + 1;
        }
    }
    

    //shifting back to make space for new room
    for (int i = numRms - 1; i >= index; i--)
    {
            this->rmArray[i + 1] = this->rmArray[i];
    }
   

    rmArray[index] = room;
    numRms += 1;
    
    return true;

}

bool Hotel::deleteRoom(int roomNumber){
    int index = -1;
    for (int i = 0; i < numRms; i++)
    {
        if(rmArray[i]->getRoomNumber() == roomNumber){
            index = i;
        }
    }
    
    if(index == -1){
        return false;
    }

    numRms -= 1;
    //shifting back to make space for new room
    for (int i = index; i < numRms; i++)
    {
        this->rmArray[i] = this->rmArray[i + 1];
    }
        this->rmArray[numRms] = NULL;
    
    return true;
    
}
bool Hotel::getRoom(int roomNumber, Room** room){
    for (int i = 0; i < numRms; i++)
    {
        if (rmArray[i]->getRoomNumber() == roomNumber)
        {
            *room = rmArray[i];
            return true;
        }
        
    }

    return false;
    
}

bool Hotel::addReservation(string customer, string bedType, int capacity, bool fr, Date& date, int duration){
    
    for (int i = 0; i < numRms; i++)
    {
        if (rmArray[i]->isMatch(bedType, capacity, fr) && rmArray[i]->addReservation(customer, date, duration))
        {
            return true;
        }
        
    }
    return false;
    
}
		
void Hotel::print(){
    for (int i = 0; i < numRms; i++)
    {
        rmArray[i]->print();
    }
    
}
void Hotel::printReservations(){
    for (int i = 0; i < numRms; i++)
    {
        rmArray[i]->printReservations();
    }
}