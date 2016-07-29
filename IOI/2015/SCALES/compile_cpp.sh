#!/bin/bash

problem=scales

g++ -DEVAL -static -std=c++11 -g -o $problem -Wall -Wshadow -Wextra -Wconversion grader.cpp $problem.cpp
