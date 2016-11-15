// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtop.h for the primary calling header

#include "Vtop.h"              // For This
#include "Vtop__Syms.h"

//--------------------
// STATIC VARIABLES


//--------------------

VL_CTOR_IMP(Vtop) {
    Vtop__Syms* __restrict vlSymsp = __VlSymsp = new Vtop__Syms(this, name());
    Vtop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Reset internal values
    
    // Reset structure values
    _ctor_var_reset();
}

void Vtop::__Vconfigure(Vtop__Syms* vlSymsp, bool first) {
    if (0 && first) {}  // Prevent unused
    this->__VlSymsp = vlSymsp;
    // Coverage Declarations
    __vlCoverInsert(&(vlSymsp->__Vcoverage[0]), first, "ex1.v", 31, 0, ".ex1", "v_line/ex1", "if");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[1]), first, "ex1.v", 33, 0, ".ex1", "v_line/ex1", "elsif");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[2]), first, "ex1.v", 35, 0, ".ex1", "v_line/ex1", "else");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[3]), first, "ex1.v", 31, 0, ".ex1", "v_line/ex1", "case");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4]), first, "ex1.v", 38, 0, ".ex1", "v_line/ex1", "if");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[5]), first, "ex1.v", 40, 0, ".ex1", "v_line/ex1", "else");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[6]), first, "ex1.v", 38, 0, ".ex1", "v_line/ex1", "case");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[7]), first, "ex1.v", 43, 0, ".ex1", "v_line/ex1", "if");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[8]), first, "ex1.v", 45, 0, ".ex1", "v_line/ex1", "else");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[9]), first, "ex1.v", 43, 0, ".ex1", "v_line/ex1", "case");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[10]), first, "ex1.v", 48, 0, ".ex1", "v_line/ex1", "case");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[11]), first, "ex1.v", 54, 0, ".ex1", "v_line/ex1", "if");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[12]), first, "ex1.v", 56, 0, ".ex1", "v_line/ex1", "else");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[13]), first, "ex1.v", 63, 0, ".ex1", "v_line/ex1", "if");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[14]), first, "ex1.v", 69, 0, ".ex1", "v_line/ex1", "case");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[15]), first, "ex1.v", 73, 0, ".ex1", "v_line/ex1", "case");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[16]), first, "ex1.v", 77, 0, ".ex1", "v_line/ex1", "case");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[17]), first, "ex1.v", 81, 0, ".ex1", "v_line/ex1", "case");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[18]), first, "ex1.v", 67, 0, ".ex1", "v_line/ex1", "else");
}

Vtop::~Vtop() {
    delete __VlSymsp; __VlSymsp=NULL;
}

// Coverage
void Vtop::__vlCoverInsert(uint32_t* countp, bool enable, const char* filenamep, int lineno, int column,
    const char* hierp, const char* pagep, const char* commentp) {
    static uint32_t fake_zero_count = 0;
    if (!enable) countp = &fake_zero_count;
    *countp = 0;
    VL_COVER_INSERT(countp,  "filename",filenamep,  "lineno",lineno,  "column",column,
	"hier",string(name())+hierp,  "page",pagep,  "comment",commentp);
}

//--------------------


void Vtop::eval() {
    Vtop__Syms* __restrict vlSymsp = this->__VlSymsp; // Setup global symbol table
    Vtop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Initialize
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) _eval_initial_loop(vlSymsp);
    // Evaluate till stable
    VL_DEBUG_IF(VL_PRINTF("\n----TOP Evaluate Vtop::eval\n"); );
    int __VclockLoop = 0;
    QData __Vchange=1;
    while (VL_LIKELY(__Vchange)) {
	VL_DEBUG_IF(VL_PRINTF(" Clock loop\n"););
	vlSymsp->__Vm_activity = true;
	_eval(vlSymsp);
	__Vchange = _change_request(vlSymsp);
	if (++__VclockLoop > 100) vl_fatal(__FILE__,__LINE__,__FILE__,"Verilated model didn't converge");
    }
}

