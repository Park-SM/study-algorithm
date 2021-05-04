function solution(bridge_length, weight, truck_weights) {
    var answer = 0;
    let idx = 0;
    const q = {};
    do {
        answer++;
        let currentWeight = 0;
        for (const k in q) {
            if (--q[k][1] == 0) {
                delete q[k];
            } else {
                currentWeight += q[k][0];
            }
        }
        if (idx == truck_weights.length || currentWeight + truck_weights[idx] > weight) continue;
        
        q[idx] = [];
        q[idx].push(truck_weights[idx]);
        q[idx++].push(bridge_length);
    } while (Object.keys(q).length);
    return answer;
}