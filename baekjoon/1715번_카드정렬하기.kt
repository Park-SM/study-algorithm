import java.util.*

fun main() = with(Scanner(System.`in`)) {

    val n = nextInt()
    val cards = PriorityQueue<Int>()

    for (i in 0 until n) {
        cards.add(nextInt())
    }

    var cnt = 0
    while (cards.size > 1) {
        val p1 = cards.poll() ?: 0
        val p2 = cards.poll() ?: 0

        cnt += p1 + p2
        cards.add(p1 + p2)
    }
    print(cnt)
}