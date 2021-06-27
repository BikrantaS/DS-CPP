#include <iostream>
#include <bits/stdc++.h>
using namespace std;


//Selcetion Sort is Unstable
void selectionSort(int arr[],int n)
{
    for (int i = 0; i < n-1; i++)
    {
       int min_index=i;
       for (int j = i+1; j < n; j++)
       {
           if(arr[j]<arr[min_index])
            min_index=j;
       }
       swap(arr[min_index],arr[i]);
    }
}

int main()
{
	int a[]={34,67,21,77,11};
    selectionSort(a,5);
    for (int i = 0; i < 5; ++i)
    {
       cout<<a[i]<<" ";
    }

	return 0;
}


