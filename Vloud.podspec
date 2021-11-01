Pod::Spec.new do |s|
    s.name                  = 'Vloud'
    s.version               = '0.4.0'
    s.summary               = 'Vloud is a framework for BoomCore use.'
    s.license               = 'MIT'
    s.author                = { "zhaozhidan" => "zhaozhidan@baijiayun.com" }
    s.homepage              = 'https://git.baijiashilian.com/LLL/frondend/VLoud'
    s.source                = { :git => "https://git.baijiashilian.com/LLL/frondend/VLoud.git", :tag => s.version}
    s.platform              = :ios, '10.0'
    s.requires_arc          = true
    s.ios.deployment_target = '10.0'
    s.libraries             = 'c', 'sqlite3', 'stdc++'
    s.framework             = 'AudioToolbox','AVFoundation', 'CoreAudio', 'CoreGraphics', 'CoreVideo', 'GLKit', 'VideoToolbox'
    # s.public_header_files = 'Vloud.framework/Headers/*.h'
    s.vendored_frameworks   = 'Vloud.framework'
    s.pod_target_xcconfig = { 'VALID_ARCHS' => 'x86_64 armv7 arm64' }
end
