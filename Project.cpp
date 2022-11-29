using namespace std;
#include <iostream>
#include <fstream>
#include <string.h>
#include <vector>
#include <algorithm>
#include <windows.h>
#include <conio.h>
#define underline "\033[4m"
#define bold "\e[1m"

class Shopping
{

private:
    char ItemID[15], StoreID[15], ItemName[15], file[15];
    int a;
    vector<int> v;
    string s;

protected:
    int ItemPrice;

public:
    void getPrices();
    void DisplayingAll();
    void writingtofile();
    void printing(char ItemID[15]);
    void EditProduct();
    void removeSpecific();
    void removeAll();
    void sequence()
    {
        ofstream out1("sequence.txt", fstream::app);
        out1 << StoreID << endl;
        out1.close();
    }
};
void Shopping ::writingtofile()
{
    sequence();
    strcpy(file, ItemID);
    strcat(file, ".txt");
    ofstream out(file);
    out << "Item ID =  " << ItemID << " Item Price = " << ItemPrice << " ItemName = " << ItemName;
    system("cls");
    cout << "\n\n\n\n\n";
    cout << "\t\t\t\t\t " << ItemName << " Successfully Added! ";
    Sleep(2000);
    system("cls");
    out.close();
}
void Shopping ::printing(char ItemID[15])
{
    strcpy(file, ItemID);
    strcat(file, ".txt");
    ifstream in(file);

    if (in)
    {
        while (!in.eof())
        {
            getline(in, s);
            cout << "\t\t\t\t\t\t";
            cout << s;
        }
        cout << endl;
        system("pause");
        system("read");

        in.close();
    }
    else
        cout << "\t\t\t\t\t\t\t ID/File does not exist! "<<endl;
    system("pause");
    system("read");
}

void Shopping ::getPrices()
{
    system("cls");
    cout << "\n\n\n\n\n";

    cout << "\t\t\t\tEnter the number of Items to be stored (not exceeding 100) - ";
    cin >> a;
    system("cls");
    for (int i = 0; i < a; i++)
    {
        cout << "\n\n\n\n\n";
        cout << "\t\t\t\t\t Enter the Item ID for product Number " << i + 1 << " - ";
        cin >> ItemID;
        cout << "\t\t\t\t\t Enter the Price of the product Number " << i + 1 << " - ";
        cin >> ItemPrice;
        cout << "\t\t\t\t\t Enter the Name of the Product Number " << i + 1 << " - ";
        cin >> ItemName;
        strcpy(StoreID, ItemID);
        writingtofile();
    }
}
void Shopping ::EditProduct()
{
    cout << "How many Products do you want to edit? ";
    cin >> a;

    for (int i = 0; i < a; i++)
    {
        cout << "Enter the Item ID for product Number." << i + 1 << " ";
        cin >> ItemID;
        cout << "Enter the Price of the product Number." << i + 1 << " ";
        cin >> ItemPrice;
        cout << "Enter the Name of the Product Number." << i + 1 << " ";
        cin >> ItemName;
        strcpy(StoreID, ItemID);
        writingtofile();
    }
}
void Shopping ::DisplayingAll()
{
    system("cls");
    char file[15], ch;
    string s;
    int i = 0;
    ifstream in2("sequence.txt");
    ofstream in3("sequence2.txt");
    while (!in2.eof())
    {
        getline(in2, s);
        if (s.length() != 0)
        {
            i = stoi(s);
            v.push_back(i);
        }
    }
    sort(v.begin(), v.end());
    auto last = unique(v.begin(), v.end());
    v.erase(last, v.end());
    for (i = 0; i < v.size(); i++)
    {
        in3 << v[i] << endl;
    }
    ifstream in4("sequence2.txt");
    while (!in4.eof())
    {
        getline(in4, s);
        strcpy(ItemID, s.c_str());
        strcpy(file, ItemID); /*Did not call printing() here because of sequence endl printing a new line*/
        strcat(file, ".txt"); /*No else condition solves the issue*/
        ifstream in(file);

        if (in)
        {
            while (!in.eof())
            {
                getline(in, s);
                cout << "\t\t\t\t\t\t";
                cout << s;
            }
            cout << endl;
            in.close();
        }
    }
    system("pause");
    system("read");
}

