#include <iostream>

using namespace std;
int margin;
int idCount = 0;
int dCount = 0;

class BaseClass {
public:
    virtual void create() = 0;
    virtual void edit() = 0;
    virtual void del() = 0;
    virtual void display() = 0;
};

class DepartmentManagement : BaseClass {
public:
    int id;
    string name;
    DepartmentManagement() {
        id = -1;
    }
    void create();
    void edit();
    void del();
    void display();
}darr[30];

class EmployeeManagement : BaseClass {
public:
    int id;
    string name;
    int age;
    EmployeeManagement() {
        id = -1;
        age = 0;
    }
    void create();
    void edit();
    void del();
    void display();
}earr[30];

bool checkEntry(string n);
bool checkEntryDepartment(string n);

template <class T>
int search(T a[30], string x) {
    int i = 0;
    while (a[i].name != x)
        i++;
    return i;
}

template <class T>
void sort(T a[30], int n) {
    int i, j, min;
    T temp;
    for (i = 0; i < n; i++) {
        min = i;
        for (j = i + 1; j <= n; j++)
            if (a[j].name[0] < a[min].name[0])
                min = j;
        temp = a[i];
        a[i] = a[min];
        a[min] = temp;
    }
}

void DepartmentManagement::create() {
    for (margin = 0; margin <= 14; margin++)
        cout << ' ';
    for (int i = 0; i < 4; i++)
        cout << '>';
    cout << " CREATING NEW RECORD OF DEPARTMENT ";
    for (int i = 0; i < 4; i++)
        cout << '<';

    cout << endl << endl;
    for (margin = 0; margin <= 14; margin++)
        cout << ' ';
    for (int i = 0; i < 43; i++)
        cout << '*';
    cout << endl;

    for (margin = 0; margin <= 14; margin++)
        cout << ' ';
    cout << "Enter DEPARTMENT NAME: ";
    cin >> name;

    for (margin = 0; margin <= 14; margin++)
        cout << ' ';
    for (int i = 0; i < 43; i++)
        cout << '*';

    cout << "\n\n\n\tPress Enter to continue";
    system("pause > nul");

    if (!checkEntryDepartment(name)) {
        id = dCount++;

        // Display added record
        system("cls");
        cout << "\n\n\n";

        for (margin = 0; margin <= 14; margin++)
            cout << ' ';
        for (int i = 0; i < 4; i++)
            cout << '>';
        cout << " ADDED RECORD OF DEPARTMENT ";
        for (int i = 0; i < 4; i++)
            cout << '<';

        cout << endl << endl;
        for (margin = 0; margin <= 14; margin++)
            cout << ' ';
        for (int i = 0; i < 36; i++)
            cout << '*';

        cout << endl;
        for (margin = 0; margin <= 18; margin++)
            cout << ' ';
        cout << " ID\t      DEPARTMENT NAME";

        display();

        cout << endl;
        for (margin = 0; margin <= 14; margin++)
            cout << ' ';
        for (int i = 0; i < 36; i++)
            cout << '*';

        cout << "\n\n\n\tREMEMBER: Department ID is important so don't forget it.";
    }
    else {
        system("cls");
        cout << "\n\n\n\tEntry has already been added.";
    }

    cout << "\n\n\tPress any key to continue!";
    system("pause > nul");
}

