Luhn algorithm

> doubleList :: [Integer] -> [Integer]
> doubleList [] = []
> doubleList (x:[]) = x : []
> doubleList (x:y:xs) = x + x : y : doubleList xs

> addList :: [Integer] -> Integer
> addList [] = 0
> addList (x:xs) = convertNum x + addList xs

> convertNum :: Integer -> Integer
> convertNum x = n + m
>	where 
>		n = x `div` 10
>		m = x `mod` 10

> l1 = [2,4,7,5,9,1,5,3,7,9]
> l2 = [1..5]
> l3 = [2, 3, 1, 1]

> cardIsValid :: Integer -> Bool
> cardIsValid n =  (\x -> x `mod` 10 == 0) $ addList $ doubleList $ toDigits n


> lastDigit :: Integer -> Integer
> lastDigit x = x `mod` 10

> dropLastDigit :: Integer -> Integer
> dropLastDigit x = x `div` 10

> toRevDigits :: Integer -> [Integer]
> toRevDigits 0 = []
> toRevDigits x = lastDigit x : toRevDigits (dropLastDigit x)

> toDigits :: Integer -> [Integer]
> toDigits x = reverse $ toRevDigits x


Hanoi

> type Peg = String
> type Move = (Peg, Peg)

> hanoi :: Integer -> Peg -> Peg -> Peg -> [Move]
> hanoi 0 a b c = []
> hanoi n a b c = hanoi (n-1) a c b ++ [(a,b)] ++ hanoi (n-1) c b a

