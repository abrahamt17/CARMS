//By Group1 (Github - abrahamt17)

#include <iostream>

#include <string>
using namespace std;

// Structure for car accident record
struct CarAccidentRecord {
    string place;
    string date;
    string time;
    string cause;
    string carModel;
    string carNumber;
    int numDeaths;
    CarAccidentRecord* next;
};

// Function to register a new car accident record
void registerRecord(CarAccidentRecord*& head) {
    
    CarAccidentRecord* newNode = new CarAccidentRecord;
    newNode->next = 0;

    
    cout << "Enter the place of the accident: ";
    getline(cin, newNode->place);
    cout << "Enter the date of the accident (dd/mm/yyyy): ";
    getline(cin, newNode->date);
    cout << "Enter the time of the accident (hh:mm:ss): ";
    getline(cin, newNode->time);
    cout << "Enter the cause of the accident: ";
    getline(cin, newNode->cause);
    cout << "Enter the car model: ";
    getline(cin, newNode->carModel);
    cout << "Enter the car number: ";
    getline(cin, newNode->carNumber);
    cout << "Enter the number of deaths encountered: ";
    cin >> newNode->numDeaths;
    cin.ignore(); 

    
    if (head == 0) {
        head = newNode;
    } else {
        CarAccidentRecord* temp = head;
        while (temp->next != 0) {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    cout << "Record registered successfully." << endl;
}

// Function to search for a car accident record by place of incident
void searchByPlace(CarAccidentRecord* head) {
    string place;
    cout << "Enter the place of the accident to search for: ";
    getline(cin, place);

    bool found = false;
    CarAccidentRecord* temp = head;
    while (temp != 0) {
        if (temp->place == place) {
            cout << "Place: " << temp->place << endl;
            cout << "Date: " << temp->date << endl;
            cout << "Time: " << temp->time << endl;
            cout << "Cause: " << temp->cause << endl;
            cout << "Car Model: " << temp->carModel << endl;
            cout << "Car Number: " << temp->carNumber << endl;
            cout << "Number of Deaths: " << temp->numDeaths << endl << endl;
            found = true;
        }
        temp = temp->next;
    }

    if (!found) {
        cout << "No records found for the given place of incident." << endl;
    }
}

// Function to search for a car accident record by date
void searchByDate(CarAccidentRecord* head) {
    string date;
    cout << "Enter the date of the accident to search for (dd/mm/yyyy): ";
    getline(cin, date);

    bool found = false;
    CarAccidentRecord* temp = head;
    while (temp != 0) {
        if (temp->date == date) {
            cout << "Place: " << temp->place << endl;
            cout << "Date: " << temp->date << endl;
            cout << "Time: " << temp->time << endl;
            cout << "Cause: " << temp->cause << endl;
            cout << "Car Model: " << temp->carModel << endl;
            cout << "Car Number: " << temp->carNumber << endl;
            cout << "Number of Deaths: " << temp->numDeaths << endl << endl;
            found = true;
        }
        temp = temp->next;
    }
    

    if (!found) {
        cout << "No records found for the given date of incident." << endl;
    }
}

// Function to search for a car accident record by car model
void searchByCarModel(CarAccidentRecord* head) {
    string carModel;
    cout << "Enter the car model to search for: ";
    getline(cin, carModel);

    bool found = false;
    CarAccidentRecord* temp = head;
    while (temp != 0) {
        if (temp->carModel == carModel) {
            cout << "Place: " << temp->place << endl;
            cout << "Date: " << temp->date << endl;
            cout << "Time: " << temp->time << endl;
            cout << "Cause: " << temp->cause << endl;
            cout << "Car Model: " << temp->carModel << endl;
            cout << "Car Number: " << temp->carNumber << endl;
            cout << "Number of Deaths: " << temp->numDeaths << endl << endl;
            found = true;
        }
        temp = temp->next;
    }

    if (!found) {
        cout << "No records found for the given car model." << endl;
    }
}

// Function to display all car accident records
void displayRecords(CarAccidentRecord* head) {
    if (head == 0) {
        cout << "No records found." << endl;
        return;
    }

    cout << "List of car accident records:" << endl << endl;
    CarAccidentRecord* temp = head;
    while (temp != 0) {
        cout << "Place: " << temp->place << endl;
        cout << "Date: " << temp->date << endl;
        cout << "Time: " << temp->time << endl;
        cout << "Cause: " << temp->cause << endl;
        cout << "Car Model: " << temp->carModel << endl;
        cout << "Car Number: " << temp->carNumber << endl;
        cout << "Number of Deaths: " << temp->numDeaths << endl << endl;
        temp = temp->next;
    }
}
// Function to delete a car accident record
void deleteRecord(CarAccidentRecord*& head) {
    string place;
    cout << "Enter the place of the accident to delete the record: ";
    getline(cin, place);

    CarAccidentRecord* temp = head;
    CarAccidentRecord* prev = 0;
    while (temp != 0) {
        if (temp->place == place) {
            if (prev == 0) {
                head = head->next;
            } else {
                prev->next = temp->next;
            }
            delete temp;
            cout << "Record deleted successfully." << endl;
            return;
        }
        prev = temp;
        temp = temp->next;
    }

    cout << "No record found for the given place of incident." << endl;
}



// Function to display all car accident records sorted by date
void displayRecordsSortedByDate(CarAccidentRecord* head) {
    if (head == 0) {
        cout << "No records found." << endl;
        return;
    }

    // Sort the linked list by date
    CarAccidentRecord* temp = head;
    while (temp != 0) {
        CarAccidentRecord* minNode = temp;
        CarAccidentRecord* currNode = temp->next;
        while (currNode != 0) {
            if (currNode->date < minNode->date) {
                minNode = currNode;
            }
            currNode = currNode->next;
        }
        swap(temp->place, minNode->place);
        swap(temp->date, minNode->date);
        swap(temp->time, minNode->time);
        swap(temp->cause, minNode->cause);
        swap(temp->carModel, minNode->carModel);
        swap(temp->carNumber, minNode->carNumber);
        swap(temp->numDeaths, minNode->numDeaths);
        temp = temp->next;
    }

    // Display all the records
    cout << "List of car accident records sorted by date:" << endl << endl;
    temp = head;
    while (temp != 0) {
        cout << "Place: " << temp->place << endl;
        cout << "Date: " << temp->date << endl;
        cout << "Time: " << temp->time << endl;
        cout << "Cause: " << temp->cause << endl;
        cout << "Car Model: " << temp->carModel << endl;
        cout << "Car Number: " << temp->carNumber << endl;
        cout << "Number of Deaths: " << temp->numDeaths << endl << endl;
        temp = temp->next;
    }
}




// Main function
int main() {
    CarAccidentRecord* head = 0;
    int choice;

    do {
        cout<<"---------"<<" "<<" MENU"<<"------------"<<endl;
        cout << "CAR ACCIDENT RECORD MANAGEMENT SYSTEM" << endl;
        cout << "1. Register a new car accident record" << endl;
        cout << "2. Search for a car accident record by place of incident" << endl;
        cout << "3. Search for a car accident record by date" << endl;
        cout << "4. Search for a car accident record by car model" << endl;
        cout << "5. Display all car accident records" << endl;
         cout << "6. Delete previous record" << endl;
         cout<<"7.display sorted recored by date"<<endl;
        
		cout << "8. Exit" << endl;
        cout << "Enter your choice: "<<endl;
		cout<<"If you Want to Exit press 0"<<endl;
        cin >> choice;
        cin.ignore(); 

        
        switch (choice) {
            case 1:
                registerRecord(head);
                break;
            case 2:
                searchByPlace(head);
                break;
            case 3:
                searchByDate(head);
                break;
            case 4:
                searchByCarModel(head);
                break;
            case 5:
                displayRecords(head);
                break;
            case 6:
            	deleteRecord(head);
            	break;
            case 7:
                displayRecordsSortedByDate(head);
                break;
           
        
            case 8:
            	cout << "Exiting the program..." << endl;
            	break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice !=8 );

    // Free the memory allocated for the linked list
    
    
    CarAccidentRecord* temp = head;
    while (temp != 0) {
        head = head->next;
        delete temp;
        temp = head;
    }

    return 0;
}