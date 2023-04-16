//
//  ViewController.m
//  FQDateTimeDemo
//
//  Created by wuwuFQ on 2022/4/28.
//

#import "ViewController.h"
#import <FQDateTimePicker/FQDateTimePicker.h>

@interface ViewController ()<FQDateTimePickerViewDelegate, UITableViewDelegate, UITableViewDataSource>
@property (nonatomic, strong) UITableView *tableView;
@property (nonatomic, copy) NSArray *listTitles;
@property (nonatomic, strong) UILabel *contentLabel;
@end

@implementation ViewController


-(UITableView *)tableView {
    if (!_tableView) {
        _tableView = [[UITableView alloc] initWithFrame:CGRectMake(0, 0, self.view.bounds.size.width, 400) style:UITableViewStylePlain];
        _tableView.delegate = self;
        _tableView.dataSource = self;
        _tableView.tableFooterView = [UIView new];

    }
    return _tableView;
}

-(NSArray *)listTitles {
    return @[@"年月",
             @"年月日",
             @"年月日 时分",
             @"年月日 时分秒",
             @"时分",
             @"时分秒",];
}

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view.
    [self.view addSubview:self.tableView];
    self.contentLabel = [UILabel new];
    self.contentLabel.frame = CGRectMake(0, 420, self.view.bounds.size.width, 40);
    self.contentLabel.textAlignment = NSTextAlignmentCenter;
    self.contentLabel.font = [UIFont boldSystemFontOfSize:18];
    [self.view addSubview:self.contentLabel];
    
}

-(NSInteger)tableView:(UITableView *)tableView numberOfRowsInSection:(NSInteger)section {
    return self.listTitles.count;
}

-(UITableViewCell *)tableView:(UITableView *)tableView cellForRowAtIndexPath:(NSIndexPath *)indexPath {
    static NSString *cellIdentifier = @"cellIdentifier";
    UITableViewCell *cell = [tableView dequeueReusableCellWithIdentifier:cellIdentifier];
    if (!cell) {
        cell = [[UITableViewCell alloc] initWithStyle:UITableViewCellStyleValue1 reuseIdentifier:cellIdentifier];
    }
    cell.textLabel.text = [NSString stringWithFormat:@"FQ: %@", self.listTitles[indexPath.row]];
    cell.accessoryType = UITableViewCellAccessoryDisclosureIndicator;
    return cell;
}

-(void)tableView:(UITableView *)tableView didSelectRowAtIndexPath:(NSIndexPath *)indexPath {
    [tableView deselectRowAtIndexPath:indexPath animated:YES];
    FQDateTimePickerView *pickerView = [[FQDateTimePickerView alloc] init];
    pickerView.delegate = self;    //遵循代理
    pickerView.pickerModel = indexPath.row;    //日期模式
//    pickerView.cancelColor = [UIColor greenColor];    //取消颜色
//    pickerView.pickerColor = [UIColor yellowColor];    //滚轮字体颜色
//    pickerView.maskBackgroundColor = UIColor.cyanColor;    //遮罩颜色
//    pickerView.pickerBackgroundColor = UIColor.lightGrayColor;    //选择器背景色
    pickerView.title = @"wuwuFQ";    //标题
    pickerView.titleColor = [UIColor redColor];    //标题颜色
//    pickerView.unitsData = nil;    //单位重置
//    pickerView.minDate = [NSDate new];    //最小时间
    [pickerView showPicker];    //展示
}
- (void)cancelActionFQDatetimePicker:(FQDateTimePickerView *)pickerView{
    NSLog(@"wuwuFQ：cancelAction");
}

- (void)confirmActionFQDatetimePicker:(FQDateTimePickerView *)pickerView WithDate:(NSDate *)date withDateString:(NSString *)dateStr {
    NSLog(@"wuwuFQ：%@---%@", date, dateStr);
    self.contentLabel.text = dateStr;
}

- (void)scrollActionFQDatetimePicker:(FQDateTimePickerView *)pickerView WithDate:(NSDate *)date withDateString:(NSString *)dateStr {
    NSLog(@"wuwuFQ：%@---%@", date, dateStr);
}

@end
