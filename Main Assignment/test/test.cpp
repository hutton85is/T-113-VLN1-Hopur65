#include "test.h"

test::test()
{
    //ctor
}

test::~test()
{
    //dtor
}


void test::ostreamoperator()
{
    try{
        client c;
        strncpy(c.name, "valdi kaldi", 64);
        if(c.name[0] != '\0')
        {
            throw -1;
        }

    }
    catch(int err)
    {
        cout << "client name is not null" << endl;
    }

}
