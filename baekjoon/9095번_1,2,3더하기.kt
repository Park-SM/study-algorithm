
fun main() {

    val dp = IntArray(11)
    dp[1] = 1
    dp[2] = 2
    dp[3] = 4

    for (i in 4..10) {
        dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3]
    }

    for (i in 0 until readLine()!!.toInt()) {
        println(dp[readLine()!!.toInt()])
    }
}