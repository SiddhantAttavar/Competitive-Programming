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
	setup(); int tc; input(tc); while (tc--) {
		float px, py;
		input(px, py);

		float ax, ay;
		input(ax, ay);

		float bx, by;
		input(bx, by);

		vector<float> d = {
			sqrt((ax - bx) * (ax - bx) + (ay - by) * (ay - by)) / 2,
			min(
				sqrt((px - ax) * (px - ax) + (py - ay) * (py - ay)),
				sqrt(ax * ax + ay * ay)
			),
			min(
				sqrt((px - bx) * (px - bx) + (py - by) * (py - by)),
				sqrt(bx * bx + by * by)
		   )
		};

		vector<float> e = {
			sqrt(px * px + py * py),
			sqrt(ax * ax + ay * ay),
			sqrt((px - ax) * (px - ax) + (py - ay) * (py - ay)),
		};
		vector<float> f = {
			sqrt(px * px + py * py),
			sqrt(bx * bx + by * by),
			sqrt((px - bx) * (px - bx) + (py - by) * (py - by))
		};
		
		printf("%.10f", min({
			*max_element(d.begin(), d.end()),
			*max_element(e.begin(), e.end()),
			*max_element(f.begin(), f.end())
		}));
	}
}
