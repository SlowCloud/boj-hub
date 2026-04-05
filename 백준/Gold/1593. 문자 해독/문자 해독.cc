#include <bits/stdc++.h>
using namespace std;

#define FOR(i,a,b) for(auto i=a;i<b;i++)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()

using ll = long long;


map<char, int> cnt, cnt_window;

inline bool same() {
	if(cnt.size() != cnt_window.size()) return false;
	for(const auto p : cnt) {
		if(cnt_window.find(p.first) == cnt_window.end()) return false;
		if(cnt_window[p.first] != p.second) return false;
	}
	return true;
}

int main() {
	std::cin.tie(0)->sync_with_stdio(0);

	int w, g; cin >> w >> g;

	string now; cin >> now;
	for(char c : now) {
		cnt[c]++;
	}

	string s; cin >> s;
	FOR(i,0,w) {
		cnt_window[s[i]]++;
	}

	int res = 0;
	res += same();

	FOR(i,w,g) {
		char prev = s[i - w];
		cnt_window[prev]--;
		if(cnt_window[prev] == 0) {
			cnt_window.erase(prev);
		}
		cnt_window[s[i]]++;
		res += same();
	}

	cout << res;


	return 0;
}