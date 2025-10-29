// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vysyx_25050147_top.h for the primary calling header

#include "verilated.h"
#include "verilated_dpi.h"

#include "Vysyx_25050147_top___024root.h"

VL_ATTR_COLD void Vysyx_25050147_top___024root___eval_static(Vysyx_25050147_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vysyx_25050147_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vysyx_25050147_top___024root___eval_static\n"); );
}

VL_ATTR_COLD void Vysyx_25050147_top___024root___eval_initial(Vysyx_25050147_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vysyx_25050147_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vysyx_25050147_top___024root___eval_initial\n"); );
    // Body
    vlSelf->__Vtrigrprev__TOP__clk = vlSelf->clk;
}

VL_ATTR_COLD void Vysyx_25050147_top___024root___eval_final(Vysyx_25050147_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vysyx_25050147_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vysyx_25050147_top___024root___eval_final\n"); );
}

VL_ATTR_COLD void Vysyx_25050147_top___024root___eval_triggers__stl(Vysyx_25050147_top___024root* vlSelf);
#ifdef VL_DEBUG
VL_ATTR_COLD void Vysyx_25050147_top___024root___dump_triggers__stl(Vysyx_25050147_top___024root* vlSelf);
#endif  // VL_DEBUG
VL_ATTR_COLD void Vysyx_25050147_top___024root___eval_stl(Vysyx_25050147_top___024root* vlSelf);

