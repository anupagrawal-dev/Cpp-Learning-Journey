#include "Main.h"
#include <vector>

struct Vertex{
    int x;
    int y;
    int z;

    Vertex(int x, int y, int z) : x(x), y(y), z(z) 
    {
        cout<<"Constructor Called !!"<<endl;
    }

    Vertex(const Vertex &other) : x(other.x), y(other.y), z(other.z)
    {
        cout<<"Copy Constructor called!!"<<endl;
    }

    ~Vertex()
    {
        cout<<"Destructor called !!"<<endl;
    }
};

ostream& operator<<(ostream& stream, const Vertex& v1)
{
    stream<<"x = "<<v1.x<<", y = "<<v1.y<<", z = "<<v1.z;
    return stream;
}

int main()
{
    {
        vector <Vertex> abc;

        abc.push_back({1, 2, 3});
        abc.push_back({4, 5, 6});
        abc.push_back({7, 8, 9});
        abc.push_back({10, 11, 12});
        abc.push_back({13, 14, 15});
        abc.push_back({18, 17, 16});

        for(int i=0; i<(int)abc.size(); i++)
            cout<<abc[i]<<endl;

    }

    {
        vector <int> vec;
#if 0
        vec.push_back(5);

        cout<<"address of vector is 0 :: "<<&vec[0]<<endl;
        vec.push_back(6);
        cout<<"address of vector is 0 :: "<<&vec[0]<<endl;
        cout<<"address of vector is 1 :: "<<&vec[1]<<endl;
        vec.push_back(7);
        vec.push_back(8);
        cout<<"address of vector is 0 :: "<<&vec[0]<<endl;
        cout<<"address of vector is 1 :: "<<&vec[1]<<endl;
        cout<<"address of vector is 2 :: "<<&vec[2]<<endl;
        cout<<"address of vector is 3 :: "<<&vec[3]<<endl;
        vec.push_back(9);
        vec.push_back(10);
        vec.push_back(11);
        vec.push_back(12);
        cout<<"address of vector is 0 :: "<<&vec[0]<<endl;
        cout<<"address of vector is 1 :: "<<&vec[1]<<endl;
        cout<<"address of vector is 2 :: "<<&vec[2]<<endl;
        cout<<"address of vector is 3 :: "<<&vec[3]<<endl;
        cout<<"address of vector is 4 :: "<<&vec[4]<<endl;
        cout<<"address of vector is 5 :: "<<&vec[5]<<endl;
        cout<<"address of vector is 6 :: "<<&vec[6]<<endl;
        cout<<"address of vector is 7 :: "<<&vec[7]<<endl;
#endif

        /* optimized code for above */
        size_t capacity = 0;

        for(int i=0; i<8; i++)
        {
            vec.push_back(i+5);

            for(int i=0; i<(int)vec.size() && capacity != vec.capacity() ;i++)
            {
                cout<<"address of vector for index "<<i<<" is :: "<<&vec[i]<<endl;
            }

            capacity = vec.capacity();
        }
    }

    
    {
        vector <int> vec1;

        size_t capacity = 0;

        /* Now, this time i will reserved 8 elements for my vector to avoid reallocation again and again */
        vec1.reserve(8);
        cout<<"reserved 8 elements for vec1"<<endl;

        for(int i=0; i<8; i++)
        {
            vec1.push_back(i+5);

            for(int i=0; i<(int)vec1.size() && capacity != vec1.capacity() ;i++)
            {
                cout<<"address of vector vec1 for index "<<i<<" is :: "<<&vec1[i]<<endl;
            }

            capacity = vec1.capacity();
        }
    }

    /* Same want to apply for vertex, Want to reserve elements for vertex as well */
    {
        cout<<"reserved 6 elements for vertex vector "<<endl;

        vector <Vertex> abc;
        abc.reserve(6); // reserved 6 elements of vertex vector for abc 

        /* normally we were using push_back functions. So, push_back function was doing. It was first temporary structure of each element in main stack frame and after that it is copying it into actual vector which is calling copy constructor as well. */
        /* 
            To avoid this, if we will use emplace_back and just passed the values without curly braces. Then program will directly create each element inside vector which avoid copying.
        */
        abc.emplace_back(1, 2, 3); 
        abc.emplace_back(4, 5, 6);
        abc.emplace_back(7, 8, 9);
        abc.emplace_back(10, 11, 12);
        abc.emplace_back(13, 14, 15);
        abc.emplace_back(18, 17, 16);

        for(int i=0; i<(int)abc.size(); i++)
            cout<<abc[i]<<endl;

        vector <int> vec;
    }


}
