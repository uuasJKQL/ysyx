// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Implementation of DPI export functions.
//
#include "Vysyx_25050147_top.h"
#include "Vysyx_25050147_top__Syms.h"
#include "verilated_dpi.h"


svBit Vysyx_25050147_top::read_ebreak() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vysyx_25050147_top___024root::read_ebreak\n"); );
    // Init
    CData/*0:0*/ read_ebreak__Vfuncrtn__Vcvt;
    read_ebreak__Vfuncrtn__Vcvt = 0;
    // Body
    static int __Vfuncnum = -1;
    if (VL_UNLIKELY(__Vfuncnum == -1)) __Vfuncnum = Verilated::exportFuncNum("read_ebreak");
    const VerilatedScope* __Vscopep = Verilated::dpiScope();
    Vysyx_25050147_top__Vcb_read_ebreak_t __Vcb = (Vysyx_25050147_top__Vcb_read_ebreak_t)(VerilatedScope::exportFind(__Vscopep, __Vfuncnum));
    (*__Vcb)((Vysyx_25050147_top__Syms*)(__Vscopep->symsp()), read_ebreak__Vfuncrtn__Vcvt);
    svBit read_ebreak__Vfuncrtn;
    for (size_t read_ebreak__Vfuncrtn__Vidx = 0; read_ebreak__Vfuncrtn__Vidx < 1; ++read_ebreak__Vfuncrtn__Vidx) read_ebreak__Vfuncrtn = read_ebreak__Vfuncrtn__Vcvt;
    return read_ebreak__Vfuncrtn;
}
