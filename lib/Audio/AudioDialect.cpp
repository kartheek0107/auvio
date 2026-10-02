//===- AudioDialect.cpp - Audio dialect ---------------*- C++ -*-===//
//
// This file is licensed under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//

#include "Audio/AudioDialect.h"
#include "Audio/AudioOps.h"
#include "Audio/AudioTypes.h"

using namespace mlir;
using namespace mlir::audio;

#include "Audio/AudioOpsDialect.cpp.inc"

//===----------------------------------------------------------------------===//
// Audio dialect.
//===----------------------------------------------------------------------===//

void AudioDialect::initialize() {
  addOperations<
#define GET_OP_LIST
#include "Audio/AudioOps.cpp.inc"
      >();
  registerTypes();
}
