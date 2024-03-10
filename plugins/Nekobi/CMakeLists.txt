dpf_add_plugin(Nekobi
  TARGETS
    au clap dssi lv2 vst2 vst3
  FILES_DSP
    DistrhoPluginNekobi.cpp
  FILES_UI
    DistrhoArtworkNekobi.cpp
    DistrhoUINekobi.cpp
)

target_include_directories(Nekobi
  PUBLIC
    .
    nekobee-src
)
