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

	int n;
	input(n);

	vector<double> x(n);
	arrPut(x);

	double m = *min_element(x.begin(), x.end());
	range(i, 0, n) {
		x[i] /= m;
	}

	int y = 0;
	double min = 1e9;
	range(a, 1, 10001) {
		double curr = 0;
		range(i, 0, n) {
			double c = x[i] * a;
			double d = round(c);
			curr += abs(d - c);
		}

		if (curr < min) {
			min = curr;
			y = a;
		}
	}

	vector<int> r(n);
	range(i, 0, n) {
		r[i] = (int) round((double) y * x[i]);
	}

	int g = r[0];
	range(i, 1, n) {
		g = gcd(g, r[i]);
	}
	range(i, 0, n) {
		r[i] /= g;
	}

	for (int i : r) {
		print(i);
	}
}