void Vtop::_eval_initial_loop(Vtop__Syms* __restrict vlSymsp) {
    vlSymsp->__Vm_didInit = true;
    _eval_initial(vlSymsp);
    vlSymsp->__Vm_activity = true;
    int __VclockLoop = 0;
    QData __Vchange=1;
    while (VL_LIKELY(__Vchange)) {
	_eval_settle(vlSymsp);
	_eval(vlSymsp);
	__Vchange = _change_request(vlSymsp);
	if (++__VclockLoop > 100) vl_fatal(__FILE__,__LINE__,__FILE__,"Verilated model didn't DC converge");
    }
}

//--------------------
// Internal Methods

VL_INLINE_OPT void Vtop::_sequent__TOP__1(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_PRINTF("    Vtop::_sequent__TOP__1\n"); );
    Vtop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    // ALWAYS at ex1.v:61
    if (vlTOPp->reset) {
	++(vlSymsp->__Vcoverage[13]);
	vlTOPp->gnt_0 = 0U;
	vlTOPp->gnt_1 = 0U;
    } else {
	++(vlSymsp->__Vcoverage[18]);
	if ((1U == (IData)(vlTOPp->ex1__DOT__state))) {
	    ++(vlSymsp->__Vcoverage[14]);
	    vlTOPp->gnt_0 = 0U;
	    vlTOPp->gnt_1 = 0U;
	} else {
	    if ((2U == (IData)(vlTOPp->ex1__DOT__state))) {
		++(vlSymsp->__Vcoverage[15]);
		vlTOPp->gnt_0 = 1U;
		vlTOPp->gnt_1 = 0U;
	    } else {
		if ((4U == (IData)(vlTOPp->ex1__DOT__state))) {
		    ++(vlSymsp->__Vcoverage[16]);
		    vlTOPp->gnt_0 = 0U;
		    vlTOPp->gnt_1 = 1U;
		} else {
		    ++(vlSymsp->__Vcoverage[17]);
		    vlTOPp->gnt_0 = 0U;
		    vlTOPp->gnt_1 = 0U;
		}
	    }
	}
    }
    // ALWAYS at ex1.v:52
    if (vlTOPp->reset) {
	++(vlSymsp->__Vcoverage[11]);
	vlTOPp->ex1__DOT__state = 1U;
    } else {
	++(vlSymsp->__Vcoverage[12]);
	vlTOPp->ex1__DOT__state = vlTOPp->ex1__DOT__next_state;
    }
}

VL_INLINE_OPT void Vtop::_combo__TOP__2(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_PRINTF("    Vtop::_combo__TOP__2\n"); );
    Vtop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    // ALWAYS at ex1.v:24
    vlTOPp->__Vfunc_ex1__DOT__fsm_function__0__req_1 
	= vlTOPp->req_1;
    vlTOPp->__Vfunc_ex1__DOT__fsm_function__0__req_0 
	= vlTOPp->req_0;
    vlTOPp->__Vfunc_ex1__DOT__fsm_function__0__state 
	= vlTOPp->ex1__DOT__state;
    if ((1U == (IData)(vlTOPp->__Vfunc_ex1__DOT__fsm_function__0__state))) {
	++(vlSymsp->__Vcoverage[3]);
	if (vlTOPp->__Vfunc_ex1__DOT__fsm_function__0__req_0) {
	    ++(vlSymsp->__Vcoverage[0]);
	    vlTOPp->__Vfunc_ex1__DOT__fsm_function__0__Vfuncout = 2U;
	} else {
	    if (vlTOPp->__Vfunc_ex1__DOT__fsm_function__0__req_1) {
		++(vlSymsp->__Vcoverage[1]);
		vlTOPp->__Vfunc_ex1__DOT__fsm_function__0__Vfuncout = 4U;
	    } else {
		++(vlSymsp->__Vcoverage[2]);
		vlTOPp->__Vfunc_ex1__DOT__fsm_function__0__Vfuncout = 1U;
	    }
	}
    } else {
	if ((2U == (IData)(vlTOPp->__Vfunc_ex1__DOT__fsm_function__0__state))) {
	    ++(vlSymsp->__Vcoverage[6]);
	    if (vlTOPp->__Vfunc_ex1__DOT__fsm_function__0__req_0) {
		++(vlSymsp->__Vcoverage[4]);
		vlTOPp->__Vfunc_ex1__DOT__fsm_function__0__Vfuncout = 2U;
	    } else {
		++(vlSymsp->__Vcoverage[5]);
		vlTOPp->__Vfunc_ex1__DOT__fsm_function__0__Vfuncout = 1U;
	    }
	} else {
	    if ((4U == (IData)(vlTOPp->__Vfunc_ex1__DOT__fsm_function__0__state))) {
		++(vlSymsp->__Vcoverage[9]);
		if (vlTOPp->__Vfunc_ex1__DOT__fsm_function__0__req_1) {
		    ++(vlSymsp->__Vcoverage[7]);
		    vlTOPp->__Vfunc_ex1__DOT__fsm_function__0__Vfuncout = 4U;
		} else {
		    ++(vlSymsp->__Vcoverage[8]);
		    vlTOPp->__Vfunc_ex1__DOT__fsm_function__0__Vfuncout = 1U;
		}
	    } else {
		++(vlSymsp->__Vcoverage[10]);
		vlTOPp->__Vfunc_ex1__DOT__fsm_function__0__Vfuncout = 1U;
	    }
	}
    }
    vlTOPp->ex1__DOT__next_state = vlTOPp->__Vfunc_ex1__DOT__fsm_function__0__Vfuncout;
}

