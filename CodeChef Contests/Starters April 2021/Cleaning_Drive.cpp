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
typedef long long ll;

int n, m;
vector<pair<int, int>> a;

bool possible(int k) {
	int curr = 0;
	range(i, 0, m) {
		while (i < m && curr < a[i].first - 1) {
			i++;
		}
		if (i < m) {
			curr = min(curr + k, a[i].second);
		}
	}
	return curr >= n;
}

int main() {
	setup(); int tc; input(tc); while (tc--) {
		input(n, m);
		n--;
		
		a.resize(m);
		range(i, 0, m) {
			input(a[i].first, a[i].second);
			a[i].second--;
		}
		sort(a.begin(), a.end(), [](pair<int, int> a, pair<int, int> b) {
			if (a.second == b.second) {
				return a.first < b.first;
			}
			return a.second < b.second;
		});

		int low = 0, high = n + 1, res = -1;
		while (low <= high) {
			int mid = (low + high) / 2;
			if (possible(mid)) {
				res = mid;	
				high = mid - 1;
			}
			else {
				low = mid + 1;
			}
		}

		print(res);
	}
}