#!/bin/bash

problem=pyramids

g++ -std=gnu++14 -O2 -pipe -static -o $problem grader.cpp $problem.cpp
