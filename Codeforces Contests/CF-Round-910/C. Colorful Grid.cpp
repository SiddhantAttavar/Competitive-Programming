#include <bits/stdc++.h>
using namespace std;
template<typename T> inline void input(T& inVar) {cin >> inVar;}
template<typename T, typename... S> inline void input(T& inVar, S&... args) {cin >> inVar; input(args ...);}
template<typename T> inline void print(T outVar) {cout << outVar << '\n';}
template<typename T, typename... S> inline void print(T outVar, S... args) {cout << outVar << ' '; print(args ...);}
#define range(it, start, end) for (auto it = start; it < end; it++)
#define arrPut(var) for (auto &inVar : var) {cin >> inVar;}
#define arrPrint(var) for (auto outVar : var) {cout << outVar << ' ';} cout << '\n'
#define setup() ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define int long long

int32_t main() {
	setup(); int tc; input(tc); while (tc--) {
		int n, m, k;
		input(n, m, k);

		k -= n + m - 2;
		
		if (k < 0 or k % 2 == 1) {
			print("NO");
			continue;
		}

		print("YES");

		range(i, 0, m - 1) {
			if (i % 2 == 0) {
				cout << "R ";
			}
			else {
				cout << "B ";
			}
		}
		cout << endl;

		range(i, 0, m - 1) {
			if (k == 2) {
				cout << "B ";
			}
			else {
				cout << "R ";
			}
		}
		cout << endl;

		range(i, 0, m - 1) {
			cout << "B ";
		}
		cout << endl;

		range(j, 0, n - 3) {
			range(i, 0, m - 1) {
				cout << "R ";
			}
			cout << endl;
		}

		if (k == 2) {
			cout << "R R ";
		}
		else {
			cout << "B B ";
		}
		range(j, 0, m - 3) {
			cout << "R ";
		}
		if (m % 2 == 0) {
			cout << "B \n";
		}
		else {
			cout << "R \n";
		}

		range(j, 0, m - 1) {
			cout << "R ";
		}
		if (m % 2 == 1) {
			cout << "B \n";
		}
		else {
			cout << "R \n";
		}

		range(i, 2, n - 1) {
			range(j, 0, m - 1) {
				cout << "R ";
			}
			if (i % 2 == m % 2) {
				cout << "B \n";
			}
			else {
				cout << "R \n";
			}
		}

		/*
		cout << "B R ";
		range(j, 0, n - 3) {
			cout << "R ";
		}
		cout << endl;

		cout << "B R ";
		range(j, 0, n - 3) {
			cout << "R ";
		}
		cout << endl;

		range(i, 0, m - 3) {
			range(j, 0, n - 1) {
				cout << "R ";
			}
			cout << endl;
		}

		range(j, 0, n - 1) {
			if (j % 2 == m % 2) {
				cout << "B ";
			}
			else {
				cout << "R ";
			}
			cout << endl;
		}
		*/
	}
}
