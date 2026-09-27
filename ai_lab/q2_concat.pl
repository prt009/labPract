goconcat:-
  write('Enter first list:'),read(L1),
  write('Enter second list: '),read(L2),
  concat(L1,L2,R),
  write('the result is: '),write(R).


concat([],L2,L2).
concat([H|T],L2,[H|R]):-
  concat(T,L2,R).
