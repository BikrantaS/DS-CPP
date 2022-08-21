#include <iostream>
#include <deque>
using namespace std;


int main() 
{ 
    deque<int> dq={10,20,30};
    dq.push_front(5);
    dq.push_back(50);
    for(auto x:dq)
        cout<<x<<" ";
    cout<<endl;
    cout<<dq.front()<<" "<<dq.back();
    
    cout<<endl;
    cout<<"-------------"<<endl;
    deque<int> d = {10, 15, 30, 5, 12};
    auto it = d.begin();
    it++;
    d.insert(it, 20);
    d.pop_front();
    d.pop_back();
    cout<<d.size();
    return 0; 
} 