#include "Options.hpp"

#include <iostream>
#include <conio.h>
#include <ctime>
#include <thread>
#include <chrono>

using namespace std;

//------------------------------------------------------------------------------
// main
int main(const int argc, char* argv[])
{
    Options options;
    CLI11_PARSE(options.Application, argc, argv);

    // Start
    cout << options.GetFormattedMessageText();

    const auto start_time = time(nullptr);
    const auto exit_time  = start_time + options.TimeoutSeconds;
    const auto sleepDuration = chrono::duration<double, milli>(options.SleepMilliseconds);

    do
    {
        if (_kbhit())
        {
            _getch();
            break;
        }
        this_thread::sleep_for(sleepDuration);
    }
    while (time(nullptr) < exit_time || options.TimeoutSeconds == 0);

    cout << endl;

    return 0;
}
