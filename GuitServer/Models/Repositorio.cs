using System;

namespace GuitServer.Models
{
    public class Repositorio
    {
        public int Id { get; set; }
        public DateTime FechaCreacion { get; set; }
        public string? Nombre { get; set; }

        // Constructor sin parámetros con inicialización de propiedades
        public Repositorio()
        {
            FechaCreacion = DateTime.Now; // Establece la fecha de creación al momento actual
            Nombre = string.Empty; // O cualquier valor predeterminado adecuado
        }
    }

    public class GuitIgnoreItem
    {
        public int Id { get; set; }
        public string Pattern { get; set; }
        public int RepositoryId { get; set; }

        // Propiedad de navegación para el repositorio asociado
        public Repositorio Repository { get; set; }

        // Constructor sin parámetros
        public GuitIgnoreItem()
        {
            Pattern = string.Empty; // Inicializa Pattern con un valor predeterminado si es necesario
        }
    }
}