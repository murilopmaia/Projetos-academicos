// src/components/SortControls.js
import React from 'react';

import './SortControls.css'

function SortControls({ sortCriteria, setSortCriteria }) {
  const handleSort = (criteria) => {
    setSortCriteria(criteria);
  };

  return (
    <div className="sort-controls-container">
      <span className="sort-by-label">Sort By</span>
      <button
        onClick={() => handleSort('name')}
        className={`sort-button ${sortCriteria === 'name' ? 'active' : ''}`}
        aria-pressed={sortCriteria === 'name'}
      >
        A-Z
      </button>
      <button
        onClick={() => handleSort('stars')}
        className={`sort-button icon-button ${sortCriteria === 'stars' ? 'active' : ''}`}
        aria-label="Sort by stars"
        aria-pressed={sortCriteria === 'stars'}
      >
        <span role="img" aria-label="Stars">⭐</span>
      </button>
    </div>
  );
}

export default SortControls;