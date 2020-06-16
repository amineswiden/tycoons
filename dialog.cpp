#include "dialog.h"
#include "ui_dialog.h"
#include "produits.h"
#include "categories.h"
#include <QPixmap>
#include "discipline.h"
#include "joueur.h"
#include <QMessageBox>
#include <QRegExpValidator>
#include "categorie.h"
#include "staff.h"
#include "abonnements.h"
#include "abonnes.h"
#include "smtp.h"
#include "match.h"
#include "billet.h"
#include <QPainter>
#include <QPrinter>
#define CARACTERES_ETRANGERS "~{}[]()|-`'^ç@_]\"°01234567890+=£$*µ/§!?,.&#;><"
#define CARACTERES_ALPHA "azertyuiopqsdfghjklmùwxcvbnAZERTYUIOPQSDFGHJKLMWXCVBN"
int couner = 15;
bool on_off = true;
Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
    abonnements o;
    ui->tableView->setModel(o.afficher());

    abonnes a;
    ui->tableView_2->setModel(a.afficher());
     ui->tabbillet->setModel(tmpbillet.afficher());
     ui->tabmatch->setModel(tmpmatch.afficher());
    QVector<QColor> colors(2);
    QVector<double> values(2);
    colors[0] = Qt::red, colors[1]= Qt::blue;
    values[0] =tmproduits.critere1() , values[1] =tmproduits.critere2();
    ui->widget2->setData(values,colors);
    QVector <QColor> color(2);
    QVector <double> value(2);
    color[0]= Qt::green , color[1]= Qt::black;
    value[0]=tmpjoueur.total_att() ,value[1]=tmpjoueur.total_def();
    ui->widget->setData(value,color);

    QVector <QColor> color1(2);
    QVector <double> value1(2);
    color1[0]= Qt::green , color1[1]= Qt::black ;
            //color[2]= Qt::red , color[3]= Qt::blue;
    value1[0]=tmpcategorie.crit1() , value1[1]=tmpcategorie.crit2() ;
    //value[2]=tmpcategorie.crit3() , value[3]=tmpcategorie.crit4() ;
    ui->widget_23->setData(value1,color1);
    QVector <QColor> color3(2);
       QVector <double> value3(2);
       color3[0]= Qt::green , color3[1]= Qt::black;
       value3[0]=o.stprix() ,value3[1]=o.pprix();
       ui->widget_3->setData(value3,color3);

       QVector <QColor> color4(2);
          QVector <double> value4(2);
          color4[0]= Qt::green , color4[1]= Qt::black;
          value4[0]=tmpmatch.get_gagne() ,value4[1]=tmpmatch.get_perdu();
          ui->widget_anis->setData(value4,color4);

    QRegExp rx("[A-Za-z]+");
    QValidator *validator = new QRegExpValidator(rx, this);
    ui->lineEdit_nom->setValidator( validator );
    ui->lineEdit_prenom->setValidator( validator );
    ui->lineEdit_poste->setValidator( validator );
    ui->lineEdit_type->setValidator( validator );
    ui->lineEdit_id->setValidator( new QIntValidator(0, 99999999, this) );
    ui->lineEdit_id2->setValidator( new QIntValidator(0, 99999999, this) );
    ui->lineEdit_nb->setValidator( new QIntValidator(0, 99999999, this) );
    ui->lineEdit_cin->setValidator( new QIntValidator(0, 99999999, this) );
    ui->lineEdit->setValidator( new QIntValidator(0, 99999999, this) );
    ui->lineEdit_salaire->setValidator( new QIntValidator(0, 99999999, this) );
    ui->lineEdit_num_maillot->setValidator( new QIntValidator(0, 99999999, this) );
    ui->lineEdit_age->setValidator( new QIntValidator(0, 99999999, this) );
    ui->lineEdit_cap_att->setValidator( new QIntValidator(0, 99999999, this) );
    ui->lineEdit_cap_def->setValidator( new QIntValidator(0, 99999999, this) );
    ui->tablejoueur->setModel(tmpjoueur.afficher());
    ui->tablediscipline->setModel(tmpdiscipline.afficher());
    connect(ui->pushButton_13, SIGNAL(clicked()),this, SLOT(sendMail()));


    ui->lineEdit_nom_2->setValidator( validator );
    ui->lineEdit_prenom_2->setValidator( validator );
    ui->lineEdit_poste_2->setValidator( validator );
    ui->lineEdit_type_2->setValidator( validator );
    ui->lineEdit_id_2->setValidator( new QIntValidator(0, 99999999, this) );
    ui->lineEdit_id2_2->setValidator( new QIntValidator(0, 99999999, this) );
    ui->lineEdit_nb_2->setValidator( new QIntValidator(0, 99999999, this) );
    ui->lineEdit_cin_2->setValidator( new QIntValidator(0, 99999999, this) );
    ui->lineEdit_cins->setValidator( new QIntValidator(0, 99999999, this) );
    ui->lineEdit_age_2->setValidator( new QIntValidator(0, 99999999, this) );
    ui->lineEdit_tel->setValidator( new QIntValidator(0, 99999999, this) );
    ui->tablestaff->setModel(tmpstaff.afficher());
    ui->tablecategorie->setModel(tmpcategorie.afficher());
    connect(ui->pushButton_23, SIGNAL(clicked()),this, SLOT(sendMail2()));


    //ui->lineEdit_code->setValidator( new QIntValidator(0, 99999999, this) );
    ui->lineEdit_prix->setValidator( new QIntValidator(0, 99999999, this) );
    ui->lineEdit_qte->setValidator( new QIntValidator(0, 99999999, this) );
    ui->lineEdit_idp->setValidator( new QIntValidator(0, 99999999, this) );

    ui->lineEdit_idc->setValidator( new QIntValidator(0, 99999999, this) );

    QRegExp rx1("[A-Za-z]+");
        QValidator *validator1 = new QRegExpValidator(rx1, this);
        ui->lineEdit_des->setValidator( validator1 );
        ui->lineEdit_pho->setValidator( validator1 );
        ui->lineEdit_col->setValidator( validator1 );
        ui->lineEdit_nom->setValidator( validator1 );

    ui->tabproduits->setModel(tmproduits.afficher());//refresh
    ui->tabCat->setModel(tmpcat.afficher());//refresh
       //ui->lineEdit_code->setValidator( new QIntValidator(0, 99999999, this) );
       // ui->lineEdit_cin->setMaxLength(8);

//ui->label_11->setPixmap(pix.scaled(100,100,Qt::KeepAspectRatio));

/*ui->statusbar->addPermanentWidget(ui->label_8,1);
ui->statusbar->addPermanentWidget(ui->progressBar,3);*/

    correct->setMedia(QUrl("")); //ajouter l'url du son
    incorrect->setMedia(QUrl("")); //ajouter l'url du son
ui->tabmatch->setModel(tmpmatch.afficher());
ui->tabbillet->setModel(tmpbillet.afficher());//refresh
  connect(ui->pushButton_envoyera, SIGNAL(clicked()),this, SLOT(sendMail1()));


}

Dialog::~Dialog()
{
    delete ui;
}
void ::Dialog::initialiser_p()
{
    ui->lineEdit_code->setText("");
    ui->lineEdit_prix->setText("");
    ui->lineEdit_qte->setText("");
    ui->lineEdit_des->setText("");
    ui->lineEdit_pho->setText("");
    ui->lineEdit_col->setText("");
    ui->lineEdit_idp->setText("");
}
void ::Dialog::initialiser_c()
{
    ui->lineEdit_idc->setText("");
    ui->lineEdit_nom->setText("");
}

void Dialog::sendMail()
{
    Smtp* smtp = new Smtp(ui->lineEdit_sender->text(), ui->lineEdit_pass->text(), ui->lineEdit_smtp->text(), ui->lineEdit_465->text().toInt());

      connect(smtp, SIGNAL(status(QString)), this, SLOT(mailSent(QString)));


    smtp->sendMail(ui->lineEdit_sender->text(), ui->lineEdit_recepiant->text() , ui->lineEdit_subject->text(),ui->lineEdit_text->text());

    initialiser_0();

}

void Dialog::sendMail1()
{ Smtp* smtp = new Smtp(ui->lineEdit_14->text(), ui->lineEdit_15->text(), ui->lineEdit_12->text(), ui->lineEdit_13->text().toInt());
    connect(smtp, SIGNAL(status(QString)), this, SLOT(mailSent(QString)));


    smtp->sendMail(ui->lineEdit_14->text(), ui->lineEdit_19->text() , ui->lineEdit_17->text(),ui->lineEdit_18->text());

}

