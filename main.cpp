#include <iostream>
#include <ctime> 
#include <map>
#include <array>
#include <list>

int econ() {
    int rate = rand() % 21 - 10;  
    return rate;
}

void policy(map<string, array<list<int>, 3>>& jobMarket) {
    int randomChance = rand() % 100;
    if (randomChance < 3) {
        
        for (auto& company : jobMarket) {
            company.second[2].clear(); 
        }
        cout << "Policy: Closed job market for international students.\n";
    } else {
        
        cout << "Policy: Tax benefits for hiring more employees.\n";
    }

/*
tech(){
if new product
else if newtechnology
else sale decrease;

}
*/

int mian(){
/*
creat the map
map<string, array<list<int>, 3>> jobMarket;
jobMarket["Orange"] = {
list<int>{100, 120}, 
list<int>{50, 60},    
list<int>{20, 30}     
};

jobMarket["MacroH"] = {
list<int>{80, 90},    
list<int>{40, 50},    
list<int>{10, 20}     
};

jobMarket["Booble"] = {
list<int>{70, 75},    
list<int>{60, 65},   
list<int>{25, 30}   
};

jobMarket["CompanyC"] = {
list<int>{50, 55},   
list<int>{70, 80},    
list<int>{15, 20}     
};

jobMarket["stardown"] = {
list<int>{90, 100},   
list<int>{45, 50},   
list<int>{5, 10}      
};

run 36 times;




*/
return 0;
}
