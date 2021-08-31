import java.util.*

fun main() = with(Scanner(System.`in`)) {
    val n = nextInt()
    var k = nextInt()
    val coins = mutableListOf<Int>()
    for (i in 0 until n) coins.add(nextInt())
    coins.reverse()

    var answer = 0
    for (coin in coins) {
        if (coin > k) continue

        answer += k / coin
        k %= coin
    }

    print(answer)
}