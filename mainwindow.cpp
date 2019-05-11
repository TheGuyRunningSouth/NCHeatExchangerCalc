#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::CalcValues()
{
    QString temp = ui->coolantPerRecipeLineEdit->text();
    exchanger.coolantPerRecipe = temp.toFloat();

    temp = ui->coolantHeatMultiplierLineEdit->text();
    exchanger.coolantHeatMult = temp.toFloat();

    temp=ui->msrBaseCoolingRateLineEdit->text();
    exchanger.msrBaseCoolingRate = temp.toFloat();

    temp=ui->msrCoolingEfficiencyLineEdit->text();
    exchanger.msrCoolingEfficiency = temp.toFloat();

    temp=ui->numHeatersLineEdit->text();
    exchanger.numHeaters = temp.toFloat();

    temp = ui->coolantTubeConductivityLineEdit->text();
    exchanger.coolantTubeConductivity = temp.toFloat();

    temp=ui->waterBaseCoolingProvidedLineEdit->text();
    exchanger.waterBaseCoolingProvided = temp.toFloat();

    temp=ui->waterBaseHeatingRequiredLineEdit->text();
    exchanger.waterBaseHeatingRequired = temp.toFloat();

    temp=ui->exhaustSteamTubeConductivityLineEdit->text();
    exchanger.exhaustSteamTubeConductivity = temp.toFloat();

    temp=ui->lQSteamCondenserConductivityLineEdit->text();
    exchanger.lqSteamCondenserConductivity = temp.toFloat();

    temp = ui->lQSteamCondenserSurroundingTempLineEdit->text();
    exchanger.lqSteamCondenserSurroundingTemp = temp.toFloat();

    temp = ui->condensateWaterTubeConductivityLineEdit->text();
    exchanger.condensateWaterTubeConductivity = temp.toFloat();

    temp = ui->waterTubeConductivityLineEdit->text();
    exchanger.waterTubeConductivity = temp.toFloat();


    exchanger.Calc();

    ui->intermediateLoopCoolantRateLineEdit->setText(QString::number(exchanger.coolantTotalIntermediateLoopRate));
    ui->preheatLoopCoolantRateLineEdit->setText(QString::number(exchanger.coolantTotalPreheatingLoopRate));
    ui->primaryLoopCoolantRateLineEdit->setText(QString::number(exchanger.coolantTotalPrimaryRate));
    ui->totalCoolantPerTickLineEdit->setText(QString::number(exchanger.coolantTotalPrimaryRate+exchanger.coolantTotalPreheatingLoopRate+exchanger.coolantTotalPreheatingLoopRate));
                //Hot Coolant <-> Water
    ui->coolantWaterContactsRequiredLineEdit->setText(QString::number(exchanger.numCoolantWaterContacts));
    ui->waterConsumptionPerTickLineEdit->setText(QString::number(exchanger.waterTotalRate));
    ui->highPressureSteamLineEdit->setText(QString::number(exchanger.hpSteamTotalRate));
    // HP Steam -> LP Steam
                ui->exhaustSteamMBTickLineEdit->setText(QString::number(exchanger.exhaustSteamTotalRate));
                ui->exhaustSteamContactsRequiredLineEdit->setText(QString::number(exchanger.numExhaustSteamCoolantContacts));

                ui->lowPressureSteamMBTLineEdit->setText(QString::number(exchanger.lpSteamTotalRate));
    // LP Steam -> Condensate Water
                ui->lowQualitySteamMBTLineEdit->setText(QString::number(exchanger.lqSteamTotalRate));
                ui->condenserLQSteamContactsRequiredLineEdit->setText(QString::number(exchanger.numLqSteamCondenserContacts));
                ui->condensateWaterMBTLineEdit->setText(QString::number(exchanger.condensateWaterTotalRate));
    // Condensate Water <-> Hot Coolant;
                ui->condensateWaterContactsRequiredLineEdit->setText(QString::number(exchanger.numCondensateWaterCoolantContacts));

    // Power Produced
                ui->powerProducedRfTLineEdit->setText(QString::number(exchanger.power));

}

void MainWindow::ResetValues()
{
    ui->coolantPerRecipeLineEdit->setText(QString::number(20));
    ui->coolantHeatMultiplierLineEdit->setText(QString::number(125));
    ui->msrBaseCoolingRateLineEdit->setText(QString::number(0));
    ui->msrCoolingEfficiencyLineEdit->setText(QString::number(0));
    ui->numHeatersLineEdit->setText(QString::number(0));
    ui->coolantTubeConductivityLineEdit->setText(QString::number(0));
    ui->waterBaseCoolingProvidedLineEdit->setText(QString::number(800));
    ui->waterBaseHeatingRequiredLineEdit->setText(QString::number(16000));
    ui->exhaustSteamTubeConductivityLineEdit->setText(QString::number(0));
    ui->lQSteamCondenserConductivityLineEdit->setText(QString::number(0));
    ui->lQSteamCondenserSurroundingTempLineEdit->setText(QString::number(300));
    ui->condensateWaterTubeConductivityLineEdit->setText(QString::number(0));
    ui->waterTubeConductivityLineEdit->setText(QString::number(0));
    ui->intermediateLoopCoolantRateLineEdit->setText(QString::number(0));
    ui->preheatLoopCoolantRateLineEdit->setText(QString::number(0));
    ui->primaryLoopCoolantRateLineEdit->setText(QString::number(0));
    ui->totalCoolantPerTickLineEdit->setText(QString::number(0));
                //Hot Coolant <-> Water
    ui->coolantWaterContactsRequiredLineEdit->setText(QString::number(0));
    ui->waterConsumptionPerTickLineEdit->setText(QString::number(0));
    ui->highPressureSteamLineEdit->setText(QString::number(0));
    // HP Steam -> LP Steam
                ui->exhaustSteamMBTickLineEdit->setText(QString::number(0));
                ui->exhaustSteamContactsRequiredLineEdit->setText(QString::number(0));

                ui->lowPressureSteamMBTLineEdit->setText(QString::number(0));
    // LP Steam -> Condensate Water
                ui->lowQualitySteamMBTLineEdit->setText(QString::number(0));
                ui->condenserLQSteamContactsRequiredLineEdit->setText(QString::number(0));
                ui->condensateWaterMBTLineEdit->setText(QString::number(0));
    // Condensate Water <-> Hot Coolant;
                ui->condensateWaterContactsRequiredLineEdit->setText(QString::number(0));

    // Power Produced
                ui->powerProducedRfTLineEdit->setText(QString::number(0));

}

void MainWindow::on_buttonCalculate_clicked()
{
    CalcValues();
}

void MainWindow::on_buttonReset_clicked()
{
    ResetValues();
}

