parent(namihei,sazae).
male(namihei).
female(sazae).

father(P,C) :- parent(P,C), male(P).
child(C,P) :- parent(P,C).
daughter(C,P) :- child(C,P), female(C).

/*
daughter(sazae,namihei). true
daughter(namihei,sazae). false
*/

main1:-
    write('daughter(sazae,namihei) -> '),nl,
    daughter(sazae,namihei),!, write('true'),nl; write('false'),nl.

main2:-
    write('daughter(X,Y) -> '),nl,
    daughter(X,Y),write(X),write(' '),write(Y),nl,fail.

main:-
    main1,
    main2.

