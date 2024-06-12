namespace GuitServer.Models
{
    public class Commit
    {
        public int Id { get; set; }
        public int RepositorioId { get; set; }
        public string Mensaje { get; set; }
        public DateTime Fecha { get; set; }
        public string Checksum { get; set; }

        public Repositorio Repositorio { get; set; }
    }
}
