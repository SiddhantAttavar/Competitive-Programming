#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace std;
using namespace __gnu_pbds; 
template<typename T> inline void input(T& inVar) {cin >> inVar;}
template<typename T, typename... S> inline void input(T& inVar, S&... args) {cin >> inVar; input(args ...);}
template<typename T> inline void print(T outVar) {cout << outVar << '\n';}
template<typename T, typename... S> inline void print(T outVar, S... args) {cout << outVar << ' '; print(args ...);}
#define int __int128_t
#define range(it, start, end) for (auto it = start; it < end; it++)
#define arrPut(var) for (auto &inVar : var) {cin >> inVar;}
#define arrPrint(var) for (auto outVar : var) {cout << outVar << ' ';} cout << '\n'
#define setup() ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> 
const int MOD = (int) 1e9 + 7; //998244353

int abs_int(int a) {
    if (a < 0) {
        return -a;
    }
    return a;
}

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
    g = gcd(abs_int(a), abs_int(b), x0, y0);
    if (c % g) {
        return false;
    }

    x0 *= c / g;
    y0 *= c / g;
    if (a < 0) x0 = -x0;
    if (b < 0) y0 = -y0;
    return true;
}

void shift_solution(int & x, int & y, int a, int b, int cnt) {
    x += cnt * b;
    y -= cnt * a;
}

int find_all_solutions(int a, int b, int c, int minx, int maxx, int miny, int maxy) {
    int x, y, g;
    if (!find_any_solution(a, b, c, x, y, g))
        return 1e18;
    a /= g;
    b /= g;

    int sign_a = a > 0 ? +1 : -1;
    int sign_b = b > 0 ? +1 : -1;

    shift_solution(x, y, a, b, (minx - x) / b);
    if (x < minx)
        shift_solution(x, y, a, b, sign_b);
    if (x > maxx)
        return 1e18;
    int lx1 = x;

    shift_solution(x, y, a, b, (maxx - x) / b);
    if (x > maxx)
        shift_solution(x, y, a, b, -sign_b);
    int rx1 = x;

    shift_solution(x, y, a, b, -(miny - y) / a);
    if (y < miny)
        shift_solution(x, y, a, b, -sign_a);
    if (y > maxy)
        return 1e18;
    int lx2 = x;

    shift_solution(x, y, a, b, -(maxy - y) / a);
    if (y > maxy)
        shift_solution(x, y, a, b, sign_a);
    int rx2 = x;

    if (lx2 > rx2)
        swap(lx2, rx2);
    int lx = max(lx1, lx2);
    int rx = min(rx1, rx2);

    if (lx > rx)
        return 1e18;
	return lx;
}

bool check(vector<long long> &res, vector<long long> &d, int x) {
    cout.flush();
	range(i, 0, res.size()) {
		x -= res[i] * d[i];
		if (abs_int(res[i]) > 1e9) {
			return false;
		}
	}
	return x == 0;
}

int32_t main() {
	setup();

	long long x, y;
	input(x, y);

	long long n;
	input(n);
	vector<long long> d(n);
	arrPut(d);

	vector<long long> pref(n, d[0]);
	range(i, 1, n) {
        pref[i] = std::gcd(pref[i - 1], d[i]);
	}

	int z = y - x;
	vector<long long> res(n);
    vector<int> s(n);
	for (int i = n - 1; i > 0; i--) {
        s[i] = z;
		int a = find_all_solutions(pref[i - 1], d[i], z, -1e9, 1e9, -1e9, 1e9);
		assert((z - a * pref[i - 1]) % d[i] == 0);
		int b = (z - a * pref[i - 1]) / d[i];
		assert(a * pref[i - 1] + b * d[i] == z);
        assert(abs_int(a) <= 1e9);
        assert(abs_int(b) <= 1e9);

		res[i] = b;
		z = a * pref[i - 1];
	}
    assert(z <= 1e9);
    s[0] = z;
	res[0] = z / d[0];

    int c = res[0] * d[0];
    assert(c == s[0]);
    range(i, 1, n) {
        c += res[i] * d[i];
        assert(c == s[i]);
    }

	for (long long i : res) {
		print(max(0ll, i));
	}
	for (long long i : res) {
		print(max(0ll, -i));
	}
	assert(check(res, d, y - x));
}
