Pod::Spec.new do |s|
  s.name = "BoomCore"
  s.version = "1.0.0"
  s.summary = "BoomCore is Boom core SDK"
  s.license = {"type"=>"MIT", "file"=>"LICENSE"}
  s.authors = {"805413147@qq.com"=>"mybadge@163.com"}
  s.homepage = "https://github.com/mybadge/BoomCore"
  s.source   = { :git => "https://github.com/mybadge/BoomCore.git", :tag => s.version}
  s.description = "this is Boom Core api, includes RLoud, BRTC, \u662F\u4E00\u4E2A\u91CD\u8981\u7684\u5F00\u53D1\u5DE5\u5177\u5305"
  s.platform  = :ios, '10.0'
  s.requires_arc          = true
  s.frameworks = ["UIKit", "AVFoundation", "Foundation"]
  s.xcconfig = {"CLANG_ALLOW_NON_MODULAR_INCLUDES_IN_FRAMEWORK_MODULES"=>"YES", "ENABLE_BITCODE"=>"YES", "GCC_PREPROCESSOR_DEFINITIONS"=>"$(inherited) PODSPEC_NAME=\#{s.name} PODSPEC_VERSION=\#{s.version}", "OTHER_LDFLAGS"=>"-framework Vloud"}

  s.ios.deployment_target    = '10.0'
  s.ios.vendored_framework   = 'ios/BoomCore.framework'
  s.pod_target_xcconfig = { 'VALID_ARCHS' => 'x86_64 armv7 arm64' }
end
