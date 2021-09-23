#include<iostream>
using namespace std;

int gcdEuclid(int x,int y)
{
  while(x%y!=0)
  {
    int rem=x%y;
    x=y;
    y=rem;
  }
  return y;
}

int gcdEuclidRecursive(int a,int b)
{
  return b==0?a:gcdEuclidRecursive(b,a%b);
}



int main() {

  int x=24,y=36;
  int gcd=gcdEuclid(x,y);

  //By property:lcm*gcd=x*y;
  int lcm=(x*y)/gcd;
  cout<<"GCD of "<<x<<" and "<<y<<" is:"<<gcd<<endl;
  cout<<"LCM of "<<x<<" and "<<y<<" is:"<<lcm<<endl;



  return 0;
}