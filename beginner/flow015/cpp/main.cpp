#include <iostream>
#include <vector>
#include <map>
#include <set>
using namespace std;

enum Day {MON, TUE, WED, THU, FRI, SAT, SUN};

int countDaysOfYear(int year)
{
    if (year % 4) return 365;
    if (!(year % 400)) return 366;
    if (!(year % 100)) return 365;
    return 366;
}

int main(void)
{
    const int base = 2001;
    int t;
    cin >> t;
    while(t--)
    {
        int year;
        cin >> year;
        int days = 0;
        if (year >= 2001)
        {
            for (int i = base; i < year; ++i) {
                days += countDaysOfYear(i);
            }
        }

        else 
        {
            for (int i = year; i < base; ++i) {
                days -= countDaysOfYear(i);
            }
        }
        days %= 7;
        if (days < 0) days += 7;

        switch(days)
        {
            case MON:
            { 
                cout << "monday" << endl;
                break;
            }
            case TUE:
            { 
                cout << "tuesday" << endl;
                break;
            }
            case WED:
            { 
                cout << "wednesday" << endl;
                break;
            }
            case THU:
            { 
                cout << "thursday" << endl;
                break;
            }
            case FRI:
            { 
                cout << "friday" << endl;
                break;
            }
            case SAT:
            { 
                cout << "saturday" << endl;
                break;
            }
            case SUN:
            { 
                cout << "sunday" << endl;
                break;
            }
        }

    }
    return 0;
}
