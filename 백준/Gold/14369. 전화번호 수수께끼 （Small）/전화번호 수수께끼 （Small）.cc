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


struct Count {
	int cnt[26];
	Count() {
		reset();
	}
	void add(const string s) {
		for (char c : s) {
			cnt[c - 'A']++;
		}
	}
	void sub(const string s) {
		for (char c : s) {
			cnt[c - 'A']--;
		}
	}
	void reset() {
		memset(cnt, 0, sizeof cnt);
	}
	bool same(const Count c) const {
		FOR(i, 0, 26) {
			if (cnt[i] != c.cnt[i]) return false;
		}
		return true;
	}
	bool over(const Count c) const {
		FOR(i, 0, 26) {
			if (cnt[i] < c.cnt[i]) return true;
		}
		return false;
	}
};

string words[] = {
	"ZERO", "ONE","TWO","THREE","FOUR","FIVE","SIX","SEVEN","EIGHT","NINE"
};

Count target, now;

vector<int> v;
bool dfs(int n) {
	v.push_back(n);
	now.add(words[n]);
	if (target.same(now)) {
		for (auto& i : v) cout << i; cout << endl;
		now.sub(words[n]);
		v.pop_back();
		return true;
	}
	if (target.over(now)) {
		now.sub(words[n]);
		v.pop_back();
		return false;
	}
	FOR(i, 0, 10) {
		if (dfs(i)) {
			now.sub(words[n]);
			v.pop_back();
			return true;
		}
	}
	now.sub(words[n]);
	v.pop_back();
	return false;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int T; cin >> T;
	FOR(t, 1, T + 1) {
		string S; cin >> S;
		target.reset();
		target.add(S);


		cout << "Case #" << t << ": ";
		FOR(i, 0, 10) {
			if (dfs(i)) break;
		}

	}

}
