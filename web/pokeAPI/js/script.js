const pokemonNameInput = document.getElementById('pokemonNameInput');
const searchButton = document.getElementById('searchButton');
const suggestionsContainer = document.getElementById('suggestions');
const pokemonCard = document.getElementById('pokemonCard');



function getPokemonInfo(pokemonName) {
  const apiUrl = `https://pokeapi.co/api/v2/pokemon/${pokemonName.toLowerCase()}?language=pt-br`;

  fetch(apiUrl)
    .then(response => {
      if (response.status === 404) {
        throw new Error('Pokémon não encontrado!');
      }
      return response.json();
    })
    .then(data => {
      const pokemonImage = data.sprites.front_default;
      const pokemonTypes = data.types.map(type => type.type.name).join(', ');
      const pokemonStats = data.stats.map(stat => `${stat.stat.name}: ${stat.base_stat}`).join(', ');
      const pokemonAbilities = data.abilities.map(ability => ability.ability.name).join(', ');
      const pokemonHeight = data.height;
      const pokemonWeight = data.weight;
      const pokemonWeaknesses = data.types
        .map(type => type.type.name)
        .join(', ');

      const pokemonCardHtml = `
        <h2>${pokemonName}</h2>
        <img src="${pokemonImage}" alt="${pokemonName}">
        <p><strong>Tipos:</strong> ${pokemonTypes}</p>
        <p><strong>Estatísticas:</strong> ${pokemonStats}</p>
        <p><strong>Habilidades:</strong> ${pokemonAbilities}</p>
        <p><strong>Altura:</strong> ${pokemonHeight}</p>
        <p><strong>Peso:</strong> ${pokemonWeight}</p>
      `;
      pokemonCard.innerHTML = pokemonCardHtml;
    })
    .catch(error => {
      console.log(error);
      pokemonCard.innerHTML = `<p>${error.message}</p>`;
    });
}

searchButton.addEventListener('click', () => {
  const pokemonName = pokemonNameInput.value.toLowerCase();

  if (pokemonName.trim().length > 0) {
    getPokemonInfo(pokemonName);
  }
});

