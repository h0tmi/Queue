#include <iostream>

using namespace std;

class Node {
 public:
  int key;
  int data;
  Node *next;

  Node() {
    key = 0;
    data = 0;
    next = NULL;
  }
  Node(int k, int d) {
    key = k;
    data = d;
    next = NULL;
  }
};

class Queue {
 public:
  Node *front;
  Node *rear;

  Queue() {
    front = rear = NULL;
  }

  bool isEmpty();
  bool CheckIfNodeExist(Node *);
  void Enqueue(Node *);
  void Display();
  Node *Dequeue();
  int count();
};

bool Queue::isEmpty() {
  if (front == NULL && rear == NULL) {
    return true;
  } else {
    return false;
  }
}

bool Queue::CheckIfNodeExist(Node *n) {
  Node *temp = front;
  bool exist = false;

  while (temp != NULL) {
    if (temp->key == n->key) {
      exist = true;
      break;
    }
  }
}

void Queue::Enqueue(Node *n) {
  if (isEmpty()) {
    front = n;
    rear = n;
    cout << "Node enqueued successfully\n";
  } else if (CheckIfNodeExist(n)) {
    cout << "Node already with this key exist" << "\n"
         << "Enter different key value\n";
  } else {
    rear->next = n;
    rear = n;
    cout << "Node enqueued successfully\n";
  }
}

Node *Queue::Dequeue() {
  Node *temp = NULL;
  if (isEmpty()) {
    cout << "Queue is empty\n";
    return NULL;
  } else {
    if (front == rear) {
      temp = front;
      front = NULL;
      rear = NULL;
      return temp;
    } else {
      temp = front;
      front = front->next;
      return temp;
    }
  }
}

int Queue::count() {
  int count = 0;
  Node *temp = front;
  while (temp != NULL) {
    count++;
    temp = temp->next;
  }
  return count;
}

void Queue::Display() {
  if (isEmpty()) {
    cout << "Queue is empty\n";
  } else {
    Node *temp = front;
    while (temp != NULL) {
      cout << temp->key << " : " << temp->data << "; ";
      temp = temp->next;
    }
    cout << "\n";
  }
}

int main() {
  Queue q;
  int option, key, data;

  do {
    cout << "What operation do you want to perform?"
         << "Select Option number. Enter 0 to exit." << "\n";
    cout << "1. Enqueue()" << "\n";
    cout << "2. Dequeue()" << "\n";
    cout << "3. isEmpty()" << "\n";
    cout << "4. count()" << "\n";
    cout << "5. display()" << "\n";
    cout << "6. Clear Screen" << "\n" << "\n";
    cin >> option;

    //Node n1 = new Node();
    Node *new_node = new Node();

    switch (option) {
      case 0:break;
      case 1:cout << "ENQUEUE Function Called -" << "\n";
        cout << "Enter KEY and VALUE of NODE to ENQUEUE "
             << "in the Queue"
             << "\n";
        cin >> key;
        cin >> data;
        new_node->key = key;
        new_node->data = data;
        q.Enqueue(new_node);
        break;
      case 2:cout << "DEQUEUE Function Called - " << "\n";
        new_node = q.Dequeue();
        cout << "Dequeued Value is: (" << new_node->key << ","
             << new_node->data << ")";
        delete new_node;
        cout << "\n";

        break;
      case 3:cout << "isEmpty Function Called - " << "\n";
        if (q.isEmpty())
          cout << "Queue is Empty" << "\n";
        else
          cout << "Queue is NOT Empty" << "\n";
        break;
      case 4:cout << "Count Function Called - " << "\n";
        cout << "No of nodes in the Queue: " << q.count()
             << "\n";
        break;
      case 5:cout << "Display Function Called - " << "\n";
        q.Display();
        cout << "\n";
        break;

      case 6:system("cls");
        break;
      default:cout << "Enter Proper Option number " << "\n";
    }

  } while (option != 0);

  return 0;
}
