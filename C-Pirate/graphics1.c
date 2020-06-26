

//Compile this program by executing this: gcc -w `pkg-config --cflags gtk+-3.0` -o graphics1 graphics1.c `pkg-config --libs gtk+-3.0`
#include <gtk/gtk.h>
#include <stdlib.h>
#include <string.h>

char file_name[100];

static void
ls_command (GtkWidget *widget,
             gpointer   data)        
{
  
  system("ls");
}



static void gcc(GtkWidget *widget,
             gpointer   data)
{

  char add[100] = "gcc ";
  strcat(add,file_name);
  system("echo \"Compiled \"");
  system(add);
  
}


static void run_program(GtkWidget *widget,
             gpointer   data)
{
  system("./a.out");
}



static void clear(GtkWidget *widget,
             gpointer   data)
{
  system("clear");
}


static void new(GtkWidget *widget,
             gpointer   data)
{

  
  char add[100] = "gnome-terminal -e \"vim ";
  printf("Enter the name of the file\n");
  scanf("%s[^\n]",file_name);

  strcat(add,file_name);
  strcat(add,"\"");



  if( access( file_name, F_OK ) != -1 ) { 
    system("echo \"The file exits, opening that file to edit\"");
    system(add);
    system("clear");
} else {
    
    system(add);
    system("clear");
}
  
}






int
main (int   argc,
      char *argv[])
{
  GtkBuilder *builder;
  GObject *window;
  GObject *button;
  GError *error = NULL;
  

  gtk_init (&argc, &argv);

  /* Construct a GtkBuilder instance and load our UI description */
  builder = gtk_builder_new ();
  if (gtk_builder_add_from_file (builder, "builder.ui", &error) == 0)
    {
      g_printerr ("Error loading file: %s\n", error->message);
      g_clear_error (&error);
      return 1;
    }

  /* Connect signal handlers to the constructed widgets. */
  window = gtk_builder_get_object (builder, "window");
  g_signal_connect (window, "destroy", G_CALLBACK (gtk_main_quit), NULL);

  button = gtk_builder_get_object (builder, "button1");
  g_signal_connect (button, "clicked", G_CALLBACK (ls_command), NULL);

  button = gtk_builder_get_object (builder, "button2");
  g_signal_connect (button, "clicked", G_CALLBACK (gcc), NULL);

  button = gtk_builder_get_object (builder, "button3");
  g_signal_connect (button, "clicked", G_CALLBACK (run_program), NULL);

   button = gtk_builder_get_object (builder, "new");
  g_signal_connect (button, "clicked", G_CALLBACK (new), NULL);


   button = gtk_builder_get_object (builder, "clear");
  g_signal_connect (button, "clicked", G_CALLBACK (clear), NULL);

  
  

  button = gtk_builder_get_object (builder, "quit");
  g_signal_connect (button, "clicked", G_CALLBACK (gtk_main_quit), NULL);


  gtk_main ();

  return 0;
}



 
    
     
    
