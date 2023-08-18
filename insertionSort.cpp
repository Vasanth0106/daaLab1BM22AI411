//cpp program for insertion sort @ 18/08/2023
#include <iostream>
#define SIZE 10

void getInput(int arr[],int n){
    
    for(int i=0;i<n;i++)
    {
        arr[i]=rand()%100;
    }
}

void printArray(int arr[],int n)
{
    for(int i=0;i<n;i++)
    {
        std::cout<<arr[i]<<" ";
    }
    std::cout<<std::endl;
}


void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; ++i) {
        int key = arr[i];
        int j = i - 1;
        
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

int main() {
    int arr[SIZE];
    
    getInput(arr,SIZE-1);
  
    std::cout<<"Before sorting : "<<std::endl;
    printArray(arr,SIZE-1);
  
    insertionSort(arr, SIZE-1);
  
    std::cout<<"After sorting : "<<std::endl;
    printArray(arr,SIZE-1);

    return 0;
}
