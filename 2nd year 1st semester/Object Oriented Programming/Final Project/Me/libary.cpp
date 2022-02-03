
//                           Header File in Project
#include <bits/stdc++.h>
#include <conio.h>
using namespace std;

///                   CLASS USED IN PROJECT

class Book
{
    char bookNo[6];
    char bookName[30];
    char bookAuthorName[20];

public:
    char *returnBookNo(){return bookNo;}

    void reportBook()
    {
        cout << setw(11) << left << bookNo
             << " | " << setw(30) << left << bookName
             << " | " << setw(20) << left << bookAuthorName
             << " | " << endl;
    }

    friend std::istream &operator>>(std::istream &in, Book &book);
};

class Student
{

    char id[6];
    char name[20];
    char issueBookNo[6];
    int token;

public:
    char *returnID()
    {
        return id;
    }
    char *returnIssueBooKNo()
    {
        return issueBookNo;
    }
    int returnToken()
    {
        return token;
    }
    void setToken()
    {
        token = 1;
    }
    void resetToken()
    {
        token = 0;
    }
    void getsIssueBookNo(char t[])
    {
        strcpy(issueBookNo, t);
    }
    void report()
    {
        cout << setw(6) << left << id
             << " | " << setw(20) << left << name
             << " | " << setw(5) << left << token
             << " | " << endl;
    }

    friend std::istream &operator>>(std::istream &in, Student &book);
};

///                   Operator Overloading IN PROJECT

istream &operator>>(istream &in, Book &book)
{

    cout << "\nNew Book Entry.....\n";
    cout << "\nEnter The Book No: ";
    in >> book.bookNo;
    cout << "\nEnter the name of the Book: ";
    in.ignore();
    in.getline(book.bookName, 30, '\n');
    cout << "\nEnter the Author's Name: ";
    in.clear();
    in.getline(book.bookAuthorName, 20, '\n');
    cout << "\n\nBook Created Successfully..";

    return in;
}

istream &operator>>(istream &in, Student &student)
{

    cout << "\nNew Student Entry....\n";
    cout << "\nStudent Id: ";
    in >> student.id;
    cout << "\nName: ";
    in.ignore();
    in.getline(student.name, 20, '\n');
    student.issueBookNo[0] = '\0';
    student.token = 0;
    cout << "\n\nStudent Record Created Successfull..";

    return in;
}

///    	global declaration for stream object, object
fstream fp, fp1;

class Adminestrator : public Book, public Student
{
    Book book;
    Student student;

public:
    ///    	function to write in file

    void writeBook()
    {
        char ch;
        fp.open("book.dat", ios::out | ios::app);
        do
        {
            cin >> book;
            fp.write((char *)&book, sizeof(Book));
            cout << "\n\nDo you Want to add more record..(y/n?): ";
            cin >> ch;
        } while (ch == 'y' || ch == 'Y');
        fp.close();
    }

    void writeStudent()
    {
        char ch;
        fp.open("student.dat", ios::out | ios::app);
        do
        {
            cin >> student;
            fp.write((char *)&student, sizeof(Student));
            cout << "\n\nDo you want to add more record....(Y/n?): ";
            cin >> ch;
        } while (ch == 'Y' || ch == 'y');
        fp.close();
    }

    void displayAllBooks()
    {
        fp.open("book.dat", ios::in);
        if (!fp)
        {
            cout << "Error !!! File Could not be OPEN";
            return;
        }
        cout << "\n\n\t\t Book List\n\n";

        cout << "==================================================================\n";
        cout << setw(11) << left << "Book Number"
             << " | " << setw(30) << left << "Book Name"
             << " | " << setw(20) << left << "Author"
             << " | " << endl;
        cout << "==================================================================\n";

        while (fp.read((char *)&book, sizeof(Book)))
        {
            book.reportBook();
        }
        fp.close();
    }

    void displayAllStudents()
    {
        fp.open("student.dat", ios::in);
        if (!fp)
        {
            cout << "Error !!! File could not be OPEN ";
            return;
        }

        cout << "\n\n\t\t Student List\n\n";
        cout << "==================================================================\n";
        cout << setw(6) << left << "ID"
             << " | " << setw(20) << left << "NAME"
             << " | " << setw(5) << left << "TOKEN"
             << " | " << endl;
        cout << "===================================================================\n";

        while (fp.read((char *)&student, sizeof(Student)))
        {
            student.report();
        }

        fp.close();
    }

