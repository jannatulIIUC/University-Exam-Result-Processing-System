
#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <chrono>
#include <windows.h>
#include <thread>
//#include "sqlite3.h"



//HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
using namespace std;

#ifdef _WIN32
#endif




void database_connection() ;
void database_insertR() ;
void retrive_from_database() ;

const int MAX_STUDENTS = 40;

void intro_myself() ;
void view_project_name() ;
void menu() ;
void array_operation() ;
void linked_list_operation() ;
void array_insert() ;
void array_delete();
void array_search();
void array_display();
void showTemporaryMessage() ;

void linked_list_operation() ;
void linked_list_insert() ;
void linked_list_delete() ;
void linked_list_search() ;
void linked_list_display() ;


void stack_operation() ;
void stack_insert() ;
void stack_delete() ;
void stack_search() ;
void stack_display() ;

void queue_operation() ;
void queue_insert() ;
void queue_delete() ;
void queue_search() ;
void queue_display() ;

struct Student
{
    string id;
    double cgpa;
    double completedCredits;
    int notTakenCourses;
};

struct Node
{
    Student data;
    Node* next;
};

Node* head = nullptr;

Student students[MAX_STUDENTS];
int n = 0;

#define MAX_STUDENTS 40

Student stackArr[MAX_STUDENTS];
int top = -1;  // Stack initially empty

Student queueArr[MAX_STUDENTS];
int front = 0, rear = -1;
int qsize = 0;

struct Course
{
    string code;
    string name;
    double credit;
};

// Grade to GPA conversion
double gradeToPoint(const string &grade)
{
    if (grade == "A+" ) return 4.0;
    else if (grade == "A") return 3.75;
    else if (grade == "A-") return 3.50;
    else if (grade == "B+") return 3.25;
    else if (grade == "B") return 3.00;
    else if (grade == "B-") return 2.75;
    else if (grade == "C+") return 2.50;
    else if (grade == "C") return 2.25;
    else if (grade == "D") return 2.0;
    else if (grade == "F") return 0.0;
    else return -1.0; // Invalid grade
}

// Function to move cursor to specific position
void gotoxy(int x, int y)
{
#ifdef _WIN32
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);

#endif
}

void drawBox(int x, int y, int width = 30, int height = 10, const string& title = "")
{
    //system("Color 4");
    // Save current cursor position
#ifdef _WIN32
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
    COORD originalPos = csbi.dwCursorPosition;
#endif

    // Move to starting position
    gotoxy(x, y);

    // Unicode box characters
    const char* TOP_LEFT = "\u250C";
    const char* TOP_RIGHT = "\u2510";
    const char* BOTTOM_LEFT = "\u2514";
    const char* BOTTOM_RIGHT = "\u2518";
    const char* HORIZONTAL = "\u2500";
    const char* VERTICAL = "\u2502";

    // Title positioning
    int titlePos = 0;
    if (!title.empty())
    {
        titlePos = (width - 2 - title.length()) / 2;
    }

    // Top border
    cout << TOP_LEFT;
    for (int i = 0; i < width - 2; i++)
    {
        cout << HORIZONTAL;
    }
    cout << TOP_RIGHT;

    // Middle rows
    for (int row = 1; row < height - 1; row++)
    {
        gotoxy(x, y + row);
        cout << VERTICAL;

        if (row == 1 && !title.empty())
        {
            cout << string(titlePos, ' ') << title
                 << string(width - 2 - titlePos - title.length(), ' ');
        }
        else
        {
            cout << string(width - 2, ' ');
        }

        cout << VERTICAL;
    }

    // Bottom border
    gotoxy(x, y + height - 1);
    cout << BOTTOM_LEFT;
    for (int i = 0; i < width - 2; i++)
    {
        cout << HORIZONTAL;
    }
    cout << BOTTOM_RIGHT;

    // Restore cursor position
#ifdef _WIN32
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), originalPos);
#endif
}

void showTemporaryMessage(int x, int y, const char* message)
{
    COORD pos = { (SHORT)x, (SHORT)y };
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);

    SetConsoleCursorPosition(h, pos);
    cout << message;

    Sleep(1000);  // wait for 1 second

    //SetConsoleCursorPosition(h, pos);
    cout << string(strlen(message), ' ')  ;
}

