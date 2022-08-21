#include <iostream>
using namespace std;


//Iterative
int binarySearch(int arr[],int n,int x)
{
   int low=0,high=n-1;
   while(low<=high)
   {
      int mid=(low+high)/2;
      if(arr[mid]==x)return mid;
      else if(arr[mid]>x)high=mid-1;
      else low=mid+1;
   }
   return -1;
}

//Recursive
int bSearch(int arr[],int low,int high,int x)
{
   if(low>high)return -1;
   int mid=(low+high)/2;
   if(arr[mid]==x)return mid;
   else if(arr[mid]>x)return bSearch(arr,low,mid-1,x);
   else return bSearch(arr,mid+1,high,x);
}


int main()
 {
   int a[]={23,45,56,81,88,340,617};
   int n=7;

   int ans=binarySearch(a,7,56);
   cout<<"Found at:"<<ans<<endl;
   int ans2=binarySearch(a,7,6);
   cout<<"Found at:"<<ans2<<endl;

   int ans3=bSearch(a, 0, n - 1, 56);
   cout<<"Found at:"<<ans3<<endl;
   int ans4=bSearch(a, 0, n - 1, 6);
   cout<<"Found at:"<<ans4<<endl;


    
    return 0;
}