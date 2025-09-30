#include <bits/stdc++.h>
using namespace std;
#define int long long
#define rep(i, a, b) for (int i = a; i < b; i++)

int get(string s) {
    while (s.back() == '\\') {
        s.pop_back();
    }
    return stoll(s);
}

char C = '0' - 1;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    set<string> s;
    rep(i, 1, 10) {
        s.insert(string(1, '0' + i));
    }

    set<int> res;
    rep(i, 2, 18) {
        set<string> ns;
        queue<int> q;
        for (string j : s) {
            ns.insert(j + C);
            if (j.back() == C) {
                continue;
            }
            int x = get(j);
            rep(k, 0, 10) {
                q.push(10 * x + k);
            }
        }
        s = ns;

        while (!q.empty()) {
            int x = q.front();
            q.pop();
            
            string t = to_string(x);
            while (t.size() < i) {
                t += C;
            }
            s.insert(t);

            if (s.size() > 2020) {
                s.erase(--s.end());
            }
            if (s.size() == 2020) {
                res.insert(get(*s.rbegin()));
            }
        }
        
        // for (string i : s) cout << i << ' ';
        // cout << endl;
    }

    // for (int i : res) {
    //     cout << i << ' ';
    // }
    // cout << endl;

    int q;
    cin >> q;
    while (q--) {
        int m;
        cin >> m;

        if (res.count(m)) {
            cout << "YES\n";
        }
        else {
            cout << "NO\n";
        }
    }
}