void DepartmentManagement::edit() {
    system("cls");
    cout << "\n\n\n";

    for (margin = 0; margin <= 14; margin++)
        cout << ' ';
    for (int i = 0; i < 2; i++)
        cout << '>';
    cout << " EXISTING RECORD OF DEPARTMENT ";
    for (int i = 0; i < 3; i++)
        cout << '<';

    cout << endl << endl;
    for (margin = 0; margin <= 14; margin++)
        cout << ' ';
    for (int i = 0; i < 36; i++)
        cout << '*';

    cout << endl;
    for (margin = 0; margin <= 18; margin++)
        cout << ' ';
    cout << " ID\t      DEPARTMENT NAME";

    display();

    cout << endl;
    for (margin = 0; margin <= 14; margin++)
        cout << ' ';
    for (int i = 0; i < 36; i++)
        cout << '*';

    cout << "\n\n\tPress any key to continue!";
    system("pause > nul");

    // Ask for new name and age
    system("cls");
    cout << "\n\n\n";

    cout << "\tEnter NEW Department Name: ";
    cin >> name;

    // Display NEW record
    system("cls");
    cout << "\n\n\n";

    for (margin = 0; margin <= 14; margin++)
        cout << ' ';
    for (int i = 0; i < 5; i++)
        cout << '>';
    cout << " NEW RECORD OF DEPARTMENT ";
    for (int i = 0; i < 5; i++)
        cout << '<';

    cout << endl << endl;
    for (margin = 0; margin <= 14; margin++)
        cout << ' ';
    for (int i = 0; i < 36; i++)
        cout << '*';
    cout << endl;

    for (margin = 0; margin <= 18; margin++)
        cout << ' ';
    cout << " ID\t      DEPARTMENT NAME";

    display();

    cout << endl;
    for (margin = 0; margin <= 14; margin++)
        cout << ' ';
    for (int i = 0; i < 36; i++)
        cout << '*';

    cout << "\n\n\tPress any key to continue!";
    system("pause > nul");
}

void DepartmentManagement::del() {
    system("cls");
    cout << "\n\n\n";

    for (margin = 0; margin <= 14; margin++)
        cout << ' ';
    for (int i = 0; i < 3; i++)
        cout << '>';
    cout << " DELETED RECORD OF DEPARTMENT ";
    for (int i = 0; i < 3; i++)
        cout << '<';

    cout << endl << endl;
    for (margin = 0; margin <= 14; margin++)
        cout << ' ';
    for (int i = 0; i < 36; i++)
        cout << '*';

    cout << endl;
    for (margin = 0; margin <= 18; margin++)
        cout << ' ';
    cout << " ID\t      DEPARTMENT NAME";

    display();

    cout << endl;
    for (margin = 0; margin <= 14; margin++)
        cout << ' ';
    for (int i = 0; i < 36; i++)
        cout << '*';
}

void DepartmentManagement::display() {
    cout << endl;
    for (margin = 0; margin <= 20; margin++)
        cout << ' ';
    cout.width(3); cout << left << id;
    cout.width(6); cout << " ";
    cout.width(14); cout << left << name;
}

void EmployeeManagement::create() {
    for (margin = 0; margin <= 14; margin++)
        cout << ' ';
    for (int i = 0; i < 5; i++)
        cout << '>';
    cout << " CREATING NEW RECORD OF EMPLOYEE ";
    for (int i = 0; i < 5; i++)
        cout << '<';

    cout << endl << endl;
    for (margin = 0; margin <= 14; margin++)
        cout << ' ';
    for (int i = 0; i < 43; i++)
        cout << '*';
    cout << endl;

    for (margin = 0; margin <= 14; margin++)
        cout << ' ';
    cout << "Enter FIRST NAME of Employee: ";
    cin >> name;
    for (margin = 0; margin <= 14; margin++)
        cout << ' ';
    cout << "Enter AGE of Employee: ";
    cin >> age;

    for (margin = 0; margin <= 14; margin++)
        cout << ' ';
    for (int i = 0; i < 43; i++)
        cout << '*';

    cout << "\n\n\n\tPress Enter to continue";
    system("pause > nul");
    
    if (!checkEntry(name)) {
        id = idCount++;

        // Display added record
        system("cls");
        cout << "\n\n\n";

        for (margin = 0; margin <= 14; margin++)
            cout << ' ';
        for (int i = 0; i < 5; i++)
            cout << '>';
        cout << " ADDED RECORD OF EMPLOYEE ";
        for (int i = 0; i < 5; i++)
            cout << '<';

        cout << endl << endl;
        for (margin = 0; margin <= 14; margin++)
            cout << ' ';
        for (int i = 0; i < 36; i++)
            cout << '*';

        cout << endl;
        for (margin = 0; margin <= 20; margin++)
            cout << ' ';
        cout << " ID\tNAME\t    AGE";

        display();

        cout << endl;
        for (margin = 0; margin <= 14; margin++)
            cout << ' ';
        for (int i = 0; i < 36; i++)
            cout << '*';

        cout << "\n\n\n\tREMEMBER: Employee ID is important so don't forget it.";
    }
    else {
        system("cls");
        cout << "\n\n\n\tEntry has already been added.";
    }
    
    cout << "\n\n\tPress any key to continue!";
    system("pause > nul");
}

