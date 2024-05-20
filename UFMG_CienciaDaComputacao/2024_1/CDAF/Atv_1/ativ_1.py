# -*- coding: utf-8 -*-
"""ativ_1.ipynb

Automatically generated by Colab.

Original file is located at
    https://colab.research.google.com/drive/178R8IzdZo58A01d-igURx7sFoHJ8M2rw

# [CDAF] Atividade 1

## Nome e matrícula
Nome: Lucas Rafael Costa Santos
Matrícula: 2021017723

## Introdução
Nesta atividade, vamos revisar os conceitos aprendidos em sala de aula sobre aleatoriedade e previsão a partir dos dados de
súmula.


Para isso utilizaremos o dataset "Soccer Prediction Challenge", disponível no Moodle.

## Questão 1
- Carregue o dataset 'TrainingSet_2023_02_08'
- Crie 4 histogramas:
    a) um para a quantidade de gols marcados por jogo pelos times mandantes
    b) um para a quantidade de gols marcados por jogo pelos time visitantes
    c) um para a quantidade total de gols em cada partida
    d) um para a diferença de gols por partida
- Caso hajam jogos com erros claros de anotação, destaque-os e remova-os antes de gerar os histogramas.
- Calcule o mínimo, o máximo e a média dos valores representados em cada um dos 4 histogramas.
"""

import pandas as pd
import matplotlib.pyplot as plt

# Carregando o dataset
df = pd.read_excel('TrainingSet_2023_02_08.xlsx')

# Verificando e removendo linhas com gols negativos
inconsistent_rows = df[(df['HS'] < 0) | (df['AS'] < 0)]
if len(inconsistent_rows) > 0:
    print("Linhas com valores de gols negativos:")
    print(inconsistent_rows)
    df = df.drop(inconsistent_rows.index)

# Calculando estatísticas para os histogramas
stats = {
    'Mandante': {
        'min': df['HS'].min(),
        'max': df['HS'].max(),
        'mean': df['HS'].mean()
    },
    'Visitante': {
        'min': df['AS'].min(),
        'max': df['AS'].max(),
        'mean': df['AS'].mean()
    },
    'Total': {
        'min': (df['HS'] + df['AS']).min(),
        'max': (df['HS'] + df['AS']).max(),
        'mean': (df['HS'] + df['AS']).mean()
    },
    'Diferença': {
        'min': df['GD'].min(),
        'max': df['GD'].max(),
        'mean': df['GD'].mean()
    }
}

# Plotando os histogramas
fig, axs = plt.subplots(2, 2, figsize=(12, 8))
fig.suptitle('Histogramas de Gols')

axs[0, 0].hist(df['HS'], bins=range(stats['Mandante']['min'], stats['Mandante']['max']+2), edgecolor='black', color='red')
axs[0, 0].set_title('Gols Marcados por Time Mandante')
axs[0, 0].set_xlabel('Gols')
axs[0, 0].set_ylabel('Frequência')

axs[0, 1].hist(df['AS'], bins=range(stats['Visitante']['min'], stats['Visitante']['max']+2), edgecolor='black', color='DeepSkyBlue')
axs[0, 1].set_title('Gols Marcados por Time Visitante')
axs[0, 1].set_xlabel('Gols')
axs[0, 1].set_ylabel('Frequência')

axs[1, 0].hist(df['HS'] + df['AS'], bins=range(stats['Total']['min'], stats['Total']['max']+2), edgecolor='black', color='red')
axs[1, 0].set_title('Total de Gols por Partida')
axs[1, 0].set_xlabel('Gols')
axs[1, 0].set_ylabel('Frequência')

axs[1, 1].hist(df['GD'], bins=range(stats['Diferença']['min'], stats['Diferença']['max']+2), edgecolor='black', color='DeepSkyBlue')
axs[1, 1].set_title('Diferença de Gols por Partida')
axs[1, 1].set_xlabel('Diferença de Gols')
axs[1, 1].set_ylabel('Frequência')

plt.tight_layout(rect=[0, 0.03, 1, 0.95])
plt.show()

