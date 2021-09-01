import java.util.*

val map = Array(50) { IntArray(50) }

fun dfs(m: Int, n: Int, x: Int, y: Int) {
    if (map[y][x] == 0) return
    map[y][x] = 0

    if (y > 0) dfs(m, n, x, y - 1)
    if (x < m - 1) dfs(m, n, x + 1, y)
    if (y < n - 1) dfs(m, n, x, y + 1)
    if (x > 0) dfs(m, n, x - 1, y)
}

fun main() = with(Scanner(System.`in`)) {
    val test = nextInt()
    repeat(test) {

        val m = nextInt()
        var n = nextInt()
        val k = nextInt()
        for (k in 0 until k) {
            val x = nextInt()
            val y = nextInt()
            map[y][x] = 1
        }

        var answer = 0
        for (y in 0 until n) {
            for ( x in 0 until m) {
                if (map[y][x] == 1) {
                    dfs(m, n, x, y)
                    answer++
                }
            }
        }
        println(answer)
        map.forEach { it.fill(0) }
    }
}