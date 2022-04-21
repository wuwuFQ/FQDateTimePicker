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
    FQDateTimePickerModelTime,// 时分 HH:mm 只支持24小时制
    FQDateTimePickerModelTimeSecond,// 时分秒 HH:mm:ss 只支持24小时制
    FQDateTimePickerModelDateTime,//年月日 时分 yyyy-mm-dd HH:mm 只支持24小时制
    FQDateTimePickerModelDateTimeSecond,//年月日 时分秒 yyyy-mm-dd HH:mm:ss 只支持24小时制
} FQDateTimePickerModel;


NS_ASSUME_NONNULL_BEGIN
@protocol FQDateTimePickerViewDelegate <NSObject>

/// 确认操作
/// @param date 日期NSDate
/// @param dateStr 日期NSString
- (void)confirmActionWithDate:(NSDate *)date withDateString:(NSString *)dateStr;

/// 取消操作
- (void)cancelAction;

/// 滚动操作
/// @param date 日期NSDate
/// @param dateStr 日期NSString
- (void)scrollActionWithDate:(NSDate *)date withDateString:(NSString *)dateStr;

@end


@interface FQDateTimePickerView : UIView
/*----------------   UI  ------------------------*/
//确定按钮文本
@property (nonatomic, copy) NSString *confirmText;
//确定按钮颜色 默认black
@property (nonatomic, strong) UIColor *confirmColor;
//确定按钮字体 默认系统18pt
@property (nonatomic, strong) UIFont *confirmFont;

//取消按钮文本
@property (nonatomic, copy) NSString *cancelText;
//取消按钮颜色 默认黑色
@property (nonatomic, strong) UIColor *cancelColor;
//取消按钮字体 默认系统18pt
@property (nonatomic, strong) UIFont *cancelFont;

//标题文本 默认 ""
@property (nonatomic, copy) NSString *title;
//标题颜色 默认黑色
@property (nonatomic, strong) UIColor *titleColor;
//标题字体 默认系统SFUI-Regular 16.00pt
@property (nonatomic, strong) UIFont *titleFont;

//滚轮日期文本颜色(默认black)
@property (nonatomic, strong) UIColor *pickerColor;
//滚轮日期文本字体[UIFont systemFontOfSize:16]
@property (nonatomic, strong) UIFont *pickerFont;


/*----------------   NSDate  ------------------------*/
//限制最大时间
@property (nonatomic, strong) NSDate *maxDate;
//限制最小时间
@property (nonatomic, strong) NSDate *minDate;
//默认时间
@property (nonatomic, strong) NSDate *defaultDate;


@property (nonatomic, weak) id<FQDateTimePickerViewDelegate> delegate;

/// 选择器的枚举 默认FQDateTimePickerModelDate
@property (nonatomic, assign) FQDateTimePickerModel pickerModel;
///请在展示之前，设置好需要的属性
- (void)showPicker;
@end

NS_ASSUME_NONNULL_END
