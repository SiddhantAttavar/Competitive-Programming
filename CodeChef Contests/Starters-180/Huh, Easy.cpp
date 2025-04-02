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
	setup(); int tc; input(tc); while (tc--) {
		int n, k;
		input(n, k);

		if (n == 1 and k == 0) {
			print('A');
			print('B');
			continue;
		}

		string s, t;
		while (n > k and n >= 0) {
			s += 'A';
			t += 'C';
			s += 'B';
			t += 'B';
			n -= 2;
			k--;
		}
		if (!s.empty()) {
			s.pop_back();
			t.pop_back();
			n++;
			k++;
		}

		if (n < 0 or n > k) {
			print(-1);
			continue;
		}

		while (n--) {
			if (s.empty() or (s.back() != 'B' and t.back() != 'B')) {
				s += 'B';
				t += 'B';
			}
			else {
				s += 'A';
				t += 'A';
			}
		}

		print(s);
		print(t);
	}
}
