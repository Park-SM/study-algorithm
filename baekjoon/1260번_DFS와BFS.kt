import java.util.*

val visited = Array(1001) { false }
val edges = Array<MutableList<Int>>(1001) { mutableListOf() }

fun dfs(v: Int) {
    if (visited[v]) return
    visited[v] = true

    print("$v ")
    edges[v].forEach { dfs(it) }
}

fun bfs(v: Int) {
    val q: Queue<Int> = LinkedList()
    q.add(v)

    while(!q.isEmpty()) {
        val p = q.poll()
        if (visited[p]) continue
        visited[p] = true

        print("$p ")
        edges[p].forEach { q.add(it) }
    }
}

fun main() = with(Scanner(System.`in`)) {
    val n = nextInt()
    val m = nextInt()
    val v = nextInt()

    for(i in 0 until m) {
        val v1 = nextInt()
        val v2 = nextInt()
        edges[v1].add(v2)
        edges[v2].add(v1)
    }

    edges.forEach { it.sort() }
    dfs(v)
    println()
    visited.fill(false)
    bfs(v)
}