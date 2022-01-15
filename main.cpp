#include <iomanip>
#include <iostream>

using namespace std;

int main()
{
    bool addTime = true;
    char option = 'a';
    unsigned short hour_display = 0;
    unsigned short minutes_display = 0;
    unsigned short hour = 0;
    unsigned short minutes = 0;
    unsigned short hour_old = 0;
    unsigned short minutes_old = 0;
    unsigned int remainingTime = 0;

    cout << "Hello! Please enter the time in the 24h format." << endl;

    cout << "Enter the duration of you shift in hours: ";
    cin >> remainingTime;
    remainingTime = remainingTime*60;

    while(option != 'e'){
        cout << "Type 'a' to log a new time. Type 'e' to end session: ";
        cin >> option;
        if(option == 'a'){
            hour_old = hour;
            minutes_old = minutes;
            cout << "Type the hour: ";
            cin >> hour;
            cout << "Type the minutes: ";
            cin >> minutes;
            if(addTime){
                hour_display = hour + (remainingTime+minutes)/60;
                minutes_display = (minutes + remainingTime%60)%60;
                cout << "Your shift ends at " << setfill('0') << setw(2) << hour_display << ":" << setfill('0') << setw(2) << minutes_display << endl;
                addTime = false;
            } else {
                remainingTime = remainingTime - ((hour - hour_old)*60 + (minutes - minutes_old));
                addTime = true;
            }
            option = ' ';
        } else
            option = 'e';
    }
    return 0;
}
