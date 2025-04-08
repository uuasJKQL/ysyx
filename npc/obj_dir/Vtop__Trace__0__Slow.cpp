// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vtop__Syms.h"


VL_ATTR_COLD void Vtop___024root__trace_init_sub__TOP__0(Vtop___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_init_sub__TOP__0\n"); );
    // Init
    const int c = vlSymsp->__Vm_baseCode;
    // Body
    tracep->declBit(c+19,"clk", false,-1);
    tracep->declBit(c+20,"clrn", false,-1);
    tracep->declBit(c+21,"ps2_clk", false,-1);
    tracep->declBit(c+22,"ps2_data", false,-1);
    tracep->declBit(c+23,"nextdata", false,-1);
    tracep->declBus(c+24,"HEX0", false,-1, 6,0);
    tracep->declBus(c+25,"HEX1", false,-1, 6,0);
    tracep->declBit(c+26,"Ready", false,-1);
    tracep->pushNamePrefix("top ");
    tracep->declBit(c+19,"clk", false,-1);
    tracep->declBit(c+20,"clrn", false,-1);
    tracep->declBit(c+21,"ps2_clk", false,-1);
    tracep->declBit(c+22,"ps2_data", false,-1);
    tracep->declBit(c+23,"nextdata", false,-1);
    tracep->declBus(c+24,"HEX0", false,-1, 6,0);
    tracep->declBus(c+25,"HEX1", false,-1, 6,0);
    tracep->declBit(c+26,"Ready", false,-1);
    tracep->declBus(c+1,"Data", false,-1, 7,0);
    tracep->declBit(c+2,"Overflow", false,-1);
    tracep->declBus(c+27,"dataline", false,-1, 23,0);
    tracep->pushNamePrefix("controller ");
    tracep->declBit(c+19,"clk", false,-1);
    tracep->declBit(c+20,"clrn", false,-1);
    tracep->declBit(c+21,"ps2_clk", false,-1);
    tracep->declBit(c+22,"ps2_data", false,-1);
    tracep->declBit(c+23,"nextdata_n", false,-1);
    tracep->declBus(c+1,"data", false,-1, 7,0);
    tracep->declBit(c+26,"ready", false,-1);
    tracep->declBit(c+2,"overflow", false,-1);
    tracep->declBus(c+3,"buffer", false,-1, 9,0);
    for (int i = 0; i < 8; ++i) {
        tracep->declBus(c+4+i*1,"fifo", true,(i+0), 7,0);
    }
    tracep->declBus(c+12,"w_ptr", false,-1, 2,0);
    tracep->declBus(c+13,"r_ptr", false,-1, 2,0);
    tracep->declBus(c+14,"count", false,-1, 3,0);
    tracep->declBus(c+15,"ps2_clk_sync", false,-1, 2,0);
    tracep->declBit(c+16,"sampling", false,-1);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("sega ");
    tracep->declBus(c+17,"data", false,-1, 3,0);
    tracep->declBus(c+24,"seg", false,-1, 6,0);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("segb ");
    tracep->declBus(c+18,"data", false,-1, 3,0);
    tracep->declBus(c+25,"seg", false,-1, 6,0);
    tracep->popNamePrefix(2);
}

VL_ATTR_COLD void Vtop___024root__trace_init_top(Vtop___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_init_top\n"); );
    // Body
    Vtop___024root__trace_init_sub__TOP__0(vlSelf, tracep);
}

VL_ATTR_COLD void Vtop___024root__trace_full_top_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
void Vtop___024root__trace_chg_top_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
void Vtop___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/);

VL_ATTR_COLD void Vtop___024root__trace_register(Vtop___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_register\n"); );
    // Body
    tracep->addFullCb(&Vtop___024root__trace_full_top_0, vlSelf);
    tracep->addChgCb(&Vtop___024root__trace_chg_top_0, vlSelf);
    tracep->addCleanupCb(&Vtop___024root__trace_cleanup, vlSelf);
}

VL_ATTR_COLD void Vtop___024root__trace_full_sub_0(Vtop___024root* vlSelf, VerilatedVcd::Buffer* bufp);

VL_ATTR_COLD void Vtop___024root__trace_full_top_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_full_top_0\n"); );
    // Init
    Vtop___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vtop___024root*>(voidSelf);
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    Vtop___024root__trace_full_sub_0((&vlSymsp->TOP), bufp);
}

VL_ATTR_COLD void Vtop___024root__trace_full_sub_0(Vtop___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_full_sub_0\n"); );
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode);
    // Body
    bufp->fullCData(oldp+1,(vlSelf->top__DOT__Data),8);
    bufp->fullBit(oldp+2,(vlSelf->top__DOT__Overflow));
    bufp->fullSData(oldp+3,(vlSelf->top__DOT__controller__DOT__buffer),10);
    bufp->fullCData(oldp+4,(vlSelf->top__DOT__controller__DOT__fifo[0]),8);
    bufp->fullCData(oldp+5,(vlSelf->top__DOT__controller__DOT__fifo[1]),8);
    bufp->fullCData(oldp+6,(vlSelf->top__DOT__controller__DOT__fifo[2]),8);
    bufp->fullCData(oldp+7,(vlSelf->top__DOT__controller__DOT__fifo[3]),8);
    bufp->fullCData(oldp+8,(vlSelf->top__DOT__controller__DOT__fifo[4]),8);
    bufp->fullCData(oldp+9,(vlSelf->top__DOT__controller__DOT__fifo[5]),8);
    bufp->fullCData(oldp+10,(vlSelf->top__DOT__controller__DOT__fifo[6]),8);
    bufp->fullCData(oldp+11,(vlSelf->top__DOT__controller__DOT__fifo[7]),8);
    bufp->fullCData(oldp+12,(vlSelf->top__DOT__controller__DOT__w_ptr),3);
    bufp->fullCData(oldp+13,(vlSelf->top__DOT__controller__DOT__r_ptr),3);
    bufp->fullCData(oldp+14,(vlSelf->top__DOT__controller__DOT__count),4);
    bufp->fullCData(oldp+15,(vlSelf->top__DOT__controller__DOT__ps2_clk_sync),3);
    bufp->fullBit(oldp+16,((IData)((4U == (6U & (IData)(vlSelf->top__DOT__controller__DOT__ps2_clk_sync))))));
    bufp->fullCData(oldp+17,((0xfU & (IData)(vlSelf->top__DOT__Data))),4);
    bufp->fullCData(oldp+18,((0xfU & ((IData)(vlSelf->top__DOT__Data) 
                                      >> 4U))),4);
    bufp->fullBit(oldp+19,(vlSelf->clk));
    bufp->fullBit(oldp+20,(vlSelf->clrn));
    bufp->fullBit(oldp+21,(vlSelf->ps2_clk));
    bufp->fullBit(oldp+22,(vlSelf->ps2_data));
    bufp->fullBit(oldp+23,(vlSelf->nextdata));
    bufp->fullCData(oldp+24,(vlSelf->HEX0),7);
    bufp->fullCData(oldp+25,(vlSelf->HEX1),7);
    bufp->fullBit(oldp+26,(vlSelf->Ready));
    bufp->fullIData(oldp+27,(vlSelf->top__DOT__dataline),24);
}
