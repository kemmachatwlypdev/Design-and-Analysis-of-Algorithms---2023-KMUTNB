#include<bits/stdc++.h>

using namespace std;
int size = 0;
int a[1000];
void merge(int * a, int left, int right, int rightEnd) {
  int tmp[1000];
  int startL = left;
  int EndL = right - 1;
  int startR = right;
  int EndR = rightEnd;
  int index = startL;
  int indL = startL;
  int indR = startR;
  while (indL <= EndL && indR <= EndR) {
    if (a[indL] < a[indR]) {
      tmp[index] = a[indL];
      indL++;
      index++;
    } else {
      tmp[index] = a[indR];
      indR++;
      index++;
    }
  }
  while (indL <= EndL) {
    tmp[index] = a[indL];
    indL++;
    index++;
  }
  while (indR <= EndR) {
    tmp[index] = a[indR];
    indR++;
    index++;
  }
  for (int i = startL; i <= EndR; i++) {
    a[i] = tmp[i];
  }
  //------------------------------------------------------------
  for (int i = 0; i < size; i++) {
    cout << a[i] << " ";
  }
  cout << endl;
  //------------------------------------------------------------
}
void mergeSort(int * a, int left, int right) {
  if (left < right) {
    int center = (left + right) / 2;
    mergeSort(a, left, center);
    mergeSort(a, center + 1, right);
    merge(a, left, center + 1, right);
  }
}
int main() {
  string key;
  while (1) {
    cin >> key;
    if (key == "m") {
      mergeSort(a, 0, size - 1);
      break;
    } else {
      const char * c = key.c_str();
      a[size] = atoi(c);
      size++;
    }
  }
  return 0;
}
