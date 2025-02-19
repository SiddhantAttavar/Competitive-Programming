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

bool solve(string &s, int k, int a, int b) {
    int n = s.size();
    vector<int> p(n + 1, 0);
	p[0] = s[0] == '1';
    range(i, 1, n) {
        p[i] = p[i - 1] + (s[i] == '1');
    }

	if (a == 0 and b == 0) {
		return true;
	}

	if (a == 0) {
		int res = b - p[b - 1];
		range(i, b, n) {
			res = min(res, b - p[i] + p[i - b]);
		}
		return res <= k;
	}

	vector<int> f(n, 1e9);
	f[a - 1] = p[a - 1];
	range(i, a, n) {
		f[i] = min(f[i - 1], p[i] - p[i - a]);
	}

	vector<int> dp(n, 1e9);
	dp[a + b - 1] = f[a - 1] + (b - p[a + b - 1] + p[a - 1]);
	range(i, a + b, n) {
		dp[i] = min(dp[i - 1], f[i - b] + (b - p[i] + p[i - b]));
	}
	return dp[n - 1] <= k;
}

int32_t main() {
    setup(); int tc; input(tc); while (tc--) {
        int n, k;
        input(n, k);

        string s;
        input(s);

		string t(s.begin(), s.end());
		reverse(t.begin(), t.end());

        vector<int> v(n + 1);
		v[0] = n;
		while (v[0] >= 0 and !solve(s, k, 0, v[0]) and !solve(t, k, 0, v[0])) {
			v[0]--;
		}
        range(i, 1, n + 1) {
			v[i] = min(n - i, v[i - 1]);
			while (v[i] >= 0 and !solve(s, k, i, v[i]) and !solve(t, k, i, v[i])) {
				v[i]--;
			}
        }
		// arrprint(v);

		vector<int> res(n, 0);
		range(i, 1, n + 1) {
			range(j, 0, n + 1) {
				if (v[j] >= 0) {
					res[i - 1] = max(res[i - 1], i * j + v[j]);
					// print(i, j, i * j + v[j]);
				}
			}
		}
		arrprint(res);
		// print("");
    }
}
