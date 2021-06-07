//
//  FQDateTimePickerView.h
//  FQTools
//
//  Created by TKiOS on 2021/5/26.
//

#import <UIKit/UIKit.h>
typedef enum{
    FQDateTimePickerModelDate,// 年月日 2021-05-26
    FQDateTimePickerModelTime,// 时分秒 HH:mm:ss
    FQDateTimePickerModelDateTime,//年月日 时分秒 yyyy-mm-dd HH:mm:ss
} FQDateTimePickerModel;


NS_ASSUME_NONNULL_BEGIN
@protocol FQDateTimePickerViewDelegate <NSObject>
- (void)doneActionWithTime:(NSString *)time;
- (void)scrollActionWithTime:(NSString *)time;
@end


@interface FQDateTimePickerView : UIView
//确定按钮文本
@property (nonatomic, copy) NSString *doneBtnText;
//确定按钮颜色 默认黑色
@property (nonatomic, strong) UIColor *doneBtnTextColor;
//确定按钮字体 默认系统18pt
@property (nonatomic, strong) UIFont *doneBtnFont;

//取消按钮文本
@property (nonatomic, copy) NSString *cancelBtnText;
//取消按钮颜色 默认黑色
@property (nonatomic, strong) UIColor *cancelBtnTextColor;
//取消按钮字体 默认系统18pt
@property (nonatomic, strong) UIFont *cancelBtnFont;

//时间文字颜色(默认黑色)
@property (nonatomic, strong) UIColor *dateTextColor;

//滚轮日期颜色(默认黑色)
@property (nonatomic, strong) UIColor *datePickerColor;
@property (nonatomic, strong) UIFont *datePickerFont;

//限制最大时间
@property (nonatomic, strong) NSDate *maxDate;

//限制最小时间
@property (nonatomic, strong) NSDate *minDate;
//默认时间
@property (nonatomic, strong) NSDate *defaultDate;

//标题文本
@property (nonatomic, copy) NSString *title;
//标题颜色 默认黑色
@property (nonatomic, strong) UIColor *titleColor;
//标题字体 默认系统18pt
@property (nonatomic, strong) UIFont *titleFont;

@property (nonatomic, weak) id<FQDateTimePickerViewDelegate> delegate;

- (instancetype)initWithFQDateTimePickerModel:(FQDateTimePickerModel)pickerModel;
///请在展示之前，设置好需要的属性
- (void)show;
@end

NS_ASSUME_NONNULL_END
