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
	// setup();
	int tc; input(tc); while (tc--) {
		int n;
		input(n);

		int sx, sy;
		input(sx, sy);

		vector<pair<int, int>> v(n);
		bool b = (sx + sy) % 2;
		range(i, 0, n) {
			input(v[i].first, v[i].second);
		}

		vector<set<int>> a(2);
		range(i, 0, n) {
			a[(v[i].first + v[i].second) % 2].insert(i);
		}

		if (a[!b].size() > a[b].size()) {
			print("Second");
			cout.flush();

			bool l = (sx + sy) % 2;

			while (!a[0].empty() or !a[1].empty()) {
				// arrPrint(a[0]);
				// arrPrint(a[1]);
				int i;
				input(i);
				i--;
				if (i == -1) {
					return 0;
				}
				if (a[0].count(i)) {
					a[0].erase(i);
				}
				else {
					l = !l;
					a[1].erase(i);
				}

				if (a[0].empty() and a[1].empty()) {
					break;
				}
				// arrPrint(a[0]);
				// arrPrint(a[1]);

				if (a[b].empty()) {
					print(*a[!b].begin() + 1);
					cout.flush();
					a[!b].erase(a[!b].begin());
				}
				else {
					print(*a[b].begin() + 1);
					cout.flush();
					a[b].erase(a[b].begin());
				}
			}
		}
		else {
			print("First");
			bool l = (sx + sy) % 2;

			while (!a[0].empty() or !a[1].empty()) {
				if (a[!b].empty()) {
					print(*a[b].begin() + 1);
					cout.flush();
					a[b].erase(a[b].begin());
				}
				else {
					print(*a[!b].begin() + 1);
					cout.flush();
					a[!b].erase(a[!b].begin());
				}

				if (a[0].empty() and a[1].empty()) {
					break;
				}

				int i;
				input(i);
				i--;
				if (i == -1) {
					return 0;
				}
				if (a[0].count(i)) {
					a[0].erase(i);
				}
				else {
					l = !l;
					a[1].erase(i);
				}
			}
		}
	}
}
