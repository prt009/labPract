goeos:-
    write('enter the list: '),
    read(L),
    evenlen(L).

evenlen([]):-write('the list is even.'),!.
evenlen([_]):-write('the list is odd.'),!.
evenlen([_|T]):-oddlen(T).
oddlen([_|T]):-evenlen(T).