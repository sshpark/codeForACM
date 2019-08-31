import java.util.Scanner
fun main(args: Array<String>) {
    val scan = Scanner(System.`in`)
    val t = scan.nextInt()
    for (i in 0 until t) {
        val temp = scan.nextInt()
        println(temp/2)
    }
}