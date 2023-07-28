#include<iostream>
#define SIZE 10
using namespace std;

class MergeSort
{
    public :
    int a[SIZE];
    int count=0;
    void divide(int[],int,int);
    void sort(int[],int,int,int);
    void printArray();
    void getInput();
};

void MergeSort::getInput()
{
    for(int i=0;i<SIZE;i++)
    {
        a[i]=rand()%100;
        cout<<a[i]<<" ";
    }
    divide(a,0,SIZE-1);
}

void MergeSort::printArray()
{
    for(int i=0;i<SIZE;i++)
    {
        cout<<a[i]<<" ";
    }
}

void MergeSort::divide(int a[],int start, int end)
{
    int mid=(start+end)/2;
    if(start<end)
    {
        count++;
        divide(a,start,mid);
        divide(a,mid+1,end);
        sort(a,start,mid,end);
    }
}

void MergeSort::sort(int a[],int start, int mid, int end)
{
    int n1=mid-start+1;
    int n2=end-mid;

    int left_array[n1],right_array[n2];

    for(int i=0;i<n1;i++)
    {
        left_array[i]=a[start+i];
    }

    for(int i=0;i<n2;i++)
    {
        right_array[i]=a[mid+i+1];
    }
    
    int i=0,j=0,k=start;
    while(i<n1&&j<n2)
    {
        if(left_array[i]<=right_array[j]){
        a[k]=left_array[i];
        i++;
        }
        else
        {
            a[k]=right_array[j];
            j++;
        }
        k++;
    }
    while(i<n1)
    {
        a[k]=left_array[i];
        i++;
        k++;
    }
    while(j<n2)
    {
        a[k]=right_array[j];
        j++;
        k++;
    }
}

int main()
{
    MergeSort msort;
    cout<<"Before sorting \n";
    msort.getInput();
    cout<<"\nAfter sorting \n";
    msort.printArray();
    cout<<"\nBasic operation executed "<< msort.count<<" times";
    
    return 0;
}
