#include <bits/stdc++.h>
#define print(x) printf("%d\n", x);
#define printd(x) printf("%f\n", x);
#define println(...) printf(__VA_ARGS__); printf("\n");
#define range(i, n) for (int i = 0; i < n; i++)
#define reverseRange(i, n) for (int i = n - 1; i >= 0; i++)
#define stepRange(i, n, s) for (int i = 0; i < n; i += s)
#define len(a) (*(&a + 1) - a)

int main() {
    int variable = 10;
    int *pointer = &variable;

    println("Address: %d", pointer);
    println("Value: %d", *pointer);

    variable = 20;
    println("Updated Value: %d", *pointer); //20

    println("");

    //Pointers with Arrays
    int array[5] = {65, 6516, 51, 21, 7};
    int *arrayPointer;
    arrayPointer = array;
    range(i, len(array)) {
        println("The value at index %d: %d", i, *arrayPointer);
        arrayPointer++;
    }
}
