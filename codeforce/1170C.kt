import java.util.Scanner

fun main(args: Array<String>) {
    val scan = Scanner(System.`in`)
    val t = scan.nextInt()
    scan.nextLine()

    for (x in 0 until t) {
        val s = scan.nextLine()
        val tmp = scan.nextLine()
        
        if (s == tmp) {
            println("YES")
        } else {
            var cnt = 0
            var flag = true
            var i = 0
            while (i < tmp.length) {
                if (cnt >= s.length) {
                    flag = false
                    println("NO")
                    break
                }
                if (tmp[i] != s[cnt]) {
                    if (tmp[i] == '+') {
                        if (cnt+1 < s.length && s[cnt+1] == '-') {
                            cnt += 2
                            continue
                        } else {
                            flag = false
                            println("NO")
                            break    
                        }
                    } else {
                        flag = false
                        println("NO")
                        break
                    }
                } else {
                    cnt++
                }
                i++
            }
            if (flag) {
                if (cnt != s.length) {
                    println("NO")
                } else {
                    println("YES")
                }
            }
                
        }
    }
}