isPrime :: Int -> Bool
isPrime n
  | n <= 1    = False
  | otherwise = all (\x -> n `mod` x /= 0) [2..intSqrt n]

intSqrt :: Int -> Int
intSqrt = floor . sqrt . fromIntegral

primes :: [Int]
primes = filter isPrime [2..]

problem1 :: Int -> [Int]
problem1 n = take n [p | p <- primes, even $ length $ takeWhile (/= p) primes]



fibonacci :: Int -> Int
fibonacci 0 = 0
fibonacci 1 = 1
fibonacci n = fibonacci (n-1) + fibonacci (n-2)

filterFibonacci :: Int -> [Int] -> [Int]
filterFibonacci _ [] = []
filterFibonacci n (x:xs)
  | x <= n && x `mod` 10 == 3 = x : filterFibonacci n xs
  | otherwise = filterFibonacci n xs

problem2 :: Int -> [Int]
problem2 n = filterFibonacci n $ takeWhile (<= n) [fibonacci i | i <- [1..]]



multipleOfFive :: Int -> Bool
multipleOfFive x = x `mod` 5 == 0

hasThreeFactors :: Int -> Bool
hasThreeFactors x = length [d | d <- [1..x], x `mod` d == 0] == 3

problem3 :: Int -> [Int]
problem3 n = [x | x <- [1..n], multipleOfFive x || hasThreeFactors x]

main :: IO ()
main = do
  print $ problem1 10
  print $ problem1 7
  print $ problem2 100
  print $ problem2 10000
  print $ problem3 100