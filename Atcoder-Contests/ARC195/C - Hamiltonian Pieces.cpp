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

vector<pair<pair<int, int>, bool>> solve(int r, int b) {
	vector<pair<pair<int, int>, bool>> res;
	if (b == 0) {
		rep(i, 0, r / 2) {
			res.push_back({{i + 1, 1}, true});
		}
		rep(i, 0, r / 2) {
			res.push_back({{r / 2 - i, 2}, true});
		}
		return res;
	}
	if (r == 0) {
		rep(i, 0, b / 2) {
			res.push_back({{i + 2, i + 1}, false});
		}
		rep(i, 0, b / 2) {
			res.push_back({{b / 2 - i, b / 2 - i + 1}, false});
		}
		return res;
	}

	if (r % 2 == 1) {
		return {};
	}

	if (r == 1) {
		if (b % 2 == 1) {
			return {};
		}
		res.push_back({{1, 1}, true});
		for (int i = 0, x = 1, y = 2; i < b / 2; i++, x--, y++) {
			res.push_back({{x, y}, false});
		}
		for (int i = 0, x = res.back().first.first - 1, y = res.back().first.second - 1; i < b / 2; i++, x++, y--) {
			res.push_back({{x, y}, false});
		}
		return res;
	}

	int k = r % 2 == 0 ? r - 1 : r - 2;
	k /= 2;
	res.push_back({{2, k + 2}, false});
	for (int i = k + 1; i >= 1; i--) {
		res.push_back({{1, i}, true});
	}
	for (int i = 1; i <= k; i++) {
		res.push_back({{2, i}, true});
	}

	if (b == 1) {
		if (r % 2 == 0) {
			return {};
		}

		res.push_back({{2, k + 1}, true});
		res.push_back({{3, k + 1}, true});
		return res;
	}

	res.push_back({{2, k + 1}, false});
	res.push_back({{3, k + 2}, true});
	b -= 2;

	if (r % 2 == 1) {
		res.push_back({{4, k + 2}, true});
		if (b % 2 == 1) {
			res.push_back({{4, k + 1}, false});
			b--;
		}
		res.push_back({{5, k + 2}, false});
		res.push_back({{4, k + 3}, false});
		b -= 2;
	}
	else {
		if (b % 2 == 1) {
			res.push_back({{3, k + 1}, false});
			b--;
		}

		res.push_back({{4, k + 2}, false});
		res.push_back({{3, k + 3}, false});
		b -= 2;

	}

	for (int i = 0, x = res.back().first.first - 1, y = res.back().first.second + 1; i < b / 2; i++, x--, y++) {
		res.push_back({{x, y}, false});
	}
	for (int i = 0, x = res.back().first.first - 1, y = res.back().first.second - 1; i < b / 2; i++, x++, y--) {
		res.push_back({{x, y}, false});
	}
	return res;
}

bool check(vector<pair<pair<int, int>, bool>> &res) {
	rep(i, 0, res.size()) {
		pair<int, int> p = res[(i + 1) % res.size()].first;
		int x, y, a, b;
		tie(x, y) = p;
		tie(a, b) = res[i].first;
		if (res[i].second) {
			if (!(x == a and abs(b - y) == 1 or y == b and abs(x - a) == 1)) {
				return false;
			}
		}
		else {
			if (abs(x - a) != 1 or abs(b - y) != 1) {
				return false;
			}
		}
	}
	return true;
}

int32_t main() {
	setup(); int tc; input(tc); while (tc--) {
		int r, b;
		input(r, b);

		vector<pair<pair<int, int>, bool>> res = solve(r, b);
		if (res.empty()) {
			print("No");
			continue;
		}

		int x = 1e9, y = 1e9;
		for (pair<pair<int, int>, bool> p : res) {
			x = min(x, p.first.first);
			y = min(y, p.first.second);
		}
		for (pair<pair<int, int>, bool> &p : res) {
			p.first.first -= x - 1;
			p.first.second -= y - 1;
		}

		print("Yes");
		for (pair<pair<int, int>, bool> p : res) {
			if (p.second) {
				print('R', p.first.first, p.first.second);
			}
			else {
				print('B', p.first.first, p.first.second);
			}
		}
		cout.flush();

		assert(check(res));
	}
}
