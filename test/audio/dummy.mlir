// RUN: audio-opt %s | audio-opt | FileCheck %s

module {
    // CHECK-LABEL: func @bar()
    func.func @bar() {
        %0 = arith.constant 1 : i32
        // CHECK: %{{.*}} = audio.gain %{{.*}} : i32
        %res = audio.gain %0 : i32
        return
    }

    // CHECK-LABEL: func @audio_types(%arg0: !audio.custom<"10">)
    func.func @audio_types(%arg0: !audio.custom<"10">) {
        return
    }
}
