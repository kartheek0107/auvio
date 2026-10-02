# RUN: %python %s 2>&1 | FileCheck %s
import sys

# CHECK: Testing mlir_audio package
print("Testing mlir_audio package", file=sys.stderr)

import mlir_audio.ir
from mlir_audio.dialects import audio_nanobind as audio_d

with mlir_audio.ir.Context():
    audio_d.register_dialects()
    audio_module = mlir_audio.ir.Module.parse(
        """
    %0 = arith.constant 2 : i32
    %1 = audio.foo %0 : i32
    """
    )
    # CHECK: %[[C2:.*]] = arith.constant 2 : i32
    # CHECK: audio.foo %[[C2]] : i32
    print(str(audio_module), file=sys.stderr)

    custom_type = audio_d.CustomType.get("foo")
    # CHECK: !audio.custom<"foo">
    print(custom_type, file=sys.stderr)

    # CHECK: this is a fp16 type
    audio_d.print_fp_type(mlir_audio.ir.F16Type.get(), sys.stderr)
    # CHECK: this is a fp32 type
    audio_d.print_fp_type(mlir_audio.ir.F32Type.get(), sys.stderr)
    # CHECK: this is a fp64 type
    audio_d.print_fp_type(mlir_audio.ir.F64Type.get(), sys.stderr)


# CHECK: Testing mlir package
print("Testing mlir package", file=sys.stderr)

from mlir.ir import *

# CHECK-NOT: RuntimeWarning: nanobind: type '{{.*}}' was already registered!
