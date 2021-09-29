import java.util.Scanner

fun main() = with(Scanner(System.`in`)) {

    val n = nextInt()
    val m = nextInt()
    val cards = mutableListOf<Int>()
    repeat(n) {
        nextInt().let { card ->
            if (card < m) cards.add(card)
        }
    }

    var max = 0
    for (p1 in 0 until cards.lastIndex - 1) {

        for (p2 in (p1 + 1) until cards.lastIndex) {
            if (cards[p1] + cards[p2] >= m) continue

            for (p3 in (p2 + 1) until cards.size) {
                val sum = cards[p1] + cards[p2] + cards[p3]
                if (sum in (max + 1)..m) max = sum
            }
        }
    }
    print(max)
}