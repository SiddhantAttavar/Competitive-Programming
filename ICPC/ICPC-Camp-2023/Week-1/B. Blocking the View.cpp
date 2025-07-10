#include <bits/stdc++.h>
#include <cmath>
using namespace std;
template<typename T> inline void input(T& inVar) {cin >> inVar;}
template<typename T, typename... S> inline void input(T& inVar, S&... args) {cin >> inVar; input(args ...);}
template<typename T> inline void print(T outVar) {cout << outVar << '\n';}
template<typename T, typename... S> inline void print(T outVar, S... args) {cout << outVar << ' '; print(args ...);}
#define range(it, start, end) for (auto it = start; it < end; it++)
#define arrPut(var) for (auto &inVar : var) {cin >> inVar;}
#define arrPrint(var) for (auto outVar : var) {cout << outVar << ' ';} cout << '\n'
#define setup() ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define int double

int cross(complex<int> a, complex<int> b) {
	return a.real() * b.imag() - a.imag() * b.real();
}

int dot(complex<int> a, complex<int> b) {
	return a.real() * b.real() + a.imag() * b.imag();
}

int sideOf(complex<int> a, complex<int> b, complex<int> c) {
	int x = cross(c - a, b - a);
	if (x == 0) {
		return 0;
	}
	return x > 0 ? 1 : -1;
}

bool onSegment(complex<int> a, complex<int> b, complex<int> c) {
	return sideOf(a, b, c) == 0 and dot(c - a, b - a) >= 0 and dot(c - b, a - b) >= 0;
}

bool segInter(complex<int> a1, complex<int> a2, complex<int> b1, complex<int> b2) {
	// print(a1, a2, b1, b2);
	if (sideOf(a1, a2, b1) == 0) {
		// print("debug");
		return onSegment(a1, a2, b1) or onSegment(a1, a2, b2) or onSegment(b1, b2, a1);
	}

	int w = sideOf(a1, a2, b1);
	int x = sideOf(a1, a2, b2);
	int y = sideOf(b1, b2, a1);
	int z = sideOf(b1, b2, a2);
	// print(w, x, y, z);

	if (w != x and y != z) {
		return true;
	}

	return (
		w == 0 and onSegment(a1, a2, b1) or
		x == 0 and onSegment(a1, a2, b2) or
		y == 0 and onSegment(b1, b2, a1) or
		z == 0 and onSegment(b1, b2, a2)
	);
}

int32_t main() {
	const int K = 1e7;
	setup(); long long tc; input(tc); while (tc--) {
		long long ax1, ay1, ax2, ay2, bx1, by1, bx2, by2, vx, vy;
		input(ax1, ay1, ax2, ay2, bx1, by1, bx2, by2, vx, vy);

		complex<int> a1(ax1, ay1), a2(ax2, ay2), b1(bx1, by1), b2(bx2, by2), v(vx, vy);
		complex<int> c = complex<int>((a1.real() + a2.real()) / 2, (a1.imag() + a2.imag()) / 2) + v;

		vector<int> x = {sideOf(a1, a2, c), sideOf(a1, a1 + v, c), sideOf(a2, a2 + v, c)};
		vector<int> y = {sideOf(a1, a2, b1), sideOf(a1, a1 + v, b1), sideOf(a2, a2 + v, b1)};
		vector<int> z = {sideOf(a1, a2, b2), sideOf(a1, a1 + v, b2), sideOf(a2, a2 + v, b2)};

		if (segInter(a1, a2, b1, b2)) {
			print("Yes");
			continue;
		}

		if (sideOf(a1, a2, c) == 0) {
			if (segInter(b1, b2, a1, a1 + v * K) or segInter(b1, b2, a2, a2 + v * K)) {
				print("Yes");
			}
			else {
				print("No");
			}
			continue;
		}

		if (x == y or x == z) {
			print("Yes");
			continue;
		}

		if (segInter(b1, b2, a1, a1 + v * K) or segInter(b1, b2, a2, a2 + v * K)) {
			print("Yes");
		}
		else {
			print("No");
		}
	}
}
