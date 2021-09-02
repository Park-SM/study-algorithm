import java.util.*

fun main() = with(Scanner(System.`in`)) {
    val chars = next().toCharArray()
    chars.sortDescending()
    if (chars.last() == '0') {
        val sum = chars.map { it - '0' }.reduce { acc, i -> acc + i }
        print(if (sum % 3 == 0) chars.concatToString() else -1)
    } else {
        print(-1)
    }
}