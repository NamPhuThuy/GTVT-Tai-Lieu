#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct {
	int hour;
	int minute;
	int second;
} Time;

typedef struct {
	int year;
	int month;
	int day;
} Date;



void inputTime(Time *t, int hour, int minute, int second){
	t->hour = hour;
	t->minute = minute;
	t->second = second;
}

//ham hien thi
void displayTime(Time t){
	printf("%02d:%02d:%02d\n", t.hour, t.minute, t.second);
}

//ham cong
void updateTime(Time *t, int addHour, int addMinute, int addSecond){
	t->second += addSecond;
	t->minute += t->second/60;
	t->second %= 60;
	
	t->minute += addMinute;
	t->hour += t->minute/60;
	t->minute %= 60;
	
	t->hour += addHour;
	t->hour %= 24;	
}

//ham kiem tra hop le
bool isValidTime(Time t){
	return (t.hour >=0 && t.hour < 24) &&
			(t.minute >=0 && t.minute < 60) &&
			(t.second >=0 && t.second < 60);
}

	// Ham xu ly Date

// Hàm nhập
void inputDate(Date *d, int day, int month, int year){
	d->day = day;
	d->month = month;
	d->year = year;
}

// Hàm hiển thị
void displayDate(Date d){
	printf("%02d/%02d/%04d\n", d.day, d.month, d.year);
}

// Hàm kiểm tra năm nhuận
bool isLeapYear(int year){
	return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

bool isValidDate(Date d, int *maxDays){
	// Kiểm tra điều kiện cơ bản
	if (d.year < 0 || d.month < 1 || d.month > 12 || d.day < 1) {
        return false;
    }
	
	// Tạo biến ngày tối đa có thể đạt được
    *maxDays = 31;

	// Kiểm tra ngày của mỗi tháng xem có hợp lệ không
    switch (d.month) {
        case 4:
        case 6:
        case 9:
        case 11:
            *maxDays = 30;
            break;
        case 2:
            *maxDays = (isLeapYear(d.year)) ? 29 : 28;
            break;
    }

    return d.day <= *maxDays;
}

void updateDate(Date *d, int addDay, int addMonth, int addYear, int maxDays)
{
    d->day += addDay;
    if (d->day > maxDays)
    {
    	d->month += d->day / maxDays;
    	d->day %= maxDays;
	}
    
    
    d->month += addMonth;
    if (d->month > 12)
    {
    	d->year += d->month / 12;
    	d->month %= 12;
	}
    
    d->year += addYear;
}

int main(){
	Time t;
	inputTime(&t, 13, 54, 30);
	if(isValidTime(t)){
		displayTime(t);
		updateTime(&t, 2, 10, 20);
		displayTime(t);
	}
	else{
		printf("Tiem khong hop le!\n");
	}
	
	Date d;
	inputDate(&d, 18, 2, 2023);
	int maxDays;
//	if (isValidDate(d, &maxDays)){
	if (isValidDate(d, &maxDays) == true){
		displayDate(d);
		updateDate(&d, 3, 5, 12, maxDays);
		displayDate(d);
	} else{
		printf("Date khong hop le!");
	}
		
////	}
//	else{
//		printf("Date khong hop le!\n");
//	}
}
