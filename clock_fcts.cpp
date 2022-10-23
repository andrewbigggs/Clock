#include <iostream>
#include <string>
#include <ctime>

using namespace std;

// Stores current system time in three int variables
void SetProgramTime(int& currHour, int& currMin, int& currSec) {  
   time_t CURR_TIME;
   CURR_TIME = time(NULL);
   string currentTime = (ctime(&CURR_TIME));

   int colonIndex = currentTime.find(':');
   int currentHour = stoi(currentTime.substr(colonIndex - 2, 2));
   int currentMinute = stoi(currentTime.substr(colonIndex + 1, 2));
   int currentSecond = stoi(currentTime.substr(colonIndex + 4, 2));

   currHour = currentHour;
   currMin = currentMinute;
   currSec = currentSecond;

   return;
}
// Reformats the stored int variables for the current time based on user adjustments
void FormatTime(int& currHour, int& currHourInc, int& currMin, int& currMinInc, int& currSec, int& currSecInc) {
   currHour += currHourInc;      
   currMin += currMinInc;
   currSec += currSecInc;

   while (currHour > 23) {
      currHour -= 24;
   }
   while (currMin > 59) {
      currMin -= 60;
   }
   while (currSec > 59) {
      currSec -= 60;
   }

   return;
}
// Ensures hour, minute, second values always hold precisely two digits (example: 7:8:9 becomes 07:08:09)
// "fm_" is short for formatted.
void FormatTwoDigitUnits(int currHour, string& fm_Hour, int currMin, string& fm_Min, int currSec, string& fm_Sec) {
   if (currHour <= 9) {
      fm_Hour = "0";
      fm_Hour.append(to_string(currHour));
   } 
   else {
      fm_Hour = to_string(currHour); }

   if (currMin <= 9) {
      fm_Min = "0";
      fm_Min.append(to_string(currMin));
   }
   else {
      fm_Min = to_string(currMin); }

   if (currSec <= 9) {
      fm_Sec = "0";
      fm_Sec.append(to_string(currSec));
   }
   else {
      fm_Sec = to_string(currSec); }

}
// Prints a line of asterisks
void AsteriskFill(int spaces) {
   for (int i = 0; i < spaces; ++i) {
      cout << '*';
   }
   return;
}
// Outputs the 24-hour clock
void Time24H(int currHour, int currMin, int currSec) {
   string fm_Hour, fm_Min, fm_Sec;

   FormatTwoDigitUnits(currHour, fm_Hour, currMin, fm_Min, currSec, fm_Sec);
   AsteriskFill(16);
   cout << endl << "*   24H Time   *" << endl;
   cout << "*   " << fm_Hour << ':' << fm_Min << ':' << fm_Sec << "   *" << endl;
   AsteriskFill(16);
   cout << endl;
   return;
}
// Outputs the 12-hour clock
void Time12H(int currHour, int currMin, int currSec) {
   string fm_Hour, fm_Min, fm_Sec;
   string AM_PM;
   int currHour12H;
   
   if (currHour < 12) {
      AM_PM = "AM";
   }
   else {
      AM_PM = "PM";
   }
   if ((currHour % 12) != 0) {
      currHour12H = currHour % 12;
   }
   else {
      currHour12H = 12;
   }

   FormatTwoDigitUnits(currHour12H, fm_Hour, currMin, fm_Min, currSec, fm_Sec);
   AsteriskFill(16);
   cout << endl << "*   12H Time   *" << endl;
   cout << "*   " << fm_Hour << ':' << fm_Min << ':' << fm_Sec << " " << AM_PM << "*" << endl;
   AsteriskFill(16);
   cout << endl;
   return;
}
// Outputs both the 12- and 24- clocks next to one another
void Time12and24H(int currHour, int currMin, int currSec) {
   string fm_Hour, fm_Min, fm_Sec;
   string AM_PM;
   int currHour12H;

   if (currHour < 12) {
      AM_PM = "AM";
   }
   else {
      AM_PM = "PM";
   }
   if ((currHour % 12) != 0) {
      currHour12H = currHour % 12;
   }
   else {
      currHour12H = 12;
   }
   
   FormatTwoDigitUnits(currHour12H, fm_Hour, currMin, fm_Min, currSec, fm_Sec);
   AsteriskFill(40);
   cout << endl << "*   12H Time   *** ** ***   24H Time   *" << endl;
   cout << "*   " << fm_Hour << ':' << fm_Min << ':' << fm_Sec << " " << AM_PM << "*";
   FormatTwoDigitUnits(currHour, fm_Hour, currMin, fm_Min, currSec, fm_Sec);
   cout << "** ** ***   " << fm_Hour << ':' << fm_Min << ':' << fm_Sec << "   *" << endl;
   AsteriskFill(40);
   cout << endl;

   return;
}
// Prints the menu
void PrintMenu() {
   AsteriskFill(24);
   cout << endl;
   cout << "*      Main Menu       *" << endl;
   cout << "* 1: Display 12H Time  *" << endl;
   cout << "* 2: Display 24H Time  *" << endl;
   cout << "* 3: Display 12H & 24H *" << endl;
   cout << "* 4: Add 1 Hour        *" << endl;
   cout << "* 5: Add 1 Minute      *" << endl;
   cout << "* 6: Add 1 Second      *" << endl;
   cout << "* 7: Sync to System    *" << endl;
   cout << "* 8: Exit Program      *" << endl;
   AsteriskFill(24);
   cout << endl;

   return;
}
// Gets and ensures user input is within the range defined by the program
void UserInput(int& inputVar) {
      cout << ">";
      cin >> inputVar;
      cout << endl;

      while (inputVar != 1 && inputVar != 2 && inputVar != 3 && inputVar != 4 && 
      inputVar != 5 && inputVar != 6 && inputVar != 7 && inputVar != 8) {
         cout << "Enter an integer corresponding to a menu selection. (1 through 8)" << endl;
         cout << ">";
         cin >> inputVar;
      }
   
   return;
}
// Makes the system time output by all clocks to be incremented by 1 hour
void AddHour(int& currHourInc) {
   ++currHourInc;
   return;
}
// Makes the system time output by all clocks to be incremented by 1 minute
void AddMinute(int& currMinInc) {
   ++currMinInc;
   return;
}
// Makes the system time output by all clocks to be incremented by 1 second
void AddSecond(int& currSecInc) {
   ++currSecInc;
   return;
}
// Sets values for all user increments to zero.
void ZeroIncrements(int& currHourInc, int& currMinInc, int& currSecInc) {
   currHourInc = 0;
   currMinInc = 0;
   currSecInc = 0;
   return;
}
// Prints 51 lines to clear the console screen
void ClearConsoleScreen() {
   for (int i = 0; i < 51; ++i) {
      cout << endl;
   }
   return;
}
// Determines which functions are called based on user input
void InputOutputSwitch(int inputVar, int currHour, int& currHourInc, 
int currMin, int& currMinInc, int currSec, int& currSecInc, char& quitFlag) {
   switch (inputVar) {
      case 1:
         Time12H(currHour, currMin, currSec);
         break;
      case 2:
         Time24H(currHour, currMin, currSec);
         break;
      case 3:
         Time12and24H(currHour, currMin, currSec);
         break;
      case 4:
         AddHour(currHourInc);
         break;
      case 5:
         AddMinute(currMinInc);
         break;
      case 6:
         AddSecond(currSecInc);
         break;
      case 7:
         ZeroIncrements(currHourInc, currMinInc, currSecInc);
         break;
      case 8:
         quitFlag = '$';
         break;
   }
}