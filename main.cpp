#include <iomanip>
#include <limits>
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

    for (;;) {
        cout << "Enter the duration of you shift in hours: ";
        cin >> remainingTime;
        if (cin.fail()) {
            cerr << "Ooops! Please type a number" << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }
        if (remainingTime < 0 || remainingTime > 23) {
            cerr << "Please type a value between 0 and 23" << endl;
            continue;
        }
        break;
    }
    remainingTime = remainingTime*60;

    while(option != 'e'){
        cout << "Type 'a' to log a new time. Type 'e' to end session: ";
        cin >> option;
        if(option == 'a'){
            hour_old = hour;
            minutes_old = minutes;
            for (;;) {
                cout << "Type the hour: ";
                cin >> hour;
                if (cin.fail()) {
                    cerr << "Ooops! Please type a number" << endl;
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    continue;
                }
                if (hour < 0 || hour > 23) {
                    cerr << "Please type a value between 0 and 23" << endl;
                    continue;
                }
                break;
            }
            for (;;) {
                cout << "Type the minutes: ";
                cin >> minutes;
                if (cin.fail()) {
                    cerr << "Ooops! Please type a number" << endl;
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    continue;
                }
                if (minutes < 0 || minutes > 59) {
                    cerr << "Please type a value between 0 and 59" << endl;
                    continue;
                }
                break;
            }
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
        } else if (option == 'e')
                break;
            else
                option = ' ';
    }
    return 0;
}
