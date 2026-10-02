//===- StandaloneTypes.h - Standalone dialect types -------------*- C++ -*-===//
//
// This file is licensed under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//

#ifndef AUDIO_AUDIOTYPES_H
#define AUDIO_AUDIOTYPES_H

#include "mlir/IR/BuiltinTypes.h"

#define GET_TYPEDEF_CLASSES
#include "Audio/AudioOpsTypes.h.inc"

#endif // AUDIO_AUDIOTYPES_H
