// Minimal conio.h for Windows (for compatibility)
#ifndef _CONIO_H_
#define _CONIO_H_
#include <stdio.h>
#include <windows.h>

int _kbhit(void) {
    return GetAsyncKeyState(VK_UP) || GetAsyncKeyState(VK_DOWN) || GetAsyncKeyState(VK_LEFT) || GetAsyncKeyState(VK_RIGHT) || GetAsyncKeyState('Q') || GetAsyncKeyState('W') || GetAsyncKeyState('A') || GetAsyncKeyState('S') || GetAsyncKeyState('D');
}

int _getch(void) {
    return getchar();
}
#endif
