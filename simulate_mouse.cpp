#include "simulate_mouse.h"
#include <iostream>

const double XSCALEFACTOR = 65535.0 / (GetSystemMetrics(SM_CXSCREEN) - 1);
const double YSCALEFACTOR = 65535.0 / (GetSystemMetrics(SM_CYSCREEN) - 1);

void SendLeftClick(LONG dx, LONG dy)
{
    double x = dx * XSCALEFACTOR;
    double y = dy * YSCALEFACTOR;

    POINT cursor;
    GetCursorPos(&cursor);

    INPUT input[2];
    input[0].type = INPUT_MOUSE;
    input[0].mi.dx = x;
    input[0].mi.dy = y;
    input[0].mi.dwFlags = MOUSEEVENTF_MOVE | MOUSEEVENTF_ABSOLUTE | MOUSEEVENTF_LEFTDOWN;//must have MOUSEEVENTF_MOVE

    input[1].type = INPUT_MOUSE;
    input[1].mi.dx = x;
    input[1].mi.dy = y;
    input[1].mi.dwFlags = MOUSEEVENTF_MOVE | MOUSEEVENTF_ABSOLUTE | MOUSEEVENTF_LEFTUP;//must have MOUSEEVENTF_MOVE

    SendInput(2, input, sizeof(INPUT));//do left click.
    //send to event queue of mouse -> just like physically click left mouse.
    //still receive physical mouse move/click. try by while(1) with sleep(2000) between each SendInput.

    input[0].mi.dx = cursor.x * XSCALEFACTOR;
    input[0].mi.dy = cursor.y * YSCALEFACTOR;
    input[0].mi.dwFlags = MOUSEEVENTF_MOVE | MOUSEEVENTF_ABSOLUTE;

//    SendInput(1, input, sizeof(INPUT));//move cursor to previous position
}

void SendRightClick(LONG dx, LONG dy)
{
    double x = dx * XSCALEFACTOR;
    double y = dy * YSCALEFACTOR;

    POINT cursor;
    GetCursorPos(&cursor);

    INPUT input[2];
    input[0].type = INPUT_MOUSE;
    input[0].mi.dx = x;
    input[0].mi.dy = y;
    input[0].mi.dwFlags = MOUSEEVENTF_MOVE | MOUSEEVENTF_ABSOLUTE | MOUSEEVENTF_RIGHTDOWN;//must have MOUSEEVENTF_MOVE

    input[1].type = INPUT_MOUSE;
    input[1].mi.dx = x;
    input[1].mi.dy = y;
    input[1].mi.dwFlags = MOUSEEVENTF_MOVE | MOUSEEVENTF_ABSOLUTE | MOUSEEVENTF_RIGHTUP;//must have MOUSEEVENTF_MOVE

    SendInput(2, input, sizeof(INPUT));//do right click.
    //send to event queue of mouse -> just like physically click left mouse.
    //still receive physical mouse move/click. try by while(1) with sleep(2000) between each SendInput.

    input[0].mi.dx = cursor.x * XSCALEFACTOR;
    input[0].mi.dy = cursor.y * YSCALEFACTOR;
    input[0].mi.dwFlags = MOUSEEVENTF_MOVE | MOUSEEVENTF_ABSOLUTE;

    SendInput(1, input, sizeof(INPUT));//move cursor to previous position
}

LRESULT SendMESSAGE_LMOUSECLICK(HWND hwnd, short relative_x, short relative_y)
{
    std::cout << "hwnd=" << hwnd << std::endl;
    std::cout << GetActiveWindow() << std::endl;
    SendMessageA(hwnd, WM_ACTIVATE, MAKEWPARAM(WA_ACTIVE, 0), (LPARAM)GetActiveWindow());
    std::cout << GetActiveWindow() << std::endl;
    return 0;
//    SendMessageA(hwnd, WM_MOUSEMOVE, 0, MAKELPARAM(relative_x, relative_y));
//    SendMessageA(hwnd, WM_LBUTTONDOWN, MK_LBUTTON, MAKELPARAM(relative_x, relative_y));
//    return SendMessageA(hwnd, WM_LBUTTONUP, MK_LBUTTON, MAKELPARAM(relative_x, relative_y));
}
