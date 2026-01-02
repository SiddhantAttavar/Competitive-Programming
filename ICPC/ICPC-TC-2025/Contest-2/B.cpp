#include <bits/stdc++.h>
using namespace std;

#define int long long
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) ((int)(x).size())
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

vi val, comp, z, cont;
int Time, ncomps;
template<class G, class F> int dfs(int j, G& g, F& f) {
	int low = val[j] = ++Time, x; z.push_back(j);
	for (auto e : g[j]) if (comp[e] < 0)
		low = min(low, val[e] ?: dfs(e,g,f));

	if (low == val[j]) {
		do {
			x = z.back(); z.pop_back();
			comp[x] = ncomps;
			cont.push_back(x);
		} while (x != j);
		f(cont); cont.clear();
		ncomps++;
	}
	return val[j] = low;
}
template<class G, class F> void scc(G& g, F f) {
	int n = sz(g);
	val.assign(n, 0); comp.assign(n, -1);
	Time = ncomps = 0;
	rep(i,0,n) if (comp[i] < 0) dfs(i, g, f);
}

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

    void exactlyOne(int a, int b) {
        either(a, b);
        either(~a, ~b);
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

bool check(int i, int j, int k, vector<array<int, 4>> &v) {
    TwoSat t(52);
    t.setValue(~i);
    t.setValue(~j);
    t.setValue(~k);
    t.setValue(~(i + 26));
    t.setValue(~(j + 26));
    t.setValue(~(k + 26));
    rep(x, 0, 26) {
        if (x != i and x != j and x != k) {
            t.exactlyOne(x, x + 26);
        }
    }
    for (auto [x, y, a, z] : v) {
        if (a) {
            x += 26;
            y += 26;
        }
        if (z == 0) {
            t.setValue(~x);
            t.setValue(~y);
        }
        else if (z == 2) {
            t.setValue(x);
            t.setValue(y);
        }
        else {
            t.exactlyOne(x, y);
        }
    }
    return t.solve();
}

void solve() {
    int n;
    cin >> n;

    vector<array<int, 4>> v(n);
    rep(i, 0, n) {
        string s;
        int x, y;
        cin >> s >> x >> y;
        v[i] = {s[0] - 'A', s[1] - 'A', x - 1, y};
    }

    int res = 0;
    rep(i, 0, 26) {
        rep(j, i + 1, 26) {
            rep(k, j + 1, 26) {
                res += check(i, j, k, v);
            }
        }
    }
    cout << res << endl;
}

signed main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t = 1;
    // cin >> t;
    while (t--) {
		solve();
	}
}
