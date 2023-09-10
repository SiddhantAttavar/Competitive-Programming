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

	vector<int> c(n);
	arrPut(c);

	vector<bool> a(n), b(n);
	string x, y;
	input(x, y);
	range(i, 0, n) {
		a[i] = x[i] - '0';
		b[i] = y[i] - '0';
	}

	vector<pair<int, int>> zto, otz, v;
	range(i, 0, n) {
		if (a[i] and !b[i]) {
			otz.push_back({-c[i], i});
		}
		else if (!a[i] and b[i]) {
			zto.push_back({c[i], i});
		}
		else if (a[i]) {
			v.push_back({c[i], i});
		}
	}

	sort(zto.begin(), zto.end());
	sort(otz.begin(), otz.end());
	sort(v.begin(), v.end());

	int res = 0, curr = 0;
	vector<int> cost_zto(zto.size()), cost_otz(otz.size());
	range(i, 0, n) {
		curr += c[i] * a[i];
	}
 
	range(i, 0, (int) otz.size()) {
		curr -= c[otz[i].second];
		cost_otz[i] = curr;
		res += curr;
	}
 
	range(i, 0, (int) zto.size()) {
		curr += c[zto[i].second];
		cost_zto[i] = curr;
		res += curr;
	}

	otz.push_back({0, -1});
	cost_otz.push_back(0);
	zto.insert(zto.begin(), {0, -1});
	cost_zto.insert(cost_zto.begin(), 0);

	vector<vector<int>> dp(v.size() + 1, vector<int>(n + 1, 0));
	fill(dp[0].begin(), dp[0].end(), 0);

	int l = (int) otz.size() - 1;
	int r = 0;
	range(i, 0, (int) v.size()) {
		while (l >= 0 and -otz[l].first < v[i].first) {
			l--;
		}

		while (r < (int) zto.size() and zto[r].first < v[i].first) {
			r++;
		}

		int k = ((int) otz.size() - l - 2) + (r - 1) + 1;
		print(l, r, k);
		print(cost_otz[l + 1], otz[l + 1].first, cost_zto[r - 1]);
		dp[i + 1][k] = (k - 1) * v[i].first - (cost_otz[l + 1] - v[i].first - otz[l + 1].first + cost_zto[r - 1]);
		range(p, k + 1, k + i + 1) {
			dp[i + 1][p] = max({
				dp[i][p],
				dp[i][p - 1] + (p - 1) * v[i].first - (cost_otz[l + 1] - v[i].first - otz[l + 1].first + cost_zto[r - 1])
			});
		}
	}

	range(i, 0, (int) v.size() + 1) {
		arrPrint(dp[i]);
	}

	int ans = res;
	range(k, 0, n + 1) {
		if (dp[(int) v.size()][k] != -1) {
			ans = min(ans, res - dp[(int) v.size()][k]);
		}
	}

	print(ans);
}
