// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vysyx_25050147_top.h for the primary calling header

#include "verilated.h"
#include "verilated_dpi.h"

#include "Vysyx_25050147_top__Syms.h"
#include "Vysyx_25050147_top___024root.h"

#ifdef VL_DEBUG
VL_ATTR_COLD void Vysyx_25050147_top___024root___dump_triggers__stl(Vysyx_25050147_top___024root* vlSelf);
#endif  // VL_DEBUG

VL_ATTR_COLD void Vysyx_25050147_top___024root___eval_triggers__stl(Vysyx_25050147_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vysyx_25050147_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vysyx_25050147_top___024root___eval_triggers__stl\n"); );
    // Body
    vlSelf->__VstlTriggered.at(0U) = (0U == vlSelf->__VstlIterCount);
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vysyx_25050147_top___024root___dump_triggers__stl(vlSelf);
    }
#endif
}

void Vysyx_25050147_top___024unit____Vdpiimwrap_pmem_read_TOP____024unit(IData/*31:0*/ raddr, IData/*31:0*/ &pmem_read__Vfuncrtn);
extern const VlUnpacked<CData/*0:0*/, 128> Vysyx_25050147_top__ConstPool__TABLE_h2c44e8aa_0;
extern const VlUnpacked<CData/*0:0*/, 128> Vysyx_25050147_top__ConstPool__TABLE_h674ad7e6_0;
void Vysyx_25050147_top___024unit____Vdpiimwrap_pmem_write_TOP____024unit(IData/*31:0*/ waddr, IData/*31:0*/ wdata, CData/*7:0*/ wmask);

