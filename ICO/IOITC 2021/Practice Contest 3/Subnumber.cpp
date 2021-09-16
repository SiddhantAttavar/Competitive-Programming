#include <bits/stdc++.h>
using namespace std;
template<typename T> inline void input(T& inVar) {cin >> inVar;}
template<typename T, typename... S> inline void input(T& inVar, S&... args) {cin >> inVar; input(args ...);}
template<typename T> inline void print(T outVar) {cout << outVar << endl;}
template<typename T, typename... S> inline void print(T outVar, S... args) {cout << outVar << ' '; print(args ...);}
#define range(it, start, end) for (int it = start; it < end; it++)
#define arrPut(var) for (auto &inVar : var) {cin >> inVar;}
#define arrPrint(var) for (auto outVar : var) {cout << outVar << ' ';} cout << endl
#define setup() ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
typedef long long ll;

bool isGreater(string a, string b) {
	if (a.size() > b.size()) {
		return true;
	}
	if (a.size() < b.size()) {
		return false;
	}

	range(i, 0, a.size()) {
		if (a[i] > b[i]) {
			return true;
		}
		if (a[i] < b[i]) {
			return false;
		}
	}
	
	return false;
}

int main() {
	//setup();

	string s; input(s);
	int n = s.size();

	string a[n + 1];
	range(i, 1, n + 1) {
		a[i] = "";
		range(j, 0, i) {
			a[i] += '0';
		}
	}

	range(i, 1, (1 << n)) {
		string curr;
		range(j, 0, n) {
			if ((i & (1 << j)) > 0) {
				curr += s[j];
			}
		}

		if (isGreater(curr, a[curr.size()])) {
			a[curr.size()] = curr;
		}
	}

	int m; input(m); while (m--) {
		int k, l; input(k, l);
		cout << a[k][l - 1];
	}
}