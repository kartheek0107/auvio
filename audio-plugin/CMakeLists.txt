add_llvm_library(AudioPlugin
        # BUILDTREE_ONLY is only for testing purposes
        MODULE BUILDTREE_ONLY
        audio-plugin.cpp

        DEPENDS
        MLIRAudio
        PLUGIN_TOOL
        mlir-opt

        LINK_LIBS
        MLIRAudio
        )
target_include_directories(
        AudioPlugin
        PRIVATE
        "${AUDIO_BINARY_DIR}/include"
)
