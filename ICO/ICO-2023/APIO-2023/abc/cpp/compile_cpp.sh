#!/bin/bash

problem=abc

g++ -std=gnu++17 -O2 -pipe -static -o $problem grader.cpp $problem.cpp
