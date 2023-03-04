#include "TMS.h"

char* login::Id() { return id; }
char* login::Pass() { return pass; }
char* login::Password() { return password; }
void login::getid()
{
    cout << "\nEnter your id:";
    std::cin >> id;
    std::cout << "Enter the Password: ";
    std::cin >> password;
    std::cout << "\n";
    strcpy(pass, password);
}
void login::displayid()
{
    std::cout << "\n|" << "User ID:" << "\t" << "|" << "Password\n";
    std::cout << "|" << id << "\t\t" << "|" << pass << "\n\n";
}

int Detail::datef() const { return date; }
int Detail::monthf() const { return month; }
int Detail::TrainNumber() { return trainNumber; }
int Detail::ReqSeats_FirstClass() { return reqSeats_FirstClass; }
int Detail::FirstClassSeatFare() { return firstClassSeatFare; }
int Detail::ReqSeats_SecondClass() { return reqSeats_SecondClass; }
int Detail::SecondClassSeatFare() { return secondClassSeatFare; }
char* Detail::TrainName() { return trainName; }
char* Detail::BoardingPoint() { return boardingPoint; }
char* Detail::Destination() { return destination; }
void Detail::setdate()
{
    std::cout << "Date of travel\n";
    std::cout << "Day: ";
    std::cin >> date;
    std::cout << "Month: ";
    std::cin >> month;
    std::cout << "Year: ";
    std::cin >> year;
}
void Detail::setSeats()
{
    std::cout << "No of seats in first class & fare per ticket: ";
    std::cin >> reqSeats_FirstClass >> firstClassSeatFare;
    std::cout << "No of seats in second class & fare per ticket: ";
    std::cin >> reqSeats_SecondClass >> secondClassSeatFare;
}
void Detail::trainSpec()
{
    std::cout << "Train no: ";
    std::cin >> trainNumber;
    std::cout << "Train Name: ";
    std::cin >> trainName;
    std::cout << "Boarding point: ";
    std::cin >> boardingPoint;
    std::cout << "Destination pt: ";
    std::cin >> destination;
}
void Detail::getDetail()
{
    std::cout << "\n--Add New details--\n";
    trainSpec();
    setSeats();
    setdate();
}
void Detail::displaydetail()
{
    std::cout << "\n|Train No." << "\t" << "|Train Name" << "\t" << "|Boarding pt." << "\t" << "|Destination pt." << "\t";
    std::cout << "|F-Class" << "\t" << "|F-Class Fare" << "\t" << "|S-Class" << "\t" << "|S-Class Fare" << "\t";
    std::cout << "|Date" << "-" << "Month" << "-" << "Year" << "\n";
    std::cout << "|" << trainNumber << "\t\t" << "|" << trainName << "\t\t" << "|" << boardingPoint << "\t\t" << "|" << destination << "\t\t\t";
    std::cout << "|" << ReqSeats_FirstClass() << "\t\t" << "|" << FirstClassSeatFare() << "\t\t" << "|" << ReqSeats_SecondClass() << "\t\t" << "|" << SecondClassSeatFare() << "\t\t";
    std::cout << "|" << date << "-" << month << "-" << year << "\n";
}


void reservation::getReserveDetails()
{
    cout << "Enter the details as follows\n";
    trainSpec();
    cout << "No of seats required:";
    cin >> SeatsRequired;
    for (int i = 0; i < SeatsRequired; i++)
    {
        cout << "Passenger name:";
        std::cin >> passengerName[i];
        cout << "Passenger age:";
        std::cin >> age[i];
    }
    cout << "Enter the class f-first class s-second class:";
    std::cin >> travellingClass;
    cout << "Date of travel:";
    setdate();
    cout << "Enter the concession category\n";
    cout << "1.Military\n2.Senior citizen\n";
    cout << "3.Children below 5 yrs\n4.None\n";
    std::cin >> concession;
    cout << "…………END OF GETTING DETAILS…………\n";
}
void reservation::displayReserveDetails()
{
    cout << "Pnr no: " << pnr;
    cout << "\nTrain no: " << TrainNumber();
    cout << "\nTrain name: " << TrainName();
    cout << "\nBoarding point: " << BoardingPoint();
    cout << "\nDestination pt: " << Destination();
    cout << "\nNo of seats reserved: " << SeatsRequired;
    for (int i = 0; i < SeatsRequired; i++)
    {
        cout << "\nPassenger name: "; puts(passengerName[i]);
        cout << "Passenger age: " << age[i];
    }
    cout << "\nYour class: "; puts(travellingClass);
    cout << "\nDate of reservation: " << endl;
    setdate();
    cout << "\nYour concession category: " << concession;
    cout << "\nYou must pay: " << amc << endl;
    cout << "*****\n";
}
int reservation::Pnr() { return pnr; }
void reservation::getPnr()
{
    std::cout << "Pnr no:";
    std::cin >> pnr;
}

