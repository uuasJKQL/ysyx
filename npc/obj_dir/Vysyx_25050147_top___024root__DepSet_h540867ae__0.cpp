// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vysyx_25050147_top.h for the primary calling header

#include "verilated.h"
#include "verilated_dpi.h"

#include "Vysyx_25050147_top___024root.h"

VL_INLINE_OPT void Vysyx_25050147_top___024root___ico_sequent__TOP__0(Vysyx_25050147_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vysyx_25050147_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vysyx_25050147_top___024root___ico_sequent__TOP__0\n"); );
    // Body
    vlSelf->ysyx_25050147_top__DOT__idu__DOT__op_src1_I 
        = (((- (IData)((vlSelf->mem >> 0x1fU))) << 0xcU) 
           | (vlSelf->mem >> 0x14U));
    vlSelf->ysyx_25050147_top__DOT__rdata = vlSelf->ysyx_25050147_top__DOT__rfile__DOT__rf
        [(0x1fU & (vlSelf->mem >> 0xfU))];
    if ((0x40U & vlSelf->mem)) {
        if ((0x20U & vlSelf->mem)) {
            if ((0x10U & vlSelf->mem)) {
                vlSelf->ysyx_25050147_top__DOT__op_type = 0U;
                vlSelf->ysyx_25050147_top__DOT__src1 = 0U;
                vlSelf->ysyx_25050147_top__DOT__src2 = 0U;
            } else if ((8U & vlSelf->mem)) {
                if ((4U & vlSelf->mem)) {
                    if ((2U & vlSelf->mem)) {
                        if ((1U & vlSelf->mem)) {
                            vlSelf->ysyx_25050147_top__DOT__op_type = 1U;
                            vlSelf->ysyx_25050147_top__DOT__src1 
                                = (((- (IData)((vlSelf->mem 
                                                >> 0x1fU))) 
                                    << 0x14U) | ((0xff000U 
                                                  & vlSelf->mem) 
                                                 | ((0x800U 
                                                     & (vlSelf->mem 
                                                        >> 9U)) 
                                                    | (0x7feU 
                                                       & (vlSelf->mem 
                                                          >> 0x14U)))));
                            vlSelf->ysyx_25050147_top__DOT__src2 
                                = vlSelf->pc;
                        } else {
                            vlSelf->ysyx_25050147_top__DOT__op_type = 0U;
                            vlSelf->ysyx_25050147_top__DOT__src1 = 0U;
                            vlSelf->ysyx_25050147_top__DOT__src2 = 0U;
                        }
                    } else {
                        vlSelf->ysyx_25050147_top__DOT__op_type = 0U;
                        vlSelf->ysyx_25050147_top__DOT__src1 = 0U;
                        vlSelf->ysyx_25050147_top__DOT__src2 = 0U;
                    }
                } else {
                    vlSelf->ysyx_25050147_top__DOT__op_type = 0U;
                    vlSelf->ysyx_25050147_top__DOT__src1 = 0U;
                    vlSelf->ysyx_25050147_top__DOT__src2 = 0U;
                }
            } else if ((4U & vlSelf->mem)) {
                if ((2U & vlSelf->mem)) {
                    if ((1U & vlSelf->mem)) {
                        vlSelf->ysyx_25050147_top__DOT__op_type = 1U;
                        vlSelf->ysyx_25050147_top__DOT__src1 
                            = vlSelf->ysyx_25050147_top__DOT__idu__DOT__op_src1_I;
                        vlSelf->ysyx_25050147_top__DOT__src2 
                            = vlSelf->ysyx_25050147_top__DOT__rdata;
                    } else {
                        vlSelf->ysyx_25050147_top__DOT__op_type = 0U;
                        vlSelf->ysyx_25050147_top__DOT__src1 = 0U;
                        vlSelf->ysyx_25050147_top__DOT__src2 = 0U;
                    }
                } else {
                    vlSelf->ysyx_25050147_top__DOT__op_type = 0U;
                    vlSelf->ysyx_25050147_top__DOT__src1 = 0U;
                    vlSelf->ysyx_25050147_top__DOT__src2 = 0U;
                }
            } else {
                vlSelf->ysyx_25050147_top__DOT__op_type = 0U;
                vlSelf->ysyx_25050147_top__DOT__src1 = 0U;
                vlSelf->ysyx_25050147_top__DOT__src2 = 0U;
            }
        } else {
            vlSelf->ysyx_25050147_top__DOT__op_type = 0U;
            vlSelf->ysyx_25050147_top__DOT__src1 = 0U;
            vlSelf->ysyx_25050147_top__DOT__src2 = 0U;
        }
    } else if ((0x20U & vlSelf->mem)) {
        if ((0x10U & vlSelf->mem)) {
            if ((8U & vlSelf->mem)) {
                vlSelf->ysyx_25050147_top__DOT__op_type = 0U;
                vlSelf->ysyx_25050147_top__DOT__src1 = 0U;
            } else if ((4U & vlSelf->mem)) {
                if ((2U & vlSelf->mem)) {
                    if ((1U & vlSelf->mem)) {
                        vlSelf->ysyx_25050147_top__DOT__op_type = 2U;
                        vlSelf->ysyx_25050147_top__DOT__src1 
                            = (0xfffff000U & vlSelf->mem);
                    } else {
                        vlSelf->ysyx_25050147_top__DOT__op_type = 0U;
                        vlSelf->ysyx_25050147_top__DOT__src1 = 0U;
                    }
                } else {
                    vlSelf->ysyx_25050147_top__DOT__op_type = 0U;
                    vlSelf->ysyx_25050147_top__DOT__src1 = 0U;
                }
            } else {
                vlSelf->ysyx_25050147_top__DOT__op_type = 0U;
                vlSelf->ysyx_25050147_top__DOT__src1 = 0U;
            }
        } else {
            vlSelf->ysyx_25050147_top__DOT__op_type = 0U;
            vlSelf->ysyx_25050147_top__DOT__src1 = 0U;
        }
        vlSelf->ysyx_25050147_top__DOT__src2 = 0U;
    } else if ((0x10U & vlSelf->mem)) {
        if ((8U & vlSelf->mem)) {
            vlSelf->ysyx_25050147_top__DOT__op_type = 0U;
            vlSelf->ysyx_25050147_top__DOT__src1 = 0U;
            vlSelf->ysyx_25050147_top__DOT__src2 = 0U;
        } else if ((4U & vlSelf->mem)) {
            if ((2U & vlSelf->mem)) {
                if ((1U & vlSelf->mem)) {
                    vlSelf->ysyx_25050147_top__DOT__op_type = 2U;
                    vlSelf->ysyx_25050147_top__DOT__src1 
                        = (0xfffff000U & vlSelf->mem);
                    vlSelf->ysyx_25050147_top__DOT__src2 
                        = vlSelf->pc;
                } else {
                    vlSelf->ysyx_25050147_top__DOT__op_type = 0U;
                    vlSelf->ysyx_25050147_top__DOT__src1 = 0U;
                    vlSelf->ysyx_25050147_top__DOT__src2 = 0U;
                }
            } else {
                vlSelf->ysyx_25050147_top__DOT__op_type = 0U;
                vlSelf->ysyx_25050147_top__DOT__src1 = 0U;
                vlSelf->ysyx_25050147_top__DOT__src2 = 0U;
            }
        } else if ((2U & vlSelf->mem)) {
            if ((1U & vlSelf->mem)) {
                vlSelf->ysyx_25050147_top__DOT__op_type = 2U;
                vlSelf->ysyx_25050147_top__DOT__src1 
                    = vlSelf->ysyx_25050147_top__DOT__idu__DOT__op_src1_I;
                vlSelf->ysyx_25050147_top__DOT__src2 
                    = vlSelf->ysyx_25050147_top__DOT__rdata;
            } else {
                vlSelf->ysyx_25050147_top__DOT__op_type = 0U;
                vlSelf->ysyx_25050147_top__DOT__src1 = 0U;
                vlSelf->ysyx_25050147_top__DOT__src2 = 0U;
            }
        } else {
            vlSelf->ysyx_25050147_top__DOT__op_type = 0U;
            vlSelf->ysyx_25050147_top__DOT__src1 = 0U;
            vlSelf->ysyx_25050147_top__DOT__src2 = 0U;
        }
    } else {
        vlSelf->ysyx_25050147_top__DOT__op_type = (
                                                   (8U 
                                                    & vlSelf->mem)
                                                    ? 0U
                                                    : 
                                                   ((4U 
                                                     & vlSelf->mem)
                                                     ? 0U
                                                     : 
                                                    ((2U 
                                                      & vlSelf->mem)
                                                      ? 0U
                                                      : 
                                                     ((1U 
                                                       & vlSelf->mem)
                                                       ? 0U
                                                       : 4U))));
        vlSelf->ysyx_25050147_top__DOT__src1 = 0U;
        vlSelf->ysyx_25050147_top__DOT__src2 = 0U;
    }
    vlSelf->ysyx_25050147_top__DOT__result = (vlSelf->ysyx_25050147_top__DOT__src1 
                                              + vlSelf->ysyx_25050147_top__DOT__src2);
    vlSelf->ysyx_25050147_top__DOT__dnpc = ((1U == (IData)(vlSelf->ysyx_25050147_top__DOT__op_type))
                                             ? vlSelf->ysyx_25050147_top__DOT__result
                                             : ((IData)(4U) 
                                                + vlSelf->pc));
}

