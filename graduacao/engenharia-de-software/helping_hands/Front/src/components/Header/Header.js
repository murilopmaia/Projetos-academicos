import React from 'react';
import logoImage from '../../assents/logo.png';
import iconHome from '../../assents/home.png';
import iconChat from '../../assents/chat.png';
import iconCalendar from '../../assents/calendar.png';
import iconProfile from '../../assents/profile.png';
 
import './Header.css'

function Header() {
  return (
    <header className="app-header">
      <div className="logo-container">
        <img src={logoImage} alt="Helping Hand Logo" className='logo-image'/>
      </div>
      <nav className="nav-icons">
        <img src={iconHome} alt="Icon Home" />
        <img src={iconChat} alt="Icon Chat" />
        <img src={iconProfile} alt="Icon Profile" />
        <img src={iconCalendar} alt="Icon Calendar" />
      </nav>
    </header>
  );
}

export default Header;