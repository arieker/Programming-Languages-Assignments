isValidNumber :: Int -> Bool
isValidNumber x = even x && x `mod` 5 == 0 && head (show x) == '6'

solveProblem1 :: Int -> [Int]
solveProblem1 n = filter isValidNumber [1..n]

main :: IO ()
main = do
    putStrLn "solveProblem1 10"
    print (solveProblem1 10)

    putStrLn "solveProblem1 100"
    print (solveProblem1 100)

    putStrLn "solveProblem1 1000"
    print (solveProblem1 1000)

    putStrLn "solveProblem1 10000"
    print (solveProblem1 10000)

    putStrLn "solveProblem1 100000"
    print (solveProblem1 100000)