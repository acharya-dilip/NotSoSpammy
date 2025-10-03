#include <stdio.h>
#include<gtk/gtk.h>

void checkLogin(GtkApplication *app,gpointer user_data);
static void mainWindow();
void editMail(GtkApplication *app, gpointer user_data);
void closeLoginWindow(GtkApplication *app, gpointer user_data);

extern char gmail[50]="admin";
extern int tokenCount = 69;

//Size variables for userID and recipient mail
extern int varWidth=0;
extern int varHeight=0;


//Declaring Necessary Items for the MAIN PROGRAM GUI
GtkWidget *NotSoSpammyWindow;
GtkWidget *gridUserIDToken; //The Grid used to organize the buttons and other GUI elements
GtkWidget *gridParent; //The Parent grid where other sub grids will rest
GtkWidget *lockedEntryUserID; //Label where user ID will be displayed
GtkWidget *frameTokenCount;
GtkWidget *labelTokenCount;
GtkWidget *entryRecipientMail;//WIdget for Entry
GtkWidget *gridRecipientMailEditButton; //Widget for frame
GtkWidget *lockedEntrySubjectMail;
GtkWidget *lockedEntryMail;
GtkWidget *buttonSendMail;
GtkWidget *buttonEditMail;
//VARIABLES FOR LOGIN SCREEN
GtkWidget *windowLoginScreen;
GtkWidget *gridParentLogin;
GtkWidget *entryGmail;
GtkWidget *labelGmail;
GtkWidget *entryPassword;
GtkWidget *labelPassword;
GtkWidget *buttonLogin;

static void mainWindow() {



    //Main Window Init and Customization
    NotSoSpammyWindow = gtk_window_new ();
    gtk_window_set_title (GTK_WINDOW (NotSoSpammyWindow), "NotSoSpammy");
    gtk_window_set_default_size (GTK_WINDOW (NotSoSpammyWindow), 400, 400);
    gtk_window_present (GTK_WINDOW (NotSoSpammyWindow));
    g_signal_connect(NotSoSpammyWindow, "close-request",G_CALLBACK(closeLoginWindow),NULL);



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
    gridRecipientMailEditButton = gtk_grid_new();
    gtk_grid_attach(GTK_GRID(gridParent), gridRecipientMailEditButton, 0, 1, 2, 1);

    entryRecipientMail = gtk_entry_new();
    gtk_entry_set_placeholder_text(GTK_ENTRY(entryRecipientMail),"Enter Recipient Mail");
    gtk_grid_attach(GTK_GRID(gridRecipientMailEditButton), entryRecipientMail, 0, 0, 1, 1);
    gtk_widget_set_size_request(entryRecipientMail, 350, 20);
    gtk_widget_set_halign(entryRecipientMail, GTK_ALIGN_START);
    gtk_widget_set_margin_start(entryRecipientMail, 15);
    //Initialisation of buttonEditMail
    buttonEditMail = gtk_button_new_with_label("📝");
    gtk_grid_attach(GTK_GRID(gridRecipientMailEditButton),buttonEditMail,1,0,1,1);
    //Margin & Paddings
    gtk_widget_set_margin_end(buttonEditMail, 15);



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



static void activate (GtkApplication *app,gpointer user_data){


    //LOGIN SCREEN FOR THE MAIN APP
    windowLoginScreen = gtk_application_window_new(app);
    gtk_window_set_title(GTK_WINDOW(windowLoginScreen),"LOGIN");
    gtk_window_set_default_size(GTK_WINDOW(windowLoginScreen),350,150);
    gtk_window_present(GTK_WINDOW(windowLoginScreen));

    //Implementation of gridParentLogin
    gridParentLogin = gtk_grid_new();
    gtk_window_set_child(GTK_WINDOW(windowLoginScreen),gridParentLogin);

    //Margins & Padding
    //gtk_widget_set_halign(gridParentLogin,GTK_ALIGN_CENTER);
    //gtk_widget_set_valign(gridParentLogin,GTK_ALIGN_CENTER);
        gtk_widget_set_size_request(gridParentLogin, 350, 100);

    //Implementation of Mail entering field
    //LABEL FOR GMAIL
    labelGmail = gtk_label_new("User ID: ");
    gtk_grid_attach(GTK_GRID(gridParentLogin),labelGmail, 0, 0, 1, 1);
    //Margins & Padding
        gtk_widget_set_halign(labelGmail,GTK_ALIGN_END);
        gtk_widget_set_margin_start(labelGmail,10);

    //ENTRY FOR GMAIL
    entryGmail = gtk_entry_new();
    gtk_grid_attach(GTK_GRID(gridParentLogin),entryGmail, 4, 0, 1, 1);
    //Margins & Padding
        gtk_widget_set_hexpand(entryGmail, TRUE);
        gtk_widget_set_margin_start(entryGmail,5);
        gtk_widget_set_margin_end(entryGmail,15);
        gtk_widget_set_size_request(entryGmail, 100, -1);

    //Implementation of Password entry
    labelPassword = gtk_label_new("Password: ");
    gtk_grid_attach(GTK_GRID(gridParentLogin),labelPassword, 0, 1, 1, 1);
    //Margins & Padding
        gtk_widget_set_halign(labelPassword,GTK_ALIGN_END);
        gtk_widget_set_margin_start(labelPassword,10);
    entryPassword = gtk_entry_new();
    //MAKING IT SO THAT WHEN YOU TYPE PASSWORD IT WON't BE VISIBLE
    gtk_entry_set_visibility(GTK_ENTRY(entryPassword),FALSE);
    gtk_grid_attach(GTK_GRID(gridParentLogin),entryPassword, 4, 1, 6, 1);
    //Margins & PAdding
        gtk_widget_set_margin_start(entryPassword,5);
        gtk_widget_set_margin_end(entryPassword,15);

    //Implementation of buttonLogin
    buttonLogin = gtk_button_new_with_label("Login");
    gtk_grid_attach(GTK_GRID(gridParentLogin),buttonLogin, 2, 2, 6, 1);
    g_signal_connect(buttonLogin, "clicked",G_CALLBACK(checkLogin),NULL);

    //Margins & Padding
    //gtk_widget_set_margin_start(buttonLogin,15);
    gtk_widget_set_margin_end(buttonLogin,15);



}

//function to check login
void checkLogin(GtkApplication *app,gpointer user_data) {
    if (strcmp(gtk_editable_get_text(GTK_EDITABLE(entryGmail)),gmail)==0 &&
        strcmp(gtk_editable_get_text(GTK_EDITABLE(entryPassword)),"admin") == 0) {
        gtk_widget_set_visible(windowLoginScreen,FALSE);
        mainWindow();
    }
}
//FUNCTION TO CHECK IF MAIN PROGRAM IS DELETED TO CLOSE THE PROGRAM
void closeLoginWindow(GtkApplication *app, gpointer user_data) {
    gtk_window_destroy(GTK_WINDOW(windowLoginScreen));
}
//Widgets needed for the mail editing window
    GtkWidget *windowEditMail;
    GtkWidget *gridParentEdit;
    GtkWidget *entryEditMailSubject;
    GtkWidget *entryEditMailBody;
    GtkWidget *buttonConfirmEdit;
void editMail(GtkApplication *app, gpointer user_data){
    windowEditMail = gtk_entry_new();
    gtk_window_set_title(GTK_WINDOW(windowEditMail),"Edit Mail");
    gtk_window_set_default_size(GTK_WINDOW(windowEditMail),400,400);
    gtk_window_present(GTK_WINDOW(windowEditMail));
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
