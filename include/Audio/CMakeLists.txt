add_mlir_dialect(AudioOps audio)
add_mlir_doc(AudioDialect AudioDialect Audio/ -gen-dialect-doc)
add_mlir_doc(AudioOps AudioOps Audio/ -gen-op-doc)

set(LLVM_TARGET_DEFINITIONS AudioPasses.td)
mlir_tablegen(AudioPasses.h.inc --gen-pass-decls)
add_public_tablegen_target(MLIRAudioPassesIncGen)
