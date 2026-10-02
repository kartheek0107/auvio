//===- AudioPasses.h - Audio passes  ------------------*- C++ -*-===//
//
// This file is licensed under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//
#ifndef AUDIO_AUDIOPASSES_H
#define AUDIO_AUDIOPASSES_H

#include "Audio/AudioDialect.h"
#include "Audio/AudioOps.h"
#include "mlir/Pass/Pass.h"
#include <memory>

namespace mlir {
namespace audio {
#define GEN_PASS_DECL
#include "Audio/AudioPasses.h.inc"

#define GEN_PASS_REGISTRATION
#include "Audio/AudioPasses.h.inc"
} // namespace audio
} // namespace mlir

#endif
