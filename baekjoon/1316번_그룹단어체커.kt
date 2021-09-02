import java.util.*

fun main() = with(Scanner(System.`in`)) {
    val n = nextInt()
    var answer = 0
    repeat(n) {

        val str = next()
        var isGroup = true
        val alpha = BooleanArray(26)
        for (i in str.indices) {
            val idx = str[i] - 'a'
            if (alpha[idx]) {
                if (str[i - 1] != str[i]) {
                    isGroup = false
                    break
                }
            } else {
                alpha[idx] = true
            }
        }
        if (isGroup) answer++
    }
    print(answer)
}