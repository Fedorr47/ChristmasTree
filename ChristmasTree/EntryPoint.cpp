#include <vector>
#include <iostream>
#include <iterator>
#include <memory>
#include <thread>
#include <mutex>
#include <windows.h>

#include "ChristmasTree.h"

int main(void)
{
 
    HWND consoleWindow = GetConsoleWindow();
    RECT consoleRectangle;
    GetWindowRect(consoleWindow, &consoleRectangle);

    int newHeight = 640, newWidth = 480;
    MoveWindow(consoleWindow, consoleRectangle.left, consoleRectangle.top, newHeight, newWidth, TRUE);

    AsciiChristmasTree tree(3);
    std::cout << tree << std::endl;
    return 0;
}


