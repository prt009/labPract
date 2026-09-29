gopow:-
   write('enter the base: '),read(B),
   write('enter the exponent: '),read(P),
   power(B,P,R),
   write('the value is: '),write(R).

power(_, 0, 1) :- !.
power(Base, Exp, Res) :-
   Exp > 0,
   NxtE is Exp - 1,
   power(Base, NxtE, SubRes),
   Res is Base * SubRes.