void Cancellation::getCancelDetails()
{
    std::cout << "Enter the details as follows\n";
    std::cout << "Pnr no:";
    std::cin >> pnr;
    std::cout << "Date of cancellation:";
    setdate();
    std::cout << "………..END OF GETTING DETAILS………..\n";
}
void Cancellation::displayCancelDetails()
{
    std::cout << "…………………………………….\n";
    std::cout << "…………………………………….\n";
    std::cout << "Pnr no:" << pnr;
    std::cout << "\nTrain no:" << TrainNumber();
    std::cout << "\nTrain name:";
    std::cout << TrainName();
    std::cout << "Boarding point:";
    std::cout << BoardingPoint();
    std::cout << "Destination pt:";
    std::cout << Destination();
    cout << "\nYour class:";
    std::cout << travellingClass;
    cout << "no of seats to be cancelled:" << SeatsRequired;
    for (int i = 0; i < SeatsRequired; i++)
    {
        std::cout << "Passenger name:";
        std::cout << passengerName[i];
        std::cout << "passenger age:" << age[i];
    }
    std::cout << "\nDate of cancellation:" << endl;
    setdate();
    std::cout << "\nYou can collect:" << moneyReturn << "rs" << endl;
    std::cout << "*****\n";
    std::cout << "………END OF CANCELLATION………….\n";
    std::cout << "*****\n";
}


