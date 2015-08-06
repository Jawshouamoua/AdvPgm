Q0:
	In Java or C++, gadts can be implemented with a superclass for all the different representations of 
	type. For example, a list supertype needs a Empty type and a List type. However, this brings up 
	issues with how to pattern match between the two different subtypes. One could look into the subtype
	to get the type, but this violates the nature of OOP, because you're not supposed to see into an
	object to see that kind of information. It's no longer encapsulated. 

Q1:
	

> data Term a where
>	Lit :: Int -> Term Int
>	Succ :: Term Int -> Term Int
>	IsZero :: Term Int -> Term Bool
>	If :: Term Bool -> Term a -> Term a -> Term a
>	Pair :: Term a -> Term b -> Term (a,b)

> eval :: Term a -> a
> eval (Lit i) = i
> eval (Succ t) = 1 + eval t
> eval (IsZero t) = eval t == 0
> eval (If b e1 e2) = if (eval b) then (eval e1) else (eval e2)
> eval (Pair e1 e2) = (eval e1, eval e2)

> newtype Pair a b = P(a,b)

> data Verm = VLit Int | VSucc Verm | VIsZero Verm |
>				VIf Verm Verm Verm | VPr Verm Verm 
>					deriving Show


> t1 = Lit 5
> t2 = Succ t1
> t3 = IsZero t2
> t4 = (If t3 t1 t2)
> t5 = (Pair t2 t3)



