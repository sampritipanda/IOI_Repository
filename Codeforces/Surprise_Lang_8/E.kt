import java.util.*
import kotlin.collections.*

fun main(args: Array<String>) {
    val n = readLine()!!.toInt()
    val a = readLine()!!.split(' ').map(String::toInt)
    var ans: MutableList<Int> = ArrayList()
    (1..n).map { ans.add(0) }

    for(i in (1..n)) {
        var j = 0
        var cnt = 0
        while(true) {
            if(cnt == a[i - 1] && ans[j] == 0) {
                break
            }
            else {
                if (ans[j] == 0 || ans[j] > i) cnt += 1
                j += 1
            }
        }
        ans[j] = i
    }

    for(i in ans) {
        print(i)
        print(" ")
    }
    print('\n')
}
