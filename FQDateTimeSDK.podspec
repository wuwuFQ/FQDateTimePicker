#
#  Be sure to run `pod spec lint FQDateTimeSDK.podspec' to ensure this is a
#  valid spec and to remove all comments including this before submitting the spec.
#
#  To learn more about Podspec attributes see https://guides.cocoapods.org/syntax/podspec.html
#  To see working Podspecs in the CocoaPods repo see https://github.com/CocoaPods/Specs/
#

Pod::Spec.new do |spec|

  # ―――  Spec Metadata  ―――――――――――――――――――――――――――――――――――――――――――――――――――――――――― #
  #
  #  These will help people to find your library, and whilst it
  #  can feel like a chore to fill in it's definitely to your advantage. The
  #  summary should be tweet-length, and the description more in depth.
  #

  spec.name         = "FQDateTimeSDK"       #仓库名称
  spec.version      = "1.0.1"               #版本号     
  spec.summary      = "iOS年月日时分秒选择器." #简短的介绍
  spec.description  = <<-DESC#描述放在这里
    FQDateTimeSDK：年月日时分秒选择器，完美模仿原生控件，支持年月日、时分秒、年月日时分秒格式
                   DESC
  spec.homepage     = "https://github.com/wuwuFQ/FQDateTimeSDK" #GitHub上的HTTPS地址，不是clone地址
  spec.license      = { :type => "MIT", :file => "LICENSE"}  #许可证类型  文件就是同级别下的那个LICENSE
  
  spec.author       = { "wuwuFQ" => "13301325631@163.com" } #GitHub 用户名  邮箱

  spec.platform     = :ios, '9.0'   #使用平台

  spec.source       = { :git => "https://github.com/wuwuFQ/FQDateTimeSDK.git", :tag => "#{spec.version}" } #GitHub clone地址



  #spec.source_files  = "Classes", "Classes/**/*.{h,m}"   你要提供的文件
  #spec.exclude_files = "Classes/Exclude"              需要排除的文件

  # spec.public_header_files = "Classes/**/*.h"       暴露的公共头文件

  # 图片资源在这里设置
  # spec.resource  = "icon.png"
  # spec.resources = "Resources/*.png"

    spec.vendored_frameworks  = "FQDateTimeSDK.framework" #我的动态库和本文件同级
    #spec.frameworks = "Foundation", "UIKit"   #多个库的设置
    #spec.requires_arc   = true  支持ARC
    spec.pod_target_xcconfig = { 'VALID_ARCHS' => 'x86_64 armv7 arm64' }

  # spec.library   = "iconv"          静态库在这里设置
  # spec.libraries = "iconv", "xml2"

end
