#include <iostream>
using namespace std;


//Function overloading can be considered as polymorphism feature in c++

int add(int a,int b)//1
{
    cout<<"Function 1"<<endl;
    return (a+b);
}

double add(double a,double b)//2
{
    cout<<"Function 2"<<endl;
    return(a+b);
}
int add(int a,int b,int c)//3
{
    cout<<"Function 3"<<endl;
    return (a+b+c);
}
double add(int a,double b)//4
{
    cout<<"Function 4"<<endl;
    return(a+b);
}
double add(double a,int b)//5
{
    cout<<"Function 5"<<endl;
    return(a+b);
}




int main()
 {
    cout<<add(1,2)<<endl;
    cout<<add(3.5,4.5)<<endl;
    cout<<add(3,4,5)<<endl;
    cout<<add(3,4.5)<<endl;
    cout<<add(3.5,4)<<endl;

    return 0;
}