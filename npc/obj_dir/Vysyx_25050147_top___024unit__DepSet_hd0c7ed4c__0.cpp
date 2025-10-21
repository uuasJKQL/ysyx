// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vysyx_25050147_top.h for the primary calling header

#include "verilated.h"
#include "verilated_dpi.h"

#include "Vysyx_25050147_top__Syms.h"
#include "Vysyx_25050147_top___024unit.h"

extern "C" void notify_ebreak();

VL_INLINE_OPT void Vysyx_25050147_top___024unit____Vdpiimwrap_notify_ebreak_TOP____024unit() {
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vysyx_25050147_top___024unit____Vdpiimwrap_notify_ebreak_TOP____024unit\n"); );
    // Body
    notify_ebreak();
}

extern "C" void update_shadow_register(int index, const svBitVecVal* value);

VL_INLINE_OPT void Vysyx_25050147_top___024unit____Vdpiimwrap_update_shadow_register_TOP____024unit(IData/*31:0*/ index, IData/*31:0*/ value) {
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vysyx_25050147_top___024unit____Vdpiimwrap_update_shadow_register_TOP____024unit\n"); );
    // Body
    int index__Vcvt;
    for (size_t index__Vidx = 0; index__Vidx < 1; ++index__Vidx) index__Vcvt = index;
    svBitVecVal value__Vcvt[1];
    for (size_t value__Vidx = 0; value__Vidx < 1; ++value__Vidx) VL_SET_SVBV_I(32, value__Vcvt + 1 * value__Vidx, value);
    update_shadow_register(index__Vcvt, value__Vcvt);
}