    ///    	function to issue book
    void bookIssue()
    {
        char studentNo[6], bookNo[6];
        int found = 0, flag = 0;
        cout << "\n\nBook Issue.....";
        cout << "\n\n\tEnter the student's ID: ";
        cin >> studentNo;
        fp.open("student.dat", ios::in | ios::out);
        fp1.open("book.dat", ios::in | ios::out);

        while (fp.read((char *)&student, sizeof(Student)) && found == 0)
        {
            if (strcmpi(student.returnID(), studentNo) == 0)
            {
                found = 1;
                if (student.returnToken() == 0)
                {
                    cout << "\n\n\tEnter the Book Number: ";
                    cin >> bookNo;
                    while (fp1.read((char *)&book, sizeof(Book)) && flag == 0)
                    {
                        if (strcmpi(book.returnBookNo(), bookNo) == 0)
                        {
                            flag = 1;
                            student.setToken();
                            student.getsIssueBookNo(book.returnBookNo());
                            long long unsigned int pos = -1 * sizeof(Student);
                            fp.seekp(pos, ios::cur);
                            fp.write((char *)&student, sizeof(Student));
                            cout << "\n\n\tBook issued successfull\n\nPlease Note: Write the current date in backside of your book and submit within 10 days fine DOLLER. 2 for each day after 10 days period.";
                        }
                    }
                    if (flag == 0)
                        cout << "Book no Does not exist";
                }
                else
                {
                    cout << "You have not returned the last Book.";
                }
            }
        }

        if (found == 0)
            cout << "Student Record Not Exist....";
        fp.close();
        fp1.close();
    }

    ///    	function to deposit book

    void bookDeposit()
    {
        char studentID[6], bookNo[6];
        int found = 0, flag = 0, day, fine;
        cout << "\n\nBook Deposit...";
        cout << "\n\n\tEnter the student ID: ";
        cin >> studentID;
        fp.open("student.dat", ios::in | ios::out);
        fp1.open("book.dat", ios::in | ios::out);
        while (fp.read((char *)&student, sizeof(Student)) && found == 0)
        {
            if (strcmpi(student.returnID(), studentID) == 0)
            {
                found = 1;
                if (student.returnToken() == 1)
                {
                    while (fp1.read((char *)&book, sizeof(Book)) && flag == 0)
                    {
                        if (strcmpi(book.returnBookNo(), student.returnIssueBooKNo()) == 0)
                        {
                            flag = 1;
                            cout << "\n\nBook deposited in No. of days: ";
                            cin >> day;
                            if (day > 10)
                            {
                                fine = (day - 10) * 2;
                                cout << "\n\nFine has to deposited DOLLAR. " << fine;
                            }
                            student.resetToken();
                            long long unsigned int pos = -1 * sizeof(Student);
                            fp.seekp(pos, ios::cur);
                            fp.write((char *)&student, sizeof(Student));
                            cout << "\n\n\tBook Deposited successfully.";
                        }
                    }
                    if (flag == 0)
                        cout << "Book no does not exist";
                }
                else
                    cout << "No book is issued..please check!!";
            }
        }

        if (found == 0)
            cout << "Student record not exist...";

        fp.close();
        fp1.close();
    }
};
///    	INTRODUCTION FUNCTION

void intro()
{
    cout << "\n\n\t\tProject : LIBARY MANAGEMENT SYSTEM";
    cout << "\n\n\t\tMADE BY : SAJAL BISWAS";
    cout << "\n\t\tID : 194076";
    cout << "\n\t\tUniversity : Dhaka University & Engineering Technology";
}

///    	ADMINISTRATOR MENU FUNCTION

void admin_menu()
{

    int ch2;
    Adminestrator adminestrator;

    cout << "\n\n\n\tADMINISTRATOR MENU";
    cout << "\n\n\t1.CREATE STUDENT RECORD";
    cout << "\n\n\t2.DISPLAY ALL STUDENTS RECORD";
    cout << "\n\n\t3.CREATE BOOK ";
    cout << "\n\n\t4.DISPLAY ALL BOOKS ";
    cout << "\n\n\t5.BACK TO MAIN MENU";
    cout << "\n\n\tPlease Enter Your Choice (1-5): ";
    cin >> ch2;
    switch (ch2)
    {
    case 1:
        adminestrator.writeStudent();
        break;
    case 2:
        adminestrator.displayAllStudents();

        break;
    case 3:
        adminestrator.writeBook();
        break;
    case 4:
        adminestrator.displayAllBooks();
        break;

    case 5:
        return;
    default:
        cout << "\a";
    }
    admin_menu();
}

///    	THE MAIN FUNCTION OF PROGRAM

int main()
{
    char ch;
    Adminestrator adminestrator;
    intro();
    do
    {

        cout << "\n\n\n\tMAIN MENU";
        cout << "\n\n\t01. ADMINISTRATOR MENU";
        cout << "\n\n\t02. BOOK ISSUE";
        cout << "\n\n\t03. BOOK DEPOSIT";
        cout << "\n\n\t04. EXIT";
        cout << "\n\n\tPlease Select Your Option (1-4): ";
        ch = getche();
        switch (ch)
        {
        case '1':
            admin_menu();
            break;
        case '2':
            adminestrator.bookIssue();
            break;
        case '3':
            adminestrator.bookDeposit();
            break;
        case '4':
            exit(0);
        default:
            cout << "\a";
        }
    } while (ch != '4');
    return 0;
}

///    			END OF PROJECT
