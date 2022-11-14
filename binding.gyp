{
  "targets": [
    {
      "target_name": "addon",
      "include_dirs": [ '<!(node -e "require(\'nan\')")' ],
      "sources": ["binding.cc", "src/**" ],
      "msvs_settings": {
        "VCCLCompilerTool": { "AdditionalOptions": ["/std:c++17" ] }
      }
    }
  ]
}
