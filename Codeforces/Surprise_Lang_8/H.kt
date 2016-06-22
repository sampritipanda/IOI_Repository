import java.util.*
import kotlin.collections.*

fun main(args: Array<String>) {
    val (n2, k) = readLine()!!.split(' ').map(String::toLong)
    val n = n2.toInt()
    val a2: List<Int> = readLine()!!.split(' ').map(String::toInt)
    var a: Array<Int> = Array(n, {0})

    for(i in (1..n)) {
        a[a2[i - 1] - 1] = i
    }

    var dp: Array<Array<Int> > = Array(54, { Array(n, {0}) })

    var i = 1
    while(i <= n) {
        dp[0][i - 1] = a[i - 1]
        i += 1
    }

    var j = 1
    while(j < 54) {
        i = 1
        while(i <= n) {
            dp[j][i - 1] = dp[j - 1][dp[j - 1][i - 1] - 1]
            i += 1
        }
        j += 1
    }

    i = 1
    while(i <= n) {
        var ans = i
        j = 53
        while (j >= 0) {
            if(k and (1L shl j) > 0) {
                ans = dp[j][ans - 1]
            }
            j -= 1
        }
        i += 1
        print(ans)
        print(" ")
    }
    print('\n')
}
