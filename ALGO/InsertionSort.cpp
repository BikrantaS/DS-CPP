#include <iostream>

using namespace std;


//Insertion Sort is Stable
void insertionSort(int arr[],int n)
{
    
    for(int i=1;i<n;i++)
    {
        int key = arr[i];
        int j=i-1;
        while(j>=0 && arr[j]>key)
        {
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=key;
    }
}


int main()
{
	int a[]={34,67,21,77,11};
    insertionSort(a,5);
    for (int i = 0; i < 5; ++i)
    {
       cout<<a[i]<<" ";
    }

	return 0;
}


