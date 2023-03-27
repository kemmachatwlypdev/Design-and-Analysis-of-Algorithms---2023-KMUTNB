#include<bits/stdc++.h>

using namespace std;
int arr[10000];
int n = 0;
int main() {
  string key;
  while (1) {
    cin >> key;
    if (key == "s") {
      for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
      }
      cout << endl;
      for (int gap = n / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < n; i += 1) {
          int j;
          int temp = arr[i];
          for (j = i; j >= gap && arr[j - gap] > temp; j -= gap) {
            arr[j] = arr[j - gap];
          }
          arr[j] = temp;
        }
        for (int i = 0; i < n; i++) {
          cout << arr[i] << " ";
        }
        cout << endl;
      }
      break;
    } else {
      const char * c = key.c_str();
      arr[n] = atoi(c);
      n++;
    }
  }
  return 0;
}
