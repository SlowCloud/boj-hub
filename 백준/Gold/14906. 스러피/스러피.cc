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


bool slump(const string& s, int l, int r) {
	if (s[l] != 'D' && s[l] != 'E') return false;
	int idx = l + 1;
	while (idx < r && s[idx] == 'F') idx++;
	if (idx == l + 1) return false;
	if (idx == r - 1 && s[idx] == 'G') return true;
	return slump(s, idx, r);
}

bool slimp(const string& s, int l, int r) {
	if (s[l] != 'A') return false;
	if (r - l == 2) {
		return s[l + 1] == 'H';
	}
	if (s[r - 1] != 'C') return false;
	if (s[l + 1] == 'B') return slimp(s, l + 2, r - 1);
	else return slump(s, l + 1, r - 1);
}

bool slurp(const string& s) {
	int idx = s.size() - 1;
	while (idx >= 0 && (s[idx] != 'C' && s[idx] != 'H')) idx--;
	if (idx < 0) return false;
	return slimp(s, 0, idx + 1) && slump(s, idx + 1, s.size());
}

void test() {
	vector<string> slumps = { "DFG", "EFG", "DFFFFG", "DFDFDFDFG", "DFEFFFFG" };
	vector<string> not_slumps = {"DFEFF", "EFAHG", "DEFG", "DG", "EFFFFDG", "DFGA"};
	vector<string> slimps = {"AH", "ABAHC", "ABABAHCC", "ADFGC", "ADFFFFGC", "ABAEFGCC", "ADFDFGC"};
	vector<string> not_slimps = { "ABC", "ABAH", "DFGC", "ABABAHC", "SLIMP", "ADGC"};
	vector<string> slurpys = {"AHDFG", "ADFGCDFFFFFG", "ABAEFGCCDFEFFFFFG"};
	vector<string> not_slurpys = {"AHDFGA", "DFGAH", "ABABCC"};

	cout << "slump test" << endl;
	for (const auto& s : slumps) {
		if (!slump(s, 0, s.size())) {
			cout << "something's wrong..." << endl;
			cout << s << endl;
			exit(0);
		}
	}

	cout << "not_slump test" << endl;
	for (const auto& s : not_slumps) {
		if (slump(s, 0, s.size())) {
			cout << "something's wrong..." << endl;
			cout << s << endl;
			exit(0);
		}
	}

	cout << "slimp test" << endl;
	for (const auto& s : slimps) {
		if (!slimp(s, 0, s.size())) {
			cout << "something's wrong..." << endl;
			cout << s << endl;
			exit(0);
		}
	}

	cout << "not_slimp test" << endl;
	for (const auto& s : not_slimps) {
		if (slimp(s, 0, s.size())) {
			cout << "something's wrong..." << endl;
			cout << s << endl;
			exit(0);
		}
	}

	cout << "slurpy test" << endl;
	for (const auto& s : slurpys) {
		if (!slurp(s)) {
			cout << "something's wrong..." << endl;
			cout << s << endl;
			exit(0);
		}
	}

	cout << "not_slurpy test" << endl;
	for (const auto& s : not_slurpys) {
		if (slurp(s)) {
			cout << "something's wrong..." << endl;
			cout << s << endl;
			exit(0);
		}
	}

	cout << "test end!" << endl;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);

	// test();

	int N; cin >> N;

	cout << "SLURPYS OUTPUT" << endl;
	while (N--) {
		string s; cin >> s;
		cout << (slurp(s) ? "YES" : "NO") << endl;
	}
	cout << "END OF OUTPUT";

}
