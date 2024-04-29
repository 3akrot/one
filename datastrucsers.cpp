#include <iostream>
using namespace std;
const int MAX_SIZE = 100;
//stack
class stack {
  private:
  int arr[MAX_SIZE];
  int top;
  public:
  stack(){
    top = -1;
  }
  bool isempty(){
    return top == -1;
  }
  bool isfull(){
    return top == MAX_SIZE - 1;
  }
  void push(int num) {
    if(isfull()){
      cout << "error";
      return;
    }
    top++;
    arr[top] = num;
  }
  void pop(){
    if(isempty()){
      cout << "error";
    }
    top--;
  }
  void display(){
    for (int i = top; i  > -1; i--)
    {
      cout << arr[i] << endl;
    }
    
  }
  void gettop(int* ptr , int* val) {
    if (isempty()){
      cout << "stack is empty";
      *ptr = top;
      return;
    }
    *ptr = top;
    *val = arr[top];
  }

};
class qeue {
  private:
  int arr[MAX_SIZE];
  int front;
  int back;
  public:
  qeue(){
  front = -1;
  back = -1;
  }
  bool isEmpty() {
    return front == -1 && back == -1;
  }
  bool isFull () {
    return back == MAX_SIZE - 1;
  }
  void enque(int value) {
    if(isFull()) {
      cout << "que is full" << endl;
      return;
    }
    if (isEmpty()) {
      front = 0;
      back = 0;
    }
    else {
      back++;
    }
    arr[back] = value;
  }
  void deque() {
    int dequed = arr[front];
    if (isEmpty()) {
    cout << "nothing to remove"<<endl;
  }
  else {
    if(front == back){
      front = -1;
      back = -1;
    }
    else
    front++;
    cout << "dequed " << dequed<<endl;
  }
  }
  void display() {
    if(isEmpty()){
      cout<< "empty"<<endl;
      return;
    }
    cout << "{";
    for (int i = front; i <= back; i++)
    {
      cout << arr[i]<< " ";
    }
    cout << "}" << endl;
  }
  int getfront(){
    if(isEmpty()) return -1;
    return arr[front];
  }
  };
  class cicleque {
    private:
    int front;
    int back;
    int arr[MAX_SIZE];
    public:
    cicleque(){
      front = -1;
      back = -1;
    }
    bool isEmpty(){
      return front == -1;
    }
    bool isFull() {
      return (back + 1) % MAX_SIZE == front;
    }
    void enque(int val) {
      if(isFull()) {
        cout << "full" << endl;
        return;
      }
      else {
        if (isEmpty()) {
          front = 0;
        }
        back = (back + 1) % MAX_SIZE;
        arr[back] = val;
      }
    }
    void deque() {
      if (isEmpty()) {
        cout << "nothing" << endl;
        return;
      }
      if (front == back) {
      front = -1;
      back = -1;
    }
    else {
      front = (front + 1) % MAX_SIZE;
    }
  }
  void displa() {
    if (isEmpty()){
      cout << "empty" << endl;
      return;
    }
    int current = front;
    while (current != back)    {
      cout << arr[current] << " ";
      current = (current + 1) % MAX_SIZE;
    }
    cout << arr[current] << endl;
    }
    
    int getfrontval(){
    if(isEmpty()) return -1;
    else return arr[front];
  }

  
  };
  class Node {
    public:
    int data;
    Node* next;
  };
  class linkedlist {
    private:
    Node* head;
    public:
    linkedlist() {
      head = NULL;
    }
    bool isEmpty() {
      return head == NULL;
    }
    void insertatbegin(int val) {
      Node* newnode = new Node();
      newnode->data = val;
      if(isEmpty()){
        newnode->next = NULL;
        head = newnode;
        return;
      }
      newnode->next = head;
      head = newnode;
    }
    void traverseanddisplay() {
      if (isEmpty())
      {
        cout << "Empty nothing to display" << endl;
        return;
      }
      
      Node* i = head;
      while (i != NULL)
      {
        cout << i->data << " ";
        i = i->next;
      }
      
    }
    bool search(int val) {
      bool isfound = false;
      Node* i = head;
      while (i != NULL)
      {
        if(i->data == val)
          isfound = true;
          i = i->next;
      }
      return isfound;
    }
    void insertbefore(int key , int val) {
      if(search(key)){
        if(head->data == val){
          insertatbegin(val);
        }
        else {
          Node* newnode = new Node();
          newnode->data = val;
          Node* i = head;
          while(i->next->data != key){
                i = i->next;
          }
          newnode->next = i -> next;
          i->next = newnode;
          
        }
      }
      else {
        cout << "node not found";
      }

    }
    void insertatend(int val) {
      Node* newnode = new Node();
      newnode->data = val;
      newnode->next = NULL;
      if(isEmpty()){
        insertatbegin(val);
        return;
      }
      Node* i = head;
      while (i->next != NULL) 
      {
        i = i -> next;
      }
      i -> next = newnode;
      
    }
    void deleteat(int val) {
      if(isEmpty()){
        cout << "nothing to delete";
        return;
      }
      if(search(val) == false){
        cout << "node not founf to delete";
        return;
      }
      Node* i = head;
      Node* prev ;
      while (i ->data != val)
      {
        prev = i;
        i = i ->next;
      }
      prev -> next = i ->next;
      // perv i(target)
      
    }
  };
  class piroritrque {
    private:
    int size;
    int arr[MAX_SIZE];
    public:
    piroritrque(){
      size = 0;
    }
    bool isempty(){
      return size==0;
    }
    bool isfull(){
      return size == MAX_SIZE;
    }

    void enque(int val) {
      if(isfull()){
        cout << "que is full" << endl;
        return;
      }
      int i;
      //this loop shift elment to the right
      for( i = size - 1; i >= 0; --i){
        //first we check if the arr[i] bigger than elment 
        //if so we shift to right using arr[i+1] = arr[i]
        //else we break
        if(arr[i] > val){
          arr[i + 1] = arr[i];
        }
        else {
          break;
        }
      }
      //then we add the value to arr[i + 1]
      // and increase the size
      arr[i+1] = val;
      ++size;
      cout << "enqued: " << val << endl;
    }
  
    int deque(){
      int valu = arr[0];
      if(isempty()){
        cout << "que is empty" << endl;
      }
      for(int i = 1 ; i < size ; i++){
        arr[i - 1] = arr[i];
      }
      size--;
      cout << "deque: " << valu << endl;
      return valu;
    }
    void display(){
      if (isempty()){
        cout << "empty" << endl;
        return;
      }
      for(int i = 0; i < size; ++i){
        cout << arr[i] <<" "; 
      }
    }
    void getfront(int *val){
      if(isempty()){
        cout << "empty" << endl;
      }
      *val = arr[0];
    }
  };

  class stackwithlinkedlist {
    private:
    Node* top = new Node();
    public:
    stackwithlinkedlist(){
      top = NULL;
    }
    bool isEmpty(){
      return top == NULL;
    }
    void push(int val){
      Node* newnode = new Node();
      newnode->data = val;
      newnode->next = top;
      //ضروري تخلي newnode 
      //تشاور علي التوب الي فات
      top = newnode;
      cout << "pused: " << val << endl;
    }
    void display(){
      if(isEmpty()){
        cout << "empty" << endl;
        return;
      }
      Node* i = top;
      while (i != NULL)
      {
        cout << i->data << endl;
        i = i->next;
      }
      
    }
    void pop(){
      if(isEmpty()){
        cout << "empty" << endl;
        return;
      }
      int val = top->data;
      top = top->next;
      cout << "poped" << val << endl;

    }
    int size() {
      int count = 0;
      Node* i = top;
      while (i != NULL) 
      {
        count++;
        i = i->next;
      }
      return count;
    }
  };
  class quewithlinked {
    private:
    Node* front = new Node();
    Node* rear = new Node();
    public:
    quewithlinked(){
      front = NULL;
      rear = NULL;
    }
    bool isEmpty() {
      return front == NULL;
    }
    void emque(int val){
      Node *newnode = new Node();
      newnode->data = val;
      if(isEmpty()){
        rear = newnode;
        front = newnode;
        rear->data = val;
        newnode->next = NULL;
      }
    }
    void enque(int val){
      Node* newnode = new Node();
      newnode->data = val;
      if(isEmpty()){
        rear = newnode;
        front = newnode;
        rear->data = val;
        newnode->next = NULL;
      }
      else {
        rear->next = newnode;
        rear = newnode;
        rear->data = val;
        newnode->next = NULL; 
      }
      cout << "enqued " << val << endl;
    }
    void deque() {
      int val = front->data;
      if(isEmpty()){
        cout << "que is emptyy";
        return;
      }
      if( front == rear){
        front = rear = NULL;
      }
      else{
        front = front->next;
      }
      cout << "dequed " << val << endl;
      
    }
    void display() {
      if(isEmpty()){
        cout<< "noting to display" << endl;
        return;
      }
      Node *i = front;
      while (i != NULL)
      {
        cout << i->data << " ";
        i = i->next;
      }
      
    }
    int size() {
      int cout = 0;
      Node *i = front;
      while (i != NULL)
      {
        cout++;
        i = i->next;
      }
      return cout;
    }

  };
  
