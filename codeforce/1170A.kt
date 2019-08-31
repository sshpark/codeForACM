import java.util.Scanner
fun main(args: Array<String>) {
    val scan = Scanner(System.`in`)
    val t = scan.nextInt()

    for (i in 0 until t) {
        val x = scan.nextInt()
        val y = scan.nextInt()
        if (x == y) {
            println("1 1 ${x-1}")
        } else {
            val tmp = Math.min(x, y)
            val tmp1 = Math.max(x, y)
            println("1 ${tmp-1} ${tmp1-tmp+1}")
        }
    }
}