#!/usr/bin/env bash
USE_SCORING=0
. ../../../testdata_tools/gen.sh

use_solution loke.cpp

compile gen.py

sample 1
sample 2

tc t01 gen
tc t02 gen
tc t03 gen
tc t04 gen
tc t05 gen
tc t06 gen
tc t07 gen
tc t08 gen
tc t09 gen
