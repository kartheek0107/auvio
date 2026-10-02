include(AddMLIRPython)

# Specifies that all MLIR packages are co-located under the `mlir_audio`
# top level package (the API has been embedded in a relocatable way).
add_compile_definitions("MLIR_PYTHON_PACKAGE_PREFIX=${MLIR_PYTHON_PACKAGE_PREFIX}.")


################################################################################
# Sources
################################################################################

declare_mlir_python_sources(AudioPythonSources)

declare_mlir_dialect_python_bindings(
  ADD_TO_PARENT AudioPythonSources
  ROOT_DIR "${CMAKE_CURRENT_SOURCE_DIR}/mlir_audio"
  TD_FILE dialects/AudioOps.td
  SOURCES
    dialects/audio_nanobind.py
    _mlir_libs/_AudioDialectsNanobind/py.typed
  DIALECT_NAME audio)

declare_mlir_python_extension(AudioPythonSources.NanobindExtension
  MODULE_NAME _audioDialectsNanobind
  ADD_TO_PARENT AudioPythonSources
  SOURCES
    AudioExtensionNanobind.cpp
  EMBED_CAPI_LINK_LIBS
    MLIRCAPIIR
    MLIRCAPIArith
    MLIRCAPITransforms
    AudioCAPI
)


################################################################################
# Common CAPI
################################################################################

add_mlir_python_common_capi_library(AudioPythonCAPI
  INSTALL_COMPONENT AudioPythonModules
  INSTALL_DESTINATION "${MLIR_BINDINGS_PYTHON_INSTALL_PREFIX}/_mlir_libs"
  OUTPUT_DIRECTORY "${MLIR_BINARY_DIR}/${MLIR_BINDINGS_PYTHON_INSTALL_PREFIX}/_mlir_libs"
  RELATIVE_INSTALL_ROOT "../../../.."
  DECLARED_SOURCES
    AudioPythonSources
    MLIRPythonSources.Core
    MLIRPythonSources.Dialects.builtin
)

################################################################################
# Instantiation of all Python modules
################################################################################

set(AudioPythonModules_ROOT_PREFIX "${MLIR_BINARY_DIR}/${MLIR_BINDINGS_PYTHON_INSTALL_PREFIX}")

if(MLIR_PYTHON_STUBGEN_ENABLED)
  # Everything here is very tightly coupled. See the ample descriptions at the bottom of
  # mlir/python/CMakeLists.txt.

  # For a non-external projects build (e.g., installed distro) the type gen targets for the core _mlir module
  # need to be re-declared. On the contrary, for an external projects build, the MLIRPythonExtension.Core.type_stub_gen
  # target already exists and can just be added to DECLARED_SOURCES (see below).
  if(NOT EXTERNAL_PROJECT_BUILD)
    set(_core_type_stub_sources
      _mlir/__init__.pyi
      _mlir/ir.pyi
      _mlir/passmanager.pyi
      _mlir/rewrite.pyi
    )
    get_target_property(_core_extension_srcs MLIRPythonExtension.Core INTERFACE_SOURCES)
    mlir_generate_type_stubs(
      MODULE_NAME _mlir
      DEPENDS_TARGETS AudioPythonModules.extension._mlir.dso
      OUTPUT_DIR "${CMAKE_CURRENT_BINARY_DIR}/type_stubs/_mlir_libs"
      OUTPUTS "${_core_type_stub_sources}"
      DEPENDS_TARGET_SRC_DEPS "${_core_extension_srcs}"
      IMPORT_PATHS "${AudioPythonModules_ROOT_PREFIX}/_mlir_libs"
      VERBOSE
    )
    set(_mlir_typestub_gen_target "${NB_STUBGEN_CUSTOM_TARGET}")

    list(TRANSFORM _core_type_stub_sources PREPEND "_mlir_libs/")
    declare_mlir_python_sources(
      AudioPythonExtension.Core.type_stub_gen
      ROOT_DIR "${CMAKE_CURRENT_BINARY_DIR}/type_stubs"
      ADD_TO_PARENT AudioPythonSources
      SOURCES "${_core_type_stub_sources}"
    )
  endif()

  get_target_property(_audio_extension_srcs AudioPythonSources.NanobindExtension INTERFACE_SOURCES)
  mlir_generate_type_stubs(
    MODULE_NAME mlir_audio._mlir_libs._audioDialectsNanobind
    DEPENDS_TARGETS
      AudioPythonModules.extension._mlir.dso
      AudioPythonModules.extension._audioDialectsNanobind.dso
    OUTPUT_DIR "${CMAKE_CURRENT_BINARY_DIR}/type_stubs/_mlir_libs"
    OUTPUTS
      _audioDialectsNanobind/__init__.pyi
      _audioDialectsNanobind/audio.pyi
    DEPENDS_TARGET_SRC_DEPS "${_audio_extension_srcs}"
    IMPORT_PATHS "${AudioPythonModules_ROOT_PREFIX}/.."
  )
  set(_audioDialectsNanobind_typestub_gen_target "${NB_STUBGEN_CUSTOM_TARGET}")

  declare_mlir_python_sources(
    AudioPythonSources.type_stub_gen
    ROOT_DIR "${CMAKE_CURRENT_BINARY_DIR}/type_stubs"
    ADD_TO_PARENT AudioPythonSources
    SOURCES
      _mlir_libs/_audioDialectsNanobind/__init__.pyi
      _mlir_libs/_audioDialectsNanobind/audio.pyi
  )
endif()

set(_declared_sources
  AudioPythonSources
  MLIRPythonSources.Core
  MLIRPythonSources.Dialects.builtin
)
# For an external projects build, the MLIRPythonExtension.Core.type_stub_gen
# target already exists and can just be added to DECLARED_SOURCES.
if(EXTERNAL_PROJECT_BUILD AND MLIR_PYTHON_STUBGEN_ENABLED)
  list(APPEND _declared_sources MLIRPythonExtension.Core.type_stub_gen)
endif()

add_mlir_python_modules(AudioPythonModules
  ROOT_PREFIX "${AudioPythonModules_ROOT_PREFIX}"
  INSTALL_PREFIX "${MLIR_BINDINGS_PYTHON_INSTALL_PREFIX}"
  DECLARED_SOURCES "${_declared_sources}"
  COMMON_CAPI_LINK_LIBS
    AudioPythonCAPI
)

if(MLIR_PYTHON_STUBGEN_ENABLED)
  if(NOT EXTERNAL_PROJECT_BUILD)
    add_dependencies(AudioPythonModules "${_mlir_typestub_gen_target}")
  endif()
  add_dependencies(AudioPythonModules "${_audioDialectsNanobind_typestub_gen_target}")
endif()
