#include <iostream>
#include <string>
#include <sstream>
#include <chrono>

class Solution
{
public:
    std::string fractionToDecimal(int numerator, int denominator)
    {
        std::string decimal, reduced_decimal;
        int quotient, remainder, old_remainder, rec_start = 0;
        std::stringstream ss;
        int *remainders[2];
        remainders[0] = new int[denominator];
        remainders[1] = new int[denominator];
        quotient = numerator / denominator;
        remainder = numerator % denominator;
        remainders[0][remainder] = 1;
        remainders[1][remainder] = 0;
        old_remainder = remainder;
        for (int i = 1; i < denominator; i++)
        {
            ss << std::to_string((10 * remainder) / denominator);
            remainder = 10 * old_remainder % denominator;
            
            if (remainders[0][remainder]!=1)
            {
                remainders[0][remainder] = 1;
                remainders[1][remainder] = i;
            }
            else
                break;
            
            old_remainder = remainder;
        }
        // Processing left
        std::string temp = ss.str();
        rec_start = remainders[1][remainder];
        decimal = std::to_string(quotient) + "." + temp.substr(0, rec_start) + "(" + temp.substr(rec_start) + ")";
        return decimal;
    }
};

int main()
{
    int n, d;
    auto start = std::chrono::high_resolution_clock::now();
    std::cout << "Enter Numerator: ";
    std::cin >> n;
    std::cout << "Enter Denominator: ";
    std::cin >> d;
    Solution s;
    std::string dd;
    dd = s.fractionToDecimal(n, d);
    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::seconds>(end - start).count();
    std::cout << "Decimal Part: " << dd << "\nIn " << duration << " seconds.\n";
}