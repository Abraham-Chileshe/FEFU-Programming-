#include <iostream>

struct Date{
    int dd,mm,yy;
};
		     //  J   F   M   A   M    J  J   A   S   O   N   D
int MonthDays[12] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int RemainingDays(Date birthday, Date current){

    int year = current.yy; //year given

    long int days1 = birthday.dd; // adding birthday day to total days (d1)
    long int days2 = current.dd; // adding current day to total days (d1)

    //For a leap year
    if (((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0)) {
        for (int i = 0; i < birthday.mm - 1; i++)
            days1 += MonthDays[i];

        for (int i = 0; i < current.mm - 1; i++)
            days2 += MonthDays[i];

        return abs(days2 - days1);
    }
        //----

        //If not a leap year
    else{
        MonthDays[1] = 28;
        for (int i = 0; i < birthday.mm - 1; i++)
            days1 += MonthDays[i];

        for (int i = 0; i < current.mm - 1; i++)
            days2 += MonthDays[i];

        return abs(days2 - days1);
    }
    //--
}

int main(){
    int dd,mm;  //birthday date and month
    int cdd, cmm, cyy; //current date, month and year;

    std::cin >> dd>> mm;
    std::cin >> cdd >> cmm >> cyy;

    Date bday = {dd,mm,0};
    Date cday = {cdd,cmm,cyy};

    std::cout<<RemainingDays(bday,cday);

    return 0;
}
