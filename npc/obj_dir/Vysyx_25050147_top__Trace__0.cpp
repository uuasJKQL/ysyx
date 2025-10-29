// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vysyx_25050147_top__Syms.h"


void Vysyx_25050147_top___024root__trace_chg_sub_0(Vysyx_25050147_top___024root* vlSelf, VerilatedVcd::Buffer* bufp);

void Vysyx_25050147_top___024root__trace_chg_top_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vysyx_25050147_top___024root__trace_chg_top_0\n"); );
    // Init
    Vysyx_25050147_top___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vysyx_25050147_top___024root*>(voidSelf);
    Vysyx_25050147_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (VL_UNLIKELY(!vlSymsp->__Vm_activity)) return;
    // Body
    Vysyx_25050147_top___024root__trace_chg_sub_0((&vlSymsp->TOP), bufp);
}

void Vysyx_25050147_top___024root__trace_chg_sub_0(Vysyx_25050147_top___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    if (false && vlSelf) {}  // Prevent unused
    Vysyx_25050147_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vysyx_25050147_top___024root__trace_chg_sub_0\n"); );
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode + 1);
    // Body
    if (VL_UNLIKELY(vlSelf->__Vm_traceActivity[1U])) {
        bufp->chgIData(oldp+0,(vlSelf->ysyx_25050147_top__DOT__mem),32);
        bufp->chgCData(oldp+1,((0x1fU & (vlSelf->ysyx_25050147_top__DOT__inst 
                                         >> 7U))),5);
        bufp->chgIData(oldp+2,(((0U == (3U & (vlSelf->ysyx_25050147_top__DOT__inst 
                                              >> 0xcU)))
                                 ? (((- (IData)((1U 
                                                 & (~ 
                                                    (vlSelf->ysyx_25050147_top__DOT__inst 
                                                     >> 0xeU))))) 
                                     << 8U) | (0xffU 
                                               & vlSelf->ysyx_25050147_top__DOT__rdata2))
                                 : ((1U == (3U & (vlSelf->ysyx_25050147_top__DOT__inst 
                                                  >> 0xcU)))
                                     ? (((- (IData)(
                                                    (1U 
                                                     & (~ 
                                                        (vlSelf->ysyx_25050147_top__DOT__inst 
                                                         >> 0xeU))))) 
                                         << 0x10U) 
                                        | (0xffffU 
                                           & vlSelf->ysyx_25050147_top__DOT__rdata2))
                                     : ((2U == (3U 
                                                & (vlSelf->ysyx_25050147_top__DOT__inst 
                                                   >> 0xcU)))
                                         ? vlSelf->ysyx_25050147_top__DOT__rdata2
                                         : 0U)))),32);
        bufp->chgIData(oldp+3,(vlSelf->ysyx_25050147_top__DOT__waddr_mem),32);
        bufp->chgBit(oldp+4,(((~ (IData)((0U != (0x14U 
                                                 & (IData)(vlSelf->ysyx_25050147_top__DOT__op_type))))) 
                              & (0U != (0x1fU & (vlSelf->ysyx_25050147_top__DOT__inst 
                                                 >> 7U))))));
        bufp->chgIData(oldp+5,(vlSelf->ysyx_25050147_top__DOT__rdata1),32);
        bufp->chgCData(oldp+6,((0x1fU & (vlSelf->ysyx_25050147_top__DOT__inst 
                                         >> 0xfU))),5);
        bufp->chgIData(oldp+7,(vlSelf->ysyx_25050147_top__DOT__rdata2),32);
        bufp->chgCData(oldp+8,((0x1fU & (vlSelf->ysyx_25050147_top__DOT__inst 
                                         >> 0x14U))),5);
        bufp->chgCData(oldp+9,(vlSelf->ysyx_25050147_top__DOT__op_type),5);
        bufp->chgIData(oldp+10,(vlSelf->ysyx_25050147_top__DOT__src1),32);
        bufp->chgIData(oldp+11,(vlSelf->ysyx_25050147_top__DOT__src2),32);
        bufp->chgBit(oldp+12,((1U & ((IData)(vlSelf->ysyx_25050147_top__DOT__op_type) 
                                     >> 2U))));
        bufp->chgIData(oldp+13,(vlSelf->ysyx_25050147_top__DOT__inst),32);
        bufp->chgCData(oldp+14,(vlSelf->ysyx_25050147_top__DOT__alu_op),4);
        bufp->chgIData(oldp+15,((((- (IData)((vlSelf->ysyx_25050147_top__DOT__inst 
                                              >> 0x1fU))) 
                                  << 0xcU) | ((0x800U 
                                               & (vlSelf->ysyx_25050147_top__DOT__inst 
                                                  << 4U)) 
                                              | ((0x7e0U 
                                                  & (vlSelf->ysyx_25050147_top__DOT__inst 
                                                     >> 0x14U)) 
                                                 | (0x1eU 
                                                    & (vlSelf->ysyx_25050147_top__DOT__inst 
                                                       >> 7U)))))),32);
        bufp->chgIData(oldp+16,(((0U == (3U & (vlSelf->ysyx_25050147_top__DOT__inst 
                                               >> 0xcU)))
                                  ? (((- (IData)((1U 
                                                  & (~ 
                                                     (vlSelf->ysyx_25050147_top__DOT__inst 
                                                      >> 0xeU))))) 
                                      << 8U) | (0xffU 
                                                & vlSelf->ysyx_25050147_top__DOT__mem))
                                  : ((1U == (3U & (vlSelf->ysyx_25050147_top__DOT__inst 
                                                   >> 0xcU)))
                                      ? (((- (IData)(
                                                     (1U 
                                                      & (~ 
                                                         (vlSelf->ysyx_25050147_top__DOT__inst 
                                                          >> 0xeU))))) 
                                          << 0x10U) 
                                         | (0xffffU 
                                            & vlSelf->ysyx_25050147_top__DOT__mem))
                                      : ((2U == (3U 
                                                 & (vlSelf->ysyx_25050147_top__DOT__inst 
                                                    >> 0xcU)))
                                          ? vlSelf->ysyx_25050147_top__DOT__mem
                                          : 0U)))),32);
        bufp->chgBit(oldp+17,((IData)((((IData)(vlSelf->ysyx_25050147_top__DOT__op_type) 
                                        >> 4U) & vlSelf->ysyx_25050147_top__DOT__waddr_mem))));
        bufp->chgBit(oldp+18,((1U & ((IData)(vlSelf->ysyx_25050147_top__DOT__op_type) 
                                     >> 4U))));
        bufp->chgBit(oldp+19,((0U == (IData)(vlSelf->ysyx_25050147_top__DOT__op_type))));
        bufp->chgIData(oldp+20,(vlSelf->ysyx_25050147_top__DOT__exu__DOT__myalu__DOT__result),32);
        bufp->chgBit(oldp+21,((1U & (~ (IData)((0U 
                                                != vlSelf->ysyx_25050147_top__DOT__exu__DOT__myalu__DOT__Result))))));
        bufp->chgBit(oldp+22,((((vlSelf->ysyx_25050147_top__DOT__src1 
                                 >> 0x1fU) == (vlSelf->ysyx_25050147_top__DOT__exu__DOT__myalu__DOT__t_no_Cin 
                                               >> 0x1fU)) 
                               & ((vlSelf->ysyx_25050147_top__DOT__exu__DOT__myalu__DOT__Result 
                                   >> 0x1fU) != (vlSelf->ysyx_25050147_top__DOT__src1 
                                                 >> 0x1fU)))));
        bufp->chgIData(oldp+23,(vlSelf->ysyx_25050147_top__DOT__exu__DOT__myalu__DOT__Result),32);
        bufp->chgIData(oldp+24,(vlSelf->ysyx_25050147_top__DOT__exu__DOT__myalu__DOT__t_no_Cin),32);
        bufp->chgBit(oldp+25,(vlSelf->ysyx_25050147_top__DOT__exu__DOT__myalu__DOT__Carry));
        bufp->chgBit(oldp+26,(vlSelf->ysyx_25050147_top__DOT__exu__DOT__myalu__DOT__Cin));
        bufp->chgBit(oldp+27,(vlSelf->ysyx_25050147_top__DOT__exu__DOT__myalu__DOT__is_branch));
        bufp->chgIData(oldp+28,(vlSelf->ysyx_25050147_top__DOT__idu__DOT__op_src2_I),32);
        bufp->chgIData(oldp+29,((0xfffff000U & vlSelf->ysyx_25050147_top__DOT__inst)),32);
        bufp->chgIData(oldp+30,((((- (IData)((vlSelf->ysyx_25050147_top__DOT__inst 
                                              >> 0x1fU))) 
                                  << 0x14U) | ((0xff000U 
                                                & vlSelf->ysyx_25050147_top__DOT__inst) 
                                               | ((0x800U 
                                                   & (vlSelf->ysyx_25050147_top__DOT__inst 
                                                      >> 9U)) 
                                                  | (0x7feU 
                                                     & (vlSelf->ysyx_25050147_top__DOT__inst 
                                                        >> 0x14U)))))),32);
        bufp->chgIData(oldp+31,((((- (IData)((vlSelf->ysyx_25050147_top__DOT__inst 
                                              >> 0x1fU))) 
                                  << 0xcU) | ((0xfe0U 
                                               & (vlSelf->ysyx_25050147_top__DOT__inst 
                                                  >> 0x14U)) 
                                              | (0x1fU 
                                                 & (vlSelf->ysyx_25050147_top__DOT__inst 
                                                    >> 7U))))),32);
        bufp->chgCData(oldp+32,((7U & (vlSelf->ysyx_25050147_top__DOT__inst 
                                       >> 0xcU))),3);
        bufp->chgIData(oldp+33,(vlSelf->ysyx_25050147_top__DOT__rfile__DOT__rf[0]),32);
        bufp->chgIData(oldp+34,(vlSelf->ysyx_25050147_top__DOT__rfile__DOT__rf[1]),32);
        bufp->chgIData(oldp+35,(vlSelf->ysyx_25050147_top__DOT__rfile__DOT__rf[2]),32);
        bufp->chgIData(oldp+36,(vlSelf->ysyx_25050147_top__DOT__rfile__DOT__rf[3]),32);
        bufp->chgIData(oldp+37,(vlSelf->ysyx_25050147_top__DOT__rfile__DOT__rf[4]),32);
        bufp->chgIData(oldp+38,(vlSelf->ysyx_25050147_top__DOT__rfile__DOT__rf[5]),32);
        bufp->chgIData(oldp+39,(vlSelf->ysyx_25050147_top__DOT__rfile__DOT__rf[6]),32);
        bufp->chgIData(oldp+40,(vlSelf->ysyx_25050147_top__DOT__rfile__DOT__rf[7]),32);
        bufp->chgIData(oldp+41,(vlSelf->ysyx_25050147_top__DOT__rfile__DOT__rf[8]),32);
        bufp->chgIData(oldp+42,(vlSelf->ysyx_25050147_top__DOT__rfile__DOT__rf[9]),32);
        bufp->chgIData(oldp+43,(vlSelf->ysyx_25050147_top__DOT__rfile__DOT__rf[10]),32);
        bufp->chgIData(oldp+44,(vlSelf->ysyx_25050147_top__DOT__rfile__DOT__rf[11]),32);
        bufp->chgIData(oldp+45,(vlSelf->ysyx_25050147_top__DOT__rfile__DOT__rf[12]),32);
        bufp->chgIData(oldp+46,(vlSelf->ysyx_25050147_top__DOT__rfile__DOT__rf[13]),32);
        bufp->chgIData(oldp+47,(vlSelf->ysyx_25050147_top__DOT__rfile__DOT__rf[14]),32);
        bufp->chgIData(oldp+48,(vlSelf->ysyx_25050147_top__DOT__rfile__DOT__rf[15]),32);
        bufp->chgIData(oldp+49,(vlSelf->ysyx_25050147_top__DOT__rfile__DOT__rf[16]),32);
        bufp->chgIData(oldp+50,(vlSelf->ysyx_25050147_top__DOT__rfile__DOT__rf[17]),32);
        bufp->chgIData(oldp+51,(vlSelf->ysyx_25050147_top__DOT__rfile__DOT__rf[18]),32);
        bufp->chgIData(oldp+52,(vlSelf->ysyx_25050147_top__DOT__rfile__DOT__rf[19]),32);
        bufp->chgIData(oldp+53,(vlSelf->ysyx_25050147_top__DOT__rfile__DOT__rf[20]),32);
        bufp->chgIData(oldp+54,(vlSelf->ysyx_25050147_top__DOT__rfile__DOT__rf[21]),32);
        bufp->chgIData(oldp+55,(vlSelf->ysyx_25050147_top__DOT__rfile__DOT__rf[22]),32);
        bufp->chgIData(oldp+56,(vlSelf->ysyx_25050147_top__DOT__rfile__DOT__rf[23]),32);
        bufp->chgIData(oldp+57,(vlSelf->ysyx_25050147_top__DOT__rfile__DOT__rf[24]),32);
        bufp->chgIData(oldp+58,(vlSelf->ysyx_25050147_top__DOT__rfile__DOT__rf[25]),32);
        bufp->chgIData(oldp+59,(vlSelf->ysyx_25050147_top__DOT__rfile__DOT__rf[26]),32);
        bufp->chgIData(oldp+60,(vlSelf->ysyx_25050147_top__DOT__rfile__DOT__rf[27]),32);
        bufp->chgIData(oldp+61,(vlSelf->ysyx_25050147_top__DOT__rfile__DOT__rf[28]),32);
        bufp->chgIData(oldp+62,(vlSelf->ysyx_25050147_top__DOT__rfile__DOT__rf[29]),32);
        bufp->chgIData(oldp+63,(vlSelf->ysyx_25050147_top__DOT__rfile__DOT__rf[30]),32);
        bufp->chgIData(oldp+64,(vlSelf->ysyx_25050147_top__DOT__rfile__DOT__rf[31]),32);
    }
    bufp->chgBit(oldp+65,(vlSelf->rst));
    bufp->chgBit(oldp+66,(vlSelf->clk));
    bufp->chgIData(oldp+67,(vlSelf->pc),32);
    bufp->chgIData(oldp+68,(((1U & (IData)(vlSelf->ysyx_25050147_top__DOT__op_type))
                              ? ((IData)(4U) + vlSelf->pc)
                              : ((8U & (IData)(vlSelf->ysyx_25050147_top__DOT__op_type))
                                  ? ((0U == (3U & (vlSelf->ysyx_25050147_top__DOT__inst 
                                                   >> 0xcU)))
                                      ? (((- (IData)(
                                                     (1U 
                                                      & (~ 
                                                         (vlSelf->ysyx_25050147_top__DOT__inst 
                                                          >> 0xeU))))) 
                                          << 8U) | 
                                         (0xffU & vlSelf->ysyx_25050147_top__DOT__mem))
                                      : ((1U == (3U 
                                                 & (vlSelf->ysyx_25050147_top__DOT__inst 
                                                    >> 0xcU)))
                                          ? (((- (IData)(
                                                         (1U 
                                                          & (~ 
                                                             (vlSelf->ysyx_25050147_top__DOT__inst 
                                                              >> 0xeU))))) 
                                              << 0x10U) 
                                             | (0xffffU 
                                                & vlSelf->ysyx_25050147_top__DOT__mem))
                                          : ((2U == 
                                              (3U & 
                                               (vlSelf->ysyx_25050147_top__DOT__inst 
                                                >> 0xcU)))
                                              ? vlSelf->ysyx_25050147_top__DOT__mem
                                              : 0U)))
                                  : vlSelf->ysyx_25050147_top__DOT__waddr_mem))),32);
    bufp->chgIData(oldp+69,(((IData)(4U) + vlSelf->pc)),32);
    bufp->chgIData(oldp+70,(((1U == (IData)(vlSelf->ysyx_25050147_top__DOT__op_type))
                              ? vlSelf->ysyx_25050147_top__DOT__waddr_mem
                              : ((IData)((((IData)(vlSelf->ysyx_25050147_top__DOT__op_type) 
                                           >> 4U) & vlSelf->ysyx_25050147_top__DOT__waddr_mem))
                                  ? ((((- (IData)((vlSelf->ysyx_25050147_top__DOT__inst 
                                                   >> 0x1fU))) 
                                       << 0xcU) | (
                                                   (0x800U 
                                                    & (vlSelf->ysyx_25050147_top__DOT__inst 
                                                       << 4U)) 
                                                   | ((0x7e0U 
                                                       & (vlSelf->ysyx_25050147_top__DOT__inst 
                                                          >> 0x14U)) 
                                                      | (0x1eU 
                                                         & (vlSelf->ysyx_25050147_top__DOT__inst 
                                                            >> 7U))))) 
                                     + vlSelf->pc) : 
                                 ((IData)(4U) + vlSelf->pc)))),32);
    bufp->chgIData(oldp+71,(((((- (IData)((vlSelf->ysyx_25050147_top__DOT__inst 
                                           >> 0x1fU))) 
                               << 0xcU) | ((0x800U 
                                            & (vlSelf->ysyx_25050147_top__DOT__inst 
                                               << 4U)) 
                                           | ((0x7e0U 
                                               & (vlSelf->ysyx_25050147_top__DOT__inst 
                                                  >> 0x14U)) 
                                              | (0x1eU 
                                                 & (vlSelf->ysyx_25050147_top__DOT__inst 
                                                    >> 7U))))) 
                             + vlSelf->pc)),32);
}

void Vysyx_25050147_top___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vysyx_25050147_top___024root__trace_cleanup\n"); );
    // Init
    Vysyx_25050147_top___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vysyx_25050147_top___024root*>(voidSelf);
    Vysyx_25050147_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    vlSymsp->__Vm_activity = false;
    vlSymsp->TOP.__Vm_traceActivity[0U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[1U] = 0U;
}
