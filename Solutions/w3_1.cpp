#include<bits/stdc++.h>

using namespace std;
int n[10000];
int size = 0;
int main() {
  string key;
  while (1) {
    cin >> key;
    if (key == "s") {
      for (int i = 0; i < size; i++) {
        cout << n[i] << " ";
      }
      cout << endl;
      for (int i = 0; i < size; i++) {
        int t = i;
        for (int j = i; j < size; j++) {
          if (n[t] > n[j]) {
            t = j;
          }
        }
        int tt = n[i];
        n[i] = n[t];
        n[t] = tt;
        for (int i = 0; i < size; i++) {
          cout << n[i] << " ";
        }
        cout << endl;
      }
      break;
    } else if (key == "b") {
      for (int i = 0; i < size; i++) {
        cout << n[i] << " ";
      }
      cout << endl;
      for (int i = 0; i < (size - 1); i++) {
        for (int j = 0; j < (size - i) - 1; j++) {
          if (n[j] > n[j + 1]) {
            int t = n[j + 1];
            n[j + 1] = n[j];
            n[j] = t;
          }
        }
        for (int i = 0; i < size; i++) {
          cout << n[i] << " ";
        }
        cout << endl;
      }
      break;
    } else if (key == "i") {
      for (int i = 0; i < size; i++) {
        cout << n[i] << " ";
      }
      cout << endl;
      int temp1 = 0;
      for (int i = 1; i < size; i++) {
        for (int j = (i - 1); j >= 0; j--) {
          if (n[j] > n[j + 1]) {
            temp1 = n[j];
            n[j] = n[j + 1];
            n[j + 1] = temp1;
          } else {
            break;
          }
        }
        for (int i = 0; i < size; i++) {
          cout << n[i] << " ";
        }
        cout << endl;
      }
      break;
    } else {
      const char * c = key.c_str();
      n[size] = atoi(c);
      size++;
    }
  }
  return 0;
}