void EmployeeManagement :: edit() {
    system("cls");
    cout << "\n\n\n";

    for (margin = 0; margin <= 14; margin++)
        cout << ' ';
    for (int i = 0; i < 4; i++)
        cout << '>';
    cout << " EXISTING RECORD OF EMPLOYEE ";
    for (int i = 0; i < 3; i++)
        cout << '<';
    
    cout << endl << endl;
    for (margin = 0; margin <= 14; margin++)
        cout << ' ';
    for (int i = 0; i < 36; i++)
        cout << '*';
    
    cout << endl;
    for (margin = 0; margin <= 20; margin++)
        cout << ' ';
    cout << " ID\tNAME\t    AGE";

    display();

    cout << endl;
    for (margin = 0; margin <= 14; margin++)
        cout << ' ';
    for (int i = 0; i < 36; i++)
        cout << '*';

    cout << "\n\n\tPress any key to continue!";
    system("pause > nul");

    // Ask for new name and age
    system("cls");
    cout << "\n\n\n";

    cout << "\tEnter NEW Name: ";
    cin >> name;
    cout << "\tEnter NEW Age: ";
    cin >> age;

    // Display NEW record
    system("cls");
    cout << "\n\n\n";

    for (margin = 0; margin <= 14; margin++)
        cout << ' ';
    for (int i = 0; i < 6; i++)
        cout << '>';
    cout << " NEW RECORD OF EMPLOYEE ";
    for (int i = 0; i < 6; i++)
        cout << '<';
    
    cout << endl << endl;
    for (margin = 0; margin <= 14; margin++)
        cout << ' ';
    for (int i = 0; i < 36; i++)
        cout << '*';
    cout << endl;

    for (margin = 0; margin <= 20; margin++)
        cout << ' ';
    cout << " ID\tNAME\t    AGE";

    display();

    cout << endl;
    for (margin = 0; margin <= 14; margin++)
        cout << ' ';
    for (int i = 0; i < 36; i++)
        cout << '*';

    cout << "\n\n\tPress any key to continue!";
    system("pause > nul");
}

void EmployeeManagement::del() {
    system("cls");
    cout << "\n\n\n";

    for (margin = 0; margin <= 14; margin++)
        cout << ' ';
    for (int i = 0; i < 5; i++)
        cout << '>';
    cout << " DELETED RECORD OF EMPLOYEE ";
    for (int i = 0; i < 5; i++)
        cout << '<';

    cout << endl << endl;
    for (margin = 0; margin <= 14; margin++)
        cout << ' ';
    for (int i = 0; i < 36; i++)
        cout << '*';
    
    cout << endl;
    for (margin = 0; margin <= 20; margin++)
        cout << ' ';
    cout << " ID\tNAME\t    AGE";

    display();

    cout << endl;
    for (margin = 0; margin <= 14; margin++)
        cout << ' ';
    for (int i = 0; i < 36; i++)
        cout << '*';
}

void EmployeeManagement :: display() {
    cout << endl;
    for (margin = 0; margin <= 21; margin++)
        cout << ' ';
    cout.width(4); cout << left << id;
    cout << "    ";
    cout.width(10); cout << left << name;
    cout << "    ";
    cout.width(3); cout << right << age;
}

bool checkEntry(string n) {
    int i = 0;
    while (earr[i].id != -1) {
        if (earr[i].name == n)
            return true;
        i++;
    }
    return false;
}

bool checkEntryDepartment(string n) {
    int i = 0;
    while (darr[i].id != -1) {
        if (darr[i].name == n)
            return true;
        i++;
    }
    return false;
}

