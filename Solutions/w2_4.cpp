#include<bits/stdc++.h>

using namespace std;
int index_value = 0;
int num[10000];
int meet_value = 0;
int s_min = 0;
int s_max = 0;
void Sort() {
  for (int i = 0; i < s_max; i++) {
    for (int j = i + 1; j < s_max; j++) {
      if (num[i] > num[j]) {
        int t = num[i];
        num[i] = num[j];
        num[j] = t;
      }
    }
  }
}
void interpolationSearch(int value, int left, int right) {
  if (left == right && num[left] != value) {
    return;
  }
  int mid = left + (((double)(right - left) / (num[right] - num[left])) * (value - num[left]));
  if (mid < left) {
    return;
  }
  if (mid > right) {
    return;
  }
  if (right < left) {
    return;
  }
  cout << left << "," << mid << "," << right << " ";
  if (num[mid] == value) {
    meet_value = 1;
    return;
  }
  if (right == left) {
    return;
  }
  if (num[mid] < value) {
    interpolationSearch(value, mid + 1, right);
  } else if (num[mid] > value) {
    interpolationSearch(value, left, mid - 1);
  }
}
void bs(int value) {
  meet_value = 0;
  Sort();
  interpolationSearch(value, s_min, s_max - 1);
}
int main() {
  int x;
  string key;
  while (1) {
    cin >> key;
    if (key == "s") {
      cin >> x;
      bs(x);
      if (meet_value == 1) {
        cout << "Yes" << endl;
      } else {
        cout << "No" << endl;
      }
    } else if (key == "p") {
      for (int i = 0; i < s_max; i++) {
        cout << num[i] << " ";
      }
      cout << endl;
    } else if (key == "o") {
      break;
    } else {
      const char * c = key.c_str();
      num[s_max] = atoi(c);
      s_max++;
    }
  }
  return 0;
}
