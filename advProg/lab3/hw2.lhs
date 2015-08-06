> import Data.List

> data Peg = Red | Green | Blue | Yellow | Orange | Purple
>	deriving (Show, Eq, Ord)

> type Code = [Peg]

> exactMatches :: Code -> Code -> Int
> exactMatches xs ys = foldl (\acc (x,y) -> if x == y then (+) acc 1 else (+) acc 0) 0 (zip xs ys) 


> colors :: Code
> colors = [Red, Green, Blue, Yellow, Orange, Purple]
> colors' :: Code
> colors' = [Red, Blue, Blue, Yellow, Purple, Orange]

 countColors :: Code -> [Int]
 countColors xs = map (foldr (\acc x y -> if x == y then acc + 1 else acc + 0) 0 xs) colors

 map :: (a -> b) -> [a] -> [b]

> help xs = map (\x -> x == Blue) xs

> help' xs = length $ filter (\x -> x == Blue) xs

> help'' xs =  filter ((\x y -> x == y) Red) colors

> halp xs c = foldr (\acc x y -> if x == y then acc + 1 else acc + 0) 0 xs c
