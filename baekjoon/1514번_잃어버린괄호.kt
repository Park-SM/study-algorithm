import java.util.*

/* ::Note::
 * 50-50+40 문자열을 계산할 때는 앞에 char한개씩 buffer를 사용한다.
 * 빈 buf를 두고, operator 기본값을 + 로 둔 뒤, 빈 answer에다가
 * + 해서 계산한다. 그리고 마지막처리도 꼭 확인하기
 */
fun main() = with(Scanner(System.`in`)) {
    var answer = 0
    var buf = ""
    var isPlus = true
    next().forEach {
        if (it == '+' || it == '-') {
            if (isPlus) answer += buf.toInt() else answer -= buf.toInt()
            isPlus = isPlus && it == '+'
            buf = ""
        } else {
            buf += it
        }
    }
    if (isPlus) answer += buf.toInt() else answer -= buf.toInt()
    print(answer)
}