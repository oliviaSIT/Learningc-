/*
 * author: Jiabin.Li
 */


#include <iostream>
#include <array>
#include <cmath>

using namespace std;

int main() {
	double windChill[12][18];
	int V[12] = {5, 10, 15, 20, 25, 30, 35, 40, 45, 50, 55, 60};// wind(mph)
	int T[18] = {40, 35, 30, 25, 20, 15, 10, 5, 0, -5, -10, -15, -20, -25, -30, -35, -40, -45};// Temperature(F)
	double y;

	for (int i = 0; i < 12; i++) {
		for (int j = 0; j < 18; j++) {
			y = 35.74 + 0.6215 * T[j] - 35.75 * pow(V[i], 0.16) + 0.4275 * T[j] * pow(V[i], 0.16);
			windChill[i][j] = round(y);

			cout << windChill[i][j] << " "; 
		}
		cout << endl;
	}

	return 0;
}
