#include <iostream>

using namespace std;

int main()
{
    bool addTime = true;
    char option = 'a';
    unsigned short hour = 0;
    unsigned short minutes = 0;
    unsigned short hour_old = 0;
    unsigned short minutes_old = 0;
    unsigned int remainingTime = 8*60;

    cout << "Hello! Type 'a' to log a new time. Type 'e' to end session. " << endl;
    cout << "Please log the time in the 24h format" << endl;

    while(option != 'e'){
        cin >> option;
        if(option == 'a'){
            hour_old = hour;
            minutes_old = minutes;
            cout << "Type the hour: ";
            cin >> hour;
            cout << "Type the minutes: ";
            cin >> minutes;
            if(addTime){
                cout << "Your shift ends at " << (hour + (remainingTime+minutes)/60) << ":" << (minutes + remainingTime%60)%60 << endl;
                addTime = false;
            } else {
                remainingTime = remainingTime - ((hour - hour_old)*60 + (minutes - minutes_old));
                addTime = true;
            }
        }
    }
    return 0;
}
