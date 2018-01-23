#include <iostream>
#include <utility>
#include <vector>
#include <unordered_map>
using namespace std;
using pairSum = pair<int,int>;
using sumMap = unordered_map<int,int>;

pairSum getPair(int sum, vector<int>& vec){
   sumMap new_map;
   for(auto& element : vec){
       auto it = new_map.find(element);
       if(it != new_map.end())
          return std::make_pair(it->first,it->second);
      int index = sum-element;
      new_map[index] = element;
   }
   return make_pair(0,0);
   
}

int main(){
   vector<int> test = {3,5,6,7};
   pairSum new_pair = getPair(8,test);
   cout << new_pair.first << "-----" << new_pair.second << endl;
}