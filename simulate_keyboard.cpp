#include "simulate_keyboard.h"

#include <iostream>

const INPUT INPUT_leftshift_pressed   = {INPUT_KEYBOARD, {.ki = {VK_LSHIFT,0,0,0,0}}};
const INPUT INPUT_leftshift_released  = {INPUT_KEYBOARD, {.ki = {VK_LSHIFT, 0, KEYEVENTF_KEYUP, 0, 0}}};
const INPUT INPUT_leftctrl_pressed    = {INPUT_KEYBOARD, {.ki = {VK_LCONTROL, 0,0,0,0}}};
const INPUT INPUT_leftctrl_released   = {INPUT_KEYBOARD, {.ki = {VK_LCONTROL, 0, KEYEVENTF_KEYUP, 0, 0}}};
const INPUT INPUT_leftalt_pressed     = {INPUT_KEYBOARD, {.ki = {VK_LMENU, 0,0,0,0}}};
const INPUT INPUT_leftalt_released    = {INPUT_KEYBOARD, {.ki = {VK_LMENU, 0, KEYEVENTF_KEYUP, 0, 0}}};
const HKL hkl = LoadKeyboardLayout(L"00000409", KLF_SUBSTITUTE_OK);

void SendKeyStroke(char key)
{
    SHORT vk = VkKeyScanExA(key, hkl);//A and a have same lower byte. But A have higher byte set to 1 to indicate shift is pressed.
    //    std::cout << std::hex << "Key virtual code for " << key << " is " << vk << std::endl;

    INPUT INPUT_vk_pressed;
    INPUT_vk_pressed.type = INPUT_KEYBOARD;
    INPUT_vk_pressed.ki.wVk = vk;
    INPUT_vk_pressed.ki.dwFlags = 0;//pressed

    INPUT INPUT_vk_release;
    INPUT_vk_release.type = INPUT_KEYBOARD;
    INPUT_vk_release.ki.wVk = vk;
    INPUT_vk_release.ki.dwFlags = KEYEVENTF_KEYUP;

    bool leftshift_pressed = vk &0x0100;
    bool leftctrl_pressed  = vk &0x0200;
    bool leftalt_pressed   = vk &0x0400;

    INPUT input[4];
    input[1] = INPUT_vk_pressed;
    input[2] = INPUT_vk_release;

    if(leftshift_pressed) {
        input[0] = INPUT_leftshift_pressed;
        input[3] = INPUT_leftshift_released;
        SendInput(4,input,sizeof(INPUT));
    } else if(leftctrl_pressed) {
        input[0] = INPUT_leftctrl_pressed;
        input[3] = INPUT_leftctrl_released;
        SendInput(4,input,sizeof(INPUT));
    } else if(leftalt_pressed) {
        input[0] = INPUT_leftalt_pressed;
        input[3] = INPUT_leftalt_released;
        SendInput(4,input,sizeof(INPUT));
    } else {
        SendInput(2,input+1,sizeof(INPUT));
    }
}

void SendKeyStrokes(char *keys, UINT nKeys)
{
    for(UINT i = 0; i < nKeys; i++) {
        SendKeyStroke(keys[i]);
    }
}
