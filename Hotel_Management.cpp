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
void bookRoom(string name) {
        if (isBooked) {
            cout << "Sorry, this room is already booked.\n";
        } else {
            customerName = name;
            isBooked = true;
            cout << "Room " << roomNumber << " successfully booked for " << name << "!\n";
        }
   void modifyBooking(string newName) {
        if (!isBooked) {
            cout << "This room is not booked.\n";
        } else {
            customerName = newName;
            cout << "Booking for room " << roomNumber << " successfully modified.\n";
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
       void cancelBooking() {
        if (!isBooked) {
            cout << "This room is not booked.\n";
        } else {
            isBooked = false;
            customerName = "";
            cout << "Booking for room " << roomNumber << " canceled.\n";
        }
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

}
void bookRoom() {
        int roomChoice;
        string name;
        
        cout << "Enter your name: ";
        cin >> name;
        
        cout << "Enter the room number to book (1 to " << MAX_ROOMS << "): ";
        cin >> roomChoice;
        
        if (roomChoice < 1 || roomChoice > MAX_ROOMS) {
            cout << "Invalid room number. Please try again.\n";
            return;
        }
        
        rooms[roomChoice - 1]->bookRoom(name);
    }
void cancelBooking() {
        int roomChoice;
        
        cout << "Enter the room number to cancel booking (1 to " << MAX_ROOMS << "): ";
        cin >> roomChoice;
        
        if (roomChoice < 1 || roomChoice > MAX_ROOMS) {
            cout << "Invalid room number. Please try again.\n";
            return;
        }
        
        rooms[roomChoice - 1]->cancelBooking();

    void modifyBooking() {
        int roomChoice;
        
        cout << "Enter the room number to modify booking (1 to " << MAX_ROOMS << "): ";
        cin >> roomChoice;
        
        if (roomChoice < 1 || roomChoice > MAX_ROOMS) {
            cout << "Invalid room number. Please try again.\n";
            return;
        }
        
        string newName;
        cout << "Enter the new name for the booking: ";
        cin >> newName;
        
        rooms[roomChoice - 1]->modifyBooking(newName);
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

