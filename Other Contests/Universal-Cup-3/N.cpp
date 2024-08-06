#include <bits/stdc++.h>
using namespace std;

#define int long long
#define rep(i, a, b) for(int i = a; i < (b); ++i) 
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii; 
typedef vector<int> vi;

void encode(int n, int m, vector<vi> &graph) {
    vector<vi> ans(m, vi(m, 0));
    int l = 0;
    {
        int r = 1;
        while(r < n) {
            l++;
            r *= 2;
        }
    }
    rep(i, 0, n) rep(j, 0, n) ans[i][j] = graph[i][j];
    // Nodes n to n + l - 1 make the ordering
    rep(i, 0, n) {
        rep(j, 0, l) {
            if((i >> j) & 1) {
                ans[i][n + j] = 1;
                ans[n + j][i] = 1;
            }
        }
    }
    // Node n + l connects to the n nodes
    rep(i, 0, n) {
        ans[n + l][i] = 1;
        ans[i][n + l] = 1;
    }
    // Node n + l + 1 connects only to node n + l - 1
    ans[n + l + 1][n + l - 1] = 1;
    ans[n + l - 1][n + l + 1] = 1;
    // n to n + l - 1 connect to each other for ordering
    rep(j, 0, l - 1) {
        ans[n + j][n + j + 1] = 1;
        ans[n + j + 1][n + j] = 1;
    }
    // Any node with a degree of n is connected to node n + l + 2
    rep(i, 0, m - 1) {
        if(i == n + l) continue;
        int cnt = accumulate(ans[i].begin(), ans[i].end(), 0ll);
        if(cnt == n) {
            ans[i][m - 1] = 1;
            ans[m - 1][i] = 1;
        }
    }
    // Assertion (pray this doesn't occur)
    int cnt = accumulate(ans[m - 1].begin(), ans[m - 1].end(), 0ll);
    // if (cnt == n) {
        // assert(ans[m - 1][n] == 0); // This will happen when n == 3 :(
    // }
    // assert(cnt != n);
    // Print
    rep(i, 0, m) {
        rep(j, 0, m) {
            cout << ans[i][j];
        }
        cout << '\n';
    }
}

void decode(int m, int n, vector<vi> &graph) {
    int l = 0;
    {
        int r = 1;
        while(r < n) {
            l++;
            r *= 2;
        }
    }
    // Find the node with degree n
    int first;
    int second;
    set <int> original;
    vi encoders;
    rep(i, 0, m) {
        int cnt = accumulate(graph[i].begin(), graph[i].end(), 0ll);
        if (cnt == n) {
            first = i;
            rep(j, 0, m) {
                if(graph[i][j] == 1) {
                    original.insert(j);
                }
            }
        }
        if (cnt == 1) {
            second = i;
            rep(j, 0, m) {
                if(graph[i][j] == 1) {
                    encoders.push_back(j);
                }
            }
        }
    }
    // cout << first << ' ' << second << ' ' << encoders.front() << endl;
    // for(auto i : original) cout << i << ' '; cout << endl;
    set <int> ugh;
    ugh.insert(encoders.front());
    while(sz(encoders) < l) {
        int curr = encoders.back();
        rep(i, 0, m) {
            if((original.find(i) != original.end()) || (ugh.find(i) != ugh.end()) || i == second) continue;
            if(graph[curr][i] == 1) {
                encoders.push_back(i);
                ugh.insert(i);
                // cout << "inserted " << i << endl;
                break;
            }
        }
    }
    reverse(all(encoders));
    // for(auto i : encoders) cout << i << ' '; cout << endl;
    map<int, int> decode;
    for(auto i : original) {
        int val = 0;
        rep(j, 0, l) {
            if(graph[i][encoders[j]] == 1) {
                val += (1 << j);
            }
        }
        decode[i] = val;
        // cout << i << ' ' << val << endl;
    }
    vector<vi> ans(n, vi(n, 0));
    try {
    for(auto i : original) for(auto j : original) if(i != j) {
        ans[decode[i]][decode[j]] = graph[i][j];
    }
    rep(i, 0, n) {
        rep(j, 0, n) {
            cout << ans[i][j];
        }
        cout << '\n';
    }
    } catch(...) {}
}

void encode_three(int n, int m, vector<vi> &graph) {
    int l = 2;
    vector<vi> ans(m, vi(m, 0));
    rep(i, 0, n) rep(j, 0, n) {
        ans[i][j] = graph[i][j];
    }
    rep(i, n, m) rep(j, n, m) {
        if(i != j) ans[i][j] = 1;
    }
    ans[0][3] = 1; ans[3][0] = 1;
    ans[1][4] = 1; ans[4][1] = 1;
    ans[1][5] = 1; ans[5][1] = 1;
    ans[2][6] = 1; ans[6][2] = 1;
    ans[2][7] = 1; ans[7][2] = 1;
    ans[2][5] = 1; ans[5][2] = 1;
    rep(i, 0, m) {
        rep(j, 0, m) {
            cout << ans[i][j];
        }
        cout << '\n';
    }
}

void decode_three(int m, int n, vector<vi> &graph) {
    // Find a 5 x 5 complete graph
    set <int> comp;
    rep(a, 0, m) rep(b, a + 1, m) rep(c, b + 1, m) rep(d, c + 1, m) rep(e, d + 1, m) {
        if(!comp.empty()) break;
        vi v = {a, b, c, d, e};
        bool pos = true;
        for(auto i : v) for(auto j : v) {
            if(i == j) continue;
            if(graph[i][j] == 0) pos = false;
        }
        if(pos == false) continue;
        for(auto i : v) comp.insert(i);
    }
    // for(auto i : comp) cout << i << ' '; cout << endl;
    set <int> left;
    rep(i, 0, 8) if(comp.find(i) == comp.end()) left.insert(i);
    int o, t, th;
    for(auto i : left) {
        int cnt = 0;
        for(auto j : comp) if(graph[i][j]) cnt++;
        if(cnt == 1) o = i;
        if(cnt == 2) t = i;
        if(cnt == 3) th = i;
    }
    vector<vi> ans(3, vi(3, 0));
    ans[0][1] = ans[1][0] = graph[o][t];
    ans[0][2] = ans[2][0] = graph[o][th];
    ans[1][2] = ans[2][1] = graph[t][th];
    rep(i, 0, n) {
        rep(j, 0, n) {
            cout << ans[i][j];
        }
        cout << '\n';
    }
}

int32_t main() {
	cin.tie(0)->sync_with_stdio(0);

    int n, m;
    cin >> n >> m;
    vector<vi> v(n, vi(n));
    rep(i, 0, n) {
        string s;
        cin >> s;
        rep(j, 0, n) {
            v[i][j] = s[j] - '0';
        }
    }
    if(n < m) {
        if (n == 3) encode_three(n, m, v);
        else encode(n, m, v);
    } else {
        if (m == 3) decode_three(n, m, v);
        else decode(n, m, v);
    }
}
