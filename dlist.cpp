#include <cstddef> 
#include <iostream>

using namespace std;

template<class ItemType>
struct NodeType
{
	ItemType info;
	NodeType<ItemType>*	next;
	NodeType<ItemType>*	back;
};

template <class ItemType>		
DList<ItemType>::DList()		// Class constructor
{
    length = 0;
    head = NULL;
}

template <class ItemType>
DList<ItemType>::~DList   ()		
{
	// Post: List is empty; All items have been deallocated.
  makeEmpty();
}

template <class ItemType>
void DList<ItemType>::makeEmpty()
{
    // Post: List is empty; all items have been deallocated.
    head = NULL;



}

template <class ItemType>
void DList<ItemType>::deleteItem (ItemType item)	
{
	//  Pre :  item to be deleted is passed in via parameter 
        // Post :  item is deleted if it exists in list 
  NodeType<ItemType>* locationX = new NodeType;
  locationX -> info = item;
  if(isEmpty())
    cout<<"Error: List is empty"<<endl;
    
  else{
    locationX = head -> next;
    while(locationX!=NULL)
    {
      if(locationX ->info == item)
      {
        deleteLocation(locationX);
      }
      else
        locationX = locationX -> next;
    }
    
  }

}

template <class ItemType>
bool DList<ItemType>::inList (ItemType item) const
{
	//  Pre :  item to be located is passed in via parameter 
        // Post :  function returns bool value if item is found 
  NodeType<ItemType>* locationX = new NodeType;
  locationX -> info = item;
    if(isEmpty())
    cout<<"Error: List is empty"<<endl;
    
  else{
    locationX = head -> next;
    while(locationX!=NULL)
    {
      if(locationX ->info == item)
      {
        return true;
      }
      else
        locationX = locationX -> next;
    }
    
  }
  return false;

}

template <class ItemType>
bool DList<ItemType>::isEmpty() const		
{
	// Post : function returns true if list is empty, false otherwise
	return(head==NULL);
}

template <class ItemType>
void DList<ItemType>::print() const	
{
	// Pre  : List is not empty 
	// Post : Items in List have been printed to screen
  NodeType<ItemType>* locationX = new NodeType;
  locationX -> info = item;
    if(isEmpty())
    cout<<"Error: List is empty"<<endl;
    
  else{
    locationX = head -> next;
    while(locationX!=NULL)
    {
        cout<<locationX->info<<endl;
        locationX = locationX -> next;
    }
    
  }
}
	
template <class ItemType>
void DList<ItemType>::insertHead(ItemType item)	
{
	//  Pre : item to be inserted is passed in via parameter
        // Post : item is inserted at head of list;  Former first node is 
        //        linked back to this new one via double link;
        //        Length incremented;  Special case handled if list is empty 
	  NodeType<ItemType>* newNode = new NodeType;
    newNode -> info = item;
    if(isEmpty()){
      head -> next = newNode;
      newNode -> back = NULL;
      length++;
    }
  else{
    newNode -> next = head -> next;
    head -> next -> back = newNode;
    head -> next = newNode;
    newNode -> back = NULL;
    length++;
  }
}

template <class ItemType>
void DList<ItemType>::appendTail(ItemType item)
{
	//  Pre :  item to be inserted is passed in via parameter
        // Post :  item is added to tail of list; Former last node
        //         is linked to this new one via double link 
    NodeType<ItemType>* newNode = new NodeType;
    newNode -> info = item;
    if(isEmpty()){
      head -> next = newNode;
      newNode -> back = NULL;
      length++;
    }
  else{
    newNode -> back = last();
    newNode -> back -> next = newNode;
    length++;
  }

}

template <class ItemType>
int DList<ItemType>::lengthIs() const	
{
	// Post : Function returns current length of list 
  return(length); 
}

template <class ItemType>
NodeType<ItemType>* DList<ItemType>::location(ItemType item) const	
{
	//  Pre : item to be located is passed in via parameter 
        // Post : function returns address of item being searched for --
        //        if not found, NULL is returned  
  NodeType<ItemType>* locationX = new NodeType;
  locationX -> info = item;
    if(isEmpty()){
    cout<<"Error: List is empty"<<endl;
    }
    
  else{
    locationX = head -> next;
    while(locationX!=NULL)
    {
      if(locationX ->info == item)
      {
        return locationX;
      }
      else
        locationX = locationX -> next;
    }
    
  }
  return NULL;

}

template <class ItemType>
NodeType<ItemType>* DList<ItemType>::last() const	
{
	// Post : Function returns location of current last item in list
  NodeType<ItemType>* locationX = new NodeType;
  locationX -> info = item;
    if(isEmpty())
    cout<<"Error: List is empty"<<endl;
    
  else{
    locationX = head -> next;
    while(locationX->next!=NULL)
    {
      locationX = locationX -> next;
    }
    return locationX;
  }
    
}

template <class ItemType>
void DList<ItemType>::deleteLocation (NodeType<ItemType>* delPtr)	
{

	//  Pre : Item to be deleted exits in list and its location
        //        is passed in via parameter
                   
	// Post : Location passed in is removed from list;  Length
        //        is decremented, and location is deallocated 

        // Special Cases Handled for Deleting Only One Item in List,
        // The Head Item of List, and the Tail Item of List
    if(isEmpty())
    cout<<"Error: List is empty"<<endl;
    else if(delPtr == last())
    {
      delPtr -> back -> next = NULL;
      delete delPtr;
      length--;
    }
    else if(delPtr == head ->next)
    {
      head->next = delPtr->next;
      delPtr -> next -> back = NULL;
      delete delPtr;
      length--;
    }
    
  else{
        delPtr -> next -> back = delPtr -> back;
        delPtr -> back -> next = delPtr -> next;
        length--;
        delete delPtr;
  }

}