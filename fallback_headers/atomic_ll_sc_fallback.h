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
#define raw_atomic64_fetch_add_acquire(i, v &#8203;:contentReference[oaicite:0]{index=0}&#8203;
