//===- AudioDialect.td - Audio dialect -----------*- tablegen -*-===//
//
// This file is licensed under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//

#ifndef AUDIO_DIALECT
#define AUDIO_DIALECT

include "mlir/IR/OpBase.td"

//===----------------------------------------------------------------------===//
// Audio dialect definition.
//===----------------------------------------------------------------------===//

def Audio_Dialect : Dialect {
    let name = "audio";
    let summary = "A audio out-of-tree MLIR dialect.";
    let description = [{
        This dialect is an example of an out-of-tree MLIR dialect designed to
        illustrate the basic setup required to develop MLIR-based tools without
        working inside of the LLVM source tree.
    }];
    let cppNamespace = "::mlir::audio";

    let useDefaultTypePrinterParser = 1;
    let extraClassDeclaration = [{
        void registerTypes();
    }];
}

//===----------------------------------------------------------------------===//
// Base audio operation definition.
//===----------------------------------------------------------------------===//

class Audio_Op<string mnemonic, list<Trait> traits = []> :
        Op<Audio_Dialect, mnemonic, traits>;

#endif // AUDIO_DIALECT
