#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;
// creating a structure which will hold all the student records.
struct StudentRecord
{
    string firstName;
    string lastName;
    int oduUin;
    string dateOfBirth;
    double gpa;
    StudentRecord *next;
    StudentRecord *prev;
};
StudentRecord *head = NULL;

void free_list()
{
    // We will create a current node and assign head to it, then we will iterate the node through the linked list and delete all the records stored in the linked list
    StudentRecord *current = head;
    while(current!=NULL) // as I am considering tail->next = NULL
    {
        head->next = current->next;
        current->next = NULL;
        free(current);
        current = head->next;
    }

    head = NULL;
}


void display_data()
{
    cout << endl << endl << "Listing all student records: " << endl;
    cout << "---------------------------" << endl;
// We will create a node named start and will iterate it through the whole linked list and display the data
    StudentRecord *start = head;
    if (!start)
    {
        cout << "No Data!" << endl;
        return;
    }
    while(start)
    {
        cout << start -> firstName << endl;
        cout << start -> lastName << endl;
        cout << start -> oduUin << endl;
        cout << start -> dateOfBirth << endl;
        cout << start -> gpa << endl << endl;
        start = start -> next;
    }
}



StudentRecord *get_data()
{
    //creating a temporary node in which we will store all the student records and return the temporary node in the end of the function
    StudentRecord *rec = new StudentRecord;
    cout << endl;
    cout << "You chose option #1." << endl;
    cout << "What is the student's first name?: ";
    cin >> rec->firstName;
    cout << "What is the student's last name?: ";
    cin >> rec->lastName;
    cout << "What is the student's uin?: ";
    cin >> rec->oduUin;
    cout << "What is the student's date of birth?: ";
    cin >> rec->dateOfBirth;
    cout << "What is the student's GPA?: ";
    cin >> rec->gpa;
    rec->next = head;
    rec->prev = NULL;
    return rec;
}

void add_data(StudentRecord *current)
{
// We will store the address of the present head node in the next field of the current node and later we will make the current node as head node
    if(head == NULL){
        current->next = NULL;
        current->prev = NULL;
    }
    else{
        current->next=head;  // store the address of the pointer head(second field)
        current->prev=NULL;
        head->prev=current;
    }
    head = current;
}

void search(double key)
{
    // We will iterate the head through the linked list until it finds the required variable or until the end of linked list
    StudentRecord * temp = head;
    while (head != NULL)
    {
        if (head->oduUin == key)
        {
            cout<<"key found"<<endl;
            // cout<<head->uin<<endl;
            cout<<"first name = "<<head->firstName<<endl;
            cout<<"last name = "<<head->lastName<<endl;
            cout<<"date of birth = "<<head->dateOfBirth<<endl;
            cout<<"gpa = "<<head->gpa<<endl;
            return;
        }
        temp = temp->next;
    }
    cout<<"Key not found"<<endl;
}

void insert_at(){
    StudentRecord * before = head;
    StudentRecord * after = head;
    StudentRecord * current = get_data();
    int pos = 0;
    int cnt = 0;
    cout << "Enter the new position to insert: ";
    cin >> pos;
    if(pos==0){
        add_data(current);
        return;
    }
    else {
        while(after != NULL){
            cnt++;
            after=after->next;
        }
        if(pos >= cnt){
            cout << "Position is beyond the scope of this list." << endl;
            return;
        }
        cnt=0;
        while(before != NULL){
            if(cnt == (pos-1)){
                after = before->next;
                current->next=after;
                current->prev=before;
                before->next = current;
                after->prev = current;
                return;
            }
            before = before->next;
            cnt++;
        }
    }
}


void processMenu()
{
    // creating current node for StudentRecord struct
    StudentRecord *current = NULL;
    int ser;
    char choice = 0;
    while(true)
    {
        cout << endl <<"What would you like to do?" << endl;
        cout <<"==========================" << endl;
        cout << "1. Enter a student record. " << endl;
        cout << "2. List all student records. " << endl;
        cout << "3. Exit program. " <<endl;
        cout << "4. Search. " << endl;
        cout << "5. Insert to Position" << endl;

        cin >> choice;
        while(cin.get() != '\n');
        if(choice == '1')
        {
            current = get_data();
            add_data(current);
        }
        else if(choice == '2')
        {
            display_data();
        }
        else if (choice == '3')
        {
            free_list();
            return;
        }
        else if (choice == '4')
        {
            cout<<"Enter student uin to search for records"<<endl;
            cin>>ser;
            search(ser);
        }
        else if (choice == '5'){
            insert_at();
        }
        else
        {
            cout << "Allowed Selections are 1, 2, and 3!" << endl;
        }
    }
}

int main()
{
    // Program starts execution from main block
    cout << "Student Record Program." << endl << endl;
    processMenu();
// calling process function which inturn calls create and display functions
    system("pause");
    return 0;
}
