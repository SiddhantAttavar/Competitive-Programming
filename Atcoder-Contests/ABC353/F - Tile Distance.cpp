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

	int k;
	input(k);

	int a, b;
	input(a, b);

	int x, y;
	input(x, y);

	if (k < 1000) {
		deque<pair<int, pair<int, int>>> dq;
		dq.push_back({0, {a, b}});
		set<pair<int, int>> vis;
		while (!dq.empty()) {
			int z = dq.front().first, a, b;
			tie(a, b) = dq.front().second;
			dq.pop_front();

			if (a == x and b == y) {
				print(z);
				return 0;
			}

			if (z > 1000) {
				break;
			}

			vector<pair<int, int>> n = {
				{a - 1, b},
				{a + 1, b},
				{a, b - 1},
				{a, b + 1},
			};
			for (pair<int, int> v : n) {
				int p, q;
				tie(p, q) = v;
				if (vis.count({p, q})) {
					continue;
				}
				vis.insert({p, q});
				if ((a / k + b / k) % 2 == 0 or (p / k + q / k) % 2 == 0) {
					dq.push_back({z + 1, {p, q}});
				}
				else {
					dq.push_front({z, {p, q}});
				}
			}
		}
	}

	vector<pair<pair<int, int>, int>> v, w;
	if ((a / k + b / k) % 2 == 0) {
		int p = a % k, q = b % k;
		v.push_back({{a / k - 1, b / k}, p + 1});
		v.push_back({{a / k + 1, b / k}, k - p});
		v.push_back({{a / k, b / k - 1}, q + 1});
		v.push_back({{a / k, b / k + 1}, k - q});
	}
	else {
		v = {{{a / k, b / k}, 0}};
	}


	if ((x / k + y / k) % 2 == 0) {
		int p = x % k, q = y % k;
		w.push_back({{x / k - 1, y / k}, p + 1});
		w.push_back({{x / k + 1, y / k}, k - p});
		w.push_back({{x / k, y / k - 1}, q + 1});
		w.push_back({{x / k, y / k + 1}, k - q});
	}
	else {
		w = {{{x / k, y / k}, 0}};
	}

	int res = 1e18;
	for (pair<pair<int, int>, int> i : v) {
		for (pair<pair<int, int>, int> j : w) {
			int p, q, r, s;
			tie(p, q) = i.first;
			tie(r, s) = j.first;
			// print(p, q, r, s, i.second, j.second);
			res = min(res, i.second + j.second + (abs(p - q - r + s) + abs(p + q - r - s)));
		}
	}
	print(res);
}
