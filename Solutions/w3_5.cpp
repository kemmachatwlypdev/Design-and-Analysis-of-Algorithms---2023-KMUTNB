#include<bits/stdc++.h>

using namespace std;
int size = 0;
int a[1000];
void quicksort(int lowerIndex, int higherIndex) {
  //------------------------------------------------------------
  for (int i = 0; i < size; i++) {
    cout << a[i] << " ";
  }
  cout << endl;
  //------------------------------------------------------------
  int i = lowerIndex;
  int j = higherIndex;
  int pivot = a[lowerIndex + (higherIndex - lowerIndex) / 2];
  while (i <= j) {
    while (a[i] < pivot) {
      i++;
    }
    while (a[j] > pivot) {
      j--;
    }
    if (i <= j) {
      int temp = a[i];
      a[i] = a[j];
      a[j] = temp;
      i++;
      j--;
    }
  }
  if (lowerIndex < j) {
    quicksort(lowerIndex, j);
  }

  if (i < higherIndex) {
    quicksort(i, higherIndex);
  }
}
int main() {
  string key;
  while (1) {
    cin >> key;
    if (key == "q") {
      quicksort(0, size - 1);
      //------------------------------------------------------------
      for (int i = 0; i < size; i++) {
        cout << a[i] << " ";
      }
      cout << endl;
      //------------------------------------------------------------
      break;
    } else {
      const char * c = key.c_str();
      a[size] = atoi(c);
      size++;
    }
  }
  return 0;
}
