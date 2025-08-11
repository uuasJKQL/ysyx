// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vysyx_25050147_top.h for the primary calling header

#ifndef VERILATED_VYSYX_25050147_TOP___024ROOT_H_
#define VERILATED_VYSYX_25050147_TOP___024ROOT_H_  // guard

#include "verilated.h"

class Vysyx_25050147_top__Syms;

class Vysyx_25050147_top___024root final : public VerilatedModule {
  public:

    // DESIGN SPECIFIC STATE
    VL_IN8(clk,0,0);
    VL_IN8(rst,0,0);
    CData/*0:0*/ __Vtrigrprev__TOP__clk;
    CData/*0:0*/ __VactContinue;
    VL_IN(mem,31,0);
    VL_OUT(pc,31,0);
    IData/*31:0*/ ysyx_25050147_top__DOT__snpc;
    IData/*31:0*/ ysyx_25050147_top__DOT__result;
    IData/*31:0*/ __VstlIterCount;
    IData/*31:0*/ __VicoIterCount;
    IData/*31:0*/ __VactIterCount;
    VlUnpacked<IData/*31:0*/, 32> ysyx_25050147_top__DOT__rfile__DOT__rf;
    VlUnpacked<CData/*0:0*/, 2> __Vm_traceActivity;
    VlTriggerVec<1> __VstlTriggered;
    VlTriggerVec<1> __VicoTriggered;
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
