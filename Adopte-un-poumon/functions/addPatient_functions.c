#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include <gtk/gtk.h>

#include <winsock.h>
#include <MYSQL/mysql.h>

#include "addPatients_header.h"
#include "zerogets.h"




void addPatientStruct(patient * p,string name,string surname, string birth, string dateInscription, string height, string weight, string bloodType, string HLA, string plasmapherese, string smoke)
{
    p->name = name;
    p->surname = surname;
    p->birth = birth;
    p->dateInscription = dateInscription;
    p->height = height;
    p->weight = weight;
    p->bloodType = bloodType;
    p->HLA = HLA;
    p->plasmapherese = plasmapherese;
    p->smoke = smoke;





}

string query(patient * p)
{

    char request[600];
    char p1[200]="INSERT INTO patients (id,name, surname, birth, dateInscription, height, weight, bloodType, HLA, plasmapherese, smoke) VALUES (''";
    char comma[2] = ",";
    char p2[2] = ")";
    char hop[2] = "'";
    strcpy(request, p1);
    strcat(request,comma);
    strcat(request,hop);
    strcat(request,p->name);
    strcat(request,hop);
    strcat(request,comma);
    strcat(request,hop);
    strcat(request,p->surname);
    strcat(request,hop);
    strcat(request,comma);
    strcat(request,hop);
    strcat(request,p->birth);
    strcat(request,hop);
    strcat(request,comma);
    strcat(request,hop);
    strcat(request,p->dateInscription);
    strcat(request,hop);
    strcat(request,comma);
    strcat(request,hop);
    strcat(request,p->height);
    strcat(request,hop);
    strcat(request,comma);
    strcat(request,hop);
    strcat(request,p->weight);
    strcat(request,hop);
    strcat(request,comma);
    strcat(request,hop);
    strcat(request,p->bloodType);
    strcat(request,hop);
    strcat(request,comma);
    strcat(request,hop);
    strcat(request,p->HLA);
    strcat(request,hop);
    strcat(request,comma);
    strcat(request,hop);
    strcat(request,p->plasmapherese);
    strcat(request,hop);
    strcat(request,comma);
    strcat(request,hop);
    strcat(request,p->smoke);
    strcat(request,hop);
    strcat(request,p2);

    return (request);
}
void add(string request)
{
    printf(request);
    MYSQL mysql;
    mysql_init(&mysql);
    mysql_options(&mysql, MYSQL_READ_DEFAULT_GROUP, "option");
    if(mysql_real_connect(&mysql, "localhost","root","", "pulmonax", 0, NULL, 0))
    {

        mysql_query(&mysql, request);
        mysql_close(&mysql);
    }
    else
    {
        printf("Erreur connexion");

    }
}
/*----------------------------------------------------------------------------------------
------------------------------------------------------------------------------------------
------------------------------------------Passage Graphique ------------------------------
------------------------------------------------------------------------------------------*/

void addPatientWindow(int argc, char ** argv,GtkWidget * mainWindow)
{
    GtkWidget * main_box = NULL;
    GtkWidget * patientAddWindow=NULL;

    /* Initialisation de GTK+ */
    gtk_init(&argc, &argv);

    /* Cr�ation de la fen�tre */
    patientAddWindow = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    g_signal_connect(G_OBJECT(patientAddWindow), "delete-event", G_CALLBACK(gtk_main_quit), NULL);

    /* Affichage et boucle �v�nementielle */
    gtk_widget_show(patientAddWindow);

    /* On definit le titre de la fen�tre */
    gtk_window_set_title(GTK_WINDOW(patientAddWindow), "Ajout d'un patient");

    /* D�finition de la position */
    gtk_window_set_position(GTK_WINDOW(patientAddWindow), GTK_WIN_POS_CENTER_ALWAYS  );

    /* D�finition d'un icone de la fen�tre */
    gtk_window_set_icon_from_file(GTK_WINDOW(patientAddWindow),"organes.jpg",NULL);

    /* On d�finit la taile de la fen�tre par d�fault */
    gtk_window_resize(GTK_WINDOW(patientAddWindow), 500,500);

    /* Maximiser la fen�tre */
    gtk_window_maximize (GTK_WINDOW(patientAddWindow));

    /* Restaurer la fenetre */
    gtk_window_unmaximize(GTK_WINDOW(patientAddWindow));

    /* Cr�ation de la GtkBox verticale */
    main_box = gtk_vbox_new(TRUE, 0);
    /* Ajout de la GtkVBox dans la fenetre */
    gtk_container_add(GTK_CONTAINER(patientAddWindow), main_box);
    formPatient(patientAddWindow, main_box);

    gtk_widget_show_all(patientAddWindow);
    gtk_main();


}

