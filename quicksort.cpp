//cpp program to implement quick sort @ 11-7-23
#include<iostream>
#define SIZE 10
using namespace std;

class QuickSort
{
public:
    int a[SIZE],count=0;
    void sort(int[], int, int);
    int partition(int[], int, int);
    void printArray();
    void getInput();
};

void QuickSort::getInput()
{
    for (int i = 0; i < SIZE; i++)
    {
        a[i] = rand() % 100;
        cout << a[i] << " ";
    }
    sort(a, 0, SIZE - 1);
}

void QuickSort::printArray()
{
    for (int i = 0; i < SIZE; i++)
    {
        cout << a[i] << " ";
    }
}

int QuickSort::partition(int a[], int low, int high)
{
    int pivot = a[high]; // Choose the last element as the pivot
    int i = low - 1;

    for (int j = low; j <= high - 1; j++)
    {
        if (a[j] < pivot)
        {
            i++;
            swap(a[i], a[j]);
        }
    }
    swap(a[i + 1], a[high]);
    return i + 1;
}

void QuickSort::sort(int a[], int low, int high)
{
    if (low < high)
    {
        count++;
        int pi = partition(a, low, high);
        sort(a, low, pi - 1);
        sort(a, pi + 1, high);
    }
}

int main()
{
    QuickSort qsort;
    cout << "Before sorting \n";
    qsort.getInput();
    cout << "\nAfter sorting \n";
    qsort.printArray();
    cout<<"\nBasic operation executed "<<qsort.count<<" times ";
    return 0;
}
