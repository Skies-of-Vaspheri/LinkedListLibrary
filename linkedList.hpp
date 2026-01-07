#ifndef LINKLIST_H_INC
#define LINKLIST_H_INC


#include <iostream>

//Create template variable
template <typename DataT>
class LinkedListNode
{
    //Initialize element variable and pointer to next in list
    DataT data;
    LinkedListNode * next;
public:
    //Empty Constructor
    LinkedListNode(void): next(nullptr) {}

    //Define element
    LinkedListNode(DataT dat): data(dat),next(nullptr) {}
    
    //Copy Constructor
    LinkedListNode(const LinkedListNode<DataT> & other) {
        data = other.getDat();
    };

    //Assignment Operator
    LinkedListNode& operator=(const LinkedListNode&) = default;

    //Get element
    DataT& getDat(void) {
        return data;
    }

    //Set element
    void setDat(DataT d) {
        data = d;
        return;
    }

    //Return's next node
    LinkedListNode* getP(void) const {
        return next;
    }

    //Set pointer to next node
    void setP(LinkedListNode * n) {
        next = n;
        return;
    }
};


// Overarching structure of the same variable type
template <typename DataT>
class LinkedList
{
    //length, pointer to first term, and pointer to last term
    //last term for ease of edit in functions mentioned
    size_t count;
    LinkedListNode<DataT> * head;
    LinkedListNode<DataT> * tail;
public:
    //Default constructor
    LinkedList(void);

    //Constructor that establishes first node
    LinkedList(DataT dat);

    //Copy constructor
    LinkedList(const LinkedList<DataT> & other);

    //Destructor
    ~LinkedList();

    //Assignment Operator
    LinkedList& operator=(const LinkedList<DataT> & other);

    //Append New Node
    void operator+=(DataT dat);

    //length
    size_t getCount(void) const {
        return count;
    }

    //Index shortcuts
    DataT operator[](size_t index) const;
    DataT& operator[](size_t index);

    //What it says on the tin
    //Setup for insertion, removal, and searching the list
    void insert(size_t index,DataT dat);
    void remove(size_t index);
    size_t find(DataT dat);
};

//References the defns
//.defn and this setup for the sake of template functionality
#ifdef TEMPL_CANT_SEP
    #include "linkedList.defn"
#endif

#endif
