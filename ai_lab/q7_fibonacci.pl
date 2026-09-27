gofib:-
   write('enter the value for n: '),read(N),
   fib(N,R),
   write('the nth term is: '),
   write(R).

fib(1, 0).
fib(2, 1).
fib(N, Result) :-
   N > 2,
   N1 is N - 1,
   N2 is N - 2,
   fib(N1, F1),
   fib(N2, F2),
   Result is F1 + F2.
