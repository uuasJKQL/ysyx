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
