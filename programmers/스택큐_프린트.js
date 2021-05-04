function solution(priorities, location) {
    var answer = 1;
    while (priorities.length) {
        location--;
        let poped = priorities.shift();
        if (poped >= Math.max.apply(null, priorities)) {
            if (location == -1) return answer;
            answer++;
        } else {
            if (location == -1) location = priorities.length;
            priorities.push(poped);
        }
    }
    return answer;
}