const spawn = require('child_process').spawn;
//const executable = process.argv[2]
let index = 0
const tests = ["countsort", "quicksort", "qsort", "insertionsort", "shakersort"]

function runTest(){
  const algorithmName = tests[index]
  const startTime = new Date().getTime()
  const algoritmo = spawn("./" + algorithmName, []);

/*
  algoritmo.stdout.on('data', (data) => {
    console.log(data);
  })
  */

  algoritmo.on('close', (code) => {
    const endTime = new Date().getTime()
    const diff = endTime - startTime
    console.log(algorithmName + " tardo: " + diff + " ms.")
    index++;
    if(index < tests.length)
      runTest()
  })
}

runTest();
