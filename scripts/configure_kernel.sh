#!/usr/bin/env bash
set -euxo pipefail

# This script configures the kernel source by modifying defconfig and running sed commands.
# It assumes that the kernel source is located in $BUILD_DIR/kernel_platform/oneplus12_v/kernel_platform

# --- Environment and Path Setup ---
if [ -z "$BUILD_DIR" ]; then
  echo "Error: BUILD_DIR environment variable is not set."
  exit 1
fi

KERNEL_DIR="${BUILD_DIR}/kernel_platform/oneplus12_v/kernel_platform"
DEFCONFIG_FILE="${KERNEL_DIR}/common/arch/arm64/configs/gki_defconfig"

echo " BUILD_DIR: ${BUILD_DIR}"
echo " KERNEL_DIR: ${KERNEL_DIR}"
echo " DEFCONFIG_FILE: ${DEFCONFIG_FILE}"

# --- 1. Add KernelSU and SUSFS configurations to defconfig ---
echo "📦 Appending KernelSU, SUSFS, and other settings to ${DEFCONFIG_FILE}..."

# Use a heredoc to append all configs at once. Check if a key config already exists.
if grep -q "CONFIG_KSU_SUSFS=y" "${DEFCONFIG_FILE}"; then
  echo "  ✅ KernelSU/SUSFS configs already present. Skipping."
else
  cat << EOF >> "${DEFCONFIG_FILE}"

#
# KernelSU, SUSFS, and other custom configurations
#
CONFIG_KSU=y
CONFIG_KSU_SUSFS=y
CONFIG_KSU_SUSFS_HAS_MAGIC_MOUNT=y
CONFIG_KSU_SUSFS_SUS_PATH=y
CONFIG_KSU_SUSFS_SUS_MOUNT=y
CONFIG_KSU_SUSFS_AUTO_ADD_SUS_KSU_DEFAULT_MOUNT=y
CONFIG_KSU_SUSFS_AUTO_ADD_SUS_BIND_MOUNT=y
CONFIG_KSU_SUSFS_SUS_KSTAT=y
CONFIG_KSU_SUSFS_SUS_OVERLAYFS=y
CONFIG_KSU_SUSFS_TRY_UMOUNT=y
CONFIG_KSU_SUSFS_AUTO_ADD_TRY_UMOUNT_FOR_BIND_MOUNT=y
CONFIG_KSU_SUSFS_SPOOF_UNAME=y
CONFIG_KSU_SUSFS_ENABLE_LOG=y
CONFIG_KSU_SUSFS_HIDE_KSU_SUSFS_SYMBOLS=y
CONFIG_KSU_SUSFS_SPOOF_CMDLINE_OR_BOOTCONFIG=y
CONFIG_KSU_SUSFS_OPEN_REDIRECT=y
CONFIG_KSU_SUSFS_SUS_SU=n
CONFIG_KSU_WITH_KPROBES=n
CONFIG_KSU_KPROBES_HOOK=n
CONFIG_COMPAT=y

# Additional tmpfs settings
CONFIG_TMPFS_XATTR=y
CONFIG_TMPFS_POSIX_ACL=y

# Additional networking settings
CONFIG_IP_NF_TARGET_TTL=y
CONFIG_IP6_NF_TARGET_HL=y
CONFIG_IP6_NF_MATCH_HL=y
EOF
  echo "  ✅ Successfully appended configurations."
fi

# --- 2. Perform sed modifications on build scripts and configs ---
echo "📦 Performing sed modifications..."

# Enable LTO (Link Time Optimization) for performance
sed -i 's/CONFIG_LTO=n/CONFIG_LTO=y/' "${DEFCONFIG_FILE}"
sed -i 's/CONFIG_LTO_CLANG_FULL=y/CONFIG_LTO_CLANG_THIN=y/' "${DEFCONFIG_FILE}"
sed -i 's/CONFIG_LTO_CLANG_NONE=y/CONFIG_LTO_CLANG_THIN=y/' "${DEFCONFIG_FILE}"
echo "  -> Enabled ThinLTO."

# Disable defconfig check to prevent build failures on custom configs
sed -i '/check_defconfig/d' "${KERNEL_DIR}/common/build.config.gki"
echo "  -> Disabled defconfig check."

# Append "-Cabage" to the local version string
sed -i '$s|echo "\$res"|echo "\$res-Cabage"|' "${KERNEL_DIR}/common/scripts/setlocalversion"
sed -i '$s|echo "\$res"|echo "\$res-Cabage"|' "${KERNEL_DIR}/msm-kernel/scripts/setlocalversion"
sed -i '$s|echo "\$res"|echo "\$res-Cabage"|' "${KERNEL_DIR}/external/dtc/scripts/setlocalversion"
echo "  -> Set custom kernel version string."

# Remove "-dirty" suffix from version string if the tree is modified
sed -i "/stable_scmversion_cmd/s/-maybe-dirty//g" "${KERNEL_DIR}/build/kernel/kleaf/impl/stamp.bzl"
sed -i 's/-dirty//' "${KERNEL_DIR}/common/scripts/setlocalversion"
sed -i 's/-dirty//' "${KERNEL_DIR}/msm-kernel/scripts/setlocalversion"
sed -i 's/-dirty//' "${KERNEL_DIR}/external/dtc/scripts/setlocalversion"
sed -i 's/-dirty//' "${KERNEL_DIR}/build/kernel/kleaf/workspace_status_stamp.py" || echo "  -> Note: workspace_status_stamp.py not found, skipping."
echo "  -> Removed '-dirty' suffix from version."

# Force LTO to 'thin' and disable image repacking in OnePlus build scripts
sed -i '/echo "LTO $LTO "/i export LTO=thin' "${KERNEL_DIR}/oplus/build/oplus_setup.sh"
sed -i 's/export REPACK_IMG=true/export REPACK_IMG=false/g' "${KERNEL_DIR}/oplus/build/oplus_setup.sh"
echo "  -> Configured OnePlus build scripts for ThinLTO."

echo "✅ All configuration operations complete."
