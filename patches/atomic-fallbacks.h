#ifndef _LINUX_ATOMIC_FALLBACKS_H
#define _LINUX_ATOMIC_FALLBACKS_H

/*
 * Fallback definitions removed entirely to prevent conflicts
 * with externally provided atomic definitions (e.g., atomic-long.h,
 * atomic-raw64-compat.h) and because the original fallbacks
 * contained incorrect/non-atomic code.
 */

 /* Original includes were:
  * #include <linux/atomic/arch_atomic_long_fallback.h>
  * #include <linux/atomic/raw_atomic64_fallback.h>
  * These are also skipped now.
  */

#endif /* _LINUX_ATOMIC_FALLBACKS_H */
