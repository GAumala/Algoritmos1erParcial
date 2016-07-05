const spawn = require('child_process').spawn;
//const executable = process.argv[2]
let index = 0
const tests = ["countsort", "quicksort", "qsort_gcc", "bitonicsort",
"insertionsort", "shakersort"]

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
    console.log(algorithmName + ":\t" + diff + " ms.")
    index++;
    if(index < tests.length)
      runTest()
  })
}

function createNewList(){
  const listGenerator = spawn("./newlist", []);
  listGenerator.stderr.setEncoding("utf8");
  listGenerator.stderr.on('data', logOutput)
  listGenerator.on('close', (code) => {
    if(code == 0)
      runTest()
  })

}
function logOutput(data){
  console.log(data)
}
function start(){
  const make = spawn("make", []);
  make.stdout.setEncoding('utf8');
  make.stderr.setEncoding('utf8');
  make.stdout.on('data', logOutput)
  make.stderr.on('data', logOutput)
  make.on('close', (code) => {
    if(code == 0)
      createNewList()
  })
}

start();
