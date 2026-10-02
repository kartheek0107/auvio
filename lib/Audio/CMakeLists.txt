add_mlir_dialect_library(MLIRAudio
        AudioTypes.cpp
        AudioDialect.cpp
        AudioOps.cpp
        AudioPasses.cpp

        ADDITIONAL_HEADER_DIRS
        ${PROJECT_SOURCE_DIR}/include/Audio

        DEPENDS
        MLIRAudioOpsIncGen
        MLIRAudioPassesIncGen

        LINK_LIBS PUBLIC
        MLIRIR
        MLIRInferTypeOpInterface
        MLIRFuncDialect
        )
