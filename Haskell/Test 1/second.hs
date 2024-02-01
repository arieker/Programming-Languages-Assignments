isPalindrome :: Int -> Bool
isPalindrome x = reverseDigits x == x

reverseDigits :: Int -> Int
reverseDigits = read . reverse . show

sumEvenDigits :: Int -> Int
sumEvenDigits = sum . map (subtract 48 . fromEnum) . filter evenDigit . show
  where
    evenDigit c = c >= '0' && c <= '9' && even (fromEnum c)

isPrime :: Int -> Bool
isPrime x
  | x < 2 = False
  | otherwise = all (\d -> x `mod` d /= 0) [2..isqrt x]

isqrt :: Int -> Int
isqrt = floor . sqrt . fromIntegral

solveProblem2 :: Int -> Int
solveProblem2 n = sum $ map sumEvenDigits $ filter isPalindromePrimes [1..n]
  where
    isPalindromePrimes x = isPalindrome x && isPrime x

main :: IO ()
main = do
    putStrLn "solveProblem2 10"
    print (solveProblem2 10)

    putStrLn "solveProblem2 100"
    print (solveProblem2 100)

    putStrLn "solveProblem2 1000"
    print (solveProblem2 1000)

    putStrLn "solveProblem2 10000"
    print (solveProblem2 10000)

    putStrLn "solveProblem2 100000"
    print (solveProblem2 100000)

    putStrLn "solveProblem2 1000000"
    print (solveProblem2 1000000)