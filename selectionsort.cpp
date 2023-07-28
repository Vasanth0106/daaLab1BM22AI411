//CPP to implement selection sort
#include<iostream>
#define SIZE 10
using namespace std;

class s_sort
{
    public :
    int a[SIZE];
    int temp;
    

    void getdata()
    {
        for(int i=0;i<SIZE-1;i++)
        {
            a[i]=rand()%1000;
        }

        cout<<"Before sorting \n";
        for(int i=0;i<SIZE;i++)
        {
            cout<<a[i]<<"\t";
        }
        cout<<::endl;
    }
    void sort()
    {
        clock_t req_time;
        for(int i=0;i<SIZE-1;i++)
        {
            
            for(int j=i+1;j<SIZE;j++)
            {
                req_time = clock();
                if(a[j]<a[i])
                {
                 
                    temp=a[j];
                    a[j]=a[i];
                    a[i]=temp;
                }
                req_time=clock();
                
            }
        }
        req_time=clock();

        cout<<"After sorting \n";
        for(int i=0;i<SIZE;i++)
        {
            cout<<a[i]<<"\t";
        }
        cout<<"\n It took "<< (float) (req_time)/(CLOCKS_PER_SEC)<<" seconds";
    }
};

int main()
{
    s_sort selectionSort;
    selectionSort.getdata();
    selectionSort.sort();
    
}
