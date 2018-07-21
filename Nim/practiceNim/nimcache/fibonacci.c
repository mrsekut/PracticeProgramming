/* Generated by Nim Compiler v0.17.2 */
/*   (c) 2017 Andreas Rumpf */
/* The generated code is subject to the original license. */
/* Compiled for: MacOSX, amd64, clang */
/* Command for C compiler:
   clang -c  -w  -I/usr/local/Cellar/nim/0.17.2/nim/lib -o /Users/cloudspider/Desktop/pracNim/nimcache/fibonacci.o /Users/cloudspider/Desktop/pracNim/nimcache/fibonacci.c */
#define NIM_NEW_MANGLING_RULES
#define NIM_INTBITS 64

#include "nimbase.h"
#include <stdio.h>
#undef LANGUAGE_C
#undef MIPSEB
#undef MIPSEL
#undef PPC
#undef R3000
#undef R4000
#undef i386
#undef linux
#undef mips
#undef near
#undef powerpc
#undef unix
typedef struct NimStringDesc NimStringDesc;
typedef struct TGenericSeq TGenericSeq;
struct TGenericSeq {
NI len;
NI reserved;
};
struct NimStringDesc {
  TGenericSeq Sup;
NIM_CHAR data[SEQ_DECL_SIZE];
};
N_NIMCALL(NI, fib_71kem2ORS7ThfPDwhSrQqQ)(NI num);
static N_INLINE(NI, subInt)(NI a, NI b);
N_NOINLINE(void, raiseOverflow)(void);
static N_INLINE(NI, addInt)(NI a, NI b);
static N_INLINE(void, nimFrame)(TFrame* s);
N_NOINLINE(void, stackOverflow_II46IjNZztN9bmbxUD8dt8g)(void);
static N_INLINE(void, popFrame)(void);
N_NIMCALL(NimStringDesc*, nimIntToStr)(NI x);
static N_INLINE(void, initStackBottomWith)(void* locals);
N_NOINLINE(void, setStackBottom)(void* theStackBottom);
NIM_EXTERNC N_NOINLINE(void, systemInit000)(void);
NIM_EXTERNC N_NOINLINE(void, systemDatInit000)(void);
NIM_EXTERNC N_NOINLINE(void, NimMainModule)(void);
NIM_EXTERNC N_NOINLINE(void, fibonacciDatInit000)(void);
extern TFrame* framePtr_HRfVMH3jYeBJz6Q6X9b6Ptw;

static N_INLINE(NI, subInt)(NI a, NI b) {
	NI result;
{	result = (NI)0;
	result = (NI)((NU64)(a) - (NU64)(b));
	{
		NIM_BOOL T3_;
		T3_ = (NIM_BOOL)0;
		T3_ = (((NI) 0) <= (NI)(result ^ a));
		if (T3_) goto LA4_;
		T3_ = (((NI) 0) <= (NI)(result ^ (NI)((NU64) ~(b))));
		LA4_: ;
		if (!T3_) goto LA5_;
		goto BeforeRet_;
	}
	LA5_: ;
	raiseOverflow();
	}BeforeRet_: ;
	return result;
}

static N_INLINE(NI, addInt)(NI a, NI b) {
	NI result;
{	result = (NI)0;
	result = (NI)((NU64)(a) + (NU64)(b));
	{
		NIM_BOOL T3_;
		T3_ = (NIM_BOOL)0;
		T3_ = (((NI) 0) <= (NI)(result ^ a));
		if (T3_) goto LA4_;
		T3_ = (((NI) 0) <= (NI)(result ^ b));
		LA4_: ;
		if (!T3_) goto LA5_;
		goto BeforeRet_;
	}
	LA5_: ;
	raiseOverflow();
	}BeforeRet_: ;
	return result;
}

