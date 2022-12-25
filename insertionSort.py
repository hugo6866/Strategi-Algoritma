def insertion_sort(data):
  n = len(data)
  for i in range(1, n):
    key = data[i]
    j = i - 1
    while j >= 0 and data[j] > key:
      data[j + 1] = data[j]
      j -= 1
    data[j + 1] = key

TN = [0, 1, 2, 3, 4, 5, 6, 7]
MD = [1, 0, 2, 3, 4, 5, 0, 3, 1, 0, 6, 0, 1, 7, 6, 5, 0, 0, 0, 4, 0, 6, 5, 4, 3, 0, 1, 0, 2, 0, 4, 
      3, 2, 1, 0, 0, 0, 4, 0, 3, 4, 6, 5, 6, 5, 3, 1, 3, 2, 3, 4, 5, 3, 0, 0, 0, 4, 0, 3, 4, 6, 5, 
      6, 5, 3, 1, 3, 2, 4, 7, 2, 1, 0, 0, 0]
nTN = len(TN)
nMD = len(MD)

distribusi_nada = {}

for i in range(nMD):
  distribusi_nada[MD[i]] = distribusi_nada.get(MD[i], 0) + 1

data_urut = [distribusi_nada[TN[i]] for i in range(nTN)]

insertion_sort(data_urut)

for i in range(nTN):
  print(data_urut[i])
