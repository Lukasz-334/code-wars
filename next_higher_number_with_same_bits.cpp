int countPositiveBit(int num) {
    int count = 0;
    while (num != 0) {
        count += num & 1;
        num >>= 1;
    }
    return count;
}

int nextHigher(int value) {
    int count = countPositiveBit(value);

    value++;
    while (count != countPositiveBit(value)) {
        value++;
    }

    return value;
}
