#include <bits/stdc++.h>
using namespace std;
template<typename T> inline void input(T& x) {cin >> x;}
template<typename T, typename... S> inline void input(T& x, S&... y) {cin >> x; input(y ...);}
template<typename T> inline void print(T x) {cout << x << '\n';}
template<typename T, typename... S> inline void print(T x, S... y) {cout << x << ' '; print(y ...);}
#define range(i, j, n) for (int i = j; i < n; i++)
#define arrPut(x) for (auto &i : x) {cin >> i;}
#define arrPrint(x) for (auto i : x) {cout << i << ' ';} cout << '\n'
#define setup() ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define int long long

vector<pair<int, int>> a;

int32_t main() {
	setup();

	int n, k;
	input(n, k);
	
	a.resize(n);
	range(i, 0, n) {
		input(a[i].first, a[i].second);
	}
	
	vector<int> ind1, ind2;
	range(i, 0, n) {
		if (a[i].second != -1) {
			ind2.push_back(i);
		}
		ind1.push_back(i);
	}
	sort(ind1.begin(), ind1.end(), [](int x, int y) {
		return a[x].first < a[y].first;
	});
	sort(ind2.begin(), ind2.end(), [](int x, int y) {
		return a[x].second < a[y].second;
	});
	
	set<int> done;
	double res = 1e18;
	range(j, 0, (1 << n)) {
		double curr = 0, c = 1;
		bool flag = true;
		int l = 0, r = 0;
		int q = 0;
		range(u, 0, n) {
			if (j & (1 << u)) {
				if (r == ind2.size()) {
					flag = false;
					break;
				}

				int x;
				int i = ind2[r];
				if (done.count(i)) {
					x = a[i].second - a[i].first;
				}
				else {
					x = a[i].second;
					q++;
				}

				curr += x / c;
				c++;
				r++;
			}
			else {
				int i = ind1[l];
				curr += a[i].first / c;
				q++;
				l++;
				done.insert(i);
			}
			if (q >= k) {
				break;
			}
		}
		if (flag) {
			res = min(res, curr);
		}
	}

	/**
	sort(a.begin(), a.end(), [](pair<int, int> x, pair<int, int> y) {
		if (x.second == -1) {
			if (y.second == -1) {
				return x.first < y.first;
			}
			return false;
		}
		if (y.second == -1) {
			return true;
		}
		return x.first < y.first;
	});

	double res = 0;
	double c = 1;
	for (pair<int, int> p : a) {
		res += p.first / c;
		if (p.second != -1) {
			res += p.second
			c++;
		}
	}
	
	return 0;

	vector<double> x, y;
	range(i, 0, n) {
		int a, b;
		input(a, b);
		y.push_back(a);
		if (b != -1) {
			x.push_back(b - a);
		}
	}
	sort(x.begin(), x.end());
	sort(y.begin(), y.end());

	vector<vector<double>> dp(k + 1, vector<double>(k + 1));
	range(i, 1, k + 1) {
		range(j, 0, i + 1) {
			// cout << i << ' ' << j << ' ' << x.size() << ' ' << y.size() << endl;
			dp[i][j] = 1e18;
			if (i - j - 1 >= 0 and i - j - 1 < y.size()) {
				dp[i][j] = min(dp[i][j], dp[i - 1][j] + y[i - j - 1] / (j + 1));
			}
			if (j > 0 and j - 1 < x.size()) {
				dp[i][j] = min(dp[i][j], dp[i][j - 1] + x[j - 1] / j);
			}
		}
	}
	
	range(i, 1, k + 1) {
		arrPrint(dp[i]);
	}

	double res = 1e18;
	range(j, 0, min((int) x.size(), k) + 1) {
		if (dp[k][j] == 1e18) {
			continue;
		}
		res = min(res, dp[k][j]);
	}
	print(res);
	**/
}
