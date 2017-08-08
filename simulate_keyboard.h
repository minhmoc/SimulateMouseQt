#ifndef SIMULATE_KEYBOARD_H
#define SIMULATE_KEYBOARD_H
#include <windows.h>

void SendKeyStroke(char key);
void SendKeyStrokes(char* keys, UINT nKeys);
#endif // SIMULATE_KEYBOARD_H
