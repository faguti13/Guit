namespace GuitServer.Models
{
    public class Repositorio
    {
        public int Id { get; set; }
        public DateTime FechaCreacion { get; set; }
        public string Nombre { get; set; }
        public Repositorio()
        {
            Nombre = string.Empty; // O cualquier valor predeterminado adecuado
        }
    }
}
