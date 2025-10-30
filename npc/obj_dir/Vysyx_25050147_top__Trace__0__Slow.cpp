// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vysyx_25050147_top__Syms.h"


VL_ATTR_COLD void Vysyx_25050147_top___024root__trace_init_sub__TOP__0(Vysyx_25050147_top___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    Vysyx_25050147_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vysyx_25050147_top___024root__trace_init_sub__TOP__0\n"); );
    // Init
    const int c = vlSymsp->__Vm_baseCode;
    // Body
    tracep->declBit(c+71,"rst", false,-1);
    tracep->declBit(c+72,"clk", false,-1);
    tracep->declBus(c+73,"pc", false,-1, 31,0);
    tracep->pushNamePrefix("ysyx_25050147_top ");
    tracep->declBit(c+71,"rst", false,-1);
    tracep->declBit(c+72,"clk", false,-1);
    tracep->declBus(c+73,"pc", false,-1, 31,0);
    tracep->declBus(c+1,"mem", false,-1, 31,0);
    tracep->declBus(c+74,"wdata", false,-1, 31,0);
    tracep->declBus(c+2,"waddr", false,-1, 4,0);
    tracep->declBus(c+3,"wdata_mem", false,-1, 31,0);
    tracep->declBus(c+4,"waddr_mem", false,-1, 31,0);
    tracep->declBus(c+5,"wmask", false,-1, 7,0);
    tracep->declBit(c+6,"wen", false,-1);
    tracep->declBus(c+7,"rdata1", false,-1, 31,0);
    tracep->declBus(c+8,"raddr1", false,-1, 4,0);
    tracep->declBus(c+9,"rdata2", false,-1, 31,0);
    tracep->declBus(c+10,"raddr2", false,-1, 4,0);
    tracep->declBus(c+75,"snpc", false,-1, 31,0);
    tracep->declBus(c+76,"dnpc", false,-1, 31,0);
    tracep->declBus(c+11,"op_type", false,-1, 4,0);
    tracep->declBus(c+12,"src1", false,-1, 31,0);
    tracep->declBus(c+13,"src2", false,-1, 31,0);
    tracep->declBus(c+4,"result", false,-1, 31,0);
    tracep->declBus(c+2,"rd", false,-1, 4,0);
    tracep->declBit(c+14,"wen_mem", false,-1);
    tracep->declBus(c+15,"inst", false,-1, 31,0);
    tracep->declBus(c+77,"branch_target", false,-1, 31,0);
    tracep->declBus(c+16,"alu_op", false,-1, 3,0);
    tracep->declBus(c+17,"branch_offset", false,-1, 31,0);
    tracep->declBus(c+18,"mem_out", false,-1, 31,0);
    tracep->declBus(c+3,"mem_in", false,-1, 31,0);
    tracep->declBit(c+19,"is_branch", false,-1);
    tracep->declBit(c+20,"is_beq", false,-1);
    tracep->declBit(c+21,"is_ebreak", false,-1);
    tracep->pushNamePrefix("PC ");
    tracep->declBus(c+78,"WIDTH", false,-1, 31,0);
    tracep->declBus(c+79,"RESET_VAL", false,-1, 31,0);
    tracep->declBit(c+72,"clk", false,-1);
    tracep->declBit(c+71,"rst", false,-1);
    tracep->declBus(c+76,"din", false,-1, 31,0);
    tracep->declBus(c+73,"dout", false,-1, 31,0);
    tracep->declBit(c+80,"wen", false,-1);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("exu ");
    tracep->declBus(c+16,"alu_op", false,-1, 3,0);
    tracep->declBit(c+20,"is_beq", false,-1);
    tracep->declBus(c+12,"src1", false,-1, 31,0);
    tracep->declBus(c+13,"src2", false,-1, 31,0);
    tracep->declBus(c+4,"result", false,-1, 31,0);
    tracep->pushNamePrefix("myalu ");
    tracep->declBus(c+16,"alu_op", false,-1, 3,0);
    tracep->declBus(c+12,"src1", false,-1, 31,0);
    tracep->declBus(c+13,"src2", false,-1, 31,0);
    tracep->declBit(c+20,"is_beq", false,-1);
    tracep->declBus(c+4,"fresult", false,-1, 31,0);
    tracep->declBus(c+22,"result", false,-1, 31,0);
    tracep->declBit(c+23,"zero", false,-1);
    tracep->declBit(c+24,"Overflow", false,-1);
    tracep->declBus(c+25,"Result", false,-1, 31,0);
    tracep->declBus(c+26,"t_no_Cin", false,-1, 31,0);
    tracep->declBit(c+27,"Carry", false,-1);
    tracep->declBit(c+28,"Cin", false,-1);
    tracep->declBus(c+12,"sign_src1", false,-1, 31,0);
    tracep->declBit(c+29,"is_branch", false,-1);
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("idu ");
    tracep->declBus(c+15,"mem", false,-1, 31,0);
    tracep->declBus(c+7,"rs1", false,-1, 31,0);
    tracep->declBus(c+73,"pc", false,-1, 31,0);
    tracep->declBus(c+8,"raddr1", false,-1, 4,0);
    tracep->declBus(c+9,"rs2", false,-1, 31,0);
    tracep->declBus(c+10,"raddr2", false,-1, 4,0);
    tracep->declBus(c+11,"op_type", false,-1, 4,0);
    tracep->declBus(c+12,"op_src1", false,-1, 31,0);
    tracep->declBus(c+13,"op_src2", false,-1, 31,0);
    tracep->declBus(c+2,"rd", false,-1, 4,0);
    tracep->declBus(c+17,"branch_target", false,-1, 31,0);
    tracep->declBus(c+16,"alu_op", false,-1, 3,0);
    tracep->declBit(c+20,"is_beq", false,-1);
    tracep->declBus(c+7,"op_src1_I", false,-1, 31,0);
    tracep->declBus(c+30,"op_src2_I", false,-1, 31,0);
    tracep->declBus(c+31,"op_src1_U", false,-1, 31,0);
    tracep->declBus(c+32,"op_src1_J", false,-1, 31,0);
    tracep->declBus(c+7,"op_src1_R", false,-1, 31,0);
    tracep->declBus(c+9,"op_src2_R", false,-1, 31,0);
    tracep->declBus(c+7,"op_src1_S", false,-1, 31,0);
    tracep->declBus(c+33,"op_src2_S", false,-1, 31,0);
    tracep->declBus(c+81,"EBREAK", false,-1, 31,0);
    tracep->declBus(c+82,"JUMP", false,-1, 31,0);
    tracep->declBus(c+83,"ELSE", false,-1, 31,0);
    tracep->declBus(c+84,"STORE", false,-1, 31,0);
    tracep->declBus(c+85,"LOAD", false,-1, 31,0);
    tracep->declBus(c+86,"BRANCH", false,-1, 31,0);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("ifu ");
    tracep->declBus(c+4,"raddr", false,-1, 31,0);
    tracep->declBit(c+80,"valid", false,-1);
    tracep->declBit(c+14,"wen", false,-1);
    tracep->declBus(c+4,"waddr", false,-1, 31,0);
    tracep->declBus(c+3,"wdata", false,-1, 31,0);
    tracep->declBus(c+5,"wmask", false,-1, 7,0);
    tracep->declBus(c+1,"rdata", false,-1, 31,0);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("memload_change ");
    tracep->declBus(c+34,"op", false,-1, 2,0);
    tracep->declBus(c+35,"addr", false,-1, 1,0);
    tracep->declBus(c+1,"data", false,-1, 31,0);
    tracep->declBus(c+18,"result", false,-1, 31,0);
    tracep->declBus(c+36,"mem_data", false,-1, 31,0);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("memstore_change ");
    tracep->declBus(c+34,"op", false,-1, 2,0);
    tracep->declBus(c+35,"addr", false,-1, 1,0);
    tracep->declBus(c+9,"data", false,-1, 31,0);
    tracep->declBus(c+3,"mem_result", false,-1, 31,0);
    tracep->declBus(c+5,"wmask", false,-1, 7,0);
    tracep->declBus(c+37,"wmask1", false,-1, 7,0);
    tracep->declBus(c+38,"result", false,-1, 31,0);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("rfile ");
    tracep->declBus(c+87,"ADDR_WIDTH", false,-1, 2,0);
    tracep->declBus(c+88,"DATA_WIDTH", false,-1, 5,0);
    tracep->declBit(c+72,"clk", false,-1);
    tracep->declBus(c+74,"wdata", false,-1, 31,0);
    tracep->declBus(c+2,"waddr", false,-1, 4,0);
    tracep->declBus(c+7,"rdata1", false,-1, 31,0);
    tracep->declBus(c+8,"raddr1", false,-1, 4,0);
    tracep->declBus(c+9,"rdata2", false,-1, 31,0);
    tracep->declBus(c+10,"raddr2", false,-1, 4,0);
    tracep->declBit(c+6,"wen", false,-1);
    for (int i = 0; i < 32; ++i) {
        tracep->declBus(c+39+i*1,"rf", true,(i+0), 31,0);
    }
    tracep->popNamePrefix(2);
}

