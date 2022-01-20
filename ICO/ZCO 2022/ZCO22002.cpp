#include <bits/stdc++.h>
using namespace std;
template<typename T> inline void input(T& inVar) {cin >> inVar;}
template<typename T, typename... S> inline void input(T& inVar, S&... args) {cin >> inVar; input(args ...);}
template<typename T> inline void print(T outVar) {cout << outVar << endl;}
template<typename T, typename... S> inline void print(T outVar, S... args) {cout << outVar << ' '; print(args ...);}
#define range(it, start, end) for (int it = start; it < end; it++)
#define arrPut(var) for (auto &inVar : var) {cin >> inVar;}
#define arrPrint(var) for (auto outVar : var) {cout << outVar << ' ';} cout << endl
#define setup() ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define int long long

int32_t main() {
	setup(); int tc; input(tc); while (tc--) {
		int n, m; input(n, m);
		int a[m][n];
		range(i, 0, m) {
			arrPut(a[i]);
		}

		set<int> res;
		range(i, 0, m) {
			res.insert(i);
		}

		range(j, 0, n) {
			map<int, vector<int>> freq;
			range(i, 0, m) {
				if (!freq.count(a[i][j])) {
					freq[a[i][j]] = vector<int>();
				}
				freq[a[i][j]].push_back(i);
			}

			for (pair<int, vector<int>> p : freq) {
				if (p.second.size() != m / 2) {
					for (int i : p.second) {
						res.erase(i);
					}
				}
			}
		}
		
		if (res.size() == 0) {
			print(0);
			print("");
			continue;
		}

		int x = *res.begin();
		vector<int> combinations(m);
		range(i, 0, m) {
			int curr = 0;
			range(j, 0, n) {
				curr += (a[x][j] == a[i][j]) * (1 << j);
			}
			combinations[i] = curr;
		}
		sort(combinations.begin(), combinations.end());
		range(i, 0, m) {
			if (combinations[i] != i) {
				res.clear();
				break;
			}
		}

		print(res.size());
		if (res.size()) {
			arrPrint(res);
		}
	}
}
