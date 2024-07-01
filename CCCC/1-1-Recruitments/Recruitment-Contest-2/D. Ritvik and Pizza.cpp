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

// https://cp-algorithms.com/algebra/linear-diophantine-equation.html#find-the-solution-with-minimum-value-of-x-y
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
    if (g == 0 or c % g > 0) {
        return false;
    }

    x0 *= c / g;
    y0 *= c / g;
    return true;
}

void shift_solution(int & x, int & y, int a, int b, int cnt) {
    x += cnt * b;
    y -= cnt * a;
}

int solve(int a, int b, int c) {
    int x, y, g;
    if (!find_any_solution(a, b, c, x, y, g)) {
        return -1;
    }
    a /= g;
    b /= g;

    shift_solution(x, y, a, b, -x / b);
    if (x < 0) {
        shift_solution(x, y, a, b, 1);
    }
    if (x < 0 or y < 0) {
        return -1;
    }

	return x + y;
}

int32_t main() {
	setup(); int tc; input(tc); while (tc--) {
		int s, x, y;
		input(s, x, y);

        if (s == 0 and x == 0 and y == 0) {
            print(0);
            continue;
        }

		if (x > y) {
			swap(x, y);
		}

		print(solve(x, y, s));
	}
}
