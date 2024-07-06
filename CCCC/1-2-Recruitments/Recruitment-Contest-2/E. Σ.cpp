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

int32_t main() {
	setup();

	int p, q;
	input(p, q);

	int x = 0;
	while ((x + 1) * (x + 1) <= p) {
		x++;
	}

	vector<int> a(x + 1);
	vector<pair<pair<int, int>, pair<int, int>>> v;
	range(i, 1ll, x + 1) {
		a[i] = p % i;
		int l = p / (i + 1) + 1, r = p / i;
		int y = ((r - l + 1) * (p % i + p % i + i * (r - l))) / 2;
		y -= ((r - l + 1) * (2 * p - l - r)) / 2;
		v.push_back({{l, r}, {i, y}});
	}

	range(i, 0, x) {
		a[i + 1] += a[i];
	}

	sort(v.begin(), v.end());
	range(i, 1, (int) v.size()) {
		v[i].second.second += v[i - 1].second.second;
	}
	v.insert(v.begin(), {{0, 0}, {1, 0}});

	while (q--) {
		int l, r;
		input(l, r);

		int res = p * max(0ll, r - max(l - 1, p));
		r = min(r, p);


		if (l >= p) {
			print(res);
			continue;
		}

		if (r <= x) {
			print(a[r] - a[l - 1]);
			continue;
		}

		if (l <= x) {
			res += a[x] - a[l - 1];
			l = x + 1;
		}

		int i = lower_bound(v.begin(), v.end(), make_pair(make_pair(l, l), make_pair(0ll, 0ll))) - v.begin();
		int j = lower_bound(v.begin(), v.end(), make_pair(make_pair(r + 1, r + 1), make_pair(0ll, 0ll))) - v.begin() - 1;
		if (v[j].first.second > r) {
			j--;
		} 
		// print(v[j].first.first, v[j].first.second, v[j].second.first, v[j].second.second);
		if (j >= i - 1) {
			res += v[j].second.second - v[i - 1].second.second;
		}
		// print(i, j);
		i--;
		j++;
		// print(v[j].first.first, v[j].first.second, v[j].second.first, v[j].second.second);
		res += ((2 * p - l - r) * (r - l + 1)) / 2;
		if (i < (int) v.size() and i >= 0 and v[i].first.second >= l) {
			// print(v[i].first.first, v[i].first.second, v[i].second.first, v[i].second.first);
			int z = v[i].second.first;
			int e = l, f = min(r, v[i].first.second), g = v[i].first.second;
			res += ((f - e + 1) * (p % z + z * (g - f) + p % z + z * (g - e))) / 2;
			res -= ((f - e + 1) * (2 * p - e - f)) / 2;
		}
		if (j >= 0 and j < (int) v.size() and v[j].first.first <= r and v[j].first.first >= l) {
			// print(v[j].first.first, v[j].first.second, v[j].second.first, v[j].second.second);
			int e = v[j].first.first, f = r, g = v[j].first.second;
			int z = v[j].second.first;
			res += ((f - e + 1) * (p % z + z * (g - f) + p % z + z * (g - e))) / 2;
			res -= ((f - e + 1) * (2 * p - e - f)) / 2;
		}
		print(res);
	}
}
