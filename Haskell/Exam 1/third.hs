isPrime :: Int -> Bool
isPrime x
  | x < 2 = False
  | otherwise = all (\d -> x `mod` d /= 0) [2..isqrt x]

isqrt :: Int -> Int
isqrt = floor . sqrt . fromIntegral

primeFactors :: Int -> [Int]
primeFactors x = filter (\f -> x `mod` f == 0 && isPrime f) [2..x `div` 2]

solveProblem3 :: Int -> Int
solveProblem3 n = sum $ concatMap primeFactors [2..n]

main :: IO ()
main = do
    putStrLn "solveProblem3 10"
    print (solveProblem3 10)

    putStrLn "solveProblem3 100"
    print (solveProblem3 100)

    putStrLn "solveProblem3 1000"
    print (solveProblem3 1000)

    putStrLn "solveProblem3 3000"
    print (solveProblem3 3000)