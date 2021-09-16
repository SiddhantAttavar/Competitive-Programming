#include <bits/stdc++.h>
using namespace std;
#define range(i, s, n) for (int i = s; i < n; i++)
#define len(a) (*(&a + 1) - a)
#define print(x) cout << x << endl;
#define input(type, x) type x; cin >> x;
#define arrput(type, var, n) type var[n]; range(inputCount, 0, n) {cin >> var[inputCount];}
#define setup() ios::sync_with_stdio(false); cin.tie(0);

const int MOD = 20011;
vector<vector<vector<vector<int>>>> memo;
vector<vector<bool>> mat;
int r, c, d;

int solve(int i, int j, int x, int dir) {
    if (i == r || j == c || x > d || !mat[i][j]) {
        return 0;
    }

    if (i == (r - 1) && j == (c - 1)) {
        return 1;
    }
    
    if (memo[i][j][x][dir] != -1) {
        return memo[i][j][x][dir];
    }

    if (dir == 0) {
        memo[i][j][x][0] = (solve(i + 1, j, x + 1, 0) + solve(i, j + 1, 1, 1)) % MOD;
    }
    else {
        memo[i][j][x][1] = (solve(i + 1, j, 1, 0) + solve(i, j + 1, x + 1, 1)) % MOD;
    }

    return memo[i][j][x][dir];
}

int main() {
    setup();
    cin >> r >> c >> d;
    
    mat = vector<vector<bool>>(r);
    range(i, 0, r) {
        mat[i] = vector<bool>(c);
        range(j, 0, c) {
            int x;
            cin >> x;
            mat[i][j] = (x == 1);
        }
    }
    
    memo = vector<vector<vector<vector<int>>>>(r);
    range(i, 0, r) {
        memo[i] = vector<vector<vector<int>>>(c);
        range(j, 0, c) {
            memo[i][j] = vector<vector<int>>(d + 1);
            range(k, 0, d + 1) {
                memo[i][j][k] = vector<int>(2);
                memo[i][j][k][0] = -1;
                memo[i][j][k][1] = -1;
            }
        }
    }
    
    print(solve(0, 0, 0, 0));
}