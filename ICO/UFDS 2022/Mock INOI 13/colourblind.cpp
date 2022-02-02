// https://codebreaker.xyz/problem/colourblind
#include <bits/stdc++.h>
using namespace std;
template<typename T> inline void input(T& inVar) {cin >> inVar;}
template<typename T, typename... S> inline void input(T& inVar, S&... args) {cin >> inVar; input(args ...);}
template<typename T> inline void print(T outVar) {cout << outVar << '\n';}
template<typename T, typename... S> inline void print(T outVar, S... args) {cout << outVar << ' '; print(args ...);}
#define range(it, start, end) for (ll it = start; it < end; it++)
#define arrPut(var) for (auto &inVar : var) {cin >> inVar;}
#define arrPrint(var) for (auto outVar : var) {cout << outVar << ' ';} cout << '\n'
#define setup() ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define ll long long

int n, m;
vector<vector<pair<ll, ll>>> comps;
vector<vector<tuple<ll, ll, ll>>> a;
vector<vector<bool>> visited;
ll x = 1e17 + 1, y = -1;

bool checkSimilar(tuple<ll, ll, ll> a, tuple<ll, ll, ll> b, ll k) {
	ll x, y, z, i, j, l;
	tie(x, y, z) = a;
	tie(i, j, l) = b;
	return max({abs(x - i), abs(y - j), abs(z - l)}) <= k;
}

void dfs(ll i, ll j, ll k) {
	visited[i][j] = true;
	comps.back().push_back({i, j});
	vector<pair<ll, ll>> next = {
		{i - 1, j},
		{i + 1, j},
		{i, j - 1},
		{i, j + 1}
	};
	for (pair<ll, ll> p : next) {
		ll x, y;
		tie(x, y) = p;
		if (x >= 0 and x < n and y >= 0 and y < m) {
			if (!visited[x][y] and checkSimilar(a[i][j], a[x][y], k)) {
				dfs(x, y, k);
			}
		}
	}
}

int check(ll c) {
	comps.clear();
	visited.clear();
	visited.resize(n, vector<bool>(m));
	
	range(i, 0, n) {
		range(j, 0, m) {
			if (!visited[i][j]) {
				comps.push_back({});
				dfs(i, j, c);
			}
		}
	}

	ll maxX = 0, maxY = 0, maxZ = 0;
	ll minX = LLONG_MAX, minY = LLONG_MAX, minZ = LLONG_MAX;
	for (vector<pair<ll, ll>> v : comps) {
		vector<ll> x(v.size()), y(v.size()), z(v.size());
		range(i, 0, v.size()) {
			tie(x[i], y[i], z[i]) = a[v[i].first][v[i].second];
		}

		ll currMinX = *min_element(x.begin(), x.end());
		ll currMaxX = *max_element(x.begin(), x.end());
		ll currMinY = *min_element(y.begin(), y.end());
		ll currMaxY = *max_element(y.begin(), y.end());
		ll currMinZ = *min_element(z.begin(), z.end());
		ll currMaxZ = *max_element(z.begin(), z.end());

		minX = min(minX, currMinX);
		maxX = max(maxX, currMaxX);
		minY = min(minY, currMinY);
		maxY = max(maxY, currMaxY);
		minZ = min(minZ, currMinZ);
		maxZ = max(maxZ, currMaxZ);
		
		if (max({currMaxX - currMinX, currMaxY - currMinY, currMaxZ - currMinZ}) > c) {
			return 0;
		}
	}

	if (max({maxX - minX, maxY - minY, maxZ - minZ}) > c) {
		return -1;
	}
	else {
		return 1;
	}
}

void init(int H, int W, int Q, int S, vector<vector<ll>> R,vector<vector<ll>> G, vector<vector<ll>> B) {
	n = H;
	m = W;

	a.resize(n, vector<tuple<ll, ll, ll>>(m));
	range(i, 0, n) {
		range(j, 0, m) {
			a[i][j] = {R[i][j], G[i][j], B[i][j]};
		}
	}

	ll l = 0, r = 1e17;
	while (l <= r) {
		ll m = (l + r) / 2;
		int k = check(m);
		if (k == -1) {
			l = m + 1;
		}
		else if (k == 0) {
			r = m - 1;
			x = m;
		}
		else {
			r = m - 1;
			y = m - 1;
		}
	}

	l = x;
	r = y;
	while (l <= r) {
		ll m = (l + r) / 2;
		int k = check(m);
		if (k == 0) {
			l = m + 1;
			y = m;
		}
		else {
			r = m - 1;
		}
	}

	// print(x, y);
}

bool query(ll c) {
	return x <= c and c <= y;
}

/**
int main() {
	setup();

	int h, w, q, s;
	input(h, w, q, s);

	vector<vector<ll>> r(h, vector<ll>(w));
	range(i, 0, h) {
		arrPut(r[i]);
	}
	vector<vector<ll>> g(h, vector<ll>(w));
	range(i, 0, h) {
		arrPut(g[i]);
	}
	vector<vector<ll>> b(h, vector<ll>(w));
	range(i, 0, h) {
		arrPut(b[i]);
	}

	init(h, w, q, s, r, g, b);

	while (q--) {
		ll c;
		input(c);
		// print(check(c));
		if (query(c)) {
			print("Yes");
		}
		else {
			print("No");
		}
	}
}
**/