static N_INLINE(void, nimFrame)(TFrame* s) {
	NI T1_;
	T1_ = (NI)0;
	{
		if (!(framePtr_HRfVMH3jYeBJz6Q6X9b6Ptw == NIM_NIL)) goto LA4_;
		T1_ = ((NI) 0);
	}
	goto LA2_;
	LA4_: ;
	{
		T1_ = ((NI) ((NI16)((*framePtr_HRfVMH3jYeBJz6Q6X9b6Ptw).calldepth + ((NI16) 1))));
	}
	LA2_: ;
	(*s).calldepth = ((NI16) (T1_));
	(*s).prev = framePtr_HRfVMH3jYeBJz6Q6X9b6Ptw;
	framePtr_HRfVMH3jYeBJz6Q6X9b6Ptw = s;
	{
		if (!((*s).calldepth == ((NI16) 2000))) goto LA9_;
		stackOverflow_II46IjNZztN9bmbxUD8dt8g();
	}
	LA9_: ;
}

static N_INLINE(void, popFrame)(void) {
	framePtr_HRfVMH3jYeBJz6Q6X9b6Ptw = (*framePtr_HRfVMH3jYeBJz6Q6X9b6Ptw).prev;
}

N_NIMCALL(NI, fib_71kem2ORS7ThfPDwhSrQqQ)(NI num) {
	NI result;
	nimfr_("fib", "fibonacci.nim");
	result = (NI)0;
	nimln_(2, "fibonacci.nim");
	{
		if (!(num < ((NI) 2))) goto LA3_;
		result = num;
	}
	goto LA1_;
	LA3_: ;
	{
		NI TM_Vgl9cfKragMtnbvBdG1w9aow_2;
		NI T6_;
		NI TM_Vgl9cfKragMtnbvBdG1w9aow_3;
		NI T7_;
		NI TM_Vgl9cfKragMtnbvBdG1w9aow_4;
		TM_Vgl9cfKragMtnbvBdG1w9aow_2 = subInt(num, ((NI) 1));
		T6_ = (NI)0;
		T6_ = fib_71kem2ORS7ThfPDwhSrQqQ((NI)(TM_Vgl9cfKragMtnbvBdG1w9aow_2));
		TM_Vgl9cfKragMtnbvBdG1w9aow_3 = subInt(num, ((NI) 2));
		T7_ = (NI)0;
		T7_ = fib_71kem2ORS7ThfPDwhSrQqQ((NI)(TM_Vgl9cfKragMtnbvBdG1w9aow_3));
		TM_Vgl9cfKragMtnbvBdG1w9aow_4 = addInt(T6_, T7_);
		result = (NI)(TM_Vgl9cfKragMtnbvBdG1w9aow_4);
	}
	LA1_: ;
	popFrame();
	return result;
}

static N_INLINE(void, initStackBottomWith)(void* locals) {
	setStackBottom(locals);
}
void PreMainInner(void) {
	systemInit000();
	fibonacciDatInit000();
}

void PreMain(void) {
	void (*volatile inner)(void);
	systemDatInit000();
	inner = PreMainInner;
	initStackBottomWith((void *)&inner);
	(*inner)();
}

int cmdCount;
char** cmdLine;
char** gEnv;
N_CDECL(void, NimMainInner)(void) {
	NimMainModule();
}

N_CDECL(void, NimMain)(void) {
	void (*volatile inner)(void);
	PreMain();
	inner = NimMainInner;
	initStackBottomWith((void *)&inner);
	(*inner)();
}

int main(int argc, char** args, char** env) {
	cmdLine = args;
	cmdCount = argc;
	gEnv = env;
	NimMain();
	return nim_program_result;
}

NIM_EXTERNC N_NOINLINE(void, NimMainModule)(void) {
	NI T1_;
	NimStringDesc* T2_;
	nimfr_("fibonacci", "fibonacci.nim");
	nimln_(4, "fibonacci.nim");
	T1_ = (NI)0;
	T1_ = fib_71kem2ORS7ThfPDwhSrQqQ(((NI) 40));
	T2_ = (NimStringDesc*)0;
	T2_ = nimIntToStr(T1_);
	printf("%s\012", T2_? (T2_)->data:"nil");
	fflush(stdout);
	popFrame();
}

NIM_EXTERNC N_NOINLINE(void, fibonacciDatInit000)(void) {
}

