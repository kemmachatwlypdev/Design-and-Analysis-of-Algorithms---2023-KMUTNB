#include<bits/stdc++.h>

using namespace std;
//----------------- Median of three
//int array[] = {7, 11, 14, 6, 9, 4, 3, 12};
//int size = 8;
int ar_ray[100];
int size = 0;
void quicksort(int lo, int hi) {
  for (int ii = 0; ii < size; ii++) {
    cout << ar_ray[ii] << " ";
  }
  cout << endl;
  int mid = lo + ((hi - lo) / 2);
  if (ar_ray[mid] < ar_ray[hi] && ar_ray[mid] > ar_ray[lo] ||
    ar_ray[mid] < ar_ray[lo] && ar_ray[mid] > ar_ray[hi]) {
    int t = ar_ray[mid];
    ar_ray[mid] = ar_ray[hi];
    ar_ray[hi] = t;
  } else if (ar_ray[lo] < ar_ray[mid] && ar_ray[lo] > ar_ray[hi] ||
    ar_ray[lo] < ar_ray[hi] && ar_ray[lo] > ar_ray[mid]) {
    int t = ar_ray[lo];
    ar_ray[lo] = ar_ray[hi];
    ar_ray[hi] = t;
  }
  int pivot = ar_ray[hi];
  int i = lo;
  int j = hi - 1;
  while (i <= j) {
    while (ar_ray[i] < pivot) {
      i++;
    }
    while (ar_ray[j] > pivot) {
      j--;
    }
    if (i <= j) {
      int temp = ar_ray[i];
      ar_ray[i] = ar_ray[j];
      ar_ray[j] = temp;
      i++;
      j--;
    }
  }
  // cout<<lo<<","<<hi<<","<<i<<","<<j<<endl;
  // for(int i=0 ; i < size ; i++){cout<<array[i]<<" ";}cout<<endl;
  for (int t = hi; t > i; t--) {
    int x = ar_ray[t];
    ar_ray[t] = ar_ray[t - 1];
    ar_ray[t - 1] = x;
  }
  //for(int i=0 ; i < size ; i++){cout<<array[i]<<" ";}cout<<endl;
  if (lo < j) {
    quicksort(lo, j);
  }
  if (i < hi) {
    quicksort(i, hi);
  }
}
int main() {
  string key;
  while (1) {
    cin >> key;
    if (key == "t") {
      quicksort(0, size - 1);
      break;
    } else {
      const char * c = key.c_str();
      ar_ray[size] = atoi(c);
      size++;
    }
  }
  return 0;
}