int main (){
  // stack x;
  // x.push(1);
  // x.push(2);
  // x.push(3);

  // x.display();
  // x.pop();
  // cout << "----------------------------------------------------------------" << endl;
  // x.display();
  // int top;
  // int valu;
  // x.gettop(&top, &valu);
  // cout << top << valu << endl;
  //stack done
  // qeue x;
  // x.enque(1);
  // x.enque(2);
  // x.enque(3);
  // x.enque(4);
  // x.display();
  // x.deque();
  // x.deque();
  // x.deque();
  // x.deque();
  // x.display();
  // x.enque(4);
  // x.display();
  // cicleque c;
  // c.enque(1);
  // c.enque(2);
  // c.enque(3);
  // c.deque();
  // c.enque(4);
  // c.displa();
//   linkedlist list;
//   list.insertatbegin(10);
//   list.insertatbegin(20);
//   list.insertatbegin(30);
//   list.insertatbegin(40);
//   list.traverseanddisplay();
//   cout << endl;
//   cout << list.search(2);
//     cout << endl;
// list.insertbefore(20,1000);
// list.insertatend(20000);
// list.deleteat(0);
// list.traverseanddisplay();
// piroritrque x;
// x.enque(2);
// x.enque(3);
// x.enque(5);
// x.enque(7);
// x.display();
// x.deque();
// int front;
//  x.getfront(&front);
//  cout << front;
//  x.display();
// stackwithlinkedlist x;
// x.push(10);
// x.push(20);
// x.push(40);
// x.display();
// x.pop();
// x.display();
// cout << x.size() << endl;7
quewithlinked x;
x.enque(10);
x.enque(20);
x.display();
x.deque();
x.display();

cout << x.size() << endl;






}