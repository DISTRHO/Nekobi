DPF_ADD_PLUGIN(Nekobi
  TARGETS vst2
  FILES_DSP
      DistrhoPluginNekobi.cpp
  FILES_UI
      DistrhoArtworkNekobi.cpp
      DistrhoUINekobi.cpp)

target_include_directories(Nekobi PUBLIC 
    "."
    "nekobee-src"
)
