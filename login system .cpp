#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// Structure to store user data
struct User
{
    string username;
    string password;
};

// Function to check if username already exists
bool usernameExists(string username)
{
    ifstream file("credentials.txt");

    string user, pass;

    while (file >> user >> pass)
    {
        if (user == username)
        {
            file.close();
            return true;
        }
    }

    file.close();
    return false;
}

// Function for user registration
void registerUser()
{
    User u;
    string repeatPassword;

    cout << "Enter Username: ";
    cin >> u.username;

    // Check duplicate username
    if (usernameExists(u.username))
    {
        cout << "Username is already used!" << endl;
        return;
    }

    cout << "Enter Password: ";
    cin >> u.password;

    cout << "Repeat Password: ";
    cin >> repeatPassword;

    // Check password match
    if (u.password != repeatPassword)
    {
        cout << "Passwords do not match!" << endl;
        return;
    }

    // Save to file
    ofstream file("credentials.txt", ios::app);

    file << u.username << " " << u.password << endl;

    file.close();

    cout << "You have successfully signed up." << endl;
}

// Function for login
void loginUser()
{
    string username, password;
    string user, pass;

    cout << "Enter Username: ";
    cin >> username;

    cout << "Enter Password: ";
    cin >> password;

    ifstream file("credentials.txt");

    bool found = false;

    while (file >> user >> pass)
    {
        if (user == username && pass == password)
        {
            found = true;
            break;
        }
    }

    file.close();

    if (found)
    {
        cout << "Successfully logged in." << endl;
    }
    else
    {
        cout << "Invalid username or password!" << endl;
    }
}

// Main function
int main()
{
    int choice;
    int repeat;

    do
    {
        cout << "Register(1) or login(2)?: ";
        cin >> choice;

        if (choice == 1)
        {
            registerUser();
        }
        else if (choice == 2)
        {
            loginUser();
        }
        else
        {
            cout << "Invalid choice!" << endl;
        }

        cout << "Repeat(1-yes/2-no)?: ";
        cin >> repeat;

    } while (repeat == 1);

    cout << "Program ended." << endl;

    return 0;
}