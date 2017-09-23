#include <iostream>
#include <string>
#include <array>
#include <fstream>

using namespace std;

class GameLife {
public:
	int generation;
	int frequency;
	int L[10][10];

	GameLife() {
		generation = 0;
		frequency = 0;
		L[10][10] = {};
	}

	void read(string s) {
		ifstream fs(s);
		fs >> generation >> frequency;
	
		for(int i = 0; i <= 9; i++) {
			fs >> L[i][0] >> L[i][1] >> L[i][2] >> L[i][3] >> L[i][4] >> L[i][5] >> L[i][6] >> L[i][7] >> L[i][8] >> L[i][9] >> endl;
                }		
		fs.close();
	}

//	void print() {
//		for (int i = 0; i <= generation; i++) {
//			if (i % frequency == 0) {
//				cout << "generation = " << i;
//				printIJ(i);
//				cout << endl;
//			}
//			update(L);
//		}
//	}
//
//	void printIJ(int g) {
//		for (int i = 0; i <= 9; i++) {
//			for (int j = 0; j <= 9; j++) {
//				if (L[i][j]) {
//					cout << "*";
//				} else {
//					cout << " ";
//				}
//			}
//			cout << endl;
//		}
//	}
//
//
//	void update(int &L[10][10]){
//	        for (int i = 0; i <= 9; i++) {
//			for (int j = 0; j <= 9; j++) {
//				 if (L[i][j] == 1)
//                   			 L[i][j] = 10;
//            		}
//        	}	
//
//      	        for (int i = 0; i <= 9; i++) {
//           		 for (int j = 0; j <= 9; j++) {
//				updateNeighbors(i, j, L);
//			        if (L[i][j] == 3 || L[i][j] == 12 || L[i][j] == 13)
//					L[i][j] = 1;
//			        else 
//					L[i][j] = 0;
//            		 }
//        	}
//		
//        }
//        
//
//	void updateNeibours(int i, int j, int &L[10][10]) {
//                bool isLive = L[i][j] >= 10;
//                for (int h = i - 1; h <= i + 1; h++) {
//               	         if (h < 0 || h > 9)
//                                continue;
//                         for (int w = j - 1; w <= j + 1; w++) {
//                                if (w < 0 || w > 9)
//                                     continue;
//
//                                if (h == i && w == j)
//                                     continue;
//
//                                if (isLive)
//                                     ++L[h][w];
//                          }
//                }
//	}
};

int main() {
	GameLife solution;
	solution.read(".dat");
	return 0;
}
