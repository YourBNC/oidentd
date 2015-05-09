#!/bin/bash
cd $(dirname $0)/src
bison -o oidentd_cfg_parse.c --defines=oidentd_cfg_parse.h oidentd_cfg_parse.y
lex -o oidentd_cfg_scan.c oidentd_cfg_scan.l
