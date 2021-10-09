fun main() = with(System.`in`.bufferedReader()) {
    readLine().forEachIndexed { idx, c ->
        if (idx > 0 && idx % 10 == 0) println()
        print(c)
    }
}