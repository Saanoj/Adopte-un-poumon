
//Typedef

typedef char* string;
typedef struct config config;
typedef struct patient patient;
//Structures
struct patient
{
    string name;
    string surname;
    string birth;
    string dateInscription;
    string height;
    string weight;
    string sex;
    string bloodType;
    string HLA;
    string plasmapherese;
    string smoke;
    string cpt;
};


// Prototype

void mysql(string);
void addPatientStruct(patient *, string, string, string, string, string, string, string, string, string, string, string);
void addPatientWindow(int,char **,GtkWidget *);
void button_addPatient(GtkWidget*, GtkWidget*, GtkWidget*, GtkWidget*, GtkWidget*, GtkWidget*, GtkWidget*, GtkWidget*, GtkWidget*,GtkWidget*, GtkWidget*, GtkWidget*, GtkWidget*);
void validate_addPatient(GtkWidget *,GtkWidget *,GtkWidget *,int,char **);
void query();