VL_ATTR_COLD void Vysyx_25050147_top___024root__trace_init_top(Vysyx_25050147_top___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    Vysyx_25050147_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vysyx_25050147_top___024root__trace_init_top\n"); );
    // Body
    Vysyx_25050147_top___024root__trace_init_sub__TOP__0(vlSelf, tracep);
}

VL_ATTR_COLD void Vysyx_25050147_top___024root__trace_full_top_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
void Vysyx_25050147_top___024root__trace_chg_top_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
void Vysyx_25050147_top___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/);

VL_ATTR_COLD void Vysyx_25050147_top___024root__trace_register(Vysyx_25050147_top___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    Vysyx_25050147_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vysyx_25050147_top___024root__trace_register\n"); );
    // Body
    tracep->addFullCb(&Vysyx_25050147_top___024root__trace_full_top_0, vlSelf);
    tracep->addChgCb(&Vysyx_25050147_top___024root__trace_chg_top_0, vlSelf);
    tracep->addCleanupCb(&Vysyx_25050147_top___024root__trace_cleanup, vlSelf);
}

VL_ATTR_COLD void Vysyx_25050147_top___024root__trace_full_sub_0(Vysyx_25050147_top___024root* vlSelf, VerilatedVcd::Buffer* bufp);

VL_ATTR_COLD void Vysyx_25050147_top___024root__trace_full_top_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vysyx_25050147_top___024root__trace_full_top_0\n"); );
    // Init
    Vysyx_25050147_top___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vysyx_25050147_top___024root*>(voidSelf);
    Vysyx_25050147_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    Vysyx_25050147_top___024root__trace_full_sub_0((&vlSymsp->TOP), bufp);
}

