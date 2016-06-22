import java.util.*
import kotlin.collections.*

fun main(args: Array<String>) {
    val s = readLine()!!.dropWhile { it == ' ' }.dropLastWhile { it == ' ' || it == '\n' }
    var ans: MutableList<Char> = ArrayList()

    var sent_start = true
    var word_start = false
    var i = 0

    while(i < s.length) {
        if(s[i] == ' ') {
            i += 1
        }
        else if(s[i] == ',' || s[i] == '.') {
            if(s[i] == '.') {
                sent_start = true
            }
            ans.add(s[i])
            i += 1
        }
        else {
            ans.add(' ')
            while (i < s.length && s[i] != ' ' && s[i] != '.' && s[i] != ',') {
                if(sent_start) {
                    ans.add(s[i].toUpperCase())
                    sent_start = false
                }
                else {
                    ans.add(s[i].toLowerCase())
                }
                i += 1
            }
        }
    }

    for(x in ans.dropWhile { it == ' ' }.dropLastWhile { it == ' ' }) print(x)

    print('\n')
}
