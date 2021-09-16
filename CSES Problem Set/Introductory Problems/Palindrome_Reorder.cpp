#include <bits/stdc++.h>
#define range(it, start, end) for (int it = start; it < end; it++)
#define input(x) cin >> x
#define print(x) cout << x << endl
#define arrPut(var) for (auto &i : var) {cin >> i;}
#define arrPrint(var) for (auto outVar : var) {cout << outVar << " ";} cout << endl
#define setup() ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
using namespace std;
typedef long long ll;
const int MOD = 1e9 + 7;

int main() {
	setup();
	
	string s; input(s);
	unordered_map<char, int> freq;
	for (char c : s) {
		freq[c]++;
	}

	char odd = ' ';
	string a;
	for (pair<char, int> p : freq) {
		if (p.second % 2 == 1) {
			if (odd == ' ') {
				odd = p.first;
				p.second--;
			}
			else {
				print("NO SOLUTION");
				return 0;
			}
		}
		range(i, 0, p.second / 2) {
			a += p.first;
		}
	}

	for (char c : a) {
		cout << c;
	}
	if (odd != ' ') {
		cout << odd;
	}
	reverse(a.begin(), a.end());
	for (char c : a) {
		cout << c;
	}
}