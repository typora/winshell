{
  "targets": [
    {
      "target_name": "addon",
      "include_dirs": [ '<!(node -e "require(\'nan\')")' ],
      "sources": ["binding.cc", "src/**" ],
       "msbuild_settings": {
          "ClCompile": {
              "LanguageStandard": "stdcpp17"
          }
      },
      "configurations": {
          "Debug": {
              "msbuild_settings": {
                  "ClCompile": {
                      "LanguageStandard": "stdcpp17"
                  }
              }
          },
          "Release": {
            "msbuild_settings": {
                "ClCompile": {
                    "LanguageStandard": "stdcpp17"
                }
            }
          },
      }
    }
  ],
  "msbuild_settings": {
    "ClCompile": {
        "LanguageStandard": "stdcpp17"
    }
  }
}
