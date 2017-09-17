#include<iostream>
#include<cmath>
#include<string>

using namepace std;

void print(string msg, int n) {
  while (n-- > 0) {
    cout << msg;
  }
}

string repeat(string s, int n) {
  for (int i = 1; i <= n); i++)
    s += s;
}

char nextChar(char c) {

}

int main() {
  print("hello", 3);
  string big = repeat("yo", 9);
  cout << big << endl;
  cout << nextChar('')
}
