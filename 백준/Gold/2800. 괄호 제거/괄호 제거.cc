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
	
	string s; cin >> s;

	stack<int> st;
	vector<int> checker(s.size(), -1);

	int number = 0;
	FOR(i, 0, s.size()) {
		char now = s[i];
		if (now == '(') {
			st.push(i);
		}
		else if (now == ')') {
			checker[st.top()] = checker[i] = number++;
			st.pop();
		}
	}

	set<string> res;
	FOR(i, 1, 1 << number) {
		string tmp;
		FOR(j, 0, s.size()) {
			if (checker[j] != -1 && i & (1 << checker[j])) continue;
			tmp.push_back(s[j]);
		}
		res.insert(tmp);
	}

	for (const auto& s : res) cout << s << endl;

}
