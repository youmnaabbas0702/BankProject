#include "clsLoginScreen.h"
#include "clsCurrency.h"

int main()
{
    bool Locked = false;

    while(!Locked)
    {
       Locked = clsLoginScreen::ShowLoginScreen();
    }
}