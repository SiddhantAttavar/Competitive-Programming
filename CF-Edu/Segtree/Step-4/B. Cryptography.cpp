#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace std;
using namespace __gnu_pbds; 
template<typename T> inline void input(T& inVar) {cin >> inVar;}
template<typename T, typename... S> inline void input(T& inVar, S&... args) {cin >> inVar; input(args ...);}
template<typename T> inline void print(T outVar) {cout << outVar << '\n';}
template<typename T, typename... S> inline void print(T outVar, S... args) {cout << outVar << ' '; print(args ...);}
#define range(it, start, end) for (auto it = start; it < end; it++)
#define arrPut(var) for (auto &inVar : var) {cin >> inVar;}
#define arrPrint(var) for (auto outVar : var) {cout << outVar << ' ';} cout << '\n'
#define setup() ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define int long long
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> 

vector<int> mul(vector<int> a, vector<int> b, int r) {
	return vector<int>({
		(a[0] * b[0] + a[1] * b[2]) % r,
		(a[0] * b[1] + a[1] * b[3]) % r,
		(a[2] * b[0] + a[3] * b[2]) % r,
		(a[2] * b[1] + a[3] * b[3]) % r
	});
};

int32_t main() {
	setup();

	int k, n, m;
	input(k, n, m);

	int h = log2(n) + 1;

	vector<vector<vector<int>>> a(n, vector<vector<int>>(h, vector<int>(4)));
	range(i, 0, n) {
		input(a[i][0][0], a[i][0][1], a[i][0][2], a[i][0][3]);

		range(j, 1, h) {
			if (i + 1 < (1 << j)) {
				break;
			}

			a[i][j] = mul(a[i - (1 << (j - 1))][j - 1], a[i][j - 1], k);
		}
	}

	while (m--) {
		int l, r;
		input(l, r);

		l--;
		r--;

		vector<int> res = {1, 0, 0, 1};
		for (int j = h - 1; j >= 0; j--) {
			if (r - (1 << j) >= l - 1) {
				res = mul(a[r][j], res, k);
				r -= 1 << j;
			}
		}

		print(res[0], res[1]);
		print(res[2], res[3]);
		print("");
	}
}
