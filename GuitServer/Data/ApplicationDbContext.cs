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

        // DbSets existentes
        public DbSet<Archivo> Archivos { get; set; }
        public DbSet<Commit> Commits { get; set; }
        public DbSet<Cambio> Cambios { get; set; }

        // DbSets agregados para Repositorio y GuitIgnoreItem
        public DbSet<Repositorio> Repositorios { get; set; }
        public DbSet<GuitIgnoreItem> GuitIgnoreItems { get; set; }

        protected override void OnModelCreating(ModelBuilder modelBuilder)
        {
            base.OnModelCreating(modelBuilder);

            // Configuración adicional para la entidad Repositorio, si es necesario
            // Por ejemplo, para agregar la columna FechaCreacion con un valor predeterminado
            modelBuilder.Entity<Repositorio>(entity =>
            {
                entity.Property(e => e.FechaCreacion)
                      .HasDefaultValueSql("CURRENT_TIMESTAMP");
            });

            // Cualquier otra configuración de modelo específica viene aquí
        }
    }
}