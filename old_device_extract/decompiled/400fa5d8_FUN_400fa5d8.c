// Function : FUN_400fa5d8
// Address  : 0x400fa5d8
// Size     : 134 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FUN_400fa5d8(int param_1,undefined1 param_2,char param_3,undefined4 param_4,uint *param_5)

{
  uint uVar1;
  int iVar2;
  undefined4 uStack_48;
  undefined1 auStack_44 [24];
  uint uStack_2c;
  int iStack_24;
  
  memw();
  memw();
  iStack_24 = _DAT_3ffc5708;
  iVar2 = 0x1101;
  if (*(int *)(param_1 + 100) == 1) {
    uStack_48 = 0;
    memw();
    iVar2 = FUN_400f9c84(param_1,param_2,param_3,param_4,&uStack_48,auStack_44,0xff,0xff);
    if (iVar2 == 0) goto LAB_400fa651;
    if (param_3 == 'A') {
      memw();
      iVar2 = FUN_400f9c84(param_1,param_2,0x48,param_4,&uStack_48,auStack_44,0xff,0xff);
      uVar1 = uStack_2c;
      if (iVar2 == 0) goto LAB_400fa654;
    }
  }
  while( true ) {
    memw();
    memw();
    if (iStack_24 == _DAT_3ffc5708) break;
    iVar2 = (*(code *)&SUB_40082ec4)();
LAB_400fa651:
    uVar1 = uStack_2c & 0xffff;
LAB_400fa654:
    *param_5 = uVar1;
    memw();
  }
  return iVar2;
}

