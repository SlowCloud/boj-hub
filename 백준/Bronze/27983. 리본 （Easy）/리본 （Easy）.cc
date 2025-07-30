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


int X[1111], L[1111];
char C[1111];

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int N; cin >> N;

	FOR(i, 0, N) cin >> X[i];
	FOR(i, 0, N) cin >> L[i];
	FOR(i, 0, N) cin >> C[i];
	
	FOR(i, 0, N) {
		FOR(j, i + 1, N) {
			int gap = abs(X[i] - X[j]);
			int length = L[i] + L[j];
			if (gap > length) continue;
			if (C[i] == C[j]) continue;
			cout << "YES" << endl;
			cout << i + 1 << ' ' << j + 1; exit(0);
		}
	}

	cout << "NO";

}

