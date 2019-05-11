#include "heatexchanger.h"
#include <fstream>
#include <cmath>

HeatExchanger::HeatExchanger()
{

}

HeatExchanger::~HeatExchanger()
{

}

void HeatExchanger::Calc()
{
    // Inital Coolant split
    coolantTotalIntermediateLoopRate = (240000*condensateWaterTubeConductivity*coolantPerRecipe*msrCoolingEfficiency*numHeaters*waterTubeConductivity)/(condensateWaterTubeConductivity*coolantTubeConductivity*exhaustSteamTubeConductivity*waterBaseCoolingProvided*waterBaseHeatingRequired+4800000*condensateWaterTubeConductivity*waterTubeConductivity+320000*exhaustSteamTubeConductivity*waterTubeConductivity);
    coolantTotalPreheatingLoopRate = (16000*coolantPerRecipe*exhaustSteamTubeConductivity*msrCoolingEfficiency*numHeaters*waterTubeConductivity)/(condensateWaterTubeConductivity*coolantTubeConductivity*exhaustSteamTubeConductivity*waterBaseCoolingProvided*waterBaseHeatingRequired+4800000*condensateWaterTubeConductivity*waterTubeConductivity+320000*exhaustSteamTubeConductivity*waterTubeConductivity);

    // Hot Coolant <-> Water
    coolantTotalPrimaryRate = coolantPerRecipe / 20*msrCoolingEfficiency*numHeaters-coolantTotalIntermediateLoopRate - coolantTotalPreheatingLoopRate;
    coolantBaseCoolingReq = coolantHeatMult*msrBaseCoolingRate*coolantTubeConductivity;
    coolantTotalCoolingReq = coolantTotalPrimaryRate*coolantBaseCoolingReq/coolantPerRecipe;
    numCoolantWaterContacts = coolantTotalCoolingReq/waterBaseCoolingProvided;
    waterTotalRate = 200*numCoolantWaterContacts*waterTubeConductivity*400/waterBaseHeatingRequired;
    hpSteamTotalRate = waterTotalRate * 1000 / 200; // So, waterTotalRate * 5?
    numCoolantWaterContacts = ceil(coolantTotalCoolingReq/waterBaseCoolingProvided);

    // HP Steam -> LP Steam
    exhaustSteamTotalRate = hpSteamTotalRate * 4;
    exhaustSteamTotalHeatingReq = exhaustSteamTotalRate*4000/(1000*exhaustSteamTubeConductivity);
    numExhaustSteamCoolantContacts = exhaustSteamTotalHeatingReq/400;
    coolantTotalIntermediateLoopRate = coolantPerRecipe * numExhaustSteamCoolantContacts*300/(coolantBaseCoolingReq*coolantTubeConductivity);
    lpSteamTotalRate = exhaustSteamTotalRate;
    numExhaustSteamCoolantContacts = ceil(exhaustSteamTotalHeatingReq/400);

    // LP Steam -> Condensate Water
    lqSteamTotalRate = lpSteamTotalRate*2;
    numLqSteamCondenserContacts = ceil(lqSteamTotalRate*20/(1000*lqSteamCondenserConductivity*(1+log(350/lqSteamCondenserSurroundingTemp))));
    condensateWaterTotalRate = exhaustSteamTotalRate*25/1000;

    // Condensate Water <-> Hot Coolant
    condensateWaterTotalHeatingReq = condensateWaterTotalRate*32000/(1000*condensateWaterTubeConductivity);
    numCondensateWaterCoolantContacts = condensateWaterTotalHeatingReq/400;
    coolantTotalPreheatingLoopRate = coolantPerRecipe*numCondensateWaterCoolantContacts*100/(coolantBaseCoolingReq*coolantTubeConductivity);
    numCondensateWaterCoolantContacts=ceil(numCondensateWaterCoolantContacts);

    power = hpSteamTotalRate*16 + lpSteamTotalRate *4;
}