# Imprimindo as estatísticas
print("\nEstatísticas:")
for key, value in stats.items():
    print(f"{key}:")
    print(f"  Mínimo: {value['min']}")
    print(f"  Máximo: {value['max']}")
    print(f"  Média: {value['mean']}")

"""## Questão 2
- Escolha uma temporada já finalizada de alguma das ligas presentes no dataset.
- Repita os 4 histogramas da questão 1 utilizando apenas dados do campeonato selecionado.
- Quais as diferenças entre os histogramas da questão 1 e da questão 2? O que isso pode indicar sobre as características da liga escolhida quando comparada ao todo?

- R: No geral, os histogramas da questão 1 e da questão 2 apresentam uma forma bastante semelhante, por exemplo, em ambos os histogramas o número de gols marcados por mandante tem como pico o número 1. As pequenas mudanças que podemos obsevar se dá em casos específicos, como em situações com placares elásticos.
"""

import pandas as pd
import matplotlib.pyplot as plt

# Carregando o dataset
df = pd.read_excel('TrainingSet_2023_02_08.xlsx')

# Filtrando dados para a temporada e liga escolhidas (Premier League 2019/20)
df_selected = df[(df['Lge'] == 'ENG1') & (df['Sea'] == '19-20')]

# Verificando e removendo linhas com gols negativos
inconsistent_rows = df_selected[(df_selected['HS'] < 0) | (df_selected['AS'] < 0)]
if len(inconsistent_rows) > 0:
    print("Linhas com valores de gols negativos:")
    print(inconsistent_rows)
    df_selected = df_selected.drop(inconsistent_rows.index)

# Calculando estatísticas para os histogramas
stats_selected = {
    'Mandante': {
        'min': df_selected['HS'].min(),
        'max': df_selected['HS'].max(),
        'mean': df_selected['HS'].mean()
    },
    'Visitante': {
        'min': df_selected['AS'].min(),
        'max': df_selected['AS'].max(),
        'mean': df_selected['AS'].mean()
    },
    'Total': {
        'min': (df_selected['HS'] + df_selected['AS']).min(),
        'max': (df_selected['HS'] + df_selected['AS']).max(),
        'mean': (df_selected['HS'] + df_selected['AS']).mean()
    },
    'Diferença': {
        'min': df_selected['GD'].min(),
        'max': df_selected['GD'].max(),
        'mean': df_selected['GD'].mean()
    }
}

# Plotando histogramas
fig, axs = plt.subplots(2, 2, figsize=(12, 8))
fig.suptitle('Histogramas de Gols - Temporada 2019-2020 da Premier League')

axs[0, 0].hist(df_selected['HS'], bins=range(stats_selected['Mandante']['min'], stats_selected['Mandante']['max']+2), edgecolor='black', color='red')
axs[0, 0].set_title('Gols Marcados por Time Mandante')
axs[0, 0].set_xlabel('Gols')
axs[0, 0].set_ylabel('Frequência')

axs[0, 1].hist(df_selected['AS'], bins=range(stats_selected['Visitante']['min'], stats_selected['Visitante']['max']+2), edgecolor='black', color='DeepSkyBlue')
axs[0, 1].set_title('Gols Marcados por Time Visitante')
axs[0, 1].set_xlabel('Gols')
axs[0, 1].set_ylabel('Frequência')

axs[1, 0].hist(df_selected['HS'] + df_selected['AS'], bins=range(stats_selected['Total']['min'], stats_selected['Total']['max']+2), edgecolor='black', color='red')
axs[1, 0].set_title('Total de Gols por Partida')
axs[1, 0].set_xlabel('Gols')
axs[1, 0].set_ylabel('Frequência')

axs[1, 1].hist(df_selected['GD'], bins=range(stats_selected['Diferença']['min'], stats_selected['Diferença']['max']+2), edgecolor='black', color='DeepSkyBlue')
axs[1, 1].set_title('Diferença de Gols por Partida')
axs[1, 1].set_xlabel('Diferença de Gols')
axs[1, 1].set_ylabel('Frequência')

