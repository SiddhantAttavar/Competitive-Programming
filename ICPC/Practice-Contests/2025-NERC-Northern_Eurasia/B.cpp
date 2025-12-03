#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) ((int)((x).size()))
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

vector<bitset<16>> machine;
void print_hex(int x) {
    machine.push_back(x);
    string hex = "0123456789abcdef";
    cout << hex[(x >> 12) & 15];
    cout << hex[(x >> 8) & 15];
    cout << hex[(x >> 4) & 15];
    cout << hex[(x >> 0) & 15];
    cout << ' ';
}

void print(int iw, int ib, int ow, int ob, int add, int &ip, int data = 0) {
    print_hex(iw << 4 | ib);
    print_hex(ow << 4 | ob);
    print_hex(add);
    print_hex(data);
    ip += 4;
}

bool simulate(int x, int y) {
    vector<bitset<16>> v = machine;
    while (v.size() < (1 << 12)) {
        v.push_back(0);
    }
    v.back() = y;
    int ip = 0;
    rep(i, 0, (1 << 12)) {
        // cout << ip << ' ';
        int a = v[ip].to_ullong(), b = v[ip + 1].to_ullong();
        v[b >> 4][b & 15] = v[a >> 4][a & 15];
        ip = v[ip + 2].to_ullong();
        if (ip >= (1 << 12) - 2) {
            // cout << i << ' ' << y << endl;
            return v.back()[0] == (x == y);
        }
    }
    cout << endl;
    return false;
}

void solve() {
    int x;
    cin >> x;

    int io = 0xfff;
    int ip = 0;
    rep(i, 0, 16) {
        print(io, i, ip + 2, 3, ip + 4, ip);
        print(ip + 3, 0, io, i, ip + 12, ip, x >> i & 1);
        print(0, 0, 0, 0, 0, ip);
        print(ip + 3, 0, io, i, ip + 4, ip, !(x >> i & 1));
    }
    rep(i, 0, 16) {
        print(io, i, ip + 2, 7, ip + 4, ip);
    }
    print(ip + 3, 0, io, 0, io - 1, ip, 1);
    rep(i, 0, 16) {
        print(0, 0, 0, 0, 0, ip);
    }
    rep(i, 0, 16) {
        print(ip + 3, 0, io, 0, io - 1, ip, 0);
    }

    // cout << endl;
    // assert(simulate(x, 32768));
    // assert(simulate(x, x));
    // rep(i, 0, 10) {
    //     int y = rand();
    //     assert(simulate(x, rand() % (1 << 16)));
    // }
}

signed main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t = 1;
	// cin >> t;
	while (t--) solve();
}
