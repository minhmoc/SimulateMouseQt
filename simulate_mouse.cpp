#include "simulate_mouse.h"

void SendLeftClick(LONG dx, LONG dy)
{
    const double XSCALEFACTOR = 65535 / (GetSystemMetrics(SM_CXSCREEN) - 1);
    const double YSCALEFACTOR = 65535 / (GetSystemMetrics(SM_CYSCREEN) - 1);

    double x = dx * XSCALEFACTOR;
    double y = dy * YSCALEFACTOR;

    POINT cursor;
    GetCursorPos(&cursor);

    INPUT input;
    input.type = INPUT_MOUSE;
    input.mi.dx = x;
    input.mi.dy = y;
    input.mi.dwFlags = MOUSEEVENTF_MOVE | MOUSEEVENTF_ABSOLUTE | MOUSEEVENTF_LEFTDOWN | MOUSEEVENTF_LEFTUP;//must have MOUSEEVENTF_MOVE

    SendInput(1, &input, sizeof(INPUT));//do left click.
    //send to event queue of mouse -> just like physically click left mouse.
    //still receive physical mouse move/click. try by while(1) with sleep(2000) between each SendInput.

    input.mi.dx = cursor.x * XSCALEFACTOR;
    input.mi.dy = cursor.y * YSCALEFACTOR;
    input.mi.dwFlags = MOUSEEVENTF_MOVE | MOUSEEVENTF_ABSOLUTE;

    SendInput(1, &input, sizeof(INPUT));//move cursor to previous position
}

void SendRightClick(LONG dx, LONG dy)
{
    const double XSCALEFACTOR = 65535 / (GetSystemMetrics(SM_CXSCREEN) - 1);
    const double YSCALEFACTOR = 65535 / (GetSystemMetrics(SM_CYSCREEN) - 1);

    double x = dx * XSCALEFACTOR;
    double y = dy * YSCALEFACTOR;

    POINT cursor;
    GetCursorPos(&cursor);

    INPUT input;
    input.type = INPUT_MOUSE;
    input.mi.dx = x;
    input.mi.dy = y;
    input.mi.dwFlags = MOUSEEVENTF_MOVE | MOUSEEVENTF_ABSOLUTE | MOUSEEVENTF_RIGHTDOWN | MOUSEEVENTF_RIGHTUP;//must have MOUSEEVENTF_MOVE

    SendInput(1, &input, sizeof(INPUT));//do right click.
    //send to event queue of mouse -> just like physically click left mouse.
    //still receive physical mouse move/click. try by while(1) with sleep(2000) between each SendInput.

    input.mi.dx = cursor.x * XSCALEFACTOR;
    input.mi.dy = cursor.y * YSCALEFACTOR;
    input.mi.dwFlags = MOUSEEVENTF_MOVE | MOUSEEVENTF_ABSOLUTE;

    SendInput(1, &input, sizeof(INPUT));//move cursor to previous position
}
