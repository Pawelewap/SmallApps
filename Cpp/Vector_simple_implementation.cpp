// VECTOR
/*
 * PRIVATE:
 * _Resize()            -> resize vector if it is needed
 *  - returns E_OK if allocation is finished corectly
 *  - returns E_NOK_NULLPTR if malloc returns a null pointer
 *
 * _PushFront()         -> algorithm for push_front() public function
 *  - returns E_OK if allocation is finished corectly
 *  - returns E_NOK_NULLPTR if malloc returns a null pointer
 *
 * begin()              -> returns an address of first element in a vector
 * end()                -> returns an address of last element in a vector
 *
 * fill(int, int, int)  -> fills desired size of vector with given value
 *  - int pos:  position of first element to change
 *  - int size: number of elements to change
 *  - int val:  value to fill with
 *
 * size()               -> returns number of elements in a vector
 * push_back(int)       -> adds given value as last vector element
 * push_front(int)      -> adds given value as first vector element
 * pop_back()           -> delete last element of the vector
 * pop_front()          -> delete first element of the vector
 * insert(int, int)     -> insert value on given position
 * revert()             -> make revert of whole vector
 * erase()              -> Erased elements + all elements after them
 * shrink_to_fit()      -> Requests the removal of unused capacity.
*/

#include <iostream>
#include <string.h> // memcpy, memset

// global variables
static const unsigned int E_NOK_NULLPTR      = 0;
static const unsigned int E_OK               = 1;
static const unsigned int E_NOK_WRONG_SIZE   = 2;
static const unsigned int START_SIZE         = 10;
static const unsigned int BUFFER             = 10;

class VectorP
{
private:
    int* storage = new int[START_SIZE];
    int sizeOfVector = START_SIZE;
    int lastElement = 0;

    int _Resize(int size)
    {
        sizeOfVector = size;
        int* new_storage = new int[sizeOfVector + BUFFER];
        memcpy(new_storage, storage, (sizeOfVector * sizeof(int))); // copy "old - storage" block of memory to "new - new_storage" block of memory

        delete[] storage; // free previously allocated memory
        storage = new_storage; // set new memory to storage pointer
        new_storage = nullptr;

        sizeOfVector += BUFFER; // update size of vector.

        if(storage == nullptr)
        {
            return E_NOK_NULLPTR;
        }

        else
        {
            return E_OK;
        }

    }

    int _PushFront(int val)
    {
        int* add_front = new int[sizeOfVector + 1];
        add_front[0] = val;
        memcpy((add_front + 1), storage, (sizeOfVector * sizeof(int))); // copy "old - storage" block of memory to "new - new_storage" block of memory

        delete[] storage; // free previously allocated memory
        storage = add_front; // set new memory to storage pointer
        add_front = nullptr;

        if(storage == nullptr)
        {
            return E_NOK_NULLPTR;
        }

        else
        {
            return E_OK;
        }
    }

    void _PopFront()
    {
        memmove(storage, (storage + 1), ((lastElement - 1) * sizeof(int)));
    }

    void _Insert(int pos, int val)
    {
        memmove((storage + pos), (storage + (pos - 1)), ((lastElement - pos) * sizeof(int)));
        storage[pos] = val;
    }

    void _shrink_to_fit()
    {
        int* new_storage = new int[lastElement];
        memcpy(new_storage, storage, (lastElement * sizeof(int))); // copy "old - storage" block of memory to "new - new_storage" block of memory

        delete[] storage; // free previously allocated memory
        storage = new_storage; // set new memory to storage pointer
        new_storage = nullptr;

        sizeOfVector = lastElement;
    }

public:

    VectorP()
    {
        // empty
    }

    VectorP(unsigned int size, int val)
    {
        if(size > START_SIZE)
        {
            _Resize(size);
            for(unsigned int i = 0; i < size; i++)
            {
                storage[i] = val;
                lastElement++;
            }
        }

        else
        {
            for(unsigned int i = 0; i < size; i++)
            {
                storage[i] = val;
                lastElement++;
            }
        }
    }

    ~VectorP()
    {
        delete[] storage;
        storage = nullptr;
    }


////////////////////// FUNCTIONS AREA ////////////////////////////

    int begin()
    {
        return 0;
    }

    int end()
    {
        return lastElement;
    }

    int size()
    {
        std::cout << "size: " << sizeOfVector << std::endl;
        return lastElement;
    }

    void push_back(int val)
    {
        if(lastElement < sizeOfVector)
        {
            storage[lastElement] = val;
            lastElement++;
        }

        else
        {
            _Resize(sizeOfVector);
            storage[lastElement] = val;
            lastElement++;
        }
    }

    void push_front(int val)
    {

        if(lastElement < sizeOfVector)
        {
            _PushFront(val);
            lastElement++;
        }

        else
        {
            _Resize(sizeOfVector);
            _PushFront(val);

            lastElement++;
        }
    }

