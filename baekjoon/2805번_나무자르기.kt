
fun main() = with(System.`in`.bufferedReader()) {
    val (n, m) = readLine().split(" ").map { it.toInt() }
    val trees  = readLine().split(" ").map { it.toLong() }

    var min = 0
    var max = 1_000_000_000
    var answer = 0
    while (min <= max) {

        val mid = (min + max) / 2
        val sum = trees.sumOf { if (it > mid) it - mid else 0 }

        if (sum >= m) {
            min = mid + 1
            answer = mid
        } else {
            max = mid - 1
        }
    }
    print(answer)
}