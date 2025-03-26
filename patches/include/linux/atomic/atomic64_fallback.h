#ifndef _LINUX_ATOMIC64_FALLBACK_H
#define _LINUX_ATOMIC64_FALLBACK_H

#ifndef ALWAYS_INLINE
#define ALWAYS_INLINE inline __attribute__((always_inline))
#endif

#ifndef raw_atomic64_add
static inline void raw_atomic64_add(long i, atomic64_t *v)
{
    atomic64_add(i, v);
}
#endif

#ifndef raw_atomic64_add_return
static inline long raw_atomic64_add_return(long i, atomic64_t *v)
{
    return atomic64_add_return(i, v);
}
#endif

#ifndef raw_atomic64_add_return_acquire
static inline long raw_atomic64_add_return_acquire(long i, atomic64_t *v)
{
    return atomic64_add_return_acquire(i, v);
}
#endif

#ifndef raw_atomic64_add_return_release
static inline long raw_atomic64_add_return_release(long i, atomic64_t *v)
{
    return atomic64_add_return_release(i, v);
}
#endif

#ifndef raw_atomic64_add_return_relaxed
static inline long raw_atomic64_add_return_relaxed(long i, atomic64_t *v)
{
    return atomic64_add_return_relaxed(i, v);
}
#endif

#ifndef raw_atomic64_fetch_add
static inline long raw_atomic64_fetch_add(long i, atomic64_t *v)
{
    return atomic64_fetch_add(i, v);
}
#endif

#ifndef raw_atomic64_fetch_add_acquire
static inline long raw_atomic64_fetch_add_acquire(long i, atomic64_t *v)
{
    return atomic64_fetch_add_acquire(i, v);
}
#endif

#endif // _LINUX_ATOMIC64_FALLBACK_H