void Vtop::_eval(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_PRINTF("    Vtop::_eval\n"); );
    Vtop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    if (((IData)(vlTOPp->clock) & (~ (IData)(vlTOPp->__Vclklast__TOP__clock)))) {
	vlTOPp->_sequent__TOP__1(vlSymsp);
    }
    vlTOPp->_combo__TOP__2(vlSymsp);
    // Final
    vlTOPp->__Vclklast__TOP__clock = vlTOPp->clock;
}

void Vtop::_eval_initial(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_PRINTF("    Vtop::_eval_initial\n"); );
    Vtop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
}

void Vtop::final() {
    VL_DEBUG_IF(VL_PRINTF("    Vtop::final\n"); );
    // Variables
    Vtop__Syms* __restrict vlSymsp = this->__VlSymsp;
    Vtop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
}

void Vtop::_eval_settle(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_PRINTF("    Vtop::_eval_settle\n"); );
    Vtop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->_combo__TOP__2(vlSymsp);
}

VL_INLINE_OPT QData Vtop::_change_request(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_PRINTF("    Vtop::_change_request\n"); );
    Vtop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    // Change detection
    QData __req = false;  // Logically a bool
    return __req;
}

void Vtop::_ctor_var_reset() {
    VL_DEBUG_IF(VL_PRINTF("    Vtop::_ctor_var_reset\n"); );
    // Body
    clock = VL_RAND_RESET_I(1);
    reset = VL_RAND_RESET_I(1);
    req_0 = VL_RAND_RESET_I(1);
    req_1 = VL_RAND_RESET_I(1);
    gnt_0 = VL_RAND_RESET_I(1);
    gnt_1 = VL_RAND_RESET_I(1);
    ex1__DOT__state = VL_RAND_RESET_I(3);
    ex1__DOT__next_state = VL_RAND_RESET_I(3);
    __Vfunc_ex1__DOT__fsm_function__0__Vfuncout = VL_RAND_RESET_I(3);
    __Vfunc_ex1__DOT__fsm_function__0__state = VL_RAND_RESET_I(3);
    __Vfunc_ex1__DOT__fsm_function__0__req_0 = VL_RAND_RESET_I(1);
    __Vfunc_ex1__DOT__fsm_function__0__req_1 = VL_RAND_RESET_I(1);
    __Vclklast__TOP__clock = VL_RAND_RESET_I(1);
}

void Vtop::sim_init() {
    clock = 0;
    reset = 0;
}

void Vtop::toggle_clock() {
    clock = !clock;
}

void Vtop::set_input_with_reset (vector<bool> vecIn) {
    req_0 = vecIn[0];
    req_1 = vecIn[1];
    reset = vecIn[2];
}

uint32_t Vtop::get_cov_pt_value(uint32_t id) {
    return __VlSymsp->__Vcoverage[id];
}

uint32_t Vtop::num_branch_cov_pts() {
    return 19;
}
