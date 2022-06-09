#! /bin/bash

# Get answer

path="/backup/save/ProblemSolving"

if [ "$1" -a "$2" ]
then
    folder=$1
    filename=$2
else
    echo "Which would you like? "
    echo "1. Baekjoon "
    echo "2. Leetcode "
    echo "3. Programmers "
    read answer
    case ${answer} in
    1) folder="baekjoon";;
    2) folder="leetcode";;
    3) folder="programmers";;
    esac
    echo ${folder}
    echo "Problem Name "
    read filename
fi
echo $1 $2
echo ${folder} ${filename}
mkdir -p ${path}/${folder}/${filename}
cp ${path}/Makefile ${path}/${folder}/${filename}
cp ${path}/emptyfile ${path}/${folder}/${filename}/${filename}.cpp
cd ${path}/${folder}/${filename}
# mkdir -p $1/$2 && cp Makefile $1/$2
# touch $1/$2/$2.cpp
# cp emptyfile $1/$2/$2.cpp