
import React, { useState, useEffect } from 'react';
import './App.css';
import Header from './components/Header/Header';
import ServiceCard from './components/ServiceCard/ServiceCard';
import SearchInput from './components/SearchInput/SearchInput';
import SortControls from './components/SortControls/SortControls'; 
import ProviderDetailPage from './components/ProviderDetailPage/ProviderDetailPage'
import SchedulingPage from './components/SchedulingPage/SchedulingPage';

const API_URL = 'http://localhost:3000/api/providers/';

function App() {
  const [allProviders, setAllProviders] = useState([]);
  const [searchTerm, setSearchTerm] = useState('');
  const [sortCriteria, setSortCriteria] = useState('name'); 
  const [isLoading, setIsLoading] = useState(true);
  const [error, setError] = useState(null);

  const [selectedProviderId, setSelectedProviderId] = useState(null);
  const [isScheduling, setIsScheduling] = useState(false);

  useEffect(() => {
    const fetchProviders = async () => {
      setIsLoading(true);
      setError(null);
      try {
        const response = await fetch(API_URL);
        if (!response.ok) {
          throw new Error(`HTTP error! status: ${response.status}`);
        }
        const data = await response.json();
        if (data.status === 'success' && data.data && data.data.providers) {
          setAllProviders(data.data.providers);
        } else {
          throw new Error('Formato de dados inesperado da API.');
        }
      } catch (e) {
        console.error("Falha ao buscar prestadores:", e);
        setError(e.message);
      } finally {
        setIsLoading(false);
      }
    };

    fetchProviders();
  }, []);


  const handleSelectProvider = (id) => {
    setSelectedProviderId(id);
    setIsScheduling(false); // Garante que começamos na página de detalhes
    window.scrollTo(0, 0);
  };

  const handleGoBackToList = () => {
    setSelectedProviderId(null);
    setIsScheduling(false);
  };

  const handleShowScheduler = () => {
    setIsScheduling(true);
    window.scrollTo(0, 0);
  };

  const handleCancelScheduling = () => {
    setIsScheduling(false); // Volta para a página de detalhes
  };

  const selectedProvider = allProviders.find(p => p.id === selectedProviderId);

  if (selectedProvider && isScheduling) {
    // 3. Exibir página de agendamento
    return (
      <div >
        <Header />
        <div className="app-container">
          <SchedulingPage 
          provider={selectedProvider} 
          onCancel={handleCancelScheduling} // Volta para os detalhes
          onConfirm={() => { /* Lógica de confirmação aqui */ }}
        />
        </div>
      </div>
    );
  }

  // Renderização condicional
  if (selectedProvider) {
    return (
      <div >
        <Header />
        <div className="app-container">
          <ProviderDetailPage 
          provider={selectedProvider} 
          onBack={handleGoBackToList}
          onScheduleClick={handleShowScheduler} 
        />
        </div>
      </div>
    );
  }

  const processedProviders = allProviders
    .filter(provider =>
      provider.name.toLowerCase().includes(searchTerm.toLowerCase())
    )
    .sort((a, b) => {
      if (sortCriteria === 'name') {
        return a.name.localeCompare(b.name);
      }
      if (sortCriteria === 'stars') {
        return b.stars - a.stars; 
      }
      return 0;
    });


  if (isLoading) {
    return <div className="loading-message">Carregando prestadores...</div>;
  }

  if (error) {
    return <div className="error-message">Erro ao carregar dados: {error}</div>;
  }

  return (
    <div>
      <Header />
      <div className="app-container">
      <main className="main-content">
        <SearchInput searchTerm={searchTerm} setSearchTerm={setSearchTerm} />
        
        <h2 className="services-title">Services</h2>
        
        <SortControls sortCriteria={sortCriteria} setSortCriteria={setSortCriteria} />

        <div className="service-cards-list">
          {processedProviders.length > 0 ? (
            processedProviders.map(provider => (
              <ServiceCard
                key={provider.id}
                name={provider.name}
                role={provider.role}
                focus={provider.focus}
                imageUrl={provider.imageUrl}
                stars={provider.stars}
                onInfoClick={() => handleSelectProvider(provider.id)}
              />
            ))
          ) : (
            <p>Nenhum prestador encontrado com os critérios atuais.</p>
          )}
        </div>
      </main>
    </div>
    </div>
    
  );
}

export default App;