const elementoResposta = document.querySelector("#resposta")
const inputPergunta = document.querySelector("#inputPergunta") 


const respostas = [
  'Com certeza!',
  'Não tenho tanta certeza.',
  'Não conte com isso.',
  'Sem dúvidas!',
  'Pergunte novamente mais tarde.',
  'Sim, definitivamente!',
  'Minha resposta é não.',
  'Você pode contar com isso.',
  'Melhor não te dizer agora.',
  'A meu ver, sim.',
  'Minhas fontes dizem que não.',
  'Provavelmente.',
  'Não é possível prever agora.',
  'As perspectivas não são tão boas.',
  'Sim.',
  'Sinais apontam que sim.'
]


function limparPergunta() {
  inputPergunta.value = ""
}


function fazerPergunta() {

  
  if (inputPergunta.value == "") {
    alert("Digite sua pergunta") 
   
    return
  }


  const perguntaDigitada = inputPergunta.value.trim() 
  console.log("Valor da pergunta:", perguntaDigitada)


  const pergunta = "<div>" + inputPergunta.value + "</div>"


  const totalRespostas = respostas.length


  const numeroAleatorio = Math.floor(Math.random() * totalRespostas) 


  console.log("Número aleatório:", numeroAleatorio)


  elementoResposta.innerHTML = pergunta + respostas[numeroAleatorio]

  
  elementoResposta.style.opacity = 1;


  setTimeout(function() {
    elementoResposta.style.opacity = 0;

  }, 2000)
  

  limparPergunta();
 
}


