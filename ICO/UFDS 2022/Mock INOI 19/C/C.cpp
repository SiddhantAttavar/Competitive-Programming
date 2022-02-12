#include <bits/stdc++.h>
using namespace std;
template<typename T> inline void input(T &x) {cin >> x;}
template<typename T, typename... S> inline void input(T &x, S&... y) {cin >> x; input(y ...);}
template<typename T> inline void print(T x) {cout << x << '\n';}
template<typename T, typename... S> inline void print(T x, S... y) {cout << x << ' '; print(y ...);}
#define arrPut(x) for (auto &i : x) {cin >> i;}
#define arrPrint(x) for (auto i : x) {cout << i << ' ';} cout << '\n'
#define range(i, j, n) for (int i = j; i < n; i++)
#define setup() ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define int long long

int getMax(vector<int> &a, vector<int> &b, int p, int m) {
	int res = 0;
	range(i, 0, a.size()) {
		if (a[i] >= p) {
			res += p;
		}
		else if (b[i] >= m) {
			res += m;
		}
	}
	return res;
}

int32_t main() {
	setup();

	int n;
	input(n);

	vector<pair<int, int>> a(n);
	range(i, 0, n) {
		input(a[i].first, a[i].second);
	}
	sort(a.begin(), a.end());
	reverse(a.begin(), a.end());

	int k = ceil(log2(n));

	vector<int> prefSum(n + 1);
	range(i, 0, n) {
		prefSum[i + 1] = prefSum[i] + a[i].first;
	}

	vector<vector<int>> m(n, vector<int>(k, -1));
	range(i, 0, n) {
		m[i][0] = a[i].second;
	}
	range(j, 1, k) {
		range(i, 0, n) {
			if (i + (1 << j) < n) {
				m[i][j] = min(m[i][j - 1], m[i + (1 << (j - 1))][j - 1]);
			}
		}
	}

	// range(i, 0, n) {
	// 	arrPrint(m[i]);
	// }
	
	int res = a[0].first;
	range(i, 1, n) {
		res = max(res, (i + 1) * a[i].first);
		int l = -1, r = i - 1;
		while (l < r) {
			int p = l + (r - l) / 3;	
			int q = r - (r - l) / 3;
			int x = (p + 1) * a[p].first + (i - p) * a[i].first;
			int y = (q + 1) * a[q].first + (i - q) * a[i].first;

			if (x == y) {
				res = max(res, x);
				l = p + 1;
				r = q - 1;
			}
			else if (x > y) {
				res = max(res, x);
				r = p - 1;
			}
			else {
				res = max(res, y);
				l = q + 1;
			}
		}
	}

	print(res);
}
