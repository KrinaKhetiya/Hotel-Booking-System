#include <iostream>
#include <string>
using namespace std;

// for room
class Room {
   public:
    int roomNumber;
    string customerName;
    bool isBooked;

    Room(int number) {
        roomNumber = number;
        isBooked = false;
    }

void displayRooms()
    {
        cout << "\nRoom Status:\n";
        for (int i = 0; i < MAX_ROOMS; i++)
        {
            rooms[i]->displayRoom();
        }
    }
};

// for hotel system
class Hotel {
private:
    static const int MAX_ROOMS = 10;
    Room* rooms[MAX_ROOMS];

public:
    Hotel() {
        for (int i = 0; i < MAX_ROOMS; i++) {
            rooms[i] = new Room(i + 1);
        }
    }

    ~Hotel() {
        for (int i = 0; i < MAX_ROOMS; i++) {
            delete rooms[i];
        }
    }


void displayRooms()
    {
        cout << "\nRoom Status:\n";
        for (int i = 0; i < MAX_ROOMS; i++)
        {
            rooms[i]->displayRoom();
        }
    }

};


int main() {
    
    
    do {
        cout << "\nHotel Booking System\n";
        cout << "1. Display all rooms\n";
        cout << "2. Book a room\n";
        cout << "3. Cancel a booking\n";
        cout << "4. Modify a booking\n";
        cout << "5. Exit\n";
        cout << "Enter your choice (1-5): ";
        cin >> choice;
        
        switch (choice) {
            case 1:
                hotel.displayRooms();
                break;
            case 2:
                hotel.bookRoom();
                break;
            case 3:
                hotel.cancelBooking();
                break;
            case 4:
                hotel.modifyBooking();
                break;
            case 5:
                cout << "Exiting the system.\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 5);
    
    return 0;
}

