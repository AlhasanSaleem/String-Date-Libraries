#include<iostream>
#include "clsDate.h"

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

    clsDate Date1(3, 12, 2023);
    clsDate Date2(9, 12, 2023);
    cout << clsDate::CalculateBusinessDays(Date1, Date2);
    return 0;
}