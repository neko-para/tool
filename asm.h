#ifndef _ASM_H_
#define _ASM_H_

#if defined(_ASM_USE_GAS_)

#if defined(_ASM_USE_X86_)

#define _ASM_REG_(reg) "e"#reg
#define _ASM_CMD_(cmd) #cmd"l"

#elif defined(_ASM_USE_X64_)

#define _ASM_REG_(reg) "r"#reg
#define _ASM_CMD_(cmd) #cmd"q"

#endif

#define _ASM_ asm volatile
#define _ASM_DIRECT_VAL_(val) "$"#val

#define _ASM_CMD_ONE_(cmd, a) _ASM_CMD_(cmd)" "a";"
#define _ASM_CMD_TWO_(cmd, a, b) _ASM_CMD_(cmd)" "a", "b";"

#define _ASM_CMD_PUSH_(a) _ASM_CMD_ONE_(push, a)
#define _ASM_CMD_CALL_(a) _ASM_CMD_ONE_(call, a)
#define _ASM_CMD_MOV_(a, b) _ASM_CMD_TWO_(mov, a, b)
#define _ASM_CMD_ADD_(a, b) _ASM_CMD_TWO_(add, a, b)
#define _ASM_CMD_SUB_(a, b) _ASM_CMD_TWO_(sub, a, b)

#define PushDirectToReg(val, reg) \
	_ASM_ ( \
		_ASM_CMD_MOV_(_ASM_DIRECT_VAL_(val), "%"_ASM_REG_(reg)) \
	)

#define PushVaribleToReg(val, reg) \
	_ASM_ ( \
		_ASM_CMD_MOV_("%0", "%%"_ASM_REG_(reg)) \
		:: "m" (val) \
	)

#define PushDirect(val) \
	_ASM_ ( \
		_ASM_CMD_PUSH_(_ASM_DIRECT_VAL_(val)) \
	)

#define PushVarible(val) \
	_ASM_ ( \
		_ASM_CMD_PUSH_("%0") \
		:: "m" (val) \
	)

#define CallDirect(proc) \
	_ASM_ ( \
		_ASM_CMD_CALL_(#proc) \
	)

#define CallVarible(proc) \
	_ASM_ ( \
		_ASM_CMD_MOV_("%0", "%%"_ASM_REG_(ax)) \
		_ASM_CMD_CALL_("*%%"_ASM_REG_(ax)) \
		:: "m" (proc) \
	)

#define GetReturn(ret) \
	_ASM_ ( \
		_ASM_CMD_MOV_("%"_ASM_REG_(ax), "%0") \
		: "=m" (ret) \
	)

#define EraseStackDirect(val) \
	_ASM_ ( \
		_ASM_CMD_ADD_(_ASM_DIRECT_VAL_(val), "%"_ASM_REG_(sp)) \
	)

#define EraseStackVarible(val) \
	_ASM_ ( \
		_ASM_CMD_ADD_("%0", "%%"_ASM_REG_(sp)) \
		:: "m" (val) \
	)

#elif defined(_ASM_USE_INTEL_)

#error Intel type assembly not support yet.

#if defined(_ASM_USE_X86_)

#elif defined(_ASM_USE_X64_)

#endif

#endif

#if defined(_ASM_USE_X86_)

#define PushDirect1(val) PushDirect(val)
#define PushDirect2(val) PushDirect(val)
#define PushDirect3(val) PushDirect(val)
#define PushDirect4(val) PushDirect(val)
#define PushDirect5(val) PushDirect(val)
#define PushDirect6(val) PushDirect(val)

#define PushVarible1(val) PushVarible(val)
#define PushVarible2(val) PushVarible(val)
#define PushVarible3(val) PushVarible(val)
#define PushVarible4(val) PushVarible(val)
#define PushVarible5(val) PushVarible(val)
#define PushVarible6(val) PushVarible(val)

#define EraseStack1 EraseStackDirect(4)
#define EraseStack2 EraseStackDirect(4)
#define EraseStack3 EraseStackDirect(4)
#define EraseStack4 EraseStackDirect(4)
#define EraseStack5 EraseStackDirect(4)
#define EraseStack6 EraseStackDirect(4)

#elif defined(_ASM_USE_X64_)

#define PushDirect1(val) PushDirectToReg(val, di)
#define PushDirect2(val) PushDirectToReg(val, si)
#define PushDirect3(val) PushDirectToReg(val, dx)
#define PushDirect4(val) PushDirectToReg(val, cx)
#define PushDirect5(val) PushDirectToReg(val, 8)
#define PushDirect6(val) PushDirectToReg(val, 9)

#define PushVarible1(val) PushVaribleToReg(val, di)
#define PushVarible2(val) PushVaribleToReg(val, si)
#define PushVarible3(val) PushVaribleToReg(val, dx)
#define PushVarible4(val) PushVaribleToReg(val, cx)
#define PushVarible5(val) PushVaribleToReg(val, 8)
#define PushVarible6(val) PushVaribleToReg(val, 9)

#define EraseStack1
#define EraseStack2
#define EraseStack3
#define EraseStack4
#define EraseStack5
#define EraseStack6

#endif

#ifdef __cplusplus
extern "C" {
#endif

void* callfv(void* proc, unsigned long cnt, void** params);
void* callf(void* proc, unsigned long cnt, ...);

#ifdef __cplusplus
}
#endif

#endif