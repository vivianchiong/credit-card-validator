#include <iostream>

template <typename T>
void enterInput(const std::string& str, T& arg)  {
    do {
        if (std::cout << str &&
            std::cin >> arg &&
            std::to_string(arg).length() >= 8 &&
            std::to_string(arg).length() <= 19) break;
        std::cout << "Invalid input, please re-enter ... " << std::endl;
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    } while (true);

    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

bool validateCardNum(unsigned long long int num) {
    auto strNum = std::to_string(num);

    // Save and drop check digit
    int checkDigit = num % 10;
    auto payload = strNum.substr(0, strNum.length() - 1);

    // Fill out array of multipliers
    int length = payload.length();
    int multipliers[length];
    int maxIdx = length - 1;
    for (int i = 0; i < length; ++i) {
        multipliers[maxIdx - i] = (i % 2 == 0) ? 2 : 1;
    }

    // Calculate sum
    int totalSum = 0;
    for (int i = 0; i < length; ++i) {
        int payloadDigit = payload.at(i) - '0';
        int partialSum = payloadDigit * multipliers[i];

        if (partialSum >= 10) {
            totalSum += 1 + (partialSum % 10); // Sum digits of partial sum
        } else {
            totalSum += partialSum;
        }
    }

    // Compare check digits
    auto newCheckDigit = (10 - (totalSum % 10)) % 10;
    return newCheckDigit == checkDigit;
}

int main(int argc, char* const argv[]) {
    unsigned long long int cardNum = 0;
    enterInput<unsigned long long int>("Enter credit card number: ", cardNum);

    if (validateCardNum(cardNum)) {
        std::cout << "Card number is valid!" << std::endl;
    } else {
        std::cout << "Card number is NOT valid!" << std::endl;
    }
}