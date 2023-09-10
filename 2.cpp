#include <iostream>
#include <queue>
#include<stack>
using namespace std;

// struct Node{
//     int data;
//     Node *next,*prev;
// };

// struct DoubleLinkedList
// {
//     Node*head,*tail;
// };

// DoubleLinkedList *createList(int x){
// DoubleLinkedList *p=new DoubleLinkedList;
// p->head=new Node;
// p->head->data=x;
// p->head->next=NULL;
// p->head->prev=NULL;
// p->tail=p->head;
// return p;
// }

// DoubleLinkedList *insert(DoubleLinkedList*p,int x){
// Node *temp=new Node;
// temp->data=x;
// temp->next=NULL;
// temp->prev=p->tail;
// p->tail->next=temp;
// p->tail=temp;
// return p;
// }

// int countTriplets(DoubleLinkedList*p){
//     int count=0;
//     Node *curr=p->head->next;
//     while (curr->next!=NULL){
//         if (curr->prev->data+curr->data+curr->next->data==0){
//             count++;
//         }
//         curr=curr->next;
//     }
//     return count;
// }
// void print(DoubleLinkedList*p){
// Node *curr=p->head;
// while (curr!=NULL){
//     cout<<curr->data<<" ";
//     curr=curr->next;
// }
// }
// int main(){
//   int n,num;
//   cin>>n>>num;
// DoubleLinkedList *p=createList(num);
// for (int i=1;i<n;i++){
//     cin>>num;
//     p=insert(p,num);
// }
// //print(p);
// cout<<countTriplets(p);
// }


// void print(queue<int>q){
//     queue<int>temp=q;
//     while (!temp.empty()){
//         cout<<temp.front()<<" ";
//         temp.pop();
//     }
// }

// int main(){
// int n;
// cin>>n;
// string s;
// queue<int>q;
// for (int i=0;i<n;i++){
//     cin>>s;
//     if (s=="enqueue"){
//         int x;
//         cin>>x;
//         q.push(x);
//     }
//     else if (s=="dequeue"){
//         q.pop();
//     }
// }
// print(q);
// }

// int main(){
//     int n;
//     cin>>n;
//     string s;
//     stack<int>st;
//     for (int i=0;i<n;i++){
//         cin>>s;
//         if (s=="push"){
// int x;
// cin>>x;
// st.emplace(x);
//         }
//         else if (s=="pop"){
//             st.pop();
//         }
//     }
//     stack <int >temp;
//     while (!st.empty()){
//         temp.push(st.top());
//         st.pop();
//     }
//     while (!temp.empty()){
//         cout<<temp.top()<<" ";
//         temp.pop();
//     }
// }


// int main(){
// int n;
// cin>>n;
// int a[100];
// for (int i=0;i<n;i++){
//     cin>>a[i];
// }
// int count=0;
// for (int i=0;i<n-1;i++){
//     for (int j=i+1;j<n;j++){
//         if (a[i]==a[j]){
//             count++;

//         }
//     }
// }
// cout<<count;
// }

struct Node{
    int data;
    Node *next;
};

Node *head=NULL;

void insertNode (int p,int x){
    Node *temp=new Node;
    temp->data=x;
    temp->next=NULL;
    if (head==NULL){
        head=temp;
        return;
    }
    Node *curr=head;
    if (p==0){
temp->next=head;
head=head->next;
head=temp;
    }
    else{
        for (int i=1;i<p;i++){
            curr=curr->next;
        }
        temp->next=curr->next;
curr->next=temp;

    }
}

void deleteNode(int p){
    Node *curr=head;
    if (p==0){
Node *temp=head;
head=head->next;
delete(temp);
}
    else{
for (int i=0;i<p-1;i++){
    curr=curr->next;
}
Node *temp=curr->next;
curr->next=curr->next->next;
delete(temp);
    }
}
void print(){
    while (head!=NULL){
        cout<<head->data<<" ";
        head=head->next;
    }
}

int main(){
  int n;
  cin>>n;
  string s;
  for (int i=0;i<n;i++){
    cin>>s;
    if (s=="insert"){
        int p,x;
        cin>>p>>x;
        insertNode(p,x);
    }
    else if (s=="delete"){
        int x;
        cin>>x;
        deleteNode(x);
    }
  }
print();
}
