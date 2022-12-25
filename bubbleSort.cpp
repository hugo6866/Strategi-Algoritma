#include <iostream>
#include <unordered_map>

using namespace std;

void bubble_sort(int data[], int n) {
  for (int i = 0; i < n - 1; i++) {
    for (int j = 0; j < n - i - 1; j++) {
      if (data[j] > data[j + 1]) {
        int temp = data[j];
        data[j] = data[j + 1];
        data[j + 1] = temp;
      }
    }
  }
}

int main() {
  int TN[] = {0, 1, 2, 3, 4, 5, 6, 7};
  int MD[] = {1, 0, 2, 3, 4, 5, 0, 3, 1, 0, 6, 0, 1, 7, 6, 5, 0, 0, 0, 4, 0, 6, 5, 4, 3, 0, 1, 0, 2, 0, 4, 
              3, 2, 1, 0, 0, 0, 4, 0, 3, 4, 6, 5, 6, 5, 3, 1, 3, 2, 3, 4, 5, 3, 0, 0, 0, 4, 0, 3, 4, 6, 5, 
              6, 5, 3, 1, 3, 2, 4, 7, 2, 1, 0, 0, 0};
  int nTN = sizeof(TN) / sizeof(int);
  int nMD = sizeof(MD) / sizeof(int);

  unordered_map<int, int> distribusi_nada;

  for (int i = 0; i < nMD; i++) {
    distribusi_nada[MD[i]]++;
  }

  int data_urut[nTN] = {0};

  for (int i = 0; i < nTN; i++) {
    data_urut[i] = distribusi_nada[TN[i]];
  }

  bubble_sort(data_urut, nTN);

  for (int i = 0; i < nTN; i++) {
    cout << data_urut[i] << endl;
  }

  return 0;
}
