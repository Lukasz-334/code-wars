#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>


template<class Iter>
int funCount(Iter first,Iter last,const int x){

return std::count_if(first,last,[&x](auto el){
   return el == x;
});

}

bool invite_more_women(const std::vector<int> &invited) {
  
return funCount(invited.begin(),invited.end(),1)>funCount(invited.begin(),invited.end(),-1);
  
}
