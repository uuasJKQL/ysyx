// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vysyx_25050147_top.h for the primary calling header

#include "verilated.h"
#include "verilated_dpi.h"

#include "Vysyx_25050147_top__Syms.h"
#include "Vysyx_25050147_top___024unit.h"

extern "C" int pmem_read(int raddr);

VL_INLINE_OPT void Vysyx_25050147_top___024unit____Vdpiimwrap_pmem_read_TOP____024unit(IData/*31:0*/ raddr, IData/*31:0*/ &pmem_read__Vfuncrtn) {
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vysyx_25050147_top___024unit____Vdpiimwrap_pmem_read_TOP____024unit\n"); );
    // Body
    int raddr__Vcvt;
    for (size_t raddr__Vidx = 0; raddr__Vidx < 1; ++raddr__Vidx) raddr__Vcvt = raddr;
    int pmem_read__Vfuncrtn__Vcvt;
    pmem_read__Vfuncrtn__Vcvt = pmem_read(raddr__Vcvt);
    pmem_read__Vfuncrtn = pmem_read__Vfuncrtn__Vcvt;
}

extern "C" void pmem_write(int waddr, int wdata, char wmask);

VL_INLINE_OPT void Vysyx_25050147_top___024unit____Vdpiimwrap_pmem_write_TOP____024unit(IData/*31:0*/ waddr, IData/*31:0*/ wdata, CData/*7:0*/ wmask) {
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vysyx_25050147_top___024unit____Vdpiimwrap_pmem_write_TOP____024unit\n"); );
    // Body
    int waddr__Vcvt;
    for (size_t waddr__Vidx = 0; waddr__Vidx < 1; ++waddr__Vidx) waddr__Vcvt = waddr;
    int wdata__Vcvt;
    for (size_t wdata__Vidx = 0; wdata__Vidx < 1; ++wdata__Vidx) wdata__Vcvt = wdata;
    char wmask__Vcvt;
    for (size_t wmask__Vidx = 0; wmask__Vidx < 1; ++wmask__Vidx) wmask__Vcvt = wmask;
    pmem_write(waddr__Vcvt, wdata__Vcvt, wmask__Vcvt);
}

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