plt.tight_layout(rect=[0, 0.03, 1, 0.95])
plt.show()

# Imprimindo estatísticas
print("\nEstatísticas da Temporada 2019-2020 da Premier League:")
for key, value in stats_selected.items():
    print(f"{key}:")
    print(f"  Mínimo: {value['min']}")
    print(f"  Máximo: {value['max']}")
    print(f"  Média: {value['mean']}")

"""## Questão 3
- Utilizando apenas dados do campeonato selecionado, crie um dataframe que corresponda à tabela de classificação ao fim da temporada contendo o nome dos times, nº de pontos, jogos, vitórias, empates, derrotas, gols pró, gols contra e saldo de gols. Ordene a classificação por pontos, vitórias, saldo de gols e gols pró.
- Faça o mesmo considerando apenas a primeira metade de jogos.
"""

# Calculando estatísticas para a tabela de classificação
teams = df_selected['HT'].unique()  # Obtendo todos os times únicos
standings = []
for team in teams:
    home_games = df_selected[df_selected['HT'] == team]
    away_games = df_selected[df_selected['AT'] == team]

    total_games = len(home_games) + len(away_games)
    wins = ((home_games['HS'] > home_games['AS']).sum() + (away_games['AS'] > away_games['HS']).sum())
    draws = ((home_games['HS'] == home_games['AS']).sum() + (away_games['HS'] == away_games['AS']).sum())
    losses = ((home_games['HS'] < home_games['AS']).sum() + (away_games['AS'] < away_games['HS']).sum())

    goals_for = home_games['HS'].sum() + away_games['AS'].sum()
    goals_against = home_games['AS'].sum() + away_games['HS'].sum()
    goal_diff = goals_for - goals_against

    points = (wins * 3) + draws

    standings.append({
        'Time': team,
        'Pontos': points,
        'Jogos': total_games,
        'Vitórias': wins,
        'Empates': draws,
        'Derrotas': losses,
        'Gols Pró': goals_for,
        'Gols Contra': goals_against,
        'Saldo de Gols': goal_diff
    })

# Criando DataFrame da tabela de classificação
standings_df = pd.DataFrame(standings)

# Ordenando a tabela de classificação
standings_df = standings_df.sort_values(by=['Pontos', 'Saldo de Gols', 'Vitórias', 'Gols Pró'], ascending=False)

# Reiniciando o índice para variar de 1 a 20
standings_df.reset_index(drop=True, inplace=True)
standings_df.index += 1

# Exibindo a tabela de classificação
print("Tabela de Classificação ao Fim da Temporada:")
print(standings_df)

# Agora, vamos repetir o processo considerando apenas a primeira metade dos jogos
half_games = len(df_selected) // 2
df_first_half = df_selected.head(half_games)

# Calculando estatísticas para a tabela de classificação da primeira metade
standings_first_half = []
for team in teams:
    home_games = df_first_half[df_first_half['HT'] == team]
    away_games = df_first_half[df_first_half['AT'] == team]

    total_games = len(home_games) + len(away_games)
    wins = ((home_games['HS'] > home_games['AS']).sum() + (away_games['AS'] > away_games['HS']).sum())
    draws = ((home_games['HS'] == home_games['AS']).sum() + (away_games['HS'] == away_games['AS']).sum())
    losses = ((home_games['HS'] < home_games['AS']).sum() + (away_games['AS'] < away_games['HS']).sum())

    goals_for = home_games['HS'].sum() + away_games['AS'].sum()
    goals_against = home_games['AS'].sum() + away_games['HS'].sum()
    goal_diff = goals_for - goals_against

    points = (wins * 3) + draws

    standings_first_half.append({
        'Time': team,
        'Pontos': points,
        'Jogos': total_games,
        'Vitórias': wins,
        'Empates': draws,
        'Derrotas': losses,
        'Gols Pró': goals_for,
        'Gols Contra': goals_against,
        'Saldo de Gols': goal_diff
    })

