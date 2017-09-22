#include <iostream>
#include <string>
#include <array>

using namespace std;

class gameLife {
public:
	int generation;
	int frequency;
	int L[10][10];

	gameLife() {
		generation = 0;
		frequency = 0;
		L[]
	}

	void read(string s){
		Generation = g;
		frequency = f;
	}

	void print() {
		for (int i = 0; i <= generation; i++) {
			if (i % frequency == 0) {
				cout << "generation = " << i;
				printIJ(i);
				cout << endl;
			}
			update(L);
		}
	}

	void printIJ(int g) {
		for (int i = 0; i <= 9; i++) {
			for (int j = 0; j <= 9; j++) {
				if (L[i][j]) {
					cout << "*";
				} else {
					cout << " ";
				}
			}
			cout << endl;
		}
	}


	void update(int &L[10][10]){
	        for (int i = 0; i <= 9; i++) {
			for (int j = 0; j <= 9; j++) {
				 if (L[i][j] == 1)
                   			 L[i][j] = 10;
            		}
        	}	

      	        for (int i = 0; i <= 9; i++) {
           		 for (int j = 0; j <= 9; j++) {
				updateNeighbors(i, j, L);
			        if (L[i][j] == 3 || L[i][j] == 12 || L[i][j] == 13)
					L[i][j] = 1;
			        else 
					L[i][j] = 0;
            		 }
        	}
		
        }
        

	void updateNeibours(int i, int j, int &L[10][10]) {
                bool isLive = L[i][j] >= 10;
                for (int h = i - 1; h <= i + 1; h++) {
               	         if (h < 0 || h > 9)
                                continue;
                         for (int w = j - 1; w <= j + 1; w++) {
                                if (w < 0 || w > 9)
                                     continue;

                                if (h == i && w == j)
                                     continue;

                                if (isLive)
                                     ++L[h][w];
                          }
                }
	}
};

int main() {
	gamelife solution;
	sol.read(".dat");
}
