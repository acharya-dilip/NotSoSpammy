#include <stdio.h>
#include<gtk/gtk.h>


extern char gmail[50]="acharyamission6@gmail.com";
extern int tokenCount = 69;
static void activate (GtkApplication *app,gpointer user_data){
    //Declaring Necessary Items for the GUI
    GtkWidget *NotSoSpammyWindow;
    GtkWidget *gridUserIDToken; //The Grid used to organize the buttons and other GUI elements
    GtkWidget *gridParent; //The Parent grid where other sub grids will rest
    GtkWidget *displayUserID;//Will be stored in the form of Gmail for Simplicity sake
    GtkWidget *displayTokenCount;
    GtkWidget *entryRecipientMail;//WIdget for Entry
    GtkWidget *recipientMailFrame; //Widget for frame

    GtkWidget *mailDisplay;
    GtkWidget *sendMail;

    //Main Window Init and Customization
    NotSoSpammyWindow = gtk_application_window_new (app);
    gtk_window_set_title (GTK_WINDOW (NotSoSpammyWindow), "NotSoSpammy");
    gtk_window_set_default_size (GTK_WINDOW (NotSoSpammyWindow), 500, 500);
    gtk_window_present (GTK_WINDOW (NotSoSpammyWindow));

    //Initialization of gridParent
    gridParent = gtk_grid_new ();
    gtk_window_set_child(GTK_WINDOW(NotSoSpammyWindow), gridParent);
    gtk_widget_set_halign(gridParent, GTK_ALIGN_CENTER);


    //Initialization of gridUserIDToken
    gridUserIDToken = gtk_grid_new ();
    gtk_grid_attach(GTK_GRID(gridParent), gridUserIDToken, 0, 0, 10, 1);
    gtk_grid_set_column_spacing(GTK_GRID(gridUserIDToken), 170);

    //Margins & Paddings for gridUserIDToken
        gtk_widget_set_margin_top(gridUserIDToken, 20);



    //Implementation of gmail shown as UserID

    char labelUserID[50];
    //Using sprintf to format the string to display in userID
    snprintf(labelUserID,sizeof(labelUserID),"UserID: %s",gmail);
    displayUserID = gtk_frame_new(labelUserID);
    gtk_grid_attach(GTK_GRID(gridUserIDToken), displayUserID, 0, 0, 3, 1);

    //Margins & Paddings for UserID/Gmail
        gtk_widget_set_margin_start (gridUserIDToken, 10);

    //Implementation of Token Count
    char labelTokenCount[50];
    snprintf(labelTokenCount, sizeof(labelTokenCount),"🪙%d",tokenCount);
    displayTokenCount = gtk_frame_new(labelTokenCount);
    gtk_grid_attach(GTK_GRID(gridUserIDToken), displayTokenCount, 3, 0, 1, 1);

    //Implementation of Recipient Email

    //Implementatio of Recipient Email Frame
    recipientMailFrame = gtk_frame_new(NULL);
    gtk_grid_attach(GTK_GRID(gridParent), recipientMailFrame, 1, 1,8 , 6);

    //Implementation of Recipient Email Entry
    entryRecipientMail = gtk_entry_new();
    gtk_frame_set_child(GTK_FRAME(recipientMailFrame),entryRecipientMail);
    gtk_entry_set_placeholder_text(GTK_ENTRY(entryRecipientMail),"Enter Recipient Email");
    gtk_grid_attach(GTK_GRID(gridUserIDToken), entryRecipientMail, 0, 1, 1, 1);
    //To instantly grab focus/ receive the keyboard input
    gtk_widget_grab_focus(entryRecipientMail);


}

int main(int argc, char **argv) {
    GtkApplication *app;
    int status;

    app= gtk_application_new ("org.gtk.example", G_APPLICATION_DEFAULT_FLAGS);
    g_signal_connect (app, "activate", G_CALLBACK (activate), NULL);
    status = g_application_run (G_APPLICATION (app), argc, argv);
    g_object_unref (app);

    return status;
}