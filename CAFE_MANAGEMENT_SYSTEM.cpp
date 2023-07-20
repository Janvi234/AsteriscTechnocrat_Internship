#include <iostream>
using namespace std;

struct MenuItem {
    string name;
    int price;
    int quantity; // new member variable to store quantity
};

const int MAX_SIZE = 3;
MenuItem menu[MAX_SIZE] = {{"Samosa", 20, 0}, {"Dosa", 30, 0}, {"Tea", 10, 0}};

void displayMenu() {
    cout << "Menu:" << endl;
    for (int i = 0; i < MAX_SIZE; i++) {
        cout << i+1 << " " << menu[i].name << " " << menu[i].price << "/-" << endl;
    }
    cout << "0 Exit" << endl;
}

void calculateBill() {
    int choice;
    int totalBill = 0;
    int quantity;

    while (true) {
        displayMenu();
        cout << "Enter your Choice : ";
        cin >> choice;

        if (choice == 0) {
            break;
        }
        else if (choice < 0 || choice > MAX_SIZE) {
            cout << "Invalid choice. Please try again." << endl;
            continue;
        }

        cout << "Enter number of plates : ";
        cin >> quantity;

        menu[choice-1].quantity += quantity; // update quantity of selected item

        cout << endl;
    }

    cout << "::Your Bill::" << endl;
    cout << "Sr.No. | Item | Qty | Rate | Sub Total" << endl;
    cout << "-------------------------------------------------------------------" << endl;

    int itemNumber = 1;
    for (int i = 0; i < MAX_SIZE; i++) {
        if (menu[i].quantity > 0) {
            cout << itemNumber << " | " << menu[i].name << " | " << menu[i].quantity << " | " << menu[i].price << " | " << menu[i].price * menu[i].quantity << "/-" << endl;
            totalBill += menu[i].price * menu[i].quantity;
            itemNumber++;
        }
    }

    cout << "-------------------------------------------------------------------" << endl;
    cout << "Grand Total: " << totalBill << "/-" << endl;

    int cash;
    cout << "\nEnter Your Cash: ";
    cin >> cash;

    if (cash > totalBill) {
        int returnAmount = cash - totalBill;
        cout << "Return Amount: " << returnAmount << endl;
    } else if (cash < totalBill) {
        while (cash < totalBill) {
            cout << "Please pay " << totalBill - cash << " Rs. more" << endl;
            cout << "Enter Your Cash: ";
            cin >> cash;
        }
    }

    cout << "\n----- T H A N K  Y O U! -------" << endl;
    cout << "************************************************************** VISIT AGAIN *****************************************" << endl;
}

int main() {
    cout << "***** Welcome to XYZ Hotel! *****" << endl;
    calculateBill();
    return 0;
}

