import java.util.*

fun main() = with(Scanner(System.`in`)) {
    val n = nextInt()
    val p = mutableListOf<Pair<Int, Int>>()
    repeat(n) {
        p.add(nextInt() to nextInt())
    }

    for (i in p.indices) {
        var priority = 0
        for (j in p.indices) {
            if (i == j) continue
            if (p[i].first < p[j].first && p[i].second < p[j].second) priority++
        }
        print("${priority + 1} ")
    }
}