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





## 功能介绍
- 支持年月日模式
- 支持时分秒模式
- 支持年月日时分秒模式
- 支持默认时间和最大、最小时间
- 支持标题的设置，默认为空
- 目前不支持UI自定义
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
2. 在终端 cd 到你的项目根路径
```bash
pod install
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
//点击确定事件
- (void)doneActionWithTime:(nonnull NSString *)time {
    NSLog(@"time==%@", time);
}
//滚动事件
- (void)scrollActionWithTime:(nonnull NSString *)time {
    NSLog(@"time==%@", time);
}
```
- 年月日选择器
```
FQDateTimePickerView *picker = [[FQDateTimePickerView alloc] initWithFQDateTimePickerModel:FQDateTimePickerModelDate];
picker.title = @"FQDateTime";
picker.delegate = self;
picker.minDate = [NSDate new];
[picker show];
```
- 时分秒选择器
```
FQDateTimePickerView *picker = [[FQDateTimePickerView alloc] initWithFQDateTimePickerModel:FQDateTimePickerModelTime];
picker.delegate = self;
picker.maxDate = [NSDate new];
[picker show];
```
- 年月日时分秒选择器
```
FQDateTimePickerView *picker = [[FQDateTimePickerView alloc] initWithFQDateTimePickerModel:FQDateTimePickerModelDateTime];
picker.delegate = self;
picker.maxDate = [NSDate new];
[picker show];
```
>  初始版本功能不多，尤其是不能自定义UI，喜欢的请给个 ⭐️star⭐️，你的点赞我的动力，有需要可[通过博客联系](https://wuwufq.blog.csdn.net/article/details/117815524)
