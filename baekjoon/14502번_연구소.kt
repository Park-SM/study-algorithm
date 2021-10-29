import java.util.*

fun main() = with(Scanner(System.`in`)) {

    val n = nextInt()
    val m = nextInt()
    val map = Array(n) { IntArray(m) }
    val zeros = mutableListOf<Pair<Int, Int>>()

    for (y in 0 until n) {
        for (x in 0 until m) {
            val v = nextInt()
            if (v == 0) {
                zeros.add(x to y)
            }
            map[y][x] = v
        }
    }

    var max = 0
    for (w1 in zeros.indices) {
        for (w2 in (w1 + 1) until zeros.size) {
            for (w3 in (w2 + 1) until zeros.size) {
                addWalls(map, zeros[w1], zeros[w2], zeros[w3])
                getSafetyArea(map).let {
                    if (max < it) max = it
                }
                removeWalls(map, zeros[w1], zeros[w2], zeros[w3])
            }
        }
    }

    print(max)
}

fun addWalls(map: Array<IntArray>, vararg walls: Pair<Int, Int>) {
    for (w in walls) {
        map[w.second][w.first] = 1
    }
}

fun removeWalls(map: Array<IntArray>, vararg walls: Pair<Int, Int>) {
    for (w in walls) {
        map[w.second][w.first] = 0
    }
}

fun getSafetyArea(map: Array<IntArray>): Int {

    val n = map.size
    val m = map[0].size
    val tmpMap = Array(n) { IntArray(m) }
    for (y in 0 until n) {
        for (x in 0 until m) {
            tmpMap[y][x] = map[y][x]
        }
    }

    val q: Queue<Pair<Int, Int>> = LinkedList()
    for (y in 0 until n) {
        for (x in 0 until m) {
            if (tmpMap[y][x] == 2) {
                q.add(x to y)
            }
        }
    }

    while (!q.isEmpty()) {
        val (x, y) = q.poll() ?: break
        tmpMap[y][x] = 2

        if (y > 0     && tmpMap[y - 1][x] == 0) q.add(x to y - 1)
        if (x < m - 1 && tmpMap[y][x + 1] == 0) q.add(x + 1 to y)
        if (y < n - 1 && tmpMap[y + 1][x] == 0) q.add(x to y + 1)
        if (x > 0     && tmpMap[y][x - 1] == 0) q.add(x - 1 to y)
    }

    var safetyArea = 0
    for (y in 0 until n) {
        for (x in 0 until m) {
            if (tmpMap[y][x] == 0) safetyArea++
        }
    }
    return safetyArea
}