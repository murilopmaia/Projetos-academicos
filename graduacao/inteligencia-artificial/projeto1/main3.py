import numpy as np
import time
import timeit

class Problem:
    def __init__(self, initial, neighbors, heuristic, generate, goal) -> None:
        self.initial = initial
        self.neighbors = neighbors
        self.heuristic = heuristic
        self.goal = goal
        self.generate = generate
    
    def get_neighbors(self, state):
        return self.neighbors(state)
    
    def get_heuristic(self, state) :
        return self.heuristic(state)
    
    def goal_test(self, state):
        if self.get_heuristic(state) == self.goal:
            return True
        return False
    
    def generate_state(self):
        return self.generate()
    
# Hill_Climbing     
class Hill_Climbing:
    def __init__(self, problem: Problem) -> None:
        self.problem = problem
    
    def search(self, state = None):
        current = self.problem.initial if state is None else state
        while True:
            neighbors = sorted(self.problem.get_neighbors(current), key = lambda x:self.problem.get_heuristic(x))
            best_neighbor = neighbors[0]
            best_neighbor_h = self.problem.get_heuristic(best_neighbor)
            if best_neighbor_h >= self.problem.get_heuristic(current):
                return current
            current = best_neighbor

# Hill_random_climbing
class Hill_random_climbing:
    def __init__(self, problem: Problem) -> None:
        self.problem = problem

    def search(self, state = None):
        current = self.problem.initial if state is None else state
        while True:
            neighbors = sorted(self.problem.get_neighbors(current), key = lambda x:self.problem.get_heuristic(x))
            heur = [100 - self.problem.get_heuristic(x) for x in neighbors]
            i = np.random.choice(len(neighbors), p = heur/np.sum(heur))
            best_neighbor = neighbors[i]
            best_neighbor_h = heur[i]
            if best_neighbor_h >= self.problem.get_heuristic(current):
                return current
            current = best_neighbor

# Hill_climbing_width_lateral
class Hill_climbing_width_lateral:
    def __init__(self, problem: Problem) -> None:
        self.problem = problem
    
    def search(self, max_steps = 10, state = None):
        current = self.problem.initial if state is None else state
        current_h = self.problem.get_heuristic(current)
        latStep = 0
        while True:
            neighbors = sorted(self.problem.get_neighbors(current), key = lambda x:self.problem.get_heuristic(x))
            best_neighbor = neighbors[0]
            best_neighbor_h = self.problem.get_heuristic(best_neighbor)
            if best_neighbor_h >= current_h:
                if latStep == max_steps:
                    return current
                best_neighbor = neighbors[np.random.randint(0, len(neighbors))]
                latStep += 1
            else:
                latStep = 0
            current = best_neighbor
            current_h = best_neighbor_h
            if self.problem.goal_test(current):  
                return current

# Random_restart_hill_climbing

class Random_restart_hill_climbing:
    def __init__(self, problem: Problem) -> None:
        self.problem = problem
        self.hill_climbing = Hill_Climbing(problem)

    def search(self, state = None):
        current = self.problem.initial if state is None else state
        while True:
            solution = self.hill_climbing.search(current)
            if self.problem.goal_test(solution):
                return solution
            current = self.problem.generate_state()

# Random_restart_hill_climbing_with_laterals

class Random_restart_hill_climbing_with_laterals:
    def __init__(self, problem: Problem):
        self.problem = problem
        self.hill_climbing_width_lateral = Hill_climbing_width_lateral(problem)

    def search(self, state = None):
        current = self.problem.initial if state is None else state
        while True:
            
            solution= self.hill_climbing_width_lateral.search(state=current)
            if self.problem.goal_test(solution):
                return solution
            current = self.problem.generate_state()

# Simulated_annealing

