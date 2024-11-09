#include <iostream>
#include <fstream>
#include <ctime> 
#include <map>
#include <array>
#include <list>
#include <vector>
#include <cmath>  

using namespace std;

int econ() {
    int rate = rand() % 21 - 10;  
    return rate;
}

void runRanJobs(vector<string> joblist, list<string> &category) {
    srand(static_cast<unsigned int>(time(0)));

    int numJobs = rand() % 11 + 10; 
    
    for (int i = 0; i < numJobs; ++i) {
    size_t randomIndex = rand() % joblist.size();  
    category.push_back(joblist[randomIndex]);
}

}

using JobCategories = array<list<string>, 3>;
using JobMarket = map<string, JobCategories>;

void policy(JobMarket &jobMarket, int rate) {
    int randomChance = rand() % 100;
    randomChance += rate;

    if (randomChance < 3) {
        for (auto& company : jobMarket) {
            company.second[2].clear(); 
        }
        cout << "Policy: Closed job market for international students.\n";
    } else if (randomChance > 3 && randomChance < 40) {
        cout << "Policy: Tax benefits for hiring more employees.\n";
        for (auto& company : jobMarket) {
            for (auto& jobList : company.second) {
                for (auto& job : jobList) {
                    job += " (Tax Benefit)";  
                }
            }   
        }
    }
}

void tech(JobMarket &jobMarket, int rate){
    int randomEvent = rand() % 3;
    int randomChance = rand() % 100;

    if (randomEvent == 0) {
        randomChance += static_cast<int>(round(rate * 2));
        cout << "Tech: New product release boosts job opportunities.\n";
    } else if (randomEvent == 1) {
        if (rate > 0) {
            randomChance += static_cast<int>(round(rate));
        }
        cout << "Tech: Adoption of new technology improves efficiency.\n";
    } else {
        randomChance = 0 - randomChance;
        cout << "Tech: Sales decrease, leading to reduced hiring.\n";
    }

    for (auto &company : jobMarket) {
        for (auto &jobList : company.second) {
            int currentSize = jobList.size();
            int adjustment = static_cast<int>(round(currentSize * rate / 100.0));
            if (adjustment > 0) {
                for (int i = 0; i < adjustment; ++i) {
                    jobList.push_back("New Tech Job");
                }
            } else if (adjustment < 0) {
                adjustment = abs(adjustment);
                for (int i = 0; i < adjustment && !jobList.empty(); ++i) {
                    jobList.pop_back();
                }
            }
        }
    }
}

int main() {

    JobMarket jobMarket;
    vector<string> jobList;
    ifstream inputFile("testing.txt");
    if (!inputFile) {
        cerr << "Error: Unable to open file." << endl;
        return 1;
    }

    string jobTitle;
    while (getline(inputFile, jobTitle)) {
        jobList.push_back(jobTitle);
    }

    inputFile.close();

    srand(static_cast<unsigned int>(time(0)));
  

    jobMarket["Orange"] = { list<string>(), list<string>(), list<string>() };
    runRanJobs(jobList, jobMarket["Orange"][0]);
    runRanJobs(jobList, jobMarket["Orange"][1]);
    runRanJobs(jobList, jobMarket["Orange"][2]);

    jobMarket["MacroH"] = { list<string>(), list<string>(), list<string>() };
    runRanJobs(jobList, jobMarket["MacroH"][0]);
    runRanJobs(jobList, jobMarket["MacroH"][1]);
    runRanJobs(jobList, jobMarket["MacroH"][2]);

    jobMarket["Booble"] = { list<string>(), list<string>(), list<string>() };
    runRanJobs(jobList, jobMarket["Booble"][0]);
    runRanJobs(jobList, jobMarket["Booble"][1]);
    runRanJobs(jobList, jobMarket["Booble"][2]);

    jobMarket["CompanyC"] = { list<string>(), list<string>(), list<string>() };
    runRanJobs(jobList, jobMarket["CompanyC"][0]);
    runRanJobs(jobList, jobMarket["CompanyC"][1]);
    runRanJobs(jobList, jobMarket["CompanyC"][2]);

    jobMarket["stardown"] = { list<string>(), list<string>(), list<string>() };
    runRanJobs(jobList, jobMarket["stardown"][0]);
    runRanJobs(jobList, jobMarket["stardown"][1]);
    runRanJobs(jobList, jobMarket["stardown"][2]);


    for (int i = 0; i < 36; ++i) {
        cout << "\n--- Time Period " << (i + 1) << " ---\n";

        int economicRate = econ();
        cout << "Economic rate change: " << economicRate << "%\n";

        policy(jobMarket, economicRate);
        tech(jobMarket ,economicRate);

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


