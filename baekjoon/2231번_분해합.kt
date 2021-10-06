import java.util.*

fun main() = with(Scanner(System.`in`)) {
    val n = next()
    val num = n.toInt()

    for (g in (num - (n.length * 9)) until num) {
        var sum = g
        g.toString().forEach { sum +=  it - '0'}

        if (sum == num) {
            print(g)
            return
        }
    }
    print(0)
}