gomemb:-
   write('enter the element: '),
   read(X),
   write('write the list: '),
   read(L),
   write('is this present:'),
   is_memb(X,L).

is_memb(A,[A|_]):-!.
is_memb(A,[_|T]):-
   is_memb(A,T).
