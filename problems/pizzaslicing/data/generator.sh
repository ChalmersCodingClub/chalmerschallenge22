#!/usr/bin/env bash
USE_SCORING=0
. ../../../testdata_tools/gen.sh

use_solution loke.cpp

compile gen.py

sample 1
sample 2

tc t01 gen MaxD=1
tc t02 gen MaxD=1
tc t03 gen MaxAB=10
tc t04 gen MaxAB=10
tc t05 gen MaxAB=1
tc t06 gen MaxD=1 MaxAB=1
tc t07 gen MaxD=1 MaxAB=1
tc t08 gen
tc t09 gen
tc t10 gen
tc t11 gen
tc t12 gen
tc t13 gen
tc t14 gen
tc t15 gen
tc t16 gen
tc t17 gen
tc t18 gen
tc t19 gen
