#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

#include <bits/stdc++.h>
#include <unordered_set>
#include <regex>
using namespace std;

using ll = long long;
using pll = pair<ll, ll>;
using pii = pair<int, int>;

#define FOR(i,a,b) for(int i=a;i<b;i++)
#define endl '\n'
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()


set<pii> s;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int N; cin >> N;

	vector<int> v(N);
	FOR(i, 0, N) {
		int n; cin >> n;
		s.insert({ n,i });
		v[i] = n;
	}

	int M; cin >> M;
	while (M--) {
		int n; cin >> n;
		if (n == 1) {
			int i, now; cin >> i >> now;
			i--;
			s.erase({ v[i],i });
			v[i] = now;
			s.insert({ v[i],i });
		}
		else {
			auto [_, i] = *s.begin();
			cout << i+1 << endl;
		}
	}

}
