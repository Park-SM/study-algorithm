function solution(n, computers) {
    var answer = 0;
    const edges = {};
    for (var i = 0; i < n; i++) {
        for (var j = 0; j < n; j++) {
            if (edges[i] == undefined) edges[i] = [];
            if (i != j && computers[i][j] == 1) edges[i].push(j);
        }
    }
    const visited = [];
    for (var i = 0; i < n; i++) {
        const q = [];
        q.push(i);
        let isConn = false;
        while(q.length) {
            const p = q.shift();
            if (visited[p] != undefined) continue;
            visited[p] = true;
            isConn = true;
            for (var j = 0; edges[p] && j < edges[p].length; j++) q.push(edges[p][j]);
        }
        if (isConn) answer++;
    }
    return answer;
}