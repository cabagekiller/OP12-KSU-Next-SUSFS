#ifndef _LINUX_ATOMIC_LONG_H
  #define _LINUX_ATOMIC_LONG_H
  
  #include <linux/compiler.h>
  #include <linux/types.h>
  #include <asm-generic/atomic-long.h>
  #include <linux/atomic/atomic-raw64-compat.h>

#ifndef raw_atomic64_read
        static inline s64 raw_atomic64_read(const atomic64_t *v) { return atomic64_read(v); }
        #endif
        #ifndef raw_atomic64_read_acquire
        static inline s64 raw_atomic64_read_acquire(const atomic64_t *v) { return atomic64_read_acquire(v); }
        #endif
        #ifndef raw_atomic64_set
        static inline void raw_atomic64_set(atomic64_t *v, s64 i) { atomic64_set(v, i); }
        #endif
        #ifndef raw_atomic64_set_release
        static inline void raw_atomic64_set_release(atomic64_t *v, s64 i) { atomic64_set_release(v, i); }
        #endif
        #ifndef raw_atomic64_add
        static inline void raw_atomic64_add(s64 i, atomic64_t *v) { atomic64_add(i, v); }
        #endif
        #ifndef raw_atomic64_add_return
        static inline s64 raw_atomic64_add_return(s64 i, atomic64_t *v) { return atomic64_add_return(i, v); }
        #endif
        #ifndef raw_atomic64_add_return_acquire
        static inline s64 raw_atomic64_add_return_acquire(s64 i, atomic64_t *v) { return atomic64_add_return_acquire(i, v); }
        #endif
        #ifndef raw_atomic64_add_return_release
        static inline s64 raw_atomic64_add_return_release(s64 i, atomic64_t *v) { return atomic64_add_return_release(i, v); }
        #endif
        #ifndef raw_atomic64_add_return_relaxed
        static inline s64 raw_atomic64_add_return_relaxed(s64 i, atomic64_t *v) { return atomic64_add_return_relaxed(i, v); }
        #endif
        #ifndef raw_atomic64_fetch_add
        static inline s64 raw_atomic64_fetch_add(s64 i, atomic64_t *v) { return atomic64_fetch_add(i, v); }
        #endif
        #ifndef raw_atomic64_fetch_add_acquire
        static inline s64 raw_atomic64_fetch_add_acquire(s64 i, atomic64_t *v) { return atomic64_fetch_add_acquire(i, v); }
        #endif
        #ifndef raw_atomic64_fetch_add_release
        static inline s64 raw_atomic64_fetch_add_release(s64 i, atomic64_t *v) { return atomic64_fetch_add_release(i, v); }
        #endif
        #ifndef raw_atomic64_fetch_add_relaxed
        static inline s64 raw_atomic64_fetch_add_relaxed(s64 i, atomic64_t *v) { return atomic64_fetch_add_relaxed(i, v); }
        #endif
        #ifndef raw_atomic64_sub
        static inline void raw_atomic64_sub(s64 i, atomic64_t *v) { atomic64_sub(i, v); }
        #endif
        #ifndef raw_atomic64_sub_return
        static inline s64 raw_atomic64_sub_return(s64 i, atomic64_t *v) { return atomic64_sub_return(i, v); }
        #endif
        #ifndef raw_atomic64_sub_return_acquire
        static inline s64 raw_atomic64_sub_return_acquire(s64 i, atomic64_t *v) { return atomic64_sub_return_acquire(i, v); }
        #endif
        #ifndef raw_atomic64_sub_return_release
        static inline s64 raw_atomic64_sub_return_release(s64 i, atomic64_t *v) { return atomic64_sub_return_release(i, v); }
        #endif
        #ifndef raw_atomic64_sub_return_relaxed
        static inline s64 raw_atomic64_sub_return_relaxed(s64 i, atomic64_t *v) { return atomic64_sub_return_relaxed(i, v); }
        #endif
        #ifndef raw_atomic64_fetch_sub
        static inline s64 raw_atomic64_fetch_sub(s64 i, atomic64_t *v) { return atomic64_fetch_sub(i, v); }
        #endif
        #ifndef raw_atomic64_fetch_sub_acquire
        static inline s64 raw_atomic64_fetch_sub_acquire(s64 i, atomic64_t *v) { return atomic64_fetch_sub_acquire(i, v); }
        #endif
        #ifndef raw_atomic64_fetch_sub_release
        static inline s64 raw_atomic64_fetch_sub_release(s64 i, atomic64_t *v) { return atomic64_fetch_sub_release(i, v); }
        #endif
        #ifndef raw_atomic64_fetch_sub_relaxed
        static inline s64 raw_atomic64_fetch_sub_relaxed(s64 i, atomic64_t *v) { return atomic64_fetch_sub_relaxed(i, v); }
        #endif
        #ifndef raw_atomic64_inc
        static inline void raw_atomic64_inc(atomic64_t *v) { atomic64_inc(v); }
        #endif
        #ifndef raw_atomic64_inc_return
        static inline s64 raw_atomic64_inc_return(atomic64_t *v) { return atomic64_inc_return(v); }
        #endif
        #ifndef raw_atomic64_inc_return_acquire
        static inline s64 raw_atomic64_inc_return_acquire(atomic64_t *v) { return atomic64_inc_return_acquire(v); }
        #endif
        #ifndef raw_atomic64_inc_return_release
        static inline s64 raw_atomic64_inc_return_release(atomic64_t *v) { return atomic64_inc_return_release(v); }
        #endif
        #ifndef raw_atomic64_inc_return_relaxed
        static inline s64 raw_atomic64_inc_return_relaxed(atomic64_t *v) { return atomic64_inc_return_relaxed(v); }
        #endif
        #ifndef raw_atomic64_fetch_inc
        static inline s64 raw_atomic64_fetch_inc(atomic64_t *v) { return atomic64_fetch_inc(v); }
        #endif
        #ifndef raw_atomic64_fetch_inc_acquire
        static inline s64 raw_atomic64_fetch_inc_acquire(atomic64_t *v) { return atomic64_fetch_inc_acquire(v); }
        #endif
        #ifndef raw_atomic64_fetch_inc_release
        static inline s64 raw_atomic64_fetch_inc_release(atomic64_t *v) { return atomic64_fetch_inc_release(v); }
        #endif
        #ifndef raw_atomic64_fetch_inc_relaxed
        static inline s64 raw_atomic64_fetch_inc_relaxed(atomic64_t *v) { return atomic64_fetch_inc_relaxed(v); }
        #endif
        #ifndef raw_atomic64_dec
        static inline void raw_atomic64_dec(atomic64_t *v) { atomic64_dec(v); }
        #endif
        #ifndef raw_atomic64_dec_return
        static inline s64 raw_atomic64_dec_return(atomic64_t *v) { return atomic64_dec_return(v); }
        #endif
        #ifndef raw_atomic64_dec_return_acquire
        static inline s64 raw_atomic64_dec_return_acquire(atomic64_t *v) { return atomic64_dec_return_acquire(v); }
        #endif
        #ifndef raw_atomic64_dec_return_release
        static inline s64 raw_atomic64_dec_return_release(atomic64_t *v) { return atomic64_dec_return_release(v); }
        #endif
        #ifndef raw_atomic64_dec_return_relaxed
        static inline s64 raw_atomic64_dec_return_relaxed(atomic64_t *v) { return atomic64_dec_return_relaxed(v); }
        #endif
        #ifndef raw_atomic64_fetch_dec
        static inline s64 raw_atomic64_fetch_dec(atomic64_t *v) { return atomic64_fetch_dec(v); }
        #endif
        #ifndef raw_atomic64_fetch_dec_acquire
        static inline s64 raw_atomic64_fetch_dec_acquire(atomic64_t *v) { return atomic64_fetch_dec_acquire(v); }
        #endif
        #ifndef raw_atomic64_fetch_dec_release
        static inline s64 raw_atomic64_fetch_dec_release(atomic64_t *v) { return atomic64_fetch_dec_release(v); }
        #endif
        #ifndef raw_atomic64_fetch_dec_relaxed
        static inline s64 raw_atomic64_fetch_dec_relaxed(atomic64_t *v) { return atomic64_fetch_dec_relaxed(v); }
        #endif
        #ifndef raw_atomic64_and
        static inline void raw_atomic64_and(s64 i, atomic64_t *v) { atomic64_and(i, v); }
        #endif
        #ifndef raw_atomic64_fetch_and
        static inline s64 raw_atomic64_fetch_and(s64 i, atomic64_t *v) { return atomic64_fetch_and(i, v); }
        #endif
        #ifndef raw_atomic64_fetch_and_acquire
        static inline s64 raw_atomic64_fetch_and_acquire(s64 i, atomic64_t *v) { return atomic64_fetch_and_acquire(i, v); }
        #endif
        #ifndef raw_atomic64_fetch_and_release
        static inline s64 raw_atomic64_fetch_and_release(s64 i, atomic64_t *v) { return atomic64_fetch_and_release(i, v); }
        #endif
        #ifndef raw_atomic64_fetch_and_relaxed
        static inline s64 raw_atomic64_fetch_and_relaxed(s64 i, atomic64_t *v) { return atomic64_fetch_and_relaxed(i, v); }
        #endif
        #ifndef raw_atomic64_andnot
        static inline void raw_atomic64_andnot(s64 i, atomic64_t *v) { atomic64_andnot(i, v); }
        #endif
        #ifndef raw_atomic64_fetch_andnot
        static inline s64 raw_atomic64_fetch_andnot(s64 i, atomic64_t *v) { return atomic64_fetch_andnot(i, v); }
        #endif
        #ifndef raw_atomic64_fetch_andnot_acquire
        static inline s64 raw_atomic64_fetch_andnot_acquire(s64 i, atomic64_t *v) { return atomic64_fetch_andnot_acquire(i, v); }
        #endif
        #ifndef raw_atomic64_fetch_andnot_release
        static inline s64 raw_atomic64_fetch_andnot_release(s64 i, atomic64_t *v) { return atomic64_fetch_andnot_release(i, v); }
        #endif
        #ifndef raw_atomic64_fetch_andnot_relaxed
        static inline s64 raw_atomic64_fetch_andnot_relaxed(s64 i, atomic64_t *v) { return atomic64_fetch_andnot_relaxed(i, v); }
        #endif
        #ifndef raw_atomic64_or
        static inline void raw_atomic64_or(s64 i, atomic64_t *v) { atomic64_or(i, v); }
        #endif
        #ifndef raw_atomic64_fetch_or
        static inline s64 raw_atomic64_fetch_or(s64 i, atomic64_t *v) { return atomic64_fetch_or(i, v); }
        #endif
        #ifndef raw_atomic64_fetch_or_acquire
        static inline s64 raw_atomic64_fetch_or_acquire(s64 i, atomic64_t *v) { return atomic64_fetch_or_acquire(i, v); }
        #endif
        #ifndef raw_atomic64_fetch_or_release
        static inline s64 raw_atomic64_fetch_or_release(s64 i, atomic64_t *v) { return atomic64_fetch_or_release(i, v); }
        #endif
        #ifndef raw_atomic64_fetch_or_relaxed
        static inline s64 raw_atomic64_fetch_or_relaxed(s64 i, atomic64_t *v) { return atomic64_fetch_or_relaxed(i, v); }
        #endif
        #ifndef raw_atomic64_xor
        static inline void raw_atomic64_xor(s64 i, atomic64_t *v) { atomic64_xor(i, v); }
        #endif
        #ifndef raw_atomic64_fetch_xor
        static inline s64 raw_atomic64_fetch_xor(s64 i, atomic64_t *v) { return atomic64_fetch_xor(i, v); }
        #endif
        #ifndef raw_atomic64_fetch_xor_acquire
        static inline s64 raw_atomic64_fetch_xor_acquire(s64 i, atomic64_t *v) { return atomic64_fetch_xor_acquire(i, v); }
        #endif
        #ifndef raw_atomic64_fetch_xor_release
        static inline s64 raw_atomic64_fetch_xor_release(s64 i, atomic64_t *v) { return atomic64_fetch_xor_release(i, v); }
        #endif
        #ifndef raw_atomic64_fetch_xor_relaxed
        static inline s64 raw_atomic64_fetch_xor_relaxed(s64 i, atomic64_t *v) { return atomic64_fetch_xor_relaxed(i, v); }
        #endif
        #ifndef raw_atomic64_xchg
        static inline s64 raw_atomic64_xchg(atomic64_t *v, s64 new) { return atomic64_xchg(v, new); }
        #endif
        #ifndef raw_atomic64_xchg_acquire
        static inline s64 raw_atomic64_xchg_acquire(atomic64_t *v, s64 new) { return atomic64_xchg_acquire(v, new); }
        #endif
        #ifndef raw_atomic64_xchg_release
        static inline s64 raw_atomic64_xchg_release(atomic64_t *v, s64 new) { return atomic64_xchg_release(v, new); }
        #endif
        #ifndef raw_atomic64_xchg_relaxed
        static inline s64 raw_atomic64_xchg_relaxed(atomic64_t *v, s64 new) { return atomic64_xchg_relaxed(v, new); }
        #endif
        #ifndef raw_atomic64_cmpxchg
        static inline s64 raw_atomic64_cmpxchg(atomic64_t *v, s64 old, s64 new) { return atomic64_cmpxchg(v, old, new); }
        #endif
        #ifndef raw_atomic64_cmpxchg_acquire
        static inline s64 raw_atomic64_cmpxchg_acquire(atomic64_t *v, s64 old, s64 new) { return atomic64_cmpxchg_acquire(v, old, new); }
        #endif
        #ifndef raw_atomic64_cmpxchg_release
        static inline s64 raw_atomic64_cmpxchg_release(atomic64_t *v, s64 old, s64 new) { return atomic64_cmpxchg_release(v, old, new); }
        #endif
        #ifndef raw_atomic64_cmpxchg_relaxed
        static inline s64 raw_atomic64_cmpxchg_relaxed(atomic64_t *v, s64 old, s64 new) { return atomic64_cmpxchg_relaxed(v, old, new); }
        #endif
        #ifndef raw_atomic64_try_cmpxchg
        static inline bool raw_atomic64_try_cmpxchg(atomic64_t *v, s64 *old, s64 new) { return atomic64_try_cmpxchg(v, old, new); }
        #endif
        #ifndef raw_atomic64_try_cmpxchg_acquire
        static inline bool raw_atomic64_try_cmpxchg_acquire(atomic64_t *v, s64 *old, s64 new) { return atomic64_try_cmpxchg_acquire(v, old, new); }
        #endif
        #ifndef raw_atomic64_try_cmpxchg_release
        static inline bool raw_atomic64_try_cmpxchg_release(atomic64_t *v, s64 *old, s64 new) { return atomic64_try_cmpxchg_release(v, old, new); }
        #endif
        #ifndef raw_atomic64_try_cmpxchg_relaxed
        static inline bool raw_atomic64_try_cmpxchg_relaxed(atomic64_t *v, s64 *old, s64 new) { return atomic64_try_cmpxchg_relaxed(v, old, new); }
        #endif
        #ifndef raw_atomic64_sub_and_test
        static inline bool raw_atomic64_sub_and_test(s64 i, atomic64_t *v) { return atomic64_sub_and_test(i, v); }
        #endif
        #ifndef raw_atomic64_dec_and_test
        static inline bool raw_atomic64_dec_and_test(atomic64_t *v) { return atomic64_dec_and_test(v); }
        #endif
        #ifndef raw_atomic64_inc_and_test
        static inline bool raw_atomic64_inc_and_test(atomic64_t *v) { return atomic64_inc_and_test(v); }
        #endif
        #ifndef raw_atomic64_add_negative
        static inline bool raw_atomic64_add_negative(s64 i, atomic64_t *v) { return atomic64_add_negative(i, v); }
        #endif
        #ifndef raw_atomic64_fetch_add_unless
        static inline s64 raw_atomic64_fetch_add_unless(atomic64_t *v, s64 a, s64 u) { return atomic64_fetch_add_unless(v, a, u); }
        #endif
        #ifndef raw_atomic64_add_unless
        static inline bool raw_atomic64_add_unless(atomic64_t *v, s64 a, s64 u) { return atomic64_add_unless(v, a, u); }
        #endif
        #ifndef raw_atomic64_inc_not_zero
        static inline bool raw_atomic64_inc_not_zero(atomic64_t *v) { return atomic64_inc_not_zero(v); }
        #endif
        #ifndef raw_atomic64_inc_unless_negative
        static inline bool raw_atomic64_inc_unless_negative(atomic64_t *v) { return atomic64_inc_unless_negative(v); }
        #endif
        #ifndef raw_atomic64_dec_unless_positive
        static inline bool raw_atomic64_dec_unless_positive(atomic64_t *v) { return atomic64_dec_unless_positive(v); }
        #endif
        #ifndef raw_atomic64_dec_if_positive
        static inline s64 raw_atomic64_dec_if_positive(atomic64_t *v) { return atomic64_dec_if_positive(v); }
        #endif
  
  #ifdef CONFIG_64BIT
  typedef atomic64_t atomic_long_t;
  #define ATOMIC_LONG_INIT(i)       ATOMIC64_INIT(i)
  #define ATOMIC_LONG_PFX(x)        atomic64##x
  
  /* 64-bit atomic_long operations (wrap raw_atomic64_*) */
  static inline long raw_atomic_long_read(const atomic_long_t *v) { return raw_atomic64_read(v); }
  static inline long raw_atomic_long_read_acquire(const atomic_long_t *v) { return raw_atomic64_read_acquire(v); }
  static inline void raw_atomic_long_set(atomic_long_t *v, long i) { raw_atomic64_set(v, i); }
  static inline void raw_atomic_long_set_release(atomic_long_t *v, long i) { raw_atomic64_set_release(v, i); }
  static inline void raw_atomic_long_add(long i, atomic_long_t *v) { raw_atomic64_add(i, v); }
  static inline long raw_atomic_long_add_return(long i, atomic_long_t *v) { return raw_atomic64_add_return(i, v); }
  static inline long raw_atomic_long_add_return_acquire(long i, atomic_long_t *v) { return raw_atomic64_add_return_acquire(i, v); }
  static inline long raw_atomic_long_add_return_release(long i, atomic_long_t *v) { return raw_atomic64_add_return_release(i, v); }
  static inline long raw_atomic_long_add_return_relaxed(long i, atomic_long_t *v) { return raw_atomic64_add_return_relaxed(i, v); }
  static inline long raw_atomic_long_fetch_add(long i, atomic_long_t *v) { return raw_atomic64_fetch_add(i, v); }
  static inline long raw_atomic_long_fetch_add_acquire(long i, atomic_long_t *v) { return raw_atomic64_fetch_add_acquire(i, v); }
  static inline long raw_atomic_long_fetch_add_release(long i, atomic_long_t *v) { return raw_atomic64_fetch_add_release(i, v); }
  static inline long raw_atomic_long_fetch_add_relaxed(long i, atomic_long_t *v) { return raw_atomic64_fetch_add_relaxed(i, v); }
  static inline void raw_atomic_long_sub(long i, atomic_long_t *v) { raw_atomic64_sub(i, v); }
  static inline long raw_atomic_long_sub_return(long i, atomic_long_t *v) { return raw_atomic64_sub_return(i, v); }
  static inline long raw_atomic_long_sub_return_acquire(long i, atomic_long_t *v) { return raw_atomic64_sub_return_acquire(i, v); }
  static inline long raw_atomic_long_sub_return_release(long i, atomic_long_t *v) { return raw_atomic64_sub_return_release(i, v); }
  static inline long raw_atomic_long_sub_return_relaxed(long i, atomic_long_t *v) { return raw_atomic64_sub_return_relaxed(i, v); }
  static inline long raw_atomic_long_fetch_sub(long i, atomic_long_t *v) { return raw_atomic64_fetch_sub(i, v); }
  static inline long raw_atomic_long_fetch_sub_acquire(long i, atomic_long_t *v) { return raw_atomic64_fetch_sub_acquire(i, v); }
  static inline long raw_atomic_long_fetch_sub_release(long i, atomic_long_t *v) { return raw_atomic64_fetch_sub_release(i, v); }
  static inline long raw_atomic_long_fetch_sub_relaxed(long i, atomic_long_t *v) { return raw_atomic64_fetch_sub_relaxed(i, v); }
  static inline void raw_atomic_long_inc(atomic_long_t *v) { raw_atomic64_inc(v); }
  static inline long raw_atomic_long_inc_return(atomic_long_t *v) { return raw_atomic64_inc_return(v); }
  static inline long raw_atomic_long_inc_return_acquire(atomic_long_t *v) { return raw_atomic64_inc_return_acquire(v); }
  static inline long raw_atomic_long_inc_return_release(atomic_long_t *v) { return raw_atomic64_inc_return_release(v); }
  static inline long raw_atomic_long_inc_return_relaxed(atomic_long_t *v) { return raw_atomic64_inc_return_relaxed(v); }
  static inline long raw_atomic_long_fetch_inc(atomic_long_t *v) { return raw_atomic64_fetch_inc(v); }
  static inline long raw_atomic_long_fetch_inc_acquire(atomic_long_t *v) { return raw_atomic64_fetch_inc_acquire(v); }
  static inline long raw_atomic_long_fetch_inc_release(atomic_long_t *v) { return raw_atomic64_fetch_inc_release(v); }
  static inline long raw_atomic_long_fetch_inc_relaxed(atomic_long_t *v) { return raw_atomic64_fetch_inc_relaxed(v); }
  static inline void raw_atomic_long_dec(atomic_long_t *v) { raw_atomic64_dec(v); }
  static inline long raw_atomic_long_dec_return(atomic_long_t *v) { return raw_atomic64_dec_return(v); }
  static inline long raw_atomic_long_dec_return_acquire(atomic_long_t *v) { return raw_atomic64_dec_return_acquire(v); }
  static inline long raw_atomic_long_dec_return_release(atomic_long_t *v) { return raw_atomic64_dec_return_release(v); }
  static inline long raw_atomic_long_dec_return_relaxed(atomic_long_t *v) { return raw_atomic64_dec_return_relaxed(v); }
  static inline long raw_atomic_long_fetch_dec(atomic_long_t *v) { return raw_atomic64_fetch_dec(v); }
  static inline long raw_atomic_long_fetch_dec_acquire(atomic_long_t *v) { return raw_atomic64_fetch_dec_acquire(v); }
  static inline long raw_atomic_long_fetch_dec_release(atomic_long_t *v) { return raw_atomic64_fetch_dec_release(v); }
  static inline long raw_atomic_long_fetch_dec_relaxed(atomic_long_t *v) { return raw_atomic64_fetch_dec_relaxed(v); }
  static inline void raw_atomic_long_and(long i, atomic_long_t *v) { raw_atomic64_and(i, v); }
  static inline long raw_atomic_long_fetch_and(long i, atomic_long_t *v) { return raw_atomic64_fetch_and(i, v); }
  static inline long raw_atomic_long_fetch_and_acquire(long i, atomic_long_t *v) { return raw_atomic64_fetch_and_acquire(i, v); }
  static inline long raw_atomic_long_fetch_and_release(long i, atomic_long_t *v) { return raw_atomic64_fetch_and_release(i, v); }
  static inline long raw_atomic_long_fetch_and_relaxed(long i, atomic_long_t *v) { return raw_atomic64_fetch_and_relaxed(i, v); }
  static inline void raw_atomic_long_andnot(long i, atomic_long_t *v) { raw_atomic64_andnot(i, v); }
  static inline long raw_atomic_long_fetch_andnot(long i, atomic_long_t *v) { return raw_atomic64_fetch_andnot(i, v); }
  static inline long raw_atomic_long_fetch_andnot_acquire(long i, atomic_long_t *v) { return raw_atomic64_fetch_andnot_acquire(i, v); }
  static inline long raw_atomic_long_fetch_andnot_release(long i, atomic_long_t *v) { return raw_atomic64_fetch_andnot_release(i, v); }
  static inline long raw_atomic_long_fetch_andnot_relaxed(long i, atomic_long_t *v) { return raw_atomic64_fetch_andnot_relaxed(i, v); }
  static inline void raw_atomic_long_or(long i, atomic_long_t *v) { raw_atomic64_or(i, v); }
  static inline long raw_atomic_long_fetch_or(long i, atomic_long_t *v) { return raw_atomic64_fetch_or(i, v); }
  static inline long raw_atomic_long_fetch_or_acquire(long i, atomic_long_t *v) { return raw_atomic64_fetch_or_acquire(i, v); }
  static inline long raw_atomic_long_fetch_or_release(long i, atomic_long_t *v) { return raw_atomic64_fetch_or_release(i, v); }
  static inline long raw_atomic_long_fetch_or_relaxed(long i, atomic_long_t *v) { return raw_atomic64_fetch_or_relaxed(i, v); }
  static inline void raw_atomic_long_xor(long i, atomic_long_t *v) { raw_atomic64_xor(i, v); }
  static inline long raw_atomic_long_fetch_xor(long i, atomic_long_t *v) { return raw_atomic64_fetch_xor(i, v); }
  static inline long raw_atomic_long_fetch_xor_acquire(long i, atomic_long_t *v) { return raw_atomic64_fetch_xor_acquire(i, v); }
  static inline long raw_atomic_long_fetch_xor_release(long i, atomic_long_t *v) { return raw_atomic64_fetch_xor_release(i, v); }
  static inline long raw_atomic_long_fetch_xor_relaxed(long i, atomic_long_t *v) { return raw_atomic64_fetch_xor_relaxed(i, v); }
  static inline long raw_atomic_long_xchg(atomic_long_t *v, long new) { return raw_atomic64_xchg(v, new); }
  static inline long raw_atomic_long_xchg_acquire(atomic_long_t *v, long new) { return raw_atomic64_xchg_acquire(v, new); }
  static inline long raw_atomic_long_xchg_release(atomic_long_t *v, long new) { return raw_atomic64_xchg_release(v, new); }
  static inline long raw_atomic_long_xchg_relaxed(atomic_long_t *v, long new) { return raw_atomic64_xchg_relaxed(v, new); }
  static inline long raw_atomic_long_cmpxchg(atomic_long_t *v, long old, long new) { return raw_atomic64_cmpxchg(v, old, new); }
  static inline long raw_atomic_long_cmpxchg_acquire(atomic_long_t *v, long old, long new) { return raw_atomic64_cmpxchg_acquire(v, old, new); }
  static inline long raw_atomic_long_cmpxchg_release(atomic_long_t *v, long old, long new) { return raw_atomic64_cmpxchg_release(v, old, new); }
  static inline long raw_atomic_long_cmpxchg_relaxed(atomic_long_t *v, long old, long new) { return raw_atomic64_cmpxchg_relaxed(v, old, new); }
  static inline bool raw_atomic_long_try_cmpxchg(atomic_long_t *v, long *old, long new) { return raw_atomic64_try_cmpxchg(v, old, new); }
  static inline bool raw_atomic_long_try_cmpxchg_acquire(atomic_long_t *v, long *old, long new) { return raw_atomic64_try_cmpxchg_acquire(v, old, new); }
  static inline bool raw_atomic_long_try_cmpxchg_release(atomic_long_t *v, long *old, long new) { return raw_atomic64_try_cmpxchg_release(v, old, new); }
  static inline bool raw_atomic_long_try_cmpxchg_relaxed(atomic_long_t *v, long *old, long new) { return raw_atomic64_try_cmpxchg_relaxed(v, old, new); }
  static inline bool raw_atomic_long_sub_and_test(long i, atomic_long_t *v) { return raw_atomic64_sub_and_test(i, v); }
  static inline bool raw_atomic_long_dec_and_test(atomic_long_t *v) { return raw_atomic64_dec_and_test(v); }
  static inline bool raw_atomic_long_inc_and_test(atomic_long_t *v) { return raw_atomic64_inc_and_test(v); }
  static inline bool raw_atomic_long_add_negative(long i, atomic_long_t *v) { return raw_atomic64_add_negative(i, v); }
  static inline long raw_atomic_long_fetch_add_unless(atomic_long_t *v, long a, long u) { return raw_atomic64_fetch_add_unless(v, a, u); }
  static inline bool raw_atomic_long_add_unless(atomic_long_t *v, long a, long u) { return raw_atomic64_add_unless(v, a, u); }
  static inline bool raw_atomic_long_inc_not_zero(atomic_long_t *v) { return raw_atomic64_inc_not_zero(v); }
  static inline bool raw_atomic_long_inc_unless_negative(atomic_long_t *v) { return raw_atomic64_inc_unless_negative(v); }
  static inline bool raw_atomic_long_dec_unless_positive(atomic_long_t *v) { return raw_atomic64_dec_unless_positive(v); }
  static inline long raw_atomic_long_dec_if_positive(atomic_long_t *v) { return raw_atomic64_dec_if_positive(v); }
  
  #else /* CONFIG_64BIT */
  typedef atomic_t atomic_long_t;
  #define ATOMIC_LONG_INIT(i)       ATOMIC_INIT(i)
  #define ATOMIC_LONG_PFX(x)        atomic##x
  
  /* 32-bit atomic_long operations (wrap raw_atomic_*) */
  static inline long raw_atomic_long_read(const atomic_long_t *v) { return raw_atomic_read(v); }
  static inline long raw_atomic_long_read_acquire(const atomic_long_t *v) { return raw_atomic_read_acquire(v); }
  static inline void raw_atomic_long_set(atomic_long_t *v, long i) { raw_atomic_set(v, i); }
  static inline void raw_atomic_long_set_release(atomic_long_t *v, long i) { raw_atomic_set_release(v, i); }
  static inline void raw_atomic_long_add(long i, atomic_long_t *v) { raw_atomic_add(i, v); }
  static inline long raw_atomic_long_add_return(long i, atomic_long_t *v) { return raw_atomic_add_return(i, v); }
  static inline long raw_atomic_long_add_return_acquire(long i, atomic_long_t *v) { return raw_atomic_add_return_acquire(i, v); }
  static inline long raw_atomic_long_add_return_release(long i, atomic_long_t *v) { return raw_atomic_add_return_release(i, v); }
  static inline long raw_atomic_long_add_return_relaxed(long i, atomic_long_t *v) { return raw_atomic_add_return_relaxed(i, v); }
  static inline long raw_atomic_long_fetch_add(long i, atomic_long_t *v) { return raw_atomic_fetch_add(i, v); }
  static inline long raw_atomic_long_fetch_add_acquire(long i, atomic_long_t *v) { return raw_atomic_fetch_add_acquire(i, v); }
  static inline long raw_atomic_long_fetch_add_release(long i, atomic_long_t *v) { return raw_atomic_fetch_add_release(i, v); }
  static inline long raw_atomic_long_fetch_add_relaxed(long i, atomic_long_t *v) { return raw_atomic_fetch_add_relaxed(i, v); }
  static inline void raw_atomic_long_sub(long i, atomic_long_t *v) { raw_atomic_sub(i, v); }
  static inline long raw_atomic_long_sub_return(long i, atomic_long_t *v) { return raw_atomic_sub_return(i, v); }
  static inline long raw_atomic_long_sub_return_acquire(long i, atomic_long_t *v) { return raw_atomic_sub_return_acquire(i, v); }
  static inline long raw_atomic_long_sub_return_release(long i, atomic_long_t *v) { return raw_atomic_sub_return_release(i, v); }
  static inline long raw_atomic_long_sub_return_relaxed(long i, atomic_long_t *v) { return raw_atomic_sub_return_relaxed(i, v); }
  static inline long raw_atomic_long_fetch_sub(long i, atomic_long_t *v) { return raw_atomic_fetch_sub(i, v); }
  static inline long raw_atomic_long_fetch_sub_acquire(long i, atomic_long_t *v) { return raw_atomic_fetch_sub_acquire(i, v); }
  static inline long raw_atomic_long_fetch_sub_release(long i, atomic_long_t *v) { return raw_atomic_fetch_sub_release(i, v); }
  static inline long raw_atomic_long_fetch_sub_relaxed(long i, atomic_long_t *v) { return raw_atomic_fetch_sub_relaxed(i, v); }
  static inline void raw_atomic_long_inc(atomic_long_t *v) { raw_atomic_inc(v); }
  static inline long raw_atomic_long_inc_return(atomic_long_t *v) { return raw_atomic_inc_return(v); }
  static inline long raw_atomic_long_inc_return_acquire(atomic_long_t *v) { return raw_atomic_inc_return_acquire(v); }
  static inline long raw_atomic_long_inc_return_release(atomic_long_t *v) { return raw_atomic_inc_return_release(v); }
  static inline long raw_atomic_long_inc_return_relaxed(atomic_long_t *v) { return raw_atomic_inc_return_relaxed(v); }
  static inline long raw_atomic_long_fetch_inc(atomic_long_t *v) { return raw_atomic_fetch_inc(v); }
  static inline long raw_atomic_long_fetch_inc_acquire(atomic_long_t *v) { return raw_atomic_fetch_inc_acquire(v); }
  static inline long raw_atomic_long_fetch_inc_release(atomic_long_t *v) { return raw_atomic_fetch_inc_release(v); }
  static inline long raw_atomic_long_fetch_inc_relaxed(atomic_long_t *v) { return raw_atomic_fetch_inc_relaxed(v); }
  static inline void raw_atomic_long_dec(atomic_long_t *v) { raw_atomic_dec(v); }
  static inline long raw_atomic_long_dec_return(atomic_long_t *v) { return raw_atomic_dec_return(v); }
  static inline long raw_atomic_long_dec_return_acquire(atomic_long_t *v) { return raw_atomic_dec_return_acquire(v); }
  static inline long raw_atomic_long_dec_return_release(atomic_long_t *v) { return raw_atomic_dec_return_release(v); }
  static inline long raw_atomic_long_dec_return_relaxed(atomic_long_t *v) { return raw_atomic_dec_return_relaxed(v); }
  static inline long raw_atomic_long_fetch_dec(atomic_long_t *v) { return raw_atomic_fetch_dec(v); }
  static inline long raw_atomic_long_fetch_dec_acquire(atomic_long_t *v) { return raw_atomic_fetch_dec_acquire(v); }
  static inline long raw_atomic_long_fetch_dec_release(atomic_long_t *v) { return raw_atomic_fetch_dec_release(v); }
  static inline long raw_atomic_long_fetch_dec_relaxed(atomic_long_t *v) { return raw_atomic_fetch_dec_relaxed(v); }
  static inline void raw_atomic_long_and(long i, atomic_long_t *v) { raw_atomic_and(i, v); }
  static inline long raw_atomic_long_fetch_and(long i, atomic_long_t *v) { return raw_atomic_fetch_and(i, v); }
  static inline long raw_atomic_long_fetch_and_acquire(long i, atomic_long_t *v) { return raw_atomic_fetch_and_acquire(i, v); }
  static inline long raw_atomic_long_fetch_and_release(long i, atomic_long_t *v) { return raw_atomic_fetch_and_release(i, v); }
  static inline long raw_atomic_long_fetch_and_relaxed(long i, atomic_long_t *v) { return raw_atomic_fetch_and_relaxed(i, v); }
  static inline void raw_atomic_long_andnot(long i, atomic_long_t *v) { raw_atomic_andnot(i, v); }
  static inline long raw_atomic_long_fetch_andnot(long i, atomic_long_t *v) { return raw_atomic_fetch_andnot(i, v); }
  static inline long raw_atomic_long_fetch_andnot_acquire(long i, atomic_long_t *v) { return raw_atomic_fetch_andnot_acquire(i, v); }
  static inline long raw_atomic_long_fetch_andnot_release(long i, atomic_long_t *v) { return raw_atomic_fetch_andnot_release(i, v); }
  static inline long raw_atomic_long_fetch_andnot_relaxed(long i, atomic_long_t *v) { return raw_atomic_fetch_andnot_relaxed(i, v); }
  static inline void raw_atomic_long_or(long i, atomic_long_t *v) { raw_atomic_or(i, v); }
  static inline long raw_atomic_long_fetch_or(long i, atomic_long_t *v) { return raw_atomic_fetch_or(i, v); }
  static inline long raw_atomic_long_fetch_or_acquire(long i, atomic_long_t *v) { return raw_atomic_fetch_or_acquire(i, v); }
  static inline long raw_atomic_long_fetch_or_release(long i, atomic_long_t *v) { return raw_atomic_fetch_or_release(i, v); }
  static inline long raw_atomic_long_fetch_or_relaxed(long i, atomic_long_t *v) { return raw_atomic_fetch_or_relaxed(i, v); }
  static inline void raw_atomic_long_xor(long i, atomic_long_t *v) { raw_atomic_xor(i, v); }
  static inline long raw_atomic_long_fetch_xor(long i, atomic_long_t *v) { return raw_atomic_fetch_xor(i, v); }
  static inline long raw_atomic_long_fetch_xor_acquire(long i, atomic_long_t *v) { return raw_atomic_fetch_xor_acquire(i, v); }
  static inline long raw_atomic_long_fetch_xor_release(long i, atomic_long_t *v) { return raw_atomic_fetch_xor_release(i, v); }
  static inline long raw_atomic_long_fetch_xor_relaxed(long i, atomic_long_t *v) { return raw_atomic_fetch_xor_relaxed(i, v); }
  static inline long raw_atomic_long_xchg(atomic_long_t *v, long new) { return raw_atomic_xchg(v, new); }
  static inline long raw_atomic_long_xchg_acquire(atomic_long_t *v, long new) { return raw_atomic_xchg_acquire(v, new); }
  static inline long raw_atomic_long_xchg_release(atomic_long_t *v, long new) { return raw_atomic_xchg_release(v, new); }
  static inline long raw_atomic_long_xchg_relaxed(atomic_long_t *v, long new) { return raw_atomic_xchg_relaxed(v, new); }
  static inline long raw_atomic_long_cmpxchg(atomic_long_t *v, long old, long new) { return raw_atomic_cmpxchg(v, old, new); }
  static inline long raw_atomic_long_cmpxchg_acquire(atomic_long_t *v, long old, long new) { return raw_atomic_cmpxchg_acquire(v, old, new); }
  static inline long raw_atomic_long_cmpxchg_release(atomic_long_t *v, long old, long new) { return raw_atomic_cmpxchg_release(v, old, new); }
  static inline long raw_atomic_long_cmpxchg_relaxed(atomic_long_t *v, long old, long new) { return raw_atomic_cmpxchg_relaxed(v, old, new); }
  static inline bool raw_atomic_long_try_cmpxchg(atomic_long_t *v, long *old, long new) { return raw_atomic_try_cmpxchg(v, old, new); }
  static inline bool raw_atomic_long_try_cmpxchg_acquire(atomic_long_t *v, long *old, long new) { return raw_atomic_try_cmpxchg_acquire(v, old, new); }
  static inline bool raw_atomic_long_try_cmpxchg_release(atomic_long_t *v, long *old, long new) { return raw_atomic_try_cmpxchg_release(v, old, new); }
  static inline bool raw_atomic_long_try_cmpxchg_relaxed(atomic_long_t *v, long *old, long new) { return raw_atomic_try_cmpxchg_relaxed(v, old, new); }
  static inline bool raw_atomic_long_sub_and_test(long i, atomic_long_t *v) { return raw_atomic_sub_and_test(i, v); }
  static inline bool raw_atomic_long_dec_and_test(atomic_long_t *v) { return raw_atomic_dec_and_test(v); }
  static inline bool raw_atomic_long_inc_and_test(atomic_long_t *v) { return raw_atomic_inc_and_test(v); }
  static inline bool raw_atomic_long_add_negative(long i, atomic_long_t *v) { return raw_atomic_add_negative(i, v); }
  static inline long raw_atomic_long_fetch_add_unless(atomic_long_t *v, long a, long u) { return raw_atomic_fetch_add_unless(v, a, u); }
  static inline bool raw_atomic_long_add_unless(atomic_long_t *v, long a, long u) { return raw_atomic_add_unless(v, a, u); }
  static inline bool raw_atomic_long_inc_not_zero(atomic_long_t *v) { return raw_atomic_inc_not_zero(v); }
  static inline bool raw_atomic_long_inc_unless_negative(atomic_long_t *v) { return raw_atomic_inc_unless_negative(v); }
  static inline bool raw_atomic_long_dec_unless_positive(atomic_long_t *v) { return raw_atomic_dec_unless_positive(v); }
  static inline long raw_atomic_long_dec_if_positive(atomic_long_t *v) { return raw_atomic_dec_if_positive(v); }
  
  #endif /* CONFIG_64BIT */
  
  #endif /* _LINUX_ATOMIC_LONG_H */
