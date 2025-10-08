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



int main() {
	cin.tie(0)->sync_with_stdio(0);

	int N; cin >> N;

	vector<int> v(N);
	for (auto& i : v) cin >> i;

	vector<int> res(N);
	int idx = 0;
	int cnt = 0;
	for (const int n : v) {
		res[idx] = n;
		idx = (idx + n) % N;
		cnt++;
		if (cnt < N) while (res[idx]) idx = (idx + 1) % N;
	}

	cout << N << endl;
	for (auto& i : res) cout << i << ' ';

}
