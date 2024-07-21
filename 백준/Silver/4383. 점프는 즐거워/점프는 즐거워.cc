#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;
using pll = pair<ll, ll>;
using ii = pair<int, int>;

#define FOR(i,a,b) For(i,a,b)
#define For(i,a,b) for(int i=a;i<b;i++)
#define foi(i,n) for(int i=0;i<n;i++)
#define endl '\n'
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()


int main() {
	cin.tie(0)->sync_with_stdio(0);

	int N;
	while (cin >> N) {
		vector<ll> v(N);
		for (auto& i : v) cin >> i;

		if (N == 1) {
			cout << "Jolly" << endl;
			continue;
		}

		vector<ll> w;
		For(i, 1, N) {
			w.push_back(abs(v[i] - v[i - 1]));
		}
		sort(all(w));

		bool flag = true;
		if (w[0] != 1) flag = false;
		if(flag) For(i, 1, w.size()) {
			if (w[i] - w[i - 1] != 1) {
				flag = false; break;
			}
		}
		if (flag) cout << "Jolly";
		else cout << "Not jolly";
		cout << endl;
	}

}