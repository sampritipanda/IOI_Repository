#!/bin/sh

gcc koala.c grader.c -o koala -O2 -static -lm -std=c11
