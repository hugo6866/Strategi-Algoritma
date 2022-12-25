#include <iostream>
#include <unordered_map>

using namespace std;

void selection_sort(int data[], int n) {
  for (int i = 0; i < n - 1; i++) {
    int min_idx = i;
    for (int j = i + 1; j < n; j++) {
      if (data[j] < data[min_idx]) {
        min_idx = j;
      }
    }
    int temp = data[min_idx];
    data[min_idx] = data[i];
    data[i] = temp;
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

  selection_sort(data_urut, nTN);

  for (int i = 0; i < nTN; i++) {
    cout << data_urut[i] << "\n";
  }
  return 0;
}