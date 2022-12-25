#include <iostream>
#include <unordered_map>

using namespace std;

int partition(int data[], int low, int high) {
  int pivot = data[high];
  int i = low - 1;

  for (int j = low; j <= high - 1; j++) {
    if (data[j] < pivot) {
      i++;
      swap(data[i], data[j]);
    }
  }
  swap(data[i + 1], data[high]);
  return (i + 1);
}

void quick_sort(int data[], int low, int high) {
  if (low < high) {
    int pivot = partition(data, low, high);

    quick_sort(data, low, pivot - 1);
    quick_sort(data, pivot + 1, high);
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

  quick_sort(data_urut, 0, nTN - 1);

  for (int i = 0; i < nTN; i++) {
    cout << data_urut[i] << "\n";
  }

  return 0;
}