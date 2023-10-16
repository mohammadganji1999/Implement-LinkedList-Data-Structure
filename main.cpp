#include <iostream>
using namespace std;

typedef struct node
{
    int data;
    struct node* next;

} node;
node *head=NULL;
node *trail;


node* create_node(int a){

    node *new_node=new node;

    if(new_node==nullptr){
        exit(0);
    }
    else{
    new_node->data=a;
    new_node->next=NULL;

    return new_node;
    }
}

void printNode(node* node){

    cout<<"data of node is:"<<node->data<<endl;
}

void push_back(int a){

   node *new_nod=create_node(a);
   node *curser=head;
   while (curser->next!=NULL) {
    curser=curser->next;
   }
   new_nod->next=nullptr;
   curser->next=new_nod;

}
void push_front(int a){

    node *new_nod=create_node(a);
    node *p;
    if(head==nullptr){

        head=new_nod;
        head->next=nullptr;

    }
    else {

        p=head;
        head=new_nod;
        head->next=p;
    }
}

void pop_front(){

    node *p1=new node;
    p1=head;
    head=p1->next;

    p1->next=nullptr;
    delete p1;
}

void pop_back(){

    node *p2=new node;
    p2=head;

    node *p3=new node;
    p3=head;
    while (p2->next!=nullptr) {

        p2=p2->next;
    }

    while (p3->next!=p2) {

        p3=p3->next;
    }

    p3->next=nullptr;
    delete  p2;

}

void insert (int data, int insert){

    node *curs=new node;
    curs=head;
    int i=1;
    while (i!=insert) {
        curs=curs->next;
        i++;
    }
    node *curs2=new node;
    curs2=head;

    while (curs2->next!=curs) {

        curs2=curs2->next;

    }
    node *newnode=create_node(data);

    curs2->next=newnode;
    newnode->next=curs;
}

void delete1(int index){

  if(index==0){
      pop_front();
  }
    node *curs=new node;
    curs=head;
    node *curs2=new node;
    curs2=head;
    node *curs3=new node;
    curs3=head;
    int j=0;
    while(curs2->next!=nullptr){
        curs2=curs2->next;
        j++;
    }

    if(index>j){

        cout<<"this index is invalid!"<<endl;
    }

    int i=0;
    while (i!=index) {
        curs=curs->next;
        i++;
    }

    while (curs3->next!=curs) {
        curs3=curs3->next;

    }
    curs3->next=curs->next;
    curs->next=nullptr;
    delete curs;
}

void search(int data){

    node *curs=new node;
    curs=head;
    int i=1;
    int y=0;
    while(curs!=nullptr){
        if(curs->data==data){
            cout<<i<<endl;
            y++;
        }
      curs=curs->next;

        i++;
    }

    if(y==0){

        cout<<"this data dont exist!"<<endl;
    }

}
node* max(){

    node *curs=new node;
    node *curs2=new node;
    curs=head;
    int max=head->data;
    while (curs!=nullptr) {
        curs=curs->next;
        if(curs->data>max){
            max=curs->data;
            curs2->data=max;
        }
    }

    return curs2;
}

void avrage(){

    node *curs=new node;
    curs=head;
    float sum=0;
    int i=0;
    while (curs!=nullptr) {
       sum+=curs->data;
        curs=curs->next;
        i++;
    }

    cout<<static_cast< float >(sum/i);

}

