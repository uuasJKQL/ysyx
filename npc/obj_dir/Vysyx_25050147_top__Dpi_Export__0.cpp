// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Implementation of DPI export functions.
//
#include "Vysyx_25050147_top.h"
#include "Vysyx_25050147_top__Syms.h"
#include "verilated_dpi.h"


void Vysyx_25050147_top::read_ebreak(svBit* if_noebreak) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vysyx_25050147_top___024root::read_ebreak\n"); );
    // Init
    CData/*0:0*/ if_noebreak__Vcvt;
    if_noebreak__Vcvt = 0;
    // Body
    static int __Vfuncnum = -1;
    if (VL_UNLIKELY(__Vfuncnum == -1)) __Vfuncnum = Verilated::exportFuncNum("read_ebreak");
    const VerilatedScope* __Vscopep = Verilated::dpiScope();
    Vysyx_25050147_top__Vcb_read_ebreak_t __Vcb = (Vysyx_25050147_top__Vcb_read_ebreak_t)(VerilatedScope::exportFind(__Vscopep, __Vfuncnum));
    (*__Vcb)((Vysyx_25050147_top__Syms*)(__Vscopep->symsp()), if_noebreak__Vcvt);
    for (size_t if_noebreak__Vidx = 0; if_noebreak__Vidx < 1; ++if_noebreak__Vidx) *if_noebreak = if_noebreak__Vcvt;
}
