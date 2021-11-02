Pod::Spec.new do |s|
  s.name = "BoomCore"
  s.version = "1.0.1.4"
  s.summary = "BoomCore is Boom core SDK"
  s.license = {"type"=>"MIT", "file"=>"LICENSE"}
  s.authors = {"zhaozhidan"=>"mybadge@163.com"}
  s.homepage = "https://github.com/mybadge/BoomCore"
  s.source   = { :git => "https://github.com/mybadge/BoomCore.git", :tag => s.version}
  s.description = "this is Boom Core api, includes VLoud"
  s.platform  = :ios, '10.0'
  s.requires_arc          = true
  s.frameworks = ["UIKit", "AVFoundation", "Foundation", "AudioToolbox", "CoreAudio", "CoreGraphics", "CoreVideo", "GLKit", "VideoToolbox"]
  s.libraries = 'c', 'sqlite3', 'stdc++'
  # s.xcconfig = {"CLANG_ALLOW_NON_MODULAR_INCLUDES_IN_FRAMEWORK_MODULES"=>"YES", "ENABLE_BITCODE"=>"YES", "GCC_PREPROCESSOR_DEFINITIONS"=>"$(inherited) PODSPEC_NAME=\#{s.name} PODSPEC_VERSION=\#{s.version}"}

  s.ios.deployment_target    = '10.0'
  s.ios.vendored_frameworks   = 'ios/BoomCore.framework', 'ios/Vloud.framework'
  s.vendored_frameworks = 'ios/BoomCore.framework', 'ios/Vloud.framework'
  # s.pod_target_xcconfig = { 'VALID_ARCHS' => 'arm64' }
  s.pod_target_xcconfig = {
    'ARCHS[sdk=iphonesimulator*]' => '$(ARCHS_STANDARD_64_BIT)'
  }

end
