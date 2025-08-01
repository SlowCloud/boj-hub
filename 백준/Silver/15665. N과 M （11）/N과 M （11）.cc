#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;

using ll = long long;
using pll = pair<ll, ll>;
using pii = pair<int, int>;

#define FOR(i,a,b) for(int i=a;i<b;i++)
#define endl '\n'
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()


vector<int> v;

vector<int> res;
void dfs(int M) {
	if (M == 0) {
		for (auto& i : res) {
			cout << i << ' ';
		}
		cout << endl;
		return;
	}
	FOR(i, 0, v.size()) {
		res.push_back(v[i]);
		dfs(M - 1);
		res.pop_back();
	}
}

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int N, M; cin >> N >> M;
	FOR(i, 0, N) {
		int n; cin >> n;
		v.push_back(n);
	}
	sort(all(v));
	v.erase(unique(all(v)), v.end());
	
	dfs(M);

}
