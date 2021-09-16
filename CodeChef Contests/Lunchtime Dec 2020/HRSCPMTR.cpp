<<<<<<< HEAD
#include <bits/stdc++.h>
using namespace std;
#define range(i, s, n) for (int i = s; i < n; i++)
#define len(a) (*(&a + 1) - a)
#define print(x) cout << x << endl;
#define println(...) printf(__VA_ARGS__); printf("\n");
#define input(type, x) type x; cin >> x;
#define arrput(type, var, n) type var[n]; range(inputCount, 0, n) {cin >> var[inputCount];}
#define setup() ios::sync_with_stdio(false); cin.tie(0);

int n, m;
vector<vector<int>> mat;

bool isGood() { 
    range(i, 0, n) {
        int x = mat[i][0];
        range(j, 1, n - i) {
            if (mat[i + j][j] != x) {
                return false;
            }
        }
    }
    range(i, 1, m) {
        int x = mat[0][i];
        range(j, 1, m - i) {
            if (mat[j][i + j] != x) {
                return false;
            }
        }
    }
    return true;
}

int main() {
    setup();
    input(int, tc); while (tc--) {
        cin >> n >> m;

        mat = vector<vector<int>>(n);
        range(i, 0, n) {
            mat[i] = vector<int>(m);
            range(j, 0, m) {
                cin >> mat[i][j];
            }
        }

        input(int, q);
        range(i, 0, q) {
            input(int, x);
            input(int, y);
            input(int, v);

            mat[x - 1][y - 1] = v;

            print((isGood() ? "Yes": "No"));
        }
    }
=======
#include <bits/stdc++.h>
using namespace std;
#define range(i, s, n) for (int i = s; i < n; i++)
#define len(a) (*(&a + 1) - a)
#define print(x) cout << x << endl;
#define println(...) printf(__VA_ARGS__); printf("\n");
#define input(type, x) type x; cin >> x;
#define arrput(type, var, n) type var[n]; range(inputCount, 0, n) {cin >> var[inputCount];}
#define setup() ios::sync_with_stdio(false); cin.tie(0);

int n, m;
vector<vector<int>> mat;

bool isGood() { 
    range(i, 0, n) {
        int x = mat[i][0];
        range(j, 1, n - i) {
            if (mat[i + j][j] != x) {
                return false;
            }
        }
    }
    range(i, 1, m) {
        int x = mat[0][i];
        range(j, 1, m - i) {
            if (mat[j][i + j] != x) {
                return false;
            }
        }
    }
    return true;
}

int main() {
    setup();
    input(int, tc); while (tc--) {
        cin >> n >> m;

        mat = vector<vector<int>>(n);
        range(i, 0, n) {
            mat[i] = vector<int>(m);
            range(j, 0, m) {
                cin >> mat[i][j];
            }
        }

        input(int, q);
        range(i, 0, q) {
            input(int, x);
            input(int, y);
            input(int, v);

            mat[x - 1][y - 1] = v;

            print((isGood() ? "Yes": "No"));
        }
    }
>>>>>>> f6f46ae63ca36b9fa6e961ce3b0edb092483751d
}