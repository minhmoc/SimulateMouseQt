/*Author: minhhn4
 * Date: 07/08/2017
 */
#ifndef SIMULATE_MOUSE_H
#define SIMULATE_MOUSE_H
#include <windows.h>

void SendLeftClick(LONG dx, LONG dy);
void SendRightClick(LONG dx, LONG dy);
void SendMouseMove(LONG dx, LONG dy);

LRESULT SendMESSAGE_LMOUSECLICK(HWND hwnd, short relative_x, short relative_y);//use short instead of WORD due to ability to receive negative coordinate in system with multi monitor

#endif // SIMULATE_MOUSE_H
