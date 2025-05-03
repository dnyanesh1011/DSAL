#include <iostream>
#include <stdlib.h>
#include <string.h>
using namespace std;

struct node {
    string vertex;
    int time;
    node* next;
};

class adjmatlist {
    int m[10][10], n, i, j;
    char ch;
    string v[20];
    node* head[20];
    node* temp = NULL;

public:
    adjmatlist() {
        for (i = 0; i < 20; i++) {
            head[i] = NULL;
        }
    }

    void getgraph();
    void adjlist();
    void displaym();
    void displaya();
};

void adjmatlist::getgraph() {
    cout << "Enter no. of cities (max 20): ";
    cin >> n;

    cout << "Enter names of cities:" << endl;
    for (i = 0; i < n; i++)
        cin >> v[i];

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            cout << "Is there a path from " << v[i] << " to " << v[j] << "? (y/n): ";
            cin >> ch;

            if (ch == 'y') {
                cout << "Enter time required to reach " << v[j] << " from " << v[i] << " in minutes: ";
                cin >> m[i][j];
            } else if (ch == 'n') {
                m[i][j] = 0;
            } else {
                cout << "Unknown entry!" << endl;
            }
        }
    }

    adjlist();
}

void adjmatlist::adjlist() {
    cout << "Creating adjacency list..." << endl;
    for (i = 0; i < n; i++) {
        node* p = new node;
        p->next = NULL;
        p->vertex = v[i];
        head[i] = p;
        cout << head[i]->vertex << endl;
    }

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (m[i][j] != 0) {
                node* p = new node;
                p->vertex = v[j];
                p->time = m[i][j];
                p->next = NULL;

                if (head[i]->next == NULL) {
                    head[i]->next = p;
                } else {
                    temp = head[i];
                    while (temp->next != NULL) {
                        temp = temp->next;
                    }
                    temp->next = p;
                }
            }
        }
    }
}

void adjmatlist::displaym() {
    cout << endl << "Adjacency Matrix:" << endl << "\t";
    for (j = 0; j < n; j++) {
        cout << v[j] << "\t";
    }
    for (i = 0; i < n; i++) {
        cout << endl << v[i] << "\t";
        for (j = 0; j < n; j++) {
            cout << m[i][j] << "\t";
        }
    }
    cout << endl;
}

void adjmatlist::displaya() {
    cout << "Adjacency list is:" << endl;

    for (i = 0; i < n; i++) {
        if (head[i] == NULL) {
            cout << "Adjacency list not present" << endl;
            break;
        } else {
            cout << head[i]->vertex;
            temp = head[i]->next;
            while (temp != NULL) {
                cout << " -> " << temp->vertex;
                temp = temp->next;
            }
            cout << endl;
        }
    }

    cout << endl << "Path and time required to reach cities:" << endl;
    for (i = 0; i < n; i++) {
        if (head[i] == NULL) {
            cout << "Adjacency list not present" << endl;
            break;
        } else {
            temp = head[i]->next;
            while (temp != NULL) {
                cout << head[i]->vertex << " -> " << temp->vertex << endl;
                cout << "   [time required: " << temp->time << " min]" << endl;
                temp = temp->next;
            }
        }
    }
}

int main() {
    int m;
    adjmatlist a;

    while (1) {
        cout << endl << "Enter your choice:" << endl;
        cout << "1. Enter graph" << endl;
        cout << "2. Display adjacency matrix for cities" << endl;
        cout << "3. Display adjacency list for cities" << endl;
        cout << "4. Exit" << endl;
        cout << "Choice: ";
        cin >> m;

        switch (m) {
        case 1: a.getgraph(); break;
        case 2: a.displaym(); break;
        case 3: a.displaya(); break;
        case 4: exit(0);
        default: cout << "Unknown choice!" << endl;
        }
    }

    return 0;
}
