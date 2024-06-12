using Microsoft.EntityFrameworkCore;
using GuitServer.Models;


namespace GuitServer.Data
{
    public class ApplicationDbContext : DbContext
    {
        public ApplicationDbContext(DbContextOptions<ApplicationDbContext> options)
            : base(options)
        {
        }

        // Definir tus DbSets aquí. Por ejemplo:
        public DbSet<Archivo> Archivos { get; set; }
        public DbSet<Commit> Commits { get; set; }
        public DbSet<Cambio> Cambios { get; set; }
    }
}
