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
// #define int long long

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
typedef tree<
    int,
    null_type,
    less_equal<int>,
    rb_tree_tag,
    tree_order_statistics_node_update> ordered_set;

int32_t main() {
	setup();
	ordered_set o;
	int n = 0;
	int tc; input(tc); while (tc--) {
		string s;
		input(s);
		if (s == "PUSH") {
			int x;
			input(x);
			o.insert(x);
			n++;
		}
		else {
			if (n & 1) {
				ordered_set::iterator it = o.find_by_order(n / 2);
				o.erase(it);
			}
			else {
				ordered_set::iterator it = o.find_by_order(n / 2 - 1);
				o.erase(it);
			}
			n--;
		}
	}
	arrPrint(o);
}
