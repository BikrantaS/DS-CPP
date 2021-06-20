#include <iostream>
#include <stack>
using namespace std;
//Stack(container adapter) Using STL


int main()
{
    stack<int> s;
    s.push(5);
    s.push(10);
    s.push(20);
  
    cout<<s.size()<<endl;
    cout<<s.top()<<endl;
    s.pop();
    cout<<s.top()<<endl;

    cout<<"Stack Traversal:"<<endl;
    while(s.empty()==false)
    {
    	cout<<s.top()<<" ";
    	s.pop();
    }

    return 0;

}
