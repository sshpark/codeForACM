import java.util.Scanner

fun isPalindrome(str: String): Boolean {
    for (i in 0 until str.length/2) {
        if (str[i] != str[str.length-i-1])
            return false
    }
    return true
}

fun main(args: Array<String>) {
    val scan = Scanner(System.`in`)
    val x = scan.nextInt()
    scan.nextLine()
    for (i in 0 until x) {
        val s = scan.nextLine()

        if (!isPalindrome(s)) {
            println(s)
        } else {
            var flag = false
            for (j in 0 until s.length-1) {
                if (s[j] != s[j+1]) {
                    flag = true
                    println("${s.substring(0, j)}${s[j+1]}${s[j]}${s.substring(j+2, s.length)}")
                    break
                }
            }
            if (!flag) {
                println("-1")
            }
        }
    }

}