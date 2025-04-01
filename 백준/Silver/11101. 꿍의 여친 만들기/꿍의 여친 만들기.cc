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


vector<string> split(const string s, const char sp) {
	vector<string> v;
	string tmp;
	for (char c : s) {
		if (c == sp) {
			v.push_back(tmp);
			tmp.clear();
			continue;
		}
		tmp.push_back(c);
	}
	if (tmp.size()) {
		v.push_back(tmp);
	}
	return v;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int T; cin >> T;
	while (T--) {
		string score, div;
		cin >> score >> div;
		vector<string> score_tokens = split(score, ',');
		map<string, int> scores;
		for (auto& tokens : score_tokens) {
			vector<string> tmp = split(tokens, ':');
			string name = tmp[0];
			int score = stoi(tmp[1]);
			scores[name] = score;
		}

		auto div_tokens = split(div, '|');
		int res = -1;
		for (auto& tokens : div_tokens) {
			auto tmp = split(tokens, '&');
			int now = 0;
			for (auto& name : tmp) {
				now = max(now, scores[name]);
			}
			if (res == -1 || res > now) {
				res = now;
			}
		}

		cout << res << endl;
	}


}

