#include "abc.h"
#include <bits/stdc++.h>
using namespace std;
template<typename T> inline void input(T& inVar) {cin >> inVar;}
template<typename T, typename... S> inline void input(T& inVar, S&... args) {cin >> inVar; input(args ...);}
template<typename T> inline void print(T outVar) {cout << outVar << '\n';}
template<typename T, typename... S> inline void print(T outVar, S... args) {cout << outVar << ' '; print(args ...);}
#define range(it, start, end) for (auto it = start; it < end; it++)
#define arrPut(var) for (auto &inVar : var) {cin >> inVar;}
#define arrPrint(var) for (auto outVar : var) {cout << outVar << ' ';} cout << '\n'
#define setup() ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

// you may find the definitions useful
const int OP_ZERO    = 0;  // f(OP_ZERO,    x0, x1) = 0
const int OP_NOR     = 1;  // f(OP_NOR,     x0, x1) = !(x0 || x1)
const int OP_GREATER = 2;  // f(OP_GREATER, x0, x1) = (x0 > x1)
const int OP_NOT_X1  = 3;  // f(OP_NOT_X1,  x0, x1) = !x1
const int OP_LESS    = 4;  // f(OP_LESS,    x0, x1) = (x0 < x1)
const int OP_NOT_X0  = 5;  // f(OP_NOT_X0,  x0, x1) = !x0
const int OP_XOR     = 6;  // f(OP_XOR,     x0, x1) = (x0 ^ x1)
const int OP_NAND    = 7;  // f(OP_NAND,    x0, x1) = !(x0 && x1)
const int OP_AND     = 8;  // f(OP_AND,     x0, x1) = (x0 && x1)
const int OP_EQUAL   = 9;  // f(OP_EQUAL,   x0, x1) = (x0 == x1)
const int OP_X0      = 10; // f(OP_X0,      x0, x1) = x0
const int OP_GEQ     = 11; // f(OP_GEQ,     x0, x1) = (x0 >= x1)
const int OP_X1      = 12; // f(OP_X1,      x0, x1) = x1
const int OP_LEQ     = 13; // f(OP_LEQ,     x0, x1) = (x0 <= x1)
const int OP_OR      = 14; // f(OP_OR,      x0, x1) = (x0 || x1)
const int OP_ONE     = 15; // f(OP_ONE,     x0, x1) = 1


// Alice
int // returns la
alice(
    /*  in */ const int n,
    /*  in */ const char names[][5],
    /*  in */ const unsigned short numbers[],
    /* out */ bool outputs_alice[]
) {
    outputs_alice[0] = 0;
    outputs_alice[1] = 0;
    return 2;
}

// Bob
int // returns lb
bob(
    /*  in */ const int m,
    /*  in */ const char senders[][5],
    /*  in */ const char recipients[][5],
    /* out */ bool outputs_bob[]
) {
    return 0;
}


// Circuit
int // returns l
circuit(
    /*  in */ const int la,
    /*  in */ const int lb,
    /* out */ int operations[],
    /* out */ int operands[][2],
    /* out */ int outputs_circuit[][16]
) {
    // outputs_circuit = new int[][16];
    operations[2] = 10;
    operands[2][0] = 0;
    operands[2][1] = 1;
    range(i, 0, 16) {
        outputs_circuit[0][i] = la + lb;
    }
    return la + lb + 1;
}

#include "grader.cpp"
