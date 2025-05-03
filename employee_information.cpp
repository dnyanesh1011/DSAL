#include <iostream>
#include <iomanip>
using namespace std;

#define max 10

struct employee {
    string name;
    long int employee_id;
    string designation;
    int salary;
};

int num = -1;
employee emp[max];

void insert() {
    if (num < max - 1) {
        num++;
        cout << "Enter the information of the Employee" << endl;

        cout << "Employee ID: ";
        cin >> emp[num].employee_id;

        cout << "Name: ";
        cin >> emp[num].name;

        cout << "Designation: ";
        cin >> emp[num].designation;

        cout << "Salary: ";
        cin >> emp[num].salary;
    } else {
        cout << "Employee Table Full" << endl;
    }
}

void deleteIndex(int i) {
    for (int j = i; j < num; j++) {
        emp[j] = emp[j + 1];
    }
}

void displayAllRecords() {
    if (num == -1) {
        cout << "No records present!" << endl;
    } else {
        cout << endl << setw(5) << "ID" << setw(10) << "NAME" << setw(18) << "DESIGNATION" << setw(10) << "SALARY" << endl;
        for (int i = 0; i <= num; i++) {
            cout << setw(5) << emp[i].employee_id << setw(10) << emp[i].name << setw(18) << emp[i].designation << setw(10) << emp[i].salary << endl;
        }
    }
}

void deleteRecord() {
    int employee_id;
    cout << "Enter the Employee ID to Delete Record: ";
    cin >> employee_id;

    for (int i = 0; i <= num; i++) {
        if (emp[i].employee_id == employee_id) {
            deleteIndex(i);
            num--;
            cout << "Record deleted successfully." << endl;
            return;
        }
    }
    cout << "Employee record not found." << endl;
}

void searchRecord() {
    int employee_id;
    cout << "Enter the Employee ID to Search Record: ";
    cin >> employee_id;

    for (int i = 0; i <= num; i++) {
        if (emp[i].employee_id == employee_id) {
            cout << endl << setw(5) << "ID" << setw(10) << "NAME" << setw(18) << "DESIGNATION" << setw(10) << "SALARY" << endl;
            cout << setw(5) << emp[i].employee_id << setw(10) << emp[i].name << setw(18) << emp[i].designation << setw(10) << emp[i].salary << endl;
            return;
        }
    }

    cout << "Employee record not found." << endl;
}

int main() {
    int option = 0;

    while (option != 5) {
        cout << endl << "----- Employee Management System -----" << endl;
        cout << "1. Insert New Record" << endl;
        cout << "2. Display all Records" << endl;
        cout << "3. Delete Record" << endl;
        cout << "4. Search Record by Employee ID" << endl;
        cout << "5. Exit" << endl;

        cout << "Enter your choice: ";
        cin >> option;

        switch (option) {
            case 1:
                insert();
                break;
            case 2:
                displayAllRecords();
                break;
            case 3:
                deleteRecord();
                break;
            case 4:
                searchRecord();
                break;
            case 5:
                cout << "***** You have exited *****" << endl;
                break;
            default:
                cout << "Enter valid option!" << endl;
                break;
        }
    }

    return 0;
}
