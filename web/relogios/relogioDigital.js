let relogioDigital = `
<div class="relogioDigital">
    <ul>
      <li class="liHr"></li> 
      <li class="liMin"></li>
      <li class="liS"></li>
    </ul>
  </div>
`

function setarHorario () {
  let data = new Date()
  let hr = document.getElementsByClassName("liHr")
  let min = document.getElementsByClassName("liMin")
  let s = document.getElementsByClassName("liS")
  for (const i of hr) {
    i.innerHTML = data.getHours().toString().padStart(2, '0') + ":"
  }
  for (const i of min) {
    i.innerHTML = data.getMinutes().toString().padStart(2, '0') + ":"
  }
  for (const i of s) {
    i.innerHTML = data.getSeconds().toString().padStart(2, '0')
  }

}

function criarRelogioDigital () {
  let rD = document.getElementsByClassName("relogioD")

  for (const i of rD) {
    i.innerHTML += relogioDigital
  }
}
setInterval(setarHorario, 1000)