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

	int T; cin >> T;
	while (T--) {
		int N; cin >> N;
		int NN = N * N;
		string n = to_string(N);
		string nn = to_string(NN);
		if (nn.substr(nn.size() - n.size()) == n) {
			cout << "YES";
		}
		else cout << "NO";
		cout << endl;
	}

}
