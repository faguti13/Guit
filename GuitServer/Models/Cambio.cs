namespace GuitServer.Models
{
    public class Cambio
    {
        public int Id { get; set; }
        public int CommitId { get; set; }
        public int ArchivoId { get; set; }
        public string TipoCambio { get; set; }
        public byte[] Diferencia { get; set; }

        public Commit Commit { get; set; }
        public Archivo Archivo { get; set; }
    }
}
