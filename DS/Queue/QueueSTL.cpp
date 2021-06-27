#include <iostream>
#include <queue>
using namespace std;

int main() 
{ 
    queue <int> q; 
    q.push(10); 
    q.push(20); 
    q.push(30); 
  
    cout <<"Size of queue"<< q.size()<<endl;
    //Queue traversal
   while(q.empty() == false)
   {
       cout << q.front() << " " << q.back() << endl;
       q.pop();
   }
    
  
    return 0; 
} 