#!/bin/bash

cd Source
make clean
make
mv mmprog ..
make clean
cd ..
clear
./mmprog
rm -rf mmprog .DS_Store
