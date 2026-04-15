#include <string>
#pragma GCC optimize("O3")

#include <bits/stdc++.h>
using namespace std;

#define ALL(v) v.begin(), v.end()
#define FOR(i, a, b) for (auto i = a; i < b; i++)
#define endl '\n'

using pii = pair<int, int>;

vector<int> G[1111];
int vst[1111];
int p[1111];

int main() {
  ios::sync_with_stdio(0);

  int N, K;
  cin >> N >> K;

  vector<int> v;
  FOR(i, 0, N) {
    string s;
    cin >> s;
    int now = stoi(s, nullptr, 2);
    v.push_back(now);
  }

  FOR(i, 0, N) {
    FOR(j, i + 1, N) {
      int tmp = v[i] ^ v[j];
      int w = 0;
      while (tmp) {
        w += tmp & 1;
        tmp >>= 1;
      }
      if (w != 1)
        continue;
      G[i].push_back(j);
      G[j].push_back(i);
    }
  }

  int s, e;
  cin >> s >> e;
  s--;
  e--;

  queue<int> q;
  q.push(s);
  memset(vst, 0, sizeof vst);
  vst[s] = 1;

  while (q.size()) {
    int now = q.front();
    q.pop();
    for (int next : G[now]) {
      if (vst[next])
        continue;
      vst[next] = 1;
      p[next] = now;
      q.push(next);
    }
  }

  if (vst[e] == 0) {
    cout << -1;
    exit(0);
  }

  p[s] = -1;
  vector<int> way;
  for (int now = e; now != -1; now = p[now]) {
    way.push_back(now);
  }
  reverse(ALL(way));
  for (const auto &v : way)
    cout << v + 1 << ' ';
  cout << endl;

  return 0;
}
