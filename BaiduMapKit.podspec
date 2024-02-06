#
#  Be sure to run `pod spec lint BaiduMapKit.podspec' to ensure this is a
#  valid spec and to remove all comments including this before submitting the spec.
#
#  To learn more about Podspec attributes see http://docs.cocoapods.org/specification.html
#  To see working Podspecs in the CocoaPods repo see https://github.com/CocoaPods/Specs/
#

Pod::Spec.new do |s|

  s.name         = "RNBaiduMapKit"
  s.version      = '6.6.1'
  s.summary      = "百度地图iOS SDK（CocoaPods百度地图非官方库）"

  s.description  = <<-DESC
                   百度地图iOS SDK：百度地图非官方CocoaPods.
                   百度地图iOS SDK是一套基于iOS 8.0及以上版本设备的应用程序接口，不仅提供展示地图的基本接口，还提供POI检索、路径规划、地图标注、离线地图、步骑行导航等丰富的LBS能力。
                   DESC

  s.homepage     = "http://developer.baidu.com/map/index.php?title=iossdk"
 
  s.license      = { :type => 'Copyright', :text => 'Copyright (c) 2015 BaiduLBS' }

  s.author       = { "baidu map sdk" => "dituapi_01@163.com" }

  s.platform     = :ios, "10.0"

  # s.source       = { :http => "https://lbsyun-baidu.cdn.bcebos.com/iossdk/map/#{s.version}/BaiduMapKitV#{s.version}.zip" }
  s.source       = { :http => "https://lbsyun-baidu.cdn.bcebos.com/ios_external/6.6.1/RNBaiduMapKitV6.6.1.zip" }
  

  # 声明ARC
  s.requires_arc = true 
  # 声明静态库
  s.static_framework = true 

  # 添加系统依赖库
  s.frameworks = ['CoreGraphics', 'CoreLocation', 'CoreTelephony', 'OpenGLES', 'QuartzCore', 'Security', 'SystemConfiguration', 'Accelerate']

  s.libraries = ['sqlite3.0', 'c++', 'z']

  # 声明支持CPU架构
  # valid_archs = ['armv7', 'arm64', 'x86_64']
  # s.xcconfig = { 'VALID_ARCHS' =>  valid_archs.join(' ') }
  # s.pod_target_xcconfig = { 'VALID_ARCHS[sdk=iphonesimulator*]' => 'x86_64' }
  
  # 'EXCLUDED_ARCHS[sdk=iphonesimulator*]' => 'arm64' 适配xcode12，去除模拟器的arm64架构
  # -ObjC地图组件配置 -w 去工程警告
  s.user_target_xcconfig = { 'EXCLUDED_ARCHS[sdk=iphonesimulator*]' => 'arm64',
                             'OTHER_LDFLAGS' => ['-ObjC', '-w'] }

  s.pod_target_xcconfig = { 'EXCLUDED_ARCHS[sdk=iphonesimulator*]' => 'arm64', 
                            'VALID_ARCHS[sdk=iphonesimulator*]' => 'x86_64' }

  # 默认集成的分库
  # s.default_subspecs = ['Base', 'Map', 'Search', 'Cloud', 'Utils']
  s.default_subspecs = ['Base', 'Map', 'Search', 'Utils']

  # base子库
  s.subspec 'Base' do |sp|
  sp.ios.vendored_frameworks = 'BaiduMapKit/BaiduMapAPI_Base.framework'
  sp.ios.vendored_libraries = 'BaiduMapKit/thirdlibs/*.{a}'
  sp.ios.source_files = 'BaiduMapKit/BaiduMapAPI_Base.framework/Headers/*.h'
  sp.ios.public_header_files = 'BaiduMapKit/BaiduMapAPI_Base.framework/Headers/*.h'
  end

  # map子库
  s.subspec 'Map' do |sp|
  sp.ios.dependency 'BaiduMapKit/Base'
  sp.ios.resources = "BaiduMapKit/BaiduMapAPI_Map.framework/*.bundle"
  sp.ios.vendored_frameworks = 'BaiduMapKit/BaiduMapAPI_Map.framework'
  sp.ios.source_files = 'BaiduMapKit/BaiduMapAPI_Map.framework/Headers/*.h'
  sp.ios.public_header_files = 'BaiduMapKit/BaiduMapAPI_Map.framework/Headers/*.h'
  end

  # search子库
  s.subspec 'Search' do |sp|
  sp.ios.dependency 'BaiduMapKit/Base'
  sp.ios.vendored_frameworks = 'BaiduMapKit/BaiduMapAPI_Search.framework'
  sp.ios.source_files = 'BaiduMapKit/BaiduMapAPI_Search.framework/Headers/*.h'
  sp.ios.public_header_files = 'BaiduMapKit/BaiduMapAPI_Search.framework/Headers/*.h'
  end

  # utils子库
  s.subspec 'Utils' do |sp|
  sp.ios.dependency 'BaiduMapKit/Base'
  sp.ios.vendored_frameworks = 'BaiduMapKit/BaiduMapAPI_Utils.framework'
  sp.ios.source_files = 'BaiduMapKit/BaiduMapAPI_Utils.framework/Headers/*.h'
  sp.ios.public_header_files = 'BaiduMapKit/BaiduMapAPI_Utils.framework/Headers/*.h'
  end
  
  # # Bus子库
  # s.subspec 'Bus' do |sp|
  # sp.ios.dependency 'BaiduMapKit/Base'
  # sp.ios.vendored_frameworks = 'BaiduMapKit/BaiduMapAPI_Bus.framework'
  # sp.ios.source_files = 'BaiduMapKit/BaiduMapAPI_Bus.framework/Headers/*.h'
  # sp.ios.public_header_files = 'BaiduMapKit/BaiduMapAPI_Bus.framework/Headers/*.h'
  # end
end
