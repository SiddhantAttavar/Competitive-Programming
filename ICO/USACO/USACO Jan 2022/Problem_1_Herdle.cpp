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
#define int long long

int32_t main() {
	setup();
	
	vector<string> a(3), b(3);
	arrPut(a);
	arrPut(b);

	int green = 0;
	range(i, 0, 3) {
		range(j, 0, 3) {
			green += a[i][j] == b[i][j];
		}
	}

	map<char, int> x;
	for (string str : a) {
		for (char c : str) {
			x[c]++;
		}
	}

	int yellow = 0;
	for (string str : b) {
		for (char c : str) {
			if (x.count(c)) {
				yellow++;
				x[c]--;
				if (x[c] == 0) {
					x.erase(c);
				}
			}
		}
	}

	print(green);
	print(yellow - green);
}
