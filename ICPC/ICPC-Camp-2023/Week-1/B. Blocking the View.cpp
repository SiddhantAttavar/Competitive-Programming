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
#define int long long

int ax1, ay1, ax2, ay2, bx1, by1, bx2, by2, vx, vy;

bool intersects(int ax, int ay) {
	int l = (by2 - by1) * (bx1 - ax) - (bx2 - bx1) * (by1 - ay);
	int r = (by2 - by1) * vx - (bx2 - bx1) * vy;
	if (r < 0) {
		l = -l;
	}
	return l >= 0;
}

bool intersect2() {
	int l = (ay2 - ay1) * (bx1 - ax1) - (ax2 - ax1) * (by1 - ay1);
	int r = (bx2 - bx1) * (ay2 - ay1) - (by2 - by1) * (ax2 - ax1);
	if (r < 0) {
		l = -l;
		r = -r;
	}
	return l >= 0 and l <= r;
}

int32_t main() {
	setup(); int tc; input(tc); while (tc--) {
		input(ax1, ay1, ax2, ay2, bx1, by1, bx2, by2, vx, vy);

		if (intersect2()) {
			print("Yes");
		}
		else if (intersects(ax1, ay1) or intersects(ax2, ay2)) {
			print("Yes");
		}
		else {
			print("No");
		}
	}
}