void Shopping::removeSpecific()
{
    cout << "\n\n\n\n\n";
    cout << "\t\t\t\t\t\t";
    cout << "How many products do you want to remove ? ";
    cin >> a;
    for (int i = 0; i < a; i++)
    {
        system("cls");
        cout << "\n\n\n\n\n";
        cout << "\t\t\t\t\t\t";
        cout << "Enter the ItemID of the Product to be removed ";
        cin >> ItemID;
        strcpy(file, ItemID);
        strcat(file, ".txt");
        ofstream in(file);
        if (in)
        {
            in.open(file, ios::trunc);
            cout << "\t\t\t\t\t\t Data cleared successfully! " << endl;
            Sleep(1000);
            in.close();
        }
        else
            cout << "File/ID not found! " << endl;
    }
    system("pause");
    system("read");
}
void Shopping::removeAll()
{
    ifstream in("sequence2.txt");
    while (!in.eof())
    {
        getline(in, s);
        strcpy(file, s.c_str());
        strcat(file, ".txt");
        ofstream out(file);
        out.open(file, ios::trunc);
    }
}
int main()
{
    bool t = true;
    while (t == 1)
    {
        system("cls");
        Shopping shop1;
        int ch, ch1, ch2, ch3;
        char ItemID[15];
        cout << "\n\n\n\n\n";
        cout << underline << bold << "\t\t\t\t\t\t SHOP MANAGEMENT SOFTWARE "
             << "\033[0m" << endl;
        cout << bold << "\t\t\t\t\t\t 1. Formulate Products " << endl;
        cout << bold << "\t\t\t\t\t\t 2. Display Products " << endl;
        cout << bold << "\t\t\t\t\t\t 3. Delete Products " << endl;
        cin >> ch;

        switch (ch) // first menu
        {
        case 1: // Formulate Products [Done]
            ch == 1;
            system("cls");
            cout << "\n\n\n\n\n";
            cout << "\t\t\t\t\t\t 1. Add multiple Products " << endl;
            cout << "\t\t\t\t\t\t 2. Edit multiple Products " << endl;
            cout << "\t\t\t\t\t\t 3. Main Menu " << endl;
            cin >> ch1;
            switch (ch1) // Formulate products, sub options [Done]
            {
            case 1:
                ch1 == 1;
                shop1.getPrices();
                main();
            case 2:
                ch1 == 2;
                shop1.EditProduct();
                break;
            case 3:
                ch1 == 3;
                main();
                break;
            default:
                system("cls");
                cout << ch1 << " is an Invalid Option, Going back to the Main Menu! 2s ";
                Sleep(1000);
                system("cls");
                cout << ch1 << " is an Invalid Option, Going back to the Main Menu! 1s ";
                Sleep(1000);
                main();
            }
            break;
        case 2: // Display Products [Done]
            ch == 2;
            system("cls");
            cout << "\n\n\n\n\n";
            cout << "\t\t\t\t\t\t 1. Display Item details with Item ID " << endl;
            cout << "\t\t\t\t\t\t 2. Display All Items " << endl;
            cout << "\t\t\t\t\t\t 3. Main Menu " << endl;
            cin >> ch2;
            switch (ch2) // Display Products, sub options [Done]
            {
            case 1:
                ch2 == 1;
                system("cls");
                cout << "\n\n\n\n\n";
                cout << "\t\t\t\t\t\t";
                cout << "Enter the Item ID to get the details ";
                cin >> ItemID;
                shop1.printing(ItemID);
                break;
            case 2:
                ch2 == 2;
                shop1.DisplayingAll();
                break;
            case 3:
                ch2 == 3;
                main();
                break;
            default:
                system("cls");
                cout << "Invalid Option, Going back to the Main Menu! 2s ";
                Sleep(1000);
                system("cls");
                cout << "Invalid Option, Going back to the Main Menu! 1s ";
                Sleep(1000);
                main();
            }
            break;
        case 3: // Delete Products
            ch == 3;
            system("cls");
            cout << "\n\n\n\n\n";
            cout << "\t\t\t\t\t\t 1. Delete multiple Products " << endl;
            cout << "\t\t\t\t\t\t 2. Delete Everything " << endl;
            cout << "\t\t\t\t\t\t 3. Main Menu " << endl;
            cin >> ch3;
            switch (ch3)
            {
            case 1:
                ch3 == 1;
                shop1.removeSpecific();

            case 2:
                ch3 == 2;
                shop1.DisplayingAll();
                system("cls");
                shop1.removeAll();
            case 3:
                ch3 == 3;
                main();
            default:
                system("cls");
                cout << "Invalid Option, Going back to the Main Menu! 2s ";
                Sleep(1000);
                system("cls");
                cout << "Invalid Option, Going back to the Main Menu! 1s ";
                Sleep(1000);
                main();
            }
        default:
            system("cls");
            cout << "Invalid Option, Going back to the Main Menu! 3s ";
            Sleep(1000);
            system("cls");
            cout << "Invalid Option, Going back to the Main Menu! 2s ";
            Sleep(1000);
            system("cls");
            cout << "Invalid Option, Going back to the Main Menu! 1s ";
            Sleep(1000);
            main();
        }
    }
}