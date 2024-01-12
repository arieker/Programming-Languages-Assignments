{-# OPTIONS_GHC -Wno-unrecognised-pragmas #-}
{-# HLINT ignore "Use camelCase" #-}
multiply2 :: Num a => a -> a -> a
multiply2 x y = x * y
result1 = multiply2 2 8

multiply3 :: Num a => a -> a -> a -> a
multiply3 x y z = x * y * z
result2 = multiply3 2 8 3

first_a :: Int -> [Int]
first_a n = [x | x <- [1..n], x `mod` 6 == 0 || x `mod` 11 == 0]
result3 = first_a 25

isMult6Or11 :: Int -> Bool
isMult6Or11 n = n `mod` 6 == 0 || n `mod` 11 == 0

first_b :: Int -> [Int]
first_b n = [x | x <- [1..n], isMult6Or11 x]
result4 = first_b 25

second_a :: Int -> [Int]
second_a n = [x | x <- [1..n], show x == reverse (show x), head (show x) == '3']
result5 = second_a 500

isPalindromeThatStartsWithDigit3 :: Int -> Bool
isPalindromeThatStartsWithDigit3 n = show n == reverse (show n) && head (show n) == '3'

second_b :: Int -> [Int]
second_b n = [x | x <- [1..n], isPalindromeThatStartsWithDigit3 x]
result6 = second_b 500

main = do
  print result1
  print result2
  print result3
  print result4
  print result5
  print result6