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

	int x, p, q;
	input(x, p, q);

	int n, m;
	input(n);
	vector<pair<int, int>> v(n);
	range(i, 0, n) {
		input(v[i].first, v[i].second);
	}

	input(m);
	pair<int, pair<int, int>> res = {0, {-1, -1}};
	range(i, 0, m) {
		int o, a, b;
		input(o, a, b);
		if (o == 1) {
			if (x >= a and (p + b) >= res.first) {
				res = {p + b, {i + 1, -1}};
			}
		}
		else {
			if (x >= a and (q + b) >= res.first) {
				res = {q + b, {i + 1, -1}};
			}

			range(j, 0, n) {
				if ((2 * min(x, v[j].first)) >= a and (q + b + v[j].second) >= res.first) {
					res = {q + b + v[j].second, {i + 1, j + 1}};
				}
			}
		}
	}

	if (res.second.first == -1) {
		print("Forget about apartments. Live in the dormitory.");
	}
	else if (res.second.second == -1) {
		printf("You should rent the apartment #%lld alone.\n", res.second.first);
	}
	else {
		printf("You should rent the apartment #%lld with the friend #%lld.\n", res.second.first, res.second.second);
	}
}
