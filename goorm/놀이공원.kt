import java.util.Scanner

fun main() = with(Scanner(System.`in`)) {

    repeat(nextInt()) {
        val n = nextInt()
        val k = nextInt()
        val map = Array(n) { IntArray(n) }

        for (y in 0 until n) {
            for (x in 0 until n) {
                map[y][x] = nextInt()
            }
        }

        var min = Int.MAX_VALUE
        for (y in 0..(n - k)) {
            for (x in 0..(n - k)) {
                val cnt = getGarbageCnt(map, k, x, y)
                if (cnt < min) min = cnt
            }
        }
        println(min)
    }
}

fun getGarbageCnt(map: Array<IntArray>, k: Int, x: Int, y: Int): Int {
    var cnt = 0
    for (yy in y until (y + k)) {
        for (xx in x until (x + k)) {
            if (map[yy][xx] == 1) cnt++
        }
    }
    return cnt
}