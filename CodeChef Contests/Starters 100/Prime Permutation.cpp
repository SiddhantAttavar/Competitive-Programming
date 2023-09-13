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
	
	int N = (int) 1e5 + 1;
	set<int> primes;
	vector<bool> seive(N, true);
	seive[0] = seive[1] = false;
	range(i, 2, N) {
		if (seive[i]) {
			primes.insert(i);
			for (int j = i + i; j < N; j += i) {
				seive[j] = false;
			}
		}
	}

	int tc; input(tc); while (tc--) {
		int n;
		input(n);

		vector<int> res(n + 1);
		range(i, 0, n / 4) {
			res[4 * i + 1] = 4 * i + 3;
			res[4 * i + 3] = 4 * i + 1;

			res[4 * i + 2] = 4 * i + 4;
			res[4 * i + 4] = 4 * i + 2;
		}

		if (n % 2 == 1 and !primes.count(n)) {
			print(-1);
			continue;
		}

		res[n - 1] = n;
		res.erase(res.begin());
		arrPrint(res);
	}
}
