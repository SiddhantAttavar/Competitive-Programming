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

int32_t main() {
	setup();

	int n;
	input(n);

	vector<int> a(n);
	arrput(a);

	stack<int> s;
	vector<int> l(n, 0), r(n, n - 1);
	rep(i, 0, n) {
		while (!s.empty() and a[s.top()] < a[i]) {
			s.pop();
		}
		if (!s.empty()) {
			l[i] = s.top() + 1;
		}
		s.push(i);
	}

	while (!s.empty()) {
		s.pop();
	}
	for (int i = n - 1; i >= 0; i--) {
		while (!s.empty() and a[s.top()] <= a[i]) {
			s.pop();
		}
		if (!s.empty()) {
			r[i] = s.top() - 1;
		}
		s.push(i);
	}

	vector<int> p(n, 0), q(n, n - 1);
	while (!s.empty()) {
		s.pop();
	}
	rep(i, 0, n) {
		while (!s.empty() and a[s.top()] > a[i]) {
			s.pop();
		}
		if (!s.empty()) {
			p[i] = s.top() + 1;
		}
		s.push(i);
	}

	while (!s.empty()) {
		s.pop();
	}
	for (int i = n - 1; i >= 0; i--) {
		while (!s.empty() and a[s.top()] >= a[i]) {
			s.pop();
		}
		if (!s.empty()) {
			q[i] = s.top() - 1;
		}
		s.push(i);
	}

	int res = 0;
	rep(i, 0, n) {
		res += a[i] * ((r[i] - i + 1) * (i - l[i] + 1) - (q[i] - i + 1) * (i - p[i] + 1));
	}
	print(res);
}