void swap(int pos1, int pos2){
    struct node *node1, *node2, *prev1, *prev2, *temp;
       int i;

       // Get the far position among both
       const int maxPos = (pos1 > pos2) ? pos1 : pos2;
       int nodes = 0;
       node *k=new node;
       k=head;
           while (k != NULL)
           {
               nodes++;
               k = k->next;
           }
       const int totalNodes = nodes;

       // Validate swap positions
       if ((pos1 <= 0 || pos1 > totalNodes) || (pos2 <= 0 || pos2 > totalNodes))
       {
          cout<<"index is invalid!"<<endl;
       }

       // If both positions are same then no swapping required
       if (pos1 == pos2)
       {

       }


       // Identify both nodes to swap
       i = 1;
       temp  = head;
       prev1 = NULL;
       prev2 = NULL;

       // Find nodes to swap
       while (temp != NULL && (i <= maxPos))
       {
           if (i == pos1 - 1)
               prev1 = temp;
           if (i == pos1)
               node1 = temp;

           if (i == pos2 - 1)
               prev2 = temp;
           if (i == pos2)
               node2 = temp;

           temp = temp->next;
           i++;
       }

       // If both nodes to swap are found.
       if (node1 != NULL && node2 != NULL)
       {
           // Link previous of node1 with node2
           if (prev1 != NULL)
               prev1->next = node2;

           if (prev2 != NULL)
               prev2->next = node1;

           temp        = node1->next;
           node1->next = node2->next;
           node2->next = temp;

           if (prev1 == NULL)
               head = node2;
           else if (prev2 == NULL)
               head = node1;
       }

}
void reversePrint(node* p){
    if(!p){
        return;
    }
    reversePrint(p->next);
    cout<<p->data;
}
void sort(){

    node *newnod=new node;
    newnod=head;
    node *newnod2=new node;
    int max;
    while(newnod!=nullptr){

       for(newnod2=newnod->next;newnod2!=nullptr;newnod2=newnod2->next){
            if(newnod->data>newnod2->data){

                max=newnod->data;
                newnod->data=newnod2->data;
                newnod2->data=max;
            }


        }

        newnod=newnod->next;
    }


}
void print( ){

    node *tem=new node;
    tem=head;
    while(tem!=NULL){


        cout<<tem->data<<" ";
        tem=tem->next;

    }
}

int main(){

   int choice;
   while(true){
   cout<<"1.creat node:"<<endl;
   cout<<"2.print all data:"<<endl;
   cout<<"3.push front:"<<endl;
   cout<<"4.push back:"<<endl;
   cout<<"5.pop front:"<<endl;
   cout<<"6.pop back:"<<endl;
   cout<<"7.insert data:"<<endl;
   cout<<"8.delete data:"<<endl;
   cout<<"9.search data:"<<endl;
   cout<<"10.find max data:"<<endl;
   cout<<"11.avrage of datas:"<<endl;
   cout<<"12.swap with two index:"<<endl;
   cout<<"13.sort datas:"<<endl;
   cout<<"14.revers print:"<<endl;
   cout<<"15.print node:"<<endl;
   cout<<"16.EXIT:"<<endl;


   cin>>choice;

   if(choice==1){

       system("cls");

      int a1;
      cin>>a1;
      create_node(a1);

       system("pause");
       system("cls");

   }
   if(choice==2){

       system("cls");

       print();
       system("pause");
       system("cls");

   }

   if(choice==3){
       system("cls");

      int val2;
      cin>>val2;
      push_front(val2);
       system("pause");
       system("cls");

   }

   if(choice==4){
       system("cls");
      int val;
      cin>>val;
      push_back(val);
       system("pause");
       system("cls");
   }

   if(choice==5){
      system("cls");
      pop_front();
      system("pause");
      system("cls");
   }

   if(choice==6){
      system("cls");
      pop_back();
      system("pause");
      system("cls");
   }

   if(choice==7){
      system("cls");
      int data1,index;
      cout<<"enter data and index for insert:"<<endl;
      cin>>data1>>index;
      insert (data1, index);
      system("pause");
      system("cls");
   }

   if(choice==8){
      system("cls");
      int index1;
      cout<<"enter index for delete:"<<endl;
      cin>>index1;
      delete1(index1);
      system("pause");
      system("cls");
   }

   if(choice==9){
      system("cls");
      int data3;
      cout<<"enter data for search:"<<endl;
      cin>>data3;
      search(data3);
      system("pause");
      system("cls");
   }
   if(choice==10){
      system("cls");
      node *p;
      p=max();
      printNode(p);
      system("pause");
      system("cls");
   }

   if(choice==11){

       system("cls");
       avrage();
       system("pause");
       system("cls");

   }

   if(choice==12){

       system("cls");
       int ind1,ind2;
       cout<<"enter index1 and index2 for swap:"<<endl;
       cin>>ind1>>ind2;
       swap(ind1,ind2);
       system("pause");
       system("cls");

   }
   if(choice==13){

       system("cls");
       sort();
       system("pause");
       system("cls");

   }

   if(choice==14){

       system("cls");
       reversePrint(head);
       cout<<endl;
       system("pause");
       system("cls");


   }
   if(choice==16){

    exit(0);
   }

}
}
