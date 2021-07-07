#include <iostream>
#include<string>
using namespace std;

class Cars
{
    private:
        //member variable or data member
        string company_name;
        string model_name;
        string fuel_type;
        float mileage;
        double price;

    public:
        //member functions
        void setData(string cname,string mname,string ftype,float m,double p)
        {
            company_name=cname;
            model_name=mname;
            fuel_type=ftype;
            mileage=m;
            price=p;
        }

        void displayData()
        {
            cout<<"Car Properties:"<<endl;
            cout<<"Car Company Name:"<<company_name<<endl;
            cout<<"Car Company Model:"<<model_name<<endl;
            cout<<"Car Fuel type:"<<fuel_type<<endl;
            cout<<"Car mileage:"<<mileage<<endl;
            cout<<"Car price:"<<price<<endl;
            cout<<endl;

        }
};


int main()
 {
    Cars car1,car2;//objects are nothing but variable of type class
    car1.displayData();
    car1.setData("Toyota","Altis","Petrol",15.5,150000);
    car1.displayData();
    return 0;
}