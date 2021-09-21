#include <iostream>
#include<queue>
using namespace std;

int main(){
    //Priority queue is by default using Max heap
    priority_queue <int> pq;
    pq.push(10);
    pq.push(15);
    pq.push(5);
    cout<<pq.size()<<" ";
    cout<<pq.top()<<" ";
    while(pq.empty()==false){
        cout<<pq.top()<<" ";
        pq.pop();
    }
    
    return 0;
}