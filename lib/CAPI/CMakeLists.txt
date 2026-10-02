add_mlir_public_c_api_library(AudioCAPI
  Dialects.cpp
  LINK_LIBS PUBLIC
  MLIRAudio
)
