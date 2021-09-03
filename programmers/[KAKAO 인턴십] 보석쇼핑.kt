class Solution {

    fun solution(gems: Array<String>): IntArray {
        val answer = IntArray(2)
        val types = LinkedHashMap<String, Int>()
        gems.toHashSet().forEach { types[it] = 0 }

        var end = -1
        var start = -1
        var minRange = Int.MAX_VALUE
        while (end < gems.size) {
            while (++end < gems.size) {
                types[gems[end]] = types[gems[end]]!! + 1
                if (hasAllGem(types)) break
            }
            while (++start < gems.size) {
                types[gems[start]] = types[gems[start]]!! - 1
                if (!hasAllGem(types)) break
            }
            if (minRange > end - start) {
                minRange = end - start
                answer[0] = start + 1
                answer[1] = end + 1
            }
        }
        return answer
    }

    private fun hasAllGem(types: HashMap<String, Int>): Boolean {
        for (g in types) {
            if (g.value < 1) return false
        }
        return true
    }
}