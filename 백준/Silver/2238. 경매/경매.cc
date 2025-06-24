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


map<int, vector<string>> m;


int get_price() {
	int price = -1;
	int cnt = 1e9;
	for (const auto& p : m) {
		if (p.second.size() < cnt) {
			cnt = p.second.size();
			price = p.first;
		}
	}
	return price;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int U, N; cin >> U >> N;

	FOR(i, 0, N) {
		string s; cin >> s;
		int p; cin >> p;

		m[p].push_back(s);
	}

	int target_price = get_price();
	cout << m[target_price][0] << ' ' << target_price;

}
