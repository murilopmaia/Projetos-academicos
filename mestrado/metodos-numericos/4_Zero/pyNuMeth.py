def bissecao(f, a, b, tol=1e-8, max_iter=100):
    # Verificação
    FA = f(a)
    if FA * f(b) >= 0:
        print("Erro: A função deve ter sinais opostos em a e b (f(a) * f(b) < 0).")
        return None

    # Passo 1 e 2
    for i in range(1, max_iter + 1):
        
        # Passo 3
        p = a + (b - a) / 2.0  
        FP = f(p)
        
        # Passo 4
        if FP == 0 or (b - a) / 2.0 < tol:
            return p
        
        # Passo 6
        if FA * FP > 0:
            a = p
            FA = FP 
        else:
            b = p
            
    # Passo 7
    print(f"O método falhou após atingir o limite de {max_iter} iterações.")
    return p 

def bissecao_com_historico(f, a, b, tol=1e-8, max_iter=100):
    historico = {
        'iter': [],
        'a': [],
        'b': [],
        'c': [],
        'f(c)': [],
        'erro_Intervalo': []
    }
    
    FA = f(a)
    if FA * f(b) >= 0:
        print("Erro: A função deve ter sinais opostos em a e b (f(a) * f(b) < 0).")
        return None, None

    for i in range(1, max_iter + 1):
        
        c = a + (b - a) / 2.0  
        FC = f(c)
        erro = (b - a) / 2.0
        
        historico['iter'].append(i)
        historico['a'].append(a)
        historico['b'].append(b)
        historico['c'].append(c)
        historico['f(c)'].append(FC)
        historico['erro_Intervalo'].append(erro)
        
        if FC == 0 or erro < tol:
            return c, historico

        if FA * FC > 0:
            a = c
            FA = FC 
        else:
            b = c

    print(f"O método falhou após atingir o limite de {max_iter} iterações.")
    return c, historico

def bissecao_criterios_com_historico(f, a, b, tol=1e-5, max_iter=100, criterio=1):
    historico = {
        'iter': [], 'a': [], 'b': [], 'c': [], 'f(c)': [], 'valor_criterio': []
    }
    
    FA = f(a)
    if FA * f(b) >= 0:
        print("Erro: A função deve ter sinais opostos em a e b.")
        return None, None

    p_prev = None 

    for i in range(1, max_iter + 1):
        p = a + (b - a) / 2.0  
        FP = f(p)

        valor_crit = None
        
        if criterio == 3:
            valor_crit = abs(FP)
        elif p_prev is not None: 
            if criterio == 1:
                valor_crit = abs(p - p_prev)
            elif criterio == 2:
                if abs(p) > 1e-15:
                    valor_crit = abs(p - p_prev) / abs(p)

        historico['iter'].append(i)
        historico['a'].append(a)
        historico['b'].append(b)
        historico['c'].append(p)
        historico['f(c)'].append(FP)

        historico['valor_criterio'].append(valor_crit if valor_crit is not None else float('inf'))

        if valor_crit is not None and valor_crit < tol:
            return p, historico
 
        if FA * FP > 0:
            a = p
            FA = FP 
        else:
            b = p
            
        p_prev = p
            
    print(f"Aviso: Limite de iterações atingido ({max_iter}).")
    return p, historico

def ponto_fixo(g, x0, tol=1e-8, max_iter=100):
    
    # Passo 1
    i = 1
    
    # Passo 2\
    while i <= max_iter:
        
        # Passo 3
        p = g(x0)
        
        # Passo 4
        if abs(p - x0) < tol:
            return p
        
        # Passo 5
        i += 1
        
        # Passo 6
        x0 = p
        
    # Passo 7
    print(f"O método falhou após atingir o limite de {max_iter} iterações.")
    return p

def ponto_fixo_com_historico(g, x0, tol=1e-8, max_iter=100):
    historico = {'iter': [], 'x_anterior': [], 'x_novo': [], 'erro': []}
    
    for i in range(1, max_iter + 1):
        p = g(x0)
        erro = abs(p - x0)

        historico['iter'].append(i)
        historico['x_anterior'].append(x0)
        historico['x_novo'].append(p)
        historico['erro'].append(erro)

        if erro < tol:
            return p, historico

        x0 = p
        
    return p, historico

def newton(f, df, x0, tol=1e-10, max_iter=50):
    # Passo 1 e 2
    for i in range(1, max_iter + 1):
        fx = f(x0)
        dfx = df(x0)

        # Passo 3
        x1 = x0 - (fx / dfx)

        # Passo 4
        if abs(x1 - x0) < tol:
            return x1
            
        # Passo 6
        x0 = x1
        
    # Passo 7
    print(f"O método falhou após atingir o limite de {max_iter} iterações.")
    return x0

