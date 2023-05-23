#include "sequence.h"

#include <vector>
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

pair<int, int> median(int n, vector<int> &a, int l, int r) {
	int m = r - l + 1;
	vector<int> b;
	range(i, l, r + 1) {
		b.push_back(a[i]);
	}
	sort(b.begin(), b.end());

	if (m & 1) {
		return {b[m / 2], b[m / 2]};
	}
	else {
		return {b[m / 2 - 1], b[m / 2]};
	}
}

int w(int n, vector<int> &a, int l, int r, int x) {
	int c = 0;
	range(i, l, r + 1) {
		if (a[i] == x) {
			c++;
		}
	}
	return c;
}

// General case
/* int sequence(int n, std::vector<int> a) {
	int res = 0;
	range(i, 0, n) {
		range(j, i, n) {
			int x, y;
			tie(x, y) = median(n, a, i, j);
			res = max(res, w(n, a, i, j, x));
			if (x != j) {
				res = max(res, w(n, a, i, j, y));
			}
		}
	}
	return res;
} */

// Subtask 5
/* int sequence(int n, std::vector<int> a) {
	range(i, 0, n -  1) {
		if (a[i] == a[i + 1]) {
			return 2;
		}
	}
	return 1;
} */

// Subtask 4
/* vector<vector<int>> freq;

int check(int n, vector<int> &a, int x, int l) {
	int res = 0;
	range(i, 0, n - l + 1) {
		int j = i + l - 1;
		res = max(res, freq[x][j + 1] - freq[x][i]);
	}

	if (x == 1 or x == 3) {
		if (res >= (l + 1) / 2) {
			return res;
		}
		else {
			return -1;
		}
	}
	else {
		return res;
	}
}

int sequence(int n, std::vector<int> a) {
	// Precompute freq
	freq.clear();
	freq.resize(3, vector<int>(n + 1, 0));
	range(i, 0, n) {
		range(j, 0, 3) {
			freq[j][i + 1] = freq[j][i] + (a[i] == (j + 1));
		}
	}

	int res = 0;
	range(i, 0, 3) {
		int l = 0, r = n;
		while (l <= r) {
			int m = (l + r) / 2;
			int x = check(n, a, i, m);
			if (x == -1) {
				r = m - 1;
			}
			else {
				l = m + 1;
				res = max(res, x);
			}
		}
	}

	return res;
} */

// Subtask 3
int sequence(int n, std::vector<int> a) {
	// Find largest term
	int x = 0;
	while (x < n - 1 and a[x] <= a[x + 1]) {
		x++;
	}

	int res = 1;

	// Check left end
	int c = 1;
	range(i, 1, x + 1) {
		if (a[x] == a[x - 1]) {
			c++;
			res = max(res, c);
		}
		else {
			c = 1;
		}
	}

	// Check right end
	c = 1;
	range(i, x + 1, n) {
		if (a[x] == a[x - 1]) {
			c++;
			res = max(res, c);
		}
		else {
			c = 1;
		}
	}

	// Check from largest point
	int l = x, r = x;
	vector<int> b;
	map<int, int> freq;
	freq[a[x]] = 1;
	b.push_back(a[x]);

	while (l >= 0 and r < n) {
		// Add element
		int u;
		if (l > 0) {
			if (r < n - 1) {
				if (a[l - 1] > a[r + 1]) {
					u = l - 1;
					l--;
				}
				else {
					u = r + 1;
					r++;
				}
			}
			else {
				u = l - 1;
				l--;
			}
		}
		else {
			u = r + 1;
			r++;
		}

		// Update freq and b
		if (freq.count(a[u])) {
			freq[a[u]]++;
		}
		else {
			freq[a[u]] = 1;
		}
		b.push_back(a[u]);


		// Find median and get value of w for current b
		if (b.size() & 1) {
			res = max(res, freq[a[b.size() / 2]]);
		}
		else {
			res = max({res, freq[a[b.size() / 2]], freq[a[b.size()/ 2 - 1]]});
		}
	}

	return res;
}

#include "grader.cpp"
