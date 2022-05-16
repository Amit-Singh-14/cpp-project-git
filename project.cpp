#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;
bool islogin()
{
    string username, password, un, pw;

    cout << "------------------LOGIN PAGE-------------------" << endl;

    cout << "enter username :- ";
    cin >> username;
    cout << "enter password :- ";
    cin >> password;

    ifstream read(username + ".txt");
    getline(read, un);
    getline(read, pw);

    if (un == username && pw == password)
    {
        return true;
    }
    else
    {
        return false;
    }
}

class book
{
private:
    char *author, *title, *publisher;
    float *price;
    int *stock;

public:
    book()
    {
        author = new char[20];
        title = new char[20];
        publisher = new char[20];
        price = new float;
        stock = new int;
    }
    void feeddata();
    void editdata();
    void showdata();
    int search(char[], char[]);
    void buybook();
    void update(char *author, char *title, char *publisher, float *price, int *stock);
};

void book::feeddata()
{
    cin.ignore();
    ofstream file;
    cout << "\nEnter Author Name: ";
    cin.getline(author, 20);
    cout << "Enter Title Name: ";
    cin.getline(title, 20);
    cout << "Enter Publisher Name: ";
    cin.getline(publisher, 20);
    cout << "Enter Price: ";
    cin >> *price;
    cout << "Enter Stock Position: ";
    cin >> *stock;

    string a = title;
    file.open(a + ".txt");
    file << author << endl
         << title << endl
         << publisher << endl
         << *price << endl
         << *stock << endl;
    file.close();
}

void book::editdata()
{
    ofstream file;
    cout << "\nEnter Author Name: ";
    cin.getline(author, 20);
    cout << "Enter Title Name: ";
    cin.getline(title, 20);
    cout << "Enter Publisher Name: ";
    cin.getline(publisher, 20);
    cout << "Enter Price: ";
    cin >> *price;
    cout << "Enter Stock Position: ";
    cin >> *stock;

    string a = title;
    file.open(a + ".txt");
    file << author << endl
         << title << endl
         << publisher << endl
         << *price << endl
         << *stock << endl;
    file.close();
}

void book::showdata()
{
    cout << "\nAuthor Name: " << author;
    cout << "\nTitle Name: " << title;
    cout << "\nPublisher Name: " << publisher;
    cout << "\nPrice: " << *price;
    cout << "\nStock Position: " << *stock;
}

int book::search(char tbuy[20], char abuy[20])
{
    if (strcmp(tbuy, title) == 0 && strcmp(abuy, author) == 0)
        return 1;
    else
        return 0;
}

void book::buybook()
{
    int count;
    cout << "\nEnter Number Of Books to buy: ";
    cin >> count;
    if (count <= *stock)
    {
        *stock = *stock - count;
        cout << "\nBooks Bought Sucessfully";

        cout << "\nAmount: Rs. " << (*price) * count;
        update(author, title, publisher, price, stock);
    }
    else
        cout << "\nRequired Copies not in Stock";
}
void book ::update(char *author, char *title, char *publisher, float *price, int *stock)
{
    ofstream file;
    string a = title;
    file.open(a + ".txt");
    file << author << endl
         << title << endl
         << publisher << endl
         << *price << endl
         << *stock << endl;
    file.close();
}

int main()
{

    int option;
    cout<<"----------------Welcome page------------------"<<endl<<endl;

    cout << "1: Registration\n2: login\n\nyour choice :- ";
    cin >> option;
    if (option == 1)
    {
        string username, password;
        cout << "-----------------REGISTRATION PAGE------------------" << endl;
        cout << "select a username :- ";
        cin >> username;
        cout << "select a password :- ";
        cin >> password;

        cout<<"--------------succesfully registered ------------------"<<endl;
        ofstream file;
        file.open(username + ".txt");
        file << username << endl
             << password;
        file.close();

        main();
    }
    else if (option == 2)
    {

        bool status = islogin();
        if (!status)
        {
            cout << "false login!!" << endl;
            system("PAUSE");
            return 0;
        }
        else
        {
            cout << "succesfully login!!" << endl;
            system("PAUSE");

            book *B[20];
            int i = 0, r, t, choice;
            char titlebuy[20], authorbuy[20];
            while (1)
            {
                cout << "\n\n------------------MENU----------------------"
                     << "\n\t1. Entry of New Book"
                     << "\n\t2. Buy Book"
                     << "\n\t3. Search For Book"
                     << "\n\t4. Edit Details Of Book"
                     << "\n\t5. Exit"
                     << "\n\nEnter your Choice: \n";
                cin >> choice;

                switch (choice)
                {
                case 1:
                    B[i] = new book;
                    B[i]->feeddata();
                    i++;
                    break;

                case 2:
                    cin.ignore();
                    cout << "\nEnter Title Of Book:--- ";
                    cin.getline(titlebuy, 20);
                    cout << "Enter Author Of Book--- ";
                    cin.getline(authorbuy, 20);
                    for (t = 0; t < i; t++)
                    {
                        if (B[t]->search(titlebuy, authorbuy))
                        {
                            B[t]->buybook();
                            break;
                        }
                    }
                    if (t == 1)
                        cout << "\nThis Book is Not in Stock";

                    break;
                case 3:
                    cin.ignore();
                    cout << "\nEnter Title Of Book:--- ";
                    cin.getline(titlebuy, 20);
                    cout << "Enter Author Of Book:--- ";
                    cin.getline(authorbuy, 20);

                    for (t = 0; t < i; t++)
                    {
                        if (B[t]->search(titlebuy, authorbuy))
                        {
                            cout << "\nBook Found Successfully";
                            B[t]->showdata();
                            break;
                        }
                    }
                    if (t == i)
                        cout << "\nThis Book is Not in Stock";
                    break;

                case 4:
                    cin.ignore();
                    cout << "\nEnter Title Of Book:--- ";
                    cin.getline(titlebuy, 20);
                    cout << "Enter Author Of Book:--- ";
                    cin.getline(authorbuy, 20);

                    for (t = 0; t < i; t++)
                    {
                        if (B[t]->search(titlebuy, authorbuy))
                        {
                            cout << "\nBook Found Successfully";
                            B[t]->editdata();
                            break;
                        }
                    }
                    if (t == i)
                        cout << "\nThis Book is Not in Stock";
                    break;

                case 5:
                    exit(0);
                default:
                    cout << "\nInvalid Choice Entered";
                }
            }

            return 1;
        }
    }
    return 0;
}