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

	int N = 1e6;
	vector<int> spf(N + 1);
	range(i, 0, N + 1) {
		spf[i] = i;
	}
	vector<int> v(N + 1, 0);
	vector<int> p(N + 1, 1);
	range(i, 2, N + 1) {
		if (spf[i] == spf[i / spf[i]]) {
			p[i] = p[i / spf[i]];
		}
		else {
			p[i] = i / spf[i];
		}

		if (spf[i] != i) {
			continue;
		}

		for (int j = i; j <= N; j += i) {
			v[j]++;
			if (spf[j] == j) {
				spf[j] = i;
			}
		}
	}

	int n;
	input(n);

	vector<int> a(n);
	arrPut(a);

	vector<int> m(N + 1, 0);
	for (int i : a) {
		vector<int> s;
		vector<int> v = {1};
		while (i != 1) {
			s.push_back(spf[i]);
			vector<int> w;
			for (int j : v) {
				w.push_back(j * spf[i]);
			}
			v.insert(v.end(), w.begin(), w.end());
			i = p[i];
		}

		for (int j : v) {
			m[j]++;
		}
	}

	int res = 0;
	range(i, 1, N + 1) {
		if (v[i] % 2 == 0) {
			res += m[i] * (m[i] - 1) / 2;
		}
		else {
			res -= m[i] * (m[i] - 1) / 2;
		}
	}

	print(res);
}
