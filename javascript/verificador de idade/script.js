function verificar(){
    var data = new Date();
    var anoatual = data.getFullYear();
    var nasc = document.getElementById('nasc').value;
    var res = document.getElementById('res');
    var nome = document.getElementById('name').value

    var idade = anoatual - Number(nasc); 
    if (nasc.length === 0 || nasc > anoatual) {
        window.alert('ERRO! Dados inválidos!');
    } else {
        var sexo = document.getElementsByName('sex');
        var sit = ''
        var genero = ''
        if (sexo[0].checked){
            genero = 'homem'
            if (idade >= 0 && idade < 10){
                sit = 'Criança'
            } else if (idade < 20){
                sit = 'Jovem'
            } else if (idade < 50){
                sit = 'Adulto'
            } else {
                sit = 'Idoso'
            }
        } else if (sexo[1].checked){
            genero = 'mulher'
            if (idade >= 0 && idade < 10){
                sit = 'Criança'
            } else if (idade < 20){
                sit = 'Jovem'
            } else if (idade < 50){
                sit = 'Adulto'
            } else {
                sit = 'Idosa'
            }
        }
        res.innerHTML = `Resultado: Seu nome é ${nome}, e você é ${sit} ${genero} de ${idade} anos.`;
    }
}