import java.util.Scanner
fun main(args: Array<String>) {
    val scan = Scanner(System.`in`)
    val n = scan.nextInt()
    var lst = mutableListOf<Int>()

    for (i in 0 until n) {
        val tmp = scan.nextInt()
        lst.add(tmp)
    }

    var cnt = lst[0]
    var res = 0
    var m = 1

    for (i in 1 until lst.size) {
        if (lst[i] >= cnt) {
            cnt = lst[i]
            m++
        } else {
            if (i > 1 && m > 1) {
                println(lst[i])
                res++
            }    
        }
    }
    println(res)
}