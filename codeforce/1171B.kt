import java.util.Scanner

fun main(args: Array<String>) {
    val (y, b, r) = readLine()!!.split(' ').map { it.toInt() }

    var maxa = 0

    for (i in 0 .. y) {
        if (b-i >= 1 && r-i >= 2)
            maxa = Math.max(maxa, i*3+3)
    }
    println(maxa)
}