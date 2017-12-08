#include <iostream>

using namespace std;

class JulianDate {
private:
	double jd;
	static JulianDate J2000;
public:
	JulianDate() 
	JulianDate(double year, double month, double day, double hour, double min, double sec) {
		int NumOfLeap = 0;
		for(double i = 2000; i <= year; i++) {
			if(i % 400 == 0)
				NumOfLeap++;
			else if(i % 100 != 0 && i % 4 == 0)
				NumOfLeap++; 
		}
		jd = 365 * (year - 2000) + month+ day - 1 + hour / 24 
	}

	double getJD() {return jd;}

//	operator+
//	operator-
	
};
/*
JulianDate::J2000 = ;
int main() {
	JulianDate today;// get the date right now
	JulianDate a(2000, 1, 1, 00, 00, 00);//midnight January 1 2000
	JulianDate a(2000, 2, 28, 00, 00, 00);
	JulianDate a(2000, 3, 5, 04, 30, 00);
	JulianDate a(2000, 1, 3, 00, 00, 00);

	cout << d - a << "days" << endl;//2.0
	cout << e - a << "days" << endl;//2.5
	cout << a + 13 << endl;
	cout << a + 13.5<< endl;

	return 0;
}
*/
//http://www.math.harvard.edu/~knill/3dprinter/exhibits/bc/Meeus1988.pdf
