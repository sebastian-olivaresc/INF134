#include <stdio.h>
#include <iostream>


void copy_array(unsigned long* empty, unsigned long* full, int size)
{
    int i = 0;
    for (; i < size; i++)
    {
        empty[i] = full[i];
    }
}

class arr_extensible
{
    private:
        int size_base;
        unsigned long *B = new unsigned long[size_base]; 

        void change_base()
        {
            int old_size_base = size_base;
            unsigned long temp[old_size_base];
            copy_array(temp,B,old_size_base);
            delete []B;
            if (size_sub > size_base) 
                size_base*=2;
            else if (size_sub == size_base/2) 
                size_base/=2;
            unsigned long *B = new unsigned long[size_base];
            copy_array(B,temp,old_size_base);
            A = &B[size_sub];
        }

    public:
        int size_sub = int(size_base / 2);
        
        arr_extensible()/*default size array values*/
        {
            size_base = 20;
        };
        
        arr_extensible(unsigned user_size)
        {
            size_base = 2*user_size;
        };

        ~arr_extensible()
        {
            delete []B;
        };

        unsigned long *A = &B[size_sub];
        

        bool setValue(unsigned long i, int v)
        {
            bool flag = true;
            (size_sub >= i)? (A[i] = v) : (flag = false);
            return flag;
        }
        
        
        void append(int v)
        {
            ++size_sub;
            change_base();
            A[size_sub] = v;
        }

        void remove()
        {
            --size_sub;
            change_base();
        }

        int getValue(unsigned long i)
        {
            if (size_sub >= i)
                return A[i];
            return 0;
        }

        unsigned long size()
        {
            return size_sub;
        }

};