int main()
{
#ifdef _WIN32
    SetConsoleOutputCP(65001); // UTF-8
#endif

    Student students[MAX_STUDENTS];
    int n = 0; // number of students currently inserted
    intro_myself() ;

    return 0;
}

void intro_myself()
{
    /*
    #ifdef _WIN32
    SetConsoleOutputCP(65001); // UTF-8
    #endif

    // Clear screen (optional)
    system("cls");
    /*
    // Draw boxes at specific positions
    drawBox(20, 5, 40, 12, "Presented by...");
    gotoxy(30, 10) ;
    cout << "JANNATUL MAOWA" << endl ;
    gotoxy(34, 11) ;
    cout << "C241429" << endl ;

    drawBox(70, 5, 40, 12, "Presented To...");
    gotoxy(80, 10) ;
    cout << "Mysha Sarin Kabisha" << endl ;
    gotoxy(75, 11) ;
    cout << "Lecturer, Dept. of CSE, IIUC" << endl ;
    // Move cursor out of the way
    gotoxy(0, 25);

    Sleep(100);
    */
    view_project_name() ;

}

void view_project_name()
{
    system("CLS");
    //system("color F4");
    gotoxy(23, 1) ;
    cout<< "\033[1;6;91m" ;
    cout << R"(
          _   _       _                    _ _           _____                       ____                _ _
         | | | |_ __ (___   _____ _ __ ___(_| |_ _   _  | ______  ____ _ _ __ ___   |  _ \ ___ ___ _   _| | |_
         | | | | '_ \| \ \ / / _ | '__/ __| | __| | | | |  _| \ \/ / _` | '_ ` _ \  | |_) / _ / __| | | | | __|
         | |_| | | | | |\ V |  __| |  \__ | | |_| |_| | | |___ >  | (_| | | | | | | |  _ |  __\__ | |_| | | |_
          \___/|_| |_|_| \_/ \___|_|  |___|_|\__|\__, | |_____/_/\_\__,_|_| |_| |_| |_| \_\___|___/\__,_|_|\__|
                                                 |___/
                  ____                             _               ____            _
                 |  _ \ _ __ ___   ___ ___ ___ ___(_)_ __   __ _  / ___| _   _ ___| |_ ___ _ __ ___
                 | |_) | '__/ _ \ / __/ _ / __/ __| | '_ \ / _` | \___ \| | | / __| __/ _ | '_ ` _ \
                 |  __/| | | (_) | (_|  __\__ \__ | | | | | (_| |  ___) | |_| \__ | ||  __| | | | | |
                 |_|   |_|  \___/ \___\___|___|___|_|_| |_|\__, | |____/ \__, |___/\__\___|_| |_| |_|
                                                           |___/         |___/


)";

    cout << "\033[0m" ;



    gotoxy(18, 17) ;
    cout << "This is a Data Structure project developed for CGPA calculation based on semester-wise GPA." ;
    gotoxy(21, 18) ;
    cout<< "Currently, it handles only 3rd semester results using Array & LinkedList operations." ;
    gotoxy(37, 19) ;
    cout << "Users can input GPA and receive the final CGPA." ;

    cin.get();
    menu() ;
}

void menu()
{
    system("CLS") ;
    gotoxy(19, 3) ;
    cout << "\033[1;31m"<< ">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>  MAIN MENU  <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<" << "\033[0m" ;
    cout << "\033[97m" ;
    drawBox(19, 4, 85, 22, "    WHICH OPERATION YOU WANNA USE??");

    cout << "\033[93m" ;
    drawBox(25, 7, 30, 5 );
    gotoxy(36, 9) ;
    cout << "1. ARRAY" ;
    cout << "\033[0m" ;

    cout << "\033[93m" ;
    drawBox(70, 7, 30, 5 );
    gotoxy(80, 9) ;
    cout << "2. LINKED LIST" ;
    cout << "\033[0m" ;

    cout << "\033[93m" ;
    drawBox(25, 14, 30, 5);
    gotoxy(36, 16) ;
    cout << "3. STACK" ;
    cout << "\033[0m" ;

    cout << "\033[93m" ;
    drawBox(70, 14, 30, 5 );
    gotoxy(80, 16) ;
    cout << "4. QUEUE" ;
    cout << "\033[0m" ;

    cout << "\033[93m" ;
drawBox(47, 20, 30, 5);
gotoxy(58, 22);
cout << "0. EXIT";
cout << "\033[0m";

    int n ;

    gotoxy(40, 27) ;
    cout << "\033[3;4;94mCHOOSE AN OPTION\033[0m"  ;
    gotoxy(60, 27) ;
    cin >> n ;


    if (n == 1)
        array_operation() ;
    else if (n == 2)
        linked_list_operation() ;
    else if (n == 3)
        stack_operation() ;
    else if (n == 4)
        queue_operation() ;
    else if (n == 0)
    {
        system("CLS") ;
        exit(0);
    }

    else
    {
        showTemporaryMessage(68, 23, "\033[3;33mInvalid input! Please try again....\033[0m") ;
        Sleep(300) ;
        gotoxy(60, 17) ;
        fflush(stdin) ;
        menu() ;
    }

}

void array_operation()
{
    system("CLS") ;
    gotoxy(20, 4) ;
    cout << "\033[1;92m>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>  MAIN MENU  <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<\033[0m" ;
    cout << "\033[95m" ;
    drawBox(19, 5, 85, 12, "USING ARRAY");
    cout << "\033[0m" ;

    gotoxy(22, 7) ;
    cout << "\033[97m1 . INSERT  a student result" << endl ;

    gotoxy(22, 8) ;
    cout << "2 . DELETE  a student result" << endl ;

    gotoxy(22, 9) ;
    cout << "3 . SEARCH  a student result" << endl ;

    gotoxy(22, 10) ;
    cout << "4 . DISPLAY  a student result" << endl ;

    gotoxy(22, 12) ;
    cout << "Press 5 to go back......\033[0m" << endl ;



    gotoxy(40, 17) ;
    cout << "\033[3;4;94mCHOOSE AN OPTION\033[0m" ;
    gotoxy(60, 17) ;

    int n ;
    cin >> n ;

    if (n == 1)
        array_insert() ;
    else if (n == 2)
        array_delete() ;
    else if (n == 3)
        array_search() ;
    else if (n == 4)
        array_display() ;
    else if (n == 5)
        menu() ;
    else
    {
        showTemporaryMessage(40, 77, "Invalid input! Please try again....") ;
        Sleep(300) ;
        gotoxy(40, 17) ;
        fflush(stdin) ;
        // getchar() ;
        array_operation() ;
    }
}


void linked_list_operation()
{
    system("CLS") ;

    gotoxy(20, 4) ;
    cout << ">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>  MAIN MENU  <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<" ;
    cout << "\033[95m" ;
    drawBox(19, 5, 85, 12, "USING LINKED LIST");
    cout << "\033[97m" ;

    gotoxy(22, 7) ;
    cout << "1. INSERT  a student result" << endl ;

    gotoxy(22, 8) ;
    cout << "2. DELETE  a student result" << endl ;

    gotoxy(22, 9) ;
    cout << "3. SEARCH  a student result" << endl ;

    gotoxy(22, 10) ;
    cout << "4. DISPLAY  a student result" << endl ;

    gotoxy(22, 12) ;
    cout << "Press 5 to go back......" << endl ;
    gotoxy(40, 17) ;
    cout << "\033[3;4;94mCHOOSE AN OPTION\033[0m" ;
    gotoxy(60, 17) ;

    int n ;
    cin >> n ;

    if (n == 1)
        linked_list_insert() ;
    else if (n == 2)
        linked_list_delete() ;
    else if (n == 3)
        linked_list_search() ;
    else if (n == 4)
        linked_list_display() ;
    else if (n == 5)
        menu() ;
    else
    {
        showTemporaryMessage(40, 77, "Invalid input! Please try again....") ;
        Sleep(300) ;
        gotoxy(40, 17) ;
        fflush(stdin) ;
        array_operation() ;
    }
}

Student taking_input()
{
    Course courses[] =
    {
        {"URED_2302", "Sciences of Qur'an and Hadith", 2.0} ,
        {"MATH_2307", "Mathematics III", 3.0} ,
        {"CSE_2321", "Data Structures", 3.0} ,
        {"CSE_2322", "Data Structures Lab", 1.5} ,
        {"STAT_2311", "Probability and Statistics", 2.0} ,
        {"CHEM_2301", "Chemistry", 3.0} ,
        {"CSE_2323", "Digital Logic Design", 3.0} ,
        {"CSE_2324", "Digital Logic Design Lab", 1.5}
    };
    const int courseCount = sizeof(courses) / sizeof(courses[0]) ;

    Student s;
    gotoxy(23, 8);
    cout << "\033[91mEnter Student ID: \033[0m" ;
    cin >> s.id;
    cin.ignore();

    double totalWeightedGPA = 0.0, totalCredits = 0.0 ;
    s.notTakenCourses = 0;

    int y = 10;
    for (int i = 0; i < courseCount; ++i)
    {
        string grade;
        double point;

        while (true)
        {
            gotoxy(23, y++);
            cout << "\033[36m"
     << setw(10) << left << courses[i].code << " "
     << setw(30) << left << courses[i].name << " "
     << " \033[35m(Credit " << setw(2) << courses[i].credit << "): "
     << "\033[0m";
            cin >> grade;

            if (grade == "0")
            {
                s.notTakenCourses++;
                break;
            }
            else if (grade == "A+") point = 4.0;
            else if (grade == "A")  point = 3.7;
            else if (grade == "A-") point = 3.5;
            else if (grade == "B+") point = 3.3;
            else if (grade == "B")  point = 3.0;
            else if (grade == "B-") point = 2.7;
            else if (grade == "C+") point = 2.3;
            else if (grade == "C")  point = 2.0;
            else if (grade == "D")  point = 1.0;
            else if (grade == "F")  point = 0.0;
            else
            {
                showTemporaryMessage(26 , y++ , "\033[95mInvalid grade! Enter A+, A, A-, ..., F or 0.\033[0m") ;
                y-- ;
                continue ;
            }

            totalWeightedGPA += point * courses[i].credit ;
            totalCredits += courses[i].credit ;
            break ;
        }
    }

    s.cgpa = (totalCredits == 0.0) ? 0.0 : totalWeightedGPA / totalCredits ;
    s.completedCredits = totalCredits ;

    return s ;
}

void array_insert() {
    system("CLS");
    drawBox(19, 5, 85, 20, "\033[1;101mINSERT A STUDENT USING ARRAY\033[0m");

    if (n >= MAX_STUDENTS) {
        gotoxy(23, 8);
        cout << "\033[1;96mCannot insert more students. Array is full.\033[0m";
        return;
    }
    Student s = taking_input();

    int pos = n;
    while (pos > 0 && students[pos - 1].id > s.id) {
        students[pos] = students[pos - 1]; // Shift right
        pos--;
    }
    students[pos] = s;
    n++;
    gotoxy(50, 20);
    cout << "\033[1;3;93mStudent inserted successfully!\033[0m";
    Sleep(1550);
    array_operation();
}
void array_delete()
{
    system("CLS");
    drawBox(20, 6, 60, 10, "\033[1;101mDELETE STUDENT\033[0m");

    if (n == 0)
    {
        gotoxy(25, 9);
        cout << "No students to delete.";
        gotoxy(25, 11);
        cout << "\033[3;93mPress Enter to go back...\033[0m";
        cin.ignore();
        cin.get();
        array_operation();
        return;
    }

    string idToDelete;
    gotoxy(23, 9);
    cout << "\033[92mEnter Student ID to delete: \033[0m";
    cin >> idToDelete;

    bool found = false;
    for (int i = 0; i < n; ++i)
    {
        if (students[i].id == idToDelete)
        {
            found = true;
            for (int j = i; j < n - 1; ++j)
            {
                students[j] = students[j + 1];
            }
            n--;
            break;
        }
    }

    gotoxy(23, 11);
    if (found)
        cout << "Student deleted successfully.";
    else
        cout << "Student ID not found.";

    gotoxy(23, 13);
    cout << "\033[3;93mPress Enter to go back...\033[0m";
    cin.ignore();
    cin.get();
    array_operation();
}

void array_search()
{
    system("CLS");
    drawBox(20, 6, 70, 12, "\033[101mSEARCH STUDENT\033[0m");

    if (n == 0)
    {
        gotoxy(25, 9);
        cout << "No students to search.";
        gotoxy(25, 11);
        cout << "\033[3;93mPress Enter to go back...\033[0m";
        cin.ignore();
        cin.get();
        array_operation();
        return;
    }

    string idToSearch;
    gotoxy(23, 9);
    cout << "Enter Student ID to search: ";
    cin >> idToSearch;

    bool found = false;
    int pos = 0;
    for (int i = 0; i < n; ++i)
    {
        if (students[i].id == idToSearch)
        {
            found = true;
            pos = i;
            break;
        }
    }

    if (found)
    {
        gotoxy(23, 11);
        cout << "Student found:";
        gotoxy(23, 13);
        cout << "ID: " << students[pos].id;
        gotoxy(23, 14);
        cout << "CGPA: " << fixed << setprecision(2) << students[pos].cgpa;
        gotoxy(23, 15);
        cout << "Completed Credits: " << students[pos].completedCredits;
        gotoxy(23, 16);
        cout << "Courses not taken: " << students[pos].notTakenCourses;
    }
    else
    {
        gotoxy(23, 11);
        cout << "\033[93mStudent ID not found.\033[0m";
    }

    gotoxy(60, 18);
    cout << "\033[93mPress Enter to go back...\033[0m";
    cin.ignore();
    cin.get();
    array_operation();
}

void array_display()
{
    system("CLS");
    drawBox(18, 2, 100, 25, "\033[1;101mSTUDENT LIST\033[0m");

    if (n == 0)
    {
        gotoxy(45, 12);
        cout << "No student records found.";
    }
    else
    {
        // Print table header
        gotoxy(20, 5);
        cout << left << setw(10) << "SL" << setw(25) << "ID"
             << setw(15) << "CGPA" << setw(25) << "Completed"
             << "Not Taken";

        gotoxy(20, 6);
        cout << string(90, '-');

        int y = 7;
        for (int i = 0; i < n; ++i)
        {
            gotoxy(20, y++);
            cout << left << setw(10) << i + 1
                 << setw(25) << students[i].id
                 << setw(15) << fixed << setprecision(2) << students[i].cgpa
                 << setw(25) << students[i].completedCredits
                 << students[i].notTakenCourses;
        }
    }

    gotoxy(35, 27);
    cout << "\033[3;93mPress Enter to go back...\033[0m";
    cin.ignore();
    cin.get();
    array_operation();
}
void linked_list_insert()
{
    system("CLS");
    drawBox(19, 5, 85, 20, "\033[1;101mINSERT A STUDENT USING LINKED LIST\033[0m");

    Student newStudent = taking_input();

    Node* newNode = new Node;
    newNode->data = newStudent;
    newNode->next = nullptr;

    if (head == nullptr)
    {
        head = newNode; // first node
    }
    else
    {
        Node* temp = head;
        while (temp->next != nullptr)
        {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    gotoxy(23, 22);
    cout << "\033[1;3;93mStudent inserted successfully at the end of the linked list!\033[0m";
    Sleep(1550) ;

    linked_list_operation(); // If you have menu/options after insert
}

void linked_list_delete()
{
    system("CLS");
    drawBox(19, 5, 85, 20, "\033[1;101mDELETE A STUDENT USING LINKED LIST\033[0m");

    gotoxy(23, 8);
    string targetID;
    cout << "\033[92mEnter Student ID to delete: \033[0m";
    cin >> targetID;

    Node* temp = head;
    Node* prev = nullptr;

    while (temp != nullptr && temp->data.id != targetID)
    {
        prev = temp;
        temp = temp->next;
    }

    gotoxy(23, 10);
    if (temp == nullptr)
    {
        cout << "Student not found.";
    }
    else
    {
        if (prev == nullptr)
        {
            head = head->next;
        }
        else
        {
            prev->next = temp->next;
        }
        delete temp;
        cout << "\033[3;94mStudent deleted successfully.\033[0m";
    }

    gotoxy(23, 22);
    cout << "\033[3;93mPress any key to return to the menu...\033[0m";
    cin.ignore();
    cin.get();
    linked_list_operation();
}

void linked_list_search()
{
    system("CLS");
    drawBox(19, 5, 85, 20, "\033[1;101mSEARCH A STUDENT USING LINKED LIST\033[0m");

    gotoxy(23, 8);
    string targetID;
    cout << "\033[92mEnter Student ID to search: \033[0m";
    cin >> targetID;

    Node* temp = head;
    int y = 10;
    while (temp != nullptr)
    {
        if (temp->data.id == targetID)
        {
            gotoxy(23, y++);
            cout << "Student ID: " << temp->data.id;
            gotoxy(23, y++);
            cout << "CGPA: " << temp->data.cgpa;
            gotoxy(23, y++);
            cout << "Completed Credits: " << temp->data.completedCredits;
            gotoxy(23, y++);
            cout << "Not Taken Courses: " << temp->data.notTakenCourses;

            gotoxy(23, 22);
            cout << "\033[3;93mPress any key to return to the menu...\033[0m";
            cin.ignore();
            cin.get();
            linked_list_operation();
            return;
        }
        temp = temp->next;
    }

    gotoxy(23, 10);
    cout << "Student not found.";

    gotoxy(23, 22);
    cout << "\033[3;93mPress any key to return to the menu...\033[0m";
    cin.ignore();
    cin.get();
    linked_list_operation();
}

void linked_list_display()
{
    system("CLS");
    drawBox(10, 2, 100, 25, " LINKED LIST - STUDENT RECORDS ");

    if (head == NULL)
    {
        gotoxy(45, 12);
        cout << "No student records found.";
    }
    else
    {
        gotoxy(15, 5);
        cout << left << setw(5) << "SL" << setw(20) << "ID"
             << setw(10) << "CGPA" << setw(20) << "Completed"
             << "Not Taken";

        gotoxy(15, 6);
        cout << string(70, '-');

        Node* cur = head;
        int y = 7, i = 1;

        while (cur)
        {
            gotoxy(15, y++);
            cout << left << setw(5) << i++
                 << setw(20) << cur->data.id
                 << setw(10) << fixed << setprecision(2) << cur->data.cgpa
                 << setw(20) << cur->data.completedCredits
                 << cur->data.notTakenCourses;

            cur = cur->next;
        }
    }
    gotoxy(35, 27);
    cout << "\033[3;93mPress Enter to go back...\033[0m";
    cin.ignore();
    cin.get();
    linked_list_operation();
}

void stack_operation()
{
    system("CLS");

    gotoxy(20, 4);
    cout << "\033[1;92m>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>  MAIN MENU  <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<\033[0m";
    cout << "\033[95m";
    drawBox(19, 5, 85, 12, "USING STACK");
    cout << "\033[0m";

    gotoxy(22, 7);  cout << "\033[97m1 . INSERT  a student result" << endl;
    gotoxy(22, 8);  cout << "2 . DELETE  top student result" << endl;
    gotoxy(22, 9);  cout << "3 . SEARCH  a student result" << endl;
    gotoxy(22, 10); cout << "4 . DISPLAY all student results" << endl;
    gotoxy(22, 12); cout << "Press 5 to go back......\033[0m" << endl;

    gotoxy(40, 17); cout << "\033[3;4;94mCHOOSE AN OPTION\033[0m";
    gotoxy(60, 17);

    int choice;
    cin >> choice;

    if (choice == 1)      stack_insert();
    else if (choice == 2) stack_delete();
    else if (choice == 3) stack_search();
    else if (choice == 4) stack_display();
    else if (choice == 5) menu();
    else {
        showTemporaryMessage(40, 77, "Invalid input! Please try again....");
        Sleep(300);
        fflush(stdin);
        stack_operation();
    }
}

void stack_insert()
{
    system("CLS");
    drawBox(19, 5, 85, 20, "\033[1;101mINSERT A STUDENT USING STACK\033[0m");

    Student s = taking_input();
    stackArr[top++] = s;

    gotoxy(50, 20);
    cout << "\033[1;3;93mStudent pushed into stack successfully!\033[0m";
    Sleep(1550);

    stack_operation();
}


void stack_delete()
{
    system("CLS");
    drawBox(20, 6, 60, 10, "\033[1;101mDELETE STUDENT\033[0m");

    if (top == -1)
    {
        gotoxy(25, 9);
        cout << "Stack is empty. No student to delete.";
        gotoxy(25, 11);
        cout << "\033[3;93mPress Enter to go back...\033[0m";
        cin.ignore();
        cin.get();
        stack_operation();
        return;
    }

    top--;

    gotoxy(25, 9);
    cout << "Top student popped successfully.";
    gotoxy(25, 11);
    cout << "\033[3;93mPress Enter to go back...\033[0m";
    cin.ignore();
    cin.get();
    stack_operation();
}

void stack_search()
{
    system("CLS");
    drawBox(20, 6, 70, 12, "\033[101mSEARCH STUDENT\033[0m");

    if (top == -1)
    {
        gotoxy(25, 9);
        cout << "Stack is empty. No students to search.";
        gotoxy(25, 11);
        cout << "\033[3;93mPress Enter to go back...\033[0m";
        cin.ignore();
        cin.get();
        stack_operation();
        return;
    }

    string idToSearch;
    gotoxy(23, 9);
    cout << "Enter Student ID to search: ";
    cin >> idToSearch;

    bool found = false;
    Student s;
    for (int i = top; i >= 0; i--)
    {
        if (stackArr[i].id == idToSearch)
        {
            found = true;
            s = stackArr[i];
            break;
        }
    }

    if (found)
    {
        gotoxy(23, 11);
        cout << "Student found:";
        gotoxy(23, 13);
        cout << "ID: " << s.id;
        gotoxy(23, 14);
        cout << "CGPA: " << fixed << setprecision(2) << s.cgpa;
        gotoxy(23, 15);
        cout << "Completed Credits: " << s.completedCredits;
        gotoxy(23, 16);
        cout << "Courses not taken: " << s.notTakenCourses;
    }
    else
    {
        gotoxy(23, 11);
        cout << "\033[93mStudent ID not found.\033[0m";
    }

    gotoxy(60, 18);
    cout << "\033[93mPress Enter to go back...\033[0m";
    cin.ignore();
    cin.get();
    stack_operation();
}

void stack_display()
{
    system("CLS");
    drawBox(18, 2, 100, 25, "\033[1;101mSTUDENT LIST (STACK)\033[0m");

    if (top == -1)
    {
        gotoxy(45, 12);
        cout << "No student records found.";
    }
    else
    {
        gotoxy(20, 5);
        cout << left << setw(10) << "SL" << setw(25) << "ID"
             << setw(15) << "CGPA" << setw(25) << "Completed"
             << "Not Taken";

        gotoxy(20, 6);
        cout << string(90, '-');

        int y = 7;
        for (int i = top; i >= 0; --i)
        {
            gotoxy(20, y++);
            cout << left << setw(10) << (top - i + 1)
                 << setw(25) << stackArr[i].id
                 << setw(15) << fixed << setprecision(2) << stackArr[i].cgpa
                 << setw(25) << stackArr[i].completedCredits
                 << stackArr[i].notTakenCourses;
        }
    }
    gotoxy(35, 27);
    cout << "\033[3;93mPress Enter to go back...\033[0m";
    cin.ignore(); cin.get();
    stack_operation();
}

void queue_operation()
{
    system("CLS");

    gotoxy(20, 4);
    cout << "\033[1;92m>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>  MAIN MENU  <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<\033[0m";
    cout << "\033[95m";
    drawBox(19, 5, 85, 12, "USING QUEUE");
    cout << "\033[0m";

    gotoxy(22, 7);
    cout << "\033[97m1 . INSERT  a student result" << endl;
    gotoxy(22, 8);
    cout << "2 . DELETE  front student result" << endl;
    gotoxy(22, 9);
    cout << "3 . SEARCH  a student result" << endl;
    gotoxy(22, 10);

    cout << "4 . DISPLAY all student results" << endl;
    gotoxy(22, 12);
    cout << "Press 5 to go back......\033[0m" << endl;

    gotoxy(40, 17);
    cout << "\033[3;4;94mCHOOSE AN OPTION\033[0m";
    gotoxy(60, 17);

    int choice;
    cin >> choice;

    if (choice == 1)      queue_insert();
    else if (choice == 2) queue_delete();
    else if (choice == 3) queue_search();
    else if (choice == 4) queue_display();
    else if (choice == 5) menu();
    else {
        showTemporaryMessage(40, 77, "Invalid input! Please try again....");
        Sleep(300);
        fflush(stdin);
        queue_operation();
    }
}

void queue_insert()
{
    system("CLS");
    drawBox(19, 5, 85, 20, "\033[1;101mINSERT A STUDENT USING QUEUE\033[0m");

    if (qsize >= MAX_STUDENTS)
    {
        gotoxy(23, 8);
        cout << "\033[1;96mQueue full. Cannot insert more students.\033[0m";
        return;
    }

    Student s = taking_input();
    rear = (rear + 1) % MAX_STUDENTS;
    queueArr[rear] = s;
    qsize++;

    gotoxy(50, 20);
    cout << "\033[1;3;93mStudent enqueued successfully!\033[0m";
    Sleep(1550);

    queue_operation();
}

void queue_delete()
{
    system("CLS");
    drawBox(20, 6, 60, 10, "\033[1;101mDELETE STUDENT\033[0m");

    if (qsize == 0)
    {
        gotoxy(25, 9);
        cout << "Queue is empty. No student to delete.";
        gotoxy(25, 11);
        cout << "\033[3;93mPress Enter to go back...\033[0m";
        cin.ignore(); cin.get();
        queue_operation();
        return;
    }

    front = (front + 1) % MAX_STUDENTS;
    qsize--;

    gotoxy(25, 9);
    cout << "Front student dequeued successfully.";
    gotoxy(25, 11);
    cout << "\033[3;93mPress Enter to go back...\033[0m";
    cin.ignore(); cin.get();
    queue_operation();
}

void queue_search()
{
    system("CLS");
    drawBox(20, 6, 70, 12, "\033[101mSEARCH STUDENT\033[0m");

    if (qsize == 0)
    {
        gotoxy(25, 9);
        cout << "Queue is empty. No students to search.";
        gotoxy(25, 11);
        cout << "\033[3;93mPress Enter to go back...\033[0m";
        cin.ignore(); cin.get();
        queue_operation();
        return;
    }

    string idToSearch;
    gotoxy(23, 9);
    cout << "Enter Student ID to search: ";
    cin >> idToSearch;

    bool found = false;
    Student s;
    for (int i = 0; i < qsize; ++i)
    {
        int idx = (front + i) % MAX_STUDENTS;
        if (queueArr[idx].id == idToSearch)
        {
            s = queueArr[idx];
            found = true;
            break;
        }
    }
    if (found)
    {
        gotoxy(23, 11); cout << "Student found:";
        gotoxy(23, 13); cout << "ID: " << s.id;
        gotoxy(23, 14); cout << "CGPA: " << fixed << setprecision(2) << s.cgpa;
        gotoxy(23, 15); cout << "Completed Credits: " << s.completedCredits;
        gotoxy(23, 16); cout << "Courses not taken: " << s.notTakenCourses;
    }
    else
    {
        gotoxy(23, 11);
        cout << "\033[93mStudent ID not found.\033[0m";
    }
    gotoxy(60, 18);
    cout << "\033[93mPress Enter to go back...\033[0m";
    cin.ignore(); cin.get();
    queue_operation();
}

void queue_display()
{
    system("CLS");
    drawBox(18, 2, 100, 25, "\033[1;101mSTUDENT LIST (QUEUE)\033[0m");

    if (qsize == 0)
    {
        gotoxy(45, 12);
        cout << "No student records found.";
    }
    else
    {
        gotoxy(20, 5);
        cout << left << setw(10) << "SL" << setw(25) << "ID"
             << setw(15) << "CGPA" << setw(25) << "Completed"
             << "Not Taken";

        gotoxy(20, 6);
        cout << string(90, '-');

        int y = 7;
        for (int i = 0; i < qsize; ++i)
        {
            int idx = (front + i) % MAX_STUDENTS;
            gotoxy(20, y++);
            cout << left << setw(10) << (i + 1)
                 << setw(25) << queueArr[idx].id
                 << setw(15) << fixed << setprecision(2) << queueArr[idx].cgpa
                 << setw(25) << queueArr[idx].completedCredits
                 << queueArr[idx].notTakenCourses;
        }
    }

    gotoxy(35, 27);
    cout << "\033[3;93mPress Enter to go back...\033[0m";
    cin.ignore(); cin.get();
    queue_operation();
}
