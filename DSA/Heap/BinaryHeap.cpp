#include <bits/stdc++.h>
using namespace std;

class MinHeap{
    int *arr;
    int size;
    int capacity;
    
    public:
    
    MinHeap(int c){
    size = 0; 
    capacity = c; 
    arr = new int[c];
    }

    int left(int i) { return (2*i + 1); } 
    int right(int i) { return (2*i + 2); } 
    int parent(int i) { return (i-1)/2; } 
    


    //Time Complexity=O(h)
    void insert(int x) 
    { 
    if (size == capacity)return;
    size++; 
    arr[size-1]=x; 
 
    for (int i=size-1;i!=0 && arr[parent(i)]>arr[i];) 
    { 
       swap(arr[i], arr[parent(i)]); 
       i = parent(i); 
    } 
    }

    //Time Complexity=O(n)
    //Space Complexity=O(h)
    void minHeapify(int i) 
    { 
    int lt = left(i); 
    int rt = right(i); 
    int smallest = i; 
    if (lt < size && arr[lt] < arr[i]) 
        smallest = lt; 
    if (rt < size && arr[rt] < arr[smallest]) 
        smallest = rt; 
    if (smallest != i) 
    { 
        swap(arr[i],arr[smallest]); 
        minHeapify(smallest); 
    } 
    }

    //takes out the min element from the binary heap
    int extractMin() 
    { 
    if (size <= 0) 
        return INT_MAX; 
    if (size == 1) 
    { 
        size--; 
        return arr[0]; 
    }  
    swap(arr[0],arr[size-1]);
    size--; 
    minHeapify(0); 
  
    return arr[size]; 
    }


    //replaces the value at i indext with the value x,
    //then moves the new key the correct position to maintain
    //binary heap data stucture
    //Time Complexity=O(logn)
    void decreaseKey(int i, int x) 
    { 
    arr[i] = x; 
    while (i != 0 && arr[parent(i)] > arr[i]) 
    { 
       swap(arr[i], arr[parent(i)]); 
       i = parent(i); 
    } 
    }
    
    void deleteKey(int i) 
    { 
        decreaseKey(i, INT_MIN); 
        extractMin(); 
    }


    //create heap from randmly ordered array
    //Time Complexity=O(n)
    void buildHeap()
    {
        for(int i=(size-2)/2;i>=0;i--)
            minHeapify(i);
    }


    // int show(int x)
    // {
    //     int val=arr[x];
    //     return val;
    // }
    
};

int main() 
{ 
    MinHeap h(11);
    h.insert(3); 
    h.insert(2);
    h.deleteKey(0);
    h.insert(15);
    h.insert(20);
    cout << h.extractMin() << endl;
    h.decreaseKey(2, 1);
    cout << h.extractMin() << endl;

    // cout<<"The Binary heap is:"<<endl;
    // for(int i=0;i<h.se;i++)
    // {
    //     cout<<h.show(i)<<" ";
    // }
    return 0;
} 
