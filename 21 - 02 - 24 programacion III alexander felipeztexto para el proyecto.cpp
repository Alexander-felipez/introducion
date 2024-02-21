
LIBRO
(title: String) random
(author: String) random
(ISBN: String) 1,2,3,4,5
(publicationYear: Integer) random
-adicionar 3 atributos
condition: String - "Nuevo", "Usado - Buen estado", "Coleccionista", "Como nuevo", "Usado - Regular estado"
genre: String - "Misterio", "Ciencia ficción", "Romance", "Realismo mágico", "Fantasía"
language: String - "Inglés", "Español", "Francés", "Alemán", "Italiano"
ageRecommendation: String - "12+", "18+", "Todas las edades", "16+", "8+"

USUARIO
(userID: Integer) 1,2,3,4,5
(name: String) random
(lastname: String) random
(email: String) convinar nombre y apellido
-adicionar 1 atributos
gender: String - "Femenino", "Masculino", "No binario", "Prefiero no decirlo", "Otro"

BIBLIOTECARIO
(employeeID: Integer)
(name: String)
(lastname: String)
(email: String)
-adicionar 1 atributos
turnoLaboral - "Mañana", "Tarde" y "Noche"