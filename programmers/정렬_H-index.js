function solution(citations) {
    var answer = citations.length;
    citations.sort( (a, b) => {return b - a});
    do {
        let cnt = 0;
        for (var i = 0; i < citations.length; i++) {
            if (citations[i] >= answer) cnt++;
        }
        if (answer <= cnt && answer >= citations.length - cnt) {
            return answer;
        }
    } while(--answer);
    return 0;
}