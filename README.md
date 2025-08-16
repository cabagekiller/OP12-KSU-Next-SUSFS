# Automated Kernel Builder for OnePlus 12 (sm8650)

This repository provides a fully automated workflow for building a custom Android kernel for the **OnePlus 12**. It integrates modern features like KernelSU for root access and SUSFS for improved hiding capabilities, packaging everything into a flashable zip.

## Features

- **Automated Builds:** Uses GitHub Actions to compile the kernel automatically.
- **KernelSU Integration:** Integrates KernelSU as a submodule for a clean and reliable root solution.
- **SUSFS Support:** Patches the kernel and KernelSU to support SUSFS, allowing for better hiding of root and other modifications.
- **Custom Patches:** Includes additional patches for performance (e.g., BBRv3 compatibility) and system tweaks.
- **Flashable Zips:** Automatically packages the resulting kernel `Image` into a flashable zip using AnyKernel3.
- **Clean and Maintainable:** All build logic is refactored into simple, well-documented shell scripts.

## How to Use

The build process is handled entirely by GitHub Actions. You have three ways to get a build:

1.  **Push to `main`:** Every push to the `main` branch will trigger the `Build and Release Kernel` workflow. The resulting flashable zip will be available as a build artifact in the **Actions** tab of the repository.
2.  **Create a Tag:** To create a persistent release, push a git tag (e.g., `git tag v1.0 && git push origin v1.0`). The workflow will build the kernel and create a new GitHub Release with the flashable zip attached.
3.  **Manual Trigger:** You can manually trigger a build by navigating to the **Actions** tab, selecting the **Build and Release Kernel** workflow, and clicking the **"Run workflow"** button.

## How It Works

The `.github/workflows/build.yml` workflow orchestrates the entire process:

1.  **Setup Environment:** An Ubuntu runner is prepared with all the necessary build dependencies, including the Google `repo` tool and `pahole` for BTF generation.
2.  **Sync Sources:** The workflow checks out the official OnePlus 12 kernel source code and the required patch repositories.
3.  **Patching:**
    - The `scripts/apply_patches.sh` script is executed to:
      - Copy SUSFS source files into the kernel tree.
      - Apply patches to the kernel and the integrated KernelSU submodule.
      - Inject kernel header fallbacks for BBRv3 compatibility.
4.  **Configuration:**
    - The `scripts/configure_kernel.sh` script is executed to:
      - Modify the kernel's `gki_defconfig` to enable KernelSU, SUSFS, and other features.
      - Run a series of `sed` commands to adjust build flags and version strings for the build.
5.  **Build:** The kernel is compiled using Bazel via the `build_with_bazel.py` script. `ccache` is used to speed up subsequent builds.
6.  **Packaging:** The final kernel `Image` is packaged into a flashable zip file using a checkout of the AnyKernel3 project.
7.  **Release/Upload:** Depending on the trigger (push, tag, or manual), the zip is either uploaded as a build artifact or published as a formal GitHub Release.

## Customization

You can easily customize the build by modifying the scripts in the `scripts/` directory:

- **To add a new kernel patch:**
  1.  Add your `.patch` file to the `patches/` directory.
  2.  Edit `scripts/apply_patches.sh` and add a `patch` command to apply your new patch.

- **To change the kernel configuration:**
  1.  Edit `scripts/configure_kernel.sh` to add or remove `CONFIG` flags from the `gki_defconfig` section.

## Credits

This project stands on the shoulders of giants. A huge thank you to the developers and communities behind these essential tools:

- **KernelSU:** by [tiann](https://github.com/tiann) and the KernelSU team
- **SUSFS:** by [SimonPunk](https://gitlab.com/simonpunk/susfs4ksu)
- **AnyKernel3:** by [osm0sis](https://github.com/osm0sis/AnyKernel3)
- **OnePlus:** For providing the kernel source code.
