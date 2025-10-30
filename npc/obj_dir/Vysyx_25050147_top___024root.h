// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vysyx_25050147_top.h for the primary calling header

#ifndef VERILATED_VYSYX_25050147_TOP___024ROOT_H_
#define VERILATED_VYSYX_25050147_TOP___024ROOT_H_  // guard

#include "verilated.h"

class Vysyx_25050147_top__Syms;
class Vysyx_25050147_top___024unit;


class Vysyx_25050147_top___024root final : public VerilatedModule {
  public:
    // CELLS
    Vysyx_25050147_top___024unit* __PVT____024unit;

    // DESIGN SPECIFIC STATE
    VL_IN8(clk,0,0);
    VL_IN8(rst,0,0);
    CData/*4:0*/ ysyx_25050147_top__DOT__op_type;
    CData/*3:0*/ ysyx_25050147_top__DOT__alu_op;
    CData/*0:0*/ ysyx_25050147_top__DOT__exu__DOT__myalu__DOT__Carry;
    CData/*0:0*/ ysyx_25050147_top__DOT__exu__DOT__myalu__DOT__Cin;
    CData/*0:0*/ ysyx_25050147_top__DOT__exu__DOT__myalu__DOT__is_branch;
    CData/*0:0*/ ysyx_25050147_top__DOT__exu__DOT__myalu__DOT____VdfgExtracted_hf56215be__0;
    CData/*7:0*/ ysyx_25050147_top__DOT__memstore_change__DOT__wmask1;
    CData/*6:0*/ __Vtableidx1;
    CData/*0:0*/ __Vtrigrprev__TOP__clk;
    CData/*0:0*/ __VactContinue;
    VL_OUT(pc,31,0);
    IData/*31:0*/ ysyx_25050147_top__DOT__mem;
    IData/*31:0*/ ysyx_25050147_top__DOT__waddr_mem;
    IData/*31:0*/ ysyx_25050147_top__DOT__rdata1;
    IData/*31:0*/ ysyx_25050147_top__DOT__rdata2;
    IData/*31:0*/ ysyx_25050147_top__DOT__dnpc;
    IData/*31:0*/ ysyx_25050147_top__DOT__src1;
    IData/*31:0*/ ysyx_25050147_top__DOT__src2;
    IData/*31:0*/ ysyx_25050147_top__DOT__inst;
    IData/*31:0*/ ysyx_25050147_top__DOT__exu__DOT__myalu__DOT__result;
    IData/*31:0*/ ysyx_25050147_top__DOT__exu__DOT__myalu__DOT__Result;
    IData/*31:0*/ ysyx_25050147_top__DOT__exu__DOT__myalu__DOT__t_no_Cin;
    IData/*31:0*/ ysyx_25050147_top__DOT__idu__DOT__op_src2_I;
    IData/*31:0*/ ysyx_25050147_top__DOT__memload_change__DOT__mem_data;
    IData/*31:0*/ ysyx_25050147_top__DOT__memstore_change__DOT__result;
    IData/*31:0*/ __Vfunc_pmem_read__0__Vfuncout;
    IData/*31:0*/ __Vfunc_pmem_read__3__Vfuncout;
    IData/*31:0*/ __VstlIterCount;
    IData/*31:0*/ __VactIterCount;
    VlUnpacked<IData/*31:0*/, 32> ysyx_25050147_top__DOT__rfile__DOT__rf;
    VlUnpacked<CData/*0:0*/, 2> __Vm_traceActivity;
    VlTriggerVec<1> __VstlTriggered;
    VlTriggerVec<1> __VactTriggered;
    VlTriggerVec<1> __VnbaTriggered;

    // INTERNAL VARIABLES
    Vysyx_25050147_top__Syms* const vlSymsp;

    // CONSTRUCTORS
    Vysyx_25050147_top___024root(Vysyx_25050147_top__Syms* symsp, const char* v__name);
    ~Vysyx_25050147_top___024root();
    VL_UNCOPYABLE(Vysyx_25050147_top___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);


#endif  // guard
