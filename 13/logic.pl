and(0, 0, 0).
and(0, 1, 0).
and(1, 0, 0).
and(1, 1, 1).

or(0, 0, 0).
or(0, 1, 1).
or(1, 0, 1).
or(1, 1, 1).

not(0, 1).
not(1, 0).


nand(A,B,C,X) :-
    and(A,B,X), not(X, C).

not(A-B) :- nand(A,A,B,_).
and(A-B-C) :- nand(A,B,X,_), not(X, C).
or(A-B-C) :- not(A, X), not(B, Y), nand(X,Y,C,_).

% ?- and(A-B-0).

my_not(A,B) :- nand(A,A,B,_).
my_and(A,B,C) :- nand(A,B,X,_), my_not(X, C).
my_or(A,B,C) :- my_not(A, X), my_not(B, Y), nand(X,Y,C,_).

% ?- and(A-B-0).

main1:-
    write('nand(A,B,C,X). -> '),nl,
    nand(A,B,C,X),write(A),write(' '),write(B),write(' '),write(C),write(' '),write(X),write(' '),nl,fail.

main2:-
    write('and(A-B-0). -> '),nl,
    and(A-B-0),write(A-B-0),nl,fail.

main3:-
    write('and(A-B-1). -> '),nl,
    and(A-B-1),write(A-B-1),nl,fail.

main:-
    main1;main2;main3.

