// Function : FUN_400d36e0
// Address  : 0x400d36e0
// Size     : 201 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_400d36e0(int *param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  char *pcVar3;
  undefined1 auStack_44 [16];
  undefined1 auStack_34 [16];
  int iStack_24;
  
  memw();
  memw();
  iStack_24 = _DAT_3ffc5708;
  if (*param_1 == param_2) goto LAB_400d377d;
  *param_1 = param_2;
  FUN_400f0be8(auStack_44,&DAT_3f42161d);
  if (param_2 == 2) {
    pcVar3 = "FICATES";
LAB_400d3730:
    FUN_400f0d70(auStack_44,pcVar3);
  }
  else {
    if (2 < param_2) {
      if (param_2 == 4) {
        pcVar3 = "NG_MQTT";
      }
      else if (param_2 < 4) {
        pcVar3 = "IVATING";
      }
      else {
        pcVar3 = "IF_MLD6_FAILED";
        if (param_2 != 5) goto LAB_400d3713;
      }
      goto LAB_400d3730;
    }
    if (param_2 == 0) {
      pcVar3 = "s found";
      goto LAB_400d3730;
    }
    pcVar3 = "nd";
    if (param_2 == 1) goto LAB_400d3730;
  }
LAB_400d3713:
  FUN_400f0be8(auStack_34,"SUCCESS");
  uVar2 = FUN_400f10c0(auStack_34,auStack_44);
  FUN_400f0768(0x3ffc5490,uVar2);
  FUN_400f0a50(auStack_34);
  FUN_400f0a50(auStack_44);
LAB_400d377d:
  iVar1 = _DAT_3ffc5708;
  memw();
  memw();
  if (iStack_24 == _DAT_3ffc5708) {
    return;
  }
  func_0x40082ecc();
  FUN_400f0a50(auStack_34);
  do {
    FUN_400f0a50(auStack_44);
    thunk_FUN_401710d8(iVar1);
  } while( true );
}

