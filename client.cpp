#include <iostream>
#include "dlist.h"

using namespace std;

void PrintMenu();
void HeadInsert(DList<int>& list);
void TailInsert(DList<int>& list);
void AccessItem(DList<int>& list);
void Delete(DList<int>& list);
void PrintList(DList<int>& list);
void PrintLength(DList<int>& list);

int main()
{
	DList<int> list;
  char sel;
 
 do{
   PrintMenu();
   cin>>sel;
   switch(toupper(sel))
   {
   case 'H': HeadInsert(list); break;
   case 'T': TailInsert(list); break;
   case 'A': AccessItem(list); break;
   case 'D': Delete(list); break;
   case 'P': PrintList(list); break;
   case 'L': PrintLength(list); break;
   case 'Q': cout<<" \tExiting Program.."<<endl; break;
   default: cout<<"\tError. Try Again."<<endl;
   }
   }while (toupper(sel)!='Q');  
 return 0;
 
 }
 void PrintMenu()
 {
  cout<<"H: Insert Head"<<endl;
  cout<<"T: Insert Tail"<<endl;
  cout<<"A: Access Item"<<endl;
  cout<<"D: Delete Item"<<endl;
 cout<<"P: Print List"<<endl;
 cout<<"L: Print Length"<<endl;
 cout<<"Q: Quit Program"<<endl;
 cout<<"----------------------------"<<endl;
 cout<<"Selection: ";
 }
 
 void HeadInsert(DList<int> list)
 {
  
  cout<<"Item to Insert: ";
  int input;
  cin>>input;
  if (list.inList(input))
  cout<<"Already in the list!"<<endl;
  else
  list.insertHead(input);
  
 }
 void TailInsert(DList<int> list)
 {
  
  cout<<"Item to Insert: ";
  int input;
  cin>>input;
  if (list.inList(input))
  cout<<"Already in the list!"<<endl;
  else
  list.appendTail(input);
 }
 void AcessItem(DList<int> list)
 {
  
  cout<<"Item to Acesss: ";
  int input;
  cin>>input;
  if (!list.inList(input))
  cout<<"Item not found!"<<endl;
  else{
  list.deleteItem(input);
  list.insertHead(input);
  }
 }
 void Delete(DList<int> list)
 {
  
  cout<<"Item to delete: ";
  int input;
  cin>>input;
  if (!list.inList(input))
  cout<<"Item not found!"<<endl;
  else
  list.insertHead(input);
  
 }
 void PrintList(DList<int> list)
 {
  list.print();
 }
  void PrintLength(DList<int> list)
 {
  cout<<list.lengthIs()<<endl;
 }