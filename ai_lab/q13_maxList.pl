gomax:-
write('enter the list:'),
read(L),
maxlist(L,M),
write('Max element:'),
write(M),nl.


maxlist([X],X).
maxlist([H|T],M):-
    maxlist(T,M1),
    M is max(H,M1).