# credit-card-validator

Credit Card Validator - Takes in a credit card number from a common credit card
issuer (e.g. Visa) and validates it to make sure that it is a valid card number.
Validation method must be using the
[Luhn](https://en.wikipedia.org/wiki/Luhn_algorithm) algorithm. See
[Payment card number - Wikipedia](https://en.wikipedia.org/wiki/Payment_card_number#Issuer_identification_number_.28IIN.29)
for more information.

Project Idea Credits: [karan/Projects](https://github.com/karan/Projects)

## Compile

```bash
g++ -Wall -std=c++17 -o prog main.cpp
```

## Run

```bash
./prog
```
