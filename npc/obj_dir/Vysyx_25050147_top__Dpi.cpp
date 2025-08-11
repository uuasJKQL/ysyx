// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Implementation of DPI export functions.
//
// Verilator compiles this file in when DPI functions are used.
// If you have multiple Verilated designs with the same DPI exported
// function names, you will get multiple definition link errors from here.
// This is an unfortunate result of the DPI specification.
// To solve this, either
//    1. Call Vysyx_25050147_top::{export_function} instead,
//       and do not even bother to compile this file
// or 2. Compile all __Dpi.cpp files in the same compiler run,
//       and #ifdefs already inserted here will sort everything out.

#include "Vysyx_25050147_top__Dpi.h"
#include "Vysyx_25050147_top.h"

#ifndef VL_DPIDECL_read_ebreak_
#define VL_DPIDECL_read_ebreak_
void read_ebreak(svBit* if_noebreak) {
    // DPI export at /home/wyh/ysyx-workbench/npc/vsrc/ysyx_25050147_top.v:59:6
    return Vysyx_25050147_top::read_ebreak(if_noebreak);
}
#endif

