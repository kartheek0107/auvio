//===- Dialects.cpp - CAPI for dialects -----------------------------------===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//

#include "Audio-c/Dialects.h"

#include "Audio/AudioDialect.h"
#include "Audio/AudioTypes.h"
#include "mlir/CAPI/Registration.h"

MLIR_DEFINE_CAPI_DIALECT_REGISTRATION(Audio, audio,
                                      mlir::audio::AudioDialect)

MlirType mlirAudioCustomTypeGet(MlirContext ctx, MlirStringRef value) {
  return wrap(mlir::audio::CustomType::get(unwrap(ctx), unwrap(value)));
}

bool mlirAudioTypeIsACustomType(MlirType t) {
  return llvm::isa<mlir::audio::CustomType>(unwrap(t));
}

MlirTypeID mlirAudioCustomTypeGetTypeID() {
  return wrap(mlir::audio::CustomType::getTypeID());
}
