using UescColcicAPI.Services.BD.Interfaces;
using UescColcicAPI.Core;
using System.Collections.Generic;

namespace UescColcicAPI.Services.BD;

public class StudentsCRUD : IStudentsCRUD
{
    private static readonly List<Student> Students = new()
   {
      new Student {Name = "Douglas", Email = "douglas.cic@uesc.br" },
      new Student {Name = "Estevão", Email = "estevao.cic@uesc.br" },
      new Student {Name = "Gabriel", Email = "gabriel.cic@uesc.br" },
      new Student {Name = "Gabriela", Email = "gabriela.cic@uesc.br" }
   };
    public void Create(Student entity)
    {
         if(!Students.Exists(x => x.Email == entity.Email)){
            Students.Add(entity);
        }
        
    }

    public void Delete(Student entity)
    {
        var student = Students.FirstOrDefault(x => x.Email == entity.Email);
        if(student is not null){
            Students.Remove(student);
        }
        
    }

    public IEnumerable<Student> ReadAll()
    {
        return Students;
    }

    public void Update(Student entity)
    {

        var student = Students.FirstOrDefault(x => x.Email == entity.Email);
        if(student is not null) {
            student.Name = entity.Name;
        }
        else{
            
        }
    }

}
