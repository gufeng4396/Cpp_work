#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    Node() : data(0), next(NULL){};
    Node(int a) : data(a), next(NULL){};
};
class list
{
private:
    Node *head;
    int length;
    Node *find_prev_position(int position)
    {
        int i = -1;
        int prev_position = position - 1;
        Node *current = this->head;
        if (prev_position < -1 || prev_position >= this->length)
        {
            cout << "bad_position " << position << endl;
            return NULL;
        }
        while (i < prev_position)
        {
            i++;
            current = current->next;
        };
        return current;
    }

public:
    list()
    {
        head = new Node;
        length = 0;
    }
    void list_menu()
    {
        int choice;
        int position, value;
        enum choices
        {
            append,insert,l_delete,show,node_position,node_value,length,clear,destroy
        };
        while (1)
        {
            cout << "0.apppend element" << endl;
            cout << "1.insert element" << endl;
            cout << "2.delete element" << endl;
            cout << "3.show list element" << endl;
            cout << "4.find the position of element by value" << endl;
            cout << "5.find the value of element by position" << endl;
            cout << "6.the length of list" << endl;
            cout << "7.clear list" << endl;
            cout << "8.destroy list" << endl;
            cout << "enter the number" << endl;
            cin >> choice;
            switch (choice)
            {
            case append:
                cout << "enter the value" << endl;
                cin >> value;
                this->list_append(value);
                break;
            case insert:
                cout << "enter the value" << endl;
                cin >> value;
                cout << "enter the position(0--)" << endl;
                cin >> position;
                this->list_insert(value, position);
                break;
            case l_delete:
                cout << "enter the position(0--)" << endl;
                cin >> position;
                this->list_delete(position);
                break;
            case show:
                this->list_show();
                break;
            case node_position:
                cout << "enter the value" << endl;
                cin >> value;
                this->list_show_node_position(value);
                break;
            case node_value:
                cout << "enter the position(0--)" << endl;
                cin >> position;
                this->list_show_node_value(position);
                break;
            case length:
                this->list_length();
                break;
            case clear:
                list_clear();
                break;
            case destroy:
                list_destroy();
                break;
            default:
                cout << "wrong enter" << endl;
                cin.sync();
            }
        }
    }
    void list_append(int value)
    {
        Node *temp = new Node(value);
        Node *current = this->find_prev_position(this->length);
        current->next = temp;
        this->length++;
        return;
    }
    void list_insert(int value, int position)
    {
        Node *temp = new Node(value);
        Node *current = this->find_prev_position(position);
        if (current == NULL)
        {
            delete temp;
            return;
        }
        else
        {
            temp->next = current->next;
            current->next = temp;
            this->length++;
        }
        return;
    }
    void list_delete(int position)
    {
        Node *current = this->find_prev_position(position);
        if (current == NULL || current->next == NULL)
        {
            if (current)
                cout << "bad_position " << position << endl;
            return;
        }
        else
        {
            Node *temp = current->next;
            current->next = current->next->next;
            delete temp;
            this->length--;
        }
        return;
    }
    void list_show()
    {
        Node *current = this->head->next;
        if (current == NULL)
        {
            cout << "no data" << endl;
            return;
        }
        cout << "list is  ";
        while (current)
        {
            cout << "->" << current->data;
            current = current->next;
        }
        cout << endl;
        return;
    }
    void list_show_node_value(int position)
    {
        Node *current = this->find_prev_position(position);
        if (current == NULL || current->next == NULL)
        {
            if (current)
                cout << "bad_position " << position << endl;
            return;
        }
        else
            cout << " value " << current->next->data << endl;
        return;
    }
    void list_show_node_position(int value)
    {
        bool flag = false;
        Node *current = this->head->next;
        int position = 0;
        while (current)
        {
            if (current->data == value){
                cout << " position " << position;
                flag = true;
            }
            current = current->next;
            position++;
        }
        if (!flag)
            cout << "no such value" << endl;
        cout << endl;
        return;
    }
    void list_length()
    {
        cout << "length " << this->length << endl;
    }
    void list_clear()
    {
        Node *current = this->head->next;
        Node *temp = current;
        this->head->next = NULL;
        while (current)
        {
            current = current->next;
            delete temp;
            temp = current;
        }
        length = 0;
        return;
    }
    void list_destroy()
    {
        this->list_clear();
        delete this->head;
        exit(1);
    }
    ~list(){
        this->list_destroy();
    }
};
int main()
{
    list a;
    a.list_menu();
}