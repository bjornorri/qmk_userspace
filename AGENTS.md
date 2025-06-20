# AGENTS Instructions

This repository contains personal QMK userspace files and keymaps.

## Coding Style

- Format all `*.c` and `*.h` files using `qmk format-c users/**/*` before committing.
- The `.clang-format` file defines the style; do not modify it.

## Pull Requests

- Summarize the changes briefly in the PR body.
- Include any test or formatting output if relevant.

## Building

- Build for individual keyboards using `make pro` and `make max`.
- Build for all relevant keyboard targets using `make all`.

## Testing

- No automated tests are required, but run `qmk format-c users/**/*` to verify style and `make all` to verify that the code builds.
