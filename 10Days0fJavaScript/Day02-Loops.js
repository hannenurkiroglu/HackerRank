'use strict';

process.stdin.resume();
process.stdin.setEncoding('utf-8');

let inputString = '';
let currentLine = 0;

process.stdin.on('data', inputStdin => {
    inputString += inputStdin;
});

process.stdin.on('end', _ => {
    inputString = inputString.trim().split('\n').map(string => {
        return string.trim();
    });
    
    main();    
});

function readLine() {
    return inputString[currentLine++];
}

/*
 * Complete the vowelsAndConsonants function.
 * Print your output using 'console.log()'.
 */
function vowelsAndConsonants(s) {
    const vowels = s.match(/[aeiou]/gi); 
    const consonants = s.match(/[^aeiou]/gi);
    vowels.forEach(k => { console.log(k); } );
    consonants.forEach(k => { console.log(k); } );
}


function main() {
    const s = readLine();
    
    vowelsAndConsonants(s);
}
