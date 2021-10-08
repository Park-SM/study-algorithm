fun main() = with(System.`in`.bufferedReader()) {
    val s = readLine()
    val counts = IntArray(2)
    for (i in 1 until s.length) {
        if (s[i - 1] != s[i]) {
            counts[s[i - 1] - '0']++
        }
    }
    counts[s.last() - '0']++
    print(Math.min(counts[0], counts[1]))
    close()
}