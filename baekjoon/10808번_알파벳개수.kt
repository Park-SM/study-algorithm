import java.util.*

fun main() = with(Scanner(System.`in`)) {
    val alphaa = IntArray(26)
    next().forEach { alphaa[it - 'a']++ }
    alphaa.forEach { print("$it ") }
}