#include <iostream>  
#include <string.h>  
#include <conio.h>  
#define max 100  
using namespace std;  

class Guest  
{  
public:  
    char guestName[100];  
    char guestAddress[100];  
    char guestPhone[12];  
    char checkInDate[20];  
    char checkOutDate[20];  
    float paymentAdvance;  
    int bookingID;  
};  

class Accommodation  
{  
public:  
    char roomType;  
    char comfortType;  
    char airConditioning;  
    int roomNumber;  
    int rent;  
    int status;  
  
    class Guest guestDetails;  
    class Accommodation addAccommodation(int);  
    void findAccommodation(int);  
    void removeAccommodation(int);  
    void displayAccommodation(Accommodation);  
};  
  
class Accommodation accommodations[max];  
int count = 0;  
  
Accommodation Accommodation::addAccommodation(int roomNo)  
{  
    class Accommodation accommodation;  
    accommodation.roomNumber = roomNo;  
    cout << "\nType AC/Non-AC (A/N) : ";  
    cin >> accommodation.airConditioning;  
    cout << "\nType Comfort (S/N) : ";  
    cin >> accommodation.roomType;  
    cout << "\nType Size (B/S) : ";  
    cin >> accommodation.comfortType;  
    cout << "\nDaily Rent : ";  
    cin >> accommodation.rent;  
    accommodation.status = 0;  
  
    cout << "\n Room Added Successfully!";  
    getch();  
    return accommodation;  
}  

void Accommodation::findAccommodation(int roomNo)  
{  
    int i, found = 0;  
    for (i = 0; i < count; i++)  
    {  
        if (accommodations[i].roomNumber == roomNo)  
        {  
            found = 1;  
            break;  
        }  
    }  
    if (found == 1)  
    {  
        cout << "Accommodation Details\n";  
        if (accommodations[i].status == 1)  
        {  
            cout << "\nAccommodation is Reserved";  
        }  
        else  
        {  
            cout << "\nAccommodation is available";  
        }  
        displayAccommodation(accommodations[i]);  
        getch();  
    }  
    else  
    {  
        cout << "\nAccommodation not found";  
        getch();  
    }  
}  

void Accommodation::displayAccommodation(Accommodation tempAccommodation)  
{  
    cout << "\nRoom Number: \t" << tempAccommodation.roomNumber;  
    cout << "\nType AC/Non-AC (A/N) " << tempAccommodation.airConditioning;  
    cout << "\nType Comfort (S/N) " << tempAccommodation.roomType;  
    cout << "\nType Size (B/S) " << tempAccommodation.comfortType;  
    cout << "\nRent: " << tempAccommodation.rent;  
}  

class HotelManagement : protected Accommodation  
{  
public:  
    void performCheckIn();  
    void showAvailableAccommodations();  
    void searchGuest(char *);  
    void performCheckOut(int);  
    void guestSummaryReport();  
};  

void HotelManagement::guestSummaryReport()  
{  
    if (count == 0)  
    {  
        cout << "\n No Guest in Hotel !!";  
    }  
    for (int i = 0; i < count; i++)  
    {  
        if (accommodations[i].status == 1)  
        {  
            cout << "\n Guest First Name : " << accommodations[i].guestDetails.guestName;  
            cout << "\n Room Number : " << accommodations[i].roomNumber;  
            cout << "\n Address (only city) : " << accommodations[i].guestDetails.guestAddress;  
            cout << "\n Phone : " << accommodations[i].guestDetails.guestPhone;  
            cout << "\n---------------------------------------";  
        }  
    }  
    getch();  
}  

void HotelManagement::performCheckIn()  
{  
    int i, found = 0, roomNo;  
    class Accommodation accommodation;  
    cout << "\nEnter Room number : ";  
    cin >> roomNo;  
    for (i = 0; i < count; i++)  
    {  
        if (accommodations[i].roomNumber == roomNo)  
        {  
            found = 1;  
            break;  
        }  
    }  
    if (found == 1)  
    {  
        if (accommodations[i].status == 1)  
        {  
            cout << "\nAccommodation is already Booked";  
            getch();  
            return;  
        }  
  
        cout << "\nEnter booking id: ";  
        cin >> accommodations[i].guestDetails.bookingID;  
  
        cout << "\nEnter Guest Name (First Name): ";  
        cin >> accommodations[i].guestDetails.guestName;  
  
        cout << "\nEnter Address (only city): ";  
        cin >> accommodations[i].guestDetails.guestAddress;  
  
        cout << "\nEnter Phone: ";  
        cin >> accommodations[i].guestDetails.guestPhone;  
  
        cout << "\nEnter From Date: ";  
        cin >> accommodations[i].guestDetails.checkInDate;  
  
        cout << "\nEnter to  Date: ";  
        cin >> accommodations[i].guestDetails.checkOutDate;  
  
        cout << "\nEnter Advance Payment: ";  
        cin >> accommodations[i].guestDetails.paymentAdvance;  
  
        accommodations[i].status = 1;  
  
        cout << "\n Guest Checked-in Successfully..";  
        getch();  
    }  
}  

void HotelManagement::showAvailableAccommodations()  
{  
    int i, found = 0;  
    for (i = 0; i < count; i++)  
    {  
        if (accommodations[i].status == 0)  
        {  
            displayAccommodation(accommodations[i]);  
            cout << "\n\nPress enter for next accommodation";  
            found = 1;  
            getch();  
        }  
    }  
    if (found == 0)  
    {  
        cout << "\nAll accommodations are reserved";  
        getch();  
    }  
}  

