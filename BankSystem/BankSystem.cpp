#include "clsLoginScreen.h"
#include "clsCurrency.h"

void _PrintCurrency(clsCurrency Currency)
{
    cout << "\nCurrency Card:\n";
    cout << "_____________________________\n";
    cout << "\nCountry    : " << Currency.Country();
    cout << "\nCode       : " << Currency.CurrencyCode();
    cout << "\nName       : " << Currency.CurrencyName();
    cout << "\nRate(1$) = : " << Currency.Rate();
    cout << "\n_____________________________\n";

}

int main()
{
    bool Locked = false;

    while(!Locked)
    {
       Locked = clsLoginScreen::ShowLoginScreen();
    }

   /* clsCurrency C1 = C1.Find("Egp");

    if (C1.IsEmpty())
    {
        cout << "\nCurrency is not found.\n";
    }

    else {
        _PrintCurrency(C1);
    }
    
    clsCurrency C2 = C2.Find("china");

    if (C2.IsEmpty())
    {
        cout << "\nCurrency is not found.\n";
    }

    else {
        _PrintCurrency(C2);
    }

    cout << "Currency1 after updating Rate:\n";
    C1.UpdateRate(50.63);
    _PrintCurrency(C1);*/

}