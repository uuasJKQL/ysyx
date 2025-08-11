// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vysyx_25050147_top.h for the primary calling header

#include "verilated.h"

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
                VL_FATAL_MT("/home/wyh/ysyx-workbench/npc/vsrc/ysyx_25050147_top.v", 1, "", "Settle region did not converge.");
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

VL_ATTR_COLD void Vysyx_25050147_top___024root___stl_sequent__TOP__0(Vysyx_25050147_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vysyx_25050147_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vysyx_25050147_top___024root___stl_sequent__TOP__0\n"); );
    // Body
    vlSelf->ysyx_25050147_top__DOT__snpc = ((IData)(4U) 
                                            + vlSelf->pc);
    if ((1U == ((0x98U == ((0x3f8U & (vlSelf->mem << 3U)) 
                           | (7U & (vlSelf->mem >> 0xcU))))
                 ? 1U : ((0x11U == ((0x3f8U & (vlSelf->mem 
                                               << 3U)) 
                                    | (7U & (vlSelf->mem 
                                             >> 0xcU))))
                          ? ((0x20U == ((0x20U & (vlSelf->mem 
                                                  >> 0xaU)) 
                                        | (0x1fU & 
                                           (vlSelf->mem 
                                            >> 7U))))
                              ? 2U : 0U) : 0U)))) {
        vlSelf->ysyx_25050147_top__DOT__result = ((
                                                   ((- (IData)(
                                                               (vlSelf->mem 
                                                                >> 0x1fU))) 
                                                    << 0xcU) 
                                                   | (vlSelf->mem 
                                                      >> 0x14U)) 
                                                  + 
                                                  vlSelf->ysyx_25050147_top__DOT__rfile__DOT__rf
                                                  [
                                                  (0x1fU 
                                                   & (vlSelf->mem 
                                                      >> 0xfU))]);
    }
}

VL_ATTR_COLD void Vysyx_25050147_top___024root___eval_stl(Vysyx_25050147_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vysyx_25050147_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vysyx_25050147_top___024root___eval_stl\n"); );
    // Body
    if (vlSelf->__VstlTriggered.at(0U)) {
        Vysyx_25050147_top___024root___stl_sequent__TOP__0(vlSelf);
    }
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vysyx_25050147_top___024root___dump_triggers__ico(Vysyx_25050147_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vysyx_25050147_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vysyx_25050147_top___024root___dump_triggers__ico\n"); );
    // Body
    if ((1U & (~ (IData)(vlSelf->__VicoTriggered.any())))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if (vlSelf->__VicoTriggered.at(0U)) {
        VL_DBG_MSGF("         'ico' region trigger index 0 is active: Internal 'ico' trigger - first iteration\n");
    }
}
#endif  // VL_DEBUG

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
    vlSelf->mem = VL_RAND_RESET_I(32);
    vlSelf->rst = VL_RAND_RESET_I(1);
    vlSelf->clk = VL_RAND_RESET_I(1);
    vlSelf->pc = VL_RAND_RESET_I(32);
    vlSelf->ysyx_25050147_top__DOT__snpc = VL_RAND_RESET_I(32);
    vlSelf->ysyx_25050147_top__DOT__result = VL_RAND_RESET_I(32);
    for (int __Vi0 = 0; __Vi0 < 32; ++__Vi0) {
        vlSelf->ysyx_25050147_top__DOT__rfile__DOT__rf[__Vi0] = VL_RAND_RESET_I(32);
    }
    vlSelf->__Vtrigrprev__TOP__clk = VL_RAND_RESET_I(1);
    for (int __Vi0 = 0; __Vi0 < 2; ++__Vi0) {
        vlSelf->__Vm_traceActivity[__Vi0] = 0;
    }
}
