#include <iostream>
#include <ctime> 
#include <map>
#include <array>
#include <list>

int econ() {
    int rate = rand() % 21 - 10;  
    return rate;
}


void populateRandomJobs(const vector<string>& joblist) {

    srand(static_cast<unsigned int>(time(0)));


    int numJobs = rand() % 11 + 10; 

    for (int i = 0; i < numJobs; ++i) {
        int randomIndex = rand() % joblist.size();
        jobList.push_back(joblist[randomIndex]);
    }

    map<string, int> jobCount;
    for (const auto& job : jobList) {
        jobCount[job]++;
    }

    cout << "Job Counts:" << std::endl;
    for (const auto& entry : jobCount) {
        cout << entry.first << ": " << entry.second << endl;
    }
}

void policy(map<string, array<list<int>, 3>>& jobMarket,int rate) {
    int randomChance = rand() % 100;
    randomChance = randomChance + rate;
    if (randomChance < 3) {
        
        for (auto& company : jobMarket) {
            company.second[2] = 0; 
        }
        cout << "Policy: Closed job market for international students.\n";
    }  
    else if(randomChance > 3 && randomChance < 40){
        
        cout << "Policy: Tax benefits for hiring more employees.\n";
        for (auto& company : jobMarket) {
            for (auto& jobList : company.second) {
                for (auto& job : jobList) {
                    job += 5; 
                }
            }
        }
    }

int tech(int rate) {
    int randomEvent = rand() % 3;
    int randomChance = rand() % 100;
    if (randomEvent == 0) {
        randomChance += (rate*2)

        cout << "Tech: New product release boosts job opportunities.\n";
    } else if (randomEvent == 1) {
        if (rate >0){randomChance += rate;}
        cout << "Tech: Adoption of new technology improves efficiency.\n";
    } else {
        randomChance = 0 - randomChande;
        cout << "Tech: Sales decrease, leading to reduced hiring.\n";
    }
    return radomChance;
}


int mian(){
    vector<string> jobList;
    ifstream inputFile("testing.txt");
    if (!inputFile) {
        cerr << "Error: Unable to open file." << endl;
        return 1;
    }
    while (inputFile >> companyName >> jobCategory) {
        
        inputFile.ignore();
        getline(inputFile, jobTitle);
        jobList.push_back(jobTitle);
    }

    inputFile.close();

    srand(static_cast<unsigned int>(time(0)));
    int randomIndex = rand() % jobList.size();
    string randomJob = jobList[randomIndex];

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


 for (int i = 0; i < 36; ++i) {
        cout << "\n--- Time Period " << (i + 1) << " ---\n";

        int economicRate = econ();
        cout << "Economic rate change: " << economicRate << "%\n";

        policy(jobMarket, economicRate);

        int techImpact = tech(economicRate);
        cout << "Tech impact: " << techImpact << "%\n";

        for (const auto& company : jobMarket) {
            cout << "Company: " << company.first << "\n";
            int categoryIndex = 1;
            for (const auto& jobList : company.second) {
                cout << "  Job Category " << categoryIndex++ << ": ";
                for (const auto& job : jobList) {
                    cout << job << " ";
                }
                cout << "\n";
            }
        }
 }

return 0;
}
