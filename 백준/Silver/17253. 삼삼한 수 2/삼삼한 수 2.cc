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

	ll N; cin >> N;

	if (N == 0) {
		cout << "NO"; exit(0);
	}

	while (N > 0) {
		if (N % 3 == 2) {
			cout << "NO"; exit(0);
		}
		N /= 3;
	}
	cout << "YES";

}
