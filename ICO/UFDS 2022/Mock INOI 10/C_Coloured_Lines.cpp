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
	int n, c, p; input(n, c, p);
	c--;
	if (n < 3) {
		print(0);
		return 0;
	}

	vector<vector<int>> a(n, vector<int>(n));
	range(i, 0, n) {
		string s; input(s);
		range(j, 0, n) {
			if (s[j] == 'o') {
				a[i][j] = 0;
			}
			else if (s[j] == 'r') {
				a[i][j] = 1;
			}
			else {
				a[i][j] = 2;
			}
		}
	}

	vector<int> maxCol(n, 1);
	range(i, 0, n) {
		range(j, 1, n) {
			if (a[j][i] != a[j - 1][i]) {
				c = 1;
			}
			else {
				c++;
				maxCol[i] = max(maxCol[i], c);
			}
		}
	}

	vector<vector<int>> maxBeg(n, vector<int>(n, 1));
	range(i, 0, n) {
		range(j, 1, n) {
			if (a[i][j] == a[i][j - 1]) {
				maxBeg[i][j] = maxBeg[i][j - 1] + 1;
			}
			else {
				maxBeg[i][j] = 1;
			}
		}
	}
	vector<vector<int>> maxEnd(n, vector<int>(n, 1));
	range(i, 0, n) {
		for (int j = n - 1; j >= 0; j--) {
			if (a[i][j] == a[i][j + 1]) {
				maxEnd[i][j] = maxEnd[i][j + 1] + 1;
			}
			else {
				maxEnd[i][j] = 1;
			}
		}
	}

	swap(maxBeg, maxEnd);

	vector<int> maxRowBeg(n, 1);
	range(i, 0, n) {
		range(j, 0, n) {
			maxRowBeg[j] = max({maxRowBeg[j], maxBeg[i][j], maxCol[j]});
		}
	}
	vector<int> maxRowEnd(n, 1);
	range(i, 0, n) {
		range(j, 0, n) {
			maxRowEnd[j] = max({maxRowEnd[j], maxEnd[i][j], maxCol[j]});
		}
	}
	range(i, 0, n) {
		arrPrint(maxBeg[i]);
	}
	

	int res = 0;
	int currSum = 0;
	for (int i = c; i >= 0; i--) {
		res = max(res, currSum + maxRowBeg[i] * maxRowBeg[i] * (p - (c - i)));
		currSum += maxRowBeg[i] * maxRowBeg[i];
		print(res);
	}
	currSum = 0;
	for (int i = c; i < n; i++) {
		res = max(res, currSum + maxRowEnd[i] * maxRowEnd[i] * (p - (i - c)));
		currSum += maxRowEnd[i] * maxRowEnd[i];
	}
	print(res);
}
