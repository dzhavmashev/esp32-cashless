// Function : FUN_400da604
// Address  : 0x400da604
// Size     : 234 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_400da604(int param_1,int param_2,int *param_3)

{
  int iVar1;
  char *pcVar2;
  undefined4 ****ppppuVar3;
  int *piVar4;
  int iStack_38;
  undefined4 ***local_34 [3];
  byte bStack_25;
  int iStack_24;
  
  memw();
  memw();
  iStack_24 = _DAT_3ffc5708;
  *(int *)(param_1 + 0x800) = param_2;
  FUN_400f0be8(local_34,&DAT_3f42161d);
  if (param_2 == 2) {
    pcVar2 = "MESH_DISCONNECTED";
  }
  else if (param_2 < 3) {
    if (param_2 == 0) {
      pcVar2 = "RR_MESH_DISCONNECTED";
    }
    else {
      pcVar2 = "ntering CONNECTING";
      if (param_2 != 1) goto LAB_400da632;
    }
  }
  else if (param_2 == 4) {
    pcVar2 = "_FAILED";
  }
  else if (param_2 < 4) {
    pcVar2 = "d): %s\n";
  }
  else {
    pcVar2 = "E_ERROR";
    if (param_2 != 5) goto LAB_400da632;
  }
  FUN_400f0d70(local_34,pcVar2);
LAB_400da632:
  ppppuVar3 = local_34;
  if ((bStack_25 & 0x80) == 0) {
    ppppuVar3 = (undefined4 ****)local_34[0];
  }
  FUN_400f06a4(0x3ffc5490,"K_ERROR",ppppuVar3);
  iVar1 = FUN_400da468(param_3);
  if (iVar1 == 0) {
    piVar4 = param_3;
    if ((*(byte *)((int)param_3 + 0xf) & 0x80) == 0) {
      piVar4 = (int *)*param_3;
    }
    FUN_400f06a4(0x3ffc5490,"d to %s",piVar4);
  }
  FUN_400f0754(0x3ffc5490);
  if (*(int *)(param_1 + 0x828) != 0) {
    iStack_38 = param_2;
    (**(code **)(param_1 + 0x82c))(param_1 + 0x820,&iStack_38,param_3);
  }
  FUN_400f0a50(local_34);
  iVar1 = _DAT_3ffc5708;
  memw();
  memw();
  if (iStack_24 != _DAT_3ffc5708) {
    func_0x40082ecc();
    FUN_400f0a50(local_34);
    thunk_FUN_401710d8(iVar1);
  }
  return;
}

