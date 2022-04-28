![最美女帝](https://user-images.githubusercontent.com/23627803/121161116-417c5080-c87f-11eb-94cb-dab46a05360b.jpeg)

# FQDateTimeSDK
[博客地址](https://wuwufq.blog.csdn.net/article/details/117815524)
> iOS时间选择器，日期选择器；年月日、时分秒选择器。
> 在原生控件的基础上增加`秒`的选择，和原生PickerView一样的丝滑。

<div  align = 'center' >
<img src="https://user-images.githubusercontent.com/23627803/121637253-afad5700-cabb-11eb-995d-670320281613.png" width = 30% height = 30% >
<img src="https://user-images.githubusercontent.com/23627803/121647056-8b0bac00-cac8-11eb-9d78-8f72979268e4.png" width = 30% height = 30% >
<img src="https://user-images.githubusercontent.com/23627803/121647086-9232ba00-cac8-11eb-8ee9-b0a6404b22ab.png" width = 30% height = 30% >
    <img src="https://user-images.githubusercontent.com/23627803/121642635-606b2480-cac3-11eb-8c72-f6edcee614b1.gif" width = 50% height = 50% >

</div>


# 更新记录
- 1.0.1版本 2022-04-29
    1. 日期的单位支持自定义
    2. 修复每月天数不实时刷新
    
- 1.0版本 2022-04-21
    1. 增加更多picker模式：支持年月、年月日、时分、时分秒、年月日时分、年月日时分秒
    2. 可自定义字体大小和颜色



## 功能介绍
- 支持年月日模式
- 支持时分秒模式
- 支持年月日时分秒模式
- 支持默认时间和最大、最小时间
- 支持标题的设置，默认为空
- 字体大小和颜色可以自定义


## 集成方式
### 手动集成
1. 把项目`clone`或`Download ZIP`到本地
2. 把项目内的`FQDateTimeSDK.framework`拖到你的项目里
![image](https://user-images.githubusercontent.com/23627803/121634046-80e0b200-cab6-11eb-8a93-e853bddddb7e.png)
3. 设置 `Embed&Sign`
![image](https://user-images.githubusercontent.com/23627803/121634466-2bf16b80-cab7-11eb-9024-b3e4afa18941.png)

### cocoaPods自动集成
_这里默认大家对cocoaPods都是信手拈来的_
1. 在Podfile引入
```bash
pod 'FQDateTimeSDK'
```
或者
```bash
pod 'FQDateTimeSDK', '~> 1.0.1'
```
2. 在终端 cd 到你的项目根路径 
- 下载
```bash
pod install
```
或者
```bash
pod install --no-repo-update
```
- 更新
```bash
pod update
```
或者
```bash
pod update FQDateTimeSDK --no-repo-update
```
## 使用案列
1. 在用到时间选择器的地方引用头文件
```object-c
#import <FQDateTimeSDK/FQDateTimeSDK.h>
```
2. 遵循代理`FQDateTimePickerViewDelegate`
```
@interface ViewController ()<FQDateTimePickerViewDelegate>

@end
```
3. 实现代理方法
```
- (void)cancelAction {
    NSLog(@"wuwuFQ：cancelAction");
}

- (void)confirmActionWithDate:(nonnull NSDate *)date withDateString:(nonnull NSString *)dateStr {
    NSLog(@"wuwuFQ：%@---%@", date, dateStr);
}

- (void)scrollActionWithDate:(nonnull NSDate *)date withDateString:(nonnull NSString *)dateStr {
    NSLog(@"wuwuFQ：%@---%@", date, dateStr);
}
```
- 年月日选择器
```
FQDateTimePickerView *pickerView = [[FQDateTimePickerView alloc] init];
pickerView.delegate = self;
pickerView.pickerModel = indexPath.row;
pickerView.cancelColor = [UIColor greenColor];
pickerView.pickerColor = [UIColor systemPinkColor];
pickerView.title = @"wuwuFQ";
pickerView.titleColor = [UIColor redColor];
[pickerView showPicker];
```

>  有问题可以一起探讨，喜欢的请给个 ⭐️star⭐️，你的点赞我的动力，有需要可[通过博客联系](https://wuwufq.blog.csdn.net/article/details/117815524)
