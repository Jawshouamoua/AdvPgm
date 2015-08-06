

Ex 1:

> conjunction :: Bool -> Bool -> Bool
> conjunction False _ = False
> conjunction True False = False
> conjunction True True = True

> implication :: Bool -> Bool -> Bool
> implication True False = False
> implication True True = True
> implication False _ = True 

Ex 2:

> sub :: Int -> Int -> Int
> sub 0 _ = 0
> sub x 0 = x
> sub x y = x - y

sub 0 _ = 0
sub x 0 = x
sub (Succ x) (Succ y) = sub x y

> lt :: Int -> Int -> Bool
> lt x y = x < y

lt 0 0 = False
lt 0 (Succ y) = True
lt (Succ x) 0 = False
lt (Succ x) (Succ y) = lt x y


> lte = Int -> Int -> Bool
> lte x y = x <= y

lte 0 0 = True
lte 0 (Succ y) = True
lte (Succ x) 0 = False
lte (Succ x) (Succ y) = lte x y


ex 3:


