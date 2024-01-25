
char get_symbol(const int code) {
    return code < 10 ? (0x30 + code) : ('A' + code - 10);
}

void convertToHex(unsigned long long number) {
    const int bufferSize = 18; // Количество символов для числа и "0x"
    char hexNumber[bufferSize] = "0x";

    for (int i = bufferSize - 3; i > 1; i--) {
        unsigned char nibble = (number & 0xF000000000000000) >> (i - 2) * 4;
        hexNumber[bufferSize - i] = get_symbol(nibble);
    }

    std::cout << hexNumber << std::endl;
}

int main() {
    unsigned long long number;
    std::cout << "Enter a decimal number: ";
    std::cin >> number;

    convertToHex(number);

    return 0;
}
