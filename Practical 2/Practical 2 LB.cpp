#include <iostream>
using namespace std;

// Linear Search
int linear(int array[], int s, int t) {
    for (int i = 0; i < s; i++) {
        if (array[i] == t) {
            return i;
        }
    }
    return -1;
}

// Binary Search
int binary(int array[], int s, int t) {
    int l = 0;
    int h = s - 1;

    while (l <= h) {
        int m = (l + h) / 2;

        if (array[m] == t) {
            return m;
        }
        else if (array[m] < t) {
            l = m + 1;
        }
        else {
            h = m - 1;
        }
    }

    return -1;
}

// Display Array
void display(int array[], int n) {
    cout << "Array is:\n";

    for (int i = 0; i < n; i++) {
        cout << array[i] << " ";
    }

    cout << endl;
}

int main() {

    int array[] = {2, 6, 7, 9, 11};
    int n = sizeof(array) / sizeof(array[0]);

    int t = 6;

    display(array, n);

    int f = linear(array, n, t);
    int g = binary(array, n, t);

    cout << "\nTarget element: " << t << endl;

    if (f != -1) {
        cout << "Linear Search: Element found at index " << f << endl;
    }
    else {
        cout << "Linear Search: Element not found" << endl;
    }

    if (g != -1) {
        cout << "Binary Search: Element found at index " << g << endl;
    }
    else {
        cout << "Binary Search: Element not found" << endl;
    }

    return 0;
}
