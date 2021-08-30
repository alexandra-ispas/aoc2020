import System.IO
import Control.Monad
import Data.List
import Data.Maybe

{-
    Function which converts a string to an int.
    Used for converting input from a file
-}
readInt :: String -> Int
readInt = read

{-
    task1 
    given a file with a list of numbers, find
    a pair of 2 numbers a and b so that
    a+b=2020. What is a*b =?
-}
task1 :: FilePath -> IO ()
task1 path = do file <- readFile path
                let x = map readInt $ words file
                let l = head $ [(a, b) | a <- x, b <- x, a + b == 2020, a /= b]
                print (uncurry (*) l)

{-
    task2
    given a file with a list of numbers, find
    3 numbers a, b and c so that
    a+b+c=2020. What is a*b*c =?
-}
task2 :: FilePath -> IO ()
task2 path = do file <- readFile path
                let x = map readInt $ words file
                let l@(n1, n2, n3) = head $ [(a, b, c) | a <- x, b <- x, c <- x, a + b + c == 2020, a /= b, a /= c]
                print (n1*n2*n3)
