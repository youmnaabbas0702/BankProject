#include "clsLoginScreen.h"

int main()
{
    bool Locked = false;

    while(!Locked)
    {
       Locked = clsLoginScreen::ShowLoginScreen();
    }
}