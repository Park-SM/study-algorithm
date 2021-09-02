import java.util.*

fun main() = with(Scanner(System.`in`)) {
    next().toCharArray().also {
        it.sortDescending()
        it.concatToString()
    }.let {
        print(it)
    }
}