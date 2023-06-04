(* test0 *)
program test0;
var
   a : integer;
   b : integer;
   k : integer;
function test(i, j :  integer): integer;
var
   result :  integer;
begin
   result  := i * j;
   test := result;
end;

begin
   a := 2;
   b := 3;
   k := test(a, b);
   if k > 5 then
      writeln('>5')
  else
     writeln('<=5');
end.


