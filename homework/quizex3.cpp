#include <iostream>
#include <cmath>
using namespace std;
/*
double f(double x,double y)
{
double PI=3.1415926;
return atan(x/y)/PI*180;
}

int main()
{
cout<<f(4,4)<<endl;
return 0;
}


int main() {
int a = 5;
const int &b=a;
b=6;
cout<<a<<endl;
return 0;
}
*/

int main() {
int a = 5;
const int &b=a;
a=6;
cout<<b<<endl;
return 0;
}
