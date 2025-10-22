#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace std;
using namespace __gnu_pbds; 
template<typename T> inline void input(T& x) {cin >> x;}
template<typename T, typename... S> inline void input(T& x, S&... args) {cin >> x; input(args ...);}
template<typename T> inline void print(T x) {cout << x << '\n';}
template<typename T, typename... S> inline void print(T x, S... args) {cout << x << ' '; print(args ...);}
#define debug(...) cout << #__VA_ARGS__ << ": "; print(__VA_ARGS__);
#define rep(i, a, b) for (auto i = (a); i < (b); i++)
#define arrput(l) for (auto &i : l) {cin >> i;}
#define arrprint(l) for (auto i : l) {cout << i << ' ';} cout << '\n'
#define setup() ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define int long long
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> 
const int MOD = (int) 1e9 + 7; //998244353;

#define vi vector<int>
#define sz(x) (int) x.size()

const int N = 1e7;

struct TwoSat {
	int N;
	vector<vi> gr;
	vi values; // 0 = false, 1 = true

	TwoSat(int n = 0) : N(n), gr(2*n) {
		gr.reserve(1e7);
	}

	int addVar() { // (optional)
		gr.emplace_back();
		gr.emplace_back();
		return N++;
	}

	void either(int f, int j) {
		f = max(2*f, -1-2*f);
		j = max(2*j, -1-2*j);
		if (max(f, j) < 0 or max(f, j) >= gr.size()) return;
		gr[f].push_back(j^1);
		gr[j].push_back(f^1);
	}
	void setValue(int x) { either(x, x); }

	int atMostOne(const vi& li) { // (optional)
		if (li.empty()) return addVar();
		if (sz(li) == 1) {
			int x = addVar();
			either(~li[0], x);
			return x;
		}
		int cur = ~li[0];
		rep(i,1,sz(li)) {
			int next = addVar();
			either(cur, ~li[i]);
			either(cur, next);
			either(~li[i], next);
			cur = ~next;
		}
		return ~cur;
	}

	vi val, comp, inStack;
	int timer = 0;
	vector<int> st;

	bool solve() {
		values.assign(N, -1);
		val.assign(2*N, 0);
		comp.assign(2*N, 0);
		inStack.assign(2*N, 0);
		st.clear();
		timer = 0;

		int cid = 0; // component id counter
		vector<int> idx(2*N, -1), low(2*N, 0);
		vector<int> stack;
		vector<char> onstack(2*N, false);
		int idCounter = 0;

		for (int start = 0; start < 2*N; ++start) {
			if (idx[start] != -1) continue;

			// manual DFS stack: (node, iterator index, "phase")
			vector<pair<int,int>> dfs;
			dfs.emplace_back(start, 0);

			while (!dfs.empty()) {
				auto &[v, it] = dfs.back();

				if (idx[v] == -1) {
					idx[v] = low[v] = ++idCounter;
					stack.push_back(v);
					onstack[v] = true;
				}

				if (it < (int)gr[v].size()) {
					int to = gr[v][it++];
					if (idx[to] == -1) {
						dfs.emplace_back(to, 0);
					} else if (onstack[to]) {
						low[v] = min(low[v], idx[to]);
					}
				} else {
					// Postorder: update low-link
					for (int to : gr[v])
						if (onstack[to])
							low[v] = min(low[v], low[to]);

					if (low[v] == idx[v]) {
						// found SCC
						while (true) {
							int x = stack.back(); stack.pop_back();
							onstack[x] = false;
							comp[x] = cid + 1;
							if (values[x >> 1] == -1)
								values[x >> 1] = x & 1;
							if (x == v) break;
						}
						cid++;
					}
					dfs.pop_back();
				}
			}
		}

		for (int i = 0; i < N; ++i)
			if (comp[2*i] == comp[2*i + 1])
				return false;
		return true;
	}
};

int z = 1;
void insert(int u, string &s, vector<pair<int, int>> &tree, vector<vector<int>> &l, int x) {
	for (char c : s) {
		if (u < 0 or u >= tree.size() or tree.size() != l.size()) return;
		if (c == '0') {
			if (tree[u].first == -1) {
				tree[u].first = z++;
				tree.push_back({-1, -1});
				l.push_back({});
			}
			u = tree[u].first;
		}
		else {
			if (tree[u].second == -1) {
				tree[u].second = z++;
				tree.push_back({-1, -1});
				l.push_back({});
			}
			u = tree[u].second;
		}
	}
	if (u < 0 or u >= tree.size() or tree.size() != l.size()) return;
	l[u].push_back(x);
}

void dfs(int u, int p, vector<pair<int, int>> &tree, vector<vector<int>> &l, TwoSat &t) {
	if (u == -1) {
		return;
	}
	if (u < 0 or u >= tree.size() or tree.size() != l.size()) return;

	int x = t.atMostOne(l[u]);
	for (int i : l[u]) {
		t.either(~i, x);
	}
	if (p != -1) {
		for (int i : l[u]) {
			t.either(~p, ~i);
		}
		t.either(~p, x);
	}
	dfs(tree[u].first, x, tree, l, t);
	dfs(tree[u].second, x, tree, l, t);
}

int32_t main() {
	try {
	setup();

	freopen("binary.in", "r", stdin);
	freopen("binary.out", "w", stdout);

	int n;
	input(n);

	vector<string> s(n);
	arrput(s);

	vector<pair<int, int>> tree = {{-1, -1}};
	vector<vector<int>> l = {{}};
	tree.reserve(N);
	l.reserve(N);
	vector<int> v(n, -1);
	TwoSat t(n);
		rep(i, 0, n) {
			int j = s[i].find('?');
			if (j == -1) {
				int x = s[i][0] == '0' ? ~i : i;
				t.setValue(x);
				insert(0, s[i], tree, l, x);
			}
			else {
				v[i] = j;
				string a = s[i], b = s[i];
				if (j < 0 or j > s[i].size()) return 0;
				a[j] = '0';
				b[j] = '1';
				insert(0, a, tree, l, ~i);
				insert(0, b, tree, l, i);
			}
		}

	dfs(0, -1, tree, l, t);

	if (!t.solve()) {
		print("NO");
		return 0;
	}

	print("YES");
	rep(i, 0, n) {
		if (v[i] != -1) {
			s[i][v[i]] = t.values[i] + '0';
		}
		print(s[i]);
	}
	}
	catch (exception e) {}
}
