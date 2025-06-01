#!/bin/bash
set -euxo pipefail

# This script is expected to be run from:
# ${{ env.BUILD_DIR }}/${{ env.KERNEL_DIR }}/kernel_platform

echo "=== Starting SUSFS and Patches Setup ==="

# Define relative paths to the cloned repos (expected to be in BUILD_DIR)
# BUILD_DIR is the parent of KERNEL_DIR, KERNEL_DIR is parent of kernel_platform
# So from kernel_platform, BUILD_DIR is ../../
SUSFS_PATCHES_ROOT="../../susfs4ksu"
LOCAL_PATCHES_ROOT="../../kernel_patches"

# Check if the source directories exist
if [ ! -d "${SUSFS_PATCHES_ROOT}/kernel_patches" ]; then
    echo "Error: ${SUSFS_PATCHES_ROOT}/kernel_patches directory not found!"
    exit 1
fi
if [ ! -d "${LOCAL_PATCHES_ROOT}" ]; then
    echo "Error: ${LOCAL_PATCHES_ROOT} directory not found!"
    exit 1
fi

SUSFS_SPECIFIC_PATCHES="${SUSFS_PATCHES_ROOT}/kernel_patches"
KSU_NEXT_DIR="KernelSU-Next" # Already in kernel_platform/KernelSU-Next

echo "Current directory: $(pwd)"
echo "Listing contents of .: "
ls -A .
echo "Listing contents of common: "
ls -A common || echo "common directory does not exist yet"
echo "Listing contents of ${SUSFS_PATCHES_ROOT}: "
ls -A "${SUSFS_PATCHES_ROOT}"
echo "Listing contents of ${LOCAL_PATCHES_ROOT}: "
ls -A "${LOCAL_PATCHES_ROOT}"


# 1. Create directories
mkdir -p ./common/fs ./common/include/linux

# 2. Copy files from susfs4ksu
echo "Copying files from ${SUSFS_SPECIFIC_PATCHES}..."
cp "${SUSFS_SPECIFIC_PATCHES}/fs/"* ./common/fs/
cp "${SUSFS_SPECIFIC_PATCHES}/include/linux/"* ./common/include/linux/

# 3. Copy patches to their respective locations before applying
echo "Copying patches..."
cp "${SUSFS_SPECIFIC_PATCHES}/50_add_susfs_in_gki-android14-6.1.patch" ./common/
cp "${LOCAL_PATCHES_ROOT}/69_hide_stuff.patch" ./common/
# cp "${LOCAL_PATCHES_ROOT}/next/next_hooks.patch" ./common/ # This patch's application is commented out below, so copying is also commented.
cp "${LOCAL_PATCHES_ROOT}/next/syscall_hooks.patch" ./common/

# The following patches were commented out in the original workflow,
# keeping them commented here for reference.
# cp "${SUSFS_SPECIFIC_PATCHES}/KernelSU/10_enable_susfs_for_ksu.patch" "${KSU_NEXT_DIR}/"
# cp "${LOCAL_PATCHES_ROOT}/0001-kernel-patch-susfs-v1.5.5-to-KernelSU-Next-v1.0.5.patch" "${KSU_NEXT_DIR}/"

# 4. Apply patches
# The original workflow had some patches commented out.
# I'm keeping the logic similar, applying patches that were active.

# Patch for KernelSU-Next (originally commented out)
# cd "${KSU_NEXT_DIR}"
# if [ -f "0001-kernel-patch-susfs-v1.5.5-to-KernelSU-Next-v1.0.5.patch" ]; then
#   echo "Applying 0001-kernel-patch-susfs-v1.5.5-to-KernelSU-Next-v1.0.5.patch to ${KSU_NEXT_DIR}..."
#   # patch -p1 --forward < 0001-kernel-patch-susfs-v1.5.5-to-KernelSU-Next-v1.0.5.patch || echo "Warning: KernelSU SUSFS patch (0001) may have been already applied or failed."
# else
#   echo "Patch file 0001-kernel-patch-susfs-v1.5.5-to-KernelSU-Next-v1.0.5.patch not found in ${KSU_NEXT_DIR}"
# fi
# cd .. # Back to kernel_platform

cd ./common
echo "Applying patches in ./common directory..."
if [ -f "syscall_hooks.patch" ]; then
  patch -p1 -F 3 < syscall_hooks.patch || echo "Warning: syscall_hooks.patch applying failed or already applied."
else
  echo "Patch file syscall_hooks.patch not found in common/"
fi

# next_hooks.patch was commented out in the original workflow
# if [ -f "next_hooks.patch" ]; then
#   # patch -p1 --forward < next_hooks.patch || echo "Warning: next_hooks.patch applying failed or already applied."
# else
#   echo "Patch file next_hooks.patch not found in common/"
# fi


if [ -f "50_add_susfs_in_gki-android14-6.1.patch" ]; then
  patch -p1 < 50_add_susfs_in_gki-android14-6.1.patch || echo "Warning: 50_add_susfs_in_gki-android14-6.1.patch applying failed or already applied."
else
  echo "Patch file 50_add_susfs_in_gki-android14-6.1.patch not found in common/"
fi

if [ -f "69_hide_stuff.patch" ]; then
  patch -p1 -F 3 < 69_hide_stuff.patch || echo "Warning: 69_hide_stuff.patch applying failed or already applied."
else
  echo "Patch file 69_hide_stuff.patch not found in common/"
fi
cd .. # Back to kernel_platform

# 5. Git operations
# These were present in the original workflow to commit changes.
echo "Committing changes related to SUSFS setup..."
# The sed command was commented out, keeping it that way.
# sed -i '/obj-$(CONFIG_KSU_SUSFS_SUS_SU) += sus_su.o/d' ./fs/Makefile # This path seems wrong, should be ./common/fs/Makefile if applicable

# Check for changes in kernel_platform/common and commit them
cd ./common
git diff --quiet --exit-code || (git add -A && git commit -m "BUILD Kernel: Apply SUSFS patches to common" || true)
cd .. # Back to kernel_platform

# Check for changes in kernel_platform (overall) and commit them
git diff --quiet --exit-code || (git add -A && git commit -m "BUILD Kernel: SUSFS setup and other patches" || true)

# This was in the original script, purpose might be to untrack it if it was added by mistake.
# Or if it's a submodule that should not be committed by this parent repo.
git rm --cached KernelSU-Next || true

echo "=== SUSFS and Patches Setup Completed ==="
