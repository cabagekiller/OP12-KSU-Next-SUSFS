#!/usr/bin/env bash
set -euxo pipefail

# This script applies all necessary patches to the kernel source.
# It assumes that the kernel source is located in $BUILD_DIR/kernel_platform/oneplus12_v/kernel_platform
# and the patch repositories are cloned in $BUILD_DIR.

# --- Environment and Path Setup ---
if [ -z "$BUILD_DIR" ]; then
  echo "Error: BUILD_DIR environment variable is not set."
  exit 1
fi

KERNEL_DIR="${BUILD_DIR}/kernel_platform/oneplus12_v/kernel_platform"
SUSFS_PATCH_DIR="${BUILD_DIR}/susfs4ksu/kernel_patches"
CUSTOM_PATCH_DIR="${BUILD_DIR}/kernel_patches"
KSU_DIR="${KERNEL_DIR}/KernelSU-Next"

echo " BUILD_DIR: ${BUILD_DIR}"
echo " KERNEL_DIR: ${KERNEL_DIR}"
echo " SUSFS_PATCH_DIR: ${SUSFS_PATCH_DIR}"
echo " CUSTOM_PATCH_DIR: ${CUSTOM_PATCH_DIR}"
echo " KSU_DIR: ${KSU_DIR}"

# --- 1. Copy SUSFS Source Files ---
echo "📦 Copying SUSFS source files..."
cp "${SUSFS_PATCH_DIR}/fs/susfs.c"           "${KERNEL_DIR}/common/fs/"
cp "${SUSFS_PATCH_DIR}/include/linux/susfs.h" "${KERNEL_DIR}/common/include/linux/"
cp "${SUSFS_PATCH_DIR}/include/linux/susfs_def.h" "${KERNEL_DIR}/common/include/linux/"
echo "✅ SUSFS source files copied."

# --- 2. Apply Patches ---
echo "📦 Applying patches..."

# Patch KernelSU-Next to add SUSFS support
echo "  -> Applying SUSFS support to KernelSU-Next..."
patch -p1 --forward -d "${KSU_DIR}" < "${CUSTOM_PATCH_DIR}/next/0001-kernel-implement-susfs-v1.5.8-KernelSU-Next-v1.0.8.patch" || echo "  ⚠️  Warning: KernelSU SUSFS patch may have already been applied or failed."

# Enter common kernel directory to apply remaining patches
cd "${KERNEL_DIR}/common"

# Apply core SUSFS patch
echo "  -> Applying core SUSFS patch..."
patch -p1 --forward < "${SUSFS_PATCH_DIR}/50_add_susfs_in_gki-android14-6.1.patch" || echo "  ⚠️  Warning: Core SUSFS patch may have already been applied or failed."

# Apply hiding patches
echo "  -> Applying hiding patches..."
patch -p1 --forward -F3 < "${CUSTOM_PATCH_DIR}/69_hide_stuff.patch" || echo "  ⚠️  Warning: 'hide_stuff' patch may have already been applied or failed."
patch -p1 --forward -F3 < "${CUSTOM_PATCH_DIR}/next/scope_min_manual_hooks_v1.4.patch" || echo "  ⚠️  Warning: 'scope_min_manual_hooks' patch may have already been applied or failed."

echo "✅ Patches applied."

# --- 3. Inject Kernel Header Fallbacks (for BBRv3 compatibility) ---
echo "📦 Injecting kernel header fallbacks..."

HEADER_ATOMIC="${KERNEL_DIR}/common/arch/arm64/include/asm/atomic_ll_sc.h"
HEADER_COMPILER="${KERNEL_DIR}/common/include/linux/compiler_types.h"

# Inject atomic fallbacks if not present
if grep -q "BBRv3 compatibility fallback macros" "$HEADER_ATOMIC"; then
  echo "  ✅ Atomic fallbacks already exist. Skipping."
else
  echo "  -> Injecting atomic fallbacks into ${HEADER_ATOMIC}"
  # Using a temporary file to avoid issues with cat and sudo permissions
  TMPFILE=$(mktemp)
  cat << 'EOF' > "$TMPFILE"

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
static inline long arch_atomic_long_fetch_andnot_release(long i, atomic_long_t *v) { long old, new; do { old = atomic_long_read(v); new = old & ~i; } while (atomic_long_cmpxchg_release(v, old, new) != old); return old; }
#endif
#ifndef arch_atomic_long_fetch_xor
static inline long arch_atomic_long_fetch_xor(long i, atomic_long_t *v) { long old, new; do { old = atomic_long_read(v); new = old ^ i; } while (atomic_long_cmpxchg(v, old, new) != old); return old; }
#endif
#ifndef arch_atomic_long_fetch_or
static inline long arch_atomic_long_fetch_or(long i, atomic_long_t *v) { long old, new; do { old = atomic_long_read(v); new = old | i; } while (atomic_long_cmpxchg(v, old, new) != old); return old; }
#endif
#ifndef arch_atomic_long_fetch_and
static inline long arch_atomic_long_fetch_and(long i, atomic_long_t *v) { long old, new; do { old = atomic_long_read(v); new = old & i; } while (atomic_long_cmpxchg(v, old, new) != old); return old; }
#endif
/* END: BBRv3 compatibility fallback macros */
EOF
  cat "$TMPFILE" >> "$HEADER_ATOMIC"
  rm "$TMPFILE"
fi

# Inject asm_volatile_goto fallback if not present
if grep -q "asm_volatile_goto" "$HEADER_COMPILER"; then
  echo "  ✅ asm_volatile_goto fallback already exists. Skipping."
else
  echo "  -> Injecting asm_volatile_goto fallback into ${HEADER_COMPILER}"
  TMPFILE=$(mktemp)
  cat << 'EOF' > "$TMPFILE"

/* BEGIN: asm_volatile_goto fallback */
#ifndef asm_volatile_goto
#define asm_volatile_goto(...) asm volatile(__VA_ARGS__)
#endif
/* END: asm_volatile_goto fallback */
EOF
  cat "$TMPFILE" >> "$HEADER_COMPILER"
  rm "$TMPFILE"
fi

echo "✅ Kernel header fallbacks injected successfully."
echo "✅ All patching operations complete."
