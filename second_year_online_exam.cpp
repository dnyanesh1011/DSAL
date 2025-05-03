#include <iostream>
using namespace std;

class Heap {
    int n;
    int *minheap, *maxheap;

public:
    void get();
    void displayMin() { cout << "Minimum marks are: " << minheap[0] << endl; }
    void displayMax() { cout << "Maximum marks are: " << maxheap[0] << endl; }
    void upAdjust(bool isMaxHeap, int index);
};

void Heap::get() {
    cout << "Enter number of students:" << endl;
    cin >> n;
    int k;
    minheap = new int[n];
    maxheap = new int[n];

    cout << "Enter marks of students:" << endl;
    for (int i = 0; i < n; i++) {
        cin >> k;

        minheap[i] = k;
        upAdjust(false, i);

        maxheap[i] = k;
        upAdjust(true, i);
    }
}

void Heap::upAdjust(bool isMaxHeap, int index) {
    int temp;
    if (isMaxHeap) {
        while (index > 0 && maxheap[(index - 1) / 2] < maxheap[index]) {
            temp = maxheap[index];
            maxheap[index] = maxheap[(index - 1) / 2];
            maxheap[(index - 1) / 2] = temp;
            index = (index - 1) / 2;
        }
    } else {
        while (index > 0 && minheap[(index - 1) / 2] > minheap[index]) {
            temp = minheap[index];
            minheap[index] = minheap[(index - 1) / 2];
            minheap[(index - 1) / 2] = temp;
            index = (index - 1) / 2;
        }
    }
}

int main() {
    Heap H;
    H.get();
    H.displayMin();
    H.displayMax();
    return 0;
}
