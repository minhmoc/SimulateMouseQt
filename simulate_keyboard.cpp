#include "simulate_keyboard.h"

#include <iostream>

void SendKeyStroke(char key)
{
    HKL hkl = LoadKeyboardLayout(L"00000409", KLF_SUBSTITUTE_OK);
    SHORT vk = VkKeyScanExA(key, hkl);//A and a have same lower byte. But A have higher byte set to 1 to indicate shift is pressed.
    std::cout << std::hex << vk << std::endl;
//    INPUT input;
}
