/*******************************************************************************
*  file    : main.cpp
*  created : 12.05.2018
*  author  : Slyshyk Oleksiy (alexslyshyk@gmail.com)
*******************************************************************************/

#include <cstdint>
#include <cstdio>
#include <stringarray.hpp>

template <uint32_t N>
struct TestStruct {
    char buf[N];
    TestStruct() { buf[0] = 0; }
    explicit TestStruct(const char* str) {
        if (str) {
            strncpy(buf, str, N - 1);
            buf[N - 1] = 0;
        }
    }
};

int main()
{
    printf("StringArray ver: %s \n", STRINGARRAY_VER_STR);

    TestStruct<256> ts("Helllo world!");

    StringArray<256> hw("Hello world!");
    printf("%s\n", hw.data());
    StringArray<512> arr512("Array 512!");
    StringArray<256> arr256(arr512);
    arr256[6] = '2';
    printf("%s\n", arr256.data());
    arr512.push_back('X');
    printf("%s\n", arr512.data());
    arr256.append(10, '*');
    printf("%s\n", arr256.data());
    hw.append(arr256).append(arr512);
    printf("%s\n", hw.data());
    hw = "new value !\n";
    printf("%s\n", hw.data());

    StringArray<10> eq1, eq2;
    eq1 = "A";
    eq2 = eq1;
    printf("%s == %s ; %i\n", eq1.c_str(),eq2.c_str(), eq1 == eq2);
    printf("%s != %s ; %i\n", eq1.c_str(),eq2.c_str(), eq1 != eq2);
    printf("%s > %s ; %i\n", eq1.c_str(),eq2.c_str(), eq1 > eq2);
    printf("%s >= %s ; %i\n", eq1.c_str(),eq2.c_str(), eq1 >= eq2);
    printf("%s < %s ; %i\n", eq1.c_str(),eq2.c_str(), eq1 < eq2);
    printf("%s <= %s ; %i\n", eq1.c_str(),eq2.c_str(), eq1 <= eq2);

    printf("%s\n", "--------------------------------------------------");
    StringArray<10> neq1, neq2;
    neq1 = "A";
    neq2 = "B";
    printf("%s == %s ; %i\n", neq1.c_str(),neq2.c_str(), neq1 == neq2);
    printf("%s != %s ; %i\n", neq1.c_str(),neq2.c_str(), neq1 != neq2);
    printf("%s > %s ; %i\n" , neq1.c_str(),neq2.c_str(), neq1 > neq2);
    printf("%s >= %s ; %i\n", neq1.c_str(),neq2.c_str(), neq1 >= neq2);
    printf("%s < %s ; %i\n" , neq1.c_str(),neq2.c_str(), neq1 < neq2);
    printf("%s <= %s ; %i\n", neq1.c_str(),neq2.c_str(), neq1 <= neq2);

    printf("%s\n", "--------------------------------------------------");
    std::swap(neq1, neq2);
    printf("%s ,%s \n", neq1.c_str(),neq2.c_str());
    neq1.swap(neq2);
    printf("%s ,%s \n", neq1.c_str(),neq2.c_str());
    return 0;
}
