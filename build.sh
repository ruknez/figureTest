#!/bin/bash


mkdir build || exit 1
cp fileWithData build || exit 2
cd build && cmake .. || exit 3
make || exit 4
