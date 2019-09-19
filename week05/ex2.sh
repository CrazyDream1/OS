#!/bin/sh
x = `tail -1 file.txt`
expr $x + 1 >> file.txt
