#include <iostream>
using namespace std;

// Define a structure for the nodes in the linked list
struct Node {
    int data; // The data stored in the node
    Node* next; // Pointer to the next node in the list
};


// Initialize the head of the list to NULL
Node* head = NULL;


// Function to insert a new node at the beginning of the list
void insert_begin(int d) {
    // Create a new node
    Node* newNode = new Node();
    // Set the data of the new node
    newNode->data = d;
    // Set the next pointer of the new node to the current head of the list
    newNode->next = head;
    // Set the head of the list to the new node
    head = newNode;
}


// Function to insert a new node at the end of the list
void insert_end(int d) {
    // Create a new node
    Node* newNode = new Node();
    // Set the data of the new node
    newNode->data = d;
    // Set the next pointer of the new node to NULL (since it will be the last node)
    newNode->next = NULL;

    // If the list is empty (i.e., head is NULL), make the new node the head
    if(head == NULL) {
        head = newNode;
    } else {
        // If the list is not empty, traverse to the end of the list
        
		// Initialize a pointer to the head of the list
        Node* last = head;
        // Traverse the list until the last node is reached
// The last node is identified by its 'next' pointer being NULL
        while(last->next != NULL) {
        	// Move to the next node in the list
            last = last->next;
        }
        // Make the new node the next node of the last node
        last->next = newNode;
    }
}


void insert_at(int d, int p) {
    // Create a new node
    Node* newNode = new Node();
    // Set the data of the new node to 'd'
    newNode->data = d;
    // Initialize the 'next' pointer of the new node to NULL
    newNode->next = NULL;

    // If the position 'p' is 0
    if(p == 0) {
        // Insert the new node at the beginning of the list
        newNode->next = head;
        head = newNode;
    } else {
        // If the position 'p' is not 0
        // Create a temporary node and initialize it to the head of the list
        Node* temp = head;
        // Traverse the list until reaching the node just before the position 'p'
        for(int i = 1; temp != NULL && i < p - 1; i++) {
            temp = temp->next;
        }
        // If the position 'p' is valid
        if(temp != NULL) {
            // Insert the new node at position 'p'
            newNode->next = temp->next;
            temp->next = newNode;
        }
    }
}


// Function to delete first node at the beginning of the list
void delete_begin() {
    // Check if the list is not empty
    if(head != NULL) {
        // Create a temporary node pointer and point it to the head of the list
        Node* temp = head;
        // Move the head pointer to the next node in the list
        head = head->next;
        // Delete the node that was originally at the beginning of the list
        delete temp;
    }
}


// Function to delete the last node of a linked list
void delete_end() {
    // Check if the list is not empty
    if(head != NULL) {
        // If the head is the only node in the list
        if(head->next == NULL) {
            // Delete the head and set it to null
            delete head;
            head = NULL;
        } else {
            // Create a temporary node pointer and point it to the head of the list
            Node* temp = head;
            // Traverse the list until temp points to the second-to-last node
            while(temp->next->next != NULL) {
                temp = temp->next;
            }
            // Delete the last node
            delete temp->next;
            // Set the next of the new last node to null
            temp->next = NULL;
        }
    }
}



// Function to delete a node at a specific position in the linked list
void delete_at(int p) {
    // Check if the list is not empty
    if (head != NULL) {
        // If the position is 0, delete the first node (similar to delete_begin)
        if (p == 0) {
            Node* temp = head;
            head = head->next;
            delete temp;
        } else {
            // If the position is not 0
            // Create a temporary node pointer and point it to the head of the list
            Node* temp = head;
            // Traverse the list until reaching the node just before the position 'p'
            for (int i = 1; temp != NULL && i < p - 1; i++) {
                temp = temp->next;
            }
            // If the position 'p' is valid
            if (temp != NULL && temp->next != NULL) {
                Node* nodeToDelete = temp->next; // Store the node to be deleted
                temp->next = temp->next->next; // Link the previous node to the node after the deleted node
                delete nodeToDelete; // Delete the node
            } else {
                // If the position is invalid
                cout << "Invalid position. Node not found at position " << p << endl;
            }
        }
    }
}


//function to delete specific data
void delete_data(int d) {
    // Check if the list is not empty
    if(head != NULL) {
        // If the head node is the one to be deleted
        if(head->data == d) {
            Node* temp = head; // Temporary pointer to the head node
            head = head->next; // Move the head pointer to the next node
            delete temp; // Delete the old head node
        } else {
            // If the node to be deleted is not the head node
            Node* temp = head; // Start from the head node
            // Traverse the list until we find the node to be deleted or reach the end of the list
            while(temp->next != NULL && temp->next->data != d) {
                temp = temp->next;
            }
            // If the node to be deleted was found in the list
            if(temp->next != NULL) {
                Node* nextNode = temp->next->next; // Store the node next to the one to be deleted
                delete temp->next; // Delete the node
                temp->next = nextNode; // Link the previous node to the node after the deleted node
            }
        }
    }
}


// Function to search a node in a linked list
Node* search(int d) {
    // Start from the head node
    Node* temp = head;

    // Traverse the list until you find the node or reach the end
    while(temp != NULL) {
        // If the node is found, return it
        if(temp->data == d) {
            return temp;
        }
        // Move to the next node
        temp = temp->next;
    }

    // If the node was not found, return NULL
    return NULL;
}


//traverse () function is used to display the elements in the linked list .
//naming traverse function as display
// Function to display the list
void display() {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}


// Function to display the menu
void displayMenu() {
    cout << "Linked List Operations Menu:" << endl;
    cout << "1. Insert at the beginning" << endl;
    cout << "2. Insert at the end" << endl;
    cout << "3. Insert at a specific position" << endl;
    cout << "4. Delete at the beginning" << endl;
    cout << "5. Delete at the end" << endl;
    cout << "6. Delete at a specific position" << endl;
    cout << "7. Delete a specific value" << endl;
    cout << "8. Search for a node" << endl;
    cout << "9. Display the linked list" << endl;
    cout << "10. Exit" << endl;
}


int main() {
    int choice;
    
    do {
        // Display the menu to the user
        displayMenu();
        
        // Prompt the user to enter their choice
        cout << "Enter your choice: ";
        cin >> choice;

        // Perform the operation based on the user's choice
        switch (choice) {
            case 1: {
                int data;
                cout << "Enter data to insert at the beginning: ";
                cin >> data;
                insert_begin(data);
                break;
            }
            case 2: {
                int data;
                cout << "Enter data to insert at the end: ";
                cin >> data;
                insert_end(data);
                break;
            }
            case 3: {
                int data, position;
                cout << "Enter data to insert: ";
                cin >> data;
                cout << "Enter position to insert at: ";
                cin >> position;
                insert_at(data, position);
                break;
            }
            case 4:
                delete_begin();
                break;
            case 5:
                delete_end();
                break;
            case 6: {
                int position;
                cout << "Enter position to delete at: ";
                cin >> position;
                delete_at(position);
                break;
            }   
            case 7: {
                int data;
                cout << "Enter data to delete: ";
                cin >> data;
                delete_data(data);
                break;
            }
            case 8: {
                int data;
                cout << "Enter data to search: ";
                cin >> data; 
                Node* result = search(data);
                if (result != NULL) {
                    cout << "Node found with data: " << result->data << endl;
                } else {
                    cout << "Node not found." << endl;
                }
                break;
            }
            case 9:
                display();
                break;
            case 10:
                cout << "Exiting the program." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
        
        cout << endl;
    } while (choice != 10);

    return 0;
}

