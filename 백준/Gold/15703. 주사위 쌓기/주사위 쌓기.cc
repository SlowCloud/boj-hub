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

	vector<int> v(1111);
	FOR(i, 0, N) {
		int n; cin >> n;
		v[n]++;
	}

	int res = 0;
	int cnt = N;
	while (cnt) {
		int number = 0;
		res++;
		FOR(i, 0, 1001) {
			while (v[i] && i >= number) {
				v[i]--; number++; cnt--;
			}
		}
	}

	cout << res;

}