VL_ATTR_COLD void Vysyx_25050147_top___024root__trace_full_sub_0(Vysyx_25050147_top___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    if (false && vlSelf) {}  // Prevent unused
    Vysyx_25050147_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vysyx_25050147_top___024root__trace_full_sub_0\n"); );
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode);
    // Body
    bufp->fullIData(oldp+1,(vlSelf->ysyx_25050147_top__DOT__mem),32);
    bufp->fullCData(oldp+2,((0x1fU & (vlSelf->ysyx_25050147_top__DOT__inst 
                                      >> 7U))),5);
    bufp->fullIData(oldp+3,(((2U & vlSelf->ysyx_25050147_top__DOT__waddr_mem)
                              ? ((1U & vlSelf->ysyx_25050147_top__DOT__waddr_mem)
                                  ? (vlSelf->ysyx_25050147_top__DOT__memstore_change__DOT__result 
                                     << 0x18U) : (vlSelf->ysyx_25050147_top__DOT__memstore_change__DOT__result 
                                                  << 0x10U))
                              : ((1U & vlSelf->ysyx_25050147_top__DOT__waddr_mem)
                                  ? (vlSelf->ysyx_25050147_top__DOT__memstore_change__DOT__result 
                                     << 8U) : vlSelf->ysyx_25050147_top__DOT__memstore_change__DOT__result))),32);
    bufp->fullIData(oldp+4,(vlSelf->ysyx_25050147_top__DOT__waddr_mem),32);
    bufp->fullCData(oldp+5,(((2U & vlSelf->ysyx_25050147_top__DOT__waddr_mem)
                              ? ((1U & vlSelf->ysyx_25050147_top__DOT__waddr_mem)
                                  ? (0xf8U & ((IData)(vlSelf->ysyx_25050147_top__DOT__memstore_change__DOT__wmask1) 
                                              << 3U))
                                  : (0xfcU & ((IData)(vlSelf->ysyx_25050147_top__DOT__memstore_change__DOT__wmask1) 
                                              << 2U)))
                              : ((1U & vlSelf->ysyx_25050147_top__DOT__waddr_mem)
                                  ? (0xfeU & ((IData)(vlSelf->ysyx_25050147_top__DOT__memstore_change__DOT__wmask1) 
                                              << 1U))
                                  : (IData)(vlSelf->ysyx_25050147_top__DOT__memstore_change__DOT__wmask1)))),8);
    bufp->fullBit(oldp+6,(((~ (IData)((0U != (0x14U 
                                              & (IData)(vlSelf->ysyx_25050147_top__DOT__op_type))))) 
                           & (0U != (0x1fU & (vlSelf->ysyx_25050147_top__DOT__inst 
                                              >> 7U))))));
    bufp->fullIData(oldp+7,(vlSelf->ysyx_25050147_top__DOT__rdata1),32);
    bufp->fullCData(oldp+8,((0x1fU & (vlSelf->ysyx_25050147_top__DOT__inst 
                                      >> 0xfU))),5);
    bufp->fullIData(oldp+9,(vlSelf->ysyx_25050147_top__DOT__rdata2),32);
    bufp->fullCData(oldp+10,((0x1fU & (vlSelf->ysyx_25050147_top__DOT__inst 
                                       >> 0x14U))),5);
    bufp->fullCData(oldp+11,(vlSelf->ysyx_25050147_top__DOT__op_type),5);
    bufp->fullIData(oldp+12,(vlSelf->ysyx_25050147_top__DOT__src1),32);
    bufp->fullIData(oldp+13,(vlSelf->ysyx_25050147_top__DOT__src2),32);
    bufp->fullBit(oldp+14,((1U & ((IData)(vlSelf->ysyx_25050147_top__DOT__op_type) 
                                  >> 2U))));
    bufp->fullIData(oldp+15,(vlSelf->ysyx_25050147_top__DOT__inst),32);
    bufp->fullCData(oldp+16,(vlSelf->ysyx_25050147_top__DOT__alu_op),4);
    bufp->fullIData(oldp+17,((((- (IData)((vlSelf->ysyx_25050147_top__DOT__inst 
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
    bufp->fullIData(oldp+18,(((0x4000U & vlSelf->ysyx_25050147_top__DOT__inst)
                               ? ((0x2000U & vlSelf->ysyx_25050147_top__DOT__inst)
                                   ? ((0x1000U & vlSelf->ysyx_25050147_top__DOT__inst)
                                       ? 0U : vlSelf->ysyx_25050147_top__DOT__memload_change__DOT__mem_data)
                                   : ((0x1000U & vlSelf->ysyx_25050147_top__DOT__inst)
                                       ? (0xffffU & vlSelf->ysyx_25050147_top__DOT__memload_change__DOT__mem_data)
                                       : (0xffU & vlSelf->ysyx_25050147_top__DOT__memload_change__DOT__mem_data)))
                               : ((0x2000U & vlSelf->ysyx_25050147_top__DOT__inst)
                                   ? ((0x1000U & vlSelf->ysyx_25050147_top__DOT__inst)
                                       ? 0U : vlSelf->ysyx_25050147_top__DOT__memload_change__DOT__mem_data)
                                   : ((0x1000U & vlSelf->ysyx_25050147_top__DOT__inst)
                                       ? (((- (IData)(
                                                      (1U 
                                                       & (vlSelf->ysyx_25050147_top__DOT__memload_change__DOT__mem_data 
                                                          >> 0xfU)))) 
                                           << 0x10U) 
                                          | (0xffffU 
                                             & vlSelf->ysyx_25050147_top__DOT__memload_change__DOT__mem_data))
                                       : (((- (IData)(
                                                      (1U 
                                                       & (vlSelf->ysyx_25050147_top__DOT__memload_change__DOT__mem_data 
                                                          >> 7U)))) 
                                           << 8U) | 
                                          (0xffU & vlSelf->ysyx_25050147_top__DOT__memload_change__DOT__mem_data)))))),32);
    bufp->fullBit(oldp+19,((IData)((((IData)(vlSelf->ysyx_25050147_top__DOT__op_type) 
                                     >> 4U) & vlSelf->ysyx_25050147_top__DOT__waddr_mem))));
    bufp->fullBit(oldp+20,((1U & ((IData)(vlSelf->ysyx_25050147_top__DOT__op_type) 
                                  >> 4U))));
    bufp->fullBit(oldp+21,((0U == (IData)(vlSelf->ysyx_25050147_top__DOT__op_type))));
    bufp->fullIData(oldp+22,(vlSelf->ysyx_25050147_top__DOT__exu__DOT__myalu__DOT__result),32);
    bufp->fullBit(oldp+23,((1U & (~ (IData)((0U != vlSelf->ysyx_25050147_top__DOT__exu__DOT__myalu__DOT__Result))))));
    bufp->fullBit(oldp+24,((((vlSelf->ysyx_25050147_top__DOT__src1 
                              >> 0x1fU) == (vlSelf->ysyx_25050147_top__DOT__exu__DOT__myalu__DOT__t_no_Cin 
                                            >> 0x1fU)) 
                            & ((vlSelf->ysyx_25050147_top__DOT__exu__DOT__myalu__DOT__Result 
                                >> 0x1fU) != (vlSelf->ysyx_25050147_top__DOT__src1 
                                              >> 0x1fU)))));
    bufp->fullIData(oldp+25,(vlSelf->ysyx_25050147_top__DOT__exu__DOT__myalu__DOT__Result),32);
    bufp->fullIData(oldp+26,(vlSelf->ysyx_25050147_top__DOT__exu__DOT__myalu__DOT__t_no_Cin),32);
    bufp->fullBit(oldp+27,(vlSelf->ysyx_25050147_top__DOT__exu__DOT__myalu__DOT__Carry));
    bufp->fullBit(oldp+28,(vlSelf->ysyx_25050147_top__DOT__exu__DOT__myalu__DOT__Cin));
    bufp->fullBit(oldp+29,(vlSelf->ysyx_25050147_top__DOT__exu__DOT__myalu__DOT__is_branch));
    bufp->fullIData(oldp+30,(vlSelf->ysyx_25050147_top__DOT__idu__DOT__op_src2_I),32);
    bufp->fullIData(oldp+31,((0xfffff000U & vlSelf->ysyx_25050147_top__DOT__inst)),32);
    bufp->fullIData(oldp+32,((((- (IData)((vlSelf->ysyx_25050147_top__DOT__inst 
                                           >> 0x1fU))) 
                               << 0x14U) | ((0xff000U 
                                             & vlSelf->ysyx_25050147_top__DOT__inst) 
                                            | ((0x800U 
                                                & (vlSelf->ysyx_25050147_top__DOT__inst 
                                                   >> 9U)) 
                                               | (0x7feU 
                                                  & (vlSelf->ysyx_25050147_top__DOT__inst 
                                                     >> 0x14U)))))),32);
    bufp->fullIData(oldp+33,((((- (IData)((vlSelf->ysyx_25050147_top__DOT__inst 
                                           >> 0x1fU))) 
                               << 0xcU) | ((0xfe0U 
                                            & (vlSelf->ysyx_25050147_top__DOT__inst 
                                               >> 0x14U)) 
                                           | (0x1fU 
                                              & (vlSelf->ysyx_25050147_top__DOT__inst 
                                                 >> 7U))))),32);
    bufp->fullCData(oldp+34,((7U & (vlSelf->ysyx_25050147_top__DOT__inst 
                                    >> 0xcU))),3);
    bufp->fullCData(oldp+35,((3U & vlSelf->ysyx_25050147_top__DOT__waddr_mem)),2);
    bufp->fullIData(oldp+36,(vlSelf->ysyx_25050147_top__DOT__memload_change__DOT__mem_data),32);
    bufp->fullCData(oldp+37,(vlSelf->ysyx_25050147_top__DOT__memstore_change__DOT__wmask1),8);
    bufp->fullIData(oldp+38,(vlSelf->ysyx_25050147_top__DOT__memstore_change__DOT__result),32);
    bufp->fullIData(oldp+39,(vlSelf->ysyx_25050147_top__DOT__rfile__DOT__rf[0]),32);
    bufp->fullIData(oldp+40,(vlSelf->ysyx_25050147_top__DOT__rfile__DOT__rf[1]),32);
    bufp->fullIData(oldp+41,(vlSelf->ysyx_25050147_top__DOT__rfile__DOT__rf[2]),32);
    bufp->fullIData(oldp+42,(vlSelf->ysyx_25050147_top__DOT__rfile__DOT__rf[3]),32);
    bufp->fullIData(oldp+43,(vlSelf->ysyx_25050147_top__DOT__rfile__DOT__rf[4]),32);
    bufp->fullIData(oldp+44,(vlSelf->ysyx_25050147_top__DOT__rfile__DOT__rf[5]),32);
    bufp->fullIData(oldp+45,(vlSelf->ysyx_25050147_top__DOT__rfile__DOT__rf[6]),32);
    bufp->fullIData(oldp+46,(vlSelf->ysyx_25050147_top__DOT__rfile__DOT__rf[7]),32);
    bufp->fullIData(oldp+47,(vlSelf->ysyx_25050147_top__DOT__rfile__DOT__rf[8]),32);
    bufp->fullIData(oldp+48,(vlSelf->ysyx_25050147_top__DOT__rfile__DOT__rf[9]),32);
    bufp->fullIData(oldp+49,(vlSelf->ysyx_25050147_top__DOT__rfile__DOT__rf[10]),32);
    bufp->fullIData(oldp+50,(vlSelf->ysyx_25050147_top__DOT__rfile__DOT__rf[11]),32);
    bufp->fullIData(oldp+51,(vlSelf->ysyx_25050147_top__DOT__rfile__DOT__rf[12]),32);
    bufp->fullIData(oldp+52,(vlSelf->ysyx_25050147_top__DOT__rfile__DOT__rf[13]),32);
    bufp->fullIData(oldp+53,(vlSelf->ysyx_25050147_top__DOT__rfile__DOT__rf[14]),32);
    bufp->fullIData(oldp+54,(vlSelf->ysyx_25050147_top__DOT__rfile__DOT__rf[15]),32);
    bufp->fullIData(oldp+55,(vlSelf->ysyx_25050147_top__DOT__rfile__DOT__rf[16]),32);
    bufp->fullIData(oldp+56,(vlSelf->ysyx_25050147_top__DOT__rfile__DOT__rf[17]),32);
    bufp->fullIData(oldp+57,(vlSelf->ysyx_25050147_top__DOT__rfile__DOT__rf[18]),32);
    bufp->fullIData(oldp+58,(vlSelf->ysyx_25050147_top__DOT__rfile__DOT__rf[19]),32);
    bufp->fullIData(oldp+59,(vlSelf->ysyx_25050147_top__DOT__rfile__DOT__rf[20]),32);
    bufp->fullIData(oldp+60,(vlSelf->ysyx_25050147_top__DOT__rfile__DOT__rf[21]),32);
    bufp->fullIData(oldp+61,(vlSelf->ysyx_25050147_top__DOT__rfile__DOT__rf[22]),32);
    bufp->fullIData(oldp+62,(vlSelf->ysyx_25050147_top__DOT__rfile__DOT__rf[23]),32);
    bufp->fullIData(oldp+63,(vlSelf->ysyx_25050147_top__DOT__rfile__DOT__rf[24]),32);
    bufp->fullIData(oldp+64,(vlSelf->ysyx_25050147_top__DOT__rfile__DOT__rf[25]),32);
    bufp->fullIData(oldp+65,(vlSelf->ysyx_25050147_top__DOT__rfile__DOT__rf[26]),32);
    bufp->fullIData(oldp+66,(vlSelf->ysyx_25050147_top__DOT__rfile__DOT__rf[27]),32);
    bufp->fullIData(oldp+67,(vlSelf->ysyx_25050147_top__DOT__rfile__DOT__rf[28]),32);
    bufp->fullIData(oldp+68,(vlSelf->ysyx_25050147_top__DOT__rfile__DOT__rf[29]),32);
    bufp->fullIData(oldp+69,(vlSelf->ysyx_25050147_top__DOT__rfile__DOT__rf[30]),32);
    bufp->fullIData(oldp+70,(vlSelf->ysyx_25050147_top__DOT__rfile__DOT__rf[31]),32);
    bufp->fullBit(oldp+71,(vlSelf->rst));
    bufp->fullBit(oldp+72,(vlSelf->clk));
    bufp->fullIData(oldp+73,(vlSelf->pc),32);
    bufp->fullIData(oldp+74,(((1U & (IData)(vlSelf->ysyx_25050147_top__DOT__op_type))
                               ? ((IData)(4U) + vlSelf->pc)
                               : ((8U & (IData)(vlSelf->ysyx_25050147_top__DOT__op_type))
                                   ? ((0x4000U & vlSelf->ysyx_25050147_top__DOT__inst)
                                       ? ((0x2000U 
                                           & vlSelf->ysyx_25050147_top__DOT__inst)
                                           ? ((0x1000U 
                                               & vlSelf->ysyx_25050147_top__DOT__inst)
                                               ? 0U
                                               : vlSelf->ysyx_25050147_top__DOT__memload_change__DOT__mem_data)
                                           : ((0x1000U 
                                               & vlSelf->ysyx_25050147_top__DOT__inst)
                                               ? (0xffffU 
                                                  & vlSelf->ysyx_25050147_top__DOT__memload_change__DOT__mem_data)
                                               : (0xffU 
                                                  & vlSelf->ysyx_25050147_top__DOT__memload_change__DOT__mem_data)))
                                       : ((0x2000U 
                                           & vlSelf->ysyx_25050147_top__DOT__inst)
                                           ? ((0x1000U 
                                               & vlSelf->ysyx_25050147_top__DOT__inst)
                                               ? 0U
                                               : vlSelf->ysyx_25050147_top__DOT__memload_change__DOT__mem_data)
                                           : ((0x1000U 
                                               & vlSelf->ysyx_25050147_top__DOT__inst)
                                               ? ((
                                                   (- (IData)(
                                                              (1U 
                                                               & (vlSelf->ysyx_25050147_top__DOT__memload_change__DOT__mem_data 
                                                                  >> 0xfU)))) 
                                                   << 0x10U) 
                                                  | (0xffffU 
                                                     & vlSelf->ysyx_25050147_top__DOT__memload_change__DOT__mem_data))
                                               : ((
                                                   (- (IData)(
                                                              (1U 
                                                               & (vlSelf->ysyx_25050147_top__DOT__memload_change__DOT__mem_data 
                                                                  >> 7U)))) 
                                                   << 8U) 
                                                  | (0xffU 
                                                     & vlSelf->ysyx_25050147_top__DOT__memload_change__DOT__mem_data)))))
                                   : vlSelf->ysyx_25050147_top__DOT__waddr_mem))),32);
    bufp->fullIData(oldp+75,(((IData)(4U) + vlSelf->pc)),32);
    bufp->fullIData(oldp+76,(((1U == (IData)(vlSelf->ysyx_25050147_top__DOT__op_type))
                               ? vlSelf->ysyx_25050147_top__DOT__waddr_mem
                               : ((IData)((((IData)(vlSelf->ysyx_25050147_top__DOT__op_type) 
                                            >> 4U) 
                                           & vlSelf->ysyx_25050147_top__DOT__waddr_mem))
                                   ? ((((- (IData)(
                                                   (vlSelf->ysyx_25050147_top__DOT__inst 
                                                    >> 0x1fU))) 
                                        << 0xcU) | 
                                       ((0x800U & (vlSelf->ysyx_25050147_top__DOT__inst 
                                                   << 4U)) 
                                        | ((0x7e0U 
                                            & (vlSelf->ysyx_25050147_top__DOT__inst 
                                               >> 0x14U)) 
                                           | (0x1eU 
                                              & (vlSelf->ysyx_25050147_top__DOT__inst 
                                                 >> 7U))))) 
                                      + vlSelf->pc)
                                   : ((IData)(4U) + vlSelf->pc)))),32);
    bufp->fullIData(oldp+77,(((((- (IData)((vlSelf->ysyx_25050147_top__DOT__inst 
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
    bufp->fullIData(oldp+78,(0x20U),32);
    bufp->fullIData(oldp+79,(0x80000000U),32);
    bufp->fullBit(oldp+80,(1U));
    bufp->fullIData(oldp+81,(0U),32);
    bufp->fullIData(oldp+82,(1U),32);
    bufp->fullIData(oldp+83,(2U),32);
    bufp->fullIData(oldp+84,(4U),32);
    bufp->fullIData(oldp+85,(8U),32);
    bufp->fullIData(oldp+86,(0x10U),32);
    bufp->fullCData(oldp+87,(5U),3);
    bufp->fullCData(oldp+88,(0x20U),6);
}
