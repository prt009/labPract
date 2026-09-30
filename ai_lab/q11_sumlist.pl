gosuml:-
   write('enter the list: '),read(X),
   sumlst(X,S),
   write('sum of the list is:'),write(S).

sumlst([],0).
sumlst([H|T],S):-
   sumlst(T,R1),
   S is H + R1.
