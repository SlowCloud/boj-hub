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

	int N; cin >> N;
	vector<int> A;
	FOR(i, 0, N) {
		int n; cin >> n;
		A.push_back(n);
	}

	int M; cin >> M;
	vector<int> B;
	FOR(i, 0, M) {
		int n; cin >> n;
		B.push_back(n);
	}


	vector<int> res;

	int mx = 100;
	auto iter_a = A.begin(), iter_b = B.begin();
	for (int i = mx; i >= 1; i--) {
		while (1) {
			auto nxt_a = find(iter_a, A.end(), i);
			auto nxt_b = find(iter_b, B.end(), i);
			if (nxt_a == A.end() || nxt_b == B.end()) {
				break;
			}
			res.push_back(i);
			iter_a = next(nxt_a);
			iter_b = next(nxt_b);
		}
	}

	cout << res.size() << endl;
	for (auto& i : res) cout << i << ' ';


}
