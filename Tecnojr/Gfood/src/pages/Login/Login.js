import { Link, useNavigate } from "react-router-dom";
import { LoginCadas } from "../../data/LoginCadas";
import { useState } from "react";

//css
import "./Login.css";

//Imagem
import Fundo_img from "../../assets/Fundo_login.png";
import Imagem_lateral_img from "../../assets/Imagem_lateral.png";
import Logo_img from "../../assets/Logo.png";

function Login() {
  const Navigate = useNavigate();
  const [User, setUser] = useState("");//Valor do input User
  const [Pass, setPass] = useState("");//Valor do input Pass
  const [UserERROR, setUserERROR] = useState(false);//Serve para demostrar que esta invalido
  const [PassERROR, setPassERROR] = useState(false);

  function HandleSubmit(e) {//Função que verifica as infomaçoes do input
    e.preventDefault();

    if (User !== "") {
      setUserERROR(false);
    } else {
      setUserERROR(true);
    }

    if (Pass !== "") {
      setPassERROR(false);
    } else {
      setPassERROR(true);
    }

    if (Pass !== "" && User !== "") {
      const result = LoginCadas.findIndex((item) => item.UserName === User);
      if (result === -1) {
        setUserERROR(true);
        setUser("");
        setPass("");
      } else {
        if (LoginCadas[result].PassWord !== Pass) {
          setPassERROR(true);
          setPass("");
        } else {
          Navigate("/gfood");
        }
      }
    }
  }

  return (
    <div className="Corpo_login">
      <div className="Imagem_login">
        <img width="100%" height="100%" src={Fundo_img} alt="Fundo" />
      </div>
      <div className="Filtro"></div>
      <div className="Centro_login">
        <div className="Login">
          <Link to="/gfood">
            <img src={Logo_img} alt="LOGO" />
          </Link>

          <form onSubmit={HandleSubmit}>
            <div className="Cadastro">
              <label>
                <h5>USER NAME</h5>
                <input
                  type="text"
                  value={User}
                  onChange={(e) => setUser(e.target.value)}
                  className={UserERROR === true ? "ERRO" : null}
                  placeholder={UserERROR === true ? "Invalid User Name" : null}
                />
              </label>
              <label>
                <h5>PASSWORD</h5>
                <input
                  type="password"
                  value={Pass}
                  onChange={(e) => setPass(e.target.value)}
                  className={PassERROR === true ? "ERRO" : null}
                  placeholder={PassERROR === true ? "Invalid PassWord" : null}
                />
              </label>
            </div>
            <div className="Login_Signup">
              <input type="Submit" value="LOGIN" />
              <p
                onClick={() => {
                  Navigate("/SignUp");
                }}
              >
                Don't have an account?
              </p>
            </div>
          </form>
        </div>
        <div className="Imagem_lateral">
          <img
            width="100%"
            height="100%"
            src={Imagem_lateral_img}
            alt="Lateral"
          />
        </div>
      </div>
    </div>
  );
}

export default Login;