# Criando o DataFrame da tabela de classificação da primeira metade
standings_first_half_df = pd.DataFrame(standings_first_half)

# Ordenando a tabela de classificação da primeira metade
standings_first_half_df = standings_first_half_df.sort_values(by=['Pontos', 'Saldo de Gols', 'Vitórias', 'Gols Pró'], ascending=False)

# Reiniciando o índice para variar de 1 a 20
standings_first_half_df.reset_index(drop=True, inplace=True)
standings_first_half_df.index += 1

# Exibindo tabela de classificação da primeira metade
print("\nTabela de Classificação após a Primeira Metade dos Jogos:")
print(standings_first_half_df)

"""## Questão 4
- Utilizando os jogos da liga escolhida, use regressão de Poisson para criar um modelo de previsão de resultados, como visto nos slides em sala e no Soccermatics.
-- https://soccermatics.readthedocs.io/en/latest/gallery/lesson5/plot_SimulateMatches.html
- Dê print no sumário do ajuste
- Simule a partida entre o 1º e o 4º colocado, onde o 1º joga em casa. Primeiro, apresente a quantidade esperada de gols de cada time. Em seguida, apresente um grid com as probabilidades associadas a cada placar possível.
"""

import statsmodels.api as sm
import statsmodels.formula.api as smf
import pandas as pd
import numpy as np
from scipy.stats import poisson

# Filtrando apenas os jogos da liga escolhida (Premier League 2019/20)
df_selected = df[(df['Lge'] == 'ENG1') & (df['Sea'] == '19-20')]

# Criando o dataframe de dados para ajuste do modelo
goal_model_data = pd.concat([
    df_selected[['HT','AT','HS']].rename(columns={'HT':'team', 'AT':'opponent','HS':'goals'}).assign(home=1),
    df_selected[['AT','HT','AS']].rename(columns={'AT':'team', 'HT':'opponent','AS':'goals'}).assign(home=0)
])

# Ajustando o modelo de Poisson
poisson_model = smf.glm(formula="goals ~ home + team + opponent", data=goal_model_data,
                        family=sm.families.Poisson()).fit()

# Exibindo o sumário do ajuste
print(poisson_model.summary())

# Simulando a partida entre o 1º e o 4º colocado, onde o 1º joga em casa
teams = standings_df['Time'].tolist()
team1 = teams[0]
team4 = teams[3]

# Calculando a quantidade esperada de gols para cada time
home_score_rate = poisson_model.predict(pd.DataFrame(data={'team': team1, 'opponent': team4,'home':1}, index=[1]))
away_score_rate = poisson_model.predict(pd.DataFrame(data={'team': team4, 'opponent': team1,'home':0}, index=[1]))

print(f"\nExpectativa de gols para {team1} jogando em casa contra {team4}: {home_score_rate.values[0]}")
print(f"Expectativa de gols para {team4} jogando fora contra {team1}: {away_score_rate.values[0]}\n")

# Simulando os placares possíveis
home_goals = np.arange(0, 10)  # Placares possíveis para o time da casa
away_goals = np.arange(0, 10)  # Placares possíveis para o time visitante

# Criando um grid com as probabilidades associadas a cada placar possível
result_grid = np.zeros((len(home_goals), len(away_goals)))
for i, hg in enumerate(home_goals):
    for j, ag in enumerate(away_goals):
        # Calculando a probabilidade do placar (hg, ag)
        prob = poisson.pmf(hg, home_score_rate.values[0]) * poisson.pmf(ag, away_score_rate.values[0])
        result_grid[i, j] = prob

# Exibindo o grid com as probabilidades associadas a cada placar possível
print("Grid de Probabilidades para o Placar:")
for i in range(len(home_goals)):
    for j in range(len(away_goals)):
        print(f"{team1} {home_goals[i]} - {away_goals[j]} {team4}: {result_grid[i, j]:.4f}")

