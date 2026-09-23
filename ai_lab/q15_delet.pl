godel:-
    write('Enter the list:'),
    read(L),
    write('Enter the position:'),
    read(N),
    deleten(N,L,R),
    write('The resultant list is:'),
    write(R).


deleten(1,[_|T],T):-!.
deleten(N,[Y|T],[Y|T1]):-
    N>1,
    N1 is N-1,
    deleten(N1,T,T1).