#! /bin/bash

echo $1 $2
mkdir -p $1/$2 && cp Makefile $1/$2
touch $1/$2/$2.cpp