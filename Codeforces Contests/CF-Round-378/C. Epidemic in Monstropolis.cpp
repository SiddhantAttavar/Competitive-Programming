#include <algorithm>
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
#define rep(it, start, end) for (auto it = start; it < end; it++)
#define arrput(var) for (auto &inVar : var) {cin >> inVar;}
#define arrprint(var) for (auto outVar : var) {cout << outVar << ' ';} cout << '\n'
#define setup() ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> 
const int MOD = (int) 1e9 + 7; //998244353;

bool check(vector<int> &a, vector<int> &b, vector<pair<int, char>> &res) {
	for (pair<int, char> p : res) {
		if (p.second == 'L') {
			if (p.first == 0) {
				return false;
			}
			if (a[p.first] < a[p.first - 1]) {
				return false;
			}
			a[p.first] += a[p.first - 1];
			a.erase(a.begin() + p.first - 1);
		}
		else {
			if (p.first == a.size() - 1) {
				return false;
			}
			if (a[p.first] < a[p.first + 1]) {
				return false;
			}
			a[p.first] += a[p.first + 1];
			a.erase(a.begin() + p.first + 1);
		}
	}
	return a == b;
}

int32_t main() {
	setup();

	int n;
	input(n);

	vector<int> a(n);
	arrput(a);

	int m;
	input(m);

	vector<int> b(m);
	arrput(b);

	vector<int> v = {-1};
	int l = 0;

	for (int i : b) {
		int x = a[l];
		int r = l;
		while (r < n - 1 and x + a[r + 1] <= i) {
			r++;
			x += a[r];
		}

		if (x != i) {
			print("NO");
			return 0;
		}
		v.push_back(r);
		l = r + 1;
	}

	if (l != n) {
		print("NO");
		return 0;
	}

	vector<pair<int, char>> res;
	for (int i = v.size() - 1; i > 0; i--) {
		int l = v[i - 1] + 1, r = v[i];
		// print(l, r);
		// cout.flush();

		if (l == r) {
			continue;
		}

		int k = max_element(a.begin() + l, a.begin() + r + 1) - a.begin();
		if (k == l) {
			while (k <= r and a[k] == a[l]) {
				k++;
			}

			if (k > r) {
				print("NO");
				return 0;
			}

			k--;
			rep(j, k, r) {
				res.push_back({k, 'R'});
			}
			while (k > l) {
				res.push_back({k, 'L'});
				k--;
			}
			continue;
		}

		while (k > l) {
			res.push_back({k, 'L'});
			k--;
			r--;
		}
		while (r > l) {
			res.push_back({l, 'R'});
			r--;
		}
	}

	print("YES");
	for (pair<int, char> p : res) {
		print(p.first + 1, p.second);
	}
	cout.flush();
}
