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
const int MOD = (int) 1e9 + 7; //998244353

int gcd(int a, int b, int& x, int& y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    int x1, y1;
    int d = gcd(b, a % b, x1, y1);
    x = y1;
    y = x1 - y1 * (a / b);
    return d;
}

bool find_any_solution(int a, int b, int c, int &x0, int &y0, int &g) {
    g = gcd(abs(a), abs(b), x0, y0);
    if (c % g) {
        return false;
    }

    x0 *= c / g;
    y0 *= c / g;
    if (a < 0) x0 = -x0;
    if (b < 0) y0 = -y0;
    return true;
}

int32_t main() {
	setup();

	int x, y;
	input(x, y);

	int n;
	input(n);
	vector<int> d(n);
	arrPut(d);

	vector<int> pref(n, d[0]);
	range(i, 1, n) {
		pref[i] = __gcd(pref[i - 1], d[i]);
	}

	int z = y - x;
	vector<int> res(n);
	for (int i = n - 1; i > 0; i--) {
		int a, b, c;
		find_any_solution(pref[i - 1], d[i], z, a, b, c);
		assert(a * pref[i - 1] + b * d[i] == z);

		while (abs(a) > 1e9) {
			if (abs(a - d[i]) < abs(a)) {
				a = a - d[i];
				b = b + pref[i - 1];
			}
			else {
				a = a + d[i];
				b = b - pref[i - 1];
			}
		}

		while (abs(b) > 1e9) {
			if (abs(b - pref[i - 1]) < abs(b)) {
				a = a + d[i];
				b = b - pref[i - 1];
			}
			else {
				a = a - d[i];
				b = b + pref[i - 1];
			}
		}

		assert(a * pref[i - 1] + b * d[i] == z);

		res[i] = b;
		z = a;
	}
	res[0] = z;

	for (int i : res) {
		print(max(0ll, i));
	}
	for (int i : res) {
		print(max(0ll, -i));
	}
}
