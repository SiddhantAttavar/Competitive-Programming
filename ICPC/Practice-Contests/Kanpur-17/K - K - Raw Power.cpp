#include <bits/stdc++.h>
using namespace std;

// #define int long long
#define rep(a, b, c) for (int a = b; a < c; a++)
#define all(v) v.begin(), v.end()
#define pii pair<int, int>
typedef vector<int> vi;
typedef long long ll;

const int mod = 1e9 + 7;
// l, r
// l, mid -> mid
// mid + 1, new_lo = mid+1, new_high = mid + 1

// -12, -11
//

#pragma once

// Either globally or in a single class:
static char buf[450 << 20];

void* operator new(size_t s) {
    static size_t i = sizeof(buf);
    assert(s < i); 
    i -= s;       
    return static_cast<void*>(&buf[i]); 
}

void operator delete(void* p) {
}

struct Node
{
    Node *l = nullptr, *r = nullptr;
    int lo = 0, hi = mod;
    ll val = 0;
    int cnt = 0;
    Node(int lo, int hi) : lo(lo), hi(hi) {}
    int query(int k, int rem)
    {
        // cerr << val << " " << lo << " " << hi << " " << rem << " " << cnt << "\n";

        // cerr << lo - mod << " " << hi - mod << " " << val << " " << cnt << " " << rem << "\n ";

        if (cnt == 0)
        {
            if (rem == 0)
                return lo - 1;
            return lo - 1 + k / rem;
        }
        if (val + rem * (hi - lo + 1) <= k)
            return hi;
        if (lo == hi)
            return lo - 1;
        int mid = (lo + hi) / 2;
        if (!l)
            l = new Node(lo, mid);
        if (!r)
            r = new Node(mid + 1, hi);
        int lval = l->val + rem * (mid - lo + 1);
        if (lval > k)
            return l->query(k, rem);
        return r->query(k - lval, rem + l->cnt);
    }
    void add(int pos)
    {
        val += hi - pos, cnt++;
        // cerr << lo - mod << " " << hi - mod << " " << pos - mod << "\n";
        if (lo == hi)
            return;
        int mid = (lo + hi) / 2;
        if (pos <= mid)
        {
            if (!l)
                l = new Node(lo, mid);
            l->add(pos);
        }
        else
        {
            if (!r)
                r = new Node(mid + 1, hi);
            r->add(pos);
        }
    }
};

void del(Node *n)
{
    if (n->lo == n->hi)
    {
        delete n;
        return;
    }
    if (n->l)
        del(n->l);
    if (n->r)
        del(n->r);
    delete n;
}

//

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    int n;
    cin >> n;
    vector<pii> v(n);
    rep(i, 0, n) cin >> v[i].first >> v[i].second;
    int q;
    cin >> q;
    vector<ll> queries(q);
    rep(i, 0, q) cin >> queries[i];

    auto solve = [&]()
    {
        int mn = mod;
        rep(i, 0, n) mn = min(mn, v[i].second - v[i].first);
        sort(all(v));
        vector<ll> s(n + 1);
        s[n] = 0;
        for (int i = n - 1; i >= 0; i--)
            s[i] = s[i + 1] + v[i].first;
        vi answer;
        for (ll k : queries)
        {
            int fans = 0;
            Node *st = new Node(0, mod);
            rep(i, 0, n)
            {
                // cerr << i << "\n";
                ll lose = s[i + 1] - (n - i - 1) * v[i].first;
                if (lose <= k)
                {
                    int f = st->query(k - lose, 0);
                    // cerr << k - lose << "\n";
                    // cerr << f - v[i].first << "\n";
                    fans = max(fans, f - v[i].first);
                }
                st->add(v[i].second);
            }
            del(st);
            answer.push_back(min(mn, fans));
        }
        return answer;
    };
    vi ans = solve();
    rep(i, 0, n) v[i] = {mod - v[i].second, mod - v[i].first};
    // cerr << "rev\n";
    vi ans2 = solve();
    rep(i, 0, q) cout << max(ans[i], ans2[i]) << "\n";
}

