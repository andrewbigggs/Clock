#ifndef CLOCK_FCTS_H
#define CLOCK_FCTS_H

void SetProgramTime(int& currHour, int& currMin, int& currSec);
void FormatTime(int& currHour, int& currHourInc, int& currMin, int& currMinInc, int& currSec, int& currSecInc);
void FormatTwoDigitUnits(int currHour, std::string& fm_Hour, int currMin, std::string& fm_Min, int currSec, std::string& fm_Sec);
void AsteriskFill(int spaces);
void Time24H(int currHour, int currMin, int currSec);
void Time12H(int currHour, int currMin, int currSec);
void Time12and24H(int currHour, int currMin, int currSec);
void PrintMenu();
void UserInput(int& inputVar);
void AddHour(int& currHour);
void AddMinute(int& currMin);
void AddSecond(int& currSec);
void ZeroIncrements(int& currHourInc, int& currMinInc, int& currSecInc);
void ClearConsoleScreen();
void InputOutputSwitch(int inputVar, int currHour, int& currHourInc, int currMin, int& currMinInc, int currSec, int& currSecInc, char& quitFlag);

#endif