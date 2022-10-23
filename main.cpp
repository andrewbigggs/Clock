#include <iostream>
#include <string>
#include <ctime>
#include "clock_fcts.h"

using namespace std;

int main() {

   int currHour, currMinute, currSecond;
   int currHourInc, currMinuteInc, currSecondInc;                 // "Inc" is short for increment
   int inputVar = 0;
   char quitFlag;

   ZeroIncrements(currHourInc, currMinuteInc, currSecondInc);
   SetProgramTime(currHour, currMinute, currSecond);
   Time12and24H(currHour, currMinute, currSecond);

   while (quitFlag != '$') {                                      // Loops until user enters input to exit the program
      
      PrintMenu();
      UserInput(inputVar);
      SetProgramTime(currHour, currMinute, currSecond);
      FormatTime(currHour, currHourInc, currMinute, currMinuteInc, currSecond, currSecondInc);
      if (inputVar == 1 || inputVar == 2 || inputVar == 3) {      // Clears console screen only if new clock is displayed
         ClearConsoleScreen();
      }
      InputOutputSwitch(inputVar, currHour, currHourInc, currMinute, currMinuteInc, currSecond, currSecondInc, quitFlag);
   }

   return 0;
}