void Vysyx_25050147_top___024root___eval_ico(Vysyx_25050147_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vysyx_25050147_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vysyx_25050147_top___024root___eval_ico\n"); );
    // Body
    if (vlSelf->__VicoTriggered.at(0U)) {
        Vysyx_25050147_top___024root___ico_sequent__TOP__0(vlSelf);
        vlSelf->__Vm_traceActivity[1U] = 1U;
    }
}

void Vysyx_25050147_top___024root___eval_act(Vysyx_25050147_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vysyx_25050147_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vysyx_25050147_top___024root___eval_act\n"); );
}

VL_INLINE_OPT void Vysyx_25050147_top___024root___nba_sequent__TOP__1(Vysyx_25050147_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vysyx_25050147_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vysyx_25050147_top___024root___nba_sequent__TOP__1\n"); );
    // Body
    vlSelf->ysyx_25050147_top__DOT__result = (vlSelf->ysyx_25050147_top__DOT__src1 
                                              + vlSelf->ysyx_25050147_top__DOT__src2);
    vlSelf->ysyx_25050147_top__DOT__dnpc = ((1U == (IData)(vlSelf->ysyx_25050147_top__DOT__op_type))
                                             ? vlSelf->ysyx_25050147_top__DOT__result
                                             : ((IData)(4U) 
                                                + vlSelf->pc));
}

