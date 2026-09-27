gomult:-
   write('enter the first number: '),read(A),
   write('enter the second number: '),read(X),
   write('the product is: '),mult(A,X,Y),
   write(Y).

mult(A,X,Y):-  A is X * Y.