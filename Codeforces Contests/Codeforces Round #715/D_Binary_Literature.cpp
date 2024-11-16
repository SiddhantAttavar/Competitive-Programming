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

string merge(string a, string b, char x, char y) {
	int i = 0, j = 0;
	string res;
	while (i < a.size() and j < b.size()) {
		int p = 0, q = 0;
		while (i < a.size() and a[i] == x) {
			p++;
			i++;
		}
		while (j < b.size() and b[j] == x) {
			q++;
			j++;
		}
		res += string(max(p, q), x);
		if (i < a.size() or j < b.size()) {
			res += y;
		}
		i++;
		j++;
	}
	while (i < a.size()) {
		res += a[i];
		i++;
	}
	while (j < b.size()) {
		res += b[j];
		j++;
	}
	return res;
}

int32_t main() {
	setup(); int tc; input(tc); while (tc--) {
		int n;
		input(n);

		vector<string> a(3);
		arrPut(a);
		sort(a.begin(), a.end());

		do {
			string s = merge(a[0], a[1], '0', '1');
			if (s.size() <= 3 * n) {
				print(s);
				break;
			}
			s = merge(a[0], a[1], '1', '0');
			if (s.size() <= 3 * n) {
				print(s);
				break;
			}
		} while (next_permutation(a.begin(), a.end()));
	}
}
