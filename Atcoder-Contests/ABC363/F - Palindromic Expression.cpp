#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace std;
using namespace __gnu_pbds; 
template<typename T> inline void input(T& inVar) {cin >> inVar;}
template<typename T, typename... S> inline void input(T& inVar, S&... args) {cin >> inVar; input(args ...);}
template<typename T> inline void print(T outVar) {cout << outVar << '\n';}
template<typename T, typename... S> inline void print(T outVar, S... args) {cout << outVar << ' '; print(args ...);}
#define int long long
#define range(it, start, end) for (auto it = start; it < end; it++)
#define arrPut(var) for (auto &inVar : var) {cin >> inVar;}
#define arrPrint(var) for (auto outVar : var) {cout << outVar << ' ';} cout << '\n'
#define setup() ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> 
const int MOD = (int) 1e9 + 7;

int to_int(string s) {
	int x = s[0] - '0';
	range(i, 1, s.size()) {
		x = 10 * x + (s[i] - '0');
	}
	return x;
}

int rev(int x) {
	string s = to_string(x);
	reverse(s.begin(), s.end());
	return to_int(s);
}

int32_t main() {
	setup();

	int N = 1e6;
	vector<int> spf(N + 1);
	vector<int> primes;
	range(i, 0, N + 1) {
		spf[i] = i;
	}
	range(i, 2, N + 1) {
		if (spf[i] != i) {
			continue;
		}

		primes.push_back(i);
		for (int j = i; j <= N; j += i) {
			if (spf[j] == j) {
				spf[j] = i;
			}
		}
	}

	int n;
	input(n);

	int x = n;
	map<int, int> m;
	for (int i : primes) {
		while (x % i == 0) {
			m[i]++;
			x /= i;
		}
	}
	if (x != 1) {
		m[x]++;
	}

	vector<int> l = {1};
	for (pair<int, int> p : m) {
		int z = 1;
		vector<int> nl(l.begin(), l.end());
		range(i, 0, p.second) {
			z *= p.first;
			for (int j : l) {
				nl.push_back(j * z);
			}
		}
		l = nl;
	}

	map<int, pair<int, int>> dp;
	for (int i : l) {
		dp[i] = {-1, -1};
		string s = to_string(i);
		if (i == rev(i) and s.find('0') == string::npos) {
			dp[i] = {0, i};
			continue;
		}

		for (int j : l) {
			s = to_string(j);
			if (s.find('0') == string::npos and i % (j * rev(j)) == 0 and dp[i / (j * rev(j))].first != -1) {
				dp[i] = {i / (j * rev(j)), j};
				break;
			}
		}
	}

	if (dp[n].first == -1) {
		print(-1);
		return 0;
	}

	vector<int> res;
	while (n) {
		res.push_back(dp[n].second);
		n = dp[n].first;
	}

	for (int i = res.size() - 2; i >= 0; i--) {
		res.push_back(rev(res[i]));
	}

	cout << res[0];
	range(i, 1, res.size()) {
		cout << '*' << res[i];
	}
}
