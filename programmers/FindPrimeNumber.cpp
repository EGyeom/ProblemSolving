#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> primes(10000001,0);
vector<bool> dupeCheck(10000001,0);
vector<bool> isChecked(8,0);
int primeCounter = 0;

int myStoi(string numbers)
{
    int number = 0;

    for(int i =0; i < numbers.size(); i++)
    {
        number *= 10;
        number += numbers[i] - '0';
    }

    return number;
}

void PrimeCalculator()
{
    primes[0] = 2;
    primes[1] = 2;
    for(int i = 2; i < 10000000; i++)
    {
        if(primes[i] >= 2)
            continue;
        for(int j = 1; i*j < 10000000; j++)
        {
            primes[i*j]++;
        }
    }
}

void permutation(string numbers, string tempNum, int cnt)
{
    if(cnt == tempNum.size())
    {
        int num = myStoi(tempNum);
        if(primes[num] < 2)
            if(dupeCheck[num] == false)
            {
                dupeCheck[num] = true;
                primeCounter++;
            }
        return;
    }

    for(int i = 0; i < numbers.size(); i++)
    {
        if(isChecked[i] == false)
        {
            isChecked[i] = true;
            tempNum.push_back(numbers[i]);
            permutation(numbers, tempNum, cnt);
            tempNum.pop_back();
            isChecked[i] = false;
        }
    }
}

int solution(string numbers) {

    int answer = 0;
    PrimeCalculator();
    int number = myStoi(numbers);
    int numLength = numbers.size();
    for(int cnt = 1; cnt <= numLength; cnt++)
    {
        for(int i = 0; i < numLength; i++)
        {
            string tempNum = "";
            if(isChecked[i] == false)
            {
                isChecked[i] = true;
                tempNum.push_back(numbers[i]);
                permutation(numbers, tempNum, cnt);
                tempNum.pop_back();
                isChecked[i] = false;
            }
        }
    }
    answer = primeCounter;
    return answer;
}

/*

next_permutation()
std::stoi()

*/