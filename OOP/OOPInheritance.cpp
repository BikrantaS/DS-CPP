#include <iostream>
#include<string>
using namespace std;

class base
{
public:
    int x;
protected:
    int y;
private:
    int z;
};

class publicDerived:public base//inherits class base in public way
{
    //x is public
    //y is protected
    //z is not accessible from publicDerived
};


class protectedDerived:protected base//inherits class base in protected way
{
    //x is public
    //y is protected
    //z is not accessible from publicDerived
};


class privateDerived:private base//inherits class base in private way
{
    //x is private//therefore x cannot be accessed from derived class of protectedDerive
    //y is private
    //z is not accessible from privateDerived
};

int main()
 {
    return 0;
}