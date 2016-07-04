const spawn = require('child_process').spawn;
const listGenerator = require('./listGenerator.js')
const executable = process.argv[2]


if(executable == "--help")
  console.log("Ejecutar la prueba asi: node benchmark.js [ALGORITMO]")
else if(executable == "--new-list"){
   listGenerator.work();
}
else {
  const startTime = new Date().getTime()
  const algoritmo = spawn("./" + executable, []);
  algoritmo.on('close', (code) => {
    const endTime = new Date().getTime()
    const diff = endTime - startTime
    console.log("El algoritmo tardo: " + diff + " ms.")
  })
}
