// src/components/SearchInput.js
import React from 'react';
import searchIcon from '../../assents/search.png'

import "./SearchInput.css"

function SearchInput({ searchTerm, setSearchTerm }) {
  return (
    <div className="search-input-container">
      <img src={searchIcon} alt="Search Icon" />
      <input
        type="text"
        placeholder="Procurar pelo nome..."
        value={searchTerm}
        onChange={(e) => setSearchTerm(e.target.value)}
        className="search-input-field"
      />
    </div>
  );
}

export default SearchInput;