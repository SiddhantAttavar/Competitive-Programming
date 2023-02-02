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

int n, m, k;
vector<vector<int>> v;
vector<int> x, d;
vector<vector<int>> y, z;

int32_t main() {
	setup();

	input(n, m, k);

	v.resize(k, vector<int>(4));
	x.resize(k);
	d.resize(k);
	y.resize(m + 2, vector<int>(4, 0));
	z.resize(m + 2, vector<int>(2, 0));

	range(i, 0, k) {
		arrPut(v[i]);
		
		if (v[i][1] > v[i][3]) {
			swap(v[i][1], v[i][3]);
		}

		x[i] = abs(v[i][0] - v[i][2]);
		d[i] = x[i] / 4;

		y[max(1ll, v[i][1] - d[i])][0]++;
		y[v[i][1]][1]++;
		y[v[i][3] + 1][2]++;
		y[min(m + 1, v[i][3] + d[i] + 1)][3]++;

		if (v[i][1] != 1) {
			z[max(0ll, v[i][1] - d[i])][0] += x[i] % 4;
		}
		z[min(m + 1, v[i][3] + d[i] + 1)][1] += x[i] % 4;
	}

	/* for (auto i : z) {
		print(i[0], i[1]);
	} */

	// calculate for highway at 1
	int t = 0;
	range(i, 0, k) {
		t += min(
				x[i] + 2 * (abs(1 - v[i][1]) + abs(1 - v[i][3])),
				2 * (x[i] + abs(v[i][1] - v[i][3]))
				);
	}

	int c = y[1][1];
	int b = y[1][0] - c;
	int a = k - (b + c);
	int d = 0, e = 0;
	// print(1, t, a, b, c, d, e);
	int res = t;
	range(i, 2, m + 1) {
		t -= 4 * b;
		a -= y[i][0];
		b += y[i][0];

		b -= y[i][1];
		c += y[i][1];

		c -= y[i][2];
		d += y[i][2];

		d -= y[i][3];
		e += y[i][3];

		t += z[i][1] - z[i][0];
		t += 4 * d;
		res = min(res, t);
		// print(i, t, a, b, c, d, e);
	}
	print(res);
}
