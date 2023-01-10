#include <iostream>
#include <unordered_map>

using namespace std;

void merge(int data[], int l, int m, int r) {
  int n1 = m - l + 1;
  int n2 = r - m;

  int L[n1], R[n2];

  for (int i = 0; i < n1; i++) {
    L[i] = data[l + i];
  }
  for (int j = 0; j < n2; j++) {
    R[j] = data[m + 1 + j];
  }

  int i = 0, j = 0, k = l;
  while (i < n1 && j < n2) {
    if (L[i] <= R[j]) {
      data[k] = L[i];
      i++;
    } else {
      data[k] = R[j];
      j++;
    }
    k++;
  }

  while (i < n1) {
    data[k] = L[i];
    i++;
    k++;
  }

  while (j < n2) {
    data[k] = R[j];
    j++;
    k++;
  }
}

void merge_sort(int data[], int l, int r) {
  if (l < r) {
    int m = l + (r - l) / 2;

    merge_sort(data, l, m);
    merge_sort(data, m + 1, r);

    merge(data, l, m, r);
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

  merge_sort(data_urut, 0, nTN - 1);

  for (int i = 0; i < nTN; i++) {
    cout << data_urut[i] << "\n";
  }

  return 0;
}