import java.util.*

fun main() = with(Scanner(System.`in`)) {
    val n = nextInt()
    val people = mutableListOf<Int>()

    for (i in 0 until n) people.add(nextInt())
    people.sort()

    var answer = 0
    for (i in people.indices) {
        answer += people.slice(0..i)
                        .reduce { acc, i -> acc + i }
    }
    print(answer)
}