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

	int n, m, h;
	input(n, m, h);

	vector<vector<bool>> a(n, vector<bool>(m)), b(n, vector<bool>(h));
	range(i, 0, n) {
		string s;
		input(s);
		range(j, 0, m) {
			a[i][j] = s[j] == '1';
		}
	}
	range(i, 0, n) {
		string s;
		input(s);
		range(j, 0, h) {
			b[i][j] = s[j] == '1';
		}
	}

	vector<vector<vector<int>>> v(n, vector<vector<int>>(m, vector<int>(h, 0)));
	range(i, 0, n) {
		string s;
		input(s);
		range(j, 0, m) {
			if (!a[i][j]) {
				continue;
			}

			range(k, 0, h) {
				v[i][j][k]++;
			}
		}
	}
	range(i, 0, n) {
		string s;
		input(s);
		range(k, 0, h) {
			if (!b[i][k]) {
				continue;
			}

			range(j, 0, m) {
				v[i][j][k]++;
			}
		}
	}

	bool flag = true;
	range(i, 0, n) {
		range(j, 0, m) {
			if (!a[i][j]) {
				continue;
			}

			flag = false;
			range(k, 0, h) {
				if (v[i][j][k] == 2) {
					flag = true;
				}
			}

			if (!flag) {
				break;
			}
		}

		if (!flag) {
			break;
		}

		range(k, 0, h) {
			if (!b[i][k]) {
				continue;
			}

			flag = false;
			range(j, 0, m) {
				if (v[i][j][k] == 2) {
					flag = true;
				}
			}

			if (!flag) {
				break;
			}
		}

		if (!flag) {
			break;
		}
	}

	if (!flag) {
		print(-1);
		return 0;
	}

	vector<vector<int>> kmax;
	range(i, 0, n) {
		range(j, 0, m) {
			range(k, 0, h) {
				if (v[i][j][k] == 2) {
					kmax.push_back({i, j, k});
				}
			}
		}
	}

	print(kmax.size());
	for (vector<int> p : kmax) {
		print(p[0], p[1], p[2]);
	}

	vector<vector<int>> kmin;
	range(i, 0, n) {
		vector<int> x, y;
		range(j, 0, m) {
			if (a[i][j]) {
				x.push_back(j);
			}
		}
		range(k, 0, h) {
			if (b[i][k]) {
				y.push_back(k);
			}
		}

		int l = (int) x.size() - 1, r = (int) y.size() - 1;
		while (l >= 0 and r >= 0) {
			kmin.push_back({i, x[l], y[r]});
			l--;
			r--;
		}

		while (l >= 0) {
			kmin.push_back({i, x[l], y[0]});
			l--;
		}
		while (r >= 0) {
			kmin.push_back({i, x[0], y[r]});
			r--;
		}
	}
	sort(kmin.begin(), kmin.end());

	print(kmin.size());
	for (vector<int> p : kmin) {
		print(p[0], p[1], p[2]);
	}
}
