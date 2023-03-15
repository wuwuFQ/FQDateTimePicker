//
//  FQDateTimePickerView.h
//  FQTools
//
//  Created by wuwuFQ on 2021/5/26.
//

#import <UIKit/UIKit.h>
typedef enum{
    FQDateTimePickerModelYMDate,// 年月 2021-05
    FQDateTimePickerModelDate,// 年月日 2021-05-26
    FQDateTimePickerModelDateTime,//年月日 时分 yyyy-mm-dd HH:mm 只支持24小时制
    FQDateTimePickerModelDateTimeSecond,//年月日 时分秒 yyyy-mm-dd HH:mm:ss 只支持24小时制
    FQDateTimePickerModelTime,// 时分 HH:mm 只支持24小时制
    FQDateTimePickerModelTimeSecond,// 时分秒 HH:mm:ss 只支持24小时制
} FQDateTimePickerModel;


NS_ASSUME_NONNULL_BEGIN
@protocol FQDateTimePickerViewDelegate <NSObject>

/// 确认操作
/// @param date 日期NSDate
/// @param dateStr 日期NSString
/// @param target 用于区分pickerView
- (void)confirmActionWithDate:(NSDate *)date withDateString:(NSString *)dateStr withTarget:(NSInteger)target;

@optional
/// 取消操作
/// @param target 用于区分pickerView
- (void)cancelActionWithTarget:(NSInteger)target;

/// 滚动操作
/// @param date 日期NSDate
/// @param dateStr 日期NSString
/// @param target 用于区分pickerView
- (void)scrollActionWithDate:(NSDate *)date withDateString:(NSString *)dateStr withTarget:(NSInteger)target;

@end


@interface FQDateTimePickerView : UIView
/*----------------   UI  ------------------------*/
/// 遮罩背景色
@property (nonatomic, strong) UIColor *maskBackgroundColor;

/// 选择器背景色
@property (nonatomic, strong) UIColor *pickerBackgroundColor;

/* 选择器面板视图
 * pickerBackgroundColor就是设置的panelView的背景
 * 你可以对panelView设置圆角、阴影等，
 * ⚠️但不要修改frame
 * e.g.: self.pickerView.panelView.layer.cornerRadius = 10;
 */
@property (nonatomic, strong) UIView *panelView;

/* 确定按钮
 * 按钮的外观建议通过已提供的属性设置，也可以自己扩展其他外观
 * e.g.: confirmButton.layer.borderColor
 * ⚠️禁止修改按钮的点击事件
 */
@property (nonatomic, strong) UIButton *confirmButton;
///确定按钮文本
@property (nonatomic, copy) NSString *confirmText;
///确定按钮颜色 默认black
@property (nonatomic, strong) UIColor *confirmColor;
///确定按钮字体 默认系统18pt
@property (nonatomic, strong) UIFont *confirmFont;

/* 取消按钮
 * 按钮的外观建议通过已提供的属性设置，也可以自己扩展其他外观
 * e.g.: cancelButton.layer.borderColor
 * ⚠️禁止修改按钮的点击事件
 */
@property (nonatomic, strong) UIButton *cancelButton;
///取消按钮文本
@property (nonatomic, copy) NSString *cancelText;
///取消按钮颜色 默认黑色
@property (nonatomic, strong) UIColor *cancelColor;
///取消按钮字体 默认系统18pt
@property (nonatomic, strong) UIFont *cancelFont;

///标题文本 默认 ""
@property (nonatomic, copy) NSString *title;
///标题颜色 默认黑色
@property (nonatomic, strong) UIColor *titleColor;
///标题字体 默认系统SFUI-Regular 16.00pt
@property (nonatomic, strong) UIFont *titleFont;

///滚轮日期文本颜色(默认black)
@property (nonatomic, strong) UIColor *pickerColor;
///滚轮日期文本字体[UIFont systemFontOfSize:16]
@property (nonatomic, strong) UIFont *pickerFont;


/*----------------   NSDate  ------------------------*/
///限制最大时间
@property (nonatomic, strong) NSDate *maxDate;
///限制最小时间
@property (nonatomic, strong) NSDate *minDate;
///默认时间 - - 默认当前时间
@property (nonatomic, strong) NSDate *defaultDate;
/// 单位：默认[@"年", @"月", @"日", @"时", @"分", @"秒"]，请一一对应，设置 unitsData = nil 可置空
@property (nonatomic, strong, null_unspecified) NSArray *unitsData;


/*----------------   other  ------------------------*/
/// Protocol
@property (nonatomic, weak) id<FQDateTimePickerViewDelegate> delegate;

/// 选择器的枚举 默认FQDateTimePickerModelDate
@property (nonatomic, assign) FQDateTimePickerModel pickerModel;

/// pickerView的tag  用于区分回调
@property (nonatomic, assign) NSInteger target;

/// 展示在window上（请在展示之前，设置好需要的属性）
- (void)showPicker;

/// 展示在view上（请在展示之前，设置好需要的属性）
/// - Parameter view: <#view description#>
- (void)showPickerInView:(UIView *)view;

@end

NS_ASSUME_NONNULL_END
