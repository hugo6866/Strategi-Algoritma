def merge(data, l, m, r):
  n1 = m - l + 1
  n2 = r - m

  L = [0] * n1
  R = [0] * n2

  for i in range(n1):
    L[i] = data[l + i]
  for j in range(n2):
    R[j] = data[m + 1 + j]

  i, j, k = 0, 0, l
  while i < n1 and j < n2:
    if L[i] <= R[j]:
      data[k] = L[i]
      i += 1
    else:
      data[k] = R[j]
      j += 1
    k += 1

  while i < n1:
    data[k] = L[i]
    i += 1
    k += 1

  while j < n2:
    data[k] = R[j]
    j += 1
    k += 1

def merge_sort(data, l, r):
  if l < r:
    m = l + (r - l) // 2

    merge_sort(data, l, m)
    merge_sort(data, m + 1, r)

    merge(data, l, m, r)

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

merge_sort(data_urut, 0, nTN - 1)

for i in range(nTN):
  print(data_urut[i])
