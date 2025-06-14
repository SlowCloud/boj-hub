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

struct Node {
	int year;
	string name;
};

vector<Node> nodes = {
	{1967, "DavidBowie"},
	{1969, "SpaceOddity"},
	{1970, "TheManWhoSoldTheWorld"},
	{1971, "HunkyDory"},
	{1972, "TheRiseAndFallOfZiggyStardustAndTheSpidersFromMars"},
	{1973, "AladdinSane"},
	{1973, "PinUps"},
	{1974, "DiamondDogs"},
	{1975, "YoungAmericans"},
	{1976, "StationToStation"},
	{1977, "Low"},
	{1977, "Heroes"},
	{1979, "Lodger"},
	{1980, "ScaryMonstersAndSuperCreeps"},
	{1983, "LetsDance"},
	{1984, "Tonight"},
	{1987, "NeverLetMeDown"},
	{1993, "BlackTieWhiteNoise"},
	{1995, "1.Outside"},
	{1997, "Earthling"},
	{1999, "Hours"},
	{2002, "Heathen"},
	{2003, "Reality"},
	{2013, "TheNextDay"},
	{2016, "BlackStar"},
};

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int Q; cin >> Q;
	while (Q--) {

		int S, E; cin >> S >> E;

		vector<Node> res;
		for (const auto& node : nodes) {
			if (S <= node.year && node.year <= E) {
				res.push_back(node);
			}
		}

		cout << res.size() << endl;
		for (auto& r : res) {
			cout << r.year << ' ' << r.name << endl;
		}


	}

}
