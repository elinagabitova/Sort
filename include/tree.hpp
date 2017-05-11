#include <iostream>
template <typename Iterator>
void insertion_sort(Iterator begin , Iterator end)
{
   if(!(begin < end))
    return;
   for(Iterator i = begin + 1 ; i != end ; ++i)
    for(Iterator j = i; j != begin && *j < *(j-1); --j)
        std::iter_swap(j - 1, j);
}
