/*
 * author: Jiabin.Li
 */







#include<iostream>
#include<vector>

using namespace std;

int main() {
    cout << "input one interger: " << endl;
    
    int x;
    cin >> x;
    vector<int> v = {x};
    while (x != 1) {
        if (x % 2 == 1) {
            x = 3 * x + 1;
        }
        else {
            x /= 2;
        }
    v.push_back(x);
    }

   int n = v.size();
   for (int i = 0; i < n; i++ ) {
       cout << v[i] << endl;
   }

   return 0;
}
