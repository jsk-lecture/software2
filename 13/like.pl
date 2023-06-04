like(taro,coffee).
like(hanako,tea).
like(taro,cocoa).

main1:-
    write('like(taro,coffee) -> '),nl,
    like(taro,coffee),!, write('true'),nl; write('false'),nl.

main2:-
    write('like(hanako,coffee) -> '),nl,
    like(hanako,coffee),!, write('true'),nl; write('false'),nl.

main3:-
    write('like(hanako,tee) -> '),nl,
    like(hanako,tee),!, write('true'),nl; write('false'),nl.

main4:-
    write('like(taro,X) -> '),nl,
    like(taro,X),write(X),nl,fail.

main5:-
    write('like(X,Y) -> '),nl,
    like(X,Y),write(X),write(' '),write(Y),nl,fail.

main:-
    main1,main2,main3,
    main4;
    main5.


