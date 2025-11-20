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

// 해당 구현은 객체지향적으로 좋은 방법이 아니라는 점 참고해주시길 바랍니다

map<int, int> used;

struct Card {
	int idx;
	string command;
	int target;
	bool exist;
	bool try_use(int who) {
		if (command == "next") {
			return true;
		}
		else if (command == "release") {
			used.erase(target);
			return true;
		}
		else {
			if (used[target] != 0) {
				return false;
			}
			else {
				used[target] = who;
				return true;
			}
		}
	}
	void clear() {
		exist = false;
	}
};

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int N, T; cin >> N >> T;

	vector<int> v(T);
	for (auto& i : v) cin >> i;

	vector<Card> hand(N + 1);
	vector<int> res;

	FOR(i, 0, T) {

		const int now = v[i];
		if (hand[now].exist) {
			res.push_back(hand[now].idx);
			bool result = hand[now].try_use(now);
			if (result) {
				hand[now].clear();
			}
			continue;
		}

		int n; string s; cin >> n >> s;
		int target = 0;
		if (s != "next") {
			cin >> target;
		}
		Card now_card = { n,s,target,true };

		bool result = now_card.try_use(now);
		if(!result) {
			hand[now] = now_card;
		}
		res.push_back(n);

	}

	for (auto& i : res) cout << i << ' ';



}
