#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;

using ll = long long;
using ull = unsigned long long;
using pll = pair<ll, ll>;
using pii = pair<int, int>;
using ii = pair<int, int>;

#define FOR(i,a,b) For(i,a,b)
#define For(i,a,b) for(int i=a;i<b;i++)
#define foi(i,n) for(int i=0;i<n;i++)
#define endl '\n'
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()

ll board[555][555];
ll dots[555][555];
vector<ll> k;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int N; cin >> N;
	FOR(i, 1, N + 1) {
		FOR(j, 1, N + 1) {
			cin >> board[i][j];
			if (board[i][j] == 0) {
				dots[i][j] = 1;
			}
			board[i][j] += board[i][j - 1];
			dots[i][j] += dots[i][j - 1];
		}
		FOR(j, 1, N + 1) {
			board[i][j] += board[i - 1][j];
			dots[i][j] += dots[i - 1][j];
		}
	}

	int K; cin >> K;
	k.resize(K);
	FOR(i, 0, K) {
		cin >> k[i];
	}
	sort(rall(k));
	FOR(i, 1, K) {
		k[i] += k[i - 1];
	}

	ll res = 0;

	auto out = [&](int a, int b) {
		return min(a, b) < 1 || max(a, b) > N;
	};

	FOR(i, 1, N + 1) {
		FOR(j, 1, N + 1) {
			FOR(sz, 1, N + 1) { // 이 순서가 훨씬 적게 검사를 진행할 것 같음
				int ii, jj;
				ii = i + sz - 1;
				jj = j + sz - 1;
				if (out(ii, jj)) break;
				int dot_count = dots[ii][jj] - dots[ii][j - 1] - dots[i - 1][jj] + dots[i - 1][j - 1];
				if (dot_count > K) break;
				ll now = board[ii][jj] - board[ii][j - 1] - board[i - 1][jj] + board[i - 1][j - 1];
				if(dot_count) now += k[dot_count - 1];
				res = max(now, res);
			}
		}
	}

	cout << res;

}

