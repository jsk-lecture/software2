/* test0 */
class test0 {
  public static int test(int i, int j) {
    return (i * j);
  }
  public static void main(String args[]) {
    int i, j, k;
    i = 3;
    j = 2;
    k = test(i, j);
    if ( k > 5 ) {
      System.out.println(">5");
    } else {
      System.out.println("<=5");
    }
  }
}
