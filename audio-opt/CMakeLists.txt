set(LIBS
    MLIRArithDialect
    MLIROptLib
    MLIRRegisterAllDialects
    MLIRRegisterAllPasses
    MLIRAudio
  )
add_llvm_executable(audio-opt audio-opt.cpp)

llvm_update_compile_flags(audio-opt)
target_link_libraries(audio-opt PRIVATE ${LIBS})

mlir_check_all_link_libraries(audio-opt)
