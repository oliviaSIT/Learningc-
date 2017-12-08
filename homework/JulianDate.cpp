/*
  Author: Jiabin.Li
  Cite:Zhiren.Yang
   for the getDate function.
*/


#include <iostream>
#include <time.h>
#include <cmath>

using namespace std;

class JulianDate{
private:
    double jd;
    int year, month, day, hour, minute, second;
public:
    JulianDate(){
        time_t timep;
        time(&timep);
        char tmp[64];
        strftime(tmp, sizeof(tmp), "%Y-%m-%d %H:%M:%S\n",localtime(&timep) );
        cout<<tmp;
    }
    
    JulianDate(int year, int month, int day, int hour = 0, int minute = 0, int second = 0):
    year(year), month(month), day(day), hour(hour), minute(minute), second(second) {
        jd = getdays(year);
    }

    bool Leap(int year) const {
        return ((year%4==0 && year%100!=0)|| year%400==0);
    }

    double getdays(int baseyear = 2000) const {
        int n=0;  //the number of leap years
        double days = 0;
        for(int i = baseyear; i <= year; i++){
            if(Leap(i)) n++;
        }

        switch(month) {
            case 1  : days = 0       ; break;
            case 2  : days = 31      ; break;
            case 3  : days = 59  + n ; break;
            case 4  : days = 90  + n ; break;
            case 5  : days = 120 + n ; break;
            case 6  : days = 151 + n ; break;
            case 7  : days = 181 + n ; break;
            case 8  : days = 212 + n ; break;
            case 9  : days = 243 + n ; break;
            case 10 : days = 273 + n ; break;
            case 11 : days = 304 + n ; break;
            case 12 : days = 334 + n ; break;
            default :                  break;
        }
        return (this->year - baseyear) * 365.0 + days + day - 1 + hour / 24.0 + minute / 1440.0 + second / 86400.0;
    }
    
    JulianDate getDate(const JulianDate& a, double AddDays) const {
        JulianDate Julian = a;
        int n = int(AddDays / 365);  //get how many years
        int d = 0;  //get how many leap years
        for(int i = Julian.year; i <= Julian.year + n; i++) {
            if(Leap(i)) d++;
        }

        int CurrentMonth, CurrentDay;
        double DaysOfThisYear = a.getdays(a.year);  //get how many days in this year
        int DaysLess365 = int(DaysOfThisYear + AddDays) % 365;
        int temp1 = ceil(DaysOfThisYear + AddDays);
        int temp = temp1 % 365;
        int ExtraYear = int(DaysOfThisYear + AddDays) / 365;
        
        if     (temp <= 31)      { CurrentMonth = 1; CurrentDay = DaysLess365 + 1;}
        else if(temp <= 59 + d)  { CurrentMonth = 2; CurrentDay = DaysLess365 - 31 + 1; }
        else if(temp <= 90 + d)  { CurrentMonth = 3; CurrentDay = DaysLess365 - 59 - d + 1;}
        else if(temp <= 120 + d) { CurrentMonth = 4; CurrentDay = DaysLess365 - 90 - d + 1;}
        else if(temp <= 151 + d) { CurrentMonth = 5; CurrentDay = DaysLess365 - 120 - d + 1;}
        else if(temp <= 181 + d) { CurrentMonth = 6; CurrentDay = DaysLess365 - 151 - d + 1;}
        else if(temp <= 212 + d) { CurrentMonth = 7; CurrentDay = DaysLess365 - 181 - d + 1;}
        else if(temp <= 243 + d) { CurrentMonth = 8; CurrentDay = DaysLess365 - 212 - d + 1;}
        else if(temp <= 273 + d) { CurrentMonth = 9; CurrentDay = DaysLess365 - 243 - d + 1;}
        else if(temp <= 304 + d) { CurrentMonth = 10;CurrentDay = DaysLess365 - 273 - d + 1;}
        else if(temp <= 334 + d) { CurrentMonth = 11;CurrentDay = DaysLess365 - 304 - d + 1;}
        else if(temp <= 365 + d) { CurrentMonth = 12;CurrentDay = DaysLess365 - 334 - d + 1;}
        
        Julian.year += ExtraYear;
        Julian.month = CurrentMonth;
        Julian.day = CurrentDay;
        int TotalSeconds = int((AddDays - int(AddDays)) * 24 * 60 * 60);
        Julian.second = (Julian.second + TotalSeconds % 60) % 60;
        Julian.minute = ((Julian.minute + (TotalSeconds % 3600) / 60) + (Julian.second + TotalSeconds % 60) / 60) % 60;
        Julian.hour = ((Julian.hour + TotalSeconds / 3600) + ((Julian.minute + (TotalSeconds % 3600) / 60) + (Julian.second + TotalSeconds % 60) / 60) / 60) % 24;
        return Julian;
    }
    
    friend double& operator-(const JulianDate& a,const JulianDate& b) {
        JulianDate s(2000, 1, 1, 00, 00, 00);
        s.jd=a.jd-b.jd;
        return s.jd;
    }

    friend JulianDate operator+(const JulianDate& a, double b){
        return a.getDate(a,b);
    }
    
    friend ostream& operator<<(ostream& s, const JulianDate& j) {
        s << j.year << "/" << j.month << "/" << j.day << ' ' << j.hour << ":" << j.minute << ":" << j.second <<' ';
        return s;
    }
};

JulianDate J2000(string standard);

int main() {
    JulianDate today; // get the date right now
    JulianDate a(2000, 1, 1, 00, 00, 00); // midnight, January 1, 2000
    JulianDate b(2000, 2, 28, 00, 00, 00); // midnight, January 1, 2000
    JulianDate c(2000, 3, 5, 04, 30, 00); // midnight, Feb. 28, 2000
    JulianDate d(2000, 1, 3, 00, 00, 00); // midnight, Jan. 3, 2000
    JulianDate e(2000, 1, 3, 12, 00, 00); // midnight, Jan. 3, 2000
    /*
     how many days in a year?
     365
     if year mod 4 == 0 LEAP YEAR (+1)  Feb. 29
     EXCEPT    if year mod 100 == 0 NOT LEAP YEAR  (1904 LEAP     1900 NOT
     EXCEPT if year mod 400 == 0 LEAP YEAR   (2000 leap year, 2400...)
     if J2000 = January 1, 2000 = 0    January 2, 2000 = 1
     JulianDate(2016, 3, 1)
     http://www.math.harvard.edu/~knill/3dprinter/exhibits/bc/Meeus1988.pdf
     */
    
    cout << d - a << " days\n"; // 2.0
    cout << e - a << " days\n"; // 2.5
    
    cout << a + 13 << "\n"; // what is 13 days from Jan. 1, 2000?? Jan 14, 2000
    cout << a + 13.5 << "\n";// what is 13 days from Jan. 1, 2000?? Jan 14, 2000
}

