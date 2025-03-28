#ifndef _ARCH_ATOMIC_LONG_FALLBACK_H
#define _ARCH_ATOMIC_LONG_FALLBACK_H

#ifndef arch_atomic_long_add
#define arch_atomic_long_add(i, v) raw_atomic64_add((i), &(v)->counter)
#endif

#ifndef arch_atomic_long_add_return
#define arch_atomic_long_add_return(i, v) raw_atomic64_add_return((i), &(v)->counter)
#endif

#ifndef arch_atomic_long_add_return_acquire
#define arch_atomic_long_add_return_acquire(i, v) raw_atomic64_add_return_acquire((i), &(v)->counter)
#endif

#ifndef arch_atomic_long_add_return_release
#define arch_atomic_long_add_return_release(i, v) raw_atomic64_add_return_release((i), &(v)->counter)
#endif

#ifndef arch_atomic_long_add_return_relaxed
#define arch_atomic_long_add_return_relaxed(i, v) raw_atomic64_add_return_relaxed((i), &(v)->counter)
#endif

#ifndef arch_atomic_long_fetch_add
#define arch_atomic_long_fetch_add(i, v) raw_atomic64_fetch_add((i), &(v)->counter)
#endif

#ifndef arch_atomic_long_fetch_add_acquire
#define arch_atomic_long_fetch_add_acquire(i, v) raw_atomic64_fetch_add_acquire((i), &(v)->counter)
#endif

#ifndef arch_atomic_long_fetch_add_release
#define arch_atomic_long_fetch_add_release(i, v) raw_atomic64_fetch_add_release((i), &(v)->counter)
#endif

#ifndef arch_atomic_long_fetch_add_relaxed
#define arch_atomic_long_fetch_add_relaxed(i, v) raw_atomic64_fetch_add_relaxed((i), &(v)->counter)
#endif

#endif // _ARCH_ATOMIC_LONG_FALLBACK_H
