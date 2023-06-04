/* test0 */
package main

import "fmt"

func test(i int, j int ) int {
	return (i * j)
}

func main() {
	i, j := 3, 2
	var k int = 0;
	k = test(i, j)
	if k > 5 {
		fmt.Println(">5")
	} else {
		fmt.Println("<5")
	}
}

