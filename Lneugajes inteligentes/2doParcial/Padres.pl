% primer nivel
padre(messi,willy).

% segundo nivel
padre(willy,anton).

% tercer nivel
padre(anton,michael).
padre(anton, goku).

% cuarto nivel
padre(michael,yeyo).
padre(michael,lili).

% quinto nivel
padre(lili,andrea).
padre(lili,maria).
padre(yeyo,jonas).
padre(yeyo,tim).
padre(yeyo,lea).

% sexto nivel
padre(tim,juan).


tatarabuelo(X,Y):-padre(X,Z),padre(Z,W),padre(W,A),padre(A,Y), X \= Y. 
bisabuelo(X,Y):-padre(X,Z),padre(Z,W),padre(W,Y), X \=Y.
abuelo(X,Y):-padre(X,Z),padre(Z,Y), X \=Y.
hermano(X,Y):-padre(Z,X),padre(Z,Y), X \=Y.
tio(X,Y):-padre(Z,Y),hermano(X,Z), X \=Y.
primo(X,Y):-padre(Z,X),padre(W,Y),hermano(Z,W), X \=Y.

