gomult:-
   write('enter the first number: '),read(X),
   write('enter the second number: '),read(Y),
   write('the product is: '),mult(X,Y,A),
   write(A).

mult(X,Y,A):-  A is X * Y.
