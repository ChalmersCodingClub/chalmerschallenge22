#!/usr/bin/env bash

. ../../../testdata_tools/gen.sh

use_solution victor_py3.py

compile gen.py

group group1 9
tc 1
tc g1_1 gen
tc g1_2 gen
tc g1_3 gen
tc g1_4 gen
tc g1_5 gen
tc g1_6 gen
tc g1_7 gen
tc g1_8 gen
tc g1_9 gen
