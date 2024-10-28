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
#define arrPut(var) for (auto &inVar : var) {cin >> inVar;}
#define arrPrint(var) for (auto outVar : var) {cout << outVar << ' ';} cout << '\n'
#define setup() ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> 
const int MOD = (int) 1e9 + 7; //998244353

int pref(int x, vector<int> &v, vector<int> &p, vector<int> &s, vector<int> &t) {
	if (x == 0) {
		return 0;
	}

	x--;
	int i = upper_bound(v.begin(), v.end(), x) - v.begin() - 1;
	int j = x - v[i];

	return t[i] - (j + 1) * p[i] + s[i + j + 1] - s[i];
}

int32_t main() {
	setup();
	int n;
	input(n);

	vector<int> a(n);
	arrPut(a);

	vector<int> p(n + 1, 0);
	range(i, 0, n) {
		p[i + 1] = p[i] + a[i];
	}

	vector<int> s(n + 1, 0);
	range(i, 0, n) {
		s[i + 1] = s[i] + p[i + 1];
	}

	vector<int> t(n + 1, 0);
	t[1] = s[n];
	range(i, 1, n)  {
		t[i + 1] = t[i] - a[i - 1] * (n - i + 1);
	}
	range(i, 0, n) {
		t[i + 1] += t[i];
	}

	vector<int> v(n, 0);
	range(i, 1, n) {
		v[i] = v[i - 1] + n - i + 1;
	}

	int q;
	input(q);
	while (q--) {
		int l, r;
		input(l, r);

		print(pref(r, v, p, s, t) - pref(l - 1, v, p, s, t));
	}
}
