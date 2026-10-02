//===- AudioTypes.cpp - Audio dialect types -----------*- C++ -*-===//
//
// This file is licensed under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//

#include "Audio/AudioTypes.h"

#include "Audio/AudioDialect.h"
#include "mlir/IR/Builders.h"
#include "mlir/IR/DialectImplementation.h"
#include "llvm/ADT/TypeSwitch.h"

using namespace mlir::audio;

#define GET_TYPEDEF_CLASSES
#include "Audio/AudioOpsTypes.cpp.inc"

void AudioDialect::registerTypes() {
  addTypes<
#define GET_TYPEDEF_LIST
#include "Audio/AudioOpsTypes.cpp.inc"
      >();
}
