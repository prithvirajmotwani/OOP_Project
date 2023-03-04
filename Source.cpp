#include "TMS.cpp"

int main(void)
{
    train train1;
    int choice;
    std::cout << "----- RAILWAY RESERVATION SYSTEM ----- \n";
    do
    {
        std::cout << "\n MAIN MENU \n";
        std::cout << "1.Admin mode\n2.User mode\n3.Exit \n";
        std::cout << "Enter your choice : ";
        std::cin >> choice;
        switch (choice)
        {
        case 1:
            train1.database();
            break;
        case 2:
            train1.user();
            break;
        default:
            exit(0);
        }
    } while (choice < 3);
    return 0;
}