<<<<<<< HEAD
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
const int MOD = 1e9 + 7;

int main() {
	setup();
	int tc; input(tc); while (tc--) {
		int n, m, e;
		input(n, m, e);

		int a[n][m], b[n][m];
		range(i, 0, n) {
			string s; input(s);
			range(j, 0, m) {
				a[i][j] = s[j] == '1';
			}
		}
		range(i, 0, n) {
			string s; input(s);
			range(j, 0, m) {
				b[i][j] = s[j] == '1';
			}
		}

		int totalOnes = 0;
		range(i, 0, n) {
			for (int j : a[i]) {
				totalOnes += j;
			}
		}

		if (totalOnes % 2 == 1) {
			print(-1);
			continue;
		}

		if (n == 2 && m == 2) {
			print(2);
			if (e == 1) {
				print("R 1 1 2");
				print("C 2 1 2");
			}
			continue;
		}

		//There are n * m / 2 1s to make into 0s
		//The number of operations is total ones / 2
		print(totalOnes / 2);

		if (e == 0) {
			continue;
		}

		range(i, 0, n) {
			int rowOnes = 0;
			for (int j : a[i]) {
				rowOnes += j;
			}
			if (rowOnes % 2 == 0) {
				//Pair each 1 at j with the 1 at j + 2
				range(j, 0, m) {
					if (a[i][j] == 1) {
						a[i][j] = 0;
						a[i][j + 2] = 0;
						print("R", i + 1, j + 1, j + 3);
					}
				}
			}
			else {
				//Pair each one with a one at row i + 2
				range(j, 0, m) {
					if (a[i][j] == 1) {
						a[i][j] = 0;
						a[i + 2][j] = 0;
						print("C", j + 1, i + 1, i + 3);
					}
				}
			}
		}
	}
=======
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
const int MOD = 1e9 + 7;

int main() {
	setup();
	int tc; input(tc); while (tc--) {
		int n, m, e;
		input(n, m, e);

		int a[n][m], b[n][m];
		range(i, 0, n) {
			string s; input(s);
			range(j, 0, m) {
				a[i][j] = s[j] == '1';
			}
		}
		range(i, 0, n) {
			string s; input(s);
			range(j, 0, m) {
				b[i][j] = s[j] == '1';
			}
		}

		int totalOnes = 0;
		range(i, 0, n) {
			for (int j : a[i]) {
				totalOnes += j;
			}
		}

		if (totalOnes % 2 == 1) {
			print(-1);
			continue;
		}

		if (n == 2 && m == 2) {
			print(2);
			if (e == 1) {
				print("R 1 1 2");
				print("C 2 1 2");
			}
			continue;
		}

		//There are n * m / 2 1s to make into 0s
		//The number of operations is total ones / 2
		print(totalOnes / 2);

		if (e == 0) {
			continue;
		}

		range(i, 0, n) {
			int rowOnes = 0;
			for (int j : a[i]) {
				rowOnes += j;
			}
			if (rowOnes % 2 == 0) {
				//Pair each 1 at j with the 1 at j + 2
				range(j, 0, m) {
					if (a[i][j] == 1) {
						a[i][j] = 0;
						a[i][j + 2] = 0;
						print("R", i + 1, j + 1, j + 3);
					}
				}
			}
			else {
				//Pair each one with a one at row i + 2
				range(j, 0, m) {
					if (a[i][j] == 1) {
						a[i][j] = 0;
						a[i + 2][j] = 0;
						print("C", j + 1, i + 1, i + 3);
					}
				}
			}
		}
	}
>>>>>>> f6f46ae63ca36b9fa6e961ce3b0edb092483751d
}