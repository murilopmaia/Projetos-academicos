
import { BrowserRouter, Routes, Route, Navigate } from "react-router-dom";

//Pages
import Home from "./pages/Home/Home";
import Page_Not from "./pages/Page_Not/Page_Not";
import Login from './pages/Login/Login'
import SignUp from './pages/SignUp/SignUp'
import Erro_404 from "./pages/Erro_404/Erro_404";

//css
import "./App.css";

function App() {
  return (
    <div className="App">
      <BrowserRouter>
        <Routes>
          <Route path="/gfood" element={<Home />} />
          <Route path="/About" element={<Page_Not />} />
          <Route path="/Contact" element={<Page_Not />} />
          <Route path="/Order" element={<Page_Not />} />
          <Route path="/Payment" element={<Page_Not />} />
          <Route path="/Terms" element={<Page_Not />} />
          <Route path="/Shope" element={<Page_Not />} />
          <Route path="/Order" element={<Page_Not />} />
          <Route path="/Login" element={<Login />}/>
          <Route path="/SignUp" element={<SignUp/>}/>
          <Route path='*' element={<Erro_404 />}/> 
        </Routes>
      </BrowserRouter>
    </div>
  );
}

export default App;
