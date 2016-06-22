import java.util.*
import kotlin.collections.*

fun gcd(x: Long, y: Long) : Long {
    if(y == 0L) return x

    return gcd(y, x % y)
}

fun power(x: Long, y: Int) : Long{
    var res = 1L
    var exp = y
    while(exp > 0) {
        res = res * x
        exp -= 1
    }
    return res
}

fun main(args: Array<String>) {
    val s = readLine()!!.drop(2)
    var a: MutableList<Char> = ArrayList()
    var b: MutableList<Char> = ArrayList()

    var i = 0
    while(i < s.length) {
        if(s[i] == '(') {
            i += 1
            break
        }
        else {
            a.add(s[i])
            i += 1
        }
    }
    while(i < s.length) {
        if(s[i] == ')') {
            break
        }
        else {
            b.add(s[i])
            i += 1
        }
    }

    if(a.size == 0) a = b

    var x = a.joinToString("").toLong()
    var y = b.joinToString("").toLong()

    var denom = power(10L, a.size + b.size) - power(10L, a.size)
    var numer = x * power(10L, b.size) + y - x

    var g = gcd(numer, denom)

    numer /= g
    denom /= g

    print(numer)
    print('/')
    print(denom)
    print('\n')
}
