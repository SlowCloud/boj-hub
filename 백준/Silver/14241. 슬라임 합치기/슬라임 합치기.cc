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
	
	priority_queue<int, vector<int>, greater<>> pq;
	FOR(i, 0, N) {
		int n; cin >> n;
		pq.push(n);
	}

	int res = 0;
	while (pq.size() > 1) {
		int a = pq.top(); pq.pop();
		int b = pq.top(); pq.pop();
		res += a * b;
		pq.push(a + b);
	}
	
	cout << res;

}
