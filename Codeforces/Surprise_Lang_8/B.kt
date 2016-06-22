import java.util.*
import kotlin.comparisons.compareBy

fun main(args: Array<String>) {
    val n = readLine()!!.toInt()
    val arr: List<Pair<Int, String> > = (1..n).map {
        val (x, y) = readLine()!!.split(' ')
        val y2 = y.toInt()
        Pair(y2, x)
    }.sortedWith(compareBy<Pair<Int, String>> { it.first })

    for ( (x, y) in arr) {
        println(y)
    }
}
