// Function : FUN_40137d00
// Address  : 0x40137d00
// Size     : 146 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FUN_40137d00(int *param_1,undefined1 param_2,undefined1 *param_3,uint param_4)

{
  int iVar1;
  int *piVar2;
  undefined1 uStack_66;
  undefined1 uStack_65;
  undefined1 auStack_64 [64];
  int iStack_24;
  
  memw();
  memw();
  iStack_24 = _DAT_3ffc5708;
  if (0x40 < param_4) {
    memw();
    iVar1 = FUN_4013cbd8(param_3,param_4,auStack_64,0);
    if (iVar1 != 0) goto LAB_40137d72;
    param_3 = auStack_64;
    param_4 = 0x40;
  }
  piVar2 = param_1 + 2;
  uStack_65 = (undefined1)param_4;
  memw();
  uStack_66 = param_2;
  if ((*param_1 != 0) || (iVar1 = FUN_40140a08(piVar2), iVar1 == 0)) {
    *param_1 = 1;
    memw();
    iVar1 = FUN_40140aec(piVar2,&uStack_66,2);
    if (iVar1 == 0) {
      iVar1 = FUN_40140aec(piVar2,param_3,param_4);
    }
  }
LAB_40137d72:
  FUN_4013ae54(auStack_64,0x40);
  memw();
  memw();
  if (iStack_24 != _DAT_3ffc5708) {
    (*(code *)&SUB_40082ec4)();
  }
  return iVar1;
}