void Vysyx_25050147_top___024root___nba_sequent__TOP__0(Vysyx_25050147_top___024root* vlSelf);

void Vysyx_25050147_top___024root___eval_nba(Vysyx_25050147_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vysyx_25050147_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vysyx_25050147_top___024root___eval_nba\n"); );
    // Body
    if (vlSelf->__VnbaTriggered.at(0U)) {
        Vysyx_25050147_top___024root___nba_sequent__TOP__0(vlSelf);
        vlSelf->__Vm_traceActivity[2U] = 1U;
        Vysyx_25050147_top___024root___nba_sequent__TOP__1(vlSelf);
    }
}

void Vysyx_25050147_top___024root___eval_triggers__ico(Vysyx_25050147_top___024root* vlSelf);
#ifdef VL_DEBUG
VL_ATTR_COLD void Vysyx_25050147_top___024root___dump_triggers__ico(Vysyx_25050147_top___024root* vlSelf);
#endif  // VL_DEBUG
void Vysyx_25050147_top___024root___eval_triggers__act(Vysyx_25050147_top___024root* vlSelf);
#ifdef VL_DEBUG
VL_ATTR_COLD void Vysyx_25050147_top___024root___dump_triggers__act(Vysyx_25050147_top___024root* vlSelf);
#endif  // VL_DEBUG
#ifdef VL_DEBUG
VL_ATTR_COLD void Vysyx_25050147_top___024root___dump_triggers__nba(Vysyx_25050147_top___024root* vlSelf);
#endif  // VL_DEBUG