void formPatient(GtkWidget * addPatientWindow,GtkWidget * main_box)
{
    GtkWidget * pFrame;
    GtkWidget * label;
    GtkWidget * name;
    GtkWidget * surname;
    GtkWidget * birth;
    GtkWidget * dateInscription;
    GtkWidget * height;
    GtkWidget * weight;
    GtkWidget * bloodType;
    GtkWidget * HLA;
    GtkWidget * plasmapherese;
    GtkWidget * smoke;



    /* Creation du premier GtkFrame */
    pFrame = gtk_frame_new("Ajout d'un patient");
    gtk_box_pack_start(GTK_BOX(main_box), pFrame, TRUE, FALSE, 0);


    /* Creation et insertion des elements contenus dans le premier GtkFrame */

    label = gtk_label_new("Nom :");
    gtk_box_pack_start(GTK_BOX(main_box), label, FALSE, FALSE, 0);
    name = gtk_entry_new();
    gtk_box_pack_start(GTK_BOX(main_box), name, TRUE, TRUE, 0);

    label = gtk_label_new("Prenom :");
    gtk_box_pack_start(GTK_BOX(main_box), label, FALSE, FALSE, 0);
    surname = gtk_entry_new();
    gtk_box_pack_start(GTK_BOX(main_box), surname, TRUE, TRUE, 0);

    label = gtk_label_new("Date de naissance (JJ/MM/AAAA) :");
    gtk_box_pack_start(GTK_BOX(main_box), label, FALSE, FALSE, 0);
    birth = gtk_entry_new();
    gtk_box_pack_start(GTK_BOX(main_box), birth, TRUE, TRUE, 0);


    label = gtk_label_new("Date d'inscription (JJ/MM/AAAA) :");
    gtk_box_pack_start(GTK_BOX(main_box), label, FALSE, FALSE, 0);
    dateInscription = gtk_entry_new();
    gtk_box_pack_start(GTK_BOX(main_box), dateInscription, TRUE, TRUE, 0);

    label = gtk_label_new("Taille (en cm) :");
    gtk_box_pack_start(GTK_BOX(main_box), label, FALSE, FALSE, 0);
    height = gtk_entry_new();
    gtk_box_pack_start(GTK_BOX(main_box), height, TRUE, TRUE, 0);



    label = gtk_label_new("Poids (en kg) :");
    gtk_box_pack_start(GTK_BOX(main_box), label, FALSE, FALSE, 0);
    weight = gtk_entry_new();
    gtk_box_pack_start(GTK_BOX(main_box), weight, TRUE, TRUE, 0);


    label = gtk_label_new("Groupe Sanguin :");
    gtk_box_pack_start(GTK_BOX(main_box), label, FALSE, FALSE, 0);
    bloodType = gtk_entry_new_with_max_length(3);
    gtk_box_pack_start(GTK_BOX(main_box), bloodType, TRUE, TRUE, 0);


    label = gtk_label_new("HLA (Mettez des espaces pour les séparer) :");
    gtk_box_pack_start(GTK_BOX(main_box), label, FALSE, FALSE, 0);
    HLA = gtk_entry_new_with_max_length(3);
    gtk_box_pack_start(GTK_BOX(main_box), HLA, TRUE, TRUE, 0);

    label = gtk_label_new("Plasmapherese (Mettez des espaces pour les séparer :)");
    gtk_box_pack_start(GTK_BOX(main_box), label, FALSE, FALSE, 0);
    plasmapherese = gtk_entry_new_with_max_length(3);
    gtk_box_pack_start(GTK_BOX(main_box), plasmapherese, TRUE, TRUE, 0);

    label = gtk_label_new("Fumeur : (1 ou 0) :");
    gtk_box_pack_start(GTK_BOX(main_box), label, FALSE, FALSE, 0);
    smoke = gtk_entry_new_with_max_length(3);
    gtk_box_pack_start(GTK_BOX(main_box), smoke, TRUE, TRUE, 0);

    button_addPatient(addPatientWindow, main_box, name, surname, birth, dateInscription, height, weight ,bloodType, HLA, plasmapherese, smoke);

}

