-- test0
function test(i, j)
   return i * j
end

local i = 3
local j = 2
local k = test(i, j)
if (k > 5) then
   print(">5\n")
else
   print("<=5\n")
end
