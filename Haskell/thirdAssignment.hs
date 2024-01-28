doubleList :: Num a => [a] -> [a]
doubleList = map (*2)

evenNumbers :: [Int] -> [Int]
evenNumbers = filter even

multiplyByThree :: [Int] -> [Int]
multiplyByThree = map (*3)

sumOfSquaresOfOdds :: [Int] -> Int
sumOfSquaresOfOdds = sum . map (^2) . filter odd

main :: IO ()
main = do
    let task1Result = doubleList [1, 5, -18, 99]
    putStrLn $ "Task 1 Result: " ++ show task1Result

    let task2Result = evenNumbers [1..100]
    putStrLn $ "Task 2 Result: " ++ show task2Result

    let task3Result = multiplyByThree [1, 3..77]
    putStrLn $ "Task 3 Result: " ++ show task3Result

    let task4Result = sumOfSquaresOfOdds [1, 2, 3, 4, 5, 7, 8, 1, 43, 25, 65, 22]
    putStrLn $ "Task 4 Result: " ++ show task4Result