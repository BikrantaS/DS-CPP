#include <iostream>

using namespace std;


//Bubble Sort is Stable
void bubbleSort(int arr[],int n)
{
    for (int i = 0; i < n-1; i++)
    {
       bool swapped=false;
       for (int j = 0; j<n-i-1; j++)
       {
           if(arr[j]>arr[j+1])
            {
               swap(arr[j],arr[j+1]);
               swapped=true;
            }
       }
       if(swapped==false)
         break;
    }
}

int main()
{
	int a[]={34,67,21,77,11};
    bubbleSort(a,5);
    for (int i = 0; i < 5; ++i)
    {
       cout<<a[i]<<" ";
    }

	return 0;
}


