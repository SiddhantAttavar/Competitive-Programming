#include <bits/stdc++.h>
using namespace std; typedef long long ll; typedef vector<int> vi;
template<typename T> inline void input(T& inVar) {cin >> inVar;}
template<typename T, typename... S> inline void input(T& inVar, S&... args) {cin >> inVar; input(args ...);}
template<typename T> inline void print(T outVar) {cout << outVar << endl;}
template<typename T, typename... S> inline void print(T outVar, S... args) {cout << outVar << ' '; print(args ...);}
#define range(it, start, end) for (int it = start; it < end; it++)
#define arrPut(var) for (auto &inVar : var) {cin >> inVar;}
#define arrPrint(var) for (auto outVar : var) {cout << outVar << ' ';} cout << endl
#define setup() ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define int ll
#define double long double

signed main() {
    setup(); int tc; input(tc); while (tc--) {
        int n; input(n);
        int a[n], b[n];
        arrPut(a);
        arrPut(b);

        double r[n];
        range(i, 0, n) {
            r[i] = a[i] * 1.0 / b[i];
        }

        int prefSumB2[n + 1] = {0};
        range(i, 1, n + 1) {
            prefSumB2[i] = prefSumB2[i - 1] + b[i - 1] * b[i - 1];
        }

        int prefSumAB[n + 1] = {0};
        range(i, 1, n + 1) {
            prefSumAB[i] = prefSumAB[i - 1] + a[i - 1] * b[i - 1];
        }

        //arrPrint(prefSumB2);
        //arrPrint(prefSumAB);

        range(i, 1, n) {
            if (r[i - 1] >= r[i]) {
                continue;
            }

            double fin = -1;
            for (int j = i - 1; j >= -1; j--) {
                fin = (prefSumAB[i + 1] * 1.0 - prefSumAB[j + 1]) / (prefSumB2[i + 1] - prefSumB2[j + 1]);
                if (j == -1 || r[j] >= fin) {
                    range(u, j + 1, i + 1) {
                        r[u] = fin;
                    }
                    break;
                }
            }
        }

        double res = 0;
        range(i, 0, n) {
            res += (a[i] - r[i] * b[i]) * (a[i] - r[i] * b[i]);
        }

        cout << setprecision(10) << fixed << res << endl;
    }
}