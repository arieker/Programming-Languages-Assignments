function collatzSequenceLength(n)
{
    let length = 1;
    while (n !== 1)
    {
        if (n % 2 === 0)
        {
            n /= 2;
        } else
        {
            n = 3 * n + 1;
        }
        length++;
    }
    return length;
}

function findLongestCollatzChain(upperLimit)
{
    let maxLength = 0;
    let number = 0;

    for (let i = 2; i < upperLimit; i++)
    {
        let length = collatzSequenceLength(i);
        if (length > maxLength)
        {
            maxLength = length;
            number = i;
        }
    }

    return { number: number, length: maxLength };
}

function factorial(n)
{
    if (n === 0 || n === 1)
    {
        return BigInt(1);
    } else
    {
        return BigInt(n) * factorial(n - 1);
    }
}

function sumOfDigitsInFactorial(n)
{
    const factorialResult = factorial(n);
    const factorialString = factorialResult.toString();
    
    let sum = 0;
    for (let i = 0; i < factorialString.length; i++)
    {
        sum += parseInt(factorialString[i]);
    }

    return sum;
}

const result = findLongestCollatzChain(1000000);
console.log(result.number);

const n = 100;
const sum = sumOfDigitsInFactorial(n);
console.log(sum);



