#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>

using namespace std;

void heapify(vector<int>& arr, int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest]) {
        largest = left;
    }

    if (right < n && arr[right] > arr[largest]) {
        largest = right;
    }

    if (largest != i) {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

void heapSort(vector<int>& arr) {
    int n = arr.size();

    for (int i = n / 2 - 1; i >= 0; --i) {
        heapify(arr, n, i);
    }

    for (int i = n - 1; i > 0; --i) {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}

int main() {
    srand(time(nullptr));

    int n;
    cout << "Enter the number of elements: ";
    cin >> n;

    vector<int> arr(n);

    int choice;
    cout << "Choose input method:\n";
    cout << "1. Manual entry\n";
    cout << "2. Random number generator\n";
    cout << "Choice: ";
    cin >> choice;

    if (choice == 1) {
        cout << "Enter the elements:\n";
        for (int i = 0; i < n; ++i) {
            cin >> arr[i];
        }
    } else if (choice == 2) {
        for (int i = 0; i < n; ++i) {
            arr[i] = rand() % 10000; // Generate random numbers between 0 and 9999
        }
    } else {
        cout << "Invalid choice.\n";
        return 1;
    }

    clock_t start = clock();
    heapSort(arr);
    clock_t end = clock();

    double timeTaken = static_cast<double>(end - start) / CLOCKS_PER_SEC;

    cout << "Sorted array:\n";
    for (int i = 0; i < n; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;

    cout << "Time taken: " << timeTaken << " seconds\n";

    return 0;
}
