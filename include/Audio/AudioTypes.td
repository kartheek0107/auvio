//===- AudioTypes.td - Audio dialect types -------*- tablegen -*-===//
//
// This file is licensed under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//

#ifndef AUDIO_TYPES
#define AUDIO_TYPES

include "mlir/IR/AttrTypeBase.td"
include "Audio/AudioDialect.td"

//===----------------------------------------------------------------------===//
// Audio type definitions
//===----------------------------------------------------------------------===//

class Audio_Type<string name, string typeMnemonic, list<Trait> traits = []>
    : TypeDef<Audio_Dialect, name, traits> {
  let mnemonic = typeMnemonic;
}

def Audio_CustomType : Audio_Type<"Custom", "custom"> {
    let summary = "Audio custom type";
    let description = "Custom type in audio dialect";
    let parameters = (ins StringRefParameter<"the custom value">:$value);
    let assemblyFormat = "`<` $value `>`";
}

#endif // AUDIO_TYPES
