concat([],L2,L2).
concat([H|T],L2,[H|R]):-
  concat(T,L2,R).
