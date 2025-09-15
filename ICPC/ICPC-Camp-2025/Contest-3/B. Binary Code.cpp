#include <bits/stdc++.h>
using namespace std;
// #define int long long
#define rep(i, a, b) for (int i = a; i < b; i++)

#define vi vector<int>
#define sz(x) (int)x.size()

struct TwoSat {
	int N;
	vector<vi> gr;
	vi values; // 0 = false, 1 = true

	TwoSat(int n = 0) : N(n), gr(2*n) {}

	int addVar() { // (optional)
		gr.emplace_back();
		gr.emplace_back();
		return N++;
	}

	void either(int f, int j) {
		f = max(2*f, -1-2*f);
		j = max(2*j, -1-2*j);
		gr[f].push_back(j^1);
		gr[j].push_back(f^1);
	}
	void setValue(int x) { either(x, x); }

	void atMostOne(const vi& li) { // (optional)
		if (sz(li) <= 1) return;
		int cur = ~li[0];
		rep(i,2,sz(li)) {
			int next = addVar();
			either(cur, ~li[i]);
			either(cur, next);
			either(~li[i], next);
			cur = ~next;
		}
		either(cur, ~li[1]);
	}

	vi val, comp, z; int time = 0;
	int dfs(int i) {
		int low = val[i] = ++time, x; z.push_back(i);
		for(int e : gr[i]) if (!comp[e])
			low = min(low, val[e] ?: dfs(e));
		if (low == val[i]) do {
			x = z.back(); z.pop_back();
			comp[x] = low;
			if (values[x>>1] == -1)
				values[x>>1] = x&1;
		} while (x != i);
		return val[i] = low;
	}

	bool solve() {
		values.assign(N, -1);
		val.assign(2*N, 0); comp = val;
		rep(i,0,2*N) if (!comp[i]) dfs(i);
		rep(i,0,N) if (comp[2*i] == comp[2*i+1]) return 0;
		return 1;
	}
};

void insert(vector<pair<int, int>> &tree, vector<vector<int>> &l, string &s, int x) {
	int u = 0;
	for (char c : s) {
		if (c == '0') {
			if (tree[u].first == -1) {
				tree[u].first = tree.size();
				tree.push_back({-1, -1});
				l.push_back({});
			}
			u = tree[u].first;
		}
		else {
			if (tree[u].second == -1) {
				tree[u].second = tree.size();
				tree.push_back({-1, -1});
				l.push_back({});
			}
			u = tree[u].second;
		}
	}
	l[u].push_back(x);
}

void dfs(int u, int p, vector<pair<int, int>> &tree, TwoSat &t, vector<vector<int>> &l) {
	if (u == -1) {
		return;
	}
	t.atMostOne(l[u]);
	int x = t.addVar();
	for (int i : l[u]) {
		t.either(~i, x);
	}
	if (p != -1) {
		for (int i : l[u]) {
			t.either(~p, ~i);
		}
		t.either(~p, x);
	}
	dfs(tree[u].first, x, tree, t, l);
	dfs(tree[u].second, x, tree, t, l);
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

	// freopen("binary.in", "r", stdin);
	// freopen("binary.out", "w", stdout);

	int n;
	cin >> n;

	vector<string> s(n);
	rep(i, 0, n) {
		cin >> s[i];
	}

	vector<int> k(n);
	vector<pair<int, int>> tree = {{-1, -1}};
	vector<vector<int>> l = {{}};
	TwoSat t(n);
	rep(i, 0, n) {
		k[i] = find(s[i].begin(), s[i].end(), '?') - s[i].begin();
		if (k[i] == s[i].size()) {
			k[i] = 0;
			int x = s[i][0] == '0' ? ~i : i;
			t.setValue(x);
			insert(tree, l, s[i], x);
		}
		else {
			string b = s[i], c = s[i];
			b[k[i]] = '0';
			c[k[i]] = '1';
			insert(tree, l, b, ~i);
			insert(tree, l, c, i);
		}
	}

	dfs(0, -1, tree, t, l);

	if (!t.solve()) {
		cout << "NO" << endl;
		return 0;
	}

	cout << "YES" << endl;
	rep(i, 0, n) {
		s[i][k[i]] = t.values[i] + '0';
		cout << s[i] << endl;
	}
}
