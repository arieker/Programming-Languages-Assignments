function factorial(n: number): number {
    if (n === 0 || n === 1) return 1;
    return n * factorial(n - 1);
}

function nthLexicographicPermutation(digits: number[], n: number): number[] | null {
    const permutation: number[] = [];
    let remainingDigits = [...digits];
    let remainingPermutations = n - 1;

    for (let i = digits.length; i > 0; i--) {
        const fact = factorial(i - 1);
        const index = Math.floor(remainingPermutations / fact);
        if (index >= remainingDigits.length) return null;
        permutation.push(remainingDigits[index]);
        remainingDigits.splice(index, 1);
        remainingPermutations %= fact;
    }

    return permutation;
}

const digits = [0, 1, 2, 3, 4, 5, 6, 7, 8, 9];
const millionthPermutation = nthLexicographicPermutation(digits, 1000000);
if (millionthPermutation) {
    console.log("The millionth lexicographic permutation is:", millionthPermutation.join(""));
} else {
    console.log("There is no millionth permutation for given digits.");
}


const filename = 'words.txt';
const triangleWordCount = countTriangleWords(filename);
console.log("Number of triangle words:", triangleWordCount);

function countWaysToMakeTwoPounds(): number {
    const targetAmount = 200;
    const coins = [1, 2, 5, 10, 20, 50, 100, 200];
    const ways: number[] = Array(targetAmount + 1).fill(0);
    ways[0] = 1;

    for (const coin of coins) {
        for (let amount = coin; amount <= targetAmount; amount++) {
            ways[amount] += ways[amount - coin];
        }
    }

    return ways[targetAmount];
}

const numberOfWays = countWaysToMakeTwoPounds();
console.log("Number of different ways to make £2:", numberOfWays);

import * as fs from 'fs';

function wordValue(word: string): number {
    return word.split('').reduce((acc, char) => acc + (char.charCodeAt(0) - 64), 0);
}

function isTriangleNumber(num: number): boolean {
    const n = Math.floor(Math.sqrt(2 * num));
    return n * (n + 1) === 2 * num;
}

function countTriangleWords(filename: string): number {
    const words = fs.readFileSync(filename, 'utf-8').split(',').map(word => word.slice(1, -1));
    let count = 0;

    for (const word of words) {
        const value = wordValue(word);
        if (isTriangleNumber(value)) {
            count++;
        }
    }

    return count;
}