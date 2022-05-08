#include <iostream>
#include <string>

using namespace std;

string CitireText()
{
    string input;
    cout << "Input: " << endl;
    cin >> input;

    for (int i = 0; i < input.length(); i++)
    {
        input[i] = toupper(input[i]);
    }

    return input;
}

string CriptareCaesar(string input)
{
    int offset = -1;
    string output = "";
    string alfabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

    while (offset < 0)
    {
        cout << "Introduceti valoarea pentru offset (pozitiv): ";
        cin >> offset;
    }

    for (int i = 0; i < input.length(); i++)
    {
        int index = 0;
        index = alfabet.find(input[i]);
        index += offset;

        while (index >= alfabet.length())
        {
            index -= alfabet.length();
        }
        output += alfabet[index];
    }

    return output;
}

string CriptarePolialfabetic(string input)
{
    string cheie;
    string output = "";
    string alfabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

    cout << "Introduceti cheia." << endl;
    cheie = CitireText();

    if (cheie.length() < input.length())
    {
        int counter = input.length() - cheie.length();
        for (int i = 0; i < counter; i++)
        {
            cheie += cheie[i];
        }
    }

    for (int i = 0; i < input.length(); i++)
    {
        int index;
        index = alfabet.find(input[i]) + alfabet.find(cheie[i]);

        while (index >= alfabet.length())
        {
            index -= alfabet.length();
        }

        output += alfabet[index];
    }

    return output;
}

int main()
{
     string userInput;
     cout << "Introduceti cuvantul care trebuie criptat." << endl;
     userInput = CitireText();

     int userOption = 0;
     while (userOption < 1 || userOption >5){
         cout << "Optiuni: " << endl;
         cout << "1. Metoda transpozitiei" << endl;
         cout << "2. Metoda Caesar" << endl;
         cout << "3. Metoda substitutiei" << endl;
         cout << "4. Metoda polialfabetica (Vigenere)" << endl;
         cout << "5. Iesire" << endl;
         cout << "Alegeti optiune: "<< endl;
         cin >> userOption;

         switch(userOption){
             case 1:{
                 cout << "1. Metoda transpozitiei" << endl;

                 cout << "Cuvantul criptat: " << userInput << endl;
                 userOption = 0;
             } break;

             case 2: {
                 cout << "2. Metoda Caesar" << endl;
                 userInput = CriptareCaesar(userInput);
                 cout << "Cuvantul criptat: " << userInput << endl;
                 userOption = 0;
             } break;

             case 3: {
                 cout << "3. Metoda substitutiei" << endl;

                 cout << "Cuvantul criptat: " << userInput << endl;
                 userOption = 0;
             } break;

             case 4: {
                 cout << "4. Metoda polialfabetica (Vigenere)" << endl;
                 userInput = CriptarePolialfabetic(userInput);
                 cout << "Cuvantul criptat: " << userInput << endl;
                 userOption = 0;
             } break;

             case 5: {
                 cout << "5. Iesire" << endl;
                 cout << "Cuvant final: " << userInput << endl;
                 userOption = 5;
             } break;
         }
     }

//    DEBUG MODE ---------------------------------------
//    cout << "Introduceti input pentru Caesar." << endl;
//    string inputCaesar = CitireText();
//    string outputCaesar = CriptareCaesar(inputCaesar);
//    cout << "Mesaj criptat (Caesar):" << endl;
//    cout << outputCaesar << endl;
//
//    cout << "Introduceti input pentru Polialfabetic." << endl;
//    string inputPolialfabetic = CitireText();
//    string outputPolialfabetic = CriptarePolialfabetic(inputPolialfabetic);
//    cout << "Mesaj criptat (Polialfabetic):" << endl;
//    cout << outputPolialfabetic << endl;
//    ---------------------------------------------------
    return 0;
}