void Dialog::sendMail2()
{
    Smtp* smtp = new Smtp(ui->lineEdit_sender_2->text(), ui->lineEdit_pass_2->text(), ui->lineEdit_smtp_2->text(), ui->lineEdit_466->text().toInt());

      connect(smtp, SIGNAL(status(QString)), this, SLOT(mailSent(QString)));


    smtp->sendMail(ui->lineEdit_sender_2->text(), ui->lineEdit_recepiant_2->text() , ui->lineEdit_subject_2->text(),ui->lineEdit_text_2->text());

    initialiser_0();
}
void Dialog::mailSent(QString status)
{
}

void Dialog::initialiser_0()
{      ui->lineEdit_sender->setText("");
       ui->lineEdit_pass->setText(""); ui->lineEdit_smtp->setText(""); ui->lineEdit_465->setText("");
     ui->lineEdit_recepiant->setText(""); ui->lineEdit_subject->setText("");ui->lineEdit_text->setText("");
}
void Dialog::initialiser()
{
       ui->lineEdit_cin->setText("");
       ui->lineEdit_salaire->setText("");
       ui->lineEdit_num_maillot->setText("");
       ui->lineEdit_nom->setText("");
       ui->lineEdit_prenom->setText("");
       ui->lineEdit_poste->setText("");
       ui->lineEdit_age->setText("");
       ui->lineEdit_cap_att->setText("");
       ui->lineEdit_cap_def->setText("");
}
void Dialog::initialiser1()
{
       ui->lineEdit_id->setText("");
       ui->lineEdit_type->setText("");
       ui->lineEdit_nb->setText("");

}

void Dialog::on_pushButton_clicked()
{  on_off = false;
    ui->stackedWidget->setCurrentIndex(1);
}

void Dialog::on_pushButton_2_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}




