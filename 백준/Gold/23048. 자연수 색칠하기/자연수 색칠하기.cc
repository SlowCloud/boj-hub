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



int main() {
	cin.tie(0)->sync_with_stdio(0);

	int N; cin >> N;

	vector<int> v(N + 1);
	v[1] = 1;
	int number = 2;

	FOR(i, 2, v.size()) {
		if (v[i]) continue;
		for (int j = i; j < v.size(); j += i) {
			v[j] = number;
		}
		number++;
	}

	cout << number - 1 << endl;
	FOR(i, 1, v.size()) {
		cout << v[i] << ' ';
	}

}
