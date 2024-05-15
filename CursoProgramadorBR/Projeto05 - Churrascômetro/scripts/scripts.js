// Carne - 400 g por pessoa + de 6 horas - 650
// Cerveja - 1200 ml por pessoa + 6 horas - 2000 ml
// Refrigerante/agua - 1000 ml por pessoa + 6 horas 1500 ml

// Crianças valem por 0,5 pessoa

let inputAdultos = document.getElementById("adultos");
let inputCriancas = document.getElementById("criancas");
let inputDuracao = document.getElementById("duracao");

let resultado = document.getElementById("resultado");

function carnePP(duracao) {
    if (duracao >= 6) {
        return 650;
    } else {
        return 400;
    }
}

function cervejaPP(duracao) {
    if (duracao >= 6) {
        return 2000;
    } else {
        return 1200;
    }
}

function bebidasPP(duracao) {
    if (duracao >= 6) {
        return 1500;
    } else {
        return 1000;
    }
}

function calcular() {
    console.log("Calculando...");

    let adultos = inputAdultos.value;
    let criancas = inputCriancas.value;
    let duracao = inputDuracao.value;

    let qtdTotalCarne = carnePP(duracao) * adultos + (carnePP(duracao) / 2 * criancas);
    //console.log(qtdTotalCarne);

    let qtdTotalCerveja = cervejaPP(duracao) * adultos;
    //console.log(qtdTotalCerveja);

    let qtdTotalBebidas = bebidasPP(duracao) * adultos + (bebidasPP(duracao) / 2 * criancas);
    //console.log(qtdTotalBebidas);

    resultado.innerHTML = `<p>${qtdTotalCarne / 1000} Kg de Carne</p>`
    resultado.innerHTML += `<p>${Math.ceil(qtdTotalCerveja / 355)} latas de Cerveja</p>`
    resultado.innerHTML += `<p>${Math.ceil(qtdTotalBebidas / 2000)} garrafas de Bebidas</p>`
}

