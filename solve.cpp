#include <iostream>
#include <string>
#include <vector>
#include <tuple>
#include <map>

using namespace std;

vector<int> fees = {180, 5000, 10, 600};
vector<string> records = {"05:34 5961 IN", "06:00 0000 IN", "06:34 0000 OUT", "07:59 5961 OUT", "07:59 0148 IN", "18:59 0000 IN", "19:09 0148 OUT", "22:59 5961 IN", "23:00 5961 OUT"};

vector<int> solution() {
    vector<int> answer;
    
    map<string, tuple<bool, int, int>> input;
    for (string record : records)
    {
        string code = record.substr(11);
        int time = stoi(record.substr(0, 2)) * 60 + stoi(record.substr(3, 2));
        string car = record.substr(6, 4);
        
        if (code == "IN")
        {
            get<0>(input[car]) = true;
            get<1>(input[car]) = time;
        }
        else
        {
            int parking = time - get<1>(input[car]);
            get<0>(input[car]) = false;
            get<1>(input[car]) = 0;
            get<2>(input[car]) += parking;
        }
    }
    
    for (auto it : input)
    {
        if (get<0>(it.second) == true)
        {
            int parking = 1439 - get<1>(it.second);
            get<0>(it.second) = false;
            get<1>(it.second) = 0;
            int time = get<2>(it.second);
            get<2>(it.second) = time + parking;
        }
    }
    
    map<string, int> costs;
    cout << "디버그\n";
    for (auto it : input)
    {
        cout << "안 오나?\n";
        int parking = get<2>(it.second);
        cout << "이거는? " << parking << '\n'; 
        int cost = 0;
            
        if (parking <= fees[0])
            cost = fees[1];
        else
        {
            parking -= fees[0];
            cout << parking << " 주차시간\n";
            cost += fees[1];

            if (!(parking % fees[2]))
            {
                parking /= fees[2];
                cout << parking << " 단위 시간\n";
            }
            else
            {
                parking /= fees[2];
                parking++;
                cout << parking << " 단위 시간\n";                
            }
            
            cout << parking * fees[3] << " 주차요금\n";
            cost += (parking * fees[3]);
        }

        costs.insert({it.first, cost});
    }
    
    for (auto it : costs)
        answer.push_back(it.second);
    
    return answer;
}

int main()
{
    for (int ans : solution())
        cout << ans << ' ';
}