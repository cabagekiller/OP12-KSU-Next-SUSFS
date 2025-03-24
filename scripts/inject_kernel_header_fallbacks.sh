#!/usr/bin/env bash
set -euxo pipefail

HEADER="common/arch/arm64/include/asm/atomic_ll_sc.h"
COMPILER_TYPES="common/include/linux/compiler_types.h"

echo "📦 Checking if raw_atomic64 fallback macros are already injected..."
if grep -q "BBRv3 compatibility fallback macros" "$HEADER"; then
  echo "✅ raw_atomic64 fallback macros already injected. Skipping."
else
  echo "📦 Injecting missing raw_atomic64 and atomic_long macros into $HEADER"
  cat << 'EOF' >> "$HEADER"

/* BEGIN: BBRv3 compatibility fallback macros */
#include <linux/atomic/atomic-long.h>

#ifndef raw_atomic64_read
#define raw_atomic64_read(v) atomic64_read(v)
#endif

#ifndef raw_atomic64_read_acquire
#define raw_atomic64_read_acquire(v) atomic64_read_acquire(v)
#endif

#ifndef raw_atomic64_set
#define raw_atomic64_set(v, i) atomic64_set(v, i)
#endif

#ifndef raw_atomic64_set_release
#define raw_atomic64_set_release(v, i) atomic64_set_release(v, i)
#endif

#ifndef raw_atomic64_add_return_acquire
#define raw_atomic64_add_return_acquire(i, v) atomic64_add_return_acquire(i, v)
#endif

#ifndef raw_atomic64_add_return_release
#define raw_atomic64_add_return_release(i, v) atomic64_add_return_release(i, v)
#endif

#ifndef raw_atomic64_add_return_relaxed
#define raw_atomic64_add_return_relaxed(i, v) atomic64_add_return_relaxed(i, v)
#endif

#ifndef raw_atomic64_sub
#define raw_atomic64_sub(i, v) atomic64_sub(i, v)
#endif

#ifndef raw_atomic64_sub_return
#define raw_atomic64_sub_return(i, v) atomic64_sub_return(i, v)
#endif

#ifndef raw_atomic64_sub_return_acquire
#define raw_atomic64_sub_return_acquire(i, v) atomic64_sub_return_acquire(i, v)
#endif

#ifndef raw_atomic64_sub_return_release
#define raw_atomic64_sub_return_release(i, v) atomic64_sub_return_release(i, v)
#endif

#ifndef raw_atomic64_sub_return_relaxed
#define raw_atomic64_sub_return_relaxed(i, v) atomic64_sub_return_relaxed(i, v)
#endif

#ifndef raw_atomic64_fetch_add
#define raw_atomic64_fetch_add(i, v) atomic64_fetch_add(i, v)
#endif

#ifndef raw_atomic64_fetch_add_acquire
#define raw_atomic64_fetch_add_acquire(i, v) atomic64_fetch_add_acquire(i, v)
#endif

#ifndef raw_atomic64_fetch_add_release
#define raw_atomic64_fetch_add_release(i, v) atomic64_fetch_add_release(i, v)
#endif

#ifndef raw_atomic64_fetch_add_relaxed
#define raw_atomic64_fetch_add_relaxed(i, v) atomic64_fetch_add_relaxed(i, v)
#endif

#ifndef raw_atomic64_fetch_sub
#define raw_atomic64_fetch_sub(i, v) atomic64_fetch_sub(i, v)
#endif

#ifndef raw_atomic64_fetch_sub_acquire
#define raw_atomic64_fetch_sub_acquire(i, v) atomic64_fetch_sub_acquire(i, v)
#endif

#ifndef raw_atomic64_fetch_sub_release
#define raw_atomic64_fetch_sub_release(i, v) atomic64_fetch_sub_release(i, v)
#endif

#ifndef raw_atomic64_fetch_sub_relaxed
#define raw_atomic64_fetch_sub_relaxed(i, v) atomic64_fetch_sub_relaxed(i, v)
#endif

#ifndef arch_atomic_long_fetch_andnot_release
static inline long arch_atomic_long_fetch_andnot_release(long i, atomic_long_t *v) {
    long old, new;
    do {
        old = atomic_long_read(v);
        new = old & ~i;
    } while (atomic_long_cmpxchg_release(v, old, new) != old);
    return old;
}
#endif

#ifndef arch_atomic_long_fetch_xor
static inline long arch_atomic_long_fetch_xor(long i, atomic_long_t *v) {
    long old, new;
    do {
        old = atomic_long_read(v);
        new = old ^ i;
    } while (atomic_long_cmpxchg(v, old, new) != old);
    return old;
}
#endif

#ifndef arch_atomic_long_fetch_or
static inline long arch_atomic_long_fetch_or(long i, atomic_long_t *v) {
    long old, new;
    do {
        old = atomic_long_read(v);
        new = old | i;
    } while (atomic_long_cmpxchg(v, old, new) != old);
    return old;
}
#endif

#ifndef arch_atomic_long_fetch_and
static inline long arch_atomic_long_fetch_and(long i, atomic_long_t *v) {
    long old, new;
    do {
        old = atomic_long_read(v);
        new = old & i;
    } while (atomic_long_cmpxchg(v, old, new) != old);
    return old;
}
#endif
/* END: BBRv3 compatibility fallback macros */
EOF
fi

echo "📦 Checking if asm_volatile_goto fallback is already present..."
if grep -q "asm_volatile_goto" "$COMPILER_TYPES"; then
  echo "✅ asm_volatile_goto fallback already present. Skipping."
else
  cat << 'EOF' >> "$COMPILER_TYPES"

/* BEGIN: asm_volatile_goto fallback */
#ifndef asm_volatile_goto
#define asm_volatile_goto(...) asm volatile(__VA_ARGS__)
#endif
/* END: asm_volatile_goto fallback */
EOF
fi
