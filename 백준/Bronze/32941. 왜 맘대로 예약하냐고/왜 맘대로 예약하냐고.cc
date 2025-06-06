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


int main() {
	cin.tie(0)->sync_with_stdio(0);

	int T, X; cin >> T >> X;
	int N; cin >> N;

	int cnt = 0;

	FOR(i, 0, N) {
		int K; cin >> K;
		FOR(j, 0, K) {
			int n; cin >> n;
			cnt += n == X;
		}
	}

	cout << (cnt == N ? "YES" : "NO");

}
