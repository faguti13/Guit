namespace GuitServer.Models
{
    public class Archivo
    {
        public int Id { get; set; }
        public int RepositorioId { get; set; }
        public string Nombre { get; set; }
        public byte[] Contenido { get; set; }
        public DateTime FechaCreacion { get; set; }

        public Repositorio Repositorio { get; set; }
    }
}
