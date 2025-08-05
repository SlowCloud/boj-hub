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


int N, L;

struct Stick {
	int s, e, d;
	Stick(int l, int d) {
		if (d == 0) {
			s = 0; e = s + l;
		}
		else {
			e = L - 1; s = e - l;
		}
		this->d = d; // move to; 0: right, 1: left
	}
	void move() {
		if (d == 0) {
			s++; e++;
			if (e == L - 1) d ^= 1;
		}
		else {
			s--; e--;
			if (s == 0) d ^= 1;
		}
	}
	bool overlap(const Stick& st) const {
		return (s <= st.s && st.s <= e) || (s <= st.e && st.e <= e) ||
			(st.s <= s && s <= st.e) || (st.s <= e && e <= st.e);
	}
};

vector<Stick> sticks;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	cin >> N >> L;

	FOR(i, 0, N) {
		int l, d; cin >> l >> d;
		sticks.push_back(Stick(l, d));
	}

	int now = 0;
	int res = 0;
	while (1) {
		while (now < sticks.size() - 1 && sticks[now].overlap(sticks[now + 1])) {
			now++;
		}
		if (now == sticks.size() - 1) break;
		res++;
		FOR(i, now, sticks.size()) {
			sticks[i].move();
		}
	}

	cout << res;

}
