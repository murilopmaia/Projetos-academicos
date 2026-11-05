import { Link, useNavigate } from "react-router-dom";
import { LoginCadas } from "../../data/LoginCadas";
import { useState } from "react";

//css
import "./SignUp.css";

//Imagem
import Fundo_img from "../../assets/Fundo_login.png";
import Imagem_lateral_img from "../../assets/Imagem_lateral.png";
import Logo_img from "../../assets/Logo.png";

function SignUp() {
  const Navigate = useNavigate();
  const [Email, setEmail] = useState("");
  const [User, setUser] = useState("");
  const [Pass, setPass] = useState("");
  const [UserERROR, setUserERROR] = useState(false);
  const [PassERROR, setPassERROR] = useState(false);
  const [EmailERROR, setEmailERROR] = useState(false);

  function HandleSubmit(e) {
    e.preventDefault();
    if (Email !== "") {
      setEmailERROR(false);
    } else {
      setEmailERROR(true);
    }

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

    if (Email !== "" && User !== "" && Pass !== "") {
      const result = LoginCadas.findIndex((item) => item.E_mail === Email);
      const resul2 = LoginCadas.findIndex((item) => item.UserName === User);
      console.log(result);
      console.log(resul2);
      if (result === -1 && resul2 === -1) {
        LoginCadas.push({
          UserName: User,
          PassWord: Pass,
          E_mail: Email,
        });
        Navigate("/gfood");
      } else if (result === -1 && resul2 !== -1) {
        setUserERROR(true);
        setUser("");
      } else {
        setEmailERROR(true);
        setEmail("");
      }
    }
  }

  return (
    <div className="Corpo_SignUp">
      <div className="Imagem_SignUp">
        <img width="100%" height="100%" src={Fundo_img} alt="Fundo" />
      </div>
      <div className="Filtro_SignUp"></div>
      <div className="Centro_SignUp">
        <div className="SignUp">
          <Link to="/gfood">
            <img src={Logo_img} alt="LOGO" />
          </Link>

          <form onSubmit={HandleSubmit}>
            <div className="Cadastro_SignUp">
              <label>
                <h5>USER NAME</h5>
                <input
                  type="text"
                  value={User}
                  onChange={(e) => setUser(e.target.value)}
                  className={UserERROR === true ? "ERRO_SignUp" : null}
                  placeholder={UserERROR === true ? "Invalid User Name" : null}
                />
              </label>
              <label>
                <h5>E-MAIL</h5>
                <input
                  type="email"
                  value={Email}
                  onChange={(e) => setEmail(e.target.value)}
                  className={EmailERROR === true ? "ERRO_SignUp" : null}
                  placeholder={EmailERROR === true ? "Invalid E-mail" : null}
                />
              </label>
              <label>
                <h5>PASSWORD</h5>
                <input
                  type="password"
                  value={Pass}
                  onChange={(e) => setPass(e.target.value)}
                  className={PassERROR === true ? "ERRO_SignUp" : null}
                  placeholder={PassERROR === true ? "Invalid PassWord" : null}
                />
              </label>
            </div>
            <div className="SignUp_Login">
              <input type="Submit" value="SignUp" />
              <p
                onClick={() => {
                  Navigate("/Login");
                }}
              >
                Do have an account?
              </p>
            </div>
          </form>
        </div>
        <div className="Imagem_lateral_SignUp">
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

export default SignUp;
