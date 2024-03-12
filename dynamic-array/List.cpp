//================================================
// Hoa Nguyen
// List.cpp
// November 2023
// This file contains the class methods for the
// templated List class.
//================================================

//================================================
// default constructor
// Creates a new empty List
// Parameters: none
// Return Value: none
//================================================
template <typename T>
List<T>::List ( void )
{
    capacity = DEFAULT_LIST_SIZE;
    size = 0;
    list = new T[capacity];
}

//================================================
// copy constructor
// Creates a new List from an existing one
// Parameters:
// - List reference to l
// Return Value: none
//================================================
template <typename T>
List<T>::List ( const List<T> &l )
{
    capacity = l.capacity;
    size = l.size;
    list = new T[capacity];
    
    for (int i = 0; i < size; ++i)
        list[i] = l.list[i];
}

//================================================
// isEmpty access method
// Determines if the list is empty
// Parameters: none
// Return Value:
// - True if the list is empty, false otherwise
//================================================
template <typename T>
bool List<T>::isEmpty ( void ) const
{
    return size == 0;
}

//================================================
// length access method
// Returns the number of items in the list
// Parameters: none
// Return Value:
// - the value of number of items in the list
// as integer
//================================================
template <typename T>
int List<T>::length ( void ) const
{
    return size;
}

//================================================
// subscript operator
// Accesses (by reference) the item at the
// specified index
// Parameters:
// - integer position
// Return Value:
// - A reference to the item of type T at the
// specified index
//================================================
template <typename T>
T & List<T>::operator[] ( int position )
{
    if (0 <= position && position < size)
        return list[position];

    else
    {
        cout << "Invalid Index" << endl;
        exit(3);
    }
}

//================================================
// append modifier
// Appends a new item onto the back of the list
// Parameters:
// - T item
// Return Value: none
//================================================
template <typename T>
void List<T>::append ( T item )
{
    if (size == capacity)
        reallocate();

    list[size] = item;
    size++;
}

//================================================
// insert modifier
// Inserts a new value at the specified position
// Parameters:
// - T item, int position
// Return Value: none
//================================================
template <typename T>
void List<T>::insert ( T item, int position )
{
    if (size == capacity)
        reallocate();

    if (position > size || position < 0)
        cout << "Invalid Index" << endl;

    else
    {
        for (int i = size - 1; i >= position; i--)
            list[i + 1] = list[i];
        list[position] = item;
        size++;
    }
}

//================================================
// remove modifier
// Removes an item at the specified location
// Parameters:
// - int position
// Return Value: none
//================================================
template <typename T>
void List<T>::remove ( int position )
{
    if (position >= size || position < 0)
        cout << "Invalid Index" << endl;
    else
    {
        for (int i = position; i < size - 1; i++)
            list[i] = list[i + 1];
        size--;
    }
}

//================================================
// concatenate operator
// Concatenates two lists into a new list
// Parameters:
// - List reference to l
// Return Value:
// - A new list containinga the elements of
// the calling list followed by the elements
// of the specified list
//================================================
template <typename T>
List<T> List<T>::operator+ (const List<T> &l) const
{
    List<T> result;

    for (int i = 0; i < size; ++i)
        result.append(list[i]);

    for (int i = 0; i < l.size; ++i)
        result.append(l.list[i]);
    
    return result;
}

//================================================
// assignment operator
// Assigns the contents of another list to the
// calling list
// Parameters:
// - List reference to l
// Return Value:
// - A reference to the calling list after
// the assignment
//================================================
template <typename T>
List<T> List<T>::operator= ( const List<T> &l )
{
    delete[] list;
    capacity = l.capacity;
    list = new T[capacity];
    size = l.size;

    for (int i = 0; i < size; ++i)
        list[i] = l.list[i];

    return *this;
}

//================================================
// clear operator
// Removes all items from the list
// Parameters: none
// Return Value: none
//================================================
template <typename T>
void List<T>::clear ( void )
{
    size = 0;
}

//================================================
// destructor
// Cleans up the memmory of the list
// Parameters: none
// Return Value: none
//================================================
template <typename T>
List<T>::~List ( void )
{
    delete[] list;
}

//================================================
// reallocate method
// Creates a new array that is twice the capacity
// of the current array. Copies the items from the
// current array into the new one. Deletes the
// current array. Attaches the new array to the
// list properly.
// Parameters: none
// Return Value: none
//================================================
template <typename T>
void List<T>::reallocate ( void )
{
    capacity *= 2;
    T *newList = new T[capacity];

    for (int i = 0; i < size; i++)
        newList[i] = list[i];

    delete[] list;
    list = newList;
}