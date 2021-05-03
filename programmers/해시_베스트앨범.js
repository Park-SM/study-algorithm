function solution(genres, plays) {
    var answer = [];
    const genresPlays = {};
    const genresSongs = {};
    for (var i = 0; i < genres.length; i++) {
        if (!genresPlays[genres[i]]) {
            genresPlays[genres[i]] = plays[i];
            genresSongs[genres[i]] = [];
        } else {
            genresPlays[genres[i]] += plays[i];
        }
        genresSongs[genres[i]].push(plays[i]);
    }
    while (Object.keys(genresPlays).length) {
        var max = 0, genresName = "";
        for (const key in genresPlays) {
            if (genresPlays[key] > max) {
                max = genresPlays[key];
                genresName = key;
            }
        }
        genresSongs[genresName].sort( (a, b) => { return b - a; });

        let idx = -1;
        for (var i = 0; i < plays.length; i++) {
            if (genres[i] == genresName && plays[i] == genresSongs[genresName][0]) {
                idx = i;
                break;
            }
        }
        answer.push(idx);
        
        if (genresSongs[genresName].length > 1) {
            for (var i = 0; i < plays.length; i++) {
                if (idx != i && genres[i] == genresName
                    && plays[i] == genresSongs[genresName][1])  {
                    idx = i;
                    break;
                }
            }
            answer.push(idx);
        }
        delete genresPlays[genresName];
    }
    return answer;
}