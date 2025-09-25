#include <iostream>
#include <string>
#include <sstream>
#include <vector>

class Solution
{
private:
    int find_index(std::vector<int> remainders, int remainder) // Write this function using hash-tables to get a faster result
    {
        size_t length;
        length = remainders.size();
        int pos = -1;
        for (int i = 0; i < length; i++)
        {
            if (remainder == remainders[i])
            {
                pos = i;
                return pos;
            }
        }
        return pos;
    }

public:
    std::string fractionToDecimal(int numerator, int denominator)
    {
        std::string decimal, reduced_decimal;
        int quotient, remainder, rec_start;
        std::stringstream ss;
        std::vector<int> remainders;
        quotient = numerator / denominator;
        remainder = numerator % denominator;
        remainders.push_back(remainder);
        for (int i = 1; i < denominator; i++)
        {
            ss << std::to_string((10 * remainder) / denominator);
            remainder = 10 * remainders[i - 1] % denominator;
            rec_start = find_index(remainders, remainder);
            if (rec_start < 0)
            {
                remainders.push_back(remainder);
            }
            else
                break;
        }
        // Processing left
        std::string temp = ss.str();
        decimal = std::to_string(quotient) + "." + temp.substr(0, rec_start) + "(" + temp.substr(rec_start) + ")";
        return decimal;
    }
};

int main()
{
    int n, d;
    std::cout << "Enter Numerator: ";
    std::cin >> n;
    std::cout << "Enter Denominator: ";
    std::cin >> d;
    Solution s;
    std::string dd;
    dd = s.fractionToDecimal(n, d);
    std::cout << "Decimal Part: " << dd << "\n";
}