void train::database()
{
    char password[10];
    char pass[10] = "admin";
    std::cout << "\nEnter the Admin Password: ";
    std::cin >> password;
    Detail details;
    fstream f;
    int choice;
    if (strcmp(pass, password) != 0)
    {
        std::cout << "Enter the password correctly \n";
        std::cout << "You are not permitted to login this mode\n";
    }
    if (strcmp(pass, password) == 0)
    {
        char moreRecord;
        do
        {
            std::cout << "\n --- ADMINISTRATOR MENU --- \n";
            std::cout << "1. Create detail Database \n";
            std::cout << "2. Add details \n";
            std::cout << "3. Display details \n";
            std::cout << "4. User Management \n";
            std::cout << "5. Diplay Passenger details \n";
            std::cout << "6. Return to Main Menu \n";
            std::cout << "Enter your choice : ";
            std::cin >> choice;
            switch (choice)
            {
            case 1:
                f.open("t.txt", ios::out | ios::binary);
                do
                {
                    details.getDetail();
                    f.write((char*)&details, sizeof(details));
                    cout << "\nDo you want to add one more record?\n";
                    cout << "y-for Yes\nn-for No\n";
                    cin >> moreRecord;
                } while (moreRecord == 'y');
                f.close();
                break;
            case 2:
                f.open("t.txt", ios::in | ios::out | ios::binary | ios::app);
                details.getDetail();
                f.write((char*)&details, sizeof(details));
                f.close();
                break;
            case 3:
                f.open("t.txt", ios::in | ios::out | ios::binary | ios::app);
                f.seekg(0);
                while (f.read((char*)&details, sizeof(details)))
                {
                    details.displaydetail();
                }
                f.close();
                break;
            case 4:
                manage();
                break;
            case 5:
                displaypassdetail();
                break;
            }
        } while (choice <= 5);
    }
}
void train::reserve()
{
    int choice;
    do
    {
        std::cout << "1.Reserve\n2.Return to the main menu\n";
        std::cout << "Enter your choice:";
        std::cin >> choice;
        std::cout << endl;
        switch (choice)
        {
        case 1:
            res();
            break;
        }
    } while (choice == 1);
}
void train::res()
{
    Detail details;
    reservation reservation1;
    fstream f1, f2;
    time_t t;
    f1.open("t.txt", ios::in | ios::out | ios::binary);
    f2.open("p.txt", ios::in | ios::out | ios::binary | ios::app);
    //int ch;
    int ch;
    reservation1.getReserveDetails();
    while (f1.read((char*)&details, sizeof(details)))
    {
        if (details.TrainNumber() == reservation1.TrainNumber())
        {
            if (strcmp(reservation1.travellingClass, f) == 0)
            {
                if (details.ReqSeats_FirstClass() >= reservation1.SeatsRequired)
                {
                    amt = details.FirstClassSeatFare();
                    addr = f1.tellg();
                    ad = sizeof(details.ReqSeats_FirstClass());
                    f1.seekp(addr - (7 * ad));
                    details.reqSeats_FirstClass = details.ReqSeats_FirstClass() - reservation1.SeatsRequired;
                    f1.write((char*)&details.reqSeats_FirstClass, sizeof(details.ReqSeats_FirstClass()));
                    if (reservation1.concession == 1)
                    {
                        cout << "Concession category:MILITARY PERSONNEL\n";
                        reservation1.amc = reservation1.SeatsRequired * ((amt * 50) / 100);
                    }
                    else if (reservation1.concession == 2)
                    {
                        cout << "Concession category:SENIOR CITIZEN\n";
                        reservation1.amc = reservation1.SeatsRequired * ((amt * 60) / 100);
                    }
                    else if (reservation1.concession == 3)
                    {
                        cout << "Concession category:CHILDERN BELOW FIVE\n";
                        reservation1.amc = 0.0;
                    }
                    else if (reservation1.concession == 4)
                    {
                        cout << "You cannot get any concession\n";
                        reservation1.amc = reservation1.SeatsRequired * amt;
                    }
                    srand((unsigned)time(&t));
                    reservation1.pnr = rand();
                    f2.write((char*)&reservation1, sizeof(reservation1));
                    reservation1.displayReserveDetails();
                    cout << "\n-----Your ticket is reserved-----\n";
                }
                else
                {
                    cout << "**Sorry req seats not available**\n";
                }
            }
            else if (strcmp(reservation1.travellingClass, s) == 0)
            {
                if (details.ReqSeats_SecondClass() >= reservation1.SeatsRequired)
                {
                    amt = details.SecondClassSeatFare();
                    addr = f1.tellg();
                    ad = sizeof(details.ReqSeats_SecondClass());
                    f1.seekp(addr - (5 * ad));
                    details.reqSeats_SecondClass = details.ReqSeats_SecondClass() - reservation1.SeatsRequired;
                    f1.write((char*)&details.reqSeats_SecondClass, sizeof(details.ReqSeats_SecondClass()));
                    if (reservation1.concession == 1)
                    {
                        cout << "Concession category:MILITARY PRESONNEL\n";
                        reservation1.amc = reservation1.SeatsRequired * ((amt * 50) / 100);
                    }
                    else if (reservation1.concession == 2)
                    {
                        cout << "Concession category:SENIOR CITIZEN\n";
                        reservation1.amc = reservation1.SeatsRequired * ((amt * 60) / 100);
                    }
                    else if (reservation1.concession == 3)
                    {
                        cout << "Concession category:CHILDERN BELOW FIVE\n";
                        reservation1.amc = 0.0;
                    }
                    else if (reservation1.concession == 4)
                    {
                        cout << "You cannot get any concession\n";
                        reservation1.amc = reservation1.SeatsRequired * amt;
                    }
                    f2.write((char*)&reservation1, sizeof(reservation1));
                    reservation1.displayReserveDetails();
                    cout << "\n-----Your ticket is reserved-----\n";
                }
                else
                {
                    cout << "**Sorry req no of seats not available*\n";
                }
            }
        }
        else
        {
            flag = 0;
        }
    }
    if (flag == 0)
    {
        cout << "!\n";
    }
    f1.close();
    f2.close();
}
void train::displaypassdetail()
{
    std::cout << "\n--------Passenger Details--------\n";
    fstream f;
    reservation reservation1;
    f.open("p.txt", ios::in | ios::out | ios::binary);
    f.seekg(0);
    while (f.read((char*)&reservation1, sizeof(reservation1)))
    {
        reservation1.displayReserveDetails();
    }
    f.close();
}
void train::enquiry()
{
    fstream f;
    f.open("t.txt", ios::in | ios::out | ios::binary);
    Detail a;
    while (f.read((char*)&a, sizeof(a)))
    {
        a.displaydetail();
    }
}
void train::cancell()
{
    Detail details;
    reservation reservation1;
    Cancellation cancellation1;
    fstream f1, f2, f3;
    f1.open("t.txt", ios::in | ios::out | ios::binary);
    f2.open("p.txt", ios::in | ios::out | ios::binary);
    f3.open("cn.txt", ios::in | ios::out | ios::binary);
    cout << "**CANCELLATION MENU*\n";
    cancellation1.getCancelDetails();
    while (f2.read((char*)&reservation1, sizeof(reservation1)))
    {
        if (reservation1.Pnr() == cancellation1.Pnr())
        {
            cancellation1.trainNumber = reservation1.TrainNumber();
            strcpy(cancellation1.TrainName(), reservation1.TrainName());
            strcpy(cancellation1.BoardingPoint(), reservation1.BoardingPoint());
            strcpy(cancellation1.Destination(), reservation1.Destination());
            cancellation1.SeatsRequired = reservation1.SeatsRequired;
            for (int j = 0; j < cancellation1.SeatsRequired; j++)
            {
                strcpy(cancellation1.passengerName[j], reservation1.passengerName[j]);
                cancellation1.age[j] = reservation1.age[j];
            }
            strcpy(cancellation1.travellingClass, reservation1.travellingClass);
            if (strcmp(cancellation1.travellingClass, f) == 0)
            {
                while (f1.read((char*)&details, sizeof(details)))
                {
                    if (details.TrainNumber() == cancellation1.TrainNumber())
                    {
                        details.reqSeats_FirstClass = details.ReqSeats_FirstClass() + cancellation1.SeatsRequired;
                        date = details.datef();
                        month = details.monthf();
                        addr = f1.tellg();
                        ad = sizeof(details.ReqSeats_FirstClass());
                        f1.seekp(addr - (7 * ad));
                        f1.write((char*)&details.reqSeats_FirstClass, sizeof(details.ReqSeats_FirstClass()));
                        tamt = reservation1.amc;
                        if ((cancellation1.datef() == date) && (cancellation1.monthf() == month))
                        {
                            cout << "You are cancelling at the date of departure\n";
                            cancellation1.moneyReturn = tamt - ((tamt * 60) / 100);
                        }
                        else if (cancellation1.monthf() == month)
                        {
                            cout << "You are cancelling at the month of departure\n";
                            cancellation1.moneyReturn = tamt - ((tamt * 50) / 100);
                        }
                        else if (month > cancellation1.monthf())
                        {
                            cout << "You are cancelling one month before the date of departure\n";
                            cancellation1.moneyReturn = tamt - ((tamt * 20) / 100);
                        }
                        else
                        {
                            cout << "Cancelling after the departure\n";
                            cout << "Your request cannot be completed\n";
                        }
                        goto h;
                        cancellation1.displayCancelDetails();
                    }
                }
            }
            else if (strcmp(cancellation1.travellingClass, s) == 0)
            {
                while (f1.read((char*)&details, sizeof(details)))
                {
                    if (details.TrainNumber() == cancellation1.TrainNumber())
                    {
                        details.reqSeats_SecondClass = details.ReqSeats_SecondClass() + cancellation1.SeatsRequired;
                        date = details.datef();
                        month = details.monthf();
                        addr = f1.tellg();
                        ad = sizeof(details.ReqSeats_SecondClass());
                        f1.seekp(addr - (5 * ad));
                        f1.write((char*)&details.reqSeats_SecondClass, sizeof(details.ReqSeats_SecondClass()));
                        tamt = reservation1.amc;
                        if ((cancellation1.datef() == date) && (cancellation1.monthf() == month))
                        {
                            cout << "You are cancelling at the date of departure\n";
                            cancellation1.moneyReturn = tamt - ((tamt * 60) / 100);
                        }
                        else if (cancellation1.monthf() == month)
                        {
                            cout << "You are cancelling at the month of departure\n";
                            cancellation1.moneyReturn = tamt - ((tamt * 50) / 100);
                        }
                        else if (month > cancellation1.monthf())
                        {
                            cout << "You are cancelling one month before the date of departure\n";
                            cancellation1.moneyReturn = tamt - ((tamt * 20) / 100);
                        }
                        else
                        {
                            cout << "Cancelling after the departure\n";
                            cout << "Your request cannot be completed\n";
                        }
                        goto h;
                        cancellation1.displayCancelDetails();
                    }
                }
            }
        }
        else
        {
            flag = 0;
        }
    }
h:
    if (flag == 0)
    {
        cout << "Enter the correct pnr no\n";
    }
    f1.close();
    f2.close();
    f3.close();
}
void train::can()
{
    int choice;
    do
    {
        cout << "……………..CANCELLATION MENU………\n";
        cout << "1.Cancel\n2.Return to the main menu\n";
        cout << "Enter your choice:";
        cin >> choice;
        cout << endl;
        switch (choice)
        {
        case 1:
            cancell();
            break;
        }
    } while (choice == 1);
}
void train::user()
{
    login a;
    int choice;
    cout << "\n-----Login User-----\n";
    char password[10];
    fstream f;
    f.open("id.txt", ios::in | ios::out | ios::binary);
    char id[100];
    std::cout << "Enter your ID : ";
    std::cin >> id;
    std::cout << "Enter your Password : ";
    std::cin >> password;
    while (f.read((char*)&a, sizeof(a)))
    {
        if ((strcmp(a.Id(), id) == 0) && (strcmp(a.Pass(), password) == 0))
        {
            do
            {
                std::cout << "\n1.Reserve\n2.Cancel\n3.Enquiry\n4.Return to the main menu\n";
                cout << "Enter your choice:";
                cin >> choice;
                switch (choice)
                {
                case 1:
                    reserve();
                    break;
                case 2:
                    cancell();
                    break;
                case 3:
                    enquiry();
                    break;
                }
            } while (choice <= 3);
        }
        else
        {
            date = 1;
        }
    }
    if (date == 1)
    {
        cout << "Enter your user id and password correctly\n";
    }
}
void train::manage()
{
    int choice;
    fstream f;
    char c;
    login a;
    std::cout << "\n---WELCOME TO THE USER MANAGEMENT MENU---\n";
    do
    {
        std::cout << "1. Create id database\n";
        std::cout << "2. Add details\n";
        std::cout << "3. Display details\n";
        std::cout << "4. Return to the main menu\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;
        switch (choice)
        {
        case 1:
            f.open("id.txt", ios::out | ios::binary);
            do
            {
                a.getid();
                f.write((char*)&a, sizeof(a));
                std::cout << "Do you want to add one more record\n";
                std::cout << "y-Yes\nn-No\n";
                std::cin >> c;
            } while (c == 'y');
            f.close();
            break;
        case 2:
            f.open("id.txt", ios::in | ios::out | ios::binary | ios::app);
            a.getid();
            f.write((char*)&a, sizeof(a));
            f.close();
            break;
        case 3:
            f.open("id.txt", ios::in | ios::out | ios::binary);
            f.seekg(0);
            while (f.read((char*)&a, sizeof(a)))
            {
                a.displayid();
            }
            f.close();
            break;
        }
    } while (choice <= 3);
}