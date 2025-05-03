#include <iostream>
#include <string.h>
using namespace std;

class HashFunction {
    typedef struct hash {
        long key;
        char name[10];
    } hash;

    hash h[10];

public:
    HashFunction();
    void insert();
    void display();
    int find(long);
    void Delete(long);
};

HashFunction::HashFunction() {
    for (int i = 0; i < 10; i++) {
        h[i].key = -1;
        strcpy(h[i].name, "NULL");
    }
}

void HashFunction::Delete(long k) {
    int index = find(k);
    if (index == -1) {
        cout << "Key Not Found" << endl;
    } else {
        h[index].key = -1;
        strcpy(h[index].name, "NULL");
        cout << "Key is Deleted" << endl;
    }
}

int HashFunction::find(long k) {
    for (int i = 0; i < 10; i++) {
        if (h[i].key == k) {
            cout << h[i].key << " is Found at " << i << " Location With Name " << h[i].name << endl;
            return i;
        }
    }
    return -1;
}

void HashFunction::display() {
    cout << "Key\t\tName" << endl;
    for (int i = 0; i < 10; i++) {
        // HERE WE ARE USING \t MEANS "horizontal tab spaces"
        cout << "h[" << i << "]\t" << h[i].key << "\t\t" << h[i].name << endl;
    }
}

void HashFunction::insert() {
    char ans, n[10], ntemp[10];
    long k, temp;
    int v, hi, cnt = 0, flag = 0, i;

    do {
        if (cnt >= 10) {
            cout << "Hash Table is FULL" << endl;
            break;
        }

        cout << "Enter a Telephone No: ";
        cin >> k;
        cout << "Enter a Client Name: ";
        cin >> n;

        hi = k % 10;

        if (h[hi].key == -1) {
            h[hi].key = k;
            strcpy(h[hi].name, n);
        } else {
            if (h[hi].key % 10 != hi) {
                temp = h[hi].key;
                strcpy(ntemp, h[hi].name);
                h[hi].key = k;
                strcpy(h[hi].name, n);

                for (i = hi + 1; i < 10; i++) {
                    if (h[i].key == -1) {
                        h[i].key = temp;
                        strcpy(h[i].name, ntemp);
                        flag = 1;
                        break;
                    }
                }

                for (i = 0; i < hi && flag == 0; i++) {
                    if (h[i].key == -1) {
                        h[i].key = temp;
                        strcpy(h[i].name, ntemp);
                        break;
                    }
                }
            } else {
                for (i = hi + 1; i < 10; i++) {
                    if (h[i].key == -1) {
                        h[i].key = k;
                        strcpy(h[i].name, n);
                        flag = 1;
                        break;
                    }
                }

                for (i = 0; i < hi && flag == 0; i++) {
                    if (h[i].key == -1) {
                        h[i].key = k;
                        strcpy(h[i].name, n);
                        break;
                    }
                }
            }
        }

        flag = 0;
        cnt++;

        cout << ".....Do You Want to Insert More Key (y/n): ";
        cin >> ans;
    } while (ans == 'y' || ans == 'Y');
}

int main() {
    long k;
    int ch, index;
    char ans;
    HashFunction obj;

    do {
        cout << "***** Telephone Directory (ADT) *****" << endl;
        cout << "1. Insert" << endl;
        cout << "2. Display" << endl;
        cout << "3. Find" << endl;
        cout << "4. Delete" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter Your Choice: ";
        cin >> ch;

        switch (ch) {
        case 1:
            obj.insert();
            break;
        case 2:
            obj.display();
            break;
        case 3:
            cout << "Enter a Key Which You Want to Search: ";
            cin >> k;
            index = obj.find(k);
            if (index == -1) {
                cout << "Key Not Found" << endl;
            }
            break;
        case 4:
            cout << "Enter a Key Which You Want to Delete: ";
            cin >> k;
            obj.Delete(k);
            break;
        case 5:
            break;
        default:
            cout << "Invalid choice!" << endl;
        }

        cout << ".....Do You Want to Continue in Main Menu (y/n): ";
        cin >> ans;
    } while (ans == 'y' || ans == 'Y');

    return 0;
}
