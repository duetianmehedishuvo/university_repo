#include <bits/stdc++.h>
using namespace std;

class SuperShop
{
public:
    SuperShop()
    {
        cout << "Welcome to Our  Shop\n\n";
        cout << "Please Select Product With Price Bellow Product Select Type Option: \n\n";
    }
};

class ChooseProduct
{
public:
    int x;
    int count = 0;
    int count1 = 0;
    double quantity[20];
    int productno[20];
    ChooseProduct()
    {

    label:
        for (int i = 0; i >= 0; i++)
        {
            cout << "Choose Product Type No: ";
            cin >> productno[count1];
            cout << productno[count1] << endl;
            if (productno[count1] <= 7)
            {
                cout << "Enter product quantity(in kg): ";
                cin >> quantity[count];
                break;
            }
            else if (productno[count1] <= 9)
            {
                cout << "Enter product quantity(in pcs): ";
                cin >> quantity[count];
                break;
            }
            else if (productno[count1] == 10)
            {
                cout << "Enter product quantity(Multiplier of 0.2): ";
                cin >> quantity[count];
                break;
            }
            else if (productno[count1] == 11)
            {
                cout << "Enter product quantity(in kg): ";
                cin >> quantity[count];
                break;
            }
            else
            {
                cout << "Enter valid product No.\n";
                continue;
            }
        }
        cout << "Want to buy another product or want to show bill?\n\n1. Buy another product\n2. show bill\n";
        cout << "Choose Option: ";
        cin >> x;
        if (x == 1)
        {
            count++;
            count1++;
            goto label;
        }
    }
};

class Calculation : public ChooseProduct
{
public:
    int ab = 0;

    void CalculatedProductPrice(int j, double k[], int l[], int price[])
    {
        for (int i = 0; i <= j; i++)
        {
            if (l[i] == 10)
            {
                k[i] = k[i] / 0.2;
            }
            if (l[i] == 11)
            {
                k[i] = k[i] / 0.5;
            }
            ab = ab + (price[l[i] - 1] * k[i]);
        }
        cout << "bill: " << ab << endl;
    }
    void discountCalculation(int count)
    {
        if (count >= 4 || ab >= 10000)
        {
            ab = ab - (ab * 0.1);
            cout << "You got % discount. You have to pay " << ab << " taka Only.\n";
        }
        else if (count >= 2 || ab >= 5000)
        {
            ab = ab - (ab * 0.05);
            cout << "You got % discount. You have to pay " << ab << " taka Only.\n";
        }
        else
        {
            ab = ab - (ab * 0.02);
            cout << "You got % discount. You have to pay " << ab << " taka Only.\n";
        }
    }
};


int main()
{
    int price[] = {50,150,700,200,150,140,1200,250,90,450,700};

    SuperShop a;
    Calculation c;
    c.CalculatedProductPrice(c.count, c.quantity, c.productno, price);
    c.discountCalculation(c.count);

    return 0;
}