void Vysyx_25050147_top___024root___eval(Vysyx_25050147_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vysyx_25050147_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vysyx_25050147_top___024root___eval\n"); );
    // Init
    CData/*0:0*/ __VicoContinue;
    VlTriggerVec<1> __VpreTriggered;
    IData/*31:0*/ __VnbaIterCount;
    CData/*0:0*/ __VnbaContinue;
    // Body
    vlSelf->__VicoIterCount = 0U;
    __VicoContinue = 1U;
    while (__VicoContinue) {
        __VicoContinue = 0U;
        Vysyx_25050147_top___024root___eval_triggers__ico(vlSelf);
        if (vlSelf->__VicoTriggered.any()) {
            __VicoContinue = 1U;
            if (VL_UNLIKELY((0x64U < vlSelf->__VicoIterCount))) {
#ifdef VL_DEBUG
                Vysyx_25050147_top___024root___dump_triggers__ico(vlSelf);
#endif
                VL_FATAL_MT("/home/wyh/ysyx-workbench/npc/vsrc/ysyx_25050147_top.v", 2, "", "Input combinational region did not converge.");
            }
            vlSelf->__VicoIterCount = ((IData)(1U) 
                                       + vlSelf->__VicoIterCount);
            Vysyx_25050147_top___024root___eval_ico(vlSelf);
        }
    }
    __VnbaIterCount = 0U;
    __VnbaContinue = 1U;
    while (__VnbaContinue) {
        __VnbaContinue = 0U;
        vlSelf->__VnbaTriggered.clear();
        vlSelf->__VactIterCount = 0U;
        vlSelf->__VactContinue = 1U;
        while (vlSelf->__VactContinue) {
            vlSelf->__VactContinue = 0U;
            Vysyx_25050147_top___024root___eval_triggers__act(vlSelf);
            if (vlSelf->__VactTriggered.any()) {
                vlSelf->__VactContinue = 1U;
                if (VL_UNLIKELY((0x64U < vlSelf->__VactIterCount))) {
#ifdef VL_DEBUG
                    Vysyx_25050147_top___024root___dump_triggers__act(vlSelf);
#endif
                    VL_FATAL_MT("/home/wyh/ysyx-workbench/npc/vsrc/ysyx_25050147_top.v", 2, "", "Active region did not converge.");
                }
                vlSelf->__VactIterCount = ((IData)(1U) 
                                           + vlSelf->__VactIterCount);
                __VpreTriggered.andNot(vlSelf->__VactTriggered, vlSelf->__VnbaTriggered);
                vlSelf->__VnbaTriggered.set(vlSelf->__VactTriggered);
                Vysyx_25050147_top___024root___eval_act(vlSelf);
            }
        }
        if (vlSelf->__VnbaTriggered.any()) {
            __VnbaContinue = 1U;
            if (VL_UNLIKELY((0x64U < __VnbaIterCount))) {
#ifdef VL_DEBUG
                Vysyx_25050147_top___024root___dump_triggers__nba(vlSelf);
#endif
                VL_FATAL_MT("/home/wyh/ysyx-workbench/npc/vsrc/ysyx_25050147_top.v", 2, "", "NBA region did not converge.");
            }
            __VnbaIterCount = ((IData)(1U) + __VnbaIterCount);
            Vysyx_25050147_top___024root___eval_nba(vlSelf);
        }
    }
}

#ifdef VL_DEBUG
void Vysyx_25050147_top___024root___eval_debug_assertions(Vysyx_25050147_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vysyx_25050147_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vysyx_25050147_top___024root___eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((vlSelf->rst & 0xfeU))) {
        Verilated::overWidthError("rst");}
    if (VL_UNLIKELY((vlSelf->clk & 0xfeU))) {
        Verilated::overWidthError("clk");}
}
#endif  // VL_DEBUG
