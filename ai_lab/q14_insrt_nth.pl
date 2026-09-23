goins:-
    write('Enter the list:'),
    read(L),
    write('Enter the position:'),
    read(N),
    write('Enter the element to be inserted:'),
    read(I),
    insert_nth(I,N,L,R),
    write('The resultant list is:'),
    write(R).



insert_nth(I,1,T,[I|T]):-!.
insert_nth(I,N,[Y|T],[Y|T1]):-
    N>1,
    N1 is N-1,
    insert_nth(I,N1,T,T1).