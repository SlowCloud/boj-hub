#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using pll = pair<ll, ll>;
using pii = pair<int, int>;

#define FOR(i, a, b) for (auto i = a; i < b; i++)
#define ALL(v) v.begin(), v.end()
#define RALL(v) v.rbegin(), v.rend()
#define endl '\n'

constexpr ll powll(ll n, ll k, ll mod = static_cast<ll>(1e9) + 7) {
  ll r = 1 % mod;
  while (k) {
    if (k & 1)
      r = (r * n) % mod;
    n = (n * n) % mod;
    k >>= 1;
  }
  return r;
};

template <typename T> constexpr auto OUT(const T R, const T C) {
  return [&](const T x, const T y) -> bool {
    return (x < 0 || x >= R || y < 0 || y >= C);
  };
}

template <typename... T> void read(T &...args);
template <char spliter = ' ', typename... T> void print(T &...args);
template <char spliter = ' ', typename... T> void debug(T &...args);

////////////////////////WORKING_AREA////////////////////////

constexpr bool LOOP = false;
constexpr bool DEBUG = true;

char board[1111][1111];
int dp[1111][1111];

void solve() {
  memset(dp, -1, sizeof dp);
  int N, M;
  cin >> N >> M;

  vector<pii> exits;
  FOR(i, 0, N) {
    FOR(j, 0, M) {
      cin >> board[i][j];
      if (board[i][j] == 'R') {
        dp[i][j] = 0;
      }
      if (board[i][j] == 'O') {
        exits.push_back({i, j});
      }
    }
  }

  FOR(j, 1, M) {
    FOR(i, 0, N) {
      if (board[i][j] == '#')
        continue;

      auto &now = dp[i][j];
      FOR(k, -1, 2) {
        int idx = i + k;
        if (idx < 0 || idx >= N)
          continue;
        if (dp[idx][j - 1] == -1)
          continue;
        now = max(now, dp[idx][j - 1] + (board[i][j] == 'C'));
      }
    }
  }

  int res = INT_MIN;
  for (const auto [x, y] : exits) {
    res = max(res, dp[x][y]);
  }
  if (res < 0)
    cout << -1;
  else
    cout << res;
}

////////////////////////////////////////////////////////////

template <typename... T> void read(T &...args) { (cin >> ... >> args); }

template <char spliter, typename... T> void print(T &...args) {
  ((cout << spliter << args), ...) << endl;
}

template <char spliter, typename... T> void debug(T &...args) {
  if constexpr (DEBUG) {
    ((cout << spliter << args), ...) << endl;
  }
}

int main() {
  if constexpr (LOOP) {
    print("loop mode");
    while (1) {
      solve();
      print("press enter to continue...");
      cin.get();
    }
  } else {
    cin.tie(0)->sync_with_stdio(0);
    solve();
  }
}
