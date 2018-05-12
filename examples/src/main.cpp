/*******************************************************************************
*  file    : main.cpp
*  created : 12.05.2018
*  author  : Slyshyk Oleksiy (alexslyshyk@gmail.com)
*******************************************************************************/

#include <cstdio>
#include <stringarray.hpp>

int main()
{
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
    return 0;
}
