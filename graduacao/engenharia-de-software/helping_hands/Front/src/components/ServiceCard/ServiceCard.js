
import React from 'react';
import calendarIcon from '../../assents/calendar.png'

import './ServiceCard.css'

function ServiceCard({ name, role, focus, imageUrl, stars , onInfoClick}) {
  // Função para renderizar as estrelas
  const renderStars = (rating) => {
    const totalStars = 5;
    let starDisplay = []; 
    for (let i = 1; i <= totalStars; i++) {
      if (i <= rating) {
        starDisplay.push(<span key={`star-filled-${i}`} className="star filled">★</span>);
      } else {
        starDisplay.push(<span key={`star-empty-${i}`} className="star empty">☆</span>);
      }
    }
    return starDisplay;
  };

  return (
    <div className="service-card">
      <img src={imageUrl} alt={name} className="profile-pic" />
      <div className="card-main-content"> 
        <div className="person-details-column"> 
          <h3 className="person-name">{name}</h3>
          <p className="person-role">{role}</p>
          <div className="star-rating-display" aria-label={`${stars} de 5 estrelas`}>
            {renderStars(stars)}
          </div>
          <div className="card-actions">
            <button className="info-button" onClick={onInfoClick}>Info</button>
            <img className="icon-action-btn calendar-icon" src={calendarIcon} alt="Calendar Icon" />
            <span className="icon-action-btn question-icon" role="img" aria-label="Ajuda">
              ?
            </span>
          </div>
        </div>
        <div className="card-focus-section">
          <p><strong>Focus:</strong> {focus}</p>
        </div>
      </div>
    </div>
  );
}

export default ServiceCard;