#!/bin/bash

MAINDIR=`pwd`
PART1=first_steps
PART2=part2

cd $PART1
make
cd $MAINDIR

cd $PART2
make
cd $MAINDIR