def newton_com_historico(f, df, x0, tol=1e-5, max_iter=50):
    historico = {'iter': [], 'x': [], 'f(x)': [], "f'(x)": [], 'x_next': [], 'erro': []}
    
    for i in range(1, max_iter + 1):
        fx = f(x0)
        dfx = df(x0)
        
        if dfx == 0:
            print("Derivada nula encontrada. O método falhou.")
            return x0, historico
            
        x1 = x0 - (fx / dfx)
        erro = abs(x1 - x0)
        
        historico['iter'].append(i)
        historico['x'].append(x0)
        historico['f(x)'].append(fx)
        historico["f'(x)"].append(dfx)
        historico['x_next'].append(x1)
        historico['erro'].append(erro)
        
        if erro < tol:
            return x1, historico
            
        x0 = x1
        
    print(f"O método falhou após atingir o limite de {max_iter} iterações.")
    return x0, historico

def secante(f, x0, x1, tol=1e-10, max_iter=50):
    # Step 1
    i = 1
    q0 = f(x0)
    q1 = f(x1)
    
    # Step 2
    while i <= max_iter:
        
        if q1 - q0 == 0:
            print("Erro: Divisão por zero (q1 - q0 = 0). O método falhou.")
            return x1
            
        # Step 3
        p = x1 - q1 * (x1 - x0) / (q1 - q0)
        
        # Step 4
        if abs(p - x1) < tol:
            return p
            
        # Step 5
        i += 1
        
        # Step 6
        x0 = x1
        q0 = q1
        x1 = p
        q1 = f(p)
        
    # Step 7
    print(f"O método falhou após atingir o limite de {max_iter} iterações.")
    return x1

def secante_com_historico(f, x0, x1, tol=1e-10, max_iter=50):
    historico = {
        'iter': [], 
        'x_prev': [], 
        'x_curr': [], 
        'f(x_curr)': [], 
        'x_next': [], 
        'erro': []
    }
    
    i = 1
    q0 = f(x0)
    q1 = f(x1)
    
    while i <= max_iter:
        
        if q1 - q0 == 0:
            print("Erro: Divisão por zero (q1 - q0 = 0).")
            return x1, historico
            
        p = x1 - q1 * (x1 - x0) / (q1 - q0)
        erro = abs(p - x1)

        historico['iter'].append(i)
        historico['x_prev'].append(x0)
        historico['x_curr'].append(x1)
        historico['f(x_curr)'].append(q1)
        historico['x_next'].append(p)
        historico['erro'].append(erro)
        
        if erro < tol:
            return p, historico
            
        i += 1
        x0 = x1
        q0 = q1
        x1 = p
        q1 = f(p)
        
    print(f"O método falhou após atingir o limite de {max_iter} iterações.")
    return x1, historico

def newton_criterios(f, df, x0, tol=1e-5, max_iter=50, criterio=1):
    historico = {'iter': [], 'x': [], 'valor_criterio': []}
    
    for i in range(1, max_iter + 1):
        fx = f(x0)
        dfx = df(x0)
        
        if dfx == 0: return x0, historico
            
        x1 = x0 - (fx / dfx)

        if criterio == 1:
            valor_crit = abs(x1 - x0)
        elif criterio == 2:
            valor_crit = abs(x1 - x0) / abs(x1) if abs(x1) > 1e-15 else float('inf')
        elif criterio == 3:
            valor_crit = abs(f(x1))
            
        historico['iter'].append(i)
        historico['x'].append(x1)
        historico['valor_criterio'].append(valor_crit)
        
        if valor_crit < tol:
            return x1, historico
            
        x0 = x1
        
    return x0, historico


def secante_criterios(f, x0, x1, tol=1e-5, max_iter=50, criterio=1):
    historico = {'iter': [], 'x_next': [], 'valor_criterio': []}
    i = 2
    q0 = f(x0)
    q1 = f(x1)
    
    while i <= max_iter:
        if q1 - q0 == 0: return x1, historico
            
        p = x1 - q1 * (x1 - x0) / (q1 - q0)

        if criterio == 1:
            valor_crit = abs(p - x1)
        elif criterio == 2:
            valor_crit = abs(p - x1) / abs(p) if abs(p) > 1e-15 else float('inf')
        elif criterio == 3:
            valor_crit = abs(f(p))
            
        historico['iter'].append(i)
        historico['x_next'].append(p)
        historico['valor_criterio'].append(valor_crit)
        
        if valor_crit < tol:
            return p, historico
            
        i += 1
        x0, q0 = x1, q1
        x1, q1 = p, f(p)
        
    return x1, historico