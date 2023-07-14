// para que contenha um relogio adicione a classe relogio ex: class="relogio" e adicione width e height

var angulo_horas;
var angulo_minutos;
var angulo_segundos;

let relogio = `
  <div class="borda"> 
    <div class="circulo">
      <div class="pontoHora um"></div>
      <div class="pontoHora dois"></div>
      <div class="pontoHora tres"></div>
      <div class="pontoHora quatro"></div>
      <div class="pontoHora cinco"></div>
      <div class="pontoHora seis"></div>
      <div class="pontoHora sete"></div>
      <div class="pontoHora oito"></div>
      <div class="pontoHora nove"></div>
      <div class="pontoHora dez"></div>
      <div class="pontoHora onze"></div>
      <div class="pontoHora doze"></div>
    </div>
    <div class="prego"></div>
    <div class="ponteiro ponteiroMin pMin" ><div class="parteI"></div> <div class="parteII"></div></div>
    <div class="ponteiro ponteiroHr pHr"><div class="parteI"></div> <div class="parteII"></div></div>
    <div class="ponteiro ponteiroS pS"><div class="parteI"></div> <div class="parteII"></div></div>
  </div>
`

function calcularAngulosRelogio(data) {
  let horas = data.getHours();
  let minutos = data.getMinutes();
  let segundos = data.getSeconds()
  angulo_horas = 90 + ((360/12) * ((horas%12)))
  angulo_min = -90 + ((360/60)* ((minutos%60)))
  angulo_segundos = -90 + ((360/60) *((segundos%60)))
}

function criarRelogio () {
  for (const r of document.getElementsByClassName('relogioA')) {
    r.innerHTML = relogio
  }
}
setInterval( () => {
  var data = new Date()
  // data.setHours(11)
  // data.setMinutes(0)
  // data.setSeconds(5)
  calcularAngulosRelogio(data)

  var hr = document.getElementsByClassName('pHr');
  var min = document.getElementsByClassName('pMin');
  var s = document.getElementsByClassName('pS');
  for (const i of hr) {
    i.style.transform = 'translate(-50%,-50%) rotate(' + angulo_horas + 'deg)';
  }
  for (const i of min) {
    i.style.transform = 'translate(-50%,-50%) rotate(' + angulo_min + 'deg)';
  }
  for (const i of s) {
    i.style.transform = 'translate(-50%,-50%) rotate(' + angulo_segundos + 'deg)';
  }



}, 1000)