VL_ATTR_COLD void Vysyx_25050147_top___024root___stl_sequent__TOP__0(Vysyx_25050147_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vysyx_25050147_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vysyx_25050147_top___024root___stl_sequent__TOP__0\n"); );
    // Body
    Vysyx_25050147_top___024unit____Vdpiimwrap_pmem_read_TOP____024unit(vlSelf->pc, vlSelf->__Vfunc_pmem_read__0__Vfuncout);
    vlSelf->ysyx_25050147_top__DOT__inst = vlSelf->__Vfunc_pmem_read__0__Vfuncout;
    vlSelf->ysyx_25050147_top__DOT__rdata1 = vlSelf->ysyx_25050147_top__DOT__rfile__DOT__rf
        [(0x1fU & (vlSelf->ysyx_25050147_top__DOT__inst 
                   >> 0xfU))];
    vlSelf->ysyx_25050147_top__DOT__idu__DOT__op_src2_I 
        = (((- (IData)((vlSelf->ysyx_25050147_top__DOT__inst 
                        >> 0x1fU))) << 0xcU) | (vlSelf->ysyx_25050147_top__DOT__inst 
                                                >> 0x14U));
    vlSelf->ysyx_25050147_top__DOT__rdata2 = vlSelf->ysyx_25050147_top__DOT__rfile__DOT__rf
        [(0x1fU & (vlSelf->ysyx_25050147_top__DOT__inst 
                   >> 0x14U))];
    if ((0x4000U & vlSelf->ysyx_25050147_top__DOT__inst)) {
        if ((0x2000U & vlSelf->ysyx_25050147_top__DOT__inst)) {
            vlSelf->ysyx_25050147_top__DOT__memstore_change__DOT__wmask1 = 0xfU;
            vlSelf->ysyx_25050147_top__DOT__memstore_change__DOT__result 
                = ((0x1000U & vlSelf->ysyx_25050147_top__DOT__inst)
                    ? 0U : vlSelf->ysyx_25050147_top__DOT__rdata2);
        } else if ((0x1000U & vlSelf->ysyx_25050147_top__DOT__inst)) {
            vlSelf->ysyx_25050147_top__DOT__memstore_change__DOT__wmask1 = 3U;
            vlSelf->ysyx_25050147_top__DOT__memstore_change__DOT__result 
                = (0xffffU & vlSelf->ysyx_25050147_top__DOT__rdata2);
        } else {
            vlSelf->ysyx_25050147_top__DOT__memstore_change__DOT__wmask1 = 1U;
            vlSelf->ysyx_25050147_top__DOT__memstore_change__DOT__result 
                = (0xffU & vlSelf->ysyx_25050147_top__DOT__rdata2);
        }
    } else if ((0x2000U & vlSelf->ysyx_25050147_top__DOT__inst)) {
        vlSelf->ysyx_25050147_top__DOT__memstore_change__DOT__wmask1 = 0xfU;
        vlSelf->ysyx_25050147_top__DOT__memstore_change__DOT__result 
            = ((0x1000U & vlSelf->ysyx_25050147_top__DOT__inst)
                ? 0U : vlSelf->ysyx_25050147_top__DOT__rdata2);
    } else if ((0x1000U & vlSelf->ysyx_25050147_top__DOT__inst)) {
        vlSelf->ysyx_25050147_top__DOT__memstore_change__DOT__wmask1 = 3U;
        vlSelf->ysyx_25050147_top__DOT__memstore_change__DOT__result 
            = (((- (IData)((1U & (vlSelf->ysyx_25050147_top__DOT__rdata2 
                                  >> 0xfU)))) << 0x10U) 
               | (0xffffU & vlSelf->ysyx_25050147_top__DOT__rdata2));
    } else {
        vlSelf->ysyx_25050147_top__DOT__memstore_change__DOT__wmask1 = 1U;
        vlSelf->ysyx_25050147_top__DOT__memstore_change__DOT__result 
            = (((- (IData)((1U & (vlSelf->ysyx_25050147_top__DOT__rdata2 
                                  >> 7U)))) << 8U) 
               | (0xffU & vlSelf->ysyx_25050147_top__DOT__rdata2));
    }
    if ((0x40U & vlSelf->ysyx_25050147_top__DOT__inst)) {
        if ((0x20U & vlSelf->ysyx_25050147_top__DOT__inst)) {
            if ((0x10U & vlSelf->ysyx_25050147_top__DOT__inst)) {
                vlSelf->ysyx_25050147_top__DOT__op_type 
                    = ((8U & vlSelf->ysyx_25050147_top__DOT__inst)
                        ? 2U : ((4U & vlSelf->ysyx_25050147_top__DOT__inst)
                                 ? 2U : ((2U & vlSelf->ysyx_25050147_top__DOT__inst)
                                          ? ((1U & vlSelf->ysyx_25050147_top__DOT__inst)
                                              ? 0U : 2U)
                                          : 2U)));
                vlSelf->ysyx_25050147_top__DOT__alu_op = 0U;
                vlSelf->ysyx_25050147_top__DOT__src1 = 0U;
                vlSelf->ysyx_25050147_top__DOT__src2 = 0U;
            } else if ((8U & vlSelf->ysyx_25050147_top__DOT__inst)) {
                if ((4U & vlSelf->ysyx_25050147_top__DOT__inst)) {
                    if ((2U & vlSelf->ysyx_25050147_top__DOT__inst)) {
                        if ((1U & vlSelf->ysyx_25050147_top__DOT__inst)) {
                            vlSelf->ysyx_25050147_top__DOT__op_type = 1U;
                            vlSelf->ysyx_25050147_top__DOT__src1 
                                = (((- (IData)((vlSelf->ysyx_25050147_top__DOT__inst 
                                                >> 0x1fU))) 
                                    << 0x14U) | ((0xff000U 
                                                  & vlSelf->ysyx_25050147_top__DOT__inst) 
                                                 | ((0x800U 
                                                     & (vlSelf->ysyx_25050147_top__DOT__inst 
                                                        >> 9U)) 
                                                    | (0x7feU 
                                                       & (vlSelf->ysyx_25050147_top__DOT__inst 
                                                          >> 0x14U)))));
                            vlSelf->ysyx_25050147_top__DOT__src2 
                                = vlSelf->pc;
                        } else {
                            vlSelf->ysyx_25050147_top__DOT__op_type = 2U;
                            vlSelf->ysyx_25050147_top__DOT__src1 = 0U;
                            vlSelf->ysyx_25050147_top__DOT__src2 = 0U;
                        }
                    } else {
                        vlSelf->ysyx_25050147_top__DOT__op_type = 2U;
                        vlSelf->ysyx_25050147_top__DOT__src1 = 0U;
                        vlSelf->ysyx_25050147_top__DOT__src2 = 0U;
                    }
                } else {
                    vlSelf->ysyx_25050147_top__DOT__op_type = 2U;
                    vlSelf->ysyx_25050147_top__DOT__src1 = 0U;
                    vlSelf->ysyx_25050147_top__DOT__src2 = 0U;
                }
                vlSelf->ysyx_25050147_top__DOT__alu_op = 0U;
            } else if ((4U & vlSelf->ysyx_25050147_top__DOT__inst)) {
                if ((2U & vlSelf->ysyx_25050147_top__DOT__inst)) {
                    if ((1U & vlSelf->ysyx_25050147_top__DOT__inst)) {
                        vlSelf->ysyx_25050147_top__DOT__op_type = 1U;
                        vlSelf->ysyx_25050147_top__DOT__src1 
                            = vlSelf->ysyx_25050147_top__DOT__rdata1;
                        vlSelf->ysyx_25050147_top__DOT__src2 
                            = vlSelf->ysyx_25050147_top__DOT__idu__DOT__op_src2_I;
                    } else {
                        vlSelf->ysyx_25050147_top__DOT__op_type = 2U;
                        vlSelf->ysyx_25050147_top__DOT__src1 = 0U;
                        vlSelf->ysyx_25050147_top__DOT__src2 = 0U;
                    }
                } else {
                    vlSelf->ysyx_25050147_top__DOT__op_type = 2U;
                    vlSelf->ysyx_25050147_top__DOT__src1 = 0U;
                    vlSelf->ysyx_25050147_top__DOT__src2 = 0U;
                }
                vlSelf->ysyx_25050147_top__DOT__alu_op = 0U;
            } else if ((2U & vlSelf->ysyx_25050147_top__DOT__inst)) {
                if ((1U & vlSelf->ysyx_25050147_top__DOT__inst)) {
                    vlSelf->ysyx_25050147_top__DOT__op_type = 0x10U;
                    vlSelf->ysyx_25050147_top__DOT__alu_op 
                        = (7U & (vlSelf->ysyx_25050147_top__DOT__inst 
                                 >> 0xcU));
                    vlSelf->ysyx_25050147_top__DOT__src1 
                        = vlSelf->ysyx_25050147_top__DOT__rdata1;
                    vlSelf->ysyx_25050147_top__DOT__src2 
                        = vlSelf->ysyx_25050147_top__DOT__rdata2;
                } else {
                    vlSelf->ysyx_25050147_top__DOT__op_type = 2U;
                    vlSelf->ysyx_25050147_top__DOT__alu_op = 0U;
                    vlSelf->ysyx_25050147_top__DOT__src1 = 0U;
                    vlSelf->ysyx_25050147_top__DOT__src2 = 0U;
                }
            } else {
                vlSelf->ysyx_25050147_top__DOT__op_type = 2U;
                vlSelf->ysyx_25050147_top__DOT__alu_op = 0U;
                vlSelf->ysyx_25050147_top__DOT__src1 = 0U;
                vlSelf->ysyx_25050147_top__DOT__src2 = 0U;
            }
        } else {
            vlSelf->ysyx_25050147_top__DOT__op_type = 2U;
            vlSelf->ysyx_25050147_top__DOT__alu_op = 0U;
            vlSelf->ysyx_25050147_top__DOT__src1 = 0U;
            vlSelf->ysyx_25050147_top__DOT__src2 = 0U;
        }
    } else if ((0x20U & vlSelf->ysyx_25050147_top__DOT__inst)) {
        if ((0x10U & vlSelf->ysyx_25050147_top__DOT__inst)) {
            vlSelf->ysyx_25050147_top__DOT__op_type = 2U;
            if ((8U & vlSelf->ysyx_25050147_top__DOT__inst)) {
                vlSelf->ysyx_25050147_top__DOT__alu_op = 0U;
                vlSelf->ysyx_25050147_top__DOT__src1 = 0U;
                vlSelf->ysyx_25050147_top__DOT__src2 = 0U;
            } else if ((4U & vlSelf->ysyx_25050147_top__DOT__inst)) {
                vlSelf->ysyx_25050147_top__DOT__alu_op = 0U;
                vlSelf->ysyx_25050147_top__DOT__src1 
                    = ((2U & vlSelf->ysyx_25050147_top__DOT__inst)
                        ? ((1U & vlSelf->ysyx_25050147_top__DOT__inst)
                            ? (0xfffff000U & vlSelf->ysyx_25050147_top__DOT__inst)
                            : 0U) : 0U);
                vlSelf->ysyx_25050147_top__DOT__src2 = 0U;
            } else if ((2U & vlSelf->ysyx_25050147_top__DOT__inst)) {
                if ((1U & vlSelf->ysyx_25050147_top__DOT__inst)) {
                    vlSelf->ysyx_25050147_top__DOT__alu_op 
                        = ((8U & (vlSelf->ysyx_25050147_top__DOT__inst 
                                  >> 0x1bU)) | (7U 
                                                & (vlSelf->ysyx_25050147_top__DOT__inst 
                                                   >> 0xcU)));
                    vlSelf->ysyx_25050147_top__DOT__src1 
                        = vlSelf->ysyx_25050147_top__DOT__rdata1;
                    vlSelf->ysyx_25050147_top__DOT__src2 
                        = vlSelf->ysyx_25050147_top__DOT__rdata2;
                } else {
                    vlSelf->ysyx_25050147_top__DOT__alu_op = 0U;
                    vlSelf->ysyx_25050147_top__DOT__src1 = 0U;
                    vlSelf->ysyx_25050147_top__DOT__src2 = 0U;
                }
            } else {
                vlSelf->ysyx_25050147_top__DOT__alu_op = 0U;
                vlSelf->ysyx_25050147_top__DOT__src1 = 0U;
                vlSelf->ysyx_25050147_top__DOT__src2 = 0U;
            }
        } else {
            if ((8U & vlSelf->ysyx_25050147_top__DOT__inst)) {
                vlSelf->ysyx_25050147_top__DOT__op_type = 2U;
                vlSelf->ysyx_25050147_top__DOT__src1 = 0U;
                vlSelf->ysyx_25050147_top__DOT__src2 = 0U;
            } else if ((4U & vlSelf->ysyx_25050147_top__DOT__inst)) {
                vlSelf->ysyx_25050147_top__DOT__op_type = 2U;
                vlSelf->ysyx_25050147_top__DOT__src1 = 0U;
                vlSelf->ysyx_25050147_top__DOT__src2 = 0U;
            } else if ((2U & vlSelf->ysyx_25050147_top__DOT__inst)) {
                if ((1U & vlSelf->ysyx_25050147_top__DOT__inst)) {
                    vlSelf->ysyx_25050147_top__DOT__op_type = 4U;
                    vlSelf->ysyx_25050147_top__DOT__src1 
                        = vlSelf->ysyx_25050147_top__DOT__rdata1;
                    vlSelf->ysyx_25050147_top__DOT__src2 
                        = (((- (IData)((vlSelf->ysyx_25050147_top__DOT__inst 
                                        >> 0x1fU))) 
                            << 0xcU) | ((0xfe0U & (vlSelf->ysyx_25050147_top__DOT__inst 
                                                   >> 0x14U)) 
                                        | (0x1fU & 
                                           (vlSelf->ysyx_25050147_top__DOT__inst 
                                            >> 7U))));
                } else {
                    vlSelf->ysyx_25050147_top__DOT__op_type = 2U;
                    vlSelf->ysyx_25050147_top__DOT__src1 = 0U;
                    vlSelf->ysyx_25050147_top__DOT__src2 = 0U;
                }
            } else {
                vlSelf->ysyx_25050147_top__DOT__op_type = 2U;
                vlSelf->ysyx_25050147_top__DOT__src1 = 0U;
                vlSelf->ysyx_25050147_top__DOT__src2 = 0U;
            }
            vlSelf->ysyx_25050147_top__DOT__alu_op = 0U;
        }
    } else if ((0x10U & vlSelf->ysyx_25050147_top__DOT__inst)) {
        vlSelf->ysyx_25050147_top__DOT__op_type = 2U;
        if ((8U & vlSelf->ysyx_25050147_top__DOT__inst)) {
            vlSelf->ysyx_25050147_top__DOT__alu_op = 0U;
            vlSelf->ysyx_25050147_top__DOT__src1 = 0U;
            vlSelf->ysyx_25050147_top__DOT__src2 = 0U;
        } else if ((4U & vlSelf->ysyx_25050147_top__DOT__inst)) {
            vlSelf->ysyx_25050147_top__DOT__alu_op = 0U;
            if ((2U & vlSelf->ysyx_25050147_top__DOT__inst)) {
                if ((1U & vlSelf->ysyx_25050147_top__DOT__inst)) {
                    vlSelf->ysyx_25050147_top__DOT__src1 
                        = (0xfffff000U & vlSelf->ysyx_25050147_top__DOT__inst);
                    vlSelf->ysyx_25050147_top__DOT__src2 
                        = vlSelf->pc;
                } else {
                    vlSelf->ysyx_25050147_top__DOT__src1 = 0U;
                    vlSelf->ysyx_25050147_top__DOT__src2 = 0U;
                }
            } else {
                vlSelf->ysyx_25050147_top__DOT__src1 = 0U;
                vlSelf->ysyx_25050147_top__DOT__src2 = 0U;
            }
        } else if ((2U & vlSelf->ysyx_25050147_top__DOT__inst)) {
            if ((1U & vlSelf->ysyx_25050147_top__DOT__inst)) {
                vlSelf->ysyx_25050147_top__DOT__alu_op 
                    = ((((vlSelf->ysyx_25050147_top__DOT__inst 
                          >> 0x1eU) & (0U != (0x7000U 
                                              & vlSelf->ysyx_25050147_top__DOT__inst))) 
                        << 3U) | (7U & (vlSelf->ysyx_25050147_top__DOT__inst 
                                        >> 0xcU)));
                vlSelf->ysyx_25050147_top__DOT__src1 
                    = vlSelf->ysyx_25050147_top__DOT__rdata1;
                vlSelf->ysyx_25050147_top__DOT__src2 
                    = vlSelf->ysyx_25050147_top__DOT__idu__DOT__op_src2_I;
            } else {
                vlSelf->ysyx_25050147_top__DOT__alu_op = 0U;
                vlSelf->ysyx_25050147_top__DOT__src1 = 0U;
                vlSelf->ysyx_25050147_top__DOT__src2 = 0U;
            }
        } else {
            vlSelf->ysyx_25050147_top__DOT__alu_op = 0U;
            vlSelf->ysyx_25050147_top__DOT__src1 = 0U;
            vlSelf->ysyx_25050147_top__DOT__src2 = 0U;
        }
    } else {
        if ((8U & vlSelf->ysyx_25050147_top__DOT__inst)) {
            vlSelf->ysyx_25050147_top__DOT__op_type = 2U;
            vlSelf->ysyx_25050147_top__DOT__src1 = 0U;
            vlSelf->ysyx_25050147_top__DOT__src2 = 0U;
        } else if ((4U & vlSelf->ysyx_25050147_top__DOT__inst)) {
            vlSelf->ysyx_25050147_top__DOT__op_type = 2U;
            vlSelf->ysyx_25050147_top__DOT__src1 = 0U;
            vlSelf->ysyx_25050147_top__DOT__src2 = 0U;
        } else if ((2U & vlSelf->ysyx_25050147_top__DOT__inst)) {
            if ((1U & vlSelf->ysyx_25050147_top__DOT__inst)) {
                vlSelf->ysyx_25050147_top__DOT__op_type = 8U;
                vlSelf->ysyx_25050147_top__DOT__src1 
                    = vlSelf->ysyx_25050147_top__DOT__rdata1;
                vlSelf->ysyx_25050147_top__DOT__src2 
                    = vlSelf->ysyx_25050147_top__DOT__idu__DOT__op_src2_I;
            } else {
                vlSelf->ysyx_25050147_top__DOT__op_type = 2U;
                vlSelf->ysyx_25050147_top__DOT__src1 = 0U;
                vlSelf->ysyx_25050147_top__DOT__src2 = 0U;
            }
        } else {
            vlSelf->ysyx_25050147_top__DOT__op_type = 2U;
            vlSelf->ysyx_25050147_top__DOT__src1 = 0U;
            vlSelf->ysyx_25050147_top__DOT__src2 = 0U;
        }
        vlSelf->ysyx_25050147_top__DOT__alu_op = 0U;
    }
    vlSelf->ysyx_25050147_top__DOT__exu__DOT__myalu__DOT__Cin 
        = (1U & (IData)(((0U != (0xaU & (IData)(vlSelf->ysyx_25050147_top__DOT__alu_op))) 
                         | ((IData)(vlSelf->ysyx_25050147_top__DOT__op_type) 
                            >> 4U))));
    vlSelf->ysyx_25050147_top__DOT__exu__DOT__myalu__DOT__t_no_Cin 
        = ((- (IData)((IData)(vlSelf->ysyx_25050147_top__DOT__exu__DOT__myalu__DOT__Cin))) 
           ^ vlSelf->ysyx_25050147_top__DOT__src2);
    vlSelf->ysyx_25050147_top__DOT__exu__DOT__myalu__DOT__Carry 
        = (1U & (IData)((1ULL & (((QData)((IData)(vlSelf->ysyx_25050147_top__DOT__src1)) 
                                  + ((QData)((IData)(vlSelf->ysyx_25050147_top__DOT__exu__DOT__myalu__DOT__t_no_Cin)) 
                                     + (QData)((IData)(vlSelf->ysyx_25050147_top__DOT__exu__DOT__myalu__DOT__Cin)))) 
                                 >> 0x20U))));
    vlSelf->ysyx_25050147_top__DOT__exu__DOT__myalu__DOT__Result 
        = (vlSelf->ysyx_25050147_top__DOT__src1 + (vlSelf->ysyx_25050147_top__DOT__exu__DOT__myalu__DOT__t_no_Cin 
                                                   + (IData)(vlSelf->ysyx_25050147_top__DOT__exu__DOT__myalu__DOT__Cin)));
    vlSelf->ysyx_25050147_top__DOT__exu__DOT__myalu__DOT____VdfgExtracted_hf56215be__0 
        = (1U & ((vlSelf->ysyx_25050147_top__DOT__exu__DOT__myalu__DOT__Result 
                  >> 0x1fU) ^ (((vlSelf->ysyx_25050147_top__DOT__src1 
                                 >> 0x1fU) == (vlSelf->ysyx_25050147_top__DOT__exu__DOT__myalu__DOT__t_no_Cin 
                                               >> 0x1fU)) 
                               & ((vlSelf->ysyx_25050147_top__DOT__exu__DOT__myalu__DOT__Result 
                                   >> 0x1fU) != (vlSelf->ysyx_25050147_top__DOT__src1 
                                                 >> 0x1fU)))));
    vlSelf->ysyx_25050147_top__DOT__exu__DOT__myalu__DOT__result 
        = (((((((((0U == (IData)(vlSelf->ysyx_25050147_top__DOT__alu_op)) 
                  | (1U == (IData)(vlSelf->ysyx_25050147_top__DOT__alu_op))) 
                 | (2U == (IData)(vlSelf->ysyx_25050147_top__DOT__alu_op))) 
                | (3U == (IData)(vlSelf->ysyx_25050147_top__DOT__alu_op))) 
               | (0xaU == (IData)(vlSelf->ysyx_25050147_top__DOT__alu_op))) 
              | (0xbU == (IData)(vlSelf->ysyx_25050147_top__DOT__alu_op))) 
             | (4U == (IData)(vlSelf->ysyx_25050147_top__DOT__alu_op))) 
            | (0xcU == (IData)(vlSelf->ysyx_25050147_top__DOT__alu_op)))
            ? ((0U == (IData)(vlSelf->ysyx_25050147_top__DOT__alu_op))
                ? vlSelf->ysyx_25050147_top__DOT__exu__DOT__myalu__DOT__Result
                : ((1U == (IData)(vlSelf->ysyx_25050147_top__DOT__alu_op))
                    ? ((0x1fU >= (0x3fU & vlSelf->ysyx_25050147_top__DOT__src2))
                        ? (vlSelf->ysyx_25050147_top__DOT__src1 
                           << (0x3fU & vlSelf->ysyx_25050147_top__DOT__src2))
                        : 0U) : ((2U == (IData)(vlSelf->ysyx_25050147_top__DOT__alu_op))
                                  ? (IData)(vlSelf->ysyx_25050147_top__DOT__exu__DOT__myalu__DOT____VdfgExtracted_hf56215be__0)
                                  : ((3U == (IData)(vlSelf->ysyx_25050147_top__DOT__alu_op))
                                      ? (1U & (~ (IData)(vlSelf->ysyx_25050147_top__DOT__exu__DOT__myalu__DOT__Carry)))
                                      : ((0xaU == (IData)(vlSelf->ysyx_25050147_top__DOT__alu_op))
                                          ? (IData)(vlSelf->ysyx_25050147_top__DOT__exu__DOT__myalu__DOT____VdfgExtracted_hf56215be__0)
                                          : ((0xbU 
                                              == (IData)(vlSelf->ysyx_25050147_top__DOT__alu_op))
                                              ? (1U 
                                                 & (~ (IData)(vlSelf->ysyx_25050147_top__DOT__exu__DOT__myalu__DOT__Carry)))
                                              : ((4U 
                                                  == (IData)(vlSelf->ysyx_25050147_top__DOT__alu_op))
                                                  ? 
                                                 (vlSelf->ysyx_25050147_top__DOT__src1 
                                                  ^ vlSelf->ysyx_25050147_top__DOT__src2)
                                                  : 
                                                 (vlSelf->ysyx_25050147_top__DOT__src1 
                                                  ^ vlSelf->ysyx_25050147_top__DOT__src2))))))))
            : ((5U == (IData)(vlSelf->ysyx_25050147_top__DOT__alu_op))
                ? ((0x1fU >= (0x3fU & vlSelf->ysyx_25050147_top__DOT__src2))
                    ? (vlSelf->ysyx_25050147_top__DOT__src1 
                       >> (0x3fU & vlSelf->ysyx_25050147_top__DOT__src2))
                    : 0U) : ((6U == (IData)(vlSelf->ysyx_25050147_top__DOT__alu_op))
                              ? (vlSelf->ysyx_25050147_top__DOT__src1 
                                 | vlSelf->ysyx_25050147_top__DOT__src2)
                              : ((7U == (IData)(vlSelf->ysyx_25050147_top__DOT__alu_op))
                                  ? (vlSelf->ysyx_25050147_top__DOT__src1 
                                     & vlSelf->ysyx_25050147_top__DOT__src2)
                                  : ((0xeU == (IData)(vlSelf->ysyx_25050147_top__DOT__alu_op))
                                      ? (vlSelf->ysyx_25050147_top__DOT__src1 
                                         | vlSelf->ysyx_25050147_top__DOT__src2)
                                      : ((0xfU == (IData)(vlSelf->ysyx_25050147_top__DOT__alu_op))
                                          ? (vlSelf->ysyx_25050147_top__DOT__src1 
                                             & vlSelf->ysyx_25050147_top__DOT__src2)
                                          : ((8U == (IData)(vlSelf->ysyx_25050147_top__DOT__alu_op))
                                              ? vlSelf->ysyx_25050147_top__DOT__exu__DOT__myalu__DOT__Result
                                              : ((0xdU 
                                                  == (IData)(vlSelf->ysyx_25050147_top__DOT__alu_op))
                                                  ? 
                                                 ((0x1fU 
                                                   >= 
                                                   (0x3fU 
                                                    & vlSelf->ysyx_25050147_top__DOT__src2))
                                                   ? 
                                                  VL_SHIFTRS_III(32,32,6, vlSelf->ysyx_25050147_top__DOT__src1, 
                                                                 (0x3fU 
                                                                  & vlSelf->ysyx_25050147_top__DOT__src2))
                                                   : 
                                                  (- 
                                                   (vlSelf->ysyx_25050147_top__DOT__src1 
                                                    >> 0x1fU)))
                                                  : 0U))))))));
    vlSelf->__Vtableidx1 = ((0x40U & ((~ (IData)(vlSelf->ysyx_25050147_top__DOT__exu__DOT__myalu__DOT__Carry)) 
                                      << 6U)) | (((IData)(vlSelf->ysyx_25050147_top__DOT__exu__DOT__myalu__DOT____VdfgExtracted_hf56215be__0) 
                                                  << 5U) 
                                                 | ((0x10U 
                                                     & ((~ (IData)(
                                                                   (0U 
                                                                    != vlSelf->ysyx_25050147_top__DOT__exu__DOT__myalu__DOT__Result))) 
                                                        << 4U)) 
                                                    | (IData)(vlSelf->ysyx_25050147_top__DOT__alu_op))));
    if (Vysyx_25050147_top__ConstPool__TABLE_h2c44e8aa_0
        [vlSelf->__Vtableidx1]) {
        vlSelf->ysyx_25050147_top__DOT__exu__DOT__myalu__DOT__is_branch 
            = Vysyx_25050147_top__ConstPool__TABLE_h674ad7e6_0
            [vlSelf->__Vtableidx1];
    }
    vlSelf->ysyx_25050147_top__DOT__waddr_mem = ((0x10U 
                                                  & (IData)(vlSelf->ysyx_25050147_top__DOT__op_type))
                                                  ? 
                                                 (1U 
                                                  & ((IData)(vlSelf->ysyx_25050147_top__DOT__exu__DOT__myalu__DOT__is_branch) 
                                                     ^ (IData)(vlSelf->ysyx_25050147_top__DOT__alu_op)))
                                                  : vlSelf->ysyx_25050147_top__DOT__exu__DOT__myalu__DOT__result);
    vlSelf->ysyx_25050147_top__DOT__dnpc = ((1U == (IData)(vlSelf->ysyx_25050147_top__DOT__op_type))
                                             ? vlSelf->ysyx_25050147_top__DOT__waddr_mem
                                             : ((IData)(
                                                        (((IData)(vlSelf->ysyx_25050147_top__DOT__op_type) 
                                                          >> 4U) 
                                                         & vlSelf->ysyx_25050147_top__DOT__waddr_mem))
                                                 ? 
                                                ((((- (IData)(
                                                              (vlSelf->ysyx_25050147_top__DOT__inst 
                                                               >> 0x1fU))) 
                                                   << 0xcU) 
                                                  | ((0x800U 
                                                      & (vlSelf->ysyx_25050147_top__DOT__inst 
                                                         << 4U)) 
                                                     | ((0x7e0U 
                                                         & (vlSelf->ysyx_25050147_top__DOT__inst 
                                                            >> 0x14U)) 
                                                        | (0x1eU 
                                                           & (vlSelf->ysyx_25050147_top__DOT__inst 
                                                              >> 7U))))) 
                                                 + vlSelf->pc)
                                                 : 
                                                ((IData)(4U) 
                                                 + vlSelf->pc)));
    Vysyx_25050147_top___024unit____Vdpiimwrap_pmem_read_TOP____024unit(vlSelf->ysyx_25050147_top__DOT__waddr_mem, vlSelf->__Vfunc_pmem_read__3__Vfuncout);
    vlSelf->ysyx_25050147_top__DOT__mem = vlSelf->__Vfunc_pmem_read__3__Vfuncout;
    if ((4U & (IData)(vlSelf->ysyx_25050147_top__DOT__op_type))) {
        Vysyx_25050147_top___024unit____Vdpiimwrap_pmem_write_TOP____024unit(vlSelf->ysyx_25050147_top__DOT__waddr_mem, 
                                                                             ((2U 
                                                                               & vlSelf->ysyx_25050147_top__DOT__waddr_mem)
                                                                               ? 
                                                                              ((1U 
                                                                                & vlSelf->ysyx_25050147_top__DOT__waddr_mem)
                                                                                ? 
                                                                               (vlSelf->ysyx_25050147_top__DOT__memstore_change__DOT__result 
                                                                                << 0x18U)
                                                                                : 
                                                                               (vlSelf->ysyx_25050147_top__DOT__memstore_change__DOT__result 
                                                                                << 0x10U))
                                                                               : 
                                                                              ((1U 
                                                                                & vlSelf->ysyx_25050147_top__DOT__waddr_mem)
                                                                                ? 
                                                                               (vlSelf->ysyx_25050147_top__DOT__memstore_change__DOT__result 
                                                                                << 8U)
                                                                                : vlSelf->ysyx_25050147_top__DOT__memstore_change__DOT__result)), 
                                                                             ((2U 
                                                                               & vlSelf->ysyx_25050147_top__DOT__waddr_mem)
                                                                               ? 
                                                                              ((1U 
                                                                                & vlSelf->ysyx_25050147_top__DOT__waddr_mem)
                                                                                ? 
                                                                               (0xf8U 
                                                                                & ((IData)(vlSelf->ysyx_25050147_top__DOT__memstore_change__DOT__wmask1) 
                                                                                << 3U))
                                                                                : 
                                                                               (0xfcU 
                                                                                & ((IData)(vlSelf->ysyx_25050147_top__DOT__memstore_change__DOT__wmask1) 
                                                                                << 2U)))
                                                                               : 
                                                                              ((1U 
                                                                                & vlSelf->ysyx_25050147_top__DOT__waddr_mem)
                                                                                ? 
                                                                               (0xfeU 
                                                                                & ((IData)(vlSelf->ysyx_25050147_top__DOT__memstore_change__DOT__wmask1) 
                                                                                << 1U))
                                                                                : (IData)(vlSelf->ysyx_25050147_top__DOT__memstore_change__DOT__wmask1))));
    }
    vlSelf->ysyx_25050147_top__DOT__memload_change__DOT__mem_data 
        = ((2U & vlSelf->ysyx_25050147_top__DOT__waddr_mem)
            ? ((1U & vlSelf->ysyx_25050147_top__DOT__waddr_mem)
                ? (vlSelf->ysyx_25050147_top__DOT__mem 
                   >> 0x18U) : (vlSelf->ysyx_25050147_top__DOT__mem 
                                >> 0x10U)) : ((1U & vlSelf->ysyx_25050147_top__DOT__waddr_mem)
                                               ? (vlSelf->ysyx_25050147_top__DOT__mem 
                                                  >> 8U)
                                               : vlSelf->ysyx_25050147_top__DOT__mem));
}
