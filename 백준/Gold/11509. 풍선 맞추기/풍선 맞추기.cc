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


int arrows[1'111'111];

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int N; cin >> N;

	vector<int> v;
	FOR(i, 0, N) {
		int n; cin >> n;
		v.push_back(n);
	}

	int res = 0;
	for (const int& i : v) {
		if (arrows[i] == 0) {
			res++; arrows[i] = 1;
		}
		arrows[i]--; arrows[i - 1]++;
	}

	cout << res;

}
