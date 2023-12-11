#include <iostream>
#include "clsPeriod.h"

using namespace std;

int main()
{
    // string x = "Alhasan Saleem Shakra";
    // int Position = x.find('m');
    // // by find() built in.
    // cout << Position << endl;

    // //----------------

    // clsString String1("Alhasan Saleem Shakra");
    
    // // by FindElementPosition() with object.
    // cout << String1.FindElementPosition('m') << endl;
    // // by FindElementPosition() with static non-object.
    // cout << clsString::FindElementPosition("Alhasan Saleem Shakra", "m");

    // clsDate Date1(3, 12, 2023);
    // clsDate Date2(9, 12, 2023);
    // cout << clsDate::CalculateBusinessDays(Date1, Date2);

    clsPeriod Period1(clsDate(1, 1, 2022), clsDate(10, 1, 2022));
    Period1.Print();

    cout << "\n";

    clsPeriod Period2(clsDate(3, 1, 2022), clsDate(5, 1, 2022));
    Period2.Print();


    //You can check like this
    cout << Period1.IsOverLapWith(Period2) <<endl;


    //Also you can call the static method and send period 1 and period 2
    cout << clsPeriod::IsOverlapPeriods(Period1, Period2) << endl;

    return 0;
}