function solution(progresses, speeds) {
    var answer = [];
    while (progresses.length  0) {
        for (var i = 0; i  progresses.length; i++) {
            progresses[i] += speeds[i];
        }
        if (progresses[0]  100) continue;

        let completed = 0;
        while (progresses[0] = 100) {
            speeds.shift();
            progresses.shift();
            completed++
        }
        answer.push(completed);
    }
    return answer;
}