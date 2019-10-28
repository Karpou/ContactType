#include <iostream>
#include <string>
#include<stdlib.h>
#include<stdio.h>
using namespace std;
struct node
{
    string firstName;
    string lastName;
    string phone;
    string mail;
    node *next;
};
class List
{
private:
    node *head, *tail;
public:
    List()
    {
        head = NULL;
        tail = NULL;
    }
    void sortInserted(struct node** head_ref, struct node* new_node)
    {
        struct node* current;
        if (*head_ref == NULL || (*head_ref)-> lastName >= new_node->lastName)
        {
            new_node->next = *head_ref;
            *head_ref = new_node;
        }
        else
        {
            current = *head_ref;
            while(current->next!=NULL && current->next->lastName < new_node->lastName)
            {
                current = current->next;
            }
            new_node->next=current->next;
            current->next = new_node;
        }
    }
    void create_contact(string first, string last, string number, string email) // Create node and add it onto the linked list
    {
        node *temp = new node;
        temp->firstName = first;
        temp->lastName = last;
        temp->phone = number;
        temp->mail = email;
        temp->next = NULL;
        sortInserted(&head, temp);
    }
    void display_all()
    {
        int contactNum = 1;
        node *temp = new node;
        temp = head;
        while (temp != NULL)    // Loop through the list while the temporary node is not empty
        {
            cout << "\nContact Number: " << contactNum << endl;
            cout << "First Name: " << temp->firstName << endl;
            cout << "Last Name: " << temp->lastName << endl;
            cout << "Phone Number: " << temp->phone << endl;
            cout << "E-mail Address: " << temp->mail << endl;
            ++contactNum;
            temp = temp->next;
        }
    }
    void delete_position(int pos)   // delete a stop by using the position in the list
    {
        node *current = new node;
        node *previous = new node;
        node *next = new node;
        current = head;
        for (int i = 1;i<pos;i++)   // Loop through the link list while the current node is not empty
        {
            if (current == NULL)
                return;
            previous = current;
            current = current->next;
        }
        next = current->next;
        previous->next = current->next;
        delete current;
    }
    void delete_head()  // delete head node
    {
        node *temp = new node;
        temp = head;
        head = head->next;
        delete temp;
    }
    void search(string title)
    {
        bool found;
        node *temp = head;
        found = false;
        while (temp != NULL && !found)
        {
            if (temp->lastName == title)
            {
                found = true;
            }
            else
            {
                temp = temp->next;
            }
        }
        if (found)
        {
            cout <<"\n" << title << "was found.\n";
            cout << "First Name:" << temp->firstName <<"\n";
            cout << "Last Name:" << temp->lastName <<"\n";
            cout << "Phone Number:" << temp->phone <<"\n";
            cout << "Email:" << temp->mail <<"\n";
        }
        else
        {
            cout << title << " was not found.";
        }
    }
    void display_contact(string first, string last)
    {
        bool found;
        node *temp = head;
        found = false;
        int dude = -1;
        while (temp != NULL && !found)
        {
            if (temp->firstName == first && temp->lastName == last)
            {
                dude++;
                found = true;
            }
            else
            {
                temp = temp->next;
            }
        }
        if (found)
        {
            cout << "First Name: " << temp->firstName << "\n";
            cout << "Last Name: " << temp->lastName << "\n";
            cout << "Phone Number: " << temp->phone << "\n";
            cout << "Email Address:" << temp->mail<< "\n";
            delete_position(dude);
        }
        else
        {
            cout << "\n" << first << " " << last << " was not found.\n";
            cout << "please enter a valid first and last name.";
            cin >> first;
            cin >> last;
        }
    }
};
int main()

{
    List Contacts; // create a Contacts item for the List class
    int choice, position;
    string firstName;
    string lastName;
    string phone;
    string mail;
    while (1) {
        cout << "\nWhat would you like to do?: " << endl;
        cout << "1. Show All Contacts" << endl;
        cout << "2. Add A Contact" << endl;
        cout << "3. Remove A Contact" << endl;
        cout << "4. Search Contacts" << endl;
        cout << "5. Update A Contact" << endl;
        cout << "6. Exit The Program" << endl;
        cin >> choice;
        switch (choice)
        {
            case 1:
                Contacts.display_all();
                cout << endl;
                break;
            case 2:
                cout << "\nEnter your first name: ";
                cin >> firstName;
                cout << "\nEnter your last name: ";
                cin >> lastName;
                cout<<"\nEnter your phone number:";
                cin >> phone;
                cout<<"\nEnter your e-mail address:";
                cin >> mail;
                Contacts.create_contact(firstName, lastName, phone, mail); // create the contact in the linked list
                cout << endl;
                break;
            case 3:
                cout << "Enter the contact number of the contact you would like to remove: ";
                cin >> position;
                if (position == 1)
                    Contacts.delete_head();
                else
                    Contacts.delete_position(position); // delete contact from list
                break;
            case 4:
                cout << "Please enter the Last Name of the contact you would like to search";
                cin >> lastName;
                Contacts.search(lastName);
                break;
            case 5:
                cout << "\nTo find the contact you would like to edit: ";
                cout << "\nEnter the contacts' first name: ";
                cin >> firstName;
                cout << "\nEnter the contacts' last name: ";
                cin >> lastName;
                Contacts.display_contact(firstName, lastName);
                cout << "\nEnter the contacts' NEW first name: ";
                cin >> firstName;
                cout << "\nEnter the contacts' NEW last name: ";
                cin >> lastName;
                cout << "\nEnter the contacts' NEW phone number: ";
                cin >> phone;
                cout << "\nEnter the contacts' NEW E-mail";
                cin >> mail;
                Contacts.create_contact(firstName, lastName, phone, mail);
                break;
            case 6:
                exit(1);
                break;
            default:
                cout << "\n" << choice << " is not an option. Please select a valid option." << endl;
                break;
        }
    }
    return 0;
}
