function dfs(b, t, w) {
    if (b == t) return 1;
    if (!w.length) return 0;
    
    let result = w.length;
    for (var i = 0; i < w.length; i++) {
        let cnt = 0;
        for (var j = 0; j < w[i].length; j++) if (b[j] != w[i][j]) cnt++;
        if (cnt == 1) {
            const a = w.slice(); a.splice(i, 1);
            const d = dfs(w[i], t, a);
            result = (result > d) ? d : result;
        }
    }
    return result + 1;
}

function solution(begin, target, words) {
    if (!words.includes(target)) return 0;
    return dfs(begin, target, words) - 1;
}