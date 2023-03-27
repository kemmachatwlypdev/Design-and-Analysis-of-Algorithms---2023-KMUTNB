#include<bits/stdc++.h>

using namespace std;
int index_value = 0;
int num[10000];
int meet_value = 0;
int s_min = 0;
int s_max = 0;

void sequence_search(int value) {
  meet_value = 0;
  for (int i = 0; i < s_max; i++) {
    cout << num[i] << " ";
    if (num[i] == value) {
      meet_value = 1;
      return;
    }
  }
}

int main() {
  int x;
  string key;
  while (1) {
    cin >> key;
    if (key == "s") {
      cin >> x;
      sequence_search(x);
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