    int fill(int pos, int size, int val)
    {
        if(pos > lastElement)
        {
            return E_NOK_WRONG_SIZE;
        }

        else
        {
            //memset((storage + pos), val, (size * sizeof(int)));
            for(int i = pos; i < (size + pos); i++)
            {
                storage[i] = val;
            }

            return E_OK;
        }
    }

    void pop_back()
    {
        lastElement--;
    }

    void pop_front()
    {
        _PopFront();
        lastElement--;
    }

    void insert(int pos, int val)
    {
        if(lastElement == sizeOfVector)
        {
            _Resize(BUFFER);
            _Insert(pos, val);
            lastElement++;
        }

        else
        {
            _Insert(pos, val);
            lastElement++;
        }
    }

    void erase(int pos)
    {
        lastElement--;
        lastElement -= pos;
    }

    void revert()
    {
        int end = lastElement;
        int mid = (end / 2);
        for(int i = 0; i < mid; i++)
        {
            end--;
            storage[i]   ^= storage[end];
            storage[end] ^= storage[i];
            storage[i]   ^= storage[end];
        }

    }

    void shrink_to_fit()
    {
        _shrink_to_fit();
    }

    int operator[] (int pos)
    {
        return storage[pos];
    }
};

int main()
{
    VectorP wektor;

    /////////////////////////////////////////////////////////////////////////////// CREATE FILLED
    VectorP testFill = {3, 1};

    std::cout << "testFill vectorP: " << std::endl;
    for(int i = testFill.begin(); i < testFill.end(); i++)
    {
        std::cout << testFill[i] << std::endl;
    }



    std::cout << std::endl << "wektor: push back and push front" << std::endl;
    /////////////////////////////////////////////////////////////////////////////// PUSH BACK
    for(int i = 5; i < 10; i++)
    {
        wektor.push_back(i + 1);
    }

    /////////////////////////////////////////////////////////////////////////////// PUSH FRONT
    for(int i = 5; i > 0; i--)
    {
        wektor.push_front(i);
    }

    ////////////////// PRINT VALUES
    for(int i = wektor.begin(); i < wektor.end(); i++)
    {
      std::cout << wektor[i] << std::endl;
    }
    std::cout << "capacity: "  << wektor.size() << std::endl;




    std::cout << std::endl << "FILL first two elements with 0" << std::endl;
    ///////////////////////////////////////////////////////////////////////////////  FILL
    wektor.fill(0, 2, 0);
    ////////////////// PRINT VALUES
    for(int i = wektor.begin(); i < wektor.end(); i++)
    {
      std::cout << wektor[i] << std::endl;
    }
    std::cout << "capacity: "  << wektor.size() << std::endl;




    std::cout << std::endl << "POP BACK x2" << std::endl;
    ///////////////////////////////////////////////////////////////////////////////  POP BACK
    wektor.pop_back();
    wektor.pop_back();

    ////////////////// PRINT VALUES
    for(int i = wektor.begin(); i < wektor.end(); i++)
    {
      std::cout << wektor[i] << std::endl;
    }
    std::cout << "capacity: "  << wektor.size() << std::endl;




    std::cout << std::endl << "POP FRONT x2: " << std::endl;
    ///////////////////////////////////////////////////////////////////////////////  POP FRONT
    wektor.pop_front();
    wektor.pop_front();

    ////////////////// PRINT VALUES
    for(int i = wektor.begin(); i < wektor.end(); i++)
    {
      std::cout << wektor[i] << std::endl;
    }
    std::cout << "capacity: "  << wektor.size() << std::endl;





    std::cout << std::endl << "INSERT: " << std::endl;
    ///////////////////////////////////////////////////////////////////////////////  INSERT
    wektor.insert(2,99);


    ////////////////// PRINT VALUES
    for(int i = wektor.begin(); i < wektor.end(); i++)
    {
      std::cout << wektor[i] << std::endl;
    }
    std::cout << "capacity: "  << wektor.size() << std::endl;



    std::cout << std::endl << "REVERT: " << std::endl;
    ///////////////////////////////////////////////////////////////////////////////  REVERT
    wektor.revert();

    ////////////////// PRINT VALUES
    for(int i = wektor.begin(); i < wektor.end(); i++)
    {
      std::cout << wektor[i] << std::endl;
    }
    std::cout << "capacity: "  << wektor.size() << std::endl;




    std::cout << std::endl << "ERASE: " << std::endl;
    ///////////////////////////////////////////////////////////////////////////////  ERASE
    wektor.erase(3);

    ////////////////// PRINT VALUES
    for(int i = wektor.begin(); i < wektor.end(); i++)
    {
      std::cout << wektor[i] << std::endl;
    }
    std::cout << "capacity: "  << wektor.size() << std::endl;




    std::cout << std::endl << "SHRINK TO FIT" << std::endl;
    ///////////////////////////////////////////////////////////////////////////////  SHRINK TO FIT
    wektor.shrink_to_fit();

    ////////////////// PRINT VALUES
    for(int i = wektor.begin(); i < wektor.end(); i++)
    {
      std::cout << wektor[i] << std::endl;
    }
    std::cout << "capacity: "  << wektor.size() << std::endl;

    return 0;
}
