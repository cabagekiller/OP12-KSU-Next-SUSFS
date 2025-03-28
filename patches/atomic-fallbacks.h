#ifndef _LINUX_ATOMIC_FALLBACKS_H
#define _LINUX_ATOMIC_FALLBACKS_H

#ifndef ALWAYS_INLINE
#define ALWAYS_INLINE inline __attribute__((always_inline))
#endif
#include <linux/atomic/arch_atomic_long_fallback.h>
#include <linux/atomic/raw_atomic64_fallback.h>


static ALWAYS_INLINE long raw_atomic_long_add_return(long i, atomic_long_t *v)
{
    atomic_long_t temp = *v;
    *v += i;
    return temp;
}

static ALWAYS_INLINE long raw_atomic64_add_return(long i, atomic64_t *v)
{
    atomic64_t temp = *v;
    atomic64_add(i, v);
    return temp;
}

static ALWAYS_INLINE long raw_atomic_long_add_return_acquire(long i, atomic_long_t *v)
{
    return raw_atomic_long_add_return(i, v);
}

static ALWAYS_INLINE long raw_atomic64_add_return_acquire(long i, atomic64_t *v)
{
    atomic64_t temp = *v;
    atomic64_add(i, v);
    return temp;
}

static ALWAYS_INLINE long raw_atomic_long_add_return_release(long i, atomic_long_t *v)
{
    return raw_atomic_long_add_return(i, v);
}

static ALWAYS_INLINE long raw_atomic64_add_return_release(long i, atomic64_t *v)
{
    atomic64_t temp = *v;
    atomic64_add(i, v);
    return temp;
}

static ALWAYS_INLINE long raw_atomic_long_add_return_relaxed(long i, atomic_long_t *v)
{
    return raw_atomic_long_add_return(i, v);
}

static ALWAYS_INLINE long raw_atomic64_add_return_relaxed(long i, atomic64_t *v)
{
    atomic64_t temp = *v;
    atomic64_add(i, v);
    return temp;
}

#endif /* _LINUX_ATOMIC_FALLBACKS_H */
