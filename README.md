
##问题
Xcode 验证不通过的时候添加下面的选项
s.pod_target_xcconfig = { 'VALID_ARCHS' => 'x86_64 armv7 arm64' }

## 发布新版本

```
git tag -a 0.4.0 -m 'v0.4.0' -f
```

## 检测仓库是否有语法错误
 pod lib lint --verbose --use-libraries
 
## 推送framework 到私有仓库
pod repo push boom Vloud.podspec  --use-libraries --allow-warnings


## 推送framework 到公有仓库
pod trunk push BoomCore.podspec --verbose --skip-import-validation

##  pod lib lint --skip-import-validation


## 推送 BoomCore 到 cocopod

```
pod trunk push BoomCore.podspec
```