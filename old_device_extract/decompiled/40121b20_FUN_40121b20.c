// Function : FUN_40121b20
// Address  : 0x40121b20
// Size     : 149 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FUN_40121b20(int param_1,int *param_2,int *param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined1 auStack_2c [4];
  int iStack_28;
  int iStack_24;
  
  (*(code *)&SUB_4008b530)(auStack_2c,0,0xc);
  if (param_3 != (int *)0x0) {
    param_3[1] = 0;
  }
  memw();
  (*(code *)&SUB_40092760)(param_1,auStack_2c);
  param_2[1] = iStack_28;
  *param_2 = param_1;
  param_2[2] = iStack_24;
  memw();
  iVar1 = (*(code *)&SUB_40085d80)();
  if ((iVar1 == 0) && (iVar1 = FUN_40121b0c(), param_1 == iVar1)) {
    param_2[1] = _DAT_3ffc6d94;
  }
  memw();
  iVar1 = FUN_40122d00(param_2);
  if ((iVar1 != 0) && (iVar2 = FUN_40121b0c(), param_1 == iVar2)) {
    FUN_401231d8(param_1);
    iVar2 = (*(code *)&SUB_40085d80)();
    if (iVar2 != 0) {
      if (param_3 != (int *)0x0) {
        iVar3 = param_2[2];
        iVar2 = param_2[1];
        *param_3 = iVar2;
        param_3[1] = (iVar3 + 3) - iVar2 & 0xfffffffc;
      }
      param_2[1] = _DAT_3ffc6d94;
      memw();
      iVar2 = FUN_40122bdc();
      param_2[2] = iVar2;
    }
  }
  memw();
  return iVar1;
}

