#include <iostream>
#include <unordered_map>
#include <vector>
class SportsFacility {
private:
    std::string name;
    int totalSlots;
    std::unordered_map<int, std::string> slots;

public:
    SportsFacility(std::string n, int total) {
        name = n;
        totalSlots = total;
        for (int i = 1; i <= totalSlots; ++i) {
            slots[i] = "";
        }
    }
    void bookSlot(int slot, std::string rollNumber) {
        //slot is valid or not
        if (slot >= 1 && slot <= totalSlots && slots[slot] == "") {
            // book on roll number
            slots[slot] = rollNumber;
            std::cout << "Slot " << slot << " booked successfully for roll number " << rollNumber << "." << std::endl;
        } else {
            std::cout << "Slot " << slot << " is either unavailable or invalid." << std::endl;
        }
    }
    // check availability of a slot
    void checkAvailability(int slot) {
        if (slot >= 1 && slot <= totalSlots) {
            if (slots[slot] == "") {
                std::cout << "Slot " << slot << " is available." << std::endl;
            } else {
                std::cout << "Slot " << slot << " is already booked by roll number " << slots[slot] << "." << std::endl;
            }
        } else {
            std::cout << "Slot " << slot << " is invalid." << std::endl;
        }
    }
    //availability of all slots
    void displayAvailability() {
        std::cout << "Availability for " << name << ":" << std::endl;
        for (const auto& [slot, bookedBy] : slots) {
            if (bookedBy == "") {
                std::cout << "Slot " << slot << ": Available" << std::endl;
            } else {
                std::cout << "Slot " << slot << ": Booked by " << bookedBy << std::endl;
            }
        }
    }
};
//track of booking history
class BookingHistory {
private:
    struct Booking {
        std::string facility;
        int slot;
        std::string rollNumber;
    };
    std::vector<Booking> history;

public:
    void addBooking(std::string facilityName, int slot, std::string rollNumber) {
        history.push_back({facilityName, slot, rollNumber});
    }

    //display booking history
    void displayHistory() {
        std::cout << "Booking History:" << std::endl;
        for (const auto& booking : history) {
            std::cout << "Facility: " << booking.facility << ", Slot: " << booking.slot << ", Booked by: " << booking.rollNumber << std::endl;
        }
    }
};
int main() {
    SportsFacility gym("Gym", 5);
    SportsFacility squashCourt("Squash Court", 3);

    BookingHistory history;

    gym.bookSlot(1, "A123");
    gym.bookSlot(3, "B456");
    gym.displayAvailability();

    squashCourt.bookSlot(2, "C789");
    squashCourt.displayAvailability();

    //error cases
    gym.bookSlot(1, "D101");
    gym.checkAvailability(5);
    gym.bookSlot(7, "E202");

    history.addBooking("Gym", 1, "A123");
    history.addBooking("Gym", 3, "B456");
    history.addBooking("Squash Court", 2, "C789");

    history.displayHistory();

    return 0;
}
