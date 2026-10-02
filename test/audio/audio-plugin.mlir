// UNSUPPORTED: system-windows
// RUN: mlir-opt %s --load-dialect-plugin=%audio_libs/AudioPlugin%shlibext --pass-pipeline="builtin.module(audio-switch-bar-foo)" | FileCheck %s

module {
  // CHECK-LABEL: func @foo()
  func.func @bar() {
    return
  }

  // CHECK-LABEL: func @audio_types(%arg0: !audio.custom<"10">)
  func.func @audio_types(%arg0: !audio.custom<"10">) {
    return
  }
}
