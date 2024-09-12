from flask import Flask, jsonify, request
import requests
import random

app = Flask(__name__)


@app.route('/pokemon/<pokemon_name>')
def get_pokemon(pokemon_name):
    """Fetches and returns details of a Pokemon by name."""
    url = f"https://pokeapi.co/api/v2/pokemon/{pokemon_name}"
    response = requests.get(url)

    if response.status_code == 200:
        # Parse JSON data
        data = response.json()
        return jsonify(data)
    else:
        # Handle unsuccessful request (e.g., Pokemon not found)
        return jsonify({"error": f"Pokemon '{pokemon_name}' not found."}), 404

@app.route('/random')
def get_random_pokemon():
  url = "https://pokeapi.co/api/v2/pokemon?limit=1089"
  response = requests.get(url)
  data = response.json()
  random_index = random.randint(0, len(data['results']) - 1)
  pokemon_name = data['results'][random_index]['name']
  return get_pokemon(pokemon_name)

@app.route('/team/<team_names>')
def get_team(team_names):
  pokemon_team = []
  for name in team_names.split(','):
    pokemon_team.append(get_pokemon(name.strip()))
  return jsonify(pokemon_team)

if __name__ == '__main__':
    app.run(debug=True)