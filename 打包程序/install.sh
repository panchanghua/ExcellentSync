#!/bin/sh

exe="first_project" #发布的程序名称
des="/home/pan/Desktop/build-first_project-Desktop_Qt-Release/" #你的路径

deplist=$(ldd $exe | awk  '{if (match($3,"/")){ printf("%s "),$3 } }')
cp $deplist $des

