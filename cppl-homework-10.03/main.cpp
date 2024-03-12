//
//  main.cpp
//  cppl-homework-10.03
//
//  Created by a1ex on 3/7/24.
//

#include <iostream>

template <class T>
class unique_ptr
{
private:
    T *_ptr = new T();
    
public:
    unique_ptr (T *_ptr)
    {
        this->_ptr = _ptr;
        _ptr = nullptr;
        std::cout << "Constructor worked!" << '\n';
    }
    
    T& operator*() const
    {
        return *_ptr;
    }
    
    T& operator*()
    {
        return *_ptr;
    }
    
    unique_ptr(const unique_ptr&) = delete;
    unique_ptr& operator=(const unique_ptr&) = delete;
    
    T* release()
    {
        T* temp = _ptr;
        _ptr = nullptr;
        return temp;
    }
    
    ~unique_ptr()
    {
        delete _ptr;
        std::cout << "Destructor was called!" << '\n';
    }
};

int main(int argc, const char * argv[]) {
    
       int a = 5;
       unique_ptr<int> ptr1(&a);
       ptr1.release();
    
    
    
   
    return 0;
}
