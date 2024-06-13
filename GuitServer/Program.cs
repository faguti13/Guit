using Microsoft.EntityFrameworkCore;
using Microsoft.OpenApi.Models;
using GuitServer.Data; // Asegúrate de que esta es la directiva correcta para tu namespace
var builder = WebApplication.CreateBuilder(args);

// Add services to the container.
builder.Services.AddEndpointsApiExplorer();
builder.Services.AddSwaggerGen(c =>
{
    c.SwaggerDoc("v1", new OpenApiInfo { Title = "GuitServer API", Version = "v1" });
});

// Configurar el contexto de la base de datos
builder.Services.AddDbContext<ApplicationDbContext>(options =>
    options.UseMySql(builder.Configuration.GetConnectionString("DefaultConnection"), 
        new MySqlServerVersion(new Version(8, 0, 21))));

var app = builder.Build();

// Configure the HTTP request pipeline.
if (app.Environment.IsDevelopment())
{
    app.UseSwagger();
    app.UseSwaggerUI(c => c.SwaggerEndpoint("/swagger/v1/swagger.json", "GuitServer API v1"));
}

app.UseHttpsRedirection();

var summaries = new[]
{
    "Freezing", "Bracing", "Chilly", "Cool", "Mild", "Warm", "Balmy", "Hot", "Sweltering", "Scorching"
};

app.MapGet("/weatherforecast", () =>
{
    var forecast = Enumerable.Range(1, 5).Select(index =>
        new WeatherForecast
        (
            DateOnly.FromDateTime(DateTime.Now.AddDays(index)),
            Random.Shared.Next(-20, 55),
            summaries[Random.Shared.Next(summaries.Length)]
        ))
        .ToArray();
    return forecast;
})
.WithName("GetWeatherForecast")
.WithOpenApi();

// Agregar rutas para manejar comandos específicos
app.MapPost("/commands/init", () =>
{
    // Lógica para manejar el comando init
    // Por ejemplo, inicializar configuraciones o datos necesarios
    return Results.Ok("Comando init procesado");
});

app.MapPost("/commands/add", (string item) =>
{
    // Lógica para manejar el comando add
    // 'item' representa el elemento a agregar, procesamiento según sea necesario
    return Results.Ok($"Item {item} agregado correctamente");
});

app.Run();

record WeatherForecast(DateOnly Date, int TemperatureC, string? Summary)
{
    public int TemperatureF => 32 + (int)(TemperatureC / 0.5556);
}