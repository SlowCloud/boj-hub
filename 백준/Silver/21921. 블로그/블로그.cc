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

	int N, X; cin >> N >> X;

	vector<int> v(N);
	for (auto& i : v) cin >> i;

	ll res = 0, sum = 0;
	int cnt = 0;
	queue<int> q;

	FOR(i, 0, X) {
		q.push(v[i]);
		sum += v[i];
	}

	res = sum;
	cnt = 1;

	FOR(i, X, N) {
		sum -= q.front(); q.pop();
		q.push(v[i]); sum += v[i];
		if(res < sum) {
			res = sum;
			cnt = 1;
		}
		else if (res == sum) {
			cnt++;
		}
	}

	if (res == 0) {
		cout << "SAD";
	}
	else 
	cout << res << ' ' << cnt;

}
