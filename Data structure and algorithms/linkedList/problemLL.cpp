#include <iostream>
#include <unordered_map>
#include <map>
#include <vector>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    Node(int data){
        this->data  = data;
        this->next = NULL;
    }
};

void printList(Node* &head){
    if(head == NULL){
        cout<<"List is empty"<<endl;
        return;
    }
    Node* temp = head;
    while (temp != NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}

void insertAtFirst(Node* &head, Node* &tail, int data){
    Node* newNode = new Node(data);
    if(head == NULL){
        head = newNode;
        tail = newNode;
        return;
    }
    newNode->next = head;
    head = newNode;
}

void insertAtLast(Node* &head, Node* &tail, int data){
    Node* newNode = new Node(data);
    if(tail == NULL){
        tail = newNode;
        head = newNode;
        return;
    }
    tail->next = newNode;
    tail = newNode;
}

Node* reverseLinkedList(Node *head){
    if(head == NULL || head->next == NULL){
        return head;
    }
    Node* prev = NULL;
    Node* curr = head;
    Node* forward = NULL;

    //note this will not update the tail if you want so then take tail as parameter and update that too like below
    // tail = curr;

    while(curr != NULL){
        forward = curr->next;
        curr->next = prev;
        prev = curr;
        curr = forward;
    }
    return prev;
}

Node* reverseLLRec(Node* curr, Node* forward = NULL, Node* prev = NULL){
    if(curr == NULL){
        return prev;
    }

    forward = curr->next;
    curr->next = prev;
    prev = curr;
    curr = forward;
    return reverseLLRec(curr, forward, prev);
}

int getLength(Node* &head){
    int cnt = 0;
    Node* temp = head;
    while(temp != NULL){
        cnt++;
        temp = temp->next;
    }
    return cnt;
}

Node* midOfLL(Node* &head){
    int len = getLength(head);
    int ans = len/2;
    Node* temp = head;
    int cnt = 0;

    while(cnt < ans){
        temp = temp->next;
        cnt++;
    }
    return temp;
}

Node* midOfLL2(Node* &head){
    Node* fast = head;
    Node* slow = head;

    while(fast != NULL){
        fast = fast->next;
        if(fast != NULL){
            fast = fast->next;
            slow = slow->next;
        }
    }
    return slow;
}

Node* kReverse(Node* head, int k){
    if(head == NULL){
        return NULL;
    }
    Node* prev = NULL;
    Node* forward = NULL;
    Node* curr = head;
    int cnt = 0;

    while(curr != NULL && cnt < k){
        forward = curr->next;
        curr->next = prev;
        prev = curr;
        curr = forward;
        cnt++;
    }

    if(forward != NULL){
        head->next = kReverse(forward, k);
    }
    return prev;
}

bool isCircular(Node* head){
    if(head == NULL){
        return true;
    }

    Node* temp = head->next;

    while(temp != NULL && temp != head){
        temp = temp->next;
    }
    if(temp == NULL){
        return false;
    }
    // if(temp == head){
    //     return true;
    // }
    return true;
}

//cycle detection
bool detectLoop(Node* head){
    if(head == NULL){
        return false;
    }
    map<Node*, bool> visited;
    Node* temp = head;

    while(temp != NULL){
        if(visited[temp] == true){
            cout<<"Loop at node with data : "<<temp->data<<endl;
            return true;
        }
        visited[temp] = true;
        temp = temp->next;
    }
    return false;
}

//floyd loop detection
bool floydLoopDetection(Node* head){
    if(head == NULL)
        return false;

    Node* fast = head;
    Node* slow = head;

    while(slow != NULL && fast != NULL){
        fast = fast->next;
        if(fast != NULL){
            fast = fast->next;
        }
        slow = slow->next;

        if(fast == slow){
            return true;
        }
    }
    return false;
}

Node* getStartingLoopNode(Node* head){
    /*
        some notes to understand
        ->when getting intersection point using floyd algo we will randomly get any node
        ->the distance from head to starting node of loop is equal to the distance from intersection node to starting node of loop (A == D)
        ->above expression can be calculated using following relation
        ->distance of fast node = 2 * distance of slow node
        ->distance of fast = A+XC+B (using diagram) here X = number of times to complete one circle by node(fast)
        ->distance of slow = A+YC+B (using diagram) here Y = number of times to complete one circle by node(slow)

        ->after solving you will get C(X-2Y) = A+B => CK = A+B => C = A+B => A+D = A+B => A = D
    */ 
    if(head == NULL)
        return NULL;

    Node* fast = head;
    Node* slow = head;

    //get the intersection point using floyd algo
    while(slow != NULL && fast != NULL){
        fast = fast->next;
        if(fast != NULL){
            fast = fast->next;
        }
        slow = slow->next;

        if(slow == fast){
            break;
        }
    }
    //here fast is the intersection point
    if(fast == NULL){
        //because no loop found
        return NULL;
    }
    slow = head;
    while( slow != fast){
        slow = slow->next;
        fast = fast->next;
    }
    //slow and fast both are pointing to starting of loop node so return any one
    return slow;
}

void removeLoop(Node* head){
    if(head == NULL){
        return;
    }

    Node* startOfLoop = getStartingLoopNode(head);
    if(startOfLoop == NULL){
        //because no loop found
        return;
    }
    Node* temp = startOfLoop;

    while(temp->next != startOfLoop){
        temp = temp->next;
    }
    temp->next = NULL;
}

//combined all together find check if loop exist then get staring node and then remove it
void removeLoopCombined(Node *head){
    if(head == NULL)
        return;

    Node* fast = head;
    Node* slow = head;

    //get the intersection point using floyd algo
    while(slow != NULL && fast != NULL){
        fast = fast->next;
        if(fast != NULL){
            fast = fast->next;
        }
        slow = slow->next;

        if(slow == fast){
            break;
        }
    }
    //here fast is the intersection point
    if(fast == NULL){
        //because no loop found
        return;
    }
    slow = head;
    while( slow != fast){
        slow = slow->next;
        fast = fast->next;
    }

    Node* temp = slow;
    while(temp->next != slow){
        temp = temp->next;
    }
    temp->next = NULL;
}

void sortedRemoveDuplicate(Node* head){
    if(head == NULL){
        return;
    }
    Node* curr = head;
    Node* duplicate = NULL;
    while(curr != NULL && curr->next != NULL){
        if(curr->data == curr->next->data){
            duplicate = curr->next;
            curr->next = duplicate->next;
            duplicate->next = NULL;
            delete duplicate;
        }else{
            curr = curr->next;
        }
    }
}

void unsortedRemoveDuplicate1(Node* head){
    //using two loop TC -> O(N^2) SC -> O(1)
    if(head == NULL){
        return;
    }
    Node* i = head;
    Node* j = NULL;
    Node* prev = NULL;
    while(i != NULL){
        j = i->next;
        prev = i;
        while(j != NULL){
            if(i->data == j->data){
                prev->next = j->next;
                j->next = NULL;
                delete j;
                j = prev->next;
            }else{
                prev = j;
                j = j->next;
            }
        }
        i = i->next;
    }
}

void unsortedRemoveDuplicate2(Node* head){
    //using map TC -> O(N) SC -> O(N)
    if(head == NULL){
        return;
    }

    //if you use map then time complexity increases but in case of unordered_map its not
    unordered_map<int, bool> visited;
    Node* curr = head;
    Node* prev = NULL;
    while(curr != NULL){
        if(visited[curr->data] == true){
            prev->next = curr->next;
            curr->next = NULL;
            delete curr;
            curr = prev->next;
        }else{
            visited[curr->data] = true;
            prev = curr;
            curr = curr->next;
        }
    }
}

Node* sortZeroOneTwo1(Node* head){
    int zeroCount = 0;
    int oneCount = 0;
    int twoCount = 0;

    Node* temp = head;

    while(temp != NULL){
        if(temp->data == 0){
            zeroCount++;
        }else if(temp->data == 1){
            oneCount++;
        }else if(temp->data == 2){
            twoCount++;
        }

        temp = temp->next;
    }

    temp = head;

    while (temp != NULL){
        if(zeroCount != 0){
            temp->data = 0;
            zeroCount--;
        }else if(oneCount != 0){
            temp->data = 1;
            oneCount--;
        }else if(twoCount != 0){
            temp->data = 2;
            twoCount--;
        }
        temp = temp->next;
    }
    return head;
}

void addLast(Node* &tail, Node* &curr){
    tail->next = curr;
    tail = curr;
}
Node* sortZeroOneTwo2(Node* head){
    Node* zeroHead = new Node(-1);
    Node* zeroTail = zeroHead;
    Node* oneHead = new Node(-1);
    Node* oneTail = oneHead;
    Node* twoHead = new Node(-1);
    Node* twoTail = twoHead;

    Node* curr = head;

    while(curr != NULL){
        if(curr->data == 0){
            addLast(zeroTail, curr);
        }else if(curr->data == 1){
            addLast(oneTail, curr);
        }else if(curr->data == 2){
            addLast(twoTail, curr);
        }
        curr = curr->next;
    }

    if(oneHead->next != NULL){
        zeroTail->next = oneHead->next;
    }else{
        zeroTail->next = twoHead->next;
    }
    oneTail->next = twoHead->next;
    twoTail->next = NULL;
    head = zeroHead->next;

    delete zeroHead;
    delete oneHead;
    delete twoHead;
    return head;
}

bool isPalindrome1(Node* head){
    vector<int>arr;
    Node*temp = head;

    while(temp != NULL){
        arr.push_back(temp->data);
        temp = temp->next;
    }

    int i = 0, j = arr.size()-1;

    while(i <= j){
        if(arr[i++] != arr[j--]){
            return false;
        }
    }
    return true;
}

bool isPalindrome2(Node* head){
    if(head == NULL){
        return 0;
    }
    if(head->next == NULL){
        return 1;
    }
    Node* mid = head;
    Node* fast = mid->next;
    bool flag = 1;

    while(fast->next != NULL){
        fast = fast->next;
        if(fast->next != NULL){
            fast = fast->next;
            mid = mid->next;
        }
    }
    //taking head of reversed list
    Node* revList = reverseLinkedList(mid->next);
    //connecting mid ka next with rev list
    mid->next = revList;
    Node* temp = head;
    while(temp != mid->next){
        if(temp->data != revList->data){
            flag = 0;
            break;
        }
        temp = temp->next;
        revList = revList->next;
    }
    revList = reverseLinkedList(mid->next);
    //connecting mid ka next with rev list so that it stays in its original state
    mid->next = revList;
    return flag;
}

Node* addTwoLinkedList(Node* head1, Node* head2){
    Node* first = reverseLinkedList(head1);
    Node* second = reverseLinkedList(head2);
    Node* ansHead = NULL;
    int carry = 0, sum = 0, digit;

    while(first != NULL || second != NULL || carry != 0){
        int val1 = 0;
        int val2 = 0;
        if(first != NULL)
            val1 = first->data;

        if(second != NULL)
            val2 = second->data;

        sum = val1 + val2 + carry;
        digit = sum % 10;

        Node* temp = new Node(digit);
        //adding before head(insertAtFirst) by doing this t don't need to reverse the ansList
        if(ansHead == NULL){
            ansHead = temp;
        }else{
            temp->next = ansHead;
            ansHead = temp;
        }

        carry = sum/10;
        if(first != NULL)
            first = first->next;
        if(second != NULL)
            second = second->next;
    }
    return ansHead;
}


int main() {
    Node* node1 = NULL;
    Node* head = node1;
    Node* tail = node1;
    // insertAtLast(head, tail, 7);
    insertAtLast(head, tail, 2);    
    insertAtLast(head, tail, 4);
    insertAtLast(head, tail, 3);
    // insertAtLast(head, tail, 2);
    // insertAtLast(head, tail, 1);


    Node* head2 = new Node(5);
    Node* tail2 = head2;
    insertAtLast(head2, tail2, 6);
    insertAtLast(head2, tail2, 4);
    // insertAtLast(head2, tail2, 3);

    printList(head);
    printList(head2);
    head2 = addTwoLinkedList(head, head2);
    printList(head2);



    // head = reverseLinkedList(head);
    // head = reverseLLRec(head);

    // printList(head);

    // head = sortZeroOneTwo1(head);
    // head = sortZeroOneTwo2(head);

    // cout<<isPalindrome1(head)<<endl;
    // cout<<isPalindrome2(head)<<endl;
    // printList(head);

    // tail->next = head->next->next;
    // if(floydLoopDetection(head)){
    //     cout<<"Loop present"<<endl;
    // }else{
    //     cout<<"Loop doesn't present"<<endl;
    // }
    // Node* sNode = getStartingLoopNode(head);
    // if(sNode == NULL){
    //     cout<<"Start value : "<<sNode<<endl;
    // }else{
    //     cout<<"Start value : "<<sNode->data<<endl;
    // }
    // removeLoopCombined(head);
    // printList(head);


    // Node* mid = midOfLL(head);
    // Node* mid = midOfLL2(head);
    // printList(mid);
    // cout<<mid->data<<endl;

    // head = kReverse(head, 3);
    // printList(head);

    //cout<<isCircular(head)<<endl;

    // sortedRemoveDuplicate(head);
    // printList(head);

    // unsortedRemoveDuplicate1(head);
    // unsortedRemoveDuplicate2(head);
    // printList(head);

    // cout<<"Head : "<<head->data<<endl;
    // cout<<"Tail : "<<tail->data<<endl;
    return 0;
}