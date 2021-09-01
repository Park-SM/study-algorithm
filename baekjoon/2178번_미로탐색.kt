import java.util.*

val map = Array(100) { IntArray(100) }

fun main() = with(Scanner(System.`in`)) {
    val n = nextInt()
    val m = nextInt()

    repeat(n) { n ->
        next().forEachIndexed { idx, i ->
            map[n][idx] = i - '0'
        }
    }

    val q: Queue<IntArray> = LinkedList()
    q.add(intArrayOf(0, 0, 2))
    while(!q.isEmpty()) {
        val p = q.poll()
        val x = p[0]
        val y = p[1]
        val value = p[2]
        if (map[y][x] != 1) continue
        map[y][x] = value

        if (y > 0)
            q.add(intArrayOf(x, y - 1, value + 1))
        if (x < m - 1)
            q.add(intArrayOf(x + 1, y, value + 1))
        if (y < n - 1)
            q.add(intArrayOf(x, y + 1, value + 1))
        if (x > 0)
            q.add(intArrayOf(x - 1, y, value + 1))
    }

    print(map[n - 1][m - 1] - 1)
}