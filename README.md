

![coding](https://user-images.githubusercontent.com/23627803/204128599-89a9527e-381e-4278-ac0a-3323ce9e858b.png)



# FQDateTimePicker
> iOS时间选择器，日期选择器；年月日、时分秒选择器。
> 在原生控件的基础上增加`秒`的选择，和原生PickerView一样的丝滑。
### [博客地址，可评论](https://wuwufq.blog.csdn.net/article/details/117815524)
### [博客地址，可探讨](https://wuwufq.blog.csdn.net/article/details/117815524)
### [博客地址，可私聊](https://wuwufq.blog.csdn.net/article/details/117815524)

<div  align='center'>
<img src="https://user-images.githubusercontent.com/23627803/121637253-afad5700-cabb-11eb-995d-670320281613.png" width = 30% height = 30% >
<img src="https://user-images.githubusercontent.com/23627803/121647056-8b0bac00-cac8-11eb-9d78-8f72979268e4.png" width = 30% height = 30% >
<img src="https://user-images.githubusercontent.com/23627803/121647086-9232ba00-cac8-11eb-8ee9-b0a6404b22ab.png" width = 30% height = 30% >
<img src="https://user-images.githubusercontent.com/23627803/121642635-606b2480-cac3-11eb-8c72-f6edcee614b1.gif" width = 50% height = 50% >

</div>


## 更新记录

|版本| 更新内容 |日期|
|--|:--|--|
|2.0.3|- iOS18移除Bitcode|2024-11-24|
|2.0.2 | - 适配iOS安全区域| 2023-05-16|
|2.0.1 | - 修复获取keyWindow不正确的问题| 2023-04-17|
|2.0 | - 重构工程，重命名Framework <br>- 代理函数有改变，其他无变化| 2023-04-16|
|1.1.5 | - 选择器只展示在window层，避免视图错乱| 2023-03-27|
|1.1.4 | - 修复12小时制的显示问题| 2023-03-16|
|1.1.3 | - 暴露出面板视图、确定按钮、取消按钮，可以根据自己的业务绘制pickerView| 2023-03-15|
|1.1.2 | - 修复picker显示问题 <br>- 优化选择器的选择动画| 2022-11-29|
|1.1.1 | - 优化时分秒的显示| 2022-11-23|
|1.1 | - 设置maxDate、minDate后，范围外的时间不可见| 2022-10-01|
|1.0.6 | - picker可以展示在view和window上| 2022-09-23|
|1.0.5 | - 优化picker弧度，更贴合原生| 2022-09-14|
|1.0.4 | - 增加pickerBackgroundColor，可以修改pickerView背景色 <br>- 支持bitcode| 2022-08-08|
|1.0.3 | - 增加maskBackgroundColor，可以修改遮罩颜色 | 2022-05-27|
|1.0.2| - 增加target，用以区分pickerView|2022-05-14|
|1.0.1| - 日期的单位支持自定义  <br>- 修复每月天数不实时刷新|2022-04-29|
|1.0|- 增加更多picker模式：支持年月、年月日、时分、时分秒、年月日时分、年月日时分秒 <br>- 可自定义字体大小和颜色|2022-04-21|



## 功能介绍
- 支持年月日模式
- 支持时分秒模式
- 支持年月日时分秒模式
- 支持默认时间和最大、最小时间
- 支持标题的设置，默认为空
- 字体大小和颜色可以自定义
- 支持背景色和遮罩颜色自定义

## 集成方式
### 手动集成
1. 把项目`clone`或`Download ZIP`到本地
2. 把项目内的`FQDateTimePicker.framework`拖到你的项目里
![image](https://user-images.githubusercontent.com/23627803/121634046-80e0b200-cab6-11eb-8a93-e853bddddb7e.png)
3. 如果项目报错  `Library not loaded: @rpath/FQDateTimePicker.framework/FQDateTimePicker`， 设置 `Embed&Sign`
![image](https://user-images.githubusercontent.com/23627803/121634466-2bf16b80-cab7-11eb-9024-b3e4afa18941.png)
4. 如果项目报错` Building for iOS Simulator, but the linked and embedded framework 'FQDateTimePicker.framework' was built for iOS + iOS Simulator. `
解决方法是： `Buil Settings` --> `Build Options` --> `Validate Workspace` 改为**Yes**
![Xnip2022-05-14_22-26-55](https://user-images.githubusercontent.com/23627803/168431873-9f4bb708-9a7e-44ee-8989-77524b38e0d0.jpg)

   

### cocoaPods自动集成
_这里默认大家对cocoaPods都是信手拈来的_
1. 在Podfile引入
```bash
pod 'FQDateTimePicker'
```
或者
```bash
pod 'FQDateTimePicker', '~> 2.0.2'
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
pod update FQDateTimePicker --no-repo-update
```
## 使用案列
1. 在用到时间选择器的地方引用头文件
```object-c
#import <FQDateTimePicker/FQDateTimePicker.h>
```
2. 遵循代理`FQDateTimePickerViewDelegate`
```
@interface ViewController ()<FQDateTimePickerViewDelegate>

@end
```
3. 实现代理方法
```
- (void)cancelActionFQDateTimePicker:(FQDateTimePickerView *)pickerView{
    NSLog(@"wuwuFQ：cancelAction");
}

- (void)confirmActionFQDateTimePicker:(FQDateTimePickerView *)pickerView WithDate:(NSDate *)date withDateString:(NSString *)dateStr {
    NSLog(@"wuwuFQ：%@---%@", date, dateStr);
    self.contentLabel.text = dateStr;
}

- (void)scrollActionFQDateTimePicker:(FQDateTimePickerView *)pickerView WithDate:(NSDate *)date withDateString:(NSString *)dateStr {
    NSLog(@"wuwuFQ：%@---%@", date, dateStr);
}

```
- 年月日选择器
```
    FQDateTimePickerView *pickerView = [[FQDateTimePickerView alloc] init];
    pickerView.delegate = self;    //遵循代理
    pickerView.pickerModel = FQDateTimePickerModelDate;    //日期模式
    pickerView.cancelColor = [UIColor greenColor];    //取消颜色
    pickerView.pickerColor = [UIColor yellowColor];    //滚轮字体颜色
    pickerView.maskBackgroundColor = UIColor.cyanColor;    //遮罩颜色
    pickerView.pickerBackgroundColor = UIColor.lightGrayColor;    //选择器背景色
    pickerView.title = @"wuwuFQ";    //标题
    pickerView.titleColor = [UIColor redColor];    //标题颜色
    pickerView.unitsData = nil;    //单位重置
    pickerView.minDate = [NSDate new];    //最小时间
    [pickerView showPicker];    //展示
```

>  有问题可以一起探讨，喜欢的请给个 ⭐️star⭐️，你的点赞我的动力，有需要可[通过博客联系](https://wuwufq.blog.csdn.net/article/details/117815524)
