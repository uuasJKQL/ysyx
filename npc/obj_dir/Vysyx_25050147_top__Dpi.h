// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Prototypes for DPI import and export functions.
//
// Verilator includes this file in all generated .cpp files that use DPI functions.
// Manually include this file where DPI .c import functions are declared to ensure
// the C functions match the expectations of the DPI imports.

#ifndef VERILATED_VYSYX_25050147_TOP__DPI_H_
#define VERILATED_VYSYX_25050147_TOP__DPI_H_  // guard

#include "svdpi.h"

#ifdef __cplusplus
extern "C" {
#endif


    // DPI IMPORTS
    // DPI import at /home/wyh/ysyx-workbench/npc/vsrc/ysyx_25050147_top.v:1:30
    extern void notify_ebreak();
    // DPI import at /home/wyh/ysyx-workbench/npc/vsrc/ysyx_25050147_IFU.v:1:29
    extern int pmem_read(int raddr);
    // DPI import at /home/wyh/ysyx-workbench/npc/vsrc/ysyx_25050147_IFU.v:2:30
    extern void pmem_write(int waddr, int wdata, char wmask);
    // DPI import at /home/wyh/ysyx-workbench/npc/vsrc/ysyx_25050147_top.v:2:30
    extern void update_shadow_register(int index, const svBitVecVal* value);

#ifdef __cplusplus
}
#endif

#endif  // guard
