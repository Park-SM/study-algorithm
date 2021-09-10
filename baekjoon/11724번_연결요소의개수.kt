import java.util.*

fun main() = with(Scanner(System.`in`)) {
    val n = nextInt()
    val m = nextInt()

    val edges   = Array(n + 1) { mutableListOf<Int>() }
    repeat(m) {
        val v1 = nextInt()
        val v2 = nextInt()
        edges[v1].add(v2)
        edges[v2].add(v1)
    }

    val visited = BooleanArray(n + 1)
    fun dfs(v: Int): Int {
        if (visited[v]) return 0
        visited[v] = true

        return edges[v].fold(1) { acc, v -> acc + dfs(v) }
    }

    var answer = 0
    for (v in 1..n) {
        if (dfs(v) != 0) answer++
    }
    print(answer)
}