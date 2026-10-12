
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

string promptForPassword()
{
    string password;
    cout << "Enter your password: ";
    cin >> password;
    return password;
}

void displayFile(string filename)
{
    ifstream file(filename);
    string line;

    if (file.is_open()) {
        cout << " Document Contents" << endl;

        while (getline(file, line))
        {
            cout << line << endl;
        }

        file.close();
    }
    else
    {
        cout << "Error: Cannot open the file." << endl;
    }
}

int main()
{
    string correctPassword = "1234231";
    string passwords[3];

    string password = promptForPassword();

    if (password != correctPassword) {
        cout << "Incorrect password!" << endl;
        return 0;
    }

    string choice;
    cout << "Do you want to view the document? (yes/no): ";
    cin >> choice;

    if (choice != "yes" && choice == "no")
    {
        cout << "BYE BYE" << endl;
        return 0;
    }
	system("pause");
    system("cls");
    for (int i = 0; i < 3; i++)
    {
        cout << "Enter the password to view the document: ";
        cin >> passwords[i];

        if (passwords[i] == correctPassword)
        {
            cout << "Correct password!" << endl;
            displayFile("document.txt");
            return 0;
        }
        else
        {
            cout << "Incorrect password." << endl;
            cout << "Attempts remaining: " << 2 - i << endl;
        }
    }

    cout << "You entered the wrong password 3 times." << endl;
    cout << "U ARE LOCK OUTTTTTTT" << endl;

    return 0;
}
