#include "widget.h"
#include "ui_widget.h"
#include <QMessageBox>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_pushButtonConnexion_clicked()
{
    bd=QSqlDatabase::addDatabase("QMYSQL");
    bd.setHostName(ui->lineEditAdresseIP->text());
    bd.setDatabaseName(ui->lineEditNomBdd->text());
    bd.setUserName(ui->lineEditLogin->text());
    bd.setPassword(ui->lineEditMotDePasse->text());
    QMessageBox message;
    if (!bd.open())
    {
        QMessageBox message;
        message.setText("pb acces bd "+bd.lastError().text());
        message.exec();
    }
    else
    {
        message.setText("acces bd ok ");
        message.exec();
        ui->groupBoxConnexion->setEnabled(false);
        ui->groupBoxAffichageInfosComptes->setEnabled(true);

    }
}

void Widget::on_pushButtonAfficherInfos_clicked()
{
    QSqlQuery requete("select nom,prenom,idCompte,solde  from comptes order by idCompte;" );
    if (!requete.exec()){
        qDebug()<<"pb requete "<<requete.lastError();
    }
    QString nom,prenom;
    float solde;
    int idCompte;
    int ligne=0;
    while(requete.next()){
        nom=requete.value("nom").toString();
        prenom=requete.value("prenom").toString();
        solde=requete.value("solde").toFloat();
        idCompte=requete.value("idCompte").toInt();
        /* si on le fait avec un textEdit
         ui->textEditInfos->append(nom);
        ui->textEditInfos->append(prenom);
        ui->textEditInfos->append(solde);
        ui->textEditInfos->append(idCompte);
*/

            // ajouter une ligne au tableau
            ui->tableWidgetInfos->insertRow(ui->tableWidgetInfos->rowCount());
                // numero de la ligne
            int col=0;      // numero de la colonne
            // ajouter un nom
            QTableWidgetItem *nomItem = new QTableWidgetItem(nom);
            ui->tableWidgetInfos->setItem(ligne,col,nomItem);
            col++;
            // ajouter un prenom
            QTableWidgetItem *prenomItem = new QTableWidgetItem(prenom);
            ui->tableWidgetInfos->setItem(ligne,col,prenomItem);
            col++;
            // ajouter le numero de compte
            QTableWidgetItem *idCompteItem = new QTableWidgetItem(QString::number(idCompte));
            ui->tableWidgetInfos->setItem(ligne,col,idCompteItem);
            col++;
            // ajouter le solde
            QTableWidgetItem *soldeItem = new QTableWidgetItem(QString::number(solde));
            ui->tableWidgetInfos->setItem(ligne,col,soldeItem);
            ligne++;

    }
}
