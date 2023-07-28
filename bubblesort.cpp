#include <iostream>
using namespace std;
#define SIZE 10
class bubbleSort
{
public:
    int a[SIZE], temp;
    void getInput();
    clock_t req_time;
    void sort();
};

void bubbleSort::getInput()
{
    for (int i = 0; i < SIZE; i++)
    {
        a[i] = rand() % 1000;
    }
}

void bubbleSort::sort()
{
    cout << "Array before sorting" << endl;
    for (int i = 0; i < SIZE; i++)
    {
        cout << a[i] << "\t";
    }
    cout << endl;

    for (int i = 0; i < SIZE - 1; i++)
    {
        for (int j = i + 1; j < SIZE; j++)
        {
            req_time = clock();
            if (a[i] > a[j])
            {
                temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
            req_time = clock() - req_time;
        }
    }

    cout << "Array after sorting" << endl;
    for (int i = 0; i < SIZE; i++)
    {
        cout << a[i] << "\t";
    }
    cout << endl;

    cout << "It took " << ((float)(req_time) / CLOCKS_PER_SEC) << " seconds";
}

int main()
{
    bubbleSort bSort;
    bSort.getInput();
    bSort.sort();
}
