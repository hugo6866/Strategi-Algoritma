#include <iostream>
#include <unordered_map>

using namespace std;

int main() {
  int TN[] = {0, 1, 2, 3, 4, 5, 6, 7};
  int MD[] = {1, 0, 2, 3, 4, 5, 0, 3, 1, 0, 6, 0, 1, 7, 6, 5, 0, 0, 0, 4, 0, 6, 5, 4, 3, 0, 1, 0, 2, 0, 4, 
              3, 2, 1, 0, 0, 0, 4, 0, 3, 4, 6, 5, 6, 5, 3, 1, 3, 2, 3, 4, 5, 3, 0, 0, 0, 4, 0, 3, 4, 6, 5, 
              6, 5, 3, 1, 3, 2, 4, 7, 2, 1, 0, 0, 0};
  int a = sizeof(TN) / sizeof(int);
  // Banyak elemen dalam MD
  int b = sizeof(MD) / sizeof(int);

  unordered_map<int, int> distribusi_nada;

  for (int i = 0; i < a; i++) {
    distribusi_nada[TN[i]] = 0;
  }

  // Hitung banyaknya setiap nada dalam melodi
  for (int i = 0; i < b; i++) {
    distribusi_nada[MD[i]]++;
  }

  // Cetak hasil distribusi nada
  for (int i = 0; i < a; i++) {
    cout << TN[i] << ": " << distribusi_nada[TN[i]] << endl;
  }

  return 0;
}
