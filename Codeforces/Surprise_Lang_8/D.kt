import java.util.*
import kotlin.collections.*

fun main(args: Array<String>) {
    val q = readLine()!!.toInt()

    for (asdad in (1..q)) {
        val (n, m, p) = readLine()!!.split(' ').map(String::toInt)
        var pos = false
        for(i in (1..p)) {
            if(p % i == 0) {
                val a = i
                val b = p/i
                if(a <= n && b <= m) pos = true
                if(a <= m && b <= n) pos = true
            }
        }

        if(pos) println("Yes")
        else println("No")
    }
}
