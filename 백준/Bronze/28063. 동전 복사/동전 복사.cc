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


bool isVertex(int r, int c, int N) {
	return (r == 1 || r == N) && (c == 1 || c == N);
}

bool isEdge(int r, int c, int N) {
	return (r == 1 || r == N) || (c == 1 || c == N);
}

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int N; cin >> N;

	if (N == 1) {
		cout << 0; exit(0);
	}

	int r, c; cin >> r >> c;

	// vertex
	if (isVertex(r, c, N)) {
		cout << 2;
		exit(0);
	}

	// edge
	if (isEdge(r, c, N)) {
		cout << 3;
		exit(0);
	}

	// center
	cout << 4;

}