VL_ATTR_COLD void Vysyx_25050147_top___024root___eval_settle(Vysyx_25050147_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vysyx_25050147_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vysyx_25050147_top___024root___eval_settle\n"); );
    // Init
    CData/*0:0*/ __VstlContinue;
    // Body
    vlSelf->__VstlIterCount = 0U;
    __VstlContinue = 1U;
    while (__VstlContinue) {
        __VstlContinue = 0U;
        Vysyx_25050147_top___024root___eval_triggers__stl(vlSelf);
        if (vlSelf->__VstlTriggered.any()) {
            __VstlContinue = 1U;
            if (VL_UNLIKELY((0x64U < vlSelf->__VstlIterCount))) {
#ifdef VL_DEBUG
                Vysyx_25050147_top___024root___dump_triggers__stl(vlSelf);
#endif
                VL_FATAL_MT("/home/wyh/ysyx-workbench/npc/vsrc/ysyx_25050147_top.v", 6, "", "Settle region did not converge.");
            }
            vlSelf->__VstlIterCount = ((IData)(1U) 
                                       + vlSelf->__VstlIterCount);
            Vysyx_25050147_top___024root___eval_stl(vlSelf);
        }
    }
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vysyx_25050147_top___024root___dump_triggers__stl(Vysyx_25050147_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vysyx_25050147_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vysyx_25050147_top___024root___dump_triggers__stl\n"); );
    // Body
    if ((1U & (~ (IData)(vlSelf->__VstlTriggered.any())))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if (vlSelf->__VstlTriggered.at(0U)) {
        VL_DBG_MSGF("         'stl' region trigger index 0 is active: Internal 'stl' trigger - first iteration\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void Vysyx_25050147_top___024root___stl_sequent__TOP__0(Vysyx_25050147_top___024root* vlSelf);

VL_ATTR_COLD void Vysyx_25050147_top___024root___eval_stl(Vysyx_25050147_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vysyx_25050147_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vysyx_25050147_top___024root___eval_stl\n"); );
    // Body
    if (vlSelf->__VstlTriggered.at(0U)) {
        Vysyx_25050147_top___024root___stl_sequent__TOP__0(vlSelf);
        vlSelf->__Vm_traceActivity[1U] = 1U;
        vlSelf->__Vm_traceActivity[0U] = 1U;
    }
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vysyx_25050147_top___024root___dump_triggers__act(Vysyx_25050147_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vysyx_25050147_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vysyx_25050147_top___024root___dump_triggers__act\n"); );
    // Body
    if ((1U & (~ (IData)(vlSelf->__VactTriggered.any())))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if (vlSelf->__VactTriggered.at(0U)) {
        VL_DBG_MSGF("         'act' region trigger index 0 is active: @(posedge clk)\n");
    }
}
#endif  // VL_DEBUG

#ifdef VL_DEBUG
VL_ATTR_COLD void Vysyx_25050147_top___024root___dump_triggers__nba(Vysyx_25050147_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vysyx_25050147_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vysyx_25050147_top___024root___dump_triggers__nba\n"); );
    // Body
    if ((1U & (~ (IData)(vlSelf->__VnbaTriggered.any())))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if (vlSelf->__VnbaTriggered.at(0U)) {
        VL_DBG_MSGF("         'nba' region trigger index 0 is active: @(posedge clk)\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void Vysyx_25050147_top___024root___ctor_var_reset(Vysyx_25050147_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vysyx_25050147_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vysyx_25050147_top___024root___ctor_var_reset\n"); );
    // Body
    vlSelf->rst = VL_RAND_RESET_I(1);
    vlSelf->clk = VL_RAND_RESET_I(1);
    vlSelf->pc = VL_RAND_RESET_I(32);
    vlSelf->ysyx_25050147_top__DOT__mem = VL_RAND_RESET_I(32);
    vlSelf->ysyx_25050147_top__DOT__waddr_mem = VL_RAND_RESET_I(32);
    vlSelf->ysyx_25050147_top__DOT__rdata1 = VL_RAND_RESET_I(32);
    vlSelf->ysyx_25050147_top__DOT__rdata2 = VL_RAND_RESET_I(32);
    vlSelf->ysyx_25050147_top__DOT__dnpc = VL_RAND_RESET_I(32);
    vlSelf->ysyx_25050147_top__DOT__op_type = VL_RAND_RESET_I(5);
    vlSelf->ysyx_25050147_top__DOT__src1 = VL_RAND_RESET_I(32);
    vlSelf->ysyx_25050147_top__DOT__src2 = VL_RAND_RESET_I(32);
    vlSelf->ysyx_25050147_top__DOT__inst = VL_RAND_RESET_I(32);
    vlSelf->ysyx_25050147_top__DOT__alu_op = VL_RAND_RESET_I(4);
    for (int __Vi0 = 0; __Vi0 < 32; ++__Vi0) {
        vlSelf->ysyx_25050147_top__DOT__rfile__DOT__rf[__Vi0] = VL_RAND_RESET_I(32);
    }
    vlSelf->ysyx_25050147_top__DOT__exu__DOT__myalu__DOT__result = VL_RAND_RESET_I(32);
    vlSelf->ysyx_25050147_top__DOT__exu__DOT__myalu__DOT__Result = VL_RAND_RESET_I(32);
    vlSelf->ysyx_25050147_top__DOT__exu__DOT__myalu__DOT__t_no_Cin = VL_RAND_RESET_I(32);
    vlSelf->ysyx_25050147_top__DOT__exu__DOT__myalu__DOT__Carry = VL_RAND_RESET_I(1);
    vlSelf->ysyx_25050147_top__DOT__exu__DOT__myalu__DOT__Cin = VL_RAND_RESET_I(1);
    vlSelf->ysyx_25050147_top__DOT__exu__DOT__myalu__DOT__is_branch = VL_RAND_RESET_I(1);
    vlSelf->ysyx_25050147_top__DOT__exu__DOT__myalu__DOT____VdfgExtracted_hf56215be__0 = VL_RAND_RESET_I(1);
    vlSelf->ysyx_25050147_top__DOT__idu__DOT__op_src2_I = VL_RAND_RESET_I(32);
    vlSelf->__Vfunc_pmem_read__0__Vfuncout = 0;
    vlSelf->__Vfunc_pmem_read__3__Vfuncout = 0;
    vlSelf->__Vtableidx1 = 0;
    vlSelf->__Vtrigrprev__TOP__clk = VL_RAND_RESET_I(1);
    for (int __Vi0 = 0; __Vi0 < 2; ++__Vi0) {
        vlSelf->__Vm_traceActivity[__Vi0] = 0;
    }
}
