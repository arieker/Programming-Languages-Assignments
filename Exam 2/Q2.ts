function isPrime(num: number): boolean {
    if (num <= 1) return false;
    if (num <= 3) return true;

    if (num % 2 === 0 || num % 3 === 0) return false;

    let i = 5;
    while (i * i <= num) {
        if (num % i === 0 || num % (i + 2) === 0) return false;
        i += 6;
    }

    return true;
}

function sumOfPrimesBelowN(n: number): number {
    let sum = 0;
    for (let i = 2; i < n; i++) {
        if (isPrime(i)) {
            sum += i;
        }
    }
    return sum;
}

const limit = 2000000;
const sumOfPrimes = sumOfPrimesBelowN(limit);
console.log(`The sum of all prime numbers below ${limit} is: ${sumOfPrimes}`);