class Simulated_annealing:
    def __init__(self, problem: Problem, schedule) -> None:
        self.problem = problem
        self.schedule = schedule

    def search(self, state=None):
        current = self.problem.initial if state is None else state
        t = 0
        while True:
            T = self.schedule(t)
            t += 1
            if T <= 1e-10:  # Evitar T ser zero ou próximo de zero
                return current
            neighbors = self.problem.get_neighbors(current)
            if not neighbors:
                return current
            neighbor = neighbors[np.random.randint(0, len(neighbors))]
            delta_e = self.problem.get_heuristic(current) - self.problem.get_heuristic(neighbor)
            if delta_e > self.problem.goal:
                current = neighbor
            else:
                # Usar np.clip para evitar overflow
                prob = np.exp(np.clip(delta_e / T, -500, 500))
                if np.random.random() < prob:
                    current = neighbor
            if self.problem.get_heuristic(current) == 0:
                return current
            
# local_been_search

class Local_bean_search:
    def __init__(self, problem: Problem, k = 10) -> None:
        self.problem = problem
        self.k = k
    
    def search(self, maxStep = 100, state = None):
        bean = []
        step = 0
        for i in range(self.k):
            bean.append(self.problem.generate_state())
            if self.problem.goal_test(bean[i]):
                return bean[i]
        while True:
            step += 1
            neighbors = []
            for i in range(self.k):
                neighbors = sorted(neighbors + self.problem.get_neighbors(bean[i]), key = lambda x:self.problem.get_heuristic(x))
            bean = neighbors[:self.k]
            if self.problem.goal_test(bean[0]):
                return bean[0]
            if step == maxStep:
                return bean[0]

# genetic_algorithm

class Genetic_algorithm:
    def __init__(self, problem: Problem, fitness, population_size = 10, mutation_rate = 0.1):
        self.problem = problem
        self.population_size = population_size
        self.mutation_rate = mutation_rate
        self.fitness = fitness

    def search(self, stepL = 100):
        def weighted_by(population, fitness):
            return [fitness(individual) for individual in population]
        def weighted_random_choices(population, weights, n):
            return [population[i] for i in np.random.choice(len(population), n, p = weights/np.sum(weights))]
        def reproduce(parent1, parent2):
            n = len(parent1)
            c = np.random.randint(1, n)
            return np.array(list(parent1[:c]) + list(parent2[c:]))
        def mutate(child):
            n = len(child)
            c = np.random.randint(0, n)
            child[c] = np.random.randint(1, 9)
            return child
        step = 0
        population = []
        for j in range(self.population_size):
            population.append(self.problem.generate_state())
        while True:
            step += 1
            weights = weighted_by(population, self.fitness)
            population2 = []
            for i in range(len(population)):
                parent1, parent2 = weighted_random_choices(population, weights, 2)
                child = reproduce(parent1, parent2)
                if np.random.random() < self.mutation_rate:
                    child = mutate(child)
                population2.append(child)
            population = sorted(population2, key = lambda x:self.fitness(x))
        
            if (self.problem.goal_test(population[-1])) or (step == stepL):
                return population[-1]
