#include <iostream>
#include <vector>
using namespace std;

class Node{
  public:
  int data;
  Node* next;

  Node(int data){
    this->data = data;
    this->next = NULL;
  }
};

class List{
  public:
  Node* head;
  Node* tail;
  int listSize;

  List(){
    head = tail = NULL;
    listSize = 0;
  }
  List(vector<int> &arr){
    head = new Node(arr[0]);
    tail = head;
    listSize = arr.size();

    for(int i = 1; i < listSize; i++){
      tail->next = new Node(arr[i]);
      tail = tail->next;
    }
  }

  void insertAtFirst(int data){
    if(head == NULL){
      head = new Node(data);
      tail = head;
    }else{
      Node* temp = new Node(data);
      temp->next = head;
      head = temp;
    }
    listSize++;
  }

  void insertAtLast(int data){
    if(head == NULL){
      head = new Node(data);
      tail = head;
    }else{
      tail->next = new Node(data);
      tail = tail->next;
    }
    listSize++;
  }

  void insert(int data, int position){
    if(position > listSize || position < 0){
      cout<<"Invalid position"<<endl;
      return;
    }
    if(position == 0) return insertAtFirst(data);
    if(position == listSize) return insertAtLast(data);
    Node* temp = head;
    position--;
    while(position--){
      temp = temp->next;
    }
    Node* next = temp->next;
    temp->next = new Node(data);;
    temp->next->next = next;
    listSize++;
  }

  void deleteFirst(){
    if(head == NULL) return;
    Node* temp = head;
    head = temp->next;
    delete temp;
    if(head == NULL) tail = NULL;
  }

  void deleteLast(){
    if(head == NULL) return;
    if(head->next == NULL){
      delete head;
      head = tail = NULL;
      return;
    }

    Node* prev = NULL;
    Node* curr = head;
    while(curr->next){
      prev = curr;
      curr = curr->next;
    }
    prev->next = NULL;
    tail = prev;
    delete curr;
  }

  void deleteNodeAt(int position){
    if(position < 1 || position > listSize){
      cout<<"Invalid position"<<endl;
      return;
    }
    if(position == 1) return deleteFirst();

    Node* prev = NULL;
    Node* curr = head;
    position--;
    while(position--){
      prev = curr;
      curr = curr->next;
    }
    prev->next = curr->next;
    if(curr == tail) tail = prev;

    delete curr;
  }

  int size(){
    return listSize;
  }

  void printList(){
    Node* temp = head;
    while(temp){
      cout<<temp->data<<" ";
      temp = temp->next;
    }cout<<endl;
  }
};


// Node* createList(vector<int> &arr, int i){
//   if(i == arr.size()) return NULL;
//   Node* n = new Node(arr[i]);
//   n->next = createList(arr, i+1);
//   return n;
// }

// Node* createListFirst(vector<int> &arr, int i, Node* temp){
//   if(i == arr.size()){
//     return temp;
//   }

//   Node* curr = new Node(arr[i]);
//   curr->next = temp;
//   return createListFirst(arr, i+1, curr);
// }

Node* deleteOk(Node* head, Node* prev, Node* curr, int position){
  if(position == 1){
    if(prev) prev->next = curr->next;
    else head = curr->next;
    delete curr;
    return head;
  }
  return deleteOk(head, curr, curr->next, position-1);
}

Node* reverse(Node* head){
  if(head == NULL) return head;

  Node* prev = NULL, *curr = head, *next = NULL;
  while(curr){
    next = curr->next;
    curr->next = prev;
    prev = curr;
    curr = next;
  }

  return prev;
}

Node* middle(Node* head){
  Node* fast = head;
  Node* slow = head;

  while(fast->next){
    fast = fast->next;
    slow = slow->next;
    if(fast->next){
      fast = fast->next;
    }
  }

  return slow;
}

Node* rotate(Node* head, int k){
  if(head == NULL || head->next == NULL || k == 0) return head;

  int totalNode = 1;
  Node* temp = head;
  while(temp->next){
    totalNode++;
    temp = temp->next;
  }

  Node* lastNode = temp;

  k = k % totalNode;
  int count = totalNode - k - 1;
  temp = head;
  while(count--){
    temp = temp->next;
  }

  Node* after = temp->next;
  temp->next = NULL;
  lastNode->next = head;
  head = after;
  return head;
}

Node* removeKThNodeFromEnd(Node* head, int k){
  if(!head || !head->next) return NULL;
  int count = 1;
  Node* temp = head;
  while(temp->next){
    count++;
    temp = temp->next;
  }
  k = count - k;
  temp = head;
  Node* prev = NULL;
  while(k--){
    prev = temp;
    temp = temp->next;
  }

  if(!prev) head = head->next;
  else prev->next = temp->next;

  delete temp;
  return head;
}

Node* removeKThNodeFromEnd2(Node* head, int k){
  Node *first = head, *second = head, *prev = NULL;
  k--;
  while(k--){
    second = second->next;
  }

  while(second->next){
    prev = first;
    first = first->next;
    second = second->next;
  }

  if(!prev) head = head->next;
  else prev->next = first->next;

  delete first;
  return head;
}

Node* removeEveryKTHNode(Node* head, int k){
  if(k == 1) return NULL;
  Node* prev = NULL, *curr = head;
  int c = 1;

  while(curr){
    if(c == k){
      prev->next = curr->next;
      delete curr;
      curr = prev->next;
      c = 1;
    }else{
      prev = curr;
      curr = curr->next;
      c++;
    }
  }

  return head;
}

bool isPlaindrome(Node* head){
  Node *prev = NULL, *slow = head, *fast = head;
  while(fast->next){
    prev = slow;
    slow = slow->next;
    fast = fast->next;
    if(fast->next) fast = fast->next;
  }

  prev->next = NULL;
  Node* temp = head;
  Node* temp2 = reverse(slow);

  while(temp){
    if(temp->data != temp2->data) return false;
    temp = temp->next;
    temp2 = temp2->next;
  }

  return true;
}

int main() {
  // vector<int> arr = {4, 3, 9, 10, 45};
  // List* l = new List(arr);
  // l->printList();

  // l->insertAtFirst(10);
  // l->insertAtFirst(20);
  // l->insertAtFirst(30);
  // l->insertAtLast(40);

  // l->insert(60, 0);
  // l->insert(10, 0);
  // l->insert(20, 0);

  // l->insertAtLast(20);
  // l->insertAtFirst(10);
  // l->insertAtFirst(20);
  // l->deleteFirst();
  // l->insertAtFirst(10);
  // l->deleteLast();
  // l->insertAtLast(10);

  // l->deleteNodeAt(4);

  // l->printList();
  // cout<<l->head->data<<endl;
  // cout<<l->tail->data<<endl;

  Node* head = NULL;
  Node* n1 = new Node(10);
  head = n1;
  Node* n2 = new Node(20);
  n1->next = n2;
  Node* n3 = new Node(30);
  n2->next = n3;
  Node* n4 = new Node(40);
  n3->next = n4;
  Node* n5 = new Node(50);
  n4->next = n5;

  // head = deleteOk(head, NULL, head, 5);

  // head = reverse(head);
  // head = rotate(head, 2);
  // head = removeKThNodeFromEnd(head, 2);
  // head = removeKThNodeFromEnd2(head, 2);
  head = removeEveryKTHNode(head, 2);

  Node* temp = head;
  while(temp){
    cout<<temp->data<<" ";
    temp = temp->next;
  }cout<<endl;

  return 0;
}