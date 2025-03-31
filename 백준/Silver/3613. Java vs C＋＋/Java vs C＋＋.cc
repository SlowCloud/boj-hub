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



vector<int> G[222'222];
vector<pii> edges;


// 대문자가 없어야 함
// 언더바가 연속 2개 이상 있으면 안 됨
// 처음과 끝에 언더바가 있으면 안 됨
bool c(string s) {
	if (s[0] == '_' || s.back() == '_') {
		return false;
	}
	for (char c : s) {
		if (isupper(c)) return false;
	}
	int cnt = 0;
	for (char c : s) {
		if (c == '_') {
			cnt++;
			if (cnt > 1) return false;
		}
		else {
			cnt = 0;
		}
	}
	return true;
}

// 첫 문자는 소문자여야 함
// 언더바가 있으면 안 됨
bool java(string s) {
	if (isupper(s[0])) return false;
	for (char c : s) {
		if (c == '_') return false;
	}
	return true;
}

string to_c(string s) {
	string res;
	for (char c : s) {
		if (isupper(c)) {
			res.push_back('_');
			res.push_back(tolower(c));
		}
		else res.push_back(c);
	}
	return res;
}

string to_java(string s) {
	string res;
	bool flag = false;
	for (char c : s) {
		if (c == '_') {
			flag = true; continue;
		}
		if (flag) {
			res.push_back(toupper(c));
			flag = false;
		}
		else {
			res.push_back(c);
		}
	}
	return res;
}

/*

자바

C

*/


int main() {
	cin.tie(0)->sync_with_stdio(0);

	string s; cin >> s;

	if (java(s)) {
		cout << to_c(s);
	}
	else if(c(s)) {
		cout << to_java(s);
	}
	else {
		cout << "Error!";
	}

}

