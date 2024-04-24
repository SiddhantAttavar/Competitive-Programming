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
	int N = 1e7;
	vector<int> spf(N + 1, 0);
	range(i, 1, N + 1) {
		spf[i] = i;
	}
	range(i, 2, N + 1) {
		if (spf[i] != i) {
			continue;
		}

		for (int j = i; j <= N; j += i) {
			if (spf[j] == j) {
				spf[j] = i;
			}
		}
	}

	setup(); int tc; input(tc); while (tc--) {
		string x, y;
		input(x, y);


		vector<int> a, b;
		sort(x.begin(), x.end());
		do {
			if (x[0] == '0') {
				continue;
			}

			a.push_back(stoi(x));
		} while (next_permutation(x.begin(), x.end()));

		sort(y.begin(), y.end());
		do {
			if (y[0] == '0') {
				continue;
			}

			b.push_back(stoi(y));
		} while (next_permutation(y.begin(), y.end()));

		set<int> p, q;
		for (int i : a) {
			while (i > 1) {
				p.insert(spf[i]);
				i /= spf[i];
			}
		}
		for (int i : b) {
			while (i > 1) {
				q.insert(spf[i]);
				i /= spf[i];
			}
		}

		int res = 1;
		for (int i : p) {
			if (q.count(i)) {
				res = i;
			}
		}
		print(res);
	}
}
