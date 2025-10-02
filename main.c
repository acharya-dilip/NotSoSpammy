#include <stdio.h>
#include<gtk/gtk.h>


extern char gmail[50]="acharyamission6@gmail.com";
extern int tokenCount = 69;

//Size variables for userID and recipient mail
extern int varWidth=0;
extern int varHeight=0;


static void activate (GtkApplication *app,gpointer user_data){
    //Declaring Necessary Items for the GUI
    GtkWidget *NotSoSpammyWindow;
    GtkWidget *gridUserIDToken; //The Grid used to organize the buttons and other GUI elements
    GtkWidget *gridParent; //The Parent grid where other sub grids will rest
    GtkWidget *lockedEntryUserID; //Label where user ID will be displayed
    GtkWidget *frameTokenCount;
    GtkWidget *labelTokenCount;
    GtkWidget *entryRecipientMail;//WIdget for Entry
    GtkWidget *frameRecipientMail; //Widget for frame
    GtkWidget *lockedEntrySubjectMail;
    GtkWidget *lockedEntryMail;
    GtkWidget *buttonSendMail;



    //Main Window Init and Customization
    NotSoSpammyWindow = gtk_application_window_new (app);
    gtk_window_set_title (GTK_WINDOW (NotSoSpammyWindow), "NotSoSpammy");
    gtk_window_set_default_size (GTK_WINDOW (NotSoSpammyWindow), 400, 400);
    //gtk_window_present (GTK_WINDOW (NotSoSpammyWindow));



    //Initialization of gridParent
    gridParent = gtk_grid_new ();
    gtk_window_set_child(GTK_WINDOW(NotSoSpammyWindow), gridParent);
    gtk_widget_set_halign(gridParent, GTK_ALIGN_CENTER);
    gtk_widget_set_valign(gridParent, GTK_ALIGN_CENTER);



    //Initialization of gridUserIDToken
    gridUserIDToken = gtk_grid_new ();
    gtk_grid_attach(GTK_GRID(gridParent), gridUserIDToken, 0, 0, 2, 1);
    gtk_grid_set_column_spacing(GTK_GRID(gridUserIDToken), 170);
    //Margins & Paddings for gridUserIDToken
        gtk_widget_set_margin_top(gridUserIDToken, 20);
        gtk_widget_set_margin_start(gridUserIDToken, 15);
        gtk_widget_set_margin_end(gridUserIDToken, 15);
        gtk_widget_set_margin_bottom(gridUserIDToken, 10);


    //Implementation of gmail shown as UserID
    lockedEntryUserID = gtk_entry_new();
    char valueUserID[50];
    //Using sprintf to format the string to display in userID
    snprintf(valueUserID,sizeof(valueUserID),"UserID: %s",gmail);
    //Inserting text
    gtk_editable_set_text(GTK_EDITABLE(lockedEntryUserID), valueUserID);
    gtk_grid_attach(GTK_GRID(gridUserIDToken), lockedEntryUserID, 0, 0, 3, 1);
    gtk_entry_set_has_frame (GTK_ENTRY(lockedEntryUserID), TRUE);
    //Locking the entry
    gtk_editable_set_editable(GTK_EDITABLE(lockedEntryUserID), FALSE);
    //MARGINS & PADDINGS
    gtk_widget_set_size_request(lockedEntryUserID, 350, 20);



    //Implementation of Token Count
    char TokenCount[50];
    snprintf(TokenCount, sizeof(TokenCount),"🪙%d",tokenCount);
    labelTokenCount = gtk_label_new (TokenCount);
    frameTokenCount = gtk_frame_new(NULL);
    gtk_frame_set_child(GTK_FRAME(frameTokenCount),labelTokenCount);
    //gtk_frame_set_label_widget(GTK_FRAME(frameTokenCount), labelTokenCount);
    gtk_grid_attach(GTK_GRID(gridUserIDToken), frameTokenCount, 3, 0, 1, 1);
    //MARGINS & Paddings
    gtk_widget_set_size_request(frameTokenCount, 50, 30);
    gtk_widget_set_valign(frameTokenCount,GTK_ALIGN_CENTER);



    //Implementation of Recipient Email
    //Implementation of Recipient Email Frame
    frameRecipientMail = gtk_frame_new(NULL);
    gtk_grid_attach(GTK_GRID(gridParent), frameRecipientMail, 0, 1,5 , 1);
    //Implementation of Recipient Email Entry
    entryRecipientMail = gtk_entry_new();
    gtk_frame_set_child(GTK_FRAME(frameRecipientMail),entryRecipientMail);
    gtk_entry_set_placeholder_text(GTK_ENTRY(entryRecipientMail),"Enter Recipient Email");
    gtk_grid_attach(GTK_GRID(gridUserIDToken), entryRecipientMail, 0, 0, 0, 0);
    //To instantly grab focus/ receive the keyboard input
    gtk_widget_grab_focus(entryRecipientMail);
    gtk_widget_set_size_request(frameRecipientMail, 350, 20);
    //Margins & Paddings
        //gtk_widget_set_margin_top(recipientMailFrame, 5);
        gtk_widget_set_margin_start(frameRecipientMail, 15);
        gtk_widget_set_halign(frameRecipientMail, GTK_ALIGN_START);


    //Initialization of entrySubjectMail where the subject of the mail is displayed
    lockedEntrySubjectMail = gtk_entry_new();
    //Locking the entry
    gtk_editable_set_editable(GTK_EDITABLE(lockedEntrySubjectMail),FALSE);
    gtk_grid_attach(GTK_GRID(gridParent),lockedEntrySubjectMail,0,2,1,1);
    //Margins & Padding
        gtk_widget_set_margin_start(lockedEntrySubjectMail, 15);
        gtk_widget_set_margin_top(lockedEntrySubjectMail,15);
        gtk_widget_set_margin_end(lockedEntrySubjectMail,15);



    //Initialization of the lockedEntryMail which is the field where the mail that is to be sent will be displayed
    lockedEntryMail = gtk_entry_new();
    //Locking the entry
    gtk_editable_set_editable(GTK_EDITABLE(lockedEntryMail),FALSE);
    gtk_grid_attach(GTK_GRID(gridParent),lockedEntryMail, 0, 3, 1, 1);
    //MARGINS & PADDING
        gtk_widget_set_size_request(lockedEntryMail, 570, 350);
        gtk_widget_set_margin_start(lockedEntryMail, 15);
        gtk_widget_set_margin_top(lockedEntryMail,15);
        gtk_widget_set_margin_bottom(lockedEntryMail, 15);
        gtk_widget_set_margin_end(lockedEntryMail,15);
         gtk_widget_set_halign(lockedEntryMail, GTK_ALIGN_CENTER);



    //Implementation of the Send Mail Button
    buttonSendMail = gtk_button_new_with_label("Send");
    gtk_grid_attach(GTK_GRID(gridParent),buttonSendMail,0,4,1,1);
    //MARGINS & PADDING
        gtk_widget_set_margin_start(buttonSendMail,15);
        gtk_widget_set_margin_end(buttonSendMail,15);
        gtk_widget_set_margin_bottom(buttonSendMail,15);



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