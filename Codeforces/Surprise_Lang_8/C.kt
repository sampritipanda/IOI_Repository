import java.util.*
import kotlin.collections.*

fun main(args: Array<String>) {
    val a = readLine()!!.split(' ').map(String::toInt).drop(1)
    val b = readLine()!!.split(' ').map(String::toInt).drop(1)

    val ans = b.filter { !a.contains(it) }
    val ans2 = a.filter { !b.contains(it) }

    print(ans.size + ans2.size)
    print(" ")

    for(x in ans) {
        print(x)
        print(" ")
    }
    for(x in ans2) {
        print(x)
        print(" ")
    }
    print("\n")
}
