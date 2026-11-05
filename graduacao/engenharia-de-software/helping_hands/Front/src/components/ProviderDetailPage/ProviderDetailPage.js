import React from 'react';
import commentIcon from '../../assents/comment.png'
import starsIcon from '../../assents/stars.png'
import calendarIcon from '../../assents/calendar.png'

import './ProviderDetailPage.css'

// Componente para a Página de Detalhes do Prestador
function ProviderDetailPage({ provider, onBack, onScheduleClick }) {
  if (!provider) {
    return <div>Prestador não encontrado. <button onClick={onBack}>Voltar</button></div>;
  }

  // Desestruturar todos os dados do prestador
  const { 
    name, role, imageUrl, stars, reviewsCount, scheduleSummary, 
    experienceYears, focus, profileBio, professionalExperience, highlights 
  } = provider;

  return (
    <div className="detail-page">
      
      <h2 className="detail-page-title">Service Info</h2>
      
      <div className="detail-content-wrapper">
        <button className="back-arrow" onClick={onBack}>
          &lt;
        </button>
        <div className="provider-detail-card">
          {/* Coluna da Esquerda */}
          <div className="detail-left-column">
            <img src={imageUrl} alt={name} className="detail-profile-pic" />
            <div className="detail-name-card">
              <h1 className="detail-name">{name}</h1>
              <p className="detail-role">{role}</p>
            </div>
            <div className="detail-stats-bar">
            <div className="stat-item">
              <img src={starsIcon} alt="stars icon" />
              <span>{stars}</span>
            </div>
            <div className="stat-item">
              <img src={commentIcon} alt="comment icon" />
              <span>{reviewsCount || 0}</span>
            </div>
            <div className="stat-item">
              <img src={calendarIcon} alt="calendar icon" />
              <span>{scheduleSummary}</span>
            </div>
          </div>
            <button className="schedule-button" onClick={onScheduleClick}>Schedule</button>
            
          </div>

          {/* Coluna da Direita */}
          <div className="detail-right-column">
            {experienceYears && (
              <div className="experience-box">
                <span className="icon" role="img" aria-label="Experience">💡</span>
                <strong>{experienceYears} years experience</strong>
              </div>
            )}
            <div className="detail-focus-section">
              <p><strong>Focus:</strong> {focus}</p>
            </div>

            <div className="profile-section">
              <h3>Profile</h3>
              <p>{profileBio}</p>
            </div>
            <div className="profile-section">
              <h3>Professional Experience</h3>
              <p>{professionalExperience}</p>
            </div>
            <div className="profile-section">
              <h3>Highlights</h3>
              <ul>
                {highlights && highlights.map((item, index) => (
                  <li key={index}>{item}</li>
                ))}
              </ul>
            </div>
          </div>
        </div>
      </div>
    </div>
  );
}

export default ProviderDetailPage;