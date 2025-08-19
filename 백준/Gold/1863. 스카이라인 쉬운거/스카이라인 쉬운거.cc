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

	vector<pii> v(N);
	for (auto& i : v) cin >> i.first >> i.second;
	sort(all(v));

	stack<int> st;
	st.push(0);

	int res = 0;
	for (const auto& p : v) {
		const int& now = p.second;
		while (st.top() > now) {
			res++; st.pop();
		}
		if(st.top() != now) st.push(now);
	}

	while (st.size()) {
		res += !!st.top();
		st.pop();
	}
	cout << res;


}
