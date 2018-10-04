//Name:   Nehemias Miranda
//Class:  Data Structure
//Program: Sequence LinkedLists

#include "sequence3d.h"
#include <iostream>

using namespace std;

namespace DSProject02 {
     //Default Constructor Initialized Empty.
    sequence::sequence() {
       
        head_ptr = NULL;
        tail_ptr = NULL;
        cursor = NULL;
        many_nodes = 0;
    }
    //copies the source from head_ptr to tail_ptr into new unaltered sequence.
    //Loop to find the sources' current and copy the sources cursor
    //to the new sequence cursor.
    sequence::sequence(const sequence &source) {
        list_copy(source.head_ptr, head_ptr, tail_ptr);
        many_nodes = source.many_nodes;
        
        node* temp = source.head_ptr;
        cursor=head_ptr;
        while (temp!=source.cursor) {
            
            temp=temp->nlink();
            cursor= cursor->nlink();
        }
        
    }
    
    void sequence::operator=(const sequence &source) {
        //Check for Self Assignment.
        if (this == &source)
        {
            return;
        }
        else{
            //Empy the sequence
            list_clear(head_ptr);
            //copies the source from head_ptr to tail_ptr into new unaltered sequence.
            list_copy(source.head_ptr, head_ptr, tail_ptr);
            many_nodes = source.many_nodes;
            node* temp = source.head_ptr;
            cursor=head_ptr;
            //Loop to find the sources' current and copy the sources cursor
            //to the new sequence cursor.
            while (temp!=source.cursor) {
                
                temp=temp->nlink();
                cursor= cursor->nlink();
            }        }
    }
    
    sequence::~sequence() {
        
        //Clears the sequence
        list_clear(head_ptr);
    }
    
    void sequence::start() {
        
        //Puts the cursor ath the beggining of the sequence
        cursor = head_ptr;
    }
    
    void sequence::advance() {
        
         //Moving the cursor 1 forward.
         cursor = cursor->nlink();
      
    }
    void sequence::retreat(){
        
        //Moving the cursor 1 backward.
         cursor=cursor->plink();
        
        
    
    }
    
    void sequence::insert(const sequence::value_type &entry) {
        
        //Case 1: Empty sequence
        //Whenever the sequence is empty the new node will be inserted
        //in the first position
        if(head_ptr == NULL)
        {
            list_head_insert(head_ptr, entry);
            cursor = head_ptr;
            tail_ptr=head_ptr;
            
        }
        //Case 2: No current item or cursor is at head.
        //Whenever there is no current or current is the first element
        //the new node will be inserted in the first position
        else if(cursor == NULL || cursor == head_ptr)
        {
            list_head_insert(head_ptr, entry);
            cursor = head_ptr;
            
        }
        else
         //Case 3: Cursor anywhere in the middle
         //Will insert a new node before the cursor and update the
         //cursor to be the new entry.
            
        {
            list_insert(cursor, entry);
            cursor = cursor-> plink();
            
        }
        ++many_nodes;
        

    }
    
    void sequence::append(const sequence::value_type &entry) {
        //If sequence is empty
        //Whenever the sequence is empty the new node will be added
        //at the begginign of the sequence.
        //cursor and tail pointer will be updated to be the same as head
        if(head_ptr == NULL)
        {
            list_head_insert(head_ptr, entry);
            cursor = head_ptr;
            tail_ptr=head_ptr;
            
        }
        // If no current item
        //Whenever there isn't any current item the cursor will move
        //to the end of the list and append the new entry.
        //cursor will be updated to be at the new entry.
        else if(cursor==NULL)
        {
            cursor = list_locate(head_ptr, list_length(head_ptr));
            list_append(cursor, entry);
            
            cursor = cursor->nlink();
        }
        else
         //When theres a current item.
        //Whenever theres a current item, the new entry will be added after
        //the current item. Cursor will be updated to be the newly entered node.
        {
            list_append(cursor, entry);
            cursor = cursor -> nlink();
        }

        ++many_nodes;
   
    }
    
    void sequence::remove_current() {
       
        //case1: Remove at head
        //Whenever the current is the first item
        //the cursor and head will be moved one forward and
        //the old head or current will be removed.
        if(cursor==head_ptr){
            cursor=head_ptr->nlink();
            list_head_remove(head_ptr);
            head_ptr=cursor;
            
        }
        //Case 2: When cursor is at tail
        //Whenever the current is the last item
        //the cursor and head will be moved one backward and
        //the old tail or current will be removed.
        else if(cursor==tail_ptr){
            
            tail_ptr=tail_ptr->plink();
            list_remove(cursor);
            cursor=tail_ptr;
            //cursor=tail_ptr->plink();
            //list_remove(tail_ptr);
            //tail_ptr=cursor;
        
            }
        //Case 3: When cursor is anywhere else
        //Wehenever the it will remove at the cursor it must
        //move 1 forward and store the cursor in a temporary node.
        //then remove the current
        else{
            node* temp = cursor->nlink();
            list_remove(cursor);
            cursor=temp;
            
        }
        --many_nodes;
        
        

    }
    
    sequence::value_type sequence::current() const {
        return cursor->data();
    }
    
}
