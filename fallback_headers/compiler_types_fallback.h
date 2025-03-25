/* BEGIN: asm_volatile_goto fallback */
#ifndef asm_volatile_goto
#define asm_volatile_goto(...) asm volatile(__VA_ARGS__)
#endif
/* END: asm_volatile_goto fallback */
