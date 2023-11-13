#include <bits/stdc++.h> // Login and Registration System
using namespace std;
void SignUp();
bool isValidEmail(string);
bool isValidFirstName(string);
bool isValidLastName(string);
bool isValidPassword(string);
void verifyAccount();
void SignIn();

int main()
{
    // when the user opens the website
    cout << "Hey.." << endl;
    cout << "Welcome to our website!" << endl;
    cout << "Let's begin the journey.." << endl
         << endl;

    SignUp();

    return 0;
}

void SignUp() // This function asks the user if they are a new user or already have an account
{

    string newUser, username, password, firstName, lastName, email;

    cout << "New user?  \n(Note: if you are a new user, type Yes; otherwise, type No) \n";

    cin >> newUser; // must be "yes" if they are a new user or "no" if they are not a new user
    cin.ignore();

    if (newUser == "Yes" || newUser == "yes")
    {
        cout << "First name: "; // enter first name
        cin >> firstName;
        while (!isValidFirstName(firstName))
        {
            cout << "The first name is not valid, please try again: " << endl;
            cin >> firstName;
        }
        cout << endl
             << "Valid first name." << endl
             << endl;

        cout << "Last name: "; // enter last name
        cin >> lastName;
        while (!isValidLastName(lastName))
        {
            cout << "The last name is not valid, please try again: " << endl;
            cin >> lastName;
        }
        cout << endl
             << "Valid last name." << endl
             << endl;

        cout << "Email: "; // enter email
        cin >> email;
        while (!isValidEmail(email))
        {
            cout << "The email address is not valid, please try again: " << endl;
            cin >> email;
        }
        cout << endl
             << "Valid email address." << endl
             << endl;

        cout << "Password: \n(Note: your password must contain at least one digit, one special character, one uppercase letter, and one lowercase letter) \n"; // enter password
        cin >> password;
        while (!isValidPassword(password))
        {
            cout << "The password is not valid, please try again: " << endl;
            cin >> password;
        }
        cout << endl
             << "Valid password." << endl
             << endl;

        cout << "Registration completed! \n"
             << endl;
        verifyAccount();
    }
    else if (newUser == "No" || newUser == "no") // already have an account
    {
        string username, password;
        cout << endl
             << "     Log in       " << endl
             << endl;
        cout << "Enter your username: " << endl;
        getline(cin, username);

        cout << "Enter your password: " << endl;
        cin >> password;

        cout << endl
             << "Login success!" << endl;
    }
}

bool isValidFirstName(string firstName) // function to check the validity of the first name
{
    return (isupper(firstName[0]) != 0);
}

bool isValidLastName(string lastName) // function to check the validity of the last name
{
    return (isupper(lastName[0]) != 0);
}

bool isValidEmail(string email) // function to check the validity of the email
{
    int atPos = -1, dotPos = -1; // variables to store the position of '@' and '.'
    int atCounter = 0, dotCounter = 0; // check if there is more than one '@' or '.'
    if ((isalpha(email[0]) != 0))    // if the email address starts with a letter (valid)
    {
        for (int i = 0; i < email.length(); i++)
        {
            if (email[i] == '@') // If the character is '@'
            {
                atPos = i;
                ++atCounter;
            }
            else if (email[i] == '.') // If the character is '.'
            {
                dotPos = i;
                ++dotCounter;
            }
        }
        if (atPos == -1 || dotPos == -1) // If '@' or '.' is not present
            return false;

        if (atPos > dotPos) // If '.' is present before '@'
            return false;

        if (dotCounter > 1 || atCounter > 1)
            return false;

        return !(dotPos >= (email.length() - 1));
    }
    else if (isdigit(email[0]) != 0) // if the email address starts with a number (not valid)
    {
        return false;
    }
    else // if the email address starts with other symbols (not valid)
    {
        return false;
    }
}

bool isValidPassword(string password) // function to check the validity of the password
{
    int digit = 0, uppercase = 0, lowercase = 0, specialChar = 0; // counter to find if the password contains at least one digit, one special character, one uppercase letter, and one lowercase letter
    if (password.length() >= 8 && password.length() <= 15)
    {
        if (password.find(" ") == -1)
        {
            for (int i = 0; i < password.length(); i++)
            {
                if (isdigit(password[i]) != 0)
                {
                    ++digit;
                }
                else if (islower(password[i]) != 0)
                {
                    ++lowercase;
                }
                else if (isupper(password[i]) != 0)
                {
                    ++uppercase;
                }
                else if (password[i] == '@' || password[i] == '#' || password[i] == '_')
                {
                    ++specialChar;
                }
            }

            if (digit == 0 || uppercase == 0 || lowercase == 0 || specialChar == 0)
            {
                return false;
            }
            else
            {
                return true;
            }
        }
        else if (password.find(" ") != -1)
        {
            return false;
        }
    }

    cout << "Note: your password length must be between 8 and 15 characters." << endl;
    return false;
}

void verifyAccount() // verifying account
{
    int code;

    cout << "We have sent a verification code to your email to confirm your account." << endl
         << "Please check your email." << endl;

    cout << "Email message: Your verification code is  ";
    srand(time(0));

    for (int i = 0; i <= 3; i++)
    {
        cout << rand() % 10;
    }
    cout << "\n";

    cout << "Enter the verification code here: \n";
    cin >> code;

    cout << "Your account has been verified." << endl;
    SignIn();
}

void SignIn()
{
    string username, password;

    cin.ignore();
    cout << endl
         << "     Log in       " << endl
         << endl;
    cout << "Enter your username: " << endl;
    getline(cin, username);

    cout << "Enter your password: " << endl;
    cin >> password;

    cout << endl
         << "Login success!" << endl;
}

