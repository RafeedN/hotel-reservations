# Hotel Reservations
## Project Context
This project is the backend logic of a hotel reservation management system. It utilizes **classes**, **arrays**, and **dynamic memory** to provide a **functional system**. The program allows users to **add** rooms, **request** reservations, and **view** details of existing rooms and reservations. It includes features such as checking room availability, matching specific criteria for room selection, and managing reservation dates so that they do not overlap each other. The application is designed to be user-friendly and efficient, providing a reliable solution for hotel room management.
 
## Project Learning Goals Achieved
- Understand the basics of **classes**, **arrays**, and **static and dynamic memory** in **C++**.
- Learn how to **create** and **populate classes**, use functions and constructors effectively, and provide a working Makefile.
- Gain experience in **array manipulation** and implementing **application logic** with **CRUD** functionalities.
- Develope **tests(unit, integration, system)** and practicing **debugging techniques** to improve **reliability** and **problem-solving** abilities. 
## Classes
 1. **Date Class**: This class represents a specific date and provides functions to compare dates, sort them, and advance the date by a specified number of days.
 2. **Reservation Class**: The Reservation class encapsulates information about a reservation, including the customer's name, check-in date, and duration of stay. It offers functions to set the duration, check for overlaps with other reservations, compare reservations, and print reservation details.
 3. **Room Class**: The Room class represents a hotel room and contains attributes such as room number, bed type, capacity, and fridge availability. It also maintains an array of Reservation objects for the room. The class provides functions to add reservations, check if a room matches certain criteria, compare rooms, and print room information along with its reservations.
 4. **Hotel Class**: The Hotel class serves as the main control class, managing the interaction between other classes. It maintains an array of Room objects and offers functions to add rooms, delete rooms, retrieve a specific room, add reservations to matching rooms, update reservations based on the current date, and print information about rooms and reservations.
## Run
```c
$ make all
$ ./hotelRes
```
## Tests
 ![image](https://github.com/RafeedN/hotel-reservations/assets/87875513/abb8258f-acda-426a-8a5e-698c600c8e17)
 
![image](https://github.com/RafeedN/hotel-reservations/assets/87875513/94986a94-c22e-4609-84ca-8037bb43911c)

## Clean Traget in the Makefile
Linux:
```c
$ clean:
$   rm -f hotelRes *.o
```
Windows:
```c
$ clean:
$   del /q *.o *.exe
```

