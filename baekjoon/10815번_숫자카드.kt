import java.util.*

fun main() = with(Scanner(System.`in`)) {
    val n = nextInt()
    val cards = IntArray(n)
    for (i in cards.indices) {
        cards[i] = nextInt()
    }
    cards.sort()

    val m = nextInt()
    for (i in 0 until m) {

        val target = nextInt()

        var s = 0
        var e = cards.lastIndex
        var v = false
        while(s <= e) {
            val mid = (s + e) / 2
            if (target == cards[mid]) {
                v = true
                break
            } else if (target > cards[mid]) {
                s = mid + 1
            } else {
                e = mid - 1
            }
        }
        print(if (v) "1 " else "0 ")
    }
}