void HotelManagement::searchGuest(char *guestName)  
{  
    int i, found = 0;  
    for (i = 0; i < count; i++)  
    {  
        if (accommodations[i].status == 1 && stricmp(accommodations[i].guestDetails.guestName, guestName) == 0)  
        {  
            cout << "\nGuest Name: " << accommodations[i].guestDetails.guestName;  
            cout << "\nRoom Number: " << accommodations[i].roomNumber;  
            cout << "\n\nPress enter for next record";  
            found = 1;  
            getch();  
        }  
    }  
    if (found == 0)  
    {  
        cout << "\nPerson not found.";  
        getch();  
    }  
}  

void HotelManagement::performCheckOut(int roomNum)  
{  
    int i, found = 0, days, rno;  
    float billAmount = 0;  
    for (i = 0; i < count; i++)  
    {  
        if (accommodations[i].status == 1 && accommodations[i].roomNumber == roomNum)  
        {  
            found = 1;  
            break;  
        }  
    }  
    if (found == 1)  
    {  
        cout << "\nEnter Number of Days:\t";  
        cin >> days;  
        billAmount = days * accommodations[i].rent;  
  
        cout << "\n\t######## CheckOut Details ########\n";  
        cout << "\nGuest Name : " << accommodations[i].guestDetails.guestName;  
        cout << "\nRoom Number : " << accommodations[i].roomNumber;  
        cout << "\nAddress : " << accommodations[i].guestDetails.guestAddress;  
        cout << "\nPhone : " << accommodations[i].guestDetails.guestPhone;  
        cout << "\nTotal Amount Due : " << billAmount << " /";  
        cout << "\nAdvance Paid: " << accommodations[i].guestDetails.paymentAdvance << " /";  
        cout << "\n*** Total Payable: " << billAmount - accommodations[i].guestDetails.paymentAdvance << "/ only";  
  
        accommodations[i].status = 0;  
    }  
    getch();  
}  

void manageAccommodations()  
{  
    class Accommodation accommodation;  
    int opt, roomNo, i, flag = 0;  
    char ch;  
    do  
    {  
        system("cls");  
        cout << "\n### Manage Accommodations ###";  
        cout << "\n1. Add Accommodation";  
        cout << "\n2. Search Accommodation";  
        cout << "\n3. Back to Main Menu";  
        cout << "\n\nEnter Option: ";  
        cin >> opt;  
  
        switch (opt)  
        {  
        case 1:  
            cout << "\nEnter Room Number: ";  
            cin >> roomNo;  
            i = 0;  
            for (i = 0; i < count; i++)  
            {  
                if (accommodations[i].roomNumber == roomNo)  
                {  
                    flag = 1;  
                }  
            }  
            if (flag == 1)  
            {  
                cout << "\nRoom Number is Present.\nPlease enter unique Number";  
                flag = 0;  
                getch();  
            }  
            else  
            {  
                accommodations[count] = accommodation.addAccommodation(roomNo);  
                count++;  
            }  
            break;  
        case 2:  
            cout << "\nEnter room number: ";  
            cin >> roomNo;  
            accommodation.findAccommodation(roomNo);  
            break;  
        case 3:  
            // nothing to do  
            break;  
        default:  
            cout << "\nPlease Enter correct option";  
            break;  
        }  
    } while (opt != 3);  
}  

int main()  
{  
    class HotelManagement hm;  
    int i, j, opt, roomNo;  
    char ch;  
    char guestName[100];  
  
    system("cls");  
  
    do  
    {  
        system("cls");  
        cout << "######## Hotel Management #########\n";  
        cout << "\n1. Manage Accommodations";  
        cout << "\n2. Check-In Accommodation";  
        cout << "\n3. Available Accommodations";  
        cout << "\n4. Search Guest";  
        cout << "\n5. Check-Out Accommodation";  
        cout << "\n6. Guest Summary Report";  
        cout << "\n7. Exit";  
        cout << "\n\nEnter Option: ";  
        cin >> opt;  
        switch (opt)  
        {  
        case 1:  
            manageAccommodations();  
            break;  
        case 2:  
            if (count == 0)  
            {  
                cout << "\nAccommodations data is not available.\nPlease add the accommodations first.";  
                getch();  
            }  
            else  
                hm.performCheckIn();  
            break;  
        case 3:  
            if (count == 0)  
            {  
                cout << "\nAccommodations data is not available.\nPlease add the accommodations first.";  
                getch();  
            }  
            else  
                hm.showAvailableAccommodations();  
            break;  
        case 4:  
            if (count == 0)  
            {  
                cout << "\nAccommodations are not available.\nPlease add the accommodations first.";  
                getch();  
            }  
            else  
            {  
                cout << "Enter Guest Name: ";  
                cin >> guestName;  
                hm.searchGuest(guestName);  
            }  
            break;  
        case 5:  
            if (count == 0)  
            {  
                cout << "\nAccommodations are not available.\nPlease add the accommodations first.";  
                getch();  
            }  
            else  
            {  
                cout << "Enter Room Number : ";  
                cin >> roomNo;  
                hm.performCheckOut(roomNo);  
            }  
            break;  
        case 6:  
            hm.guestSummaryReport();  
            break;  
        case 7:  
            cout << "\nTHANK YOU! FOR USING SOFTWARE";  
            break;  
        default:  
            cout << "\nPlease Enter correct option";  
            break;  
        }  
    } while (opt != 7);  
  
    getch();  
}

