// https://www.nowcoder.com/practice/7f8a8553ddbf4eaab749ec988726702b
#include <iostream>
using namespace std;

const int MAX_N = 1e6;
const int TYPES = 26;

int trie[MAX_N][TYPES];
int last[MAX_N];
int pass[MAX_N];
int cnt = 1;

void insert(string s) {
  int cur = 1;
  for (int i = 0, path; i < s.length(); i++) {
    path = s.at(i) - 'a';
    if (trie[cur][path] == 0) trie[cur][path] = ++cnt;
    pass[cur]++;
    cur = trie[cur][path];
  }
  pass[cur]++, last[cur]++;
}

int count(string s) {
  int cur = 1;
  for (int i = 0, path; i < s.length(); i++) {
    path = s.at(i) - 'a';
    if (trie[cur][path] == 0) return 0;
    cur = trie[cur][path];
  }
  return last[cur];
}

int prefix(string s) {
  int cur = 1;
  for (int i = 0, path; i < s.length(); i++) {
    path = s.at(i) - 'a';
    if (trie[cur][path] == 0) return 0;
    cur = trie[cur][path];
  }
  return pass[cur];
}

void delpath(string s) {
  if (count(s)) {
    int cur = 1;
    for (int i = 0, path; i < s.length(); i++) {
      path = s.at(i) - 'a';
      if (--pass[cur] == 0) {
        trie[cur][path] = 0;
        return;
      }
      cur = trie[cur][path];
    }
    pass[cur]--;
    last[cur]--;
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int m;
  cin >> m;
  while (m--) {
    int op;
    string s;
    cin >> op >> s;
    switch (op) {
    case 1:
      insert(s);
      break;
    case 2:
      delpath(s);
      break;
    case 3:
      cout << (count(s) ? "YES" : "NO") << endl;
      break;
    case 4:
      cout << prefix(s) << endl;
      break;
    default:
      break;
    }
  }
  return 0;
}