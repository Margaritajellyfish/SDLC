#include <iostream>
#include <fstream>
#include <ctime>
#include <map>
#include <array>
#include <list>
#include <vector>
#include <cmath>
#include <algorithm> 

using namespace std;


int econ() {
    int rate = rand() % 21 - 10;
    return rate;
}

void runRanJobs(const vector<string>& joblist, list<string> &category) {
    int numJobs = rand() % 11 + 10;

    for (int i = 0; i < numJobs; ++i) {
        size_t randomIndex = rand() % joblist.size();
        category.push_back(joblist[randomIndex]);
    }
}

using JobCategories = array<list<string>, 3>;
using JobMarket = map<string, JobCategories>;

void policy(JobMarket &jobMarket, int rate, const vector<string>& jobList) {
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
            for (auto& jobListCategory : company.second) {
                size_t randomIndex = rand() % jobList.size();
                jobListCategory.push_back(jobList[randomIndex]);
            }
        }
    } else if (randomChance >= 40 && randomChance < 60) {
        
        cout << "Policy: Reopened job market for international students.\n";
        for (auto& company : jobMarket) {
            
            size_t randomIndex = rand() % jobList.size();
            company.second[2].push_back(jobList[randomIndex]);
        }
    }
}


void tech(JobMarket &jobMarket, int rate, const vector<string>& jobList) {
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
        for (auto &jobListCategory : company.second) {
            int currentSize = jobListCategory.size();
            int adjustment = static_cast<int>(round(currentSize * rate / 100.0));

            
            if (currentSize == 0 && rate > 0) {
                adjustment = max(1, static_cast<int>(round(rate / 10.0)));
            }

            if (adjustment > 0) {
                for (int i = 0; i < adjustment; ++i) {
                    size_t randomIndex = rand() % jobList.size();
                    jobListCategory.push_back(jobList[randomIndex]);
                }
            } else if (adjustment < 0) {
                adjustment = abs(adjustment);
                for (int i = 0; i < adjustment && !jobListCategory.empty(); ++i) {
                    jobListCategory.pop_back();
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
        cerr << "Error: Unable to open file 'testing.txt'." << endl;
        return 1;
    }

    string jobTitle;
    while (getline(inputFile, jobTitle)) {
        if (!jobTitle.empty()) {
            jobList.push_back(jobTitle);
        }
    }

    inputFile.close();

    
    srand(static_cast<unsigned int>(time(0)));

    
    vector<string> companyNames = {"Orange", "MacroH", "Booble", "CompanyC", "stardown"};
    for (const auto& companyName : companyNames) {
        jobMarket[companyName] = {list<string>(), list<string>(), list<string>()};
        runRanJobs(jobList, jobMarket[companyName][0]);
        runRanJobs(jobList, jobMarket[companyName][1]);
        runRanJobs(jobList, jobMarket[companyName][2]);
    }

    
    for (int i = 0; i < 36; ++i) {
        cout << "\n--- Time Period " << (i + 1) << " ---\n";

        int economicRate = econ();
        cout << "Economic rate change: " << economicRate << "%\n";

        policy(jobMarket, economicRate, jobList);
        tech(jobMarket, economicRate, jobList);

        
        for (const auto& company : jobMarket) {
            cout << "Company: " << company.first << "\n";
            int categoryIndex = 1;
            for (const auto& jobListCategory : company.second) {
                cout << "  Job Category " << categoryIndex++ << ": ";
                for (const auto& job : jobListCategory) {
                    cout << job << " ";
                }
                cout << "\n";
            }
        }
    }
    return 0;
}
