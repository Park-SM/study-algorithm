val br = System.`in`.bufferedReader()
val bw = System.out.bufferedWriter()

fun main() {

    val n   = br.readLine().toInt()
    val arr = IntArray(10001)

    for (i in 0 until n) {
        arr[br.readLine().toInt()]++
    }
    for (i in 0..10000) {
        for (j in 1..arr[i]) {
            bw.write("$i\n")
        }
    }
    bw.close()
}