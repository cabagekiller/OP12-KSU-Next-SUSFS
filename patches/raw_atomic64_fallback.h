#ifndef _RAW_ATOMIC64_FALLBACK_H
#define _RAW_ATOMIC64_FALLBACK_H

#ifndef raw_atomic64_add
#define raw_atomic64_add(i, v) ((v)->counter += (i))
#endif

#ifndef raw_atomic64_add_return
#define raw_atomic64_add_return(i, v) (((v)->counter += (i)))
#endif

#ifndef raw_atomic64_add_return_acquire
#define raw_atomic64_add_return_acquire(i, v) raw_atomic64_add_return(i, v)
#endif

#ifndef raw_atomic64_add_return_release
#define raw_atomic64_add_return_release(i, v) raw_atomic64_add_return(i, v)
#endif

#ifndef raw_atomic64_add_return_relaxed
#define raw_atomic64_add_return_relaxed(i, v) raw_atomic64_add_return(i, v)
#endif

#ifndef raw_atomic64_fetch_add
#define raw_atomic64_fetch_add(i, v) __extension__ ({ typeof((v)->counter) __old = (v)->counter; (v)->counter += (i); __old; })
#endif

#ifndef raw_atomic64_fetch_add_acquire
#define raw_atomic64_fetch_add_acquire(i, v) raw_atomic64_fetch_add(i, v)
#endif

#ifndef raw_atomic64_fetch_add_release
#define raw_atomic64_fetch_add_release(i, v) raw_atomic64_fetch_add(i, v)
#endif

#ifndef raw_atomic64_fetch_add_relaxed
#define raw_atomic64_fetch_add_relaxed(i, v) raw_atomic64_fetch_add(i, v)
#endif

#endif // _RAW_ATOMIC64_FALLBACK_H
