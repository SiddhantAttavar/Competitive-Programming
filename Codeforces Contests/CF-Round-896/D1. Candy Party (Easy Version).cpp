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

	map<int, pair<int, int>> m;
	m[0] = {0, 0};
	range(i, 0, 40) {
		range(j, 0, 40) {
			if (i != j) {
				m[(1ll << i) - (1ll << j)] = {i, j};
			}
		}
	}
	// for (pair<int, pair<int, int>> p : m) {
	// 	print(p.first, p.second.first, p.second.second);
	// }


	int tc; input(tc); while (tc--) {
		int n;
		input(n);

		vector<int> a(n);
		arrPut(a);

		int avg = 0;
		for (int i : a) {
			avg += i;
		}
		if (avg % n != 0) {
			print("No");
			continue;
		}

		avg /= n;

		bool flag = true;
		map<int, int> in, out;
		for (int i : a) {
			int x = i - avg;

			if (!m.count(x)) {
				flag = false;
				break;
			}

			in[m[x].first]++;
			out[m[x].second]++;
		}

		if (!flag or in.size() != out.size()) {
			print("No");
			continue;
		}

		for (pair<int, int> p : in) {
			if (!out.count(p.first) or p.second != out[p.first]) {
				flag = false;
				break;
			}
		}

		print(flag ? "Yes" : "No");
	}
}
