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

	if (N == 1) {
		cout << "A"; exit(0);
	}

	vector<int> v(N);
	for (auto& i : v) cin >> i;

	set<int> res;

	for (int a = -1e7; a <= 1e7; a++) {

		int first, second;
		first = v[0];
		second = v[1];

		// first*a + b = second
		// b = second - first* a
		int b = second - first * a;

		bool possible = true;
		for (int i = 0; i < v.size() - 1; i++) {
			int l, r;
			l = v[i];
			r = v[i + 1];
			if (l * a + b != r) {
				possible = false; break;
			}
		}

		if (possible) {
			res.insert(v.back() * a + b);
		}

		if (res.size() > 1) break;

	}

	if (res.empty()) {
		cout << "B";
	}
	else if (res.size() > 1) {
		cout << "A";
	}
	else {
		cout << *res.begin();
	}

}