void menu()
{
    int ch = -1;
    string str[13] = { "Enter \'1\': ADD EMPLOYEE", "Enter \'2\': EDIT EMPLOYEE", "Enter \'3\': DELETE EMPLOYEE", "Enter \'4\': DISPLAY EMPLOYEES", "Enter \'5\': SEARCH EMPLOYEE",
                       "Enter \'6\': SORT EMPLOYEE", "Enter \'7\': ADD DEPARTMENT", "Enter \'8\': EDIT DEPARTMENT", "Enter \'9\': DELETE DEPARTMENT",
                       "Enter \'10\': DISPLAY DEPARTMENT", "Enter \'11\': SEARCH DEPARTMENT", "Enter \'12\': SORT DEPARTMENT", "Enter \'13\': EXIT PROGRAM" };
    earr[0].id = -1;
    darr[0].id = -1;
    
    do
    {
        system("cls");
        cout << endl;

        for (margin = 0; margin <= 14; margin++)
            cout << ' ';
        for (int i = 0; i < 5; i++)
            cout << '>';
        cout << " EMPLOYEE MANAGEMENT SYSTEM ";
        for (int i = 0; i < 5; i++)
            cout << '<';

        cout << endl << endl;
        for (int j = 0; j < 13; j++) {
            for (margin = 0; margin <= 14; margin++)
                cout << ' ';
            for (int i = 0; i < 38; i++)
                cout << '*';
            
            cout << endl;
            for (margin = 0; margin <= 20; margin++)
                cout << ' ';

            cout << str[j];
            cout << endl;
        }

        for (margin = 0; margin <= 14; margin++)
            cout << ' ';
        for (int i = 0; i < 38; i++)
            cout << '*';

        cout << endl << endl;
        for (margin = 0; margin <= 20; margin++)
            cout << ' ';

        cout << "Select: ";
        cin >> ch;

        switch (ch) {
        case 1: { //ADD EMPLOYEE;
            system("cls");
            cout << "\n\n\n";

            int i = 0;
            while (earr[i].id != -1)
                i++;

            earr[i].create();
            earr[i + 1].id = -1;

            break;
        }

        case 2: { //EDIT EMPLOYEE;
            system("cls");
            cout << "\n\n\n";

            if (earr[0].id == -1) {
                for (margin = 0; margin <= 14; margin++)
                    cout << ' ';
                cout << "There is no record...";
                system("pause > nul");
                break;
            }

            int edit;
            for (margin = 0; margin <= 14; margin++)
                cout << ' ';
            cout << "Enter ID to be edited: ";
            cin >> edit;

            int i = 0;
            while (earr[i].id != -1)
                i++;

            if (edit >= i || edit < 0) {
                cout << "\n\n\n";
                for (margin = 0; margin <= 14; margin++)
                    cout << ' ';
                cout << "ID not found...";
                system("pause > nul");
                break;
            }

            earr[edit].edit();

            break;
        }

        case 3: { //DELETE EMPLOYEE;
            system("cls");
            cout << "\n\n\n";

            if (earr[0].id == -1) {
                for (margin = 0; margin <= 14; margin++)
                    cout << ' ';
                cout << "There is no record...";
                system("pause > nul");
                break;
            }

            int del;
            for (margin = 0; margin <= 14; margin++)
                cout << ' ';
            cout << "Enter ID to be deleted: ";
            cin >> del;

            int i = 0;
            while (earr[i].id != -1)
                i++;

            if (del >= i || del < 0) {
                cout << "\n\n\n";
                for (margin = 0; margin <= 14; margin++)
                    cout << ' ';
                cout << "ID not found...";
                system("pause > nul");
                break;
            }

            earr[del].del();

            cout << "\n\n\n\tPress any key to continue!";
            system("pause > nul");

            // Perform Deletion
            i = del;
            while (earr[i].id != -1) {
                earr[i] = earr[i + 1];
                i++;
            }

            earr[i].id = -1;

            break;
        }

        case 4: { //DISPLAY EMPLOYEES;
            system("cls");
            cout << "\n\n\n";

            if (earr[0].id == -1) {
                for (margin = 0; margin <= 14; margin++)
                    cout << ' ';
                cout << "There is no record...";
                system("pause > nul");
                break;
            }

            int len = 0;
            while (earr[len].id != -1)
                len++;

            int i = 0;
            char next;
            while (i < len) {
                for (margin = 0; margin <= 14; margin++)
                    cout << ' ';
                for (int j = 0; j < 7; j++)
                    cout << '>';
                cout << " RECORDS OF EMPLOYEES ";
                for (int j = 0; j < 7; j++)
                    cout << '<';

                cout << endl << endl;
                for (margin = 0; margin <= 14; margin++)
                    cout << ' ';
                for (int j = 0; j < 36; j++)
                    cout << '*';
                
                cout << endl;
                for (margin = 0; margin <= 20; margin++)
                    cout << ' ';
                cout << " ID\tNAME\t    AGE";

                for (int j = 1; i < len && j <= 5; j++, i++)
                    earr[i].display();

                cout << endl;
                for (margin = 0; margin <= 14; margin++)
                    cout << ' ';
                for (int j = 0; j < 36; j++)
                    cout << '*';

                if (earr[i].id != -1 && i % 5 == 0) {
                    cout << "\n\n\n\tPress \'n\' to continue showing records: ";
                    cin >> next;
                    if (next == 'n' || next == 'N') {
                        system("cls");
                        cout << "\n\n\n";
                        continue;
                    }
                    else
                        break;
                }

                else if (earr[i].id == -1) {
                    cout << "\n\n\n\tPress any key to continue!";
                    system("pause > nul");
                }

                else
                    continue;
            }

            break;
        }

        case 5: { //SEARCH EMPLOYEE
            system("cls");
            cout << "\n\n\n";

            if (earr[0].id == -1) {
                for (margin = 0; margin <= 14; margin++)
                    cout << ' ';
                cout << "There is no record...";
                system("pause > nul");
                break;
            }

            string n;
            for (margin = 0; margin <= 14; margin++)
                cout << ' ';
            cout << "Enter EMPLOYEE NAME to search for record: ";
            cin >> n;

            system("cls");
            cout << "\n\n\n";

            int result = search(earr, n);
            if (result == -1) {
                for (margin = 0; margin <= 14; margin++)
                    cout << ' ';
                cout << "ID not found...";
                system("pause > nul");
            }

            else {
                for (margin = 0; margin <= 14; margin++)
                    cout << ' ';
                for (int i = 0; i < 5; i++)
                    cout << '>';
                cout << " FOUNDED RECORD OF EMPLOYEE ";
                for (int i = 0; i < 5; i++)
                    cout << '<';

                cout << endl << endl;
                for (margin = 0; margin <= 14; margin++)
                    cout << ' ';
                for (int i = 0; i < 36; i++)
                    cout << '*';

                cout << endl;
                for (margin = 0; margin <= 20; margin++)
                    cout << ' ';
                cout << " ID\tNAME\t    AGE";

                earr[result].display();

                cout << endl;
                for (margin = 0; margin <= 14; margin++)
                    cout << ' ';
                for (int i = 0; i < 36; i++)
                    cout << '*';
            }

            break;
        }
              
        case 6: { //SORT EMPLOYEE
            system("cls");
            cout << "\n\n\n";

            if (earr[0].id == -1) {
                for (margin = 0; margin <= 14; margin++)
                    cout << ' ';
                cout << "There is no record...";
                system("pause > nul");
                break;
            }

            int len = 0;
            while (earr[len].id != -1)
                len++;

            sort(earr, len);

            int i = 0;
            char next;
            while (i < len) {
                for (margin = 0; margin <= 14; margin++)
                    cout << ' ';
                for (int j = 0; j < 7; j++)
                    cout << '>';
                cout << " RECORDS OF EMPLOYEES ";
                for (int j = 0; j < 7; j++)
                    cout << '<';

                cout << endl << endl;
                for (margin = 0; margin <= 14; margin++)
                    cout << ' ';
                for (int j = 0; j < 36; j++)
                    cout << '*';

                cout << endl;
                for (margin = 0; margin <= 20; margin++)
                    cout << ' ';
                cout << " ID\tNAME\t    AGE";

                for (int j = 1; i < len && j <= 5; j++, i++)
                    earr[i].display();

                cout << endl;
                for (margin = 0; margin <= 14; margin++)
                    cout << ' ';
                for (int j = 0; j < 36; j++)
                    cout << '*';

                if (earr[i].id != -1 && i % 5 == 0) {
                    cout << "\n\n\n\tPress \'n\' to continue showing records: ";
                    cin >> next;
                    if (next == 'n' || next == 'N') {
                        system("cls");
                        cout << "\n\n\n";
                        continue;
                    }
                    else
                        break;
                }

                else if (earr[i].id == -1) {
                    cout << "\n\n\n\tPress any key to continue!";
                    system("pause > nul");
                }

                else
                    continue;
            }

            break;
        }

        case 7: { //ADD DEPARTMENT;
            system("cls");
            cout << "\n\n\n";

            int i = 0;
            while (darr[i].id != -1)
                i++;

            darr[i].create();
            darr[i + 1].id = -1;

            break;
        }

        case 8: { //EDIT DEPARTMENT;
            system("cls");
            cout << "\n\n\n";

            if (darr[0].id == -1) {
                for (margin = 0; margin <= 14; margin++)
                    cout << ' ';
                cout << "There is no record...";
                system("pause > nul");
                break;
            }

            int edit;
            for (margin = 0; margin <= 14; margin++)
                cout << ' ';
            cout << "Enter ID to be edited: ";
            cin >> edit;

            int i = 0;
            while (darr[i].id != -1)
                i++;

            if (edit >= i || edit < 0) {
                cout << "\n\n\n";
                for (margin = 0; margin <= 14; margin++)
                    cout << ' ';
                cout << "ID not found...";
                system("pause > nul");
                break;
            }

            darr[edit].edit();

            break;
        }

        case 9: { //DELETE DEPARTMENT;
            system("cls");
            cout << "\n\n\n";

            if (darr[0].id == -1) {
                for (margin = 0; margin <= 14; margin++)
                    cout << ' ';
                cout << "There is no record...";
                system("pause > nul");
                break;
            }

            int del;
            for (margin = 0; margin <= 14; margin++)
                cout << ' ';
            cout << "Enter ID to be deleted: ";
            cin >> del;

            int i = 0;
            while (darr[i].id != -1)
                i++;

            if (del >= i || del < 0) {
                cout << "\n\n\n";
                for (margin = 0; margin <= 14; margin++)
                    cout << ' ';
                cout << "ID not found...";
                system("pause > nul");
                break;
            }

            darr[del].del();

            cout << "\n\n\n\tPress any key to continue!";
            system("pause > nul");

            // Perform Deletion
            i = del;
            while (darr[i].id != -1) {
                darr[i] = darr[i + 1];
                i++;
            }

            darr[i].id = -1;

            break;
        }

        case 10: { //DISPLAY DEPARTMENTS;
            system("cls");
            cout << "\n\n\n";

            if (darr[0].id == -1) {
                for (margin = 0; margin <= 14; margin++)
                    cout << ' ';
                cout << "There is no record...";
                system("pause > nul");
                break;
            }

            int len = 0;
            while (darr[len].id != -1)
                len++;

            int i = 0;
            char next;
            while (i < len) {
                for (margin = 0; margin <= 14; margin++)
                    cout << ' ';
                for (int j = 0; j < 6; j++)
                    cout << '>';
                cout << " RECORDS OF DEPARTMENTS ";
                for (int j = 0; j < 6; j++)
                    cout << '<';

                cout << endl << endl;
                for (margin = 0; margin <= 14; margin++)
                    cout << ' ';
                for (int j = 0; j < 36; j++)
                    cout << '*';

                cout << endl;
                for (margin = 0; margin <= 18; margin++)
                    cout << ' ';
                cout << " ID\t      DEPARTMENT NAME";

                for (int j = 1; i < len && j <= 5; j++, i++)
                    darr[i].display();

                cout << endl;
                for (margin = 0; margin <= 14; margin++)
                    cout << ' ';
                for (int j = 0; j < 36; j++)
                    cout << '*';

                if (darr[i].id != -1 && i % 5 == 0) {
                    cout << "\n\n\n\tPress \'n\' to continue showing records: ";
                    cin >> next;
                    if (next == 'n' || next == 'N') {
                        system("cls");
                        cout << "\n\n\n";
                        continue;
                    }
                    else
                        break;
                }

                else if (darr[i].id == -1) {
                    cout << "\n\n\n\tPress any key to continue!";
                    system("pause > nul");
                }

                else
                    continue;
            }

            break;
        }

        case 11: { //SEARCH DEPARTMENT
            system("cls");
            cout << "\n\n\n";

            if (darr[0].id == -1) {
                for (margin = 0; margin <= 14; margin++)
                    cout << ' ';
                cout << "There is no record...";
                system("pause > nul");
                break;
            }

            string n;
            for (margin = 0; margin <= 14; margin++)
                cout << ' ';
            cout << "Enter DEPARTMENT NAME to search for record: ";
            cin >> n;

            system("cls");
            cout << "\n\n\n";

            int result = search(darr, n);
            if (result == -1) {
                for (margin = 0; margin <= 14; margin++)
                    cout << ' ';
                cout << "ID not found...";
                system("pause > nul");
            }

            else {
                for (margin = 0; margin <= 14; margin++)
                    cout << ' ';
                for (int i = 0; i < 5; i++)
                    cout << '>';
                cout << " FOUNDED RECORD OF DEPARTMENT ";
                for (int i = 0; i < 5; i++)
                    cout << '<';

                cout << endl << endl;
                for (margin = 0; margin <= 14; margin++)
                    cout << ' ';
                for (int i = 0; i < 36; i++)
                    cout << '*';

                cout << endl;
                for (margin = 0; margin <= 20; margin++)
                    cout << ' ';
                cout << " ID\t      DEPARTMENT NAME";

                darr[result].display();

                cout << endl;
                for (margin = 0; margin <= 14; margin++)
                    cout << ' ';
                for (int i = 0; i < 36; i++)
                    cout << '*';
            }

            break;
        }

        case 12: { //SORT DEPARTMENT
            system("cls");
            cout << "\n\n\n";

            if (darr[0].id == -1) {
                for (margin = 0; margin <= 14; margin++)
                    cout << ' ';
                cout << "There is no record...";
                system("pause > nul");
                break;
            }

            int len = 0;
            while (darr[len].id != -1)
                len++;

            sort(darr, len);

            int i = 0;
            char next;
            while (i < len) {
                for (margin = 0; margin <= 14; margin++)
                    cout << ' ';
                for (int j = 0; j < 7; j++)
                    cout << '>';
                cout << " RECORDS OF DEPARTMENTS ";
                for (int j = 0; j < 7; j++)
                    cout << '<';

                cout << endl << endl;
                for (margin = 0; margin <= 14; margin++)
                    cout << ' ';
                for (int j = 0; j < 36; j++)
                    cout << '*';

                cout << endl;
                for (margin = 0; margin <= 20; margin++)
                    cout << ' ';
                cout << " ID\t      DEPARTMENT NAME";

                for (int j = 1; i < len && j <= 5; j++, i++)
                    darr[i].display();

                cout << endl;
                for (margin = 0; margin <= 14; margin++)
                    cout << ' ';
                for (int j = 0; j < 36; j++)
                    cout << '*';

                if (darr[i].id != -1 && i % 5 == 0) {
                    cout << "\n\n\n\tPress \'n\' to continue showing records: ";
                    cin >> next;
                    if (next == 'n' || next == 'N') {
                        system("cls");
                        cout << "\n\n\n";
                        continue;
                    }
                    else
                        break;
                }

                else if (darr[i].id == -1) {
                    cout << "\n\n\n\tPress any key to continue!";
                    system("pause > nul");
                }

                else
                    continue;
            }

            break;
        }

        case 13: {//EXIT PROGRAM
            cout << "\n\nProgram ended!!\n\n";
            break;
        }

        default: cout << "\n\n\tWrong Choice!!\n\tPress Any Key to Try Again";
            system("pause > nul");
        }
    } while (ch != 'x' && ch != 'X');

}

int main() {
    menu();
    return 0;
}