#include <QList>
#include "primelist.h"

bool thisPrime(int number) {
    if (number <= 1) {
        return false;
    }
    for (int i = 2; i * i <= number; ++i) {
        if (number % i == 0) {
            return false;
        }
    }
    return true;
}

// Выводит список простых чисел в заданном интервале
QList<int> getPrimes(int start, int end) {
    QList<int> primes;
    for (int i = start; i <= end; ++i) {
        if (thisPrime(i)) {
            primes.append(i);
        }
    }
    return primes;
}

