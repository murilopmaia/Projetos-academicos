// Crie o novo arquivo: src/components/SchedulingPage.js
import React, { useState, useEffect } from 'react';
import commentIcon from '../../assents/comment.png'
import starsIcon from '../../assents/stars.png'
import "./SchedulingPage.css"


// (Opcional) Helper para manipular datas. Para projetos reais, use uma biblioteca como date-fns.
const getDayInfo = (dateString) => {
  const date = new Date(`${dateString}T00:00:00`);
  const day = date.getDate();
  const weekday = date.toLocaleDateString('en-US', { weekday: 'short' }).toUpperCase();
  return { day, weekday };
};

function SchedulingPage({ provider, onCancel, onConfirm }) {
  const [selectedDate, setSelectedDate] = useState(null);
  const [selectedTime, setSelectedTime] = useState(null);
  const [patientType, setPatientType] = useState('yourself');
  const [formData, setFormData] = useState({
    fullName: '',
    age: '',
    gender: 'Female', // Valor padrão
    need: ''
  });
  
  // Encontra os horários disponíveis para a data selecionada
  const availableTimeSlots = provider.Availabilities?.find(a => a.date.split('T')[0] === selectedDate)?.TimeSlots || [];

  const handleDateSelect = (dateStr) => {
    setSelectedDate(dateStr);
    setSelectedTime(null); // Reseta a hora ao mudar o dia
  };
  
  const handleInputChange = (e) => {
    const { name, value } = e.target;
    setFormData(prev => ({ ...prev, [name]: value }));
  };

    const handleGenderSelect = (gender) => {
        setFormData(prev => ({ ...prev, gender }));
    };

  const handleConfirmBooking = () => {
    if (!selectedDate || !selectedTime) {
      alert('Por favor, selecione uma data e um horário.');
      return;
    }
    const bookingDetails = {
      providerId: provider.id,
      date: selectedDate,
      time: selectedTime,
      patientDetails: formData
    };
    console.log('Confirmando agendamento:', bookingDetails);
    onConfirm(bookingDetails); // Chama a função passada por props
  };

  return (
    <div className="scheduling-page">
      {/* Barra de informações do Prestador */}
      <div className="provider-info-bar">
        <div className="provider-name-pill">
            {provider.name}
        </div>
        <div className="provider-actions">
            {/* Ícone de Estrelas */}
            <div className="action-icon-circle">
            <img src={starsIcon} alt="Stars" />
            </div>
            
            {/* Ícone de Comentários */}
            <div className="action-icon-circle">
            <img src={commentIcon} alt="Comments" />
            </div>

            {/* Ícone de Interrogação */}
            <div className="action-icon-circle">
            <span className="blue-question-mark">?</span>
            </div>
        </div>
        </div>
      
      <div className="scheduler-container">
        {/* Coluna da Esquerda: Calendário e Horários */}
        <div className="time-selection-column">
            <div className='month-date-selector'>
                <div className="month-selector">
                    <h3>July</h3> {/* Lógica para mudar de mês seria adicionada aqui */}
                    <span>▼</span>
                </div>

                <div className="date-scroller">
                    {provider.Availabilities?.map(avail => {
                    const dateStr = avail.date.split('T')[0];
                    const { day, weekday } = getDayInfo(dateStr);
                    return (
                        <div 
                        key={dateStr}
                        className={`date-item ${selectedDate === dateStr ? 'selected' : ''}`}
                        onClick={() => handleDateSelect(dateStr)}
                        >
                        <span>{weekday}</span>
                        <strong>{day}</strong>
                        </div>
                    );
                    })}
                </div>
            </div>
          

          <h3 className="available-time-title">Available Time</h3>
          <div className="time-grid">
            {availableTimeSlots.map(slot => (
              <button 
                key={slot.time}
                className={`time-slot ${selectedTime === slot.time ? 'selected' : ''}`}
                onClick={() => setSelectedTime(slot.time)}
              >
                {slot.time}
              </button>
            ))}
          </div>
        </div>

        {/* Coluna da Direita: Formulário */}
        <div className="patient-form-column">
            <h3>Patient Details</h3>
            <div className="patient-type-tabs">
                <button
                type="button"
                className={patientType === 'yourself' ? 'active' : ''}
                onClick={() => setPatientType('yourself')}
                >
                Yourself
                </button>
                <button
                type="button"
                className={patientType === 'another' ? 'active' : ''}
                onClick={() => setPatientType('another')}
                >
                Another Person
                </button>
            </div>

            <form className="patient-form">
                <label htmlFor="fullName">Full Name</label>
                <input id="fullName" type="text" name="fullName" value={formData.fullName} onChange={handleInputChange} placeholder="Jane" />
                
                <label htmlFor="age">Age</label>
                <input id="age" type="number" name="age" value={formData.age} onChange={handleInputChange} placeholder="30" />

                <label>Gender</label>
                <div className="gender-options">
                {['Male', 'Female', 'Other'].map(genderValue => (
                    <button
                    key={genderValue}
                    type="button" // Importante para não submeter o formulário
                    className={`gender-btn ${formData.gender === genderValue ? 'active' : ''}`}
                    onClick={() => handleGenderSelect(genderValue)}
                    >
                    {genderValue}
                    </button>
                ))}
                </div>

                {/* Linha separadora */}
                <div className="form-separator"></div>

                <label htmlFor="need">Describe your need</label>
                <textarea id="need" name="need" value={formData.need} onChange={handleInputChange} placeholder="Enter Your Need Here..."></textarea>
            </form>
            
            <div className="form-actions">
                <button className="cancel-btn" onClick={onCancel}>Cancel</button>
                <button className="confirm-btn" onClick={handleConfirmBooking}>Confirm</button>
            </div>
            </div>
      </div>
    </div>
  );
}

export default SchedulingPage;