fun main() = with(System.`in`.bufferedReader()) {

    val n = readLine().toInt()
    val a = readLine().split(" ").map { it.toInt() }.sorted()
    val b = readLine().split(" ").map { it.toInt() }.sortedDescending()

    var sum = 0
    for (i in 0 until n) {
        sum += a[i] * b[i]
    }
    print(sum)
    close()
}