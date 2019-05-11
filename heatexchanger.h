#ifndef HEATEXCHANGER_H
#define HEATEXCHANGER_H
#include <string>
#include <QObject>


class HeatExchanger : public QObject
{
public:
    HeatExchanger();
    ~HeatExchanger();
    float   coolantPerRecipe,
            coolantHeatMult,
            msrBaseCoolingRate,
            msrCoolingEfficiency,
            numHeaters,
            coolantTubeConductivity,
            waterTubeConductivity,
            waterBaseCoolingProvided,
            waterBaseHeatingRequired,
            exhaustSteamTubeConductivity,
            lqSteamCondenserConductivity,
            lqSteamCondenserSurroundingTemp,
            condensateWaterTubeConductivity;

//Calculated numbers

//Coolant Split Ratio
    float   coolantTotalIntermediateLoopRate,
            coolantTotalPreheatingLoopRate,
//Hot Coolant <-> Water
            coolantTotalPrimaryRate,
            coolantBaseCoolingReq,
            coolantTotalCoolingReq,
            numCoolantWaterContacts,
            waterTotalRate,
            hpSteamTotalRate,
// HP Steam -> LP Steam
            exhaustSteamTotalRate,
            exhaustSteamTotalHeatingReq,
            numExhaustSteamCoolantContacts,
            //coolantTotalIntermediateLoopRate,
            lpSteamTotalRate,
// LP Steam -> Condensate Water
            lqSteamTotalRate,
            numLqSteamCondenserContacts,
            condensateWaterTotalRate,
// Condensate Water <-> Hot Coolant;
            condensateWaterTotalHeatingReq,
            numCondensateWaterCoolantContacts,/*,
            coolantTotalPreHeatingLoopRate,*/

// Power Produced
            power;

    void Calc();
    void grabValues();

 public slots:
    void calcValues();
    void resetValues();


};

#endif // HEATEXCHANGER_H

