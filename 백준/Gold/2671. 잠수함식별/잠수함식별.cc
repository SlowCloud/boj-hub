#include <bits/stdc++.h>
#include <unordered_set>
#include <unordered_map>
#include <random>

#include <regex>

using namespace std;

#define FAST ios::sync_with_stdio(0);
#define NOTIE cin.tie(0); cout.tie(0);
constexpr int INF = 21e8;
constexpr long long LLINF = 9e18;

#define endl '\n'
typedef long long ll;
typedef pair<int, int> ii;



int main() {
	FAST; NOTIE;

	regex re("(100+1+|01)+");
	string s; cin >> s;
	cout << (regex_match(s, re) ? "SUBMARINE" : "NOISE");

} // main

