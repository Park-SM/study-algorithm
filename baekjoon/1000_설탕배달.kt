import java.util.*
import kotlin.math.min

fun main() = with(Scanner(System.`in`)) {
    var kg = nextInt()

    var answer = Int.MAX_VALUE
    for (i in 0..(kg / 3)) {
        if ((kg - (3 * i)) % 5 == 0) {
            answer = min(answer,i + ((kg - (3 * i)) / 5))
        }
    }
    print(if (answer != Int.MAX_VALUE) answer else -1)
}