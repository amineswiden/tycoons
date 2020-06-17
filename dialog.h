#ifndef DIALOG_H
#define DIALOG_H
#include "joueur.h"
#include "discipline.h"
#include "produits.h"
#include "categories.h"
#include "staff.h"
#include "categorie.h"
#include "match.h"
#include "billet.h"
#include <QMediaPlayer>
#include <QDialog>

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = nullptr);
    ~Dialog();
    //QMediaPlayer *correct =new QMediaPlayer();
    QMediaPlayer *incorrect =new QMediaPlayer();
    private slots:
    void sendMail();
    void sendMail1();
    void sendMail2();
    void mailSent(QString);
    void initialiser_0();
    void initialiser();
    void initialiser1();
    void initialiser_p();
    void initialiser_c();
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();



    void on_pushButton_modifierj_clicked();

    void on_pushButton_supprimerj_clicked();

    void on_pushButton_recherchej_clicked();

    void on_pushButton_triej_clicked();

    void on_pushButton_ajouterd_clicked();

    void on_pushButton_modifierd_clicked();

    void on_pushButton_supprimerd_clicked();

    void on_pushButton_recherched_clicked();

    void on_pushButton_tried_clicked();

    void on_pushButton_9_clicked();

    void on_pushButton_ajouterj_clicked();

    void on_tablejoueur_clicked();

    void on_tablejoueur_doubleClicked();

    void on_tablediscipline_clicked();

    void on_tablediscipline_doubleClicked();

    void on_pushButton_ajoutp_clicked();

    void on_pushButton_modifp_clicked();

    void on_pushButton_suppp_clicked();

    void on_pushButton_rechp_clicked();

    void on_pushButton_tri_clicked();

    void on_pushButton_pdfp_clicked();

    void on_pushButton_ajoutcat_clicked();

    void on_pushButton_modifCat_clicked();

    void on_pushButton_suppCat_clicked();

    void on_pushButton_rechCat_clicked();

    void on_pushButton_triCat_clicked();

    void on_pushButton_3_clicked();

    void on_tabproduits_clicked();

    void on_tabproduits_doubleClicked();

    void on_tabCat_clicked();

    void on_tabCat_doubleClicked();

    void on_pushButton_menu2_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_ajoutab_clicked();

    void on_pushButton_modifierab_clicked();

    void on_pushButton_supprimerab_clicked();

    void on_pushButton_ajoutera_clicked();

    void on_pushButton_modifiera_clicked();

    void on_pushButton_supprimera_clicked();



    void on_pushButton_12_clicked();

    void on_tableView_clicked();

    void on_tableView_2_clicked();

    //void on_pushButton_6_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_8_clicked();

    void on_pushButton_14_clicked();

    void on_pushButton_15_clicked();

    void on_pushButton_18_clicked();

    void on_pushButton_17_clicked();

    void on_tablestaff_clicked();

    void on_tablestaff_doubleClicked();

    void on_pushButton_ajouterd_2_clicked();

    void on_pushButton_20_clicked();

    void on_pushButton_supprimer2_clicked();

    void on_pushButton_21_clicked();

    void on_pushButton_22_clicked();

    void on_tablecategorie_clicked();

    void on_tablecategorie_doubleClicked();

    void on_pushButton_24_clicked();

    void on_pushButton_25_clicked();

    void on_pb_ajouter_billet_clicked();

    void on_pb_supprimer_billet_clicked();

    void on_pushButton_trieBillet_clicked();

    void on_pushButton_supBillet_clicked();

    void on_pb_ajouter_clicked();

    void on_pb_supprimer_clicked();

    void on_pushButton_rech_match_clicked();

    void on_pushButton_tri_match_clicked();

    void on_pushButton_26_clicked();

    /*------------------controle de saisieProduits-------------------------------------------------------------------------------------------------- */
        void on_lineEdit_code_textChanged(const QString &arg1);
        void on_lineEdit_prix_textChanged(const QString &arg1);
        void on_lineEdit_qte_textChanged(const QString &arg1);
        void on_lineEdit_des_textEdited (const QString &arg1);
        void on_lineEdit_col_textEdited (const QString &arg1);
        void on_lineEdit_idp_textChanged(const QString &arg1);
    /*------------------categories-------------------------------------------------------------------------------------------------------------------*/
        void on_lineEdit_idc_textChanged(const QString &arg1);
        void on_lineEdit_nonc_textEdited(const QString &arg1);
    /*-----------------abonnements------------------------------------------------------------------------------------------------*/
        void on_lineEdit_ida_textChanged(const QString &arg1) ;
        void on_lineEdit_prixa_textChanged(const QString &arg1);
        void on_lineEdit_typea_textEdited(const QString &arg1) ;
    /*---------------abonnes--------------------------------------------------------------------------------------------------------*/
        void on_lineEdit_cina_textChanged(const QString &arg1) ;
        void on_lineEdit_noma_textEdited(const QString &arg1)  ;
        void on_lineEdit_prenoma_textEdited(const QString &arg1) ;
        void on_lineEdit_numa_textChanged(const QString &arg1) ;
        void on_lineEdit_adressea_textEdited(const QString &arg1) ;
    /*---------------staff--------------------------------------------------------------------------------------------------------*/
         void on_lineEdit_cin_2_textChanged(const QString &arg1) ;
         void on_lineEdit_nom_2_textEdited(const QString &arg1) ;
         void on_lineEdit_prenom_2_textEdited(const QString &arg1) ;
         void on_lineEdit_poste_2_textEdited(const QString &arg1) ;
         void on_lineEdit_age_2_textEdited(const QString &arg1) ;
         void on_lineEdit_tel_textEdited(const QString &arg1) ;
    /*----------------categorie-------------------------------------------------------------------------------------------*/
       void on_lineEdit_id_2_textChanged(const QString &arg1) ;
       void on_lineEdit_type_2_textChanged(const QString &arg1) ;
       void on_lineEdit_nb_2_textChanged(const QString &arg1) ;
       void on_lineEdit_sal_textChanged(const QString &arg1) ;
    /*----------------joueuur-------------------------------------------------------------------*/
       void on_lineEdit_cin_textChanged(const QString &arg1) ;
       void on_lineEdit_nom_textEdited(const QString &arg1) ;
       void on_lineEdit_prenom_textEdited(const QString &arg1) ;
       void on_lineEdit_num_maillot_textChanged(const QString &arg1) ;
       void on_lineEdit_poste_textEdited(const QString &arg1) ;
       void on_lineEdit_salaire_textEdited(const QString &arg1) ;
       void on_lineEdit_cap_att_textEdited(const QString &arg1) ;
       void on_lineEdit_cap_def_textEdited(const QString &arg1) ;
     /*-----------discipline--------------------------------------------------------------------------*/
       void on_lineEdit_id_textChanged(const QString &arg1) ;
       void on_lineEdit_type_textEdited(const QString &arg1) ;
       void on_lineEdit_nb_textEdited(const QString &arg1) ;
     //-------------billetterie----------------------------------------------------------------------------------------------
       void on_lineEdit_id_3_textChanged(const QString &arg1) ;
       void on_lineEdit_nbticket_textEdited(const QString &arg1) ;
       void on_lineEdit_prix_2_nb_textEdited(const QString &arg1) ;
     //------match--------------------------------------------------------------------------------------------------------
       void on_lineEdit_ctqui_textChanged(const QString &arg1) ;
       void on_lineEdit_placement_textEdited(const QString &arg1) ;
       void on_lineEdit_type_3_textEdited(const QString &arg1) ;


       void on_pushButton_modifanis1_clicked();

       void on_pushButton_modifanis1_2_clicked();

       void on_pb_ajouter_menuanis_clicked();

       void on_pushButton_match_clicked();

       void on_tabmatch_clicked(const QModelIndex &index);

       void on_tabbillet_clicked(const QModelIndex &index);

       void on_pb_ajouter_image_clicked();

       void on_pb_modifier_image_clicked();

private:
    Ui::Dialog *ui;
    joueur tmpjoueur;
    discipline tmpdiscipline;
    Produits tmproduits;
    Categories tmpcat;
    staff tmpstaff;
    categorie tmpcategorie;
    match tmpmatch;
    billet tmpbillet;
};

#endif // DIALOG_H
