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
const int MOD = (int) 1e9 + 7;

int32_t main() {
	setup();

	int n, m;
	input(n, m);

	set<int> a, b;
	range(i, 0, n) {
		a.insert(i);
		b.insert(i);
	}

	set<int> p, q;
	range(i, 0, m) {
		int x, y;
		input(x, y);

		a.erase(x - 1);
		b.erase(y - 1);

		p.insert(x - 1);
		q.insert(y - 1);
	}

	while (p.size() < m) {
		p.insert(*a.begin());
		a.erase(a.begin());
	}
	while (q.size() < m) {
		q.insert(*b.begin());
		b.erase(b.begin());
	}

	vector<pair<int, int>> res;
	for (int i : p) {
		for (int j : q) {
			res.push_back({i + 1, j + 1});
		}
	}

	vector<int> x(a.begin(), a.end());
	vector<int> y(b.begin(), b.end());

	range(i, 0, n - m) {
		range(j, 0, m) {
			res.push_back({x[i] + 1, y[(i + j) % (n - m)] + 1});
		}
	}

	print(res.size());
	for (pair<int, int> p : res) {
		print(p.first, p.second);
	}
}
