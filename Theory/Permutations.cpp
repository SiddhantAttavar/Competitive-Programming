#include <bits/stdc++.h>
using namespace std;
#define range(i, s, n) for (int i = s; i < n; i++)
#define len(a) (*(&a + 1) - a)
#define print(x) printf("%d\n", x);
#define println(...) printf(__VA_ARGS__); printf("\n");
#define input(type, x) type x; cin >> x;
#define arrput(type, var, n) type var[n]; range(inputCount, 0, n) {cin >> var[inputCount];}

int main() {
    input(int, n);
    arrput(int, a, n);

    sort(a, a + n);

    int total = 1;
    range(i, 2, n + 1) {
        total *= i;
    }

    range(i, 1, total) {
        for (int j: a) {
            printf("%d ", j);
        }
        println("");

        int x = n - 2;
        while (a[x] >= a[x + 1]) {
            x--;
        }

        int low = x + 1;
        int high = n - 1;
        while (low < high) {
            if ((high - low) == 1) {
                if (a[high] > a[x] && a[high] < a[low]) {
                    low = high;
                }
                break;
            }

            int mid = (low + high) / 2;
            if (a[mid] > a[x]) {
                low = mid;
            }
            else {
                high = mid - 1;
            }
        }
        
        int temp = a[x];
        a[x] = a[low];
        a[low] = temp;

        reverse(a + x + 1, a + n);
    }

    for (int j: a) {
        printf("%d ", j);
    }
    println("");
}