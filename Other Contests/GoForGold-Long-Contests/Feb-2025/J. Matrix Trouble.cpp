#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace std;
using namespace __gnu_pbds; 
template<typename T> inline void input(T& inVar) {cin >> inVar;}
template<typename T, typename... S> inline void input(T& inVar, S&... args) {cin >> inVar; input(args ...);}
template<typename T> inline void print(T outVar) {cout << outVar << '\n';}
template<typename T, typename... S> inline void print(T outVar, S... args) {cout << outVar << ' '; print(args ...);}
#define int long long
#define range(it, start, end) for (auto it = start; it < end; it++)
#define arrput(var) for (auto &inVar : var) {cin >> inVar;}
#define arrprint(var) for (auto outVar : var) {cout << outVar << ' ';} cout << '\n'
#define setup() ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> 
const int MOD = (int) 1e9 + 7; //998244353

vector<vector<vector<vector<int>>>> build_st(vector<vector<int>> &a) {
    int n = a.size(), m = a[0].size();
    vector<vector<vector<vector<int>>>> x(n, vector<vector<vector<int>>>(m, vector<vector<int>>(20, vector<int>(20, 1e9))));
    range(i, 0, n) {
        range(j, 0, m) {
            x[i][j][0][0] = a[i][j];
        }
    }

    range(l, 1, 20) {
        range(i, 0, n) {
            range(j, 0, m - (1 << l) + 1) {
				x[i][j][0][l] = min(x[i][j][0][l - 1], x[i][j + (1 << (l - 1))][0][l - 1]);
            }
        }
    }

    range(k, 1, 20) {
		range(l, 1, 20) {
			range(i, 0, n - (1 << k) + 1) {
				range(j, 0, m - (1 << l) + 1) {
					x[i][j][k][l] = min({
						x[i][j][k - 1][l - 1],
						x[i][j + (1 << (l - 1))][k - 1][l - 1],
						x[i + (1 << (k - 1))][j][k - 1][l - 1],
						x[i + (1 << (k - 1))][j + (1 << (l - 1))][k - 1][l - 1]
					});
				}
			}
		}
    }
	return x;
}

int32_t main() {
    setup();

    int n, m;
    input(n, m);

    vector<vector<int>> a(n, vector<int>(m));
    range(i, 0, n) {
        arrput(a[i]);
    }

    vector<vector<int>> b(n, vector<int>(m, m));
    range(i, 0, n) {
        map<int, int> s;
        for (int j = m - 1; j >= 0; j--) {
            if (s.count(a[i][j])) {
                b[i][j] = s[a[i][j]];
            }
            s[a[i][j]] = j;
        }
    }

    vector<vector<int>> c(n, vector<int>(m, n));
    range(j, 0, m) {
        map<int, int> s;
        for (int i = n - 1; i >= 0; i--) {
            if (s.count(a[i][j])) {
                c[i][j] = s[a[i][j]];
            }
            s[a[i][j]] = i;
        }
    }
	range(i, 0, n) {
		arrprint(b[i]);
	}
	range(i, 0, n) {
		arrprint(c[i]);
	}

    vector<vector<vector<vector<int>>>> x = build_st(b);
    vector<vector<vector<vector<int>>>> y = build_st(c);

	int q;
	input(q);
	while (q--) {
		int a, b, c, d;
		input(a, b, c, d);

		a--;
		b--;
		c--;
		d--;

		int p = c - a + 1, q = d - b + 1;
		int k = 0, l = 0;
		while (1 << (k + 1) <= p) {
			k++;
		}
		while (1 << (l + 1) <= q) {
			l++;
		}

		int s = min({
			x[a][b][p][q],
			x[c - (1 << k) + 1][b][p][q],
			x[a][d - (1 << l) + 1][p][q],
			x[c - (1 << k) + 1][d - (1 << l) + 1][p][q]
		});
		int t = min({
			y[a][b][p][q],
			y[c - (1 << k) + 1][b][p][q],
			y[a][d - (1 << l) + 1][p][q],
			y[c - (1 << k) + 1][d - (1 << l) + 1][p][q]
		});

		if (s > c and t > d) {
			print("YES");
		}
		else {
			print("NO");
		}
	}
}