def main():
    state = np.random.randint(1, 9, 8)

    def next_state(state):
        next_states = []
        for i in range(8):
            for j in range(1, 9):
                if j != state[i]:
                    next_state = state.copy()
                    next_state[i] = j
                    next_states.append(next_state)
        return next_states
    
    def eight_queens_heuristic(state):
        h = 0
        for i in range(8):
            for j in range(i+1, 8):
                if state[i] == state[j]:
                    h += 1
                    continue
                if state[i] == state[j] + (j - i):
                    h += 1
                    continue
                if state[i] == state[j] - (j - i):
                    h += 1
        return h

    def geometric_schedule(t, T0 = 500, k = 0.5, n_iter = 10):
        return (T0 * np.exp(-k * t / (n_iter - 1)))

    def exponential_schedule(t, T0 = 8, alpha = 0.99):
        return (T0 * alpha**t)

    def linear_schedule(t, T0 = 10, n_iter = 100):
        return (T0 * (1 - t / n_iter))
    

    
    eight_queensP = Problem(state, next_state, eight_queens_heuristic, lambda: np.random.randint(1, 9, 8), 0)
    hill_Climbing = Hill_Climbing(eight_queensP)
    hill_random_climbing = Hill_random_climbing(eight_queensP)
    hill_climbing_width_lateral = Hill_climbing_width_lateral(eight_queensP)
    random_restart_hill_climbing = Random_restart_hill_climbing(eight_queensP)
    random_restart_hill_climbing_with_laterals = Random_restart_hill_climbing_with_laterals(eight_queensP)
    simulated_annealing_geometric = Simulated_annealing(eight_queensP, geometric_schedule)
    simulated_annealing_exponential = Simulated_annealing(eight_queensP, exponential_schedule)
    simulated_annealing_linear = Simulated_annealing(eight_queensP, linear_schedule)
    local_bean_search = Local_bean_search(eight_queensP)
    genetic_algorithm = Genetic_algorithm(eight_queensP, lambda x: (28 - eight_queensP.get_heuristic(x)), population_size=100)
    
    numberBus = 10
    print("Tempo para realizar 50 buscas\n")
    print("Hill Climbing")
    tempo_execucao = timeit.timeit(lambda: hill_Climbing.search(), number=numberBus)
    print(f'Tempo de execucao - {tempo_execucao:.2f} segundos\n')
    print("Hill Climbing Random")
    tempo_execucao = timeit.timeit(lambda: hill_random_climbing.search(), number=numberBus)
    print(f'Tempo de execucao - {tempo_execucao:.2f} segundos\n')
    print("Hill Cimbling Width Lateral")
    tempo_execucao = timeit.timeit(lambda: hill_climbing_width_lateral.search(), number=numberBus)
    print(f'Tempo de execucao - {tempo_execucao:.2f} segundos\n')
    print("Random Restart Hill Climbing")
    tempo_execucao = timeit.timeit(lambda: random_restart_hill_climbing.search(), number=numberBus)
    print(f'Tempo de execucao - {tempo_execucao:.2f} segundos\n')
    print("Random Restart Hill Climbing Width Laterals")
    tempo_execucao = timeit.timeit(lambda: random_restart_hill_climbing_with_laterals.search(), number=numberBus)
    print(f'Tempo de execucao - {tempo_execucao:.2f} segundos\n')
    print("Simulated Anealing Geometric")
    tempo_execucao = timeit.timeit(lambda: simulated_annealing_geometric.search(), number=numberBus)
    print(f'Tempo de execucao - {tempo_execucao:.2f} segundos\n')
    print("Simulated Anealing Exponention")
    tempo_execucao = timeit.timeit(lambda: simulated_annealing_exponential.search(), number=numberBus)
    print(f'Tempo de execucao - {tempo_execucao:.2f} segundos\n')
    print("Simulated Anealing Linear")
    tempo_execucao = timeit.timeit(lambda: simulated_annealing_linear.search(), number=numberBus)
    print(f'Tempo de execucao - {tempo_execucao:.2f} segundos\n')
    print("Local Bean Search")
    tempo_execucao = timeit.timeit(lambda: local_bean_search.search(), number=numberBus)
    print(f'Tempo de execucao - {tempo_execucao:.2f} segundos\n')
    print("Genetic Algorithm")
    tempo_execucao = timeit.timeit(lambda: genetic_algorithm.search(), number=numberBus)
    print(f'Tempo de execucao - {tempo_execucao:.2f} segundos\n')

    i = 0
    count = 0
    respostas = []
    inicio = time.time()
    while(i < 20):
        count += 1 
        val = random_restart_hill_climbing_with_laterals.search()
        random_restart_hill_climbing_with_laterals.problem.initial = random_restart_hill_climbing_with_laterals.problem.generate_state()
        if eight_queensP.goal_test(val) == True:    
            if val.tolist() not in respostas:
                i += 1
                respostas.append(val.tolist())
                print(f"Numero de tentativas - {count}     Numero de solucoes encontradas {i}")
                print(f"    Solucao - {val}")
        
    fim = time.time()
    print(f"\nPorcentagem de acerto {(i * 100)/ count : .2f}%")
    print(f"Tempo de execucao - {fim - inicio:.2f} segundos")
    print("\nSolucoes encontradas: ")
    for i in range(20):
        print(f"    {respostas[i]} - {eight_queensP.get_heuristic(respostas[i])}")

if __name__ == '__main__':
    main()