void Dialog::on_pushButton_ajouterj_clicked()
{
    int cin =ui->lineEdit_cin->text().toInt();
        float salaire =ui->lineEdit_salaire->text().toFloat();
        int numero_maillot=ui->lineEdit_num_maillot->text().toInt();
        QString nom=ui->lineEdit_nom->text();
        QString prenom=ui->lineEdit_prenom->text();
        QString poste=ui->lineEdit_poste->text();
        int age=ui->lineEdit_age->text().toInt();
          int cap_att=ui->lineEdit_cap_att->text().toInt();
            int cap_def=ui->lineEdit_cap_def->text().toInt();
        joueur J (cin,nom,prenom,numero_maillot,poste,salaire,age,cap_att,cap_def);
        bool test= J.ajouter();
        initialiser();
  if(test)
{

      ui->tablejoueur->setModel(tmpjoueur.afficher());//refresh
QMessageBox::information(nullptr, QObject::tr("Ajouter un joueur"),
                  QObject::tr("joueur ajouté.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);



}
  else
      QMessageBox::critical(nullptr, QObject::tr("Ajouter un joueur"),
                  QObject::tr("Erreur !.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);
}



void Dialog::on_pushButton_modifierj_clicked()
{
    int cin =ui->lineEdit_cin->text().toInt();
    float salaire =ui->lineEdit_salaire->text().toFloat();
    int numero_maillot=ui->lineEdit_num_maillot->text().toInt();
    QString nom=ui->lineEdit_nom->text();
    QString prenom=ui->lineEdit_prenom->text();
    QString poste=ui->lineEdit_poste->text();
    int age=ui->lineEdit_age->text().toInt();
      int cap_att=ui->lineEdit_cap_att->text().toInt();
        int cap_def=ui->lineEdit_cap_def->text().toInt();
    joueur J (cin,nom,prenom,numero_maillot,poste,salaire,age,cap_att,cap_def);
    bool test= J.modifier();
    initialiser();
  if(test)
{

      ui->tablejoueur->setModel(tmpjoueur.afficher());//refresh
QMessageBox::information(nullptr, QObject::tr("modifier un joueur"),
                  QObject::tr("joueur modifié.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);

}
  else
      QMessageBox::critical(nullptr, QObject::tr("modifier un joueur"),
                  QObject::tr("Erreur !.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);

}

void Dialog::on_pushButton_supprimerj_clicked()
{
    int cin = ui->lineEdit->text().toInt();
    bool test=tmpjoueur.supprimer(cin);
    ui->lineEdit->setText("");
    if(test)
    {ui->tablejoueur->setModel(tmpjoueur.afficher());//refresh
        QMessageBox::information(nullptr, QObject::tr("Supprimer un joueur"),
                    QObject::tr("joueur supprimé.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

    }
    else
        QMessageBox::critical(nullptr, QObject::tr("Supprimer un joueur"),
                    QObject::tr("Erreur !.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

}

void Dialog::on_pushButton_recherchej_clicked()
{
    QString nom = ui->lineEdit_2->text();
             ui->tablejoueur->setModel(tmpjoueur.rechercher(nom));
}

void Dialog::on_pushButton_triej_clicked()
{
  ui->tablejoueur->setModel(tmpjoueur.trier());
}

void Dialog::on_pushButton_ajouterd_clicked()
{
    int id =ui->lineEdit_id->text().toInt();
     int nb_titre=ui->lineEdit_nb->text().toInt();
     QString type=ui->lineEdit_type->text();

     discipline d (id,type,nb_titre);
     bool test= d.ajouter();
     initialiser1();
if(test)
{

   ui->tablediscipline->setModel(tmpdiscipline.afficher());//refresh
QMessageBox::information(nullptr, QObject::tr("Ajouter une discipline"),
               QObject::tr("discipline ajouté.\n"
                           "Click Cancel to exit."), QMessageBox::Cancel);

}
else
   QMessageBox::critical(nullptr, QObject::tr("Ajouter un discipline"),
               QObject::tr("Erreur !.\n"
                           "Click Cancel to exit."), QMessageBox::Cancel);

}

void Dialog::on_pushButton_modifierd_clicked()
{
    int cin =ui->lineEdit_cin->text().toInt();
    float salaire =ui->lineEdit_salaire->text().toFloat();
    int numero_maillot=ui->lineEdit_num_maillot->text().toInt();
    QString nom=ui->lineEdit_nom->text();
    QString prenom=ui->lineEdit_prenom->text();
    QString poste=ui->lineEdit_poste->text();
    int age=ui->lineEdit_age->text().toInt();
      int cap_att=ui->lineEdit_cap_att->text().toInt();
        int cap_def=ui->lineEdit_cap_def->text().toInt();
    joueur J (cin,nom,prenom,numero_maillot,poste,salaire,age,cap_att,cap_def);
    bool test= J.modifier();
    initialiser();
  if(test)
{

      ui->tablejoueur->setModel(tmpjoueur.afficher());//refresh
QMessageBox::information(nullptr, QObject::tr("modifier un joueur"),
                  QObject::tr("joueur modifié.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);

}
  else
      QMessageBox::critical(nullptr, QObject::tr("modifier un joueur"),
                  QObject::tr("Erreur !.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);
}

void Dialog::on_pushButton_supprimerd_clicked()
{
    int id = ui->lineEdit_id2->text().toInt();
    bool test=tmpdiscipline.supprimer(id);
      ui->lineEdit_id2->setText("");
    if(test)
    {ui->tablediscipline->setModel(tmpdiscipline.afficher());//refresh
        QMessageBox::information(nullptr, QObject::tr("Supprimer un discipline"),
                    QObject::tr("discipline supprimé.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

    }
    else
        QMessageBox::critical(nullptr, QObject::tr("Supprimer un discipline"),
                    QObject::tr("Erreur !.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
}

void Dialog::on_pushButton_recherched_clicked()
{
    QString type = ui->lineEdit_3->text();
         ui->tablediscipline->setModel(tmpdiscipline.rechercher(type));
}

void Dialog::on_pushButton_tried_clicked()
{
 ui->tablediscipline->setModel(tmpdiscipline.trier());
}

void Dialog::on_pushButton_9_clicked()
{
  ui->stackedWidget->setCurrentIndex(0);
}


void Dialog::on_tablejoueur_clicked()
{
    QSqlQueryModel * model=tmpjoueur.afficher();
       int idx = ui->tablejoueur->selectionModel()->currentIndex().row();
      ui->lineEdit_cin->setText(model->index(idx , 0).data().toString());
      ui->lineEdit_nom->setText(model->index(idx , 1).data().toString());
      ui->lineEdit_prenom->setText(model->index(idx , 2).data().toString());
      ui->lineEdit_num_maillot->setText(model->index(idx , 3).data().toString());
      ui->lineEdit_poste->setText(model->index(idx , 4).data().toString());
      ui->lineEdit_salaire->setText(model->index(idx , 5).data().toString());
      ui->lineEdit_age->setText(model->index(idx , 6).data().toString());
      ui->lineEdit_cap_att->setText(model->index(idx , 7).data().toString());
      ui->lineEdit_cap_def->setText(model->index(idx , 8).data().toString());
}

void Dialog::on_tablejoueur_doubleClicked()
{
    QSqlQueryModel * model=tmpjoueur.afficher();
    int idx = ui->tablejoueur->selectionModel()->currentIndex().row();
    ui->lineEdit->setText(model->index(idx , 0).data().toString());
}

void Dialog::on_tablediscipline_clicked()
{
    QSqlQueryModel * model=tmpdiscipline.afficher();
        int idx = ui->tablediscipline->selectionModel()->currentIndex().row();
       ui->lineEdit_id->setText(model->index(idx , 0).data().toString());
       ui->lineEdit_type->setText(model->index(idx , 1).data().toString());
       ui->lineEdit_nb->setText(model->index(idx , 2).data().toString());
}

void Dialog::on_tablediscipline_doubleClicked()
{
    QSqlQueryModel * model=tmpdiscipline.afficher();
    int idx = ui->tablediscipline->selectionModel()->currentIndex().row();
    ui->lineEdit_id2->setText(model->index(idx , 0).data().toString());
}

void Dialog::on_pushButton_ajoutp_clicked()
{
    int code=ui->lineEdit_code->text().toInt();
    float prix=ui->lineEdit_prix->text().toFloat();
    int idp=ui->lineEdit_idp->text().toInt();
    int qte=ui->lineEdit_qte->text().toInt();
    QString des=ui->lineEdit_des->text();
    QString pho=ui->lineEdit_pho->text();
    QString col=ui->lineEdit_col->text();
    Produits p(code,prix,qte,des,pho,col,idp);
   initialiser_p();
    bool test=p.ajouter();
    if(test)
  {

        ui->tabproduits->setModel(tmproduits.afficher());//refresh
  QMessageBox::information(nullptr, QObject::tr("Ajouter un produits"),
                    QObject::tr("Produits ajouté.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

  }
    else
        QMessageBox::critical(nullptr, QObject::tr("Ajouter un produits"),
                    QObject::tr("Erreur !.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
}

void Dialog::on_pushButton_modifp_clicked()
{
    int code=ui->lineEdit_code->text().toInt();
    float prix=ui->lineEdit_prix->text().toFloat();
    int idp=ui->lineEdit_idp->text().toInt();
    int qte=ui->lineEdit_qte->text().toInt();
    QString des=ui->lineEdit_des->text();
    QString pho=ui->lineEdit_pho->text();
    QString col=ui->lineEdit_col->text();
    Produits p(code,prix,qte,des,pho,col,idp);
    bool test=p.modifier();
    initialiser_p();
    if(test)
  {

        ui->tabproduits->setModel(tmproduits.afficher());//refresh
  QMessageBox::information(nullptr, QObject::tr("Modifier un produits"),
                    QObject::tr("Produits modifié.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

  }

    else
        QMessageBox::critical(nullptr, QObject::tr("Modifier un produits"),
                    QObject::tr("Erreur !.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
}

void Dialog::on_pushButton_suppp_clicked()
{
    int code = ui->lineEdit_supp->text().toInt();
    bool test=tmproduits.supprimer(code);
    ui->lineEdit->setText("");
    if(test)
    {ui->tabproduits->setModel(tmproduits.afficher());//refresh
        QMessageBox::information(nullptr, QObject::tr("Supprimer un produit"),
                    QObject::tr("Etudiant supprimé.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);


    }
    else
        QMessageBox::critical(nullptr, QObject::tr("Supprimer un produit"),
                    QObject::tr("Erreur !.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
}

void Dialog::on_pushButton_rechp_clicked()
{
    QString des=ui->lineEdit_rech->text();
    ui->tabproduits->setModel(tmproduits.recherche(des));
}

void Dialog::on_pushButton_tri_clicked()
{

    ui->tabproduits->setModel(tmproduits.trier());
}

void Dialog::on_pushButton_pdfp_clicked()
{
    //QDateTime datecreation = date.currentDateTime();
        //QString afficheDC = "Date de Creation PDF : " + datecreation.toString() ;
              // QPdfWriter pdf(" C:/Users/amine/Desktop/Pdf.pdf");
               QPrinter printer(QPrinter::HighResolution);
               printer.setOutputFormat(QPrinter::PdfFormat);
               printer.setOutputFileName("C:/Users/amine/Desktop/Pdf.pdf");

               QPainter painter(&printer);
              int i = 4000;
                   painter.setPen(Qt::red);
                   painter.setFont(QFont("Arial", 40));
                   painter.drawText(2200,1200,"Liste des Produits");
                   painter.setPen(Qt::black);
                   painter.setFont(QFont("Arial", 30));
                  // painter.drawText(1100,2000,afficheDC);
                   painter.drawRect(1000,100,7300,2000);
                   //painter.drawPixmap(QRect(7600,70,2000,2600),QPixmap("C:/Users/RH/Desktop/projecpp/image/logopdf.png"));
                   painter.drawRect(0,3000,9600,500);
                   painter.setFont(QFont("Arial",15));
                   painter.drawText(200,3300,"code");
                   painter.drawText(1300,3300,"prix");
                   painter.drawText(2100,3300,"quantité");
                   painter.drawText(3200,3300,"designation");
                   painter.drawText(5300,3300,"photo");
                   painter.drawText(7700,3300,"couleur");
                   painter.drawText(9000,3300,"idp");

                   QSqlQuery query;
                   query.prepare("select * from produits ");
                   query.exec();
                   while (query.next())
                   {
                       painter.drawText(200,i,query.value(0).toString());
                       painter.drawText(1300,i,query.value(1).toString());
                       painter.drawText(2200,i,query.value(2).toString());
                       painter.drawText(3200,i,query.value(3).toString());
                       painter.drawText(5300,i,query.value(4).toString());
                       painter.drawText(7700,i,query.value(5).toString());
                       painter.drawText(9000,i,query.value(6).toString());
                      i = i + 500;
                   }


                   int reponse = QMessageBox::question(this, "Génerer PDF", "<PDF Enregistré>...Vous Voulez Affichez Le PDF ?", QMessageBox::Yes |  QMessageBox::No);
                       if (reponse == QMessageBox::Yes)
                       {

                           painter.end();
                       }
                       if (reponse == QMessageBox::No)
                       {
                            painter.end();
                       }
}

void Dialog::on_pushButton_ajoutcat_clicked()
{
    int idc=ui->lineEdit_idc->text().toInt();
    QString nom=ui->lineEdit_nomc->text();
    Categories c(idc,nom);
    bool test=c.ajouter();
    initialiser_c();
    if(test)
  {

        ui->tabCat->setModel(tmpcat.afficher());//refresh
  QMessageBox::information(nullptr, QObject::tr("Ajouter une catégorie"),
                    QObject::tr("Produits ajouté.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

  }
    else
        QMessageBox::critical(nullptr, QObject::tr("Ajouter une catégorie"),
                    QObject::tr("Erreur !.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
}

void Dialog::on_pushButton_modifCat_clicked()
{
    int idc=ui->lineEdit_idc->text().toInt();
    QString nom=ui->lineEdit_nomc->text();
    Categories c(idc,nom);
    bool test=c.modifier();
    initialiser_c();
    if(test)
  {

        ui->tabCat->setModel(tmpcat.afficher());//refresh
  QMessageBox::information(nullptr, QObject::tr("Modifier une catégorie"),
                    QObject::tr("Categorie modifié.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

  }
    else
        QMessageBox::critical(nullptr, QObject::tr("Modifier une catégorie"),
                    QObject::tr("Erreur !.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
}

void Dialog::on_pushButton_suppCat_clicked()
{
    int idc = ui->lineEdit_Idc->text().toInt();
    bool test=tmpcat.supprimer(idc);
    ui->lineEdit_Idc->setText("");
    if(test)
    {ui->tabCat->setModel(tmpcat.afficher());//refresh
        QMessageBox::information(nullptr, QObject::tr("Supprimer une categorie"),
                    QObject::tr("Catégorie supprimée.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

    }
    else
        QMessageBox::critical(nullptr, QObject::tr("Supprimer une categorie"),
                    QObject::tr("Erreur !.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
}

void Dialog::on_pushButton_rechCat_clicked()
{
    QString nom=ui->lineEdit_rechCat->text();
    ui->tabCat->setModel(tmpcat.recherche(nom));
}

void Dialog::on_pushButton_triCat_clicked()
{
  ui->tabCat->setModel(tmpcat.trier());
}

void Dialog::on_pushButton_3_clicked()
{
  ui->stackedWidget->setCurrentIndex(0);
}

void Dialog::on_tabproduits_clicked()
{
    QSqlQueryModel * model=tmproduits.afficher();
      int rowidx = ui->tabproduits->selectionModel()->currentIndex().row();

      ui->lineEdit_code->setText(model->index(rowidx , 0).data().toString());
      ui->lineEdit_prix->setText(model->index(rowidx , 1).data().toString());
      ui->lineEdit_qte->setText(model->index(rowidx , 2).data().toString());
      ui->lineEdit_des->setText(model->index(rowidx , 3).data().toString());
      ui->lineEdit_pho->setText(model->index(rowidx , 4).data().toString());
      ui->lineEdit_col->setText(model->index(rowidx , 5).data().toString());
      ui->lineEdit_idp->setText(model->index(rowidx , 6).data().toString());
}

void Dialog::on_tabproduits_doubleClicked()
{
    QSqlQueryModel * model=tmproduits.afficher();
       int rowidx = ui->tabproduits->selectionModel()->currentIndex().row();
        ui->lineEdit_supp->setText(model->index(rowidx , 0).data().toString());
}

void Dialog::on_tabCat_clicked()
{
    QSqlQueryModel * model=tmpcat.afficher();
    int rowidx = ui->tabCat->selectionModel()->currentIndex().row();

    ui->lineEdit_idc->setText(model->index(rowidx , 0).data().toString());
    ui->lineEdit_nom->setText(model->index(rowidx , 1).data().toString());
}

void Dialog::on_tabCat_doubleClicked()
{
    QSqlQueryModel * model=tmpcat.afficher();
    int rowidx = ui->tabCat->selectionModel()->currentIndex().row();

    ui->lineEdit_Idc->setText(model->index(rowidx , 0).data().toString());
}

void Dialog::on_pushButton_menu2_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void Dialog::on_pushButton_5_clicked()
{
 ui->stackedWidget->setCurrentIndex(3);
}

void Dialog::on_pushButton_ajoutab_clicked()
{
    int b=ui->lineEdit_ida->text().toInt();
    int c=ui->lineEdit_prixa->text().toInt();
    abonnements a(b,c,ui->lineEdit_typea->text(),ui->dateEdit->date());
      if(a.ajouter()){
    QMessageBox::information(nullptr, QObject::tr("aadded successfuly"),
                        QObject::tr("added successfuly.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);

        }


        else
        {
            QMessageBox::critical(nullptr, QObject::tr("added unsuccessfuly"),
                        QObject::tr("champ vide.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);

}
       ui->tableView->setModel(a.afficher());

}

void Dialog::on_pushButton_modifierab_clicked()
{
    {

        int a=ui->lineEdit_ida->text().toInt();
            int b= ui->lineEdit_prixa->text().toInt();
            QString c= ui->lineEdit_typea->text();
            QDate d= ui->dateEdit->date();

           abonnements o(a,b,c,d);
            if(o.modifier()){
                ui->tableView->setModel(o.afficher());
                QMessageBox::information(nullptr, QObject::tr("update successful"),
                            QObject::tr("update succesful.\n"
                                        "verifiez vos parametres."), QMessageBox::Cancel);

            }

            else
    {
                QMessageBox::critical(nullptr, QObject::tr("updating failed"),
                            QObject::tr("updating failedl.\n"
                                        "verifiez vos parametres."), QMessageBox::Cancel);



    }
            ui->tableView->setModel(o.afficher());
}
}

void Dialog::on_pushButton_supprimerab_clicked()
{
    abonnements o;
    o.supprimer(ui->lineEdit_ida1->text().toInt());
    ui->tableView->setModel(o.afficher());
}

void Dialog::on_pushButton_ajoutera_clicked()
{
    int a= ui->lineEdit_cina->text().toInt();
         QString b= ui->lineEdit_noma->text();
         QString c= ui->lineEdit_prenoma->text();
         int d= ui->lineEdit_numa->text().toInt();
           QString e= ui->lineEdit_emaila->text();
           QString f= ui->lineEdit_adressea->text();
           QDate g= ui->dateEdit_datea->date();

       abonnes o(a,b,c,d,e,f,g);
         if(o.ajouter()){

             QMessageBox::information(nullptr, QObject::tr("ajout successful"),
                         QObject::tr("ajout successful.\n"
                                     "Click Cancel to exit."), QMessageBox::Cancel);

         }


         else
         {
             QMessageBox::critical(nullptr, QObject::tr("ajout unsuccessful"),
                         QObject::tr("champ vide.\n"
                                     "Click Cancel to exit."), QMessageBox::Cancel);


         }
          ui->tableView_2->setModel(o.afficher());
}

void Dialog::on_pushButton_modifiera_clicked()
{

    int a= ui->lineEdit_cina->text().toInt();
         QString b= ui->lineEdit_noma->text();
         QString c= ui->lineEdit_prenoma->text();
         int d= ui->lineEdit_numa->text().toInt();
           QString e= ui->lineEdit_emaila->text();
           QString f= ui->lineEdit_adressea->text();
           QDate g= ui->dateEdit_datea->date();

         abonnes o(a,b,c,d,e,f,g);
           if(o.modifier()){
               ui->tableView_2->setModel(o.afficher());
               QMessageBox::information(nullptr, QObject::tr("update successful"),
                           QObject::tr("update successful.\n"
                                       "Click Cancel to exit."), QMessageBox::Cancel);

           }

           else
   {
               QMessageBox::critical(nullptr, QObject::tr("updating failed"),
                           QObject::tr("updating failedl.\n"
                                       "verifiez vos parametres."), QMessageBox::Cancel);



   }
}

void Dialog::on_pushButton_supprimera_clicked()
{
    abonnes o;
       o.supprimer(ui->lineEdit_cina2->text().toInt());
       ui->tableView_2->setModel(o.afficher());
}


void Dialog::on_pushButton_12_clicked()
{
     ui->stackedWidget->setCurrentIndex(0);
}

void Dialog::on_tableView_clicked()
{
    abonnements a;
       QSqlQueryModel * model=a.afficher();
            int idx = ui->tableView->selectionModel()->currentIndex().row();
                 ui->lineEdit_ida->setText(model->index(idx , 0).data().toString());
            ui->lineEdit_prixa->setText(model->index(idx , 1).data().toString());
           ui->lineEdit_typea->setText(model->index(idx , 2).data().toString());
           ui->dateEdit->setDate(model->index(idx , 3).data().toDate());
}

void Dialog::on_tableView_2_clicked()
{
    abonnes a;
      QSqlQueryModel * model=a.afficher();
           int idx = ui->tableView_2->selectionModel()->currentIndex().row();
                ui->lineEdit_cina->setText(model->index(idx , 0).data().toString());
           ui->lineEdit_noma->setText(model->index(idx , 1).data().toString());
          ui->lineEdit_prenoma->setText(model->index(idx , 2).data().toString());
          ui->lineEdit_numa->setText(model->index(idx , 3).data().toString());
          ui->lineEdit_emaila->setText(model->index(idx , 4).data().toString());
          ui->lineEdit_adressea->setText(model->index(idx , 5).data().toString());
          ui->dateEdit_datea->setDate(model->index(idx , 3).data().toDate());
}

/*void MainWindow::on_pushButton_6_clicked()
{

        on_off = true;
           while(on_off == true){

           QApplication::processEvents();

           QPixmap ship(":/img/img/koura.png");
           QPixmap rotate(ship.size());

           QPainter p(&rotate);

           p.setRenderHint(QPainter::Antialiasing);
           p.setRenderHint(QPainter::SmoothPixmapTransform);
           p.setRenderHint(QPainter::HighQualityAntialiasing);
           p.translate(rotate.size().width() / 2, rotate.size().height() / 2);
           p.rotate(couner);
           p.translate(-rotate.size().width() / 2, -rotate.size().height() / 2);

           p.drawPixmap(0, 0, ship);



           p.end();

           ui->label_koora->setPixmap(rotate);

           couner++;
           }

}*/

void Dialog::on_pushButton_6_clicked()
{
    ui->stackedWidget->setCurrentIndex(4);
}

void Dialog::on_pushButton_8_clicked()
{
    int cin =ui->lineEdit_cin->text().toInt();
        QString nom=ui->lineEdit_nom->text();
        QString prenom=ui->lineEdit_prenom->text();
        QString poste=ui->lineEdit_poste->text();
        int age=ui->lineEdit_age->text().toInt();
        int tel=ui->lineEdit_tel->text().toInt();
        staff S (cin,nom,prenom,poste,age,tel);
        bool test= S.ajouter();
        initialiser();
  if(test)
{

      ui->tablestaff->setModel(tmpstaff.afficher());//refresh
QMessageBox::information(nullptr, QObject::tr("Ajouter un staff"),
                  QObject::tr("staff ajouté.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);



}
  else
      QMessageBox::critical(nullptr, QObject::tr("Ajouter un staff"),
                  QObject::tr("Erreur !.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);

}

void Dialog::on_pushButton_14_clicked()
{
    int cin =ui->lineEdit_cin->text().toInt();
    QString nom=ui->lineEdit_nom->text();
    QString prenom=ui->lineEdit_prenom->text();
    QString poste=ui->lineEdit_poste->text();
    int age=ui->lineEdit_age->text().toInt();
        int tel=ui->lineEdit_tel->text().toInt();
    staff S (cin,nom,prenom,poste,age,tel);
    bool test= S.modifier();
    initialiser();
  if(test)
{

      ui->tablestaff->setModel(tmpstaff.afficher());//refresh
QMessageBox::information(nullptr, QObject::tr("modifier un staff"),
                  QObject::tr("staff modifié.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);

}
  else
      QMessageBox::critical(nullptr, QObject::tr("modifier un staff"),
                  QObject::tr("Erreur !.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);
}

void Dialog::on_pushButton_15_clicked()
{
    int cin = ui->lineEdit->text().toInt();
    bool test=tmpstaff.supprimer(cin);
    ui->lineEdit->setText("");
    if(test)
    {ui->tablestaff->setModel(tmpstaff.afficher());//refresh
        QMessageBox::information(nullptr, QObject::tr("Supprimer un staff"),
                    QObject::tr("staff supprimé.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

    }
    else
        QMessageBox::critical(nullptr, QObject::tr("Supprimer un staff"),
                    QObject::tr("Erreur !.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
}

void Dialog::on_pushButton_18_clicked()
{
    QString nom = ui->lineEdit_2->text();
           ui->tablestaff->setModel(tmpstaff.rechercher(nom));
}

void Dialog::on_pushButton_17_clicked()
{
    ui->tablestaff->setModel(tmpstaff.trier());
}

void Dialog::on_tablestaff_clicked()
{
    QSqlQueryModel * model=tmpstaff.afficher();
         int idx = ui->tablestaff->selectionModel()->currentIndex().row();
        ui->lineEdit_cin->setText(model->index(idx , 0).data().toString());
        ui->lineEdit_nom->setText(model->index(idx , 1).data().toString());
        ui->lineEdit_prenom->setText(model->index(idx , 2).data().toString());
        ui->lineEdit_poste->setText(model->index(idx , 3).data().toString());
        ui->lineEdit_age->setText(model->index(idx , 4).data().toString());
        ui->lineEdit_tel->setText(model->index(idx , 5).data().toString());
}

void Dialog::on_tablestaff_doubleClicked()
{
    QSqlQueryModel * model=tmpstaff.afficher();
    int idx = ui->tablestaff->selectionModel()->currentIndex().row();
    ui->lineEdit->setText(model->index(idx , 0).data().toString());
}

void Dialog::on_pushButton_ajouterd_2_clicked()
{
    int id =ui->lineEdit_id_2->text().toInt();
     int nb_heures=ui->lineEdit_nb_2->text().toInt();
     QString type=ui->lineEdit_type_2->text();
     int salaire=ui->lineEdit_sal->text().toInt();


     categorie C (id,type,nb_heures,salaire);
     bool test= C.ajouter();
     initialiser1();
if(test)
{

   ui->tablecategorie->setModel(tmpcategorie.afficher());//refresh
QMessageBox::information(nullptr, QObject::tr("Ajouter une categorie"),
               QObject::tr("categoriee ajoutée.\n"
                           "Click Cancel to exit."), QMessageBox::Cancel);

}
else
   QMessageBox::critical(nullptr, QObject::tr("Ajouter une categorie"),
               QObject::tr("Erreur !.\n"
                           "Click Cancel to exit."), QMessageBox::Cancel);
}

void Dialog::on_pushButton_20_clicked()
{

    int id =ui->lineEdit_id_2->text().toInt();
     int nb_heures=ui->lineEdit_nb_2->text().toInt();
     QString type=ui->lineEdit_type_2->text();
     int salaire=ui->lineEdit_sal->text().toInt();


     categorie C (id,type,nb_heures,salaire);
     bool test= C.modifier();
if(test)
{

   ui->tablecategorie->setModel(tmpcategorie.afficher());//refresh
QMessageBox::information(nullptr, QObject::tr("modifier une categorie"),
               QObject::tr("categorie modifiée.\n"
                           "Click Cancel to exit."), QMessageBox::Cancel);

}
else
   QMessageBox::critical(nullptr, QObject::tr("modifier une categorie"),
               QObject::tr("Erreur !.\n"
                           "Click Cancel to exit."), QMessageBox::Cancel);
}

void Dialog::on_pushButton_supprimer2_clicked()
{
    int id = ui->lineEdit_id2_2->text().toInt();
    bool test=tmpcategorie.supprimer(id);
      ui->lineEdit_id2_2->setText("");
    if(test)
    {ui->tablecategorie->setModel(tmpcategorie.afficher());//refresh
        QMessageBox::information(nullptr, QObject::tr("Supprimer un categorie"),
                    QObject::tr("categorie supprimée.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

    }
    else
        QMessageBox::critical(nullptr, QObject::tr("Supprimer une categorie"),
                    QObject::tr("Erreur !.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
}

void Dialog::on_pushButton_21_clicked()
{
    QString type = ui->lineEdit_3->text();
         ui->tablecategorie->setModel(tmpcategorie.rechercher(type));
}

void Dialog::on_pushButton_22_clicked()
{
    ui->tablecategorie->setModel(tmpcategorie.trier());

}

void Dialog::on_tablecategorie_clicked()
{  QSqlQueryModel * model=tmpcategorie.afficher();
    int idx = ui->tablecategorie->selectionModel()->currentIndex().row();
   ui->lineEdit_id_2->setText(model->index(idx , 0).data().toString());
   ui->lineEdit_type_2->setText(model->index(idx , 1).data().toString());
   ui->lineEdit_nb_2->setText(model->index(idx , 2).data().toString());
   ui->lineEdit_sal->setText(model->index(idx , 3).data().toString());

}

void Dialog::on_tablecategorie_doubleClicked()
{
    QSqlQueryModel * model=tmpcategorie.afficher();
    int idx = ui->tablecategorie->selectionModel()->currentIndex().row();
    ui->lineEdit_id2_2->setText(model->index(idx , 0).data().toString());
}

void Dialog::on_pushButton_24_clicked()
{
   ui->stackedWidget->setCurrentIndex(0);
}

void Dialog::on_pushButton_25_clicked()
{

        //QDateTime datecreation = date.currentDateTime();
            //QString afficheDC = "Date de Creation PDF : " + datecreation.toString() ;
                  // QPdfWriter pdf(" C:/Users/IMNA/Desktop/Pdf.pdf");
                   QPrinter printer(QPrinter::HighResolution);
                   printer.setOutputFormat(QPrinter::PdfFormat);
                   printer.setOutputFileName("C:/Users/amine/Desktop/Pdf.pdf");

                   QPainter painter(&printer);
                  int i = 4000;
                       painter.setPen(Qt::red);
                       painter.setFont(QFont("Arial", 40));
                       painter.drawText(2200,1200,"Liste des abonnées");
                       painter.setPen(Qt::black);
                       painter.setFont(QFont("Arial", 30));
                      // painter.drawText(1100,2000,afficheDC);
                       painter.drawRect(1000,100,7300,2000);
                       //painter.drawPixmap(QRect(7600,70,2000,2600),QPixmap("C:/Users/RH/Desktop/projecpp/image/logopdf.png"));
                       painter.drawRect(0,3000,9600,500);
                       painter.setFont(QFont("Arial",15));
                       painter.drawText(200,3300,"cin");
                       painter.drawText(1300,3300,"nom");
                       painter.drawText(2100,3300,"prenom");
                       painter.drawText(3200,3300,"numtel");
                       painter.drawText(5300,3300,"email");
                       painter.drawText(7700,3300,"adresse");
                       painter.drawText(9000,3300,"date de naissance");

                       QSqlQuery query;
                       query.prepare("select * from abonnes ");
                       query.exec();
                       while (query.next())
                       {
                           painter.drawText(200,i,query.value(0).toString());
                           painter.drawText(1300,i,query.value(1).toString());
                           painter.drawText(2200,i,query.value(2).toString());
                           painter.drawText(3200,i,query.value(3).toString());
                           painter.drawText(5300,i,query.value(4).toString());
                           painter.drawText(7700,i,query.value(5).toString());
                           painter.drawText(9000,i,query.value(6).toString());
                          i = i + 500;
                       }


                       int reponse = QMessageBox::question(this, "Génerer PDF", "<PDF Enregistré>...Vous Voulez Affichez Le PDF ?", QMessageBox::Yes |  QMessageBox::No);
                           if (reponse == QMessageBox::Yes)
                           {

                               painter.end();
                           }
                           if (reponse == QMessageBox::No)
                           {
                                painter.end();
                           }
    }


void Dialog::on_pb_ajouter_billet_clicked()
{

    QString id= ui->lineEdit_id_3->text();
    int nbticket= ui->lineEdit_nbticket->text().toInt();
    int prix= ui->lineEdit_prix_2->text().toInt();

  billet e(id,nbticket,prix);
  bool test=e.ajouter();
  if(test)
{ui->tabbillet->setModel(tmpbillet.afficher());//refresh
QMessageBox::information(nullptr, QObject::tr("Ajouter un billet"),
                  QObject::tr("billet ajouté.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);

}
  else
      QMessageBox::critical(nullptr, QObject::tr("Ajouter un billet"),
                  QObject::tr("Erreur !.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);
}

void Dialog::on_pb_supprimer_billet_clicked()
{
    QString  id = ui->lineEdit_id_3->text();
bool test = tmpbillet.supprimer(id);
if(test)
{   ui->tabbillet->setModel(tmpbillet.afficher());//refresh
    QMessageBox::information(nullptr, QObject::tr("Supprimer un billet"),
                QObject::tr("billet supprimé.\n"
                            "Click Cancel to exit."), QMessageBox::Cancel);

}
else
    QMessageBox::critical(nullptr, QObject::tr("Supprimer un billet"),
                QObject::tr("Erreur !.\n"
                            "Click Cancel to exit."), QMessageBox::Cancel);
}

void Dialog::on_pushButton_trieBillet_clicked()
{
    QString type = ui->lineEdit_ctqui_4->text();
         ui->tabbillet->setModel(tmpbillet.rechercher(type));
}

void Dialog::on_pushButton_supBillet_clicked()
{
    ui->tabbillet->setModel(tmpbillet.trier());

}

void Dialog::on_pb_ajouter_clicked()
{
    QString ctqui= ui->lineEdit_ctqui->text();
    QString dat= ui->lineEdit_date->text();
    QString placement= ui->lineEdit_placement->text();
    QString type= ui->lineEdit_type_3->text();
    QString etat= ui->lineEdit_etat->text();
  match e(ctqui,dat,placement,type,etat);
  bool test=e.ajouter();
  if(test)
{ui->tabmatch->setModel(tmpmatch.afficher());//refresh
QMessageBox::information(nullptr, QObject::tr("Ajouter un match"),
                  QObject::tr("match ajouté.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);

}
  else
      QMessageBox::critical(nullptr, QObject::tr("Ajouter un match"),
                  QObject::tr("Erreur !.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);

}

void Dialog::on_pb_supprimer_clicked()
{
    QString  ctqui = ui->lineEdit_ctqui->text();
bool test = tmpmatch.supprimer(ctqui);
if(test)
{ui->tabmatch->setModel(tmpmatch.afficher());//refresh
    QMessageBox::information(nullptr, QObject::tr("Supprimer un match"),
                QObject::tr("match supprimé.\n"
                            "Click Cancel to exit."), QMessageBox::Cancel);

}
else
    QMessageBox::critical(nullptr, QObject::tr("Supprimer un match"),
                QObject::tr("Erreur !.\n"
                            "Click Cancel to exit."), QMessageBox::Cancel);

}

void Dialog::on_pushButton_rech_match_clicked()
{
    QString type = ui->lineEdit_supctr->text();
         ui->tabmatch->setModel(tmpmatch.rechercher(type));
}

void Dialog::on_pushButton_tri_match_clicked()
{
    ui->tabmatch->setModel(tmpmatch.trier());

}

void Dialog::on_pushButton_26_clicked()
{
    //QDateTime datecreation = date.currentDateTime();
        //QString afficheDC = "Date de Creation PDF : " + datecreation.toString() ;
              // QPdfWriter pdf(" C:/Users/IMNA/Desktop/Pdf.pdf");
               QPrinter printer(QPrinter::HighResolution);
               printer.setOutputFormat(QPrinter::PdfFormat);
               printer.setOutputFileName("C:/Users/amine/Desktop/Pdf_anis.pdf");

               QPainter painter(&printer);
              int i = 4000;
                   painter.setPen(Qt::red);
                   painter.setFont(QFont("Arial", 40));
                   painter.drawText(2200,1200,"Liste des match");
                   painter.setPen(Qt::black);
                   painter.setFont(QFont("Arial", 30));
                   painter.drawRect(1000,100,7300,2000);
                   painter.drawRect(0,3000,9600,500);
                   painter.setFont(QFont("Arial",15));
                   painter.drawText(200,3300,"ctqui");
                   painter.drawText(1300,3300,"date");
                   painter.drawText(2100,3300,"placement");
                   painter.drawText(3200,3300,"type");
                   QSqlQuery query;
                   query.prepare("select * from match ");
                   query.exec();
                   while (query.next())
                   {
                       painter.drawText(200,i,query.value(0).toString());
                       painter.drawText(1300,i,query.value(1).toString());
                       painter.drawText(2200,i,query.value(2).toString());
                       painter.drawText(3200,i,query.value(3).toString());

                      i = i + 500;
                   }


                   int reponse = QMessageBox::question(this, "Génerer PDF", "<PDF Enregistré>...Vous Voulez Affichez Le PDF ?", QMessageBox::Yes |  QMessageBox::No);
                       if (reponse == QMessageBox::Yes)
                       {

                           painter.end();
                       }
                       if (reponse == QMessageBox::No)
                       {
                            painter.end();
                       }
}

/*-------------------------controle de saisie produits-------------------------------------------------------------------------*/

void Dialog::on_lineEdit_code_textChanged(const QString &arg1)
{
    QString texte=arg1;
 QString caracteresAlpha(CARACTERES_ALPHA);
 for (int i=0; i<texte.size(); i++)
 foreach (const QChar &y, caracteresAlpha)
     if(texte.at(i)==y)
    {
         texte[i]=' ';
         //incorrect->play();
     }

  ui->lineEdit_code->setText(texte);
}

void Dialog::on_lineEdit_prix_textChanged(const QString &arg1)
{
    QString texte=arg1;
 QString caracteresAlpha(CARACTERES_ALPHA);
 for (int i=0; i<texte.size(); i++)
 foreach (const QChar &y, caracteresAlpha)
     if(texte.at(i)==y)
    {
         texte[i]=' ';
         //incorrect->play();
     }

  ui->lineEdit_prix->setText(texte);
}


void Dialog::on_lineEdit_qte_textChanged(const QString &arg1)
{
    QString texte=arg1;
 QString caracteresAlpha(CARACTERES_ALPHA);
 for (int i=0; i<texte.size(); i++)
 foreach (const QChar &y, caracteresAlpha)
     if(texte.at(i)==y)
    {
         texte[i]=' ';
         //incorrect->play();
     }

  ui->lineEdit_code->setText(texte);
}

void Dialog::on_lineEdit_des_textEdited(const QString &arg1)
{
    QString texte=arg1;
QString caracteresEtrangers(CARACTERES_ETRANGERS);
for (int i=0; i<texte.size(); i++)
foreach (const QChar &y, caracteresEtrangers)
    if(texte.at(i)==y)
    {texte[i]=' ';
    // incorrect->play();
    }

 ui->lineEdit_des->setText(texte);

}

void Dialog::on_lineEdit_col_textEdited(const QString &arg1)
{

    QString texte=arg1;
QString caracteresEtrangers(CARACTERES_ETRANGERS);
for (int i=0; i<texte.size(); i++)
foreach (const QChar &y, caracteresEtrangers)
    if(texte.at(i)==y)
    {texte[i]=' ';
    // incorrect->play();
    }

 ui->lineEdit_col->setText(texte);

}

void Dialog::on_lineEdit_idp_textChanged(const QString &arg1)
{
    QString texte=arg1;
 QString caracteresAlpha(CARACTERES_ALPHA);
 for (int i=0; i<texte.size(); i++)
 foreach (const QChar &y, caracteresAlpha)
     if(texte.at(i)==y)
    {
         texte[i]=' ';
         //incorrect->play();
     }

  ui->lineEdit_idp->setText(texte);
}

/*---------------------Categories--------------------------------------------------------------------------------------------------------*/
void Dialog::on_lineEdit_idc_textChanged(const QString &arg1)
{
    QString texte=arg1;
 QString caracteresAlpha(CARACTERES_ALPHA);
 for (int i=0; i<texte.size(); i++)
 foreach (const QChar &y, caracteresAlpha)
     if(texte.at(i)==y)
    {
         texte[i]=' ';
         //incorrect->play();
     }

  ui->lineEdit_idc->setText(texte);
}

void Dialog::on_lineEdit_nonc_textEdited(const QString &arg1)
{

    QString texte=arg1;
QString caracteresEtrangers(CARACTERES_ETRANGERS);
for (int i=0; i<texte.size(); i++)
foreach (const QChar &y, caracteresEtrangers)
    if(texte.at(i)==y)
    {texte[i]=' ';
    // incorrect->play();
    }

 ui->lineEdit_nomc->setText(texte);

}

/*--------------------------abonnements-----------------------------------------------------------------------------------------------*/
void Dialog::on_lineEdit_ida_textChanged(const QString &arg1)
{
    QString texte=arg1;
 QString caracteresAlpha(CARACTERES_ALPHA);
 for (int i=0; i<texte.size(); i++)
 foreach (const QChar &y, caracteresAlpha)
     if(texte.at(i)==y)
    {
         texte[i]=' ';
         //incorrect->play();
     }

  ui->lineEdit_ida->setText(texte);
}

void Dialog::on_lineEdit_prixa_textChanged(const QString &arg1)
{
    QString texte=arg1;
 QString caracteresAlpha(CARACTERES_ALPHA);
 for (int i=0; i<texte.size(); i++)
 foreach (const QChar &y, caracteresAlpha)
     if(texte.at(i)==y)
    {
         texte[i]=' ';
         //incorrect->play();
     }

  ui->lineEdit_prixa->setText(texte);
}

void Dialog::on_lineEdit_typea_textEdited(const QString &arg1)
{

    QString texte=arg1;
QString caracteresEtrangers(CARACTERES_ETRANGERS);
for (int i=0; i<texte.size(); i++)
foreach (const QChar &y, caracteresEtrangers)
    if(texte.at(i)==y)
    {texte[i]=' ';
    // incorrect->play();
    }

 ui->lineEdit_typea->setText(texte);

}
/*--------------------abonnes---------------------------------------------------------------------------------------------------*/

void Dialog::on_lineEdit_cina_textChanged(const QString &arg1)
{
    QString texte=arg1;
 QString caracteresAlpha(CARACTERES_ALPHA);
 for (int i=0; i<texte.size(); i++)
 foreach (const QChar &y, caracteresAlpha)
     if(texte.at(i)==y)
    {
         texte[i]=' ';
         //incorrect->play();
     }

  ui->lineEdit_cina->setText(texte);
}

void Dialog::on_lineEdit_noma_textEdited(const QString &arg1)
{

    QString texte=arg1;
QString caracteresEtrangers(CARACTERES_ETRANGERS);
for (int i=0; i<texte.size(); i++)
foreach (const QChar &y, caracteresEtrangers)
    if(texte.at(i)==y)
    {texte[i]=' ';
    // incorrect->play();
    }

 ui->lineEdit_noma->setText(texte);

}


void Dialog::on_lineEdit_prenoma_textEdited(const QString &arg1)
{

    QString texte=arg1;
QString caracteresEtrangers(CARACTERES_ETRANGERS);
for (int i=0; i<texte.size(); i++)
foreach (const QChar &y, caracteresEtrangers)
    if(texte.at(i)==y)
    {texte[i]=' ';
    // incorrect->play();
    }

 ui->lineEdit_prenoma->setText(texte);
}

void Dialog::on_lineEdit_numa_textChanged(const QString &arg1)
{
    QString texte=arg1;
 QString caracteresAlpha(CARACTERES_ALPHA);
 for (int i=0; i<texte.size(); i++)
 foreach (const QChar &y, caracteresAlpha)
     if(texte.at(i)==y)
    {
         texte[i]=' ';
         //incorrect->play();
     }

  ui->lineEdit_numa->setText(texte);
}

void Dialog::on_lineEdit_adressea_textEdited(const QString &arg1)
{

    QString texte=arg1;
QString caracteresEtrangers(CARACTERES_ETRANGERS);
for (int i=0; i<texte.size(); i++)
foreach (const QChar &y, caracteresEtrangers)
    if(texte.at(i)==y)
    {texte[i]=' ';
    // incorrect->play();
    }

 ui->lineEdit_adressea->setText(texte);
}

/*--------------------------------staff-------------------------------------------------------*/
void Dialog::on_lineEdit_cin_2_textChanged(const QString &arg1)
{
    QString texte=arg1;
 QString caracteresAlpha(CARACTERES_ALPHA);
 for (int i=0; i<texte.size(); i++)
 foreach (const QChar &y, caracteresAlpha)
     if(texte.at(i)==y)
    {
         texte[i]=' ';
         //incorrect->play();
     }

  ui->lineEdit_cin_2->setText(texte);
}

void Dialog::on_lineEdit_nom_2_textEdited(const QString &arg1)
{

    QString texte=arg1;
QString caracteresEtrangers(CARACTERES_ETRANGERS);
for (int i=0; i<texte.size(); i++)
foreach (const QChar &y, caracteresEtrangers)
    if(texte.at(i)==y)
    {texte[i]=' ';
    // incorrect->play();
    }

ui->lineEdit_nom_2->setText(texte);
}

void Dialog::on_lineEdit_prenom_2_textEdited(const QString &arg1)
{
    QString texte=arg1;
QString caracteresEtrangers(CARACTERES_ETRANGERS);
for (int i=0; i<texte.size(); i++)
foreach (const QChar &y, caracteresEtrangers)
    if(texte.at(i)==y)
    {texte[i]=' ';
    // incorrect->play();
    }

ui->lineEdit_prenom_2->setText(texte);
}

void Dialog::on_lineEdit_poste_2_textEdited(const QString &arg1)
{

    QString texte=arg1;
QString caracteresEtrangers(CARACTERES_ETRANGERS);
for (int i=0; i<texte.size(); i++)
foreach (const QChar &y, caracteresEtrangers)
    if(texte.at(i)==y)
    {texte[i]=' ';
    // incorrect->play();
    }

 ui->lineEdit_poste_2->setText(texte);
}

void Dialog::on_lineEdit_age_2_textEdited(const QString &arg1)
{
    QString texte=arg1;
 QString caracteresAlpha(CARACTERES_ALPHA);
 for (int i=0; i<texte.size(); i++)
 foreach (const QChar &y, caracteresAlpha)
     if(texte.at(i)==y)
    {
         texte[i]=' ';
         //incorrect->play();
     }

  ui->lineEdit_age_2->setText(texte);
}

void Dialog::on_lineEdit_tel_textEdited(const QString &arg1)
{
    QString texte=arg1;
 QString caracteresAlpha(CARACTERES_ALPHA);
 for (int i=0; i<texte.size(); i++)
 foreach (const QChar &y, caracteresAlpha)
     if(texte.at(i)==y)
    {
         texte[i]=' ';
         //incorrect->play();
     }

  ui->lineEdit_tel->setText(texte);
}

/*-----------------categorie-----------------------------------------------------------------------*/
void Dialog::on_lineEdit_id_2_textChanged(const QString &arg1)
{
    QString texte=arg1;
 QString caracteresAlpha(CARACTERES_ALPHA);
 for (int i=0; i<texte.size(); i++)
 foreach (const QChar &y, caracteresAlpha)
     if(texte.at(i)==y)
    {
         texte[i]=' ';
         //incorrect->play();
     }

  ui->lineEdit_id_2->setText(texte);

}

void Dialog::on_lineEdit_type_2_textChanged(const QString &arg1)
{

    QString texte=arg1;
QString caracteresEtrangers(CARACTERES_ETRANGERS);
for (int i=0; i<texte.size(); i++)
foreach (const QChar &y, caracteresEtrangers)
    if(texte.at(i)==y)
    {texte[i]=' ';
    // incorrect->play();
    }

 ui->lineEdit_type_2->setText(texte);
}

void Dialog::on_lineEdit_nb_2_textChanged(const QString &arg1)
{
    QString texte=arg1;
 QString caracteresAlpha(CARACTERES_ALPHA);
 for (int i=0; i<texte.size(); i++)
 foreach (const QChar &y, caracteresAlpha)
     if(texte.at(i)==y)
    {
         texte[i]=' ';
         //incorrect->play();
     }

  ui->lineEdit_nb_2->setText(texte);

}

void Dialog::on_lineEdit_sal_textChanged(const QString &arg1)
{
    QString texte=arg1;
 QString caracteresAlpha(CARACTERES_ALPHA);
 for (int i=0; i<texte.size(); i++)
 foreach (const QChar &y, caracteresAlpha)
     if(texte.at(i)==y)
    {
         texte[i]=' ';
         //incorrect->play();
     }

  ui->lineEdit_sal->setText(texte);

}

/*----------------joueuur-------------------------------------------------------------------*/
void Dialog::on_lineEdit_cin_textChanged(const QString &arg1)
{
    QString texte=arg1;
 QString caracteresAlpha(CARACTERES_ALPHA);
 for (int i=0; i<texte.size(); i++)
 foreach (const QChar &y, caracteresAlpha)
     if(texte.at(i)==y)
    {
         texte[i]=' ';
         //incorrect->play();
     }

  ui->lineEdit_cin->setText(texte);
}
void Dialog::on_lineEdit_nom_textEdited(const QString &arg1){
    QString texte=arg1;
QString caracteresEtrangers(CARACTERES_ETRANGERS);
for (int i=0; i<texte.size(); i++)
foreach (const QChar &y, caracteresEtrangers)
    if(texte.at(i)==y)
    {texte[i]=' ';
    // incorrect->play();
    }

 ui->lineEdit_nom->setText(texte);
}
void Dialog::on_lineEdit_prenom_textEdited(const QString &arg1) {
    QString texte=arg1;
QString caracteresEtrangers(CARACTERES_ETRANGERS);
for (int i=0; i<texte.size(); i++)
foreach (const QChar &y, caracteresEtrangers)
    if(texte.at(i)==y)
    {texte[i]=' ';
    // incorrect->play();
    }

 ui->lineEdit_prenom->setText(texte);
}

void Dialog::on_lineEdit_num_maillot_textChanged(const QString &arg1)
{
    QString texte=arg1;
 QString caracteresAlpha(CARACTERES_ALPHA);
 for (int i=0; i<texte.size(); i++)
 foreach (const QChar &y, caracteresAlpha)
     if(texte.at(i)==y)
    {
         texte[i]=' ';
         //incorrect->play();
     }

 ui->lineEdit_num_maillot->setText(texte);
}

   void Dialog::on_lineEdit_poste_textEdited(const QString &arg1)
   {
       QString texte=arg1;
   QString caracteresEtrangers(CARACTERES_ETRANGERS);
   for (int i=0; i<texte.size(); i++)
   foreach (const QChar &y, caracteresEtrangers)
       if(texte.at(i)==y)
       {texte[i]=' ';
       // incorrect->play();
       }

    ui->lineEdit_poste->setText(texte);
   }
   void Dialog::on_lineEdit_salaire_textEdited(const QString &arg1)
   {
       QString texte=arg1;
    QString caracteresAlpha(CARACTERES_ALPHA);
    for (int i=0; i<texte.size(); i++)
    foreach (const QChar &y, caracteresAlpha)
        if(texte.at(i)==y)
       {
            texte[i]=' ';
            //incorrect->play();
        }

    ui->lineEdit_salaire->setText(texte);
   }
   void Dialog::on_lineEdit_cap_att_textEdited(const QString &arg1)
   {
       QString texte=arg1;
    QString caracteresAlpha(CARACTERES_ALPHA);
    for (int i=0; i<texte.size(); i++)
    foreach (const QChar &y, caracteresAlpha)
        if(texte.at(i)==y)
       {
            texte[i]=' ';
            //incorrect->play();
        }

    ui->lineEdit_cap_att->setText(texte);

   }
   void Dialog::on_lineEdit_cap_def_textEdited(const QString &arg1)
   {
       QString texte=arg1;
    QString caracteresAlpha(CARACTERES_ALPHA);
    for (int i=0; i<texte.size(); i++)
    foreach (const QChar &y, caracteresAlpha)
        if(texte.at(i)==y)
       {
            texte[i]=' ';
            //incorrect->play();
        }

    ui->lineEdit_cap_def->setText(texte);
   }

/*----------------------------------------------------discipline----------------------------------------------------------   */
   void Dialog::on_lineEdit_id_textChanged(const QString &arg1)
   {
       QString texte=arg1;
    QString caracteresAlpha(CARACTERES_ALPHA);
    for (int i=0; i<texte.size(); i++)
    foreach (const QChar &y, caracteresAlpha)
        if(texte.at(i)==y)
       {
            texte[i]=' ';
            //incorrect->play();
        }

   ui->lineEdit_id->setText(texte);
   }
   void Dialog::on_lineEdit_type_textEdited(const QString &arg1)
   {
       QString texte=arg1;
    QString caracteresAlpha(CARACTERES_ALPHA);
    for (int i=0; i<texte.size(); i++)
    foreach (const QChar &y, caracteresAlpha)
        if(texte.at(i)==y)
       {
            texte[i]=' ';
            //incorrect->play();
        }

   ui->lineEdit_type->setText(texte);
   }
   void Dialog::on_lineEdit_nb_textEdited(const QString &arg1)
   {
       QString texte=arg1;
    QString caracteresAlpha(CARACTERES_ALPHA);
    for (int i=0; i<texte.size(); i++)
    foreach (const QChar &y, caracteresAlpha)
        if(texte.at(i)==y)
       {
            texte[i]=' ';
            //incorrect->play();
        }

   ui->lineEdit_nb->setText(texte);
   }

   //-------------billetterie----------------------------------------------------------------------------------------------
   void Dialog::on_lineEdit_id_3_textChanged(const QString &arg1)  {
       QString texte=arg1;
   QString caracteresEtrangers(CARACTERES_ETRANGERS);
   for (int i=0; i<texte.size(); i++)
   foreach (const QChar &y, caracteresEtrangers)
       if(texte.at(i)==y)
       {texte[i]=' ';
       // incorrect->play();
       }

     ui->lineEdit_id_3->setText(texte);
     }

     void Dialog::on_lineEdit_nbticket_textEdited(const QString &arg1)  {
         QString texte=arg1;
      QString caracteresAlpha(CARACTERES_ALPHA);
      for (int i=0; i<texte.size(); i++)
      foreach (const QChar &y, caracteresAlpha)
          if(texte.at(i)==y)
         {
              texte[i]=' ';
              //incorrect->play();
          }

     ui->lineEdit_nbticket->setText(texte);
     }
     void Dialog::on_lineEdit_prix_2_nb_textEdited(const QString &arg1)  {
         QString texte=arg1;
      QString caracteresAlpha(CARACTERES_ALPHA);
      for (int i=0; i<texte.size(); i++)
      foreach (const QChar &y, caracteresAlpha)
          if(texte.at(i)==y)
         {
              texte[i]=' ';
              //incorrect->play();
          }

     ui->lineEdit_prix_2->setText(texte);
     }

     //------match--------------------------------------------------------------------------------------------------------
       void Dialog::on_lineEdit_ctqui_textChanged(const QString &arg1)  {
           QString texte=arg1;
       QString caracteresEtrangers(CARACTERES_ETRANGERS);
       for (int i=0; i<texte.size(); i++)
       foreach (const QChar &y, caracteresEtrangers)
           if(texte.at(i)==y)
           {texte[i]=' ';
           // incorrect->play();
           }

        ui->lineEdit_ctqui->setText(texte);
       }
       void Dialog::on_lineEdit_placement_textEdited(const QString &arg1)  {
           QString texte=arg1;
       QString caracteresEtrangers(CARACTERES_ETRANGERS);
       for (int i=0; i<texte.size(); i++)
       foreach (const QChar &y, caracteresEtrangers)
           if(texte.at(i)==y)
           {texte[i]=' ';
           // incorrect->play();
           }

        ui->lineEdit_placement->setText(texte);
       }
       void Dialog::on_lineEdit_type_3_textEdited(const QString &arg1)  {
           QString texte=arg1;
       QString caracteresEtrangers(CARACTERES_ETRANGERS);
       for (int i=0; i<texte.size(); i++)
       foreach (const QChar &y, caracteresEtrangers)
           if(texte.at(i)==y)
           {texte[i]=' ';
           // incorrect->play();
           }

        ui->lineEdit_type_3->setText(texte);
       }


void Dialog::on_pushButton_modifanis1_clicked()
{
    QString ctqui= ui->lineEdit_ctqui->text();
    QString dat= ui->lineEdit_date->text();
    QString placement= ui->lineEdit_placement->text();
    QString type= ui->lineEdit_type_3->text();
    QString etat= ui->lineEdit_etat->text();
  match e(ctqui,dat,placement,type,etat);
  bool test=e.modifier();
  if(test)
{ui->tabmatch->setModel(tmpmatch.afficher());//refresh
QMessageBox::information(nullptr, QObject::tr("modifier un match"),
                  QObject::tr("match modifié.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);

}
  else
      QMessageBox::critical(nullptr, QObject::tr("modifier un match"),
                  QObject::tr("Erreur !.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);
}

void Dialog::on_pushButton_modifanis1_2_clicked()
{
    QString id= ui->lineEdit_id_3->text();
    int nbticket= ui->lineEdit_nbticket->text().toInt();
    int prix= ui->lineEdit_prix_2->text().toInt();

  billet e(id,nbticket,prix);
  bool test=e.modifier();
  if(test)
{ui->tabbillet->setModel(tmpbillet.afficher());//refresh
QMessageBox::information(nullptr, QObject::tr("modifier un billet"),
                  QObject::tr("billet modifié.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);

}
  else
      QMessageBox::critical(nullptr, QObject::tr("modifié un billet"),
                  QObject::tr("Erreur !.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);
}

void Dialog::on_pb_ajouter_menuanis_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void Dialog::on_pushButton_match_clicked()
{
     ui->stackedWidget->setCurrentIndex(5);
}
