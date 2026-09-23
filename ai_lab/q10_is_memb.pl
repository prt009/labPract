gomemb:-
write('enter the element: '),
read(X),nl,
write('write the list: '),
read(L),nl,
write('is this present:'),
is_memb(X,L).

is_memb(A,[A|_]).
is_memb(A,[H|T]):-
    is_memb(A,T).