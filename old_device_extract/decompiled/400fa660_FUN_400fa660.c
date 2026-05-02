// Function : FUN_400fa660
// Address  : 0x400fa660
// Size     : 130 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FUN_400fa660(int param_1,undefined1 param_2,int *param_3)

{
  int iVar1;
  int iVar2;
  uint uStack_48;
  undefined1 auStack_44 [2];
  byte bStack_42;
  int iStack_24;
  
  memw();
  iVar1 = *(int *)(param_1 + 100);
  memw();
  iStack_24 = _DAT_3ffc5708;
  *param_3 = 0;
  iVar2 = 0x1101;
  if (iVar1 == 1) {
    iVar1 = *(int *)(param_1 + 0x10);
    while (iVar1 != 0) {
      uStack_48 = 0;
      do {
        memw();
        iVar2 = FUN_400fb6ac(iVar1,param_2,0xff,0,&uStack_48,auStack_44,0xff,0xff);
        if (iVar2 == 0x1102) break;
        if (iVar2 != 0) goto LAB_400fa6cc;
        *param_3 = *param_3 + (uint)bStack_42;
        uStack_48 = bStack_42 + uStack_48;
      } while (uStack_48 < 0x7e);
      iVar1 = *(int *)(iVar1 + 4);
      memw();
    }
    iVar2 = 0;
  }
LAB_400fa6cc:
  memw();
  memw();
  if (iStack_24 != _DAT_3ffc5708) {
    (*(code *)&SUB_40082ec4)();
  }
  return iVar2;
}

