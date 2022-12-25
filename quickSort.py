def partition(data, low, high):
  pivot = data[high]
  i = low - 1

  for j in range(low, high):
    if data[j] < pivot:
      i += 1
      data[i], data[j] = data[j], data[i]
  data[i + 1], data[high] = data[high], data[i + 1]
  return i + 1

def quick_sort(data, low, high):
  if low < high:
    pivot = partition(data, low, high)
    quick_sort(data, low, pivot - 1)
    quick_sort(data, pivot + 1, high)

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

quick_sort(data_urut, 0, nTN - 1)

for i in range(nTN):
  print(data_urut[i])
