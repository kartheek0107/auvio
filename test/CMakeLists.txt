llvm_canonicalize_cmake_booleans(
        MLIR_ENABLE_BINDINGS_PYTHON
)

configure_lit_site_cfg(
        ${CMAKE_CURRENT_SOURCE_DIR}/lit.site.cfg.py.in
        ${CMAKE_CURRENT_BINARY_DIR}/lit.site.cfg.py
        MAIN_CONFIG
        ${CMAKE_CURRENT_SOURCE_DIR}/lit.cfg.py
)

set(AUDIO_TEST_DEPENDS
        FileCheck count not
        audio-capi-test
        audio-opt
        audio-translate
        )
if(NOT WIN32)
  list(APPEND AUDIO_TEST_DEPENDS AudioPlugin)
endif()
if(MLIR_ENABLE_BINDINGS_PYTHON)
  list(APPEND AUDIO_TEST_DEPENDS AudioPythonModules)
endif()

add_lit_testsuite(check-audio "Running the audio regression tests"
        ${CMAKE_CURRENT_BINARY_DIR}
        DEPENDS ${AUDIO_TEST_DEPENDS}
        )
set_target_properties(check-audio PROPERTIES FOLDER "Tests")

add_lit_testsuites(AUDIO ${CMAKE_CURRENT_SOURCE_DIR} DEPENDS ${AUDIO_TEST_DEPENDS})

add_subdirectory(CAPI)