void button_addPatient(GtkWidget * addPatientWindow, GtkWidget * main_box, GtkWidget * name, GtkWidget * surname, GtkWidget * birth, GtkWidget * dateInscription, GtkWidget * height, GtkWidget * weight ,GtkWidget * bloodType, GtkWidget * HLA, GtkWidget * plasmapherese, GtkWidget * smoke)
{
    GtkWidget * button_co;
        /* Bouton avec un label */
    button_co = gtk_button_new_with_label(" Ajoutez le patient ! ");


    /* Connexion du signal "clicked" du bouton */

    g_object_set_data(G_OBJECT(button_co), "name", name);
    g_object_set_data(G_OBJECT(button_co), "surname", surname);
    g_object_set_data(G_OBJECT(button_co), "birth", birth);
    g_object_set_data(G_OBJECT(button_co), "dateInscription", dateInscription);
    g_object_set_data(G_OBJECT(button_co), "height", height);
    g_object_set_data(G_OBJECT(button_co), "weight", weight);
    g_object_set_data(G_OBJECT(button_co), "bloodType", bloodType);
    g_object_set_data(G_OBJECT(button_co), "HLA", HLA);
    g_object_set_data(G_OBJECT(button_co), "plasmapherese", plasmapherese);
    g_object_set_data(G_OBJECT(button_co), "smoke", smoke);


    g_signal_connect(G_OBJECT(button_co), "clicked", G_CALLBACK(validate_addPatient), (GtkWidget*) addPatientWindow);

    gtk_box_pack_start (GTK_BOX (main_box), button_co, FALSE, FALSE, 0);


}


void validate_addPatient(GtkWidget *button_co,GtkWidget * addPatientWindow,GtkWidget * main_box,int argc,char **argv)
{

    GtkEntry * name_;
    GtkEntry * surname_;
    GtkEntry * birth_;
    GtkEntry * dateInscription_;
    GtkEntry * height_;
    GtkEntry * weight_;
    GtkEntry * bloodType_;
    GtkEntry * HLA_;
    GtkEntry * plasmapherese_;
    GtkEntry * smoke_;

    const gchar * name;
    const gchar * surname;
    const gchar * birth;
    const gchar * dateInscription;
    const gchar * height;
    const gchar * weight;
    const gchar * bloodType;
    const gchar * HLA;
    const gchar * plasmapherese;
    const gchar * smoke;
    string request;


    name_ = g_object_get_data (G_OBJECT(button_co), "name");
    surname_ = g_object_get_data (G_OBJECT(button_co), "surname");
    birth_ = g_object_get_data (G_OBJECT(button_co), "birth");
    dateInscription_ = g_object_get_data (G_OBJECT(button_co), "dateInscription");
    height_ = g_object_get_data (G_OBJECT(button_co), "height");
    weight_ = g_object_get_data (G_OBJECT(button_co), "weight");
    bloodType_ = g_object_get_data (G_OBJECT(button_co), "bloodType");
    HLA_ = g_object_get_data (G_OBJECT(button_co), "HLA");
    plasmapherese_ = g_object_get_data (G_OBJECT(button_co), "plasmapherese");
    smoke_ = g_object_get_data (G_OBJECT(button_co), "smoke");

    name = gtk_entry_get_text(name_);
    surname = gtk_entry_get_text(surname_);
    birth = gtk_entry_get_text(birth_);
   dateInscription = gtk_entry_get_text(dateInscription_);
    height = gtk_entry_get_text(height_);
    weight = gtk_entry_get_text(weight_);
    bloodType = gtk_entry_get_text(bloodType_);
    HLA = gtk_entry_get_text(HLA_);
    plasmapherese = gtk_entry_get_text(plasmapherese_);
    smoke = gtk_entry_get_text(smoke_);

    patient * p;
    addPatientStruct(&p,name, surname, birth, dateInscription, height, weight, bloodType, HLA, plasmapherese, smoke);
    request = query(&p);
    add(request);

}
