//STUDENT MANAGEMENT SYSTEM -CORRECT ONE
#include<iostream>
#include<string>
using namespace std;

struct Student {
    string name;
    string rollNo;
    int age;
};

const int MAX_SIZE = 20;
Student arr[MAX_SIZE];
int total = 0;

void insert() {
    if (total < MAX_SIZE) {
        Student s;
        cout << "Enter Roll no: ";
        cin >> s.rollNo;
        cout << "Enter name: ";
        cin >> s.name;
        cout << "Enter Age: ";
        cin >> s.age;

        arr[total++] = s;
        cout << "STUDENT INSERTED SUCCESSFULLY!.." << endl;
    }
    else {
        cout << "Maximum limit reached. Cannot insert more students." << endl;
    }
}

void update() {
    string rollNo;
    cout << "Enter roll number of the student to update: ";
    cin >> rollNo;
    
    bool exitFlag = false;
    while (!exitFlag) {
        cout << "What do you want to update?" << endl;
        cout << "a. Name" << endl;
        cout << "b. Age" << endl;
        cout << "c. Exit" << endl;
        char choice;
        cout<<"Enter your choice: "<<endl;
        cin >> choice;
        
        switch (choice) {
            case 'a':
                cout << "Enter updated name: "<<endl;
                cin >> arr[total-1].name;
                cout << "STUDENT UPDATED SUCCESSFULLY!.." << endl;
                break;
                
            case 'b':
                cout << "Enter new age: ";
                cin >> arr[total-1].age;
                cout << "Age updated successfully!" << endl;
                break;
                
            case 'c':
            	cout<<"OK... GO TO MENU ...."<<endl;
                exitFlag = true;
                break;
                
            default:
                cout << "Invalid choice!" << endl;
                break;
        }
    }
}

void deleteStudent() {
    string rollNo;
    cout << "Enter roll number of the student to delete: ";
    cin >> rollNo;
    
    for (int i = 0; i < total; i++) {
        if (arr[i].rollNo == rollNo) {
            for (int j = i; j < total - 1; j++) {
                arr[j] = arr[j + 1];
            }
            total--;
            cout << "Student deleted successfully!" << endl;
            return;
        }
    }
    
    cout << "Student not found!" << endl;
}

void show() {
    if (total == 0) {
        cout << "No students found!" << endl;
        return;
    }
    
    for (int i = 0; i < total; i++) {
        cout << "--- Student Records ---" << i + 1 << endl;
        cout << "Name: " << arr[i].name << endl;
        cout << "Roll no: " << arr[i].rollNo << endl;
        cout << "Age: " << arr[i].age << endl;
        cout << "-------------------------------" << endl;
    }
}

void search() {
    string rollNo;
    cout << "Enter roll number of the student to search: ";
    cin >> rollNo;

    for (int i = 0; i < total; i++) {
        if (arr[i].rollNo == rollNo) {
            cout << "Name: " << arr[i].name << endl;
            cout << "Roll no: " << arr[i].rollNo << endl;
            cout << "Age: " << arr[i].age << endl;
            return;
        }
    }

    cout << "Student not found!" << endl;
}

int main() {
    int value;

    while(true) {
    	cout<<"\n<<<<<<< Student Management System >>>>>>>>"<<endl;
        cout << "\n 1. Insert Student" << endl;
        cout << " 2. Update Student" << endl;
        cout << " 3. Delete Student" << endl;
        cout << " 4. Show Students" << endl;
        cout << " 5. Search Student" << endl;
        cout << " 0. exit" << endl;
        cout<<"Enter your choice: "<<endl;
        cin >> value;

        switch(value) {
            case 1:
                insert();
                break;

            case 2:
                update();
                break;

            case 3:
                deleteStudent();
                break;

            case 4:
                show();
                break;

            case 5:
                search();
                break;

            case 0:
            	cout<<"*************************************** EXIT PROGRAM ***************************************"<<endl;
                exit(0);
                break;

            default:
                cout << "Invalid input" << endl;
                break;
        }
    }

    return 0;
}

