import java.util.*

val mv = arrayOf( { i: Int -> i + 1 }, { i: Int -> i - 1 }, { i: Int -> i * 2 } )

fun main() = with(Scanner(System.`in`)) {
    val n = nextInt()
    val k = nextInt()
    val visited = IntArray(100001)
    visited[n] = 1

    val q: Queue<Int> = LinkedList()
    q.add(n)
    while(!q.isEmpty()) {
        val p = q.poll()
        if (p == k) break

        for (m in 0 until 3) {
            val np = mv[m](p)
            if (np !in 0..100000 || visited[np] != 0) continue

            visited[np] = visited[p] + 1
            q.add(np)
        }
    }
    print(visited[k] - 1)
}