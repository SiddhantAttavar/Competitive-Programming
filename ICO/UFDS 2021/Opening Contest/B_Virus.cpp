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
	setup();
	
	int n, m;
	input(n, m);
	
	vector<vector<bool>> a(n, vector<bool>(m));
	bool flag = false;
	range(i, 0, n) {
		string s;
		input(s);
		range(j, 0, m) {
			a[i][j] = s[j] == '1';
			flag |= a[i][j];
		}
	}
	if (!flag) {
		print(-1);
		return 0;
	}

	int minX = 1e9, minY = 1e9;
	int currX = 0, currY = 0;
	range(i, 1, n - 1) {
		range(j, 1, m) {
			if (a[i][j]) {
				currY++;
			}
			else if (a[i][j - 1]) {
				minY = min(minY, currY);
				currY = 0;
			}
		}
	}
	range(j, 1, m - 1) {
		range(i, 1, n) {
			if (a[i][j]) {
				currX++;
			}
			else if (a[i - 1][j]) {
				minX = min(minX, currX);
				currX = 0;
			}
		}
	}

	int k = (min(minX, minY) - 1) / 2;
	int ks = (2 * k + 1) * (2 * k + 1);

	vector<vector<int>> pSum(n, vector<int>(m));
	range(i, 1, n) {
		range(j, 1, m) {
			pSum[i][j] = a[i][j] + pSum[i][j - 1] + pSum[i - 1][j] - pSum[i - 1][j - 1];
		}
	}

	print(k);
	range(i, 0, n) {
		range(j, 0, m) {
			int x1 = i - k - 1, y1 = j - k - 1;
			int x2 = i + k, y2 = j + k;
			cout << (
				(x1 >= 0 and x2 < n and y1 >= 0 and y2 < m) and
				(pSum[x2][y2] - pSum[x1][y2] - pSum[x2][y1] + pSum[x1][y1]) == ks
			);
		}
		cout << endl;
	}
}
