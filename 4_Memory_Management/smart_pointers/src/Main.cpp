#include "Main.h"
#include <memory>

class Entity {

public:
    Entity()
    {
        cout<<"Created Entity !!"<<endl;
    }

    ~Entity()
    {
        cout<<"Destroyed Entity !!"<<endl;
    }
};

int main()
{
    cout<<"*****UNIQUE POINTER*****"<<endl;

    {
        /* Unique Pointer is a smart pointer which allocates and destroy dynamic memory without using new or delete operator */
        /* As per the name we can't create copy of this unique pointer as it doesn't shares the reference */
        /* Unique does not holds reference count and has single ownership */
 
        unique_ptr<Entity> entity = make_unique<Entity>();

        {
            /* Unique pointers can transfer but not copied their ownership to another unique pointer using move function */
            /* In simple terms, just to create change pointer name from one to another. All other things are same */

            cout<<"Transferring unique pointer to another unique pointer"<<endl;
            unique_ptr<Entity> entity1 = move(entity);

        } /* As now unique pointer moved from entity to entity1 and entity1 has scope till this block. destructor should be called here */

        cout<<"end of 2nd block where move function used "<<endl;

    }

    cout<<"end of 1st block"<<endl;

    cout<<"\n\n*****SHARED POINTER*****"<<endl;

    {
        /* shared pointer is a smart pointer which is same as unique pointer. But, allowed to share reference using other shared pointers */
        /* shared pointer uses reference count to keep track of all shared pointers which holds reference. */
        /* Shared pointer get destroyed once last shared pointer goes out of scope. */

        shared_ptr<Entity> entity = make_shared<Entity>();

        {
            /* You can check reference count value using use_count function. */
            cout<<"Total reference count is :: "<<entity.use_count()<<endl;

            shared_ptr<Entity> entity1 = entity; // now total 2 shared pointers are assigned to same reference.

            cout<<"Total reference count is :: "<<entity.use_count()<<endl;

        } // Here, destructor will not be triggered as still entity holds the reference.

        cout<<"end of 2nd block where another shared_pointer used. "<<endl;
    }

    cout<<"end of 1st block"<<endl;
    
    cout<<"\n\n*****WEAK POINTER*****"<<endl;

    {
        /* Weak pointer is only used to keep track of shared pointer existance without increasing its reference count */

        weak_ptr<Entity> entity;

        {
            shared_ptr<Entity> entity1 = make_shared<Entity>();

            /* You can check reference count value using use_count function. */
            cout<<"Total reference count is :: "<<entity.use_count()<<endl;

            /* Now, we assigns weak ptr to shared pointer reference. */
            entity = entity1;

            /* Now, weak pointer just has the info of reference. But, it can't be destroyed by weak pointer.*/
            cout<<"Total reference count is :: "<<entity1.use_count()<<endl;

            /* You check existance of shared pointer using weak pointer function called expired */
            cout<<"Is shared pointer reference still alive ? "<<( entity.expired() ? "No" : "Yes") <<endl;

        } /* As scope of shared pointer ends here. And this is last shared pointer which holds reference. So, here destructor will be called .*/

        /* You check existance of shared pointer using weak pointer function called expired */
        cout<<"Is shared pointer reference still alive ? "<<( entity.expired() ? "No" : "Yes") <<endl;
        cout<<"Total reference count by using weak pointer is :: "<<entity.use_count()<<endl;
    }


    return 0;
}
