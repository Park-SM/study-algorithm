import java.util.*

val dx = arrayOf(0, 1, 0, -1)
val dy = arrayOf(-1, 0, 1, 0)

data class Tomato(val x: Int, val y: Int)

fun main() = with(Scanner(System.`in`)) {
    val m = nextInt()
    val n = nextInt()
    val map = Array(n) { IntArray(m) }

    val q: Queue<Tomato> = LinkedList()
    for (y in 0 until n) {
        for (x in 0 until m) {
            val t = nextInt()
            map[y][x] = t
            if (t == 1) q.add(Tomato(x, y))
        }
    }

    while (!q.isEmpty()) {
        val p = q.poll()
        if (map[p.y][p.x] < 1) continue

        for (d in 0 until 4) {
            val nx = p.x + dx[d]
            val ny = p.y + dy[d]
            if (nx in 0 until m && ny in 0 until n && map[ny][nx] == 0) {
                map[ny][nx] = map[p.y][p.x] + 1
                q.add(Tomato(nx, ny))
            }
        }
    }
    var day = 0
    for (y in 0 until n) {
        for (x in 0 until m) {
            if (map[y][x] == 0) {
                print(-1)
                return
            } else {
                day = day.coerceAtLeast(map[y][x])
            }
        }
    }
    print(day - 1)
}