"""## Questão 5
- Utilize o modelo treinado para simular os placares de todos os jogos da temporada.
- Construa uma tabela de classificação em cima dos resultados esperados. Considere que jogos com uma diferença esperada de gols < 0.5 são empates.
- Compare a tabela real com a simulada. Onde estão as principais diferenças entre elas? E similaridades? Como você interpreta essa comparação? É possível identificar aspectos que o modelo subestima/superestima? É possível identificar tiveram campanhas "sortudas" ou "azaradas"?

- R: O modelo lida bem com os dois primeiros colocados, porém troca a posição entre eles, além disso ele também vai bem com o último colocado. Já no meio de tabela, as coisas ficam mais complicadas e é difícil acertar com precisão o desempenho dos times.
- Um fator interessante de se observar é o desempenho do campeão real (Liverpool), que supera, com grande margem, as expectativas, sendo uma campanha muito acima da média.
"""

# Simulando os placares de todos os jogos da temporada
simulation_results = []
for index, row in df_selected.iterrows():
    home_team = row['HT']
    away_team = row['AT']
    home_score_rate = poisson_model.predict(pd.DataFrame(data={'team': home_team, 'opponent': away_team,'home':1}, index=[1]))
    away_score_rate = poisson_model.predict(pd.DataFrame(data={'team': away_team, 'opponent': home_team,'home':0}, index=[1]))
    home_goals_simulated = np.random.poisson(home_score_rate)
    away_goals_simulated = np.random.poisson(away_score_rate)
    simulation_results.append({
        'HomeTeam': home_team,
        'AwayTeam': away_team,
        'HomeGoals': home_goals_simulated[0],
        'AwayGoals': away_goals_simulated[0]
    })

# Construindo uma tabela de classificação com base nos resultados simulados
simulated_standings = []
for team in teams:
    team_results = [result for result in simulation_results if result['HomeTeam'] == team or result['AwayTeam'] == team]
    wins = sum(1 for result in team_results if (result['HomeTeam'] == team and result['HomeGoals'] > result['AwayGoals']) or (result['AwayTeam'] == team and result['AwayGoals'] > result['HomeGoals']))
    draws = sum(1 for result in team_results if abs(result['HomeGoals'] - result['AwayGoals']) < 0.5)
    losses = sum(1 for result in team_results if (result['HomeTeam'] == team and result['HomeGoals'] < result['AwayGoals']) or (result['AwayTeam'] == team and result['AwayGoals'] < result['HomeGoals']))
    points = (wins * 3) + draws
    goals_for = sum(result['HomeGoals'] if result['HomeTeam'] == team else result['AwayGoals'] for result in team_results)
    goals_against = sum(result['AwayGoals'] if result['HomeTeam'] == team else result['HomeGoals'] for result in team_results)
    goal_diff = goals_for - goals_against
    simulated_standings.append({
        'Time': team,
        'Pontos': points,
        'Vitórias': wins,
        'Empates': draws,
        'Derrotas': losses,
        'Gols Pró': goals_for,
        'Gols Contra': goals_against,
        'Saldo de Gols': goal_diff
    })

# Criando DataFrame da tabela de classificação simulada
simulated_standings_df = pd.DataFrame(simulated_standings)

# Ordenando a tabela de classificação simulada
simulated_standings_df = simulated_standings_df.sort_values(by=['Pontos', 'Vitórias', 'Saldo de Gols', 'Gols Pró'], ascending=False)

# Reiniciando o índice para variar de 1 a 20
simulated_standings_df.reset_index(drop=True, inplace=True)
simulated_standings_df.index += 1

# Exibindo a tabela de classificação simulada
print("Tabela de Classificação Simulada:")
print(simulated_standings_df)

# Reiniciando o índice para variar de 1 a 20
simulated_standings_df.reset_index(drop=True, inplace=True)
simulated_standings_df.index += 1

# Comparando as tabelas de classificação real e simulada
comparison_df = pd.merge(standings_df, simulated_standings_df, left_index=True, right_index=True, suffixes=('_Real', '_Simulada'))

# Exibindo a comparação das tabelas de classificação
print("\nComparação entre Tabela de Classificação Real e Simulada:")
print(comparison_df)