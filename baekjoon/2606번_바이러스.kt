import java.util.*

fun main() = with(Scanner(System.`in`)) {
    val n = nextInt()
    val m = nextInt()
    val edges = Array<MutableList<Int>>(101) { mutableListOf() }
    val visited = BooleanArray(101)

    repeat(m) {
        val v1 = nextInt()
        val v2 = nextInt()
        edges[v1].add(v2)
        edges[v2].add(v1)
    }

    var answer = 0
    val q: Queue<Int> = LinkedList()
    q.add(1)
    while (!q.isEmpty()) {
        val p = q.poll()
        if (visited[p]) continue
        visited[p] = true
        answer++

        edges[p].forEach { q.add(it) }
    }
    print(answer - 1)
}