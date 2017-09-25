// author: Jiabin.Li

#include <iostream>
#include <array>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

// size of the grid is 10*10
const size_t ARRAY_SIZE = 10;

class GameLife {
private:
	int totalGeneration;
	int frequency;
	int L[ARRAY_SIZE + 2][ARRAY_SIZE + 2];

	void readInitState(string filename) {

        	string line;

        	ifstream fs(filename);

        	// first line contains 1. total generation and 2. frequency
        	getline(fs, line);
        	istringstream iss(line);
        	iss >> totalGeneration;
        	iss >> frequency;

        	// following lines are the init state of the matrix
        	for (size_t i = 1; i <= ARRAY_SIZE; i++) {
            		getline(fs, line);
            		for (size_t j = 1; j <= ARRAY_SIZE; j++) {
                		if (line[j - 1] == '*')
                    			L[i][j] = 1;
                		else
                    			L[i][j] = 0;
            		}
        	}
		
		// add the edge
		for (size_t j = 0; j <= ARRAY_SIZE + 1; j++) {
			L[0][j] = 0;
			L[j][0] = 0;
			L[ARRAY_SIZE + 1][j] = 0;
			L[j][ARRAY_SIZE + 1] = 0;
		}

		
        	fs.close();
    	}

public:
	GameLife(string filename) {
        	readInitState(filename);
        }

	void startPrint() { 	
		for (int generation = 0; generation <= totalGeneration; generation++) {
			if (generation % frequency == 0) {
				cout << "Current generation is = " << generation << endl;
				printLife();
				cout << endl;
			}
			update();
		}

	}

	void updateNeighbour(size_t i, size_t j, int (&neighbour)[ARRAY_SIZE + 2][ARRAY_SIZE + 2]) {
                int temp = 0;
		for (size_t h = i - 1; h <= i + 1; h++) {
                        for (size_t w = j - 1; w <= j + 1; w++) {
                                if (h == i && w == j)
                                        continue;
                                
				if (L[h][w] == 1)
                  			temp++;
                        }
                }
		neighbour[i][j] = temp;
        }

	void update() {
		int neighbour[ARRAY_SIZE + 2][ARRAY_SIZE + 2] = {};
		for (size_t i = 1; i <= ARRAY_SIZE; i++) {
                	for (size_t j = 1; j <= ARRAY_SIZE; j++) {
	            		updateNeighbour(i, j, neighbour);	
			}
		}

		for (size_t i = 1; i <= ARRAY_SIZE; i++) {
                        for (size_t j = 1; j <= ARRAY_SIZE; j++) {
				if ((L[i][j] == 1 && neighbour[i][j] == 2) || neighbour[i][j] == 3)
                                	L[i][j] = 1;
                		else
                    			L[i][j] = 0;
            		}
        	}
	}  

	void printLife() const {
		for (size_t i = 1; i <= ARRAY_SIZE; i++) {
            		for (size_t j = 1; j <= ARRAY_SIZE; j++) {
                		if (L[i][j] == 1) {
					cout << "*";
				} else {
					cout << " ";
				}
            		}
            		cout << endl;
        	}
	}
};

int main() {
	GameLife sol("test.dat");
        sol.startPrint();
	return 0;
}
