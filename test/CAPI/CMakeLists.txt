# Here we create a single aggregate shared library with the parts of the CAPI
# that we want to bundle together. Then we link a simple C executable
# against it to demonstrate that it does have the fully self contained
# core MLIR library and our own audio dialect.
add_mlir_aggregate(AudioCAPITestLib
  SHARED
  EMBED_LIBS
  MLIRCAPIIR
  MLIRCAPIArith
  AudioCAPI
)

add_llvm_executable(audio-capi-test
  audio-capi-test.c
)
llvm_update_compile_flags(audio-capi-test)
target_link_libraries(audio-capi-test
  PRIVATE AudioCAPITestLib)
