// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vysyx_25050147_top.h for the primary calling header

#include "verilated.h"
#include "verilated_dpi.h"

#include "Vysyx_25050147_top__Syms.h"
#include "Vysyx_25050147_top___024root.h"

#ifdef VL_DEBUG
VL_ATTR_COLD void Vysyx_25050147_top___024root___dump_triggers__ico(Vysyx_25050147_top___024root* vlSelf);
#endif  // VL_DEBUG

void Vysyx_25050147_top___024root___eval_triggers__ico(Vysyx_25050147_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vysyx_25050147_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vysyx_25050147_top___024root___eval_triggers__ico\n"); );
    // Body
    vlSelf->__VicoTriggered.at(0U) = (0U == vlSelf->__VicoIterCount);
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vysyx_25050147_top___024root___dump_triggers__ico(vlSelf);
    }
#endif
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vysyx_25050147_top___024root___dump_triggers__act(Vysyx_25050147_top___024root* vlSelf);
#endif  // VL_DEBUG

void Vysyx_25050147_top___024root___eval_triggers__act(Vysyx_25050147_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vysyx_25050147_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vysyx_25050147_top___024root___eval_triggers__act\n"); );
    // Body
    vlSelf->__VactTriggered.at(0U) = ((IData)(vlSelf->clk) 
                                      & (~ (IData)(vlSelf->__Vtrigrprev__TOP__clk)));
    vlSelf->__Vtrigrprev__TOP__clk = vlSelf->clk;
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vysyx_25050147_top___024root___dump_triggers__act(vlSelf);
    }
#endif
}

void Vysyx_25050147_top___024unit____Vdpiimwrap_notify_ebreak_TOP____024unit();

VL_INLINE_OPT void Vysyx_25050147_top___024root___nba_sequent__TOP__0(Vysyx_25050147_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vysyx_25050147_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vysyx_25050147_top___024root___nba_sequent__TOP__0\n"); );
    // Init
    CData/*4:0*/ __Vdlyvdim0__ysyx_25050147_top__DOT__rfile__DOT__rf__v0;
    __Vdlyvdim0__ysyx_25050147_top__DOT__rfile__DOT__rf__v0 = 0;
    IData/*31:0*/ __Vdlyvval__ysyx_25050147_top__DOT__rfile__DOT__rf__v0;
    __Vdlyvval__ysyx_25050147_top__DOT__rfile__DOT__rf__v0 = 0;
    CData/*0:0*/ __Vdlyvset__ysyx_25050147_top__DOT__rfile__DOT__rf__v0;
    __Vdlyvset__ysyx_25050147_top__DOT__rfile__DOT__rf__v0 = 0;
    // Body
    if ((0U == (IData)(vlSelf->ysyx_25050147_top__DOT__op_type))) {
        Vysyx_25050147_top___024unit____Vdpiimwrap_notify_ebreak_TOP____024unit();
    }
    __Vdlyvset__ysyx_25050147_top__DOT__rfile__DOT__rf__v0 = 0U;
    if ((0U != (0x1fU & (vlSelf->mem >> 7U)))) {
        __Vdlyvval__ysyx_25050147_top__DOT__rfile__DOT__rf__v0 
            = ((1U == (IData)(vlSelf->ysyx_25050147_top__DOT__op_type))
                ? ((IData)(4U) + vlSelf->pc) : vlSelf->ysyx_25050147_top__DOT__result);
        __Vdlyvset__ysyx_25050147_top__DOT__rfile__DOT__rf__v0 = 1U;
        __Vdlyvdim0__ysyx_25050147_top__DOT__rfile__DOT__rf__v0 
            = (0x1fU & (vlSelf->mem >> 7U));
    }
    if (__Vdlyvset__ysyx_25050147_top__DOT__rfile__DOT__rf__v0) {
        vlSelf->ysyx_25050147_top__DOT__rfile__DOT__rf[__Vdlyvdim0__ysyx_25050147_top__DOT__rfile__DOT__rf__v0] 
            = __Vdlyvval__ysyx_25050147_top__DOT__rfile__DOT__rf__v0;
    }
    vlSelf->ysyx_25050147_top__DOT__rdata = vlSelf->ysyx_25050147_top__DOT__rfile__DOT__rf
        [(0x1fU & (vlSelf->mem >> 0xfU))];
    vlSelf->pc = ((IData)(vlSelf->rst) ? 0x80000000U
                   : vlSelf->ysyx_25050147_top__DOT__dnpc);
    vlSelf->ysyx_25050147_top__DOT__src2 = ((0x40U 
                                             & vlSelf->mem)
                                             ? ((0x20U 
                                                 & vlSelf->mem)
                                                 ? 
                                                ((0x10U 
                                                  & vlSelf->mem)
                                                  ? 0U
                                                  : 
                                                 ((8U 
                                                   & vlSelf->mem)
                                                   ? 
                                                  ((4U 
                                                    & vlSelf->mem)
                                                    ? 
                                                   ((2U 
                                                     & vlSelf->mem)
                                                     ? 
                                                    ((1U 
                                                      & vlSelf->mem)
                                                      ? vlSelf->pc
                                                      : 0U)
                                                     : 0U)
                                                    : 0U)
                                                   : 
                                                  ((4U 
                                                    & vlSelf->mem)
                                                    ? 
                                                   ((2U 
                                                     & vlSelf->mem)
                                                     ? 
                                                    ((1U 
                                                      & vlSelf->mem)
                                                      ? vlSelf->ysyx_25050147_top__DOT__rdata
                                                      : 0U)
                                                     : 0U)
                                                    : 0U)))
                                                 : 0U)
                                             : ((0x20U 
                                                 & vlSelf->mem)
                                                 ? 0U
                                                 : 
                                                ((0x10U 
                                                  & vlSelf->mem)
                                                  ? 
                                                 ((8U 
                                                   & vlSelf->mem)
                                                   ? 0U
                                                   : 
                                                  ((4U 
                                                    & vlSelf->mem)
                                                    ? 
                                                   ((2U 
                                                     & vlSelf->mem)
                                                     ? 
                                                    ((1U 
                                                      & vlSelf->mem)
                                                      ? vlSelf->pc
                                                      : 0U)
                                                     : 0U)
                                                    : 
                                                   ((2U 
                                                     & vlSelf->mem)
                                                     ? 
                                                    ((1U 
                                                      & vlSelf->mem)
                                                      ? vlSelf->ysyx_25050147_top__DOT__rdata
                                                      : 0U)
                                                     : 0U)))
                                                  : 0U)));
}
