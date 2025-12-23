#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

#include <bits/stdc++.h>
#include <unordered_set>
#include <regex>
#include <algorithm>
using namespace std;

using ll = long long;
using pll = pair<ll, ll>;
using pii = pair<int, int>;

#define FOR(i,a,b) for(int i=a;i<b;i++)
#define endl '\n'
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()



unordered_map<char, char> p = {
	{'[', ']'}, {']', '['},
	{'(', ')'}, {')', '('},
	{'{', '}'}, {'}', '{'},
};

inline bool is_left(const char& c) {
	return c == '[' || c == '(' || c == '{';
}

bool check(const string& s) {
	stack<char> st;
	for (const char& c : s) {
		if (is_left(c)) {
			st.push(c);
		}
		else {
			if (st.empty() || p[st.top()] != c) {
				return false;
			}
			st.pop();
		}
	}
	return st.empty();
}

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int N; cin >> N;

	while (N--) {
		string s; cin >> s;

		if (s.size() % 2) {
			cout << "NO" << endl;
			continue;
		}

		if (check(s)) {
			cout << "YES 0" << endl;
			continue;
		}

		int pos = -1;
		char changed = '\0';
		FOR(i, 0, s.size()) {
			char tmp = s[i];
			for (const char& c : "(){}[]") {
				s[i] = c;
				if (check(s)) {
					pos = i;
					changed = c;
					goto end;
				}
			}
			s[i] = tmp;
		}
		end:

		if (pos == -1) {
			cout << "NO" << endl;
		}
		else {
			cout << "YES 1" << endl << pos + 1 << " " << changed << endl;
		}

	}


}
