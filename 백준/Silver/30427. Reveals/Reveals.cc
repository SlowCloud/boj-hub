#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;
using pll = pair<ll, ll>;
using ii = pair<int, int>;

#define FOR(i,a,b) For(i,a,b)
#define For(i,a,b) for(int i=a;i<b;i++)
#define foi(i,n) for(int i=0;i<n;i++)
#define endl '\n'
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()



int main() {
	cin.tie(0)->sync_with_stdio(0);

	string s;
	FOR(i, 0, 4) cin >> s; // remove dummy

	int N; cin >> N; 
	set<string> house;
	set<string> rumor;
	FOR(i, 0, N) {
		string s; cin >> s;
		house.insert(s);
	}
	house.insert("swi");

	int M; cin >> M;
	FOR(i, 0, M) {
		string s; cin >> s;
		rumor.insert(s);
	}


	// 1. 집에 동호가 있으면 무조건 범인
	if (house.count("dongho")) {
		cout << "dongho"; return 0;
	}

	// 2. 집에 있는 사람들 중 목격담이 0인 사람이 1명 있으면 범인
	int zero = 0; string zero_name;
	for (const auto& name : house) {
		if (rumor.count(name) == 0) {
			zero++; zero_name = name;
		}
	}
	if (zero == 1) {
		cout << zero_name; return 0;
	}

	// 3, 4, 5. 집에 있으면서 목격담이 없다면 범인
	for (const string& s : {"bumin", "cake", "lawyer"}) {
		if (house.count(s) && rumor.count(s) == 0) {
			cout << s; return 0;
		}
	}

	// 6. 집에 있으면서 목격담이 없으면 범인
	for (const auto& s : house) {
		if (s == "swi") continue;
		if (rumor.count(s) == 0) {
			cout << s; return 0;
